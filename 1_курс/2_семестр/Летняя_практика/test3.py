import pandas
import matplotlib.pyplot as plt

class ChessResult:

    def __init__(self, files):
        self.files = files
        self.player_data = {}

    def __open_files(self):
        # Объединяет файлы, переданные при создании экземпляра класса в один DataFrame
        data_frames = [pandas.read_csv(file) for file in self.files]
        combined_data = pandas.concat(data_frames, ignore_index=True)
        return combined_data

    def __add_user(self, id, name, rating):
        """Добавляет нового участника в единый словарь турнира"""
        self.player_data[id] = {
            "Имя": name,
            "Рейтинг": rating,
            "Очки": 0,
            "Очки чистых побед": 0,
            "Соперники": [],
        }

    def __insert_result(self, player_id, opponent_id, result):
        """Принимает на вход id игрока и его опонента, результат партии. Вносит изменения в основную таблицу их счёт"""

        # Внесение информации о полученных очках
        if result[0] in "1+":
            match_result = [1, 0]
            self.player_data[player_id]["Очки"] += 1
            self.player_data[player_id]["Очки чистых побед"] += 1
        elif result[0] == "½":
            match_result = [1 / 2, 1 / 2]
            self.player_data[player_id]["Очки"] += 0.5
            self.player_data[opponent_id]["Очки"] += 0.5
        elif result[-1] in "1+":
            match_result = [0, 1]
            self.player_data[opponent_id]["Очки"] += 1
            self.player_data[opponent_id]["Очки чистых побед"] += 1

        # Внесение информации о соперниках
        self.player_data[player_id]["Соперники"].append(
            {"id": opponent_id, "is_white": True, "result": match_result[0]}
        )
        self.player_data[opponent_id]["Соперники"].append(
            {"id": player_id, "is_white": True, "result": match_result[1]}
        )

    def __get_additional2(self, player_id):
        """Принимает на вход id игрока, возвращает коэффициент Бухгольца на основе очков соперников"""
        return sum(
            self.player_data[opponent["id"]]["Очки"]
            for opponent in self.player_data[player_id]["Соперники"]
        )

    def __get_additional1(self, player_id, additional2):
        """
        Принимает на вход id игрока и значения коэффициента Бухгольца,
        возвращает разницу коэффициента Бухгольца и минимального колличества очков соперника с прибавленным коэффициентом цвета (белый 0, черный 1)
        """
        min_opponent = 100
        is_white = True
        for opponent in self.player_data[player_id]["Соперники"]:
            opponent_points = self.player_data[opponent["id"]]["Очки"]
            if opponent_points < min_opponent:
                is_white = opponent["is_white"]
                min_opponent = opponent_points
            elif opponent_points == min_opponent:
                if is_white:
                    if not (opponent["is_white"]):
                        is_white = False
        return (
            additional2 - min_opponent if is_white else additional2 - min_opponent + 1
        )

    def __get_additional4(self, player_id, opponents_id):
        for opponent_id in opponents_id:
            self.player_data[player_id]["Соперники"]

    def calculate_standings(self):
        """Высчитывает таблицу итогов шахматного турнира, возвращает DataFrame"""
        data = self.__open_files()

        # Обработка каждой строки данных
        for index, row in data.iterrows():
            # Получение данных участников и результата матча, и исправление недочетов
            player_id = row.iloc[0]
            player_name = row.iloc[1].strip()
            player_rating = row.iloc[2]
            opponent_id = row.iloc[6]
            opponent_name = row.iloc[4].strip()
            opponent_rating = row.iloc[5]
            result = row.iloc[3]

            # Инициализация данных участников
            if player_id not in self.player_data:
                self.__add_user(player_id, player_name, player_rating)
            if opponent_id not in self.player_data:
                self.__add_user(opponent_id, opponent_name, opponent_rating)

            # Обновление данных для участников
            self.__insert_result(player_id, opponent_id, result)

        # Преобразование данных в DataFrame
        standings_data = []
        for player_id, player_info in self.player_data.items():
            additional2 = self.__get_additional2(player_id)
            additional1 = self.__get_additional1(player_id, additional2)

            standings_data.append(
                [
                    player_id,
                    player_info["Имя"],
                    player_info["Рейтинг"],
                    player_info["Очки"],
                    additional1,
                    additional2,
                    player_info["Очки чистых побед"],
                    0,
                ]
            )

        # Создание итоговой таблицы
        standings_data_frame = pandas.DataFrame(
            standings_data,
            columns=[
                "НомерУчастника",
                "ИмяУчастника",
                "РейтингУчастника",
                "ОчкиУчастника",
                "Коэфф Бухгольца 1",
                "Коэфф Бухгольца 2",
                "Чистые победы",
                "Нулевка",
            ],
        )

        # Сортировка итоговой таблицы по очкам
        standings_data_frame = standings_data_frame.sort_values(
            by=[
                "ОчкиУчастника",
                "Коэфф Бухгольца 1",
                "Коэфф Бухгольца 2",
                "Чистые победы",
            ],
            ascending=[False, False, False, False],
        ).reset_index(drop=True)

        # Добавление колонки с местами
        standings_data_frame.insert(0, "Место", standings_data_frame.index + 1)

        # Раздел проверки последнего столбца

        columns_to_check = [
            "ОчкиУчастника",
            "Коэфф Бухгольца 1",
            "Коэфф Бухгольца 2",
        ]

        duplicates = standings_data_frame[
            standings_data_frame.duplicated(
                subset=columns_to_check,
                keep=False,
            )
        ]
        if not duplicates.empty:
            for same_group, group_data_frame in duplicates.groupby(columns_to_check):
                player_numbers = group_data_frame["НомерУчастника"].tolist()
                print(player_numbers)
                for idx, row in group_data_frame.iterrows():
                    player_number = row["НомерУчастника"]
                    additional_value = self.__get_additional4(
                        player_number, player_numbers
                    )
                    standings_data_frame.loc[idx, "Нулевка"] = additional_value
        # print(duplicates)

        return standings_data_frame

    def save_as_csv(self, data_frame, output_file_name):
        """Принимает на вход DataFrame и сохраняет его по пути output_file_name"""
        data_frame.to_csv(output_file_name, index=False, encoding="utf-8-sig")


def circle(table):
    # Вычисление количества ничьих
    table['draws'] = (table['ОчкиУчастника'] - table['Чистые победы']) * 2
    
    # Фильтрация строк, где значение 'draws' не равно нулю
    table = table[table['draws'] != 0]

    # Построение круговой диаграммы с увеличенным отступом для названий и секторами
    wedges = plt.pie(table['draws'], autopct='%1.0f%%')[0]
    
    # Создание списка строк для легенды с именами и процентами
    legend_labels = [f"{name} - {round(percent)}%" for name, percent in zip(table['ИмяУчастника'], 100 * table['draws'] / sum(table['draws']))]

    # Добавление заголовка к диаграмме
    plt.title('Распределение ничьих среди участников')
    
    # Добавление легенды
    # plt.legend(wedges, table['ИмяУчастника'], title="Участники", bbox_to_anchor=(1, 0, 0, 1))

    
    # Добавление легенды с созданным списком
    plt.legend(wedges, legend_labels, title="Участники", bbox_to_anchor=(1, 0, 0, 1))


    plt.show()
    




    


files = [f"chessResultsList-{a}.csv" for a in range(1, 10)]
chess_result = ChessResult(files)
table_frame = chess_result.calculate_standings()
print(table_frame.to_string(index=False))
chess_result.save_as_csv(table_frame, "final_standings.csv")

