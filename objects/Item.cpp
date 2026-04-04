//
// Created by Gamidoi on 4/4/2026.
//

#include "Item.h"
#include <iostream>;

string Item::getSQLInsert() {
	string query = "INSERT into Item (itemName, itemDescription, itemValue, itemQuantity, isRawResource) VALUES ('" +
		itemName + "', '" + itemDescription + "', " + to_string(itemValue) + ", " + to_string(itemQuantity) + ", " + to_string(isRawResource) + ")";
	return query;
}

void Item::setDetails() {
	cout << "Please enter information for a new Item." << endl;
	cout << "name" << endl;
	getline(cin, itemName);
	cout << "description" << endl;
	getline(cin, itemDescription);
	cout << "value" << endl;
	cin >> itemValue;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "That value was not a valid decimal. Please try again." << endl;
		cin >> itemValue;
	}
	cout << "quantity" << endl;
	cin >> itemQuantity;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "That value was not a valid integer. Please try again." << endl;
		cin >> itemQuantity;
	}
	cout << "isRawResource" << endl;
	cin >> isRawResource;
	while (cin.fail() || isRawResource < 0 || isRawResource > 1) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "That is not a valid boolean value. Please enter digit 1 for true, 0 for false." << endl;
		cin >> isRawResource;
	}
	cin.ignore(10000, '\n');
}