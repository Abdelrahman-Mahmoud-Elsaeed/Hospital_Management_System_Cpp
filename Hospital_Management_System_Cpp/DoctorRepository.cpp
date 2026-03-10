#include "DoctorRepository.h"
#include <sstream>
#include <iostream>

DoctorRepository::DoctorRepository(const FileManager& fm) : fileManager(fm) {}

std::string DoctorRepository::serialize(const Doctor& doctor) const {
    return std::to_string(doctor.getId()) + "," +
        doctor.getName() + "," +
        std::to_string(doctor.getAge()) + "," +
        doctor.getGender() + "," +
        doctor.getPhone() + "," +
        doctor.getEmail() + "," +
        doctor.getSpecialization() + "," +
        std::to_string(doctor.getExperience());
}

std::optional<Doctor> DoctorRepository::deserialize(const std::string& line) const {
    if (line.empty()) return std::nullopt;

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 8) {
        std::cerr << "Data corruption detected in doctor data: " << line << "\n";
        return std::nullopt;
    }

    try {
        int id = std::stoi(tokens[0]);
        std::string name = tokens[1];
        int age = std::stoi(tokens[2]);
        std::string gender = tokens[3];
        std::string phone = tokens[4];
        std::string email = tokens[5];
        std::string specialization = tokens[6];
        int experience = std::stoi(tokens[7]);

        return Doctor(name, id, age, gender, phone, email, specialization, experience);
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing doctor data: " << e.what() << "\n";
        return std::nullopt;
    }
}

void DoctorRepository::addDoctor(const Doctor& doctor) const {
    fileManager.appendLine(FILE_PATH, serialize(doctor));
}

std::vector<Doctor> DoctorRepository::getAllDoctors() const {
    std::vector<Doctor> doctors;
    std::vector<std::string> lines = fileManager.readAllLines(FILE_PATH);

    for (const std::string& line : lines) {
        std::optional<Doctor> d = deserialize(line);
        if (d.has_value()) {
            doctors.push_back(d.value());
        }
    }
    return doctors;
}

std::optional<Doctor> DoctorRepository::getDoctorById(int id) const {
    std::vector<Doctor> doctors = getAllDoctors();
    for (const Doctor& d : doctors) {
        if (d.getId() == id) {
            return d;
        }
    }
    return std::nullopt;
}

void DoctorRepository::updateDoctor(const Doctor& doctor) const {
    std::vector<std::string> lines = fileManager.readAllLines(FILE_PATH);
    bool found = false;

    for (size_t i = 0; i < lines.size(); ++i) {
        std::optional<Doctor> d = deserialize(lines[i]);
        if (d.has_value() && d.value().getId() == doctor.getId()) {
            lines[i] = serialize(doctor);
            found = true;
            break;
        }
    }

    if (found) fileManager.writeAllLines(FILE_PATH, lines);
    else std::cerr << "Doctor with ID " << doctor.getId() << " not found.\n";
}

void DoctorRepository::deleteDoctor(int id) const {
    std::vector<std::string> lines = fileManager.readAllLines(FILE_PATH);
    std::vector<std::string> updatedLines;
    bool found = false;

    for (const std::string& line : lines) {
        std::optional<Doctor> d = deserialize(line);
        if (d.has_value() && d.value().getId() == id) {
            found = true;
            continue;
        }
        updatedLines.push_back(line);
    }

    if (found) fileManager.writeAllLines(FILE_PATH, updatedLines);
    else std::cerr << "Doctor with ID " << id << " not found.\n";
}