
#include "Person.h"
#include "Doctor.h"
using namespace std;
#include <iostream>


Doctor::Doctor(string name, int id, int age, string gender, int phone, string email, string spe, int exp) : Person(name, id, age, gender, phone, email) {

	m_specialization = spe;
	m_experience = exp;
};

void Doctor::Set_specialization(string Spe) {
	m_specialization = Spe;
}
string Doctor::get_specialization() {
	return m_specialization;
}
void Doctor::Set_exper(int exper) {
	m_experience = exper;
}
int Doctor::get_exper() {
	return m_experience;
}
void Doctor::Desplay() {
	Doctor::Desplay();

	cout << "My specialization " << m_specialization << endl << "my experience " << m_experience << endl;
}