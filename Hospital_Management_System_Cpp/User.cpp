#include "User.h"
#include <iostream>

User::User() : id(0), age(0) {}

User::User(const std::string& name, int id, int age, const std::string& gender, const std::string& phone, const std::string& email)
    : name(name), id(id), age(age), gender(gender), phone(phone), email(email) {
}

void User::setName(const std::string& n) {
    name = n;
}

std::string User::getName() const {
    return name;
}

void User::setId(int id) {
    this->id = id;
}

int User::getId() const {
    return id;
}

void User::setAge(int age) {
    this->age = age;
}

int User::getAge() const {
    return age;
}

void User::setGender(const std::string& gender) {
    this->gender = gender;
}

std::string User::getGender() const {
    return gender;
}

void User::setPhone(const std::string& phone) {
    this->phone = phone;
}

std::string User::getPhone() const {
    return phone;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}

std::string User::getEmail() const {
    return email;
}

void User::display() const {
    std::cout << "Name: " << name << "\n"
        << "ID: " << id << "\n"
        << "Age: " << age << " Years old\n"
        << "Gender: " << gender << "\n"
        << "Phone: " << phone << "\n"
        << "Email: " << email << "\n";
}