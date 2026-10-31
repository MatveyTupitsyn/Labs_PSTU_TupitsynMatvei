#include <iostream>
#include <cmath>
using namespace std;

double sum_n(double x,int n) //расчитаем сумму для заданного n
{
    double u = -2.0 * x * x; // Первый член ряда при i = 1
    double S = u;
    for (int i = 2; i <= n;++i)
    {
        u *= (-2.0 * x * x) / (i * (2 * i - 1));
        S += u;
    }
    return S;
}

double sum_eps(double x) //рассчитаем сумму для заданной точности
{
    double u = -2.0 * x * x; // Первый член ряда при i = 1
    double S = u;
    double eps = 0.0001;
    int i = 2;
    while (abs(u) > eps)
    {
        u *= (-2.0 * x * x) / (i * (2 * i - 1));
        S += u;
        i++;
    }
    return S;
}

int main()
{
    float a = 0.1;
    float b = 1;
    int k = 10;
    float h = (b - a)/k; // находим чему равен наш шаг
    int n = 15;
    
    for (float x = a; x < b; x += h) // через цикл выводим значения
    {
        cout << "X = " << x << "\t";
		cout << "SN = " << sum_n(x, n) << "\t";
		cout << "SE = " << sum_eps(x) << "\t";
		cout << "Y = " << 2*(pow(cos(x),2) - 1) << "\t" << endl;
    }
    return 0;
}