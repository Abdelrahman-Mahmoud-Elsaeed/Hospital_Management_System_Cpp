#pragma once

#include <string>
#include "User.h"

class Patient : public User {
private:
    std::string illness;

public:
    Patient();
    Patient(const std::string& name, int id, int age, const std::string& gender, const std::string& phone, const std::string& email, const std::string& illness);

    void setIllness(const std::string& illness);
    std::string getIllness() const;

    void display() const override;
};