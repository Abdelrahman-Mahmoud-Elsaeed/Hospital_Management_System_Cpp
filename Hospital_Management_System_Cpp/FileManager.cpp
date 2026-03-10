#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <filesystem>

std::vector<std::string> FileManager::readAllLines(const std::string& path) const {
    std::vector<std::string> lines;
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << path << "\n";
        return lines;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

std::string FileManager::readLine(const std::string& path, int index) const {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << path << "\n";
        return "";
    }

    std::string line;
    int current_line = 0;

    while (std::getline(file, line)) {
        if (current_line == index) {
            file.close();
            return line;
        }
        current_line++;
    }

    file.close();
    return "";
}

void FileManager::writeAllLines(const std::string& path, const std::vector<std::string>& lines) const {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << path << "\n";
        return;
    }

    for (const std::string& line : lines) {
        file << line << "\n";
    }

    file.close();
}

void FileManager::writeToLine(const std::string& path, const std::string& line, int index) const {
    std::vector<std::string> lines = readAllLines(path);
    if (index < 0 || index >= lines.size()) {
        std::cerr << "Index out of range: " << index << "\n";
        return;
    }

    lines[index] = line;
    writeAllLines(path, lines);
}

void FileManager::appendLine(const std::string& path, const std::string& line) const {
    std::ofstream file(path, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file for appending: " << path << "\n";
        return;
    }

    file << line << "\n";
    file.close();
}

bool FileManager::fileExists(const std::string& path) const {
    return std::filesystem::exists(path);
}

void FileManager::clearFile(const std::string& path) const {
    std::ofstream file(path, std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Error opening file to clear: " << path << "\n";
        return;
    }

    file.close();
}