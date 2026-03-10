#include "Patient.h"
#include <iostream>

Patient::Patient() : User(), illness("") {}

Patient::Patient(const std::string& name, int id, int age, const std::string& gender, const std::string& phone, const std::string& email, const std::string& illness)
    : User(name, id, age, gender, phone, email), illness(illness) {
}

void Patient::setIllness(const std::string& illness) {
    this->illness = illness;
}

std::string Patient::getIllness() const {
    return illness;
}

void Patient::display() const {
    User::display();
    std::cout << "Diagnosis: " << illness << "\n";
}