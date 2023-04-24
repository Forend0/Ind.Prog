#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

const double pi = 3.14159265;

class Cone {
    double x, y, z;
    double radius;
    double height;
public:
    Cone() { x = y = z = radius = height = 0; }
    Cone(double r, double h) {
        x = y = z = 0.0;
        radius = r;
        height = h;
    }
    Cone(double a, double b, double c, double r, double h) {
        x = a;
        y = b;
        z = c;
        radius = r;
        height = h;
    }
    void setCoordinate(double a, double b, double c) { x = a; y = b; z = c; }
    void setRadius(double r) { radius = r; }
    void setHeight(double h) { height = h; }
    double getRadius() { return radius; }
    double getHeight() { return height; }
    double area() {
        double l = sqrt(height * height + radius * radius);
        return pi * radius * (radius + l);
    }
    double volume() {
        return pi * radius * radius * height / 3;
    }
    friend ostream& operator<<(ostream& stream, Cone obj);
};

ostream& operator<<(ostream& stream, Cone obj) {
    stream << "(" << obj.x << "; ";
    stream << obj.y << "; ";
    stream << obj.z << ") ";
    stream << "r=" << obj.radius << " ";
    stream << "h=" << obj.height << "\n";
    return stream;
}


class halfCone : public Cone {
    double x, y, z;
    double radius;
    double halfheight;
    double height;
public:
    halfCone() { x = y = z = radius = height = halfheight = 0; }
    halfCone(double a, double b, double c, double r, double h, double h1) {
        x = a;
        y = b;
        z = c;
        halfheight = h1;
        radius = r;
        height = h;
    }
    void setCoordinate(double a, double b, double c) { x = a; y = b; z = c; }
    void setRadius(double r) { radius = r; }
    void setHeight(double h) { height = h; }
    double getRadius() { return radius; }
    double getHeight() { return height; }
    double area() {
        Cone a(x, y, z, radius, height);
        double scone = a.area();
        double rmin = ((height - halfheight) * radius) / height;
        double minheight = height - halfheight;
        double lmin = sqrt(minheight * minheight + rmin * rmin);
        double spmin = pi * rmin * lmin;
        double somin = pi * rmin * rmin;
        return (scone - spmin + somin);
    }
    double volume() {
        double minheight = height - halfheight;
        double rmin = ((height - halfheight) * radius) / height;
        Cone a(x, y, z, radius, height), b(x, y, z, rmin, minheight);
        double v1, v2;
        v1 = a.volume();
        v2 = b.volume();
        // cout << v1 << "  " << v2;
        return v1 - v2;
    }
    friend ostream& operator<<(ostream& stream, halfCone obj);
    istream& operator>> (istream& stream)
    {
        stream >> x;
        stream >> y;
        stream >> z;
        stream >> radius;
        stream >> halfheight;
        stream >> height;
        ;
        return stream;
    }

};

ostream& operator<<(ostream& stream, halfCone obj) {
    stream << "(" << obj.x << "; ";
    stream << obj.y << "; ";
    stream << obj.z << ") ";
    stream << "r=" << obj.radius << " ";
    stream << "hh=" << obj.halfheight << " ";
    stream << "h=" << obj.height << "\n";
    return stream;;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Cone c1(3, 7);
    Cone c2(1, 2, 3, 5, 10);

    cout << "Конус 1: " << c1;
    cout << "Площадь поверхности: " << c1.area() << "\n";
    cout << "Объём: " << c1.volume() << "\n";

    cout << "Конус 2: " << c2;
    cout << "Площадь поверхности: " << c2.area() << "\n";
    cout << "Объём: " << c2.volume() << "\n";
    halfCone c3(1, 2, 3, 5, 10, 5);
    cout << "Конус 3: " << c3;
    cout << "Площадь поверхности: " << c3.area() << "\n";
    cout << "Объём: " << c3.volume() << "\n";

    halfCone c4(1, 2, 3, 2, 10, 2);
    cout << "конус 4: " << c4;
    cout << "площадь роверхности: " << c4.area() << "\n";
    cout << "объём: " << c4.volume() << "\n";

    Cone c5(1, 2, 3, 5, 10);
    halfCone c5_1(1, 2, 3, 5, 10, 2);
    halfCone c5_2(1, 2, 3, 5, 10, 4);
    halfCone c5_3(1, 2, 3, 5, 10, 8);
    cout << "конус 5_1: " << c5_1;
    cout << "площадь роверхности: " << c5_1.area() << "\n";
    cout << "объём: " << c5_1.volume() << "\n";
    cout << "конус 5_2: " << c5_2;
    cout << "площадь роверхности: " << c5_2.area() << "\n";
    cout << "объём: " << c5_2.volume() << "\n";
    cout << "конус 5_3: " << c5_3;
    cout << "площадь роверхности: " << c5_3.area() << "\n";
    cout << "объём: " << c5_3.volume() << "\n";
    return 0;
}