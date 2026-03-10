#pragma once

#include <string>

class User {
protected:
    std::string name;
    int id;
    int age;
    std::string gender;
    std::string phone;
    std::string email;

public:
    User();
    User(const std::string& name, int id, int age, const std::string& gender, const std::string& phone, const std::string& email);

    virtual ~User() = default;

    void setName(const std::string& n);
    std::string getName() const;

    void setId(int id);
    int getId() const;

    void setAge(int age);
    int getAge() const;

    void setGender(const std::string& gender);
    std::string getGender() const;

    void setPhone(const std::string& phone);
    std::string getPhone() const;

    void setEmail(const std::string& email);
    std::string getEmail() const;

    virtual void display() const;
};