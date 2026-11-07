#include <iostream>
#include <clocale>
#include <iterator>
using namespace std;

// перегрузка функции для массивов разных типов с помощью шаблона
template <typename T>
void cycle_move(T (&a)[5]) //для примера возьмем массивы длиной 5
{
    int shift,n = size(a);
    if (static_cast<int>(a[0]) % 2 == 0)
    {
        shift = static_cast<int>(a[0]) % n;
        rotate(a,a + shift,a + n);
    }
    else
    {
        shift = static_cast<int>(a[n - 1]) % n;
        rotate(a,a + n - shift,a + n);
    }
}


int main()
{
    setlocale(LC_ALL,".UTF8");
    int arr[] = {1,6,3,4,7};
    cout << "Массив int до сдвига: ";
    for (int i = 0; i < size(arr);i++)
        cout << arr[i] << ' ';
    cout << endl;
    cycle_move(arr);
    cout << "Массив int после сдвига: ";
    for (int i = 0; i < size(arr);i++)
        cout << arr[i] << ' ';
    cout << endl;
    double arrd[] = {2.5,65,67.69,4.2,7.2};
    cout << "Массив double до сдвига: ";
    for (int i = 0; i < size(arrd);i++)
        cout << arrd[i] << ' ';
    cout << endl;
    cycle_move(arrd);
    cout << "Массив double после сдвига: ";
    for (int i = 0; i < size(arrd);i++)
        cout << arrd[i] << ' ';
    return 0;
}
