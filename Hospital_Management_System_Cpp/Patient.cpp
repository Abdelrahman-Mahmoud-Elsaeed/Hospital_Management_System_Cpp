
using namespace std;
#include <iostream>
#include "string"
#include "Patient.h "

Patient::Patient(string name, int id, int age, string gender, int phone, string email, string Inless) : Person(name, id, age, gender, phone, email) {
	m_Inless = Inless;
};

void Patient::set_m_Inless(string Inless) {
	m_Inless = Inless;
}

string Patient::get_m_Inless() {
	return m_Inless;
}

void Patient::Desplay() {
	Person::Desplay();
	cout << "diagnosis  " << m_Inless << endl;

}