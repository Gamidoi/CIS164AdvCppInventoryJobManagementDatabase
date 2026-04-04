#include <iostream>

#include "objects/Item.h"


using namespace std;
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>

int parseInput() {
	const int TOTALCHOICES = 10;
	string userInput = "";
	cout << "Your choices are:" << endl;
	cout << "1. add 'new item'" << endl;
	cout << "9. 'quit'" << endl;
	getline(cin, userInput);



	if (stoi(userInput) != NAN) {
		return stoi(userInput);
	}
	const string choices[TOTALCHOICES] = {"new item", "New item", "", "", "", "", "", "", "", "quit"};
	for (int i = 0; i < TOTALCHOICES; i++) {
		if (userInput.find(choices[i]) != string::npos) {
			return i;
		}
	}
	return 999;
}

class sqlConnection {
private:
	sql::Statement* statement;
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *connection;
public:
	sqlConnection() {}
	sqlConnection(string userName, string password) {
		driver = sql::mysql::get_mysql_driver_instance();
		connection = driver->connect("localhost:3306", userName, password);
		statement = connection->createStatement();
		statement->execute("use inventoryManagement;");
	}
	sql::Statement* getStatement(){return statement;}
	sql::Connection* getConnection(){return connection;}
};

void insertItem(sqlConnection database) {
	Item newItem;
	newItem.setDetails();
	try {
		database.getStatement()->execute(newItem.getSQLInsert());
	} catch (sql::SQLException &e) {
		cout << e.what() << endl;
	}
}


int main() {
	sqlConnection database;
	string name;
	string password;

	cout << "Please enter your Username: ";
	cin >> name;
	cin.ignore(1000, '\n');
	cout << "Please enter your password: ";
	cin >> password;
	cin.ignore(1000, '\n');
	try {
		database = sqlConnection(name, password);
	} catch (sql::SQLException &e) {
		cout << "Database could not be opened, please try again later." << endl;
		return -1;
	}

	bool stayConnected = true;
	while (stayConnected) {
		string query;
		int choice = 999;
		cout << "What would you like to do today?" << endl;
		choice = parseInput();

		switch (choice) {
			case 0: case 1:
				insertItem(database);
				break;
			case 9:
				stayConnected = false;
				break;

			default: cout << "Please enter a valid choice." << endl; break;
		}
	}




	database.getStatement()->close();
	database.getConnection()->close();

	return 0;
}
