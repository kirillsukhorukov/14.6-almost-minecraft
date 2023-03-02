#include <iostream>

using namespace std;

//Процедура вывода массива
void print_array (const int (&array) [5][5])
{
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++) cout << array [i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

//Процедура вывода среза
void print_slice (const bool (&array)[5][5][10], const int &level)
{
    cout << "Slice " << level << " level: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) cout << array[i][j][level-1] << '\t';
        cout << endl;
    }
    cout << endl;
}

int main()
{
    cout << "------------'Almost Minecraft'------------\n" << endl;

    //Инициализация матрицы высоты столбцов
    int matrixHeight [5][5];

    //Инициализация счетчика ввода
    int count=1;

    cout << "Enter, in turn, a height of 25 columns." << endl;
    cout << "The height of each column should not be higher than 10 blocks.\n" << endl;

    //Ввод высот столбиков и запись их в матрицу высот
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            do
            {
                cout << "Enter " << count << " column height:";
                cin >> matrixHeight [i][j];
            }
            while (matrixHeight [i][j]<0 || matrixHeight [i][j]>10);
            count++;
        }
    }

    //Печать матрицы высот столбцов
    cout << "Matrix of heights:" << endl;
    print_array(matrixHeight);

    //Инициализация трехмерного массива "маленького мира"
    bool smallWorld [5][5][10];
    for (int l=0; l<10; l++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matrixHeight[i][j]>l ? smallWorld[i][j][l] = true : smallWorld[i][j][l] = false;
            }
        }
    }

    //Инициализация переменной уровня среза
    int level;

    //Организация цикла запроса уровня среза и вывод среза
    do
    {
        //Запрос уровня
        do {
            cout << "Enter the level (from 1 to 10), the cut of which needs to be obtained (for exit, enter 0): ";
            cin >> level;
        } while (level < 0 || level > 10);

        //Вывод среза на экран
        if (level!=0) print_slice (smallWorld, level);

    }
    while (level!=0);

    return 0;
}
