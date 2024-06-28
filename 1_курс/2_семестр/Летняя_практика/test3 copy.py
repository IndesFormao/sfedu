from test3 import table_frame
import matplotlib.pyplot as plt

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
    

circle(table_frame)


    


files = [f"chessResultsList-{a}.csv" for a in range(1, 10)]
chess_result = ChessResult(files)
table_frame = chess_result.calculate_standings()
print(table_frame.to_string(index=False))
chess_result.save_as_csv(table_frame, "final_standings.csv")
circle(table_frame)
