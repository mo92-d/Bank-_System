#include "FilesHelper.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

#include <fstream>

void FilesHelper::saveLast(const string& fileName, int id) {
	fstream file(fileName, ios::out);
	file << id;
	file.close();
}

int FilesHelper::getLast(string fileName) {
	fstream file;
	file.open(fileName, ios::in);
	int id = 0;
	if (file >> id) {
		file.close();
		return id;
	}
	file.close();
	return 0;
}

void FilesHelper::saveClient(const Client& client) {
	int Id = getLast("ClientsLastId.txt");
	Id++;
	fstream file("Client.txt", ios::app);
	file << Id << "|" << client.getName() << "|"
		<< client.getPassword() << "|" << client.getBalance() << endl;
	file.close();
	saveLast("ClientsLastId.txt", Id);
}

void FilesHelper::saveEmployee(const Employee& employee) {
	int Id = getLast("EmployeeLastId.txt");
	Id++;
	fstream file("Employee.txt", ios::app);
	file << Id << "|" << employee.getName() << "|" << employee.getPassword() << "|" << employee.getSalary() << "\n";
	file.close();

	saveLast("EmployeeLastId.txt", Id);
}
void FilesHelper::saveAdmin(const Admin& admin) {
	int Id = getLast("AdminLastId.txt");
	Id++;
	fstream file("Admin.txt", ios::app);

	file << Id << "|" << admin.getName() << "|" << admin.getPassword() << "|" << admin.getSalary() << "\n";
	file.close();

	saveLast("AdminLastId.txt", Id);
}

void FilesHelper::getClients() {
	fstream file("Client.txt");
	string line;
	while (getline(file, line)) {
		addclient.push_back(Parser::parseToClient(line));
	}
	file.close();
}

void FilesHelper::getEmployees() {
	fstream file("Employee.txt");
	string line;
	while (getline(file, line)) {
		addemployee.push_back(Parser::parseToEmployee(line));
	}
	file.close();
}

void FilesHelper::getAdmins() {
	fstream file("Admin.txt");
	string line;
	while (getline(file, line)) {
		addadmin.push_back(Parser::parseToAdmin(line));
	}
	file.close();
}

void FilesHelper::clearFile(const string& fileName, const string& lastIdFile) {
	fstream file(fileName, ios::out);
	file.close();
	fstream lastFile(lastIdFile, ios::out);
	lastFile.close();
}