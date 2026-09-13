/*
 * PROJECT : EXERCISES
 * FILE    : 1.class_car.hpp
 * AUTHOR  : bitofux
 * DATE    : 2026-09-13
 * BRIEF   : 获取或修改某对象的状态，获取或修改对象之间的状态以及共享数据
 */

#ifndef EXERCISES_1_CLASS_CAR_HPP_
#define EXERCISES_1_CLASS_CAR_HPP_

class Car {
private:
    float fuel;
    float speed;
    int passengers;

public:
    void FillFuel(float amount);
    void Accelerate();
    void Break();
    void AddPassengers(int count);
    void Dashboard();
};

#endif  // EXERCISES_1_CLASS_CAR_HPP_
