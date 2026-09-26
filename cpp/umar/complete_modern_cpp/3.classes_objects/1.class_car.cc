/*
 * PROJECT : EXERCISES
 * FILE    : 1.class_car.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-13
 * BRIEF   :
 */
#include "1.class_car.hpp"
#include <iostream>

// 静态成员变量初始化
int Car::totalCars;

Car::Car()
    : Car(0) {
    std::cout << "Car()" << std::endl;
}

Car::Car(float amount)
    : Car(amount, 0) {
    std::cout << "Car(float)" << std::endl;
}

Car::Car(float amount, int pass) {
    std::cout << "Car(float,int)" << std::endl;
    ++totalCars;
    fuel = amount;
    speed = 0;
    passengers = pass;
}

Car::~Car() {
    --totalCars;
    std::cout << "~Car()\n";
}

void Car::FillFuel(float amount) { fuel = amount; }

void Car::Accelerate() {
    // 增加速度的值
    speed++;
    // 减少燃料的值
    fuel -= 0.5f;
}

void Car::Break() { speed = 0; }

void Car::AddPassengers(int count) { passengers = count; }

void Car::Dashboard() const {
    std::cout << "Fuel: " << fuel << std::endl;
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Passengers: " << passengers << std::endl;
}

void Car::ShowCount() { std::cout << "Total Cars: " << Car::totalCars << "\n"; }
