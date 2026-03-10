#pragma once

#include "Appointment.h"
#include "FileManager.h"
#include "PatientRepository.h"
#include "DoctorRepository.h"
#include <vector>
#include <string>
#include <optional>

class AppointmentRepository {
private:
    FileManager fileManager;
    PatientRepository patientRepo;
    DoctorRepository doctorRepo;
    const std::string FILE_PATH = "appointments.txt";

    std::string serialize(const Appointment& appointment) const;
    std::optional<Appointment> deserialize(const std::string& line) const;

public:
    AppointmentRepository(const FileManager& fm, const PatientRepository& pr, const DoctorRepository& dr);

    void addAppointment(const Appointment& appointment) const;
    std::vector<Appointment> getAllAppointments() const;

    std::vector<Appointment> getAppointmentsByPatientId(int patientId) const;
    std::vector<Appointment> getAppointmentsByDoctorId(int doctorId) const;
};