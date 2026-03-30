#include <iostream>


using namespace std;
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>

bool testMySQLConnection() {
	try {
		// note, that I am not loading the password to github. Because of security.
		// in my next update, I will probably prompt the user for the password.
		string password = "thisIsNotReallyThePassword";
		sql::mysql::MySQL_Driver *driver;
		sql::Connection *con;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("localhost:3306", "root", password);

		sql::Statement *stmt = con->createStatement();
		stmt->execute("use inventoryManagement;");
		stmt->execute(
			"INSERT into Item (itemName, itemDescription, itemValue, itemQuantity, isRawResource) VALUES ('nails', 'basic iron nails', 0.01, 300, true)"
			);

		// memory management, both stmt, and con are heaped, not stacked, and must be deleted.
		delete stmt;
		delete con;

		return true;

	} catch (sql::SQLException &e) {
		cout << e.what() << endl;
		return false;
	}
}

int main() {
	if (testMySQLConnection()) {
		cout << "Database conneciton is good" << endl;
	} else {
		cout << "failed to connect to database" << endl;
	}
	return 0;
}
