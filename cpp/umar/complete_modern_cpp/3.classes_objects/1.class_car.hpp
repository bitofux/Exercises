/*
 * PROJECT : EXERCISES
 * FILE    : 1.class_car.hpp
 * AUTHOR  : bitofux
 * DATE    : 2026-09-13
 * BRIEF   : 获取或修改某对象的状态，获取或修改对象之间的状态以及共享数据
 */

#pragma once

class Car {
private:
    // 燃油量
    float fuel;
    // 速度
    float speed;
    // 乘客数量
    int passengers;

public:
    // 无参构造函数
    Car();
    // 参数化构造函数
    Car(float amount);
    // 析构函数
    ~Car();
    // 加油
    void FillFuel(float amount);
    // 加速
    void Accelerate();
    // 刹车
    void Break();
    // 增加乘客
    void AddPassengers(int count);
    // 查看汽车状态
    void Dashboard();
};
