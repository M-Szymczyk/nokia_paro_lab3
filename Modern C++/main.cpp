#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

//
//}
//    if (first == nullptr || second == nullptr)
//        return false;
//    return (first->getArea() < second->getArea());
//}

//bool areaLessThan10(shared_ptr<Shape> s) {
//
//}

void printCollectionElements(const Collection &collection) {
    for (const auto &it: collection)
        if (it)
            it->print();
}

void printAreas(const Collection &collection) {
    for (const auto &it: collection)
        if (it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection &collection,
                                     std::function<bool(shared_ptr<Shape> s)>predicate,
                                     std::string info) {
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibonacciNumber(int n) {
    int prevNum = 1, prevPrevNum = 0, result = 0;
    for (auto i = 0; i < n-1; i++) {
        result = prevNum + prevPrevNum;
        prevPrevNum = prevNum;
        prevNum = result;
    }
    return result;
}

int main() {
    constexpr auto result = fibonacciNumber(44);
    cout << " 4 fibonacci Number is: " << result << endl;
    Collection shapes{make_shared<Circle>(2.0), make_shared<Circle>(3.0), nullptr, make_shared<Circle>(4.0),
                      make_shared<Rectangle>(10.0, 5.0), make_shared<Square>(3.0), make_shared<Circle>(4.0)};

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> first, shared_ptr<Shape> second) -> bool {
        return !(first == nullptr || second == nullptr) && (first->getArea() < second->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, [](shared_ptr<Shape> s) -> auto { return s && (s->getPerimeter() > 20); },
                                    "perimeter bigger than 20");

    findFirstShapeMatchingPredicate(shapes, [x = 10](shared_ptr<Shape> s) -> auto { return s && (s->getArea() < x); },
                                    "area less than 10");


    return 0;
}

