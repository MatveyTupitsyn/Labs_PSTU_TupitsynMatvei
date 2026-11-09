#include <iostream>
#include <clocale>
using namespace std;

void setmatrix(int (&arr)[100],int (&barr)[100][100], int N) //функция для составления матрицы N x N
{
    for (int i = 0;i < N;i++) //Заполним матрицу b единицами, а потом изменим первый член на необходимое значение
    {
        int sum = arr[i];
        for (int j = 0;j < N;j++)
        {
            barr[j][i] = 1;
        }

        barr[0][i] += (sum - N);

        if (barr[0][i] == 0) // изменяем два значения на 2 и -1 чтобы избавиться от нуля
        {
            barr[0][i] = 2;
            barr[1][i] = -1;
        }
    }
}

int main()
{
    setlocale(LC_ALL,".UTF8");
    int a[100];
    int b[100][100];
    int N;
    cout << "Введите длину массива (N < 100): ";
    cin >> N;
    cout << "Вводите значения массива (Без нулей)" << endl;
    for (int i = 0;i < N;i++)
    {
        cin >> a[i];
    }
    setmatrix(a,b,N);
    for (int i = 0; i < N; i++) // выводим матрицу
    {
        for (int j = 0; j < N; j++)
        {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}