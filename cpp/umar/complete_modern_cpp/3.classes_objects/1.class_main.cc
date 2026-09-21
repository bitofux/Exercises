/*
 * PROJECT : EXERCISES
 * FILE    : 1.class_main.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-13
 * BRIEF   :
 */
#include "1.class_car.hpp"

int main() {
    Car car_one;
    car_one.Dashboard();

    Car car_two{10.2f};
    car_two.Dashboard();
}
