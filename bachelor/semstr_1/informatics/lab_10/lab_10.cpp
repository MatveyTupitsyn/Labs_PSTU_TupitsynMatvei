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

    // Удаление соседних дубликатов сдвигом
    int n = N;
    for (int i = 0; i + 1 < n; ) {
        if (arr[i] == arr[i + 1]) {
            for (int k = i + 1; k + 1 < n; ++k)
                arr[k] = move(arr[k + 1]);
            --n;
        } else {
            ++i;
        }
    }

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