# Отчет к лабораторной работе №2: "Использование основных операторов языка Си"
## 1.Постановка задачи
Вариант 23: найти сумму 10 членов ряда, в котором a<sub>n</sub> = (n!/n<sup>sqrt{n}
</sup>)
## 2. Текст программы и блок - схема
```
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

long factorial(int a) //функция для расчета факториала
{
    long s = 1;
    for (int i = 2; i <= a; i++)
    {
        s *= i;
    }
    return s;
}

int main()
{
    setlocale(LC_ALL,".UTF8");
    int n,sum; // расчитывем 10 членов ряда, начиная с n
    sum = 0;
    cout << "Введите n: ";
    cin >> n;
    for (int i = n; i < n + 10; i++)
    {
        sum += (factorial(i)/pow(i,sqrt(i)));
    }
    cout << "Сумма 10 членов ряда равна " << sum;
    return 0;
}
```

![[лаб раб 2.png]]

## 3.Результат решения конкретного варианта
```
Введите n: 1
Сумма 10 членов ряда равна 3148
```
