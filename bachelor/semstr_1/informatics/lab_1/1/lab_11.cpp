#include <iostream>
using namespace std;

int main()
{
    //проверка с float
    float a_f = 1000.0;
    float b_f = 0.0001;
    
    float num1f = (a_f + b_f) * (a_f + b_f) * (a_f + b_f);
    float num2f = powf(a_f,3) + 3*a_f*a_f*b_f;
    float num3f = 3*a_f*b_f*b_f + pow(b_f,3);
    float finf = (num1f - num2f)/ num3f;
    cout << "Float result: " << finf << endl;

    //Проверка с double
    double a_d = 1000.0;
    double b_d = 0.0001;

    double num1d = (a_d + b_d) * (a_d + b_d) * (a_d + b_d);
    double num2d = powf(a_d,3) + 3*a_d*a_d*b_d;
    double num3d = 3*a_d*b_d*b_d + pow(b_d,3);
    double find = (num1d - num2d)/ num3d;
    cout << "Double result: " << find << endl;

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