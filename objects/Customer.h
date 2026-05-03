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
public:
	Customer(){customerName = ""; customerAddress = ""; customerPhone = "";}
	Customer(string customerName, string customerAddress, string customerPhone);
	string getSQLInsert();

	string getName() const {return customerName;}
	string getAddress() const {return customerAddress;}
	string getPhone() const {return customerPhone;}

	void setName(string customerName) {this->customerName = customerName;}
	void setAddress(string customerAddress) {this->customerAddress = customerAddress;}
	void setPhone(string customerPhone) {this->customerPhone = customerPhone;}
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_CUSTOMER_H