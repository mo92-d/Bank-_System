#pragma once
#include "Client.h" 
class Employee : public Person
{
	double salary;
	inline static int nextId = FilesHelper::getLast("EmployeeLastId.txt") + 1;
public:
	Employee() : salary(5000) {
		setId(nextId++);
	}
	Employee(string name, string password, double salary)
		: Person(name, password) {
		setSalary(salary);
		setId(nextId++);
	}

	void setSalary(double salary) {
		this->salary = Validation::validation_Salary(salary);
	}

	double getSalary() const {
		return salary;
	}
	void addClient(Client& client) {
		addclient.push_back(client);
		FilesHelper::saveClient(client);
	}
	void listClient()
	{
		for (auto& client : addclient) {
			client.display();
		}
	}
	Client* searchClient(int id) {
		for (auto& client : addclient) {
			if (client.getId() == id) {
				return &client;
			}
		}
		return nullptr;
	}
	void editClient(int id, string name, string password, double balance) {
		bool found = false;

		for (auto& client : addclient) {
			if (client.getId() == id) {
				Client* existingClient = searchClient(id);
				if (existingClient != nullptr) {
					client.setName(name);
					client.setPassword(password);
					client.setBalance(balance);
					found = true;
					delete existingClient;
				}
				break;
			}
		}
		if (found) {
			FilesHelper::clearFile("Client.txt", "ClientsLastId.txt");
			for (auto& client : addclient) {
				FilesHelper::saveClient(client);
			}
			cout << "Client updated successfully.\n";
		}
		else {
			cout << "Client not found!\n";
		}
		return;
	}
	void display() {
		Person::display();
		cout << "Salary : " << salary << endl;
	}
};
static vector<Employee> addemployee;