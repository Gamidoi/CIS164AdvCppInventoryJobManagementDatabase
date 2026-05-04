//
// Created by Gamidoi on 4/13/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_SQLCONNECTION_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_SQLCONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <iostream>
#include "../objects/Item.h"
#include "../objects/Customer.h"
#include "../objects/Job.h"
#include "../objects/Recipe.h"
using namespace std;



class sqlConnection {
private:
	QSqlDatabase database;
public:
	sqlConnection() = default;
	sqlConnection(string& userName, string& password);
	QSqlDatabase getDatabase() {return database;}
	bool open() {
		return database.open();
	}
	string insertItem(Item newItem);
	string updateItem(Item newItem);
	string insertCustomer(Customer newCustomer);
	string UpdateCustomer(Customer newCustomer);
	string insertJob(Job newJob);
	string updateJob(Job newJob);
	string deleteWorkOrder(Job newJob);
	string insertRecipe(Recipe newRecipe);
	string updateRecipe(Recipe newRecipe);
	string deleteRecipe(Recipe newRecipe);
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_SQLCONNECTION_H