#include <iostream>
using namespace std;

int main()
{
    int n_origin;//сохраняем изначальные значения
    int m_origin;
    cin >> n_origin >> m_origin;
    //1й пункт
    int n = n_origin;
    int m = m_origin;
    int res = n-- - m;
    cout << "Result1: " << res << '\n'
    << "n = " << n << ' ' << "m = " << m << endl;

    //2й пункт
    n = n_origin;
    m = m_origin;
    res = m-- < n;
    cout << "Result2: " << res << '\n'
    << "n = " << n << ' ' << "m = " << m << endl;

    //3й пункт
    n = n_origin;
    m = m_origin;
    res = n++ > m;
    cout << "Result3: " << res << '\n'
    << "n = " << n << ' ' << "m = " << m << endl;
    return 0;
}