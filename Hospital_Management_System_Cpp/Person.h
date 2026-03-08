#include <iostream>
using namespace std;
#include "string";

class Person
{
protected:
	string m_name;
	int m_id;
	int m_age;
	string m_gender;
	int m_phone;
	string m_email;

public:
	Person();

	 Person(string name, int id, int age, string gender, int phone, string email);

	void set_m_name(string n);
	string get_name();	
	void set_m_id(int id);
	int get_m_id();
	void set_m_age(int age);
	int get_m_age();
	void set_m_gender(string gender);
	string get_gender();
	void set_m_phone(int phone);
	int get_m_phone(int phone);	
	void set_m_email(string email);
	string get_email();

	void Desplay();
};