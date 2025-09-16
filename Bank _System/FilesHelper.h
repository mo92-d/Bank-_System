#pragma once
#include <string>
#include <vector>
using namespace std;

class Client;
class Employee;
class Admin;
class FilesHelper
{
public:
    static void saveLast(const string& fileName, int id);
    static int getLast(string fileName);
    static void saveClient(const Client& client);
    static void saveEmployee(const Employee& employee);
    static void saveAdmin(const Admin& admin);
    static void getClients();
    static void getEmployees();
    static void getAdmins();
    static void clearFile(const string& fileName, const string& lastIdFile);
};

