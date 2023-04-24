#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

const double pi = 3.14159265;

class ocean {
public:
    string ocean_name, ocean_location;
    double ocean_v, ocean_h, ocean_s;
    ocean() { ocean_name = ocean_location = ocean_v = ocean_h = ocean_s = 0; }
    ocean(string a, string b, double c, double d, double e) {
        ocean_name = a;
        ocean_location = b;
        ocean_v = c;
        ocean_h = d;
        ocean_s = e;
    }
    void printocean() {
        cout << "name: " << ocean_name << "\n ";
        cout << "location: " << ocean_location << "\n ";
        cout << "v: " << ocean_v << "\n ";
        cout << "h: " << ocean_h << " ";
        cout << "s: " << ocean_s << "\n";
    }
    istream& operator>> (istream& stream)
    {
        stream >> ocean_name;
        stream >> ocean_location;
        stream >> ocean_v;
        stream >> ocean_h;
        stream >> ocean_s;
        ;
        return stream;
    }

    friend ostream& operator<<(ostream& stream, ocean obj);
};
ostream& operator<<(ostream& stream, ocean obj) {
    stream << "name: " << obj.ocean_name << "\n ";
    stream << "location: " << obj.ocean_location << "\n ";
    stream << "v: " << obj.ocean_v << "\n ";
    stream << "h: " << obj.ocean_h << " ";
    stream << "s: " << obj.ocean_s << "\n";
    return stream;
}

class sea :public ocean {
public:
    string sea_name, sea_location;
    double sea_v, sea_h, sea_s;
    sea() { sea_name = sea_location = sea_v = sea_h = sea_s = 0; }
    sea(string a, string b, double c, double d, double e) {
        sea_name = a;
        sea_location = b;
        sea_v = c;
        sea_h = d;
        sea_s = e;
    }
    istream& operator>> (istream& stream)
    {
        stream >> sea_name;
        stream >> sea_location;
        stream >> sea_v;
        stream >> sea_h;
        stream >> sea_s;
        ;
        return stream;
    }

    friend ostream& operator<<(ostream& stream, sea obj);
};
ostream& operator<<(ostream& stream, sea obj) {
    stream << "name: " << obj.sea_name << "\n ";
    stream << "location: " << obj.sea_location << "\n ";
    stream << "v: " << obj.sea_v << "\n ";
    stream << "h: " << obj.sea_h << " ";
    stream << "s: " << obj.sea_s << "\n";
    return stream;
}

class zaliv : public sea {
public:
    string zaliv_name, zaliv_location;
    double zaliv_v, zaliv_h, zaliv_s;
    zaliv() { zaliv_name = zaliv_location = zaliv_v = zaliv_h = zaliv_s = 0; }
    zaliv(string f, string g, double h, double i, double j) {
        zaliv_name = f;
        zaliv_location = g;
        zaliv_v = h;
        zaliv_h = i;
        zaliv_s = j;
    }
    istream& operator>> (istream& stream)
    {
        stream >> zaliv_name;
        stream >> zaliv_location;
        stream >> zaliv_v;
        stream >> zaliv_h;
        stream >> zaliv_s;
        ;
        return stream;
    }

    friend ostream& operator<<(ostream& stream, zaliv obj);

};
ostream& operator<<(ostream& stream, zaliv obj) {
    stream << "name: " << obj.zaliv_name << "\n ";
    stream << "location: " << obj.zaliv_location << "\n ";
    stream << "v: " << obj.zaliv_v << "\n ";
    stream << "h: " << obj.zaliv_h << " ";
    stream << "s: " << obj.zaliv_s << "\n";
    stream << "name: " << obj.sea_name << "\n ";
    stream << "location: " << obj.sea_location << "\n ";
    stream << "v: " << obj.sea_v << "\n ";
    stream << "h: " << obj.sea_h << " ";
    stream << "s: " << obj.sea_s << "\n";
    return stream;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    ocean a("a", "local", 1, 1, 1);
    sea b("b", "local", 1, 1, 1);
    zaliv c("c", "local", 1, 1, 1);
    cout << a << b << c;
    c.printocean();
    return 0;
}