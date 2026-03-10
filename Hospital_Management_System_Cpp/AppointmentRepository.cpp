#include "AppointmentRepository.h"
#include <sstream>
#include <iostream>

AppointmentRepository::AppointmentRepository(const FileManager& fm, const PatientRepository& pr, const DoctorRepository& dr)
    : fileManager(fm), patientRepo(pr), doctorRepo(dr) {
}

std::string AppointmentRepository::serialize(const Appointment& appt) const {
    return std::to_string(appt.getPatient().getId()) + "," +
        std::to_string(appt.getDoctor().getId()) + "," +
        std::to_string(appt.getDate().year) + "," +
        std::to_string(appt.getDate().month) + "," +
        std::to_string(appt.getDate().day) + "," +
        std::to_string(appt.getTime().hour) + "," +
        std::to_string(appt.getTime().minute) + "," +
        appt.getReason();
}

std::optional<Appointment> AppointmentRepository::deserialize(const std::string& line) const {
    if (line.empty()) return std::nullopt;

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 8) {
        std::cerr << "Data corruption detected in appointment: " << line << "\n";
        return std::nullopt;
    }

    try {
        int patientId = std::stoi(tokens[0]);
        int doctorId = std::stoi(tokens[1]);
        Date date = { std::stoi(tokens[2]), std::stoi(tokens[3]), std::stoi(tokens[4]) };
        Time time = { std::stoi(tokens[5]), std::stoi(tokens[6]) };
        std::string reason = tokens[7];

        std::optional<Patient> p = patientRepo.getPatientById(patientId);
        std::optional<Doctor> d = doctorRepo.getDoctorById(doctorId);

        if (!p.has_value() || !d.has_value()) {
            std::cerr << "Foreign key constraint failed: Patient or Doctor not found.\n";
            return std::nullopt;
        }

        return Appointment(p.value(), d.value(), date, time, reason);
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing appointment data: " << e.what() << "\n";
        return std::nullopt;
    }
}

void AppointmentRepository::addAppointment(const Appointment& appointment) const {
    fileManager.appendLine(FILE_PATH, serialize(appointment));
}

std::vector<Appointment> AppointmentRepository::getAllAppointments() const {
    std::vector<Appointment> appointments;
    std::vector<std::string> lines = fileManager.readAllLines(FILE_PATH);

    for (const std::string& line : lines) {
        std::optional<Appointment> a = deserialize(line);
        if (a.has_value()) {
            appointments.push_back(a.value());
        }
    }
    return appointments;
}

std::vector<Appointment> AppointmentRepository::getAppointmentsByPatientId(int patientId) const {
    std::vector<Appointment> all = getAllAppointments();
    std::vector<Appointment> filtered;
    for (const auto& a : all) {
        if (a.getPatient().getId() == patientId) filtered.push_back(a);
    }
    return filtered;
}

std::vector<Appointment> AppointmentRepository::getAppointmentsByDoctorId(int doctorId) const {
    std::vector<Appointment> all = getAllAppointments();
    std::vector<Appointment> filtered;
    for (const auto& a : all) {
        if (a.getDoctor().getId() == doctorId) filtered.push_back(a);
    }
    return filtered;
}