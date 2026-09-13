/*
 * PROJECT : EXERCISES
 * FILE    : 1.class_car.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-13
 * BRIEF   :
 */
#include "1.class_car.hpp"
#include <iostream>

void Car::FillFuel(float amount) { fuel = amount; }

void Car::Accelerate() {
    speed++;
    fuel -= 0.5f;
}

void Car::Break() { speed = 0; }

void Car::AddPassengers(int count) { passengers = count; }

void Car::Dashboard() {
    std::cout << "Fuel: " << fuel << std::endl;
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Passengers: " << passengers << std::endl;
}
