//
// Created by Gamidoi on 5/3/2026.
//

#include "Customer.h"


string Customer::getSQLInsert() {
	string query = "INSERT into customer (customerName, customerAddress, customerPhone) values (";
	query += "'" + customerName + "', '" + customerAddress + "', '" + customerPhone + "')" ;
	return query;
}
string Customer::getSQLUpdate() {
	string query = "UPDATE customer set customerName = '" + customerName +
				"', customerAddress = '" + customerAddress +
				"', customerPhone = " + customerPhone +
				" where customerID = " + to_string(customerID);
	return query;
}