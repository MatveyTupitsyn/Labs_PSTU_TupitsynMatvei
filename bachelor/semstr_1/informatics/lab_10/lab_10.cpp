#include <iostream>
#include <string>
#include <random>
using namespace std;

string randomString(int low, int high)
{
    static mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(low, high);
    uniform_int_distribution<int> distalp(0, 25);          // индексы 0..25
    static const string alphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";

    int len = dist(gen);
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i)
        s += alphabet[distalp(gen)];
    return s;
}

int main()
{
    setlocale(LC_ALL, ".UTF8");

    int N, K;
    cout << "Введите размер массива: ";
    cin >> N;

    string* arr = new string[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = randomString(3, 10);
        cout << "Элемент массива строк сгенерирован: " << arr[i] << '\n';
    }


    int n = N;
    int out = 0;
        for (int i = 0; i < n; ++i) {
            bool dup = false;
            for (int j = 0; j < out; ++j) {
                if (arr[j] == arr[i]) 
                { 
                    dup = true; 
                    break; 
                }
            }
            if (!dup) {
                if (out != i)
                    arr[out] = std::move(arr[i]);
                ++out;
            }
        }
    n = out;
    cout << "Массив после удаления дубликатов:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << '\n';

    cout << "Введите количество удаляемых элементов с конца: ";
    cin >> K;
    if (K < 0) K = 0;
    if (K > n) K = n;
    n -= K;                       // «удаляем» K с конца — просто уменьшаем размер

    cout << "Итоговый массив (" << n << " элементов):\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << '\n';

    delete[] arr;
    return 0;
}