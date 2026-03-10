#include "Doctor.h"
#include <iostream>

Doctor::Doctor() : User(), specialization(""), experience(0) {}


Doctor::Doctor(const std::string& name, int id, int age, const std::string& gender, const std::string& phone, const std::string& email, const std::string& specialization, int experience)
    : User(name, id, age, gender, phone, email), specialization(specialization), experience(experience) {
}

void Doctor::setSpecialization(const std::string& specialization) {
    this->specialization = specialization;
}

std::string Doctor::getSpecialization() const {
    return specialization;
}

void Doctor::setExperience(int experience) {
    this->experience = experience;
}

int Doctor::getExperience() const {
    return experience;
}

void Doctor::display() const {
    User::display();

    std::cout << "Specialization: " << specialization << "\n"
        << "Experience: " << experience << " years\n";
}