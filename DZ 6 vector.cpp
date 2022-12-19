// DZ 6 vector.cpp: определяет точку входа для приложения.
//

#include "DZ 6 vector.h"
#include <iostream>
#include <cmath>
#define M_PI 3.1415926


Vector2::Vector2() : x(0.0), y(0.0), p(0.0), phi(0.0) {};  //объявляет начало координат
Vector2::Vector2(double x, double y) : x(x), y(y), p(sqrt(x* x + y * y)), phi(atan2(y, x)) {}; //перевод в полярную систему координат

double Vector2::getLen() {      //вычисление длины вектора
    return sqrt(x * x + y * y);
}

double Vector2::getPhi() {      //вычисление угла
    return std::atan2(y, x);
}

Vector2 Vector2::operator+(const Vector2& vector) const {  //сложение
    return Vector2(x + vector.x, y + vector.y);
}

Vector2 Vector2::operator-(const Vector2& vector) const {   //вычитание
    return Vector2(x - vector.x, y - vector.y);
}

void Vector2::operator-=(const Vector2& vector) {       //вычитание
    x -= vector.x;
    y -= vector.y;
}

void Vector2::operator+=(const Vector2& vector) {    // сложение
    x += vector.x;
    y += vector.y;
}

void Vector2::operator*=(const double N) {         //умножение на число
    x *= N;
    y *= N;
}
void Vector2::operator/=(const double N) {        //деление на число
    if (N != 0) {
        x /= N;
        y /= N;
    }
}

Vector2 Vector2::operator/(const double N) const {   //деление на число
    if (N != 0) return Vector2(x / N, y / N);

}

Vector2 Vector2::operator*(const double N) const {    //умножение на число
    return Vector2(x * N, y * N);
}

bool Vector2::operator==(const Vector2& vector) const {   //сравнение
    return x == vector.x && y == vector.y;
}

bool Vector2::operator!=(const Vector2& vector) const {   //сравнение
    return x != vector.x or y != vector.y;
}

double Vector2::skew_scalar_product(const Vector2& vector) const {   // косое скалярное произведение
    return x * vector.y - vector.x * y;
}

double Vector2::scalar_product(const Vector2& vector) const {   //скалярное произведение
    return x * vector.x + y * vector.y;
}


void Vector2::norm() {        //норма
    double len = sqrt(x * x + y * y);
    x /= len;
    y /= len;
}


void Vector2::change_phi(double phi) {  //меняем угол
    phi = phi / 180 * M_PI;
    double t1 = x * cos(phi) - y * sin(phi);
    double t2 = x * sin(phi) + y * cos(phi);
    x = t1;
    y = t2;
}

void Vector2::change_len(const double N) {       //меняем длину
    double len = sqrt(x * x + y * y);
    x /= len;
    y /= len;
    x *= N;
    y *= N;
}

double Vector2::cos_phi(Vector2& vector) const {       //косинусное расстояние между векторами
    double len1 = sqrt(x * x + y * y);
    double len2 = vector.getLen();
    return (x * vector.x + y * vector.y) / (len1 * len2);
}

