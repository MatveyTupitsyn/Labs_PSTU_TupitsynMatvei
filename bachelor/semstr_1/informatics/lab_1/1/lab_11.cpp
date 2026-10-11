#include <iostream>
using namespace std;

int main()
{
    //проверка с float
    float a_f = 1000.0;
    float b_f = 0.0001;
    
    float num1f = (a_f + b_f) * (a_f + b_f) * (a_f + b_f); // (a+b)^3
    float num2f = powf(a_f,3) + 3.0*a_f*a_f*b_f; // a^3 + 3a^2b
    float num3f = 3.0*a_f*b_f*b_f + powf(b_f,3); // 3ab^2 + b^3
    float finf = (num1f - num2f)/ num3f;
    cout << "Float result: " << finf << endl;

    //Проверка с double
    double a_d = 1000.0;
    double b_d = 0.0001;

    double num1d = (a_d + b_d) * (a_d + b_d) * (a_d + b_d); // (a+b)^3
    double num2d = pow(a_d,3) + 3.0*a_d*a_d*b_d; // a^3 + 3a^2b
    double num3d = 3.0*a_d*b_d*b_d + pow(b_d,3); // 3ab^2 + b^3
    double find = (num1d - num2d)/ num3d;
    cout << "Double result: " << find << endl;

    return 0;
}