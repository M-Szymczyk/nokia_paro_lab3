#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(double x, double y);

    Rectangle(double x, double y, Color color);

    Rectangle() = delete;

    Rectangle(const Rectangle &other) = default;

    Rectangle(Rectangle&& rectangle) noexcept;

    Rectangle& operator =(Rectangle && rectangle) noexcept;

    double getArea() const override;

    double getPerimeter() const override;

    virtual double getX() const final;

    auto getY() const;

    void print() const override;

private:

    double x_;
    double y_;
};
