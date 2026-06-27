/*
 * PROJECT : DAY11
 * FILE    : pimpl.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : Pointer to Impl
 */
#include "pimpl.hpp"
#include <iostream>

// 实现pimpl
class Line::pimpl {
public:
    pimpl(int x1, int y1, int x2, int y2)
        : p1_{x1, y1},
          p2_{x2, y2} {}

    void printPlimpl() const {
        std::cout << "(";
        this->p1_.printPoint();
        std::cout << ",";
        this->p2_.printPoint();
        std::cout << ")";
    }

private:
    class point {
    public:
        point(int x, int y)
            : x_{x},
              y_{y} {}
        void printPoint() const { std::cout << "(" << this->x_ << "," << this->y_ << ")"; }

    private:
        int x_;
        int y_;
    };

    point p1_;
    point p2_;
};

Line::Line(int x1, int y1, int x2, int y2)
    : pimpl_{new pimpl{x1, y1, x2, y2}} {}

void Line::printLine() const { this->pimpl_->printPlimpl(); }

Line::~Line() {
    delete pimpl_;
    pimpl_ = nullptr;
}
