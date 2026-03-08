

#include "Patient.h"
#include "Doctor.h"
#include <string>
using namespace std;

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
    string reason;

public:
    // Constructors
    Appointment();
    Appointment(Patient p, Doctor d, Date dt, Time tm, string r);

    // Getters
    Patient getPatient() const;
    Doctor getDoctor() const;
    Date getDate() const;
    Time getTime() const;
    string getReason() const;

    // Setters
    void setPatient(Patient p);
    void setDoctor(Doctor d);
    void setDate(Date dt);
    void setTime(Time tm);
    void setReason(string r);

    // Display
    void display() const;
};

