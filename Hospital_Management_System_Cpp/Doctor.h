#pragma once

#include <string>
#include "User.h"

class Doctor : public User {
private:
    std::string specialization;
    int experience;

public:
    Doctor();
    Doctor(const std::string& name, int id, int age, const std::string& gender, const std::string& phone, const std::string& email, const std::string& specialization, int experience);

    void setSpecialization(const std::string& specialization);
    std::string getSpecialization() const;

    void setExperience(int experience);
    int getExperience() const;

    void display() const override;
};