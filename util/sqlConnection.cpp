//
// Created by Gamidoi on 4/13/2026.
//

#include "sqlConnection.h"

sqlConnection::sqlConnection(string& userName, string& password) {
	database = QSqlDatabase::addDatabase("QODBC");

	// Build a connection string for MySQL via ODBC
	QString connectionString = QString(
		"DRIVER={MySQL ODBC 9.6 Unicode Driver};"
		"SERVER=50.80.0.128:3306;"
		"DATABASE=inventoryManagement;"
		"UID=%1;"
		"PWD=%2;"
		"OPTION=3;"
	).arg(QString::fromStdString(userName), QString::fromStdString(password));

	// 3. For ODBC, the string goes in setDatabaseName
	database.setDatabaseName(connectionString);
	if (!database.open()) {
		qDebug() << "Database Error:" << database.lastError().text();
	} else {
		qDebug() << "Successfully connected to MySQL via ODBC!";
	}
}

string sqlConnection::insertItem(Item newItem) {
	try {
		QSqlQuery query(database);
		query.exec(newItem.getSQLInsert().data());
		return "Item \"" + newItem.getItemName() + "\" has been added to inventory.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}