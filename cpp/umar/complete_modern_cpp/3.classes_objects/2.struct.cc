/*
 * PROJECT : EXERCISES
 * FILE    : 2.struct.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-17
 * BRIEF   : 结构体 
 */
#include <iostream>

struct Point {
    int x;
    int y;
};

void DrawLine(Point start,Point end) {
    std::cout << "(" << start.x << "," << start.y << ")\n"; 
    std::cout << "(" << end.x << "," << end.y << ")\n"; 
}

