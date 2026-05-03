//
// Created by Gamidoi on 4/13/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_MAINWINDOW_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_MAINWINDOW_H

#include <QWidget>
#include <QSqlTableModel>

#include "objects/Customer.h"
#include "objects/Item.h"
#include "util/sqlConnection.h"


QT_BEGIN_NAMESPACE

namespace Ui {
	class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QWidget {
	Q_OBJECT

public:
	explicit MainWindow(shared_ptr<sqlConnection> database, QWidget *parent = nullptr);

	~MainWindow() override;

private slots:
	void SetNewItemDetails();
	void SubmitNewItemToDatabase();
	void PopulateViewItemsTable();
	void setNewCustomerDetails();
	void submitNewCustomerToDatabase();
	void PopulateViewCustomersTable();
	void setNewJobDetails();
	void submitNewJobToDatabase();
	void PopulateViewJobsTable();
	void PopulateViewWorkOrdersTable();
	void setNewRecipeDetails();
	void submitNewRecipeToDatabase();
	void PopulateViewRecipesTable();
private:
	Ui::MainWindow *ui;
	shared_ptr<sqlConnection> database;
	shared_ptr<QSqlTableModel> viewItems;
	shared_ptr<QSqlTableModel> viewCustomers;
	shared_ptr<QSqlQueryModel> viewJobs;
	shared_ptr<QSqlQueryModel> viewWorkOrders;
	shared_ptr<QSqlQueryModel> viewRecipes;
	Item newItem;
	Customer newCustomer;
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_MAINWINDOW_H