#pragma once
//class Employee;
//class Admin;
//class Client;
#include "Employee.h"
#include "Client.h"
#include "Admin.h"
#include <vector>
#include <sstream>
#include <fstream>
class Parser
{
public:
	static vector<string> split(string line) {

		stringstream ss(line);
		string part;
		vector<string>parts;
		while (getline(ss, part, '|')) {
			parts.push_back(part);
		}
		return parts;
	}
	static Client parseToClient(string line) {
		Client client;
		vector<string>parts = split(line);
		client.setId(stoi(parts[0]));
		client.setName(parts[1]);
		client.setPassword(parts[2]);
		client.setBalance(stod(parts[3]));
		return client;
	}
	static Employee parseToEmployee(string line) {
		Employee employee;
		vector<string>parts = split(line);
		employee.setId(stoi(parts[0]));
		employee.setName(parts[1]);
		employee.setPassword(parts[2]);
		employee.setSalary(stod(parts[3]));
		return employee;
	}
	static Admin parseToAdmin(string line) {
		Admin admin;
		vector<string>parts = split(line);
		admin.setId(stoi(parts[0]));
		admin.setName(parts[1]);
		admin.setPassword(parts[2]);
		admin.setSalary(stod(parts[3]));
		return admin;
	}
};
