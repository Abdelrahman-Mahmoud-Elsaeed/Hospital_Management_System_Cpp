#pragma once

#include "Doctor.h"
#include "FileManager.h"
#include <vector>
#include <string>
#include <optional>

class DoctorRepository {
private:
    FileManager fileManager;
    const std::string FILE_PATH = "data/doctors.txt";

    std::string serialize(const Doctor& doctor) const;
    std::optional<Doctor> deserialize(const std::string& line) const;

public:
    DoctorRepository(const FileManager& fm);

    void addDoctor(const Doctor& doctor) const;
    std::vector<Doctor> getAllDoctors() const;
    std::optional<Doctor> getDoctorById(int id) const;
    void updateDoctor(const Doctor& doctor) const;
    void deleteDoctor(int id) const;
};