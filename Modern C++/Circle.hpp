#pragma once

#include "Shape.hpp"

class Circle final : public Shape {
public:
    explicit Circle(double r);

    Circle(const Circle &other) = default;

    Circle(double r, Color color);

    Circle(Circle && circle) noexcept;
    Circle& operator=(Circle&& circle ) noexcept;

    double getArea() const noexcept override;

    double getPerimeter() const noexcept override;

    auto getRadius() const;

    [[deprecated]] double getPi() ;

    void print() const override;

    Circle() = delete; // doesn't allow to call default constructor
private:

    double r_;
};
