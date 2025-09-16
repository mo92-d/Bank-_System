#pragma once
#include "Person.h"
#include <vector>
#include "FilesHelper.h"
using namespace std;
class Client : public Person {
	double balance;
	inline static int nextId = FilesHelper::getLast("ClientLastId.txt") + 1;
public:
	Client() : balance(1500) {
		setId(nextId++);
	}
	Client(string name, string password, double balance)
		: Person(name, password) {
		setBalance(balance);
		setId(nextId++);
	}

	void setBalance(double balance) {
		this->balance = Validation::validation_Balance(balance);
	}
	double getBalance() const { return balance; }

	void deposit(double amount) { balance += amount; }

	void withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
		}
		else {
			cout << "Amount Exceeded Balance" << endl;
		}
	}

	void transfer_to(double amount, Client& recipient) {
		if (amount <= balance) {
			balance -= amount;
			recipient.deposit(amount);
		}
		else {
			cout << "Amount Exceeded Balance" << endl;
		}
	}
	void checkBalance() const {
		cout << "Balance : " << balance << endl;
	}
	void display() {
		Person::display();
		cout << "Balance : " << balance << endl;
	}

};
static vector<Client> addclient;