using namespace std;
#include <iostream>
#include "Person.h"
#include "string "

class Patient : public Person {

protected:

	string m_Inless;

public:
	Patient(string name, int id, int age, string gender, int phone, string email, string Inless) : Person(name, id, age, gender, phone, email) {};

	void set_m_Inless(string Inless);

	string get_m_Inless();

	void Desplay();

};