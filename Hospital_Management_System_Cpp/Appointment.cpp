#include "Appointment.h"
#include <iostream>
#include <iomanip>

Appointment::Appointment()
    : patient(), doctor(), date{ 0, 0, 0 }, time{ 0, 0 }, reason("") {
}

Appointment::Appointment(const Patient& p, const Doctor& d, const Date& dt, const Time& tm, const std::string& r)
    : patient(p), doctor(d), date(dt), time(tm), reason(r) {
}

const Patient& Appointment::getPatient() const {
    return patient;
}

const Doctor& Appointment::getDoctor() const {
    return doctor;
}

Date Appointment::getDate() const {
    return date;
}

Time Appointment::getTime() const {
    return time;
}

std::string Appointment::getReason() const {
    return reason;
}

void Appointment::setPatient(const Patient& p) {
    patient = p;
}

void Appointment::setDoctor(const Doctor& d) {
    doctor = d;
}

void Appointment::setDate(const Date& dt) {
    date = dt;
}

void Appointment::setTime(const Time& tm) {
    time = tm;
}

void Appointment::setReason(const std::string& r) {
    reason = r;
}

void Appointment::display() const {
    std::cout << "\n========================================\n"
        << "          APPOINTMENT DETAILS           \n"
        << "========================================\n";

    std::cout << "--- Patient Info ---\n";
    patient.display();

    std::cout << "\n--- Doctor Info ---\n";
    doctor.display();

    std::cout << "\n--- Schedule ---" << "\n"
        << "Date: " << std::setfill('0') << std::setw(2) << date.day << "/"
        << std::setw(2) << date.month << "/" << date.year << "\n"
        << "Time: " << std::setfill('0') << std::setw(2) << time.hour << ":"
        << std::setw(2) << time.minute << "\n"
        << "Reason: " << reason << "\n"
        << "========================================\n";
}