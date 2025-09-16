#pragma once
#include "Validation.h"
class Person {
	int id;
	string name;
	string password;

public:
	Person() {
		id = 0;
	}
	Person(string name, string password) {
		setName(name);
		setPassword(password);
	}
	void setName(string name) {
		if (Validation::validation_Name(name)) {
			this->name = name;
		}
		else {
			cout << "Invalid name" << endl;
		}
	}
	void setPassword(string password) {
		if (Validation::validation_Password(password)) {
			this->password = password;
		}
		else {
			cout << "Invalid password" << endl;
		}
	}
	void setId(int id) {
		this->id = id;
	}
	string getName() const {
		return name; 
	}
	string getPassword() const {
		return password;
	}
	int getId() const { 
		return id;
	}
	virtual void display(){
		cout << "Id : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Password : " << password << endl;
	}
};
