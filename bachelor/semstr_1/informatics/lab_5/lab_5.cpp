#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    int a[100];
    int b[100][100];
    int N;
    bool f;
    cout << "Введите длину массива (N < 100): ";
    cin >> N;
    cout << "Вводите значения массива (Без нулей)" << endl;
    for (int i = 0;i < N;i++)
    {
        cin >> a[i];
    }
    //Заполним матрицу b единицами, а потом изменим первый член на необходимое значение
    for (int i = 0;i < N;i++)
    {
        int sum = a[i];
        for (int j = 0;j < N;j++)
        {
            b[j][i] = 1;
        }

        b[0][i] += (sum - N);

        if (b[0][i] == 0) // изменяем два значения на 2 и -1 чтобы избавиться от нуля
        {
            b[0][i] = 2;
            b[1][i] = -1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}