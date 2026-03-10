#pragma once

#include "Patient.h"
#include "Doctor.h"
#include <string>

struct Date {
    int year;
    int month;
    int day;
};

struct Time {
    int hour;
    int minute;
};

class Appointment {
private:
    Patient patient;
    Doctor doctor;
    Date date;
    Time time;
    std::string reason;

public:
    // Constructors
    Appointment();
    Appointment(const Patient& p, const Doctor& d, const Date& dt, const Time& tm, const std::string& r);

    const Patient& getPatient() const;
    const Doctor& getDoctor() const;
    Date getDate() const;
    Time getTime() const;
    std::string getReason() const;

    void setPatient(const Patient& p);
    void setDoctor(const Doctor& d);
    void setDate(const Date& dt);
    void setTime(const Time& tm);
    void setReason(const std::string& r);

    void display() const;
};