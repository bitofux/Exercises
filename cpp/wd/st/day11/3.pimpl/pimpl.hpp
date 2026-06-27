/*
 * PROJECT : DAY11
 * FILE    : pimpl.hpp
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : Pointer to Impl
 */

#ifndef DAY11_PIMPL_HPP_
#define DAY11_PIMPL_HPP_

class Line {
public:
    Line(int x1, int y1, int x2, int y2);
    ~Line();

    void printLine() const;

private:
    // 前向声明
    class pimpl;
    pimpl* pimpl_;
};

#endif  // DAY11_PIMPL_HPP_
