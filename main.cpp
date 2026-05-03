#include "serverlogonpage.h"
#include "objects/Item.h"
#include "util/sqlConnection.h"


using namespace std;
#include <QApplication>



int main(int argc, char *argv[]) {
	QApplication GUI(argc, argv);
	sqlConnection database;
	string name;
	string password;

	ServerLogOnPage logOnPage;
	logOnPage.show();


	return QApplication::exec();

	/****************************************************************
	cout << "Please enter your Username: ";
	cin >> name;
	cin.ignore(1000, '\n');
	cout << "Please enter your password: ";
	cin >> password;
	cin.ignore(1000, '\n');
	try {
		database = sqlConnection(name, password);
	} catch (exception &e) {
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
	return 0;
	********************************************************/
}
