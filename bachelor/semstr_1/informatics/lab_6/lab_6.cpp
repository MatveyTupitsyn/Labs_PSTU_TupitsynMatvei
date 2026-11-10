#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL,".UTF8");
    string s1,s2;
    cout << "Введите слово: ";
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(),s2.end()); //функция для переворачивания слова
    if (s1 == s2)
        cout << "Это слово палиндром!!";
    else
        cout << "Это слово НЕ палиндром!!";
    return 0;
}