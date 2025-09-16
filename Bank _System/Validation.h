#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{

public:
	static bool validation_Name(string name) {
		if (name.size() < 5 || name.size() > 20) {
			return false;
		}
		for (int i = 0; i < name.size(); i++) {
			if (!(isalpha(name[i]) || name[i] == ' ')) {
				return false;
			}
		}

		return true;
	}
	static bool validation_Password(string password) {
		if (password.size() < 8 || password.size() > 20) {
			return false;
		}
		return true;
	}
	static double validation_Salary(double salary) {
		if (salary >= 5000) {
			return salary;
		}
		return 5000;
	}
	static double validation_Balance(double balance) {
		if (balance >= 1500) {
			return balance;
		}
		return 1500;
	}
};
