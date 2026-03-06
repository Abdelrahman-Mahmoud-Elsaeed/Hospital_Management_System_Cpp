#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;



class StorageManager
{
private:
	string DATA_FOLDER = "./storage/";
	ofstream patients;
	ofstream doctors;
	ofstream appointments;
public:
	void savePatient() {}
	void loadPatients() {}
	void saveDoctor() {}
	void loadDoctors() {}
	void saveAppointment() {}
};

