//
// Created by Gamidoi on 4/13/2026.
//

#include "sqlConnection.h"

sqlConnection::sqlConnection(string& userName, string& password) {
	database = QSqlDatabase::addDatabase("QODBC");

	QString connectionString = QString(
		"DRIVER={MySQL ODBC 9.6 Unicode Driver};"
		"SERVER=localhost:3306;"
		"DATABASE=inventoryManagement;"
		"UID=%1;"
		"PWD=%2;"
		"OPTION=3;"
	).arg(QString::fromStdString(userName), QString::fromStdString(password));

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
string sqlConnection::updateItem(Item newItem) {
	try {
		QSqlQuery query(database);
		query.exec(newItem.getSQLUpdate().data());
		return "Item \"" + newItem.getItemName() + "\" has been updated.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}

string sqlConnection::insertCustomer(Customer newCustomer) {
	try {
		QSqlQuery query(database);
		query.exec(newCustomer.getSQLInsert().data());
		return "Customer \"" + newCustomer.getName() + "\" has been added.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}
string sqlConnection::UpdateCustomer(Customer newCustomer) {
	try {
		QSqlQuery query(database);
		query.exec(newCustomer.getSQLUpdate().data());
		return "Customer \"" + newCustomer.getName() + "\" has been updated.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}

string sqlConnection::insertJob(Job newJob) {
	try {
		QSqlQuery query(database);
		query.exec(newJob.getSQLInsert().data());
		int jobNumber = query.lastInsertId().toInt();
		query.exec(newJob.getSQLWorkOrderInsert(to_string(jobNumber)).data());

		return "Job # " + to_string(jobNumber) + " has been added.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}
string sqlConnection::updateJob(Job newJob){
	try {
		QSqlQuery query(database);
		query.exec(newJob.getSQLUpdate().data());
		query.exec(newJob.getSQLWorkOrderInsert(to_string(newJob.getJobID())).data());

		return "Job # " + to_string(newJob.getJobID()) + " has been updated.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}
string sqlConnection::deleteWorkOrder(Job newJob) {
	try {
		QSqlQuery query(database);
		query.exec(newJob.getSQLWorkOrderDelete().data());
		return "Work Order" + to_string(newJob.getWorkOrderID()) + " has been Deleted.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}

string sqlConnection::insertRecipe(Recipe newRecipe) {

	// TODO: make a check for already Assigned Product/Component combinations.

	try {
		QSqlQuery query(database);
		query.exec(newRecipe.getSQLInsert().data());

		return "Recipe has been updated.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}

string sqlConnection::updateRecipe(Recipe newRecipe){
	try {
		QSqlQuery query(database);
		for (auto eachQuery : newRecipe.getSQLUpdate()) {
			query.exec(eachQuery.data());
		}

		return "Recipe has been updated.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}
string sqlConnection::deleteRecipe(Recipe newRecipe) {
	try {
		QSqlQuery query(database);
		for (auto eachQuery : newRecipe.getSQLDelete()) {
			query.exec(eachQuery.data());
		}

		return "Recipe has been deleted.";
	} catch (exception &e) {
		cout << e.what() << endl;
		return e.what();
	}
}