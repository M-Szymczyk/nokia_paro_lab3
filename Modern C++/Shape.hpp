#pragma once

#include "Color.h"

class Shape {
public:
    Color color = Color::BLUE;

    explicit Shape(Color c) : color(c) {};

    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    virtual void print() const;
};
