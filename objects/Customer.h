//
// Created by Gamidoi on 5/3/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_CUSTOMER_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_CUSTOMER_H
using namespace std;
#include <string>

class Customer {
private:
	string customerName;
	string customerAddress;
	string customerPhone;
	int customerID;
public:
	Customer(){customerName = ""; customerAddress = ""; customerPhone = "";}
	Customer(string customerName, string customerAddress, string customerPhone): customerName(customerName), customerAddress(customerAddress), customerPhone(customerPhone){}
	string getSQLInsert();
	string getSQLUpdate();

	string getName() const {return customerName;}
	string getAddress() const {return customerAddress;}
	string getPhone() const {return customerPhone;}
	int getID() const {return customerID;}

	void setName(string customerName) {this->customerName = customerName;}
	void setAddress(string customerAddress) {this->customerAddress = customerAddress;}
	void setPhone(string customerPhone) {this->customerPhone = customerPhone;}
	void setID(int customerID) {this->customerID = customerID;}
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_CUSTOMER_H