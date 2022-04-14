#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double x, double y, Color color) : Shape(color), x_(x), y_(y) {}

Rectangle::Rectangle(double x, double y) : Shape(Color::RED), x_(x), y_(y) {}

double Rectangle::getArea() const {
    return x_ * y_;
}

double Rectangle::getPerimeter() const {
    return 2 * (x_ + y_);
}

double Rectangle::getX() const {
    return x_;
}

auto Rectangle::getY() const {
    return y_;
}

void Rectangle::print() const {
    std::cout << "Rectangle:   x: " << getX() << std::endl
              << "             y: " << getY() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}

Rectangle::Rectangle(Rectangle &&rectangle)noexcept: Shape(Color::BLUE) {
    x_ = rectangle.x_;
    y_ = rectangle.y_;
}

Rectangle  &Rectangle::operator=(Rectangle &&rectangle) noexcept{
    x_ = rectangle.x_;
    y_ = rectangle.y_;
    return *this;
}
