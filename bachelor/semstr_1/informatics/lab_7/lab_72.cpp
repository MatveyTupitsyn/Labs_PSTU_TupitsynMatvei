#include <iostream>
#include <cmath>
#include <cstdarg>
#include <clocale>
using namespace std;

double cross(double ax, double ay, double bx, double by, double px, double py) // функция для векторного произведения
{
    return (bx - ax) * (py - ay) - (by - ay) * (px - ax);
}

double dist(double (&a)[2],double (&b)[2]) // функция для нахождение длины
{
    double x1 = a[0],y1 = a[1];
    double x2 = b[0],y2 = b[1];
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

bool belong(double (&a)[2],double (&b)[2],double (&c)[2],double (&z)[2]) //функция для проверки принадлежности точки треугольнику
{
    double x1 = a[0],y1 = a[1];
    double x2 = b[0],y2 = b[1];
    double x3 = c[0],y3 = c[1];
    double x0 = z[0],y0 = z[1];

    double d1 = cross(x1, y1, x2, y2, x0, y0);
    double d2 = cross(x2, y2, x3, y3, x0, y0);
    double d3 = cross(x3, y3, x1, y1, x0, y0);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0); //проверка на одинаковые знаки: если они одинаковы,
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0); // то точка принадлежит треугольнику

    return !(hasNeg&&hasPos);
}

bool belongPolygon(int n, double mx, double my, ...) //функция для проверки принадлежности точки многоугольнику
{
    if (n < 3) 
        return false; //проверка на наличие многоугольника

    double vx[100], vy[100];

    va_list args;
    va_start(args, my);            // начинаем читать после последнего именованного параметра
    for (int i = 0; i < n; ++i) 
    {
        vx[i] = va_arg(args, double);   // x_i
        vy[i] = va_arg(args, double);   // y_i
    }
    va_end(args);

    bool hasNeg = false, hasPos = false;
    for (int i = 0; i < n; ++i) 
    {
        int j = (i + 1) % n;// замыкаем многоугольник
        double d = cross(vx[i], vy[i], vx[j], vy[j], mx, my);
        if (d < 0)
            hasNeg = true;
        if (d > 0)
            hasPos = true;
        if (hasNeg && hasPos) 
            return false;// точка по разные стороны → снаружи
    }
    return true;
}

int main()
{
    setlocale(LC_ALL,".UTF8");
    //проверка dist
    double a[] = {1.0,2.0}, b[] = {4.0,5.0};
    cout << "Длина между а и b равна " << dist(a,b) << endl;
    //проверка belong
    double tra[] = {3.0,5.0}, trb[] = {6.0,7.0}, trc[] = {6.0,9.0};
    double dot[] = {5.0,8.0};
    if (belong(tra,trb,trc,dot))
        cout << "Точка dot принадлежит треугольнику!" << endl;
    else
        cout << "Точка dot НЕ принадлежит треугольнику!" << endl;

    // для проверки последней функции возьмем пятиугольник
    bool inside = belongPolygon(
        5,                    // n — сколько вершин
        5.0, 7.0,               // точка M
        0.0,  0.0,            // вершина 1
        4.0,  0.0,            // вершина 2
        5.0,  3.0,            // вершина 3
        2.0,  5.0,            // вершина 4
        -1.0, 3.0             // вершина 5
    );
    if (inside)
        cout << "Точка принадлежит многоугольнику\n";
    else
        cout << "Точка НЕ принадлежит многоугольнику\n";
    return 0;
}