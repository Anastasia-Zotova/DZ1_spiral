﻿// DZ 6 vector.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.
#ifndef HELLO_WORLD_VECTOR2_H
#define HELLO_WORLD_VECTOR2_H


class Vector2 {  //создаю класс
public:
    double x, y, p, phi;

    Vector2();
    Vector2(double x, double y);

    double getLen();

    double getPhi();
    Vector2 operator+(const Vector2& vector) const;
    Vector2 operator-(const Vector2& vector) const;
    void operator-=(const Vector2& vector);
    void operator+=(const Vector2& vector);
    void operator*=(const double N);
    void operator/=(const double N);
    Vector2 operator*(const double N) const;
    Vector2 operator/(const double N) const;
    bool operator==(const Vector2& vector) const;
    bool operator!=(const Vector2& vector) const;
    double skew_scalar_product(const Vector2& vector) const;
    double scalar_product(const Vector2& vector) const;
    void norm();
    void change_len(const double N);
    void change_phi(double phi);
    double cos_phi(Vector2& vector) const;
};

#endif //HELLO_WORLD_VECTOR2_H