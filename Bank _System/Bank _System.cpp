#include <iostream>
#include "Employee.h"
#include "Admin.h"
#include "Client.h"
int main() {
	Client c1("Mohamed", "mypassword", 2000);
	Client c2("Mohamed", "mypassword", 2000);
	Client c3("Mohamed", "mypassword", 2000);
	Client c4("Mohamed", "mypassword", 2000);
	Employee e1("Alwjids", "securepass", 6000);
	Employee e2("Alwjids", "securepass", 6000);
	Employee e3("Alwjids", "securepass", 6000);
	Admin a1("Omarwi", "adminpass", 10000);
	Admin a2("Omarwi", "adminpass", 10000);
	Admin a3("Omarwi", "adminpass", 10000);

	/*c1.display();
	  e1.display();
	  a1.display();*/
	  //e1.getAllClients();
	  /*a1.addEmployee(e1);
		a1.getAllEmployees();*/
		//============================
	   e1.addClient(c1);
	   e1.addClient(c2);
	   e1.addClient(c3);
	   e1.addClient(c4);
		/*a1.addEmployee(e1);
		a1.addEmployee(e2);
		a1.addEmployee(e3);
	   e1.addClient(c4);
	   a1.addAdmin(a1);
	   a1.addAdmin(a2);
	   a1.addAdmin(a3);*/
	   //============================
	  /*a1.removeAllClients();
	  a1.removeAllEmployees();
	  a1.removeAllAdmins();*/

	   e1.listClient();

	return 0;
}
