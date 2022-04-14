#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    explicit Square(double x);

    Square() = delete;

    Square(const Square &other) = default;

    Square(Square && square)noexcept;

    Square& operator=(Square && square)noexcept;

    [[nodiscard]] double getArea() const override;

    [[nodiscard]] double getPerimeter() const override;

    double getY()  = delete;

    void print() const override;

    // rule of 5 missing copy assigment!
private:
};
