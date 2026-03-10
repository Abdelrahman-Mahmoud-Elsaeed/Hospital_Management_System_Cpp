#pragma once

#include <string>
#include <vector>

class FileManager {
public:
    std::vector<std::string> readAllLines(const std::string& path) const;
    std::string readLine(const std::string& path, int index) const;

    void writeAllLines(const std::string& path, const std::vector<std::string>& lines) const;
    void writeToLine(const std::string& path, const std::string& line, int index) const;
    void appendLine(const std::string& path, const std::string& line) const;

    bool fileExists(const std::string& path) const;
    void clearFile(const std::string& path) const;
};