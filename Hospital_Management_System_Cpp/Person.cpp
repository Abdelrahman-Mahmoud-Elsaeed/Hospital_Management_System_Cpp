using namespace std;
#include "string"
#include "Person.h"
#include <iostream>

Person::Person() {};

Person::Person(string name, int id, int age, string gender, int phone, string email) {
	m_name = name;
	m_id = id;
	m_age = age;
	m_gender = gender;
	m_phone = phone;
	m_email = email;
}

void Person::set_m_name(string n) {
	m_name = n;
}
string Person::get_name() {
	return m_name;
}
void Person::set_m_id(int id) {
	m_id = id;
}
int Person::get_m_id() {
	return m_id;
}
void Person::set_m_age(int age) {
	m_age = age;
}
int Person::get_m_age() {
	return m_age;
}
void Person::set_m_gender(string gender) {
	m_gender = gender;
}
string Person::get_gender() {
	return m_gender;
}
void Person::set_m_phone(int phone) {
	m_phone = phone;
}
int Person::get_m_phone(int phone) {
	return m_phone;
}
void Person::set_m_email(string email) {
	m_email = email;
}
string Person::get_email() {
	return m_email;
}
void Person::Desplay() {
	cout << "my name is  " << m_name << endl << " ID " << m_id << endl << m_age << "Years old " << endl << "gender is " << m_gender << endl << "My phone is " << m_phone << endl << "Email " << m_email << endl;
}