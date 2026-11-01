#include <iostream>
#include <clocale>
using namespace std;

void removeElement(int arr[], int& size, int index) {
    // Сдвигаем элементы влево
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--; // Уменьшаем логический размер массива
}
int main()
{
    setlocale(LC_ALL,".UTF8");
    int K, N;
    int a[100];
    cout << "Введите N (N <= 100) и K (K < N): ";
    cin >> N >> K;
    for (int i = 0; i < N; i++) //генерируем массив только на заданном участке
    {
        a[i] = i;
    }
    for (int i = K; i < N; i++) // выводим сначала числа до конца, а потом с начала до K
        cout << a[i] << ' ';
    for (int i = 0; i < K; i++)
        cout << a[i] << ' ';
    cout << endl;
    int max = a[0];
    for (int i = 0; i < N; i++) // находим максимальный элемент
    {
        if (a[i] > max)
            max = a[i];
    }
    for (int i = N - 1; i >= 0;i--) // проверяем каждый элемент
    {
        if (a[i] == max)
            removeElement(a,N,i);
    }
    for (int i = K; i >= 0; i--) // выводим по кольцу вправо
        cout << a[i] << ' ';
    for (int i = N - 1; i > K; i--)
        cout << a[i] << ' ';
    
    return 0;
}