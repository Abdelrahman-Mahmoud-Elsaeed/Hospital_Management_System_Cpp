#pragma once

#include "Patient.h"
#include "FileManager.h"
#include <vector>
#include <string>
#include <optional>

class PatientRepository {
private:
    FileManager fileManager;
    const std::string FILE_PATH = "patients.txt";

    std::string serialize(const Patient& patient) const;
    std::optional<Patient> deserialize(const std::string& line) const;

public:
    PatientRepository(const FileManager& fm);

    void addPatient(const Patient& patient) const;
    std::vector<Patient> getAllPatients() const;
    std::optional<Patient> getPatientById(int id) const;
    void updatePatient(const Patient& patient) const;
    void deletePatient(int id) const;
};