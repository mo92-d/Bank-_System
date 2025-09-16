#pragma once
#include "Employee.h"
class Admin : public Employee {
	inline static int nextId = FilesHelper::getLast("AdminLastId.txt") + 1;
public:
	Admin() {}
	Admin(string name, string password, double salary)
		: Employee(name, password, salary) {
		setId(nextId++);
	}
	void addEmployee(Employee& employee){
		addemployee.push_back(employee);
		FilesHelper::saveEmployee(employee);
	}
	Employee* searchEmployee(int id) {
		for (auto& employee : addemployee) {
			if (employee.getId() == id) {
				return &employee;
			}
		}
		return nullptr;
	}
	void editEmployee(int id, string name, string password, double salary) {

		bool found = false;
		for (auto& employee : addemployee) {
			if (employee.getId() == id) {
				Client* existingemployee = searchClient(id);
				if (existingemployee != nullptr) {
					employee.setName(name);
					employee.setPassword(password);
					employee.setSalary(salary);
					found = true;
					delete existingemployee;
				}
				break;
			}
		}
		if (found) {
			FilesHelper::clearFile("Employee.txt", "EmployeesLastId.txt");
			for (auto& employee : addemployee) {
				FilesHelper::saveEmployee(employee);
			}
			cout << "Employee updated successfully.\n";
		}
		else {
			cout << "Employee not found!\n";
		}
	}
	void listClient()
	{
		for (auto& employee : addemployee) {
			employee.display();
		}
	}
};
static vector<Admin> addadmin;