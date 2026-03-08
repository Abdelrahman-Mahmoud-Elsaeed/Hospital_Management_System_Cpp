#include "Appointment.h"
#include <iostream>
#include <iomanip>
using namespace std;



Appointment::Appointment(Patient p, Doctor d, Date dt, Time tm, string r)
    : patient(p), doctor(d), date(dt), time(tm), reason(r) {
}

Patient Appointment::getPatient() const {
    return patient;
}

Doctor Appointment::getDoctor() const {
    return doctor;
}

Date Appointment::getDate() const {
    return date;
}

Time Appointment::getTime() const {
    return time;
}

string Appointment::getReason() const {
    return reason;
}

void Appointment::setPatient(Patient p) {
    patient = p;
}

void Appointment::setDoctor(Doctor d) {
    doctor = d;
}

void Appointment::setDate(Date dt) {
    date = dt;
}

void Appointment::setTime(Time tm) {
    time = tm;
}

void Appointment::setReason(string r) {
    reason = r;
}

void Appointment::display() const {
    cout << "\n========================================" << endl;
    cout << "       APPOINTMENT DETAILS" << endl;
    cout << "========================================" << endl;

    cout << "Date: " << setfill('0') << setw(2) << date.day << "/"
        << setw(2) << date.month << "/" << date.year << endl;

    cout << "Time: " << setfill('0') << setw(2) << time.hour << ":"
        << setw(2) << time.minute << endl;

    cout << "Reason: " << reason << endl;

    cout << "========================================\n" << endl;
}