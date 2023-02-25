#include <iostream>
#include <cmath>
using namespace std;

float Distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float Cos(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    return (fabs((x2 - x1) * (x4 - x3) + (y2 - y1) * (y4 - y3)) / (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) * sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2))));
}

class Triangle {
private:
    double a, b, c;
public:
    bool exst_tr() {
        return ((a + b > c) && (b + c > a) && (a + c > b));
    }
    void set(double a1, double b1, double c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    void show() {
        cout << "1 сторона: " << a << endl;
        cout << "2 сторона: " << b << endl;
        cout << "3 сторона: " << c << endl;
    }
    double perimeter() {
        double p = a + b + c;
        return p;
    }
    double square() {
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }
};

class Circle {
private:
    float radius, x_center, y_center;
public:
    void set(float r, float x, float y) {
        radius = r;
        x_center = x;
        y_center = y;
    }
    double square_circle() {
        float PI = 3.1415926535;
        double s = PI * (radius * radius);
        return s;
    }
    bool triangle_around(float a, float b, float c) {
        Triangle temp_triangle;
        temp_triangle.set(a, b, c);
        return temp_triangle.exst_tr();
    }
    bool triangle_in(float a, float b, float c) {
        Triangle temp_triangle;
        temp_triangle.set(a, b, c);
        return temp_triangle.exst_tr();
    }
    bool check_circle(float r, float x_cntr, float y_cntr) {
        bool distance = Distance(x_center, y_center, x_cntr, y_cntr) < r + radius;
        bool not_in = radius - Distance(x_center, y_center, x_cntr, y_cntr) < r;
        bool not_around = r - Distance(x_center, y_center, x_cntr, y_cntr) < radius;
        return distance && not_around && not_in;
    }
};

class Figure {
private:
    float x1, x2, x3, x4, y1, y2, y3, y4;
    float S = (Distance(x1, y1, x3, y3) / 2) * (Distance(x2, y2, x4, y4) / 2) * sqrt(1 - pow(Cos(x1, y1, x3, y3, x2, y2, x4, y4), 2));
    float P = Distance(x1, y1, x2, y2) + Distance(x2, y2, x3, y3) + Distance(x3, y3, x4, y4) + Distance(x4, y4, x1, y1);
public:
    void set(float xt1, float xt2, float xt3, float xt4, float yt1, float yt2, float yt3, float yt4) {
        x1 = xt1;
        x2 = xt2;
        x3 = xt3;
        x4 = xt4;
        y1 = yt1;
        y2 = yt2;
        y3 = yt3;
        y4 = yt4;
    }
    void show() {
        cout << "Вершина A (" << x1 << ", " << y1 << ")." << endl;
        cout << "Вершина B (" << x2 << ", " << y2 << ")." << endl;
        cout << "Вершина C (" << x3 << ", " << y3 << ")." << endl;
        cout << "Вершина D (" << x4 << ", " << y4 << ")." << endl;
        cout << "Площадь равна " << S << "." << endl;
        cout << "Периметр равен " << P << "." << endl;
    }
    bool is_prug() {
        return Cos(x1, y1, x2, y2, x2, y2, x3, y3) == 0 && Cos(x2, y2, x3, y3, x3, y3, x4, y4) == 0 && Cos(x3, y3, x4, y4, x4, y4, x1, y1) == 0 && Cos(x4, y4, x1, y1, x1, y1, x2, y2) == 0;
    }
    bool is_romb() {
        return Distance(x1, y1, x2, y2) == Distance(x2, y2, x3, y3) && Distance(x1, y1, x2, y2) == Distance(x3, y3, x4, y4) && Distance(x1, y1, x2, y2) == Distance(x4, y4, x1, y1);
    }
    bool is_square() {
        return is_prug() && is_romb():
    }
    bool is_in_circle() {
        return Cos(x1, y1, x2, y2, x2, y2, x3, y3) + Cos(x3, y3, x4, y4, x4, y4, x1, y1) == 0 && Cos(x2, y2, x3, y3, x3, y3, x4, y4) + Cos(x4, y4, x1, y1, x1, y1, x2, y2) == 0;
    }
    bool is_out_circle() {
        return Distance(x1, y1, x2, y2) + Distance(x3, y3, x4, y4) == Distance(x2, y2, x3, y3) + Distance(x4, y4, x1, y1);
    }
};

int main()
{
    Triangle mas[3];
    double a, b, c;
    for (int i = 0; i < 3; i++) {
        cout << "Введите a, b и c для треугольника № " << i + 1 << " через пробел: " << endl;
        cin >> a >> b >> c;
        mas[i].set(a, b, c);
        if (!(mas[i].exst_tr())) {
            mas[i].show();
            cout << "Треугольника с такими сторонами не существует, попробуйте ещё раз" << endl;
            i--;
        }
    }
    for (int i = 0; i < 3; i++) {
        mas[i].show();
        cout << "Периметр треугольника: " << mas[i].perimeter() << endl;
        cout << "Площадь треугольника: " << mas[i].square() << endl;
    }
    return 0;
}