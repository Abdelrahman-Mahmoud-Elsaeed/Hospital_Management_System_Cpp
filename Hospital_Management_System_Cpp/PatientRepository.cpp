#include "PatientRepository.h"
#include <sstream>
#include <iostream>

PatientRepository::PatientRepository(const FileManager& fm) : fileManager(fm) {}


std::string PatientRepository::serialize(const Patient& patient) const {
    return std::to_string(patient.getId()) + "," +
        patient.getName() + "," +
        std::to_string(patient.getAge()) + "," +
        patient.getGender() + "," +
        patient.getPhone() + "," +
        patient.getEmail() + "," +
        patient.getIllness();
}

std::optional<Patient> PatientRepository::deserialize(const std::string& line) const {
    if (line.empty()) return std::nullopt;

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 7) {
        std::cerr << "Data corruption detected in line: " << line << "\n";
        return std::nullopt;
    }

    try {
        int id = std::stoi(tokens[0]);
        std::string name = tokens[1];
        int age = std::stoi(tokens[2]);
        std::string gender = tokens[3];
        std::string phone = tokens[4];
        std::string email = tokens[5];
        std::string illness = tokens[6];

        return Patient(name, id, age, gender, phone, email, illness);
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing patient data: " << e.what() << "\n";
        return std::nullopt;
    }
}

void PatientRepository::addPatient(const Patient& patient) const {
    std::string line = serialize(patient);
    fileManager.appendLine(FILE_PATH, line);
}

std::vector<Patient> PatientRepository::getAllPatients() const {
    std::vector<Patient> patients;
    std::vector<std::string> lines = fileManager.readAllLines(FILE_PATH);

    for (const std::string& line : lines) {
        std::optional<Patient> p = deserialize(line);
        if (p.has_value()) {
            patients.push_back(p.value());
        }
    }
    return patients;
}

std::optional<Patient> PatientRepository::getPatientById(int id) const {
    std::vector<Patient> patients = getAllPatients();
    for (const Patient& p : patients) {
        if (p.getId() == id) {
            return p;
        }
    }
    return std::nullopt;
}

void PatientRepository::updatePatient(const Patient& patient) const {
    std::vector<std::string> lines = fileManager.readAllLines(FILE_PATH);
    bool found = false;

    for (size_t i = 0; i < lines.size(); ++i) {
        std::optional<Patient> p = deserialize(lines[i]);
        if (p.has_value() && p.value().getId() == patient.getId()) {
            lines[i] = serialize(patient);
            found = true;
            break;
        }
    }

    if (found) {
        fileManager.writeAllLines(FILE_PATH, lines);
    }
    else {
        std::cerr << "Patient with ID " << patient.getId() << " not found for update.\n";
    }
}

void PatientRepository::deletePatient(int id) const {
    std::vector<std::string> lines = fileManager.readAllLines(FILE_PATH);
    std::vector<std::string> updatedLines;
    bool found = false;

    for (const std::string& line : lines) {
        std::optional<Patient> p = deserialize(line);
        if (p.has_value() && p.value().getId() == id) {
            found = true;
            continue;
        }
        updatedLines.push_back(line);
    }

    if (found) {
        fileManager.writeAllLines(FILE_PATH, updatedLines);
    }
    else {
        std::cerr << "Patient with ID " << id << " not found for deletion.\n";
    }
}