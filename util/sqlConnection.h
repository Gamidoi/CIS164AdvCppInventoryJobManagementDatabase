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
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_SQLCONNECTION_H