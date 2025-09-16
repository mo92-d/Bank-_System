#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class Client;
class Employee;
class Admin;
class FileManager:public DataSourceInterface
{
public:
	void addClient(const Client& client) {
		FilesHelper::saveClient(client);
	}
	void addEmployee(const Employee& employee){
		FilesHelper::saveEmployee(employee);
	}
	void addAdmin(const Admin& admin) {
		FilesHelper::saveAdmin(admin);
	}
    void getAllClients()  {
        FilesHelper::getClients();
    }

    void getAllEmployees()  {
        FilesHelper::getEmployees();
    }

    void getAllAdmins()  {
        FilesHelper::getAdmins();
    }

    void removeAllClients()  {
        FilesHelper::clearFile("Client.txt", "ClientsLastId.txt");
    }

    void removeAllEmployees()  {
        FilesHelper::clearFile("Employee.txt", "EmployeeLastId.txt");
    }

    void removeAllAdmins()  {
        FilesHelper::clearFile("Admin.txt", "AdminLastId.txt");
    }

};

