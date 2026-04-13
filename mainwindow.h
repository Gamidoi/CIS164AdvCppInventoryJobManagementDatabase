//
// Created by Gamidoi on 4/13/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_MAINWINDOW_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_MAINWINDOW_H

#include <QWidget>
#include <QSqlTableModel>

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
private:
	Ui::MainWindow *ui;
	shared_ptr<sqlConnection> database;
	shared_ptr<QSqlTableModel> viewItems;
	Item newItem;
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_MAINWINDOW_H