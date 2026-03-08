
#include "Person.h"
using namespace std;
#include <iostream>

class Doctor : public Person {
protected:
	string m_specialization;
	int m_experience;

public:
	Doctor();
	Doctor(string name, int id, int age, string gender, int phone, string email, string spe, int exp) : Person(name, id, age, gender, phone, email) {};

	void Set_specialization(string Spe);
	string get_specialization();
	void Set_exper(int exper);
	int get_exper();
	void Desplay();
};