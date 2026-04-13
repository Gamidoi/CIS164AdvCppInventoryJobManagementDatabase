//
// Created by Gamidoi on 4/13/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QSqlTableModel>
#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(shared_ptr<sqlConnection> database, QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	this->database = database;
	newItem = Item();
	this->viewItems = make_shared<QSqlTableModel>(this, database->getDatabase());
	PopulateViewItemsTable();
}

MainWindow::~MainWindow() {
	delete ui;
}


const string DANGEROUSCHARS = "<>;\'\"()~#@%$^&*\\";
bool checkStringHasDangeousChars(string input) {
	for (char danger: DANGEROUSCHARS) {
		if (input.find(danger) != string::npos) {
			return true;
		}
	}
	return false;
}

void MainWindow::SetNewItemDetails(){
	ui->ConfirmationOfNewItemTextBox->setText(tr(""));
	try {
		string itemName = ui->itemName->text().toStdString();
		if (checkStringHasDangeousChars(itemName)){
			ui->ConfirmationOfNewItemTextBox->setText(("Invalid item Name, name cannot include characters: \"" + DANGEROUSCHARS + "\"").data());
			throw runtime_error("");
		}
		newItem.setItemName(itemName);
	} catch (...) {
		newItem.setItemName("");
	}
	try {
		string itemDescription = ui->ItemDescription->toPlainText().toStdString();
		if (checkStringHasDangeousChars(itemDescription)){
			ui->ConfirmationOfNewItemTextBox->setText(("Invalid Description, description cannot include characters: \"" + DANGEROUSCHARS + "\"").data());
			throw runtime_error("");
		}
		newItem.setItemDescription(itemDescription);
	} catch (...) {
		newItem.setItemDescription("");
	}
	try {newItem.setItemValue(ui->ItemValue->text().toDouble());} catch (...){newItem.setItemValue(0.0);}
	try {newItem.setItemQuantity(ui->ItemQuantity->text().toInt());} catch (...){newItem.setItemQuantity(0);}
	try {newItem.setIsRawResource(ui->itemIsRaw->currentIndex());} catch (...){newItem.setIsRawResource(0);}
}

bool checkItemHasIncompleteData(Item newItem) {
	if (newItem.getItemName().empty() || newItem.getItemDescription().empty()) {
		return true;
	}
	if (checkStringHasDangeousChars(newItem.getItemName()) || checkStringHasDangeousChars(newItem.getItemDescription())) {
		return true;
	}
	if (newItem.getItemQuantity() < 0 || newItem.getItemValue() < 0) {
		return true;
	}
	return false;
}

void MainWindow::SubmitNewItemToDatabase() {
	if (checkItemHasIncompleteData(newItem)) {
		ui->ConfirmationOfNewItemTextBox->setText(("The Item contains invalid characters, has incomplete data, or has negative values for Value, or Quantity."));
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->insertItem(newItem);
	ui->ConfirmationOfNewItemTextBox->setText(confirmationMessage.data());
	viewItems->select();
}

void MainWindow::PopulateViewItemsTable() {
	viewItems->setTable("Item");
	viewItems->setHeaderData(0, Qt::Horizontal, "Item Number");
	viewItems->setHeaderData(1, Qt::Horizontal, "Item Name");
	viewItems->setHeaderData(2, Qt::Horizontal, "Item Description");
	viewItems->setHeaderData(3, Qt::Horizontal, "Item Value");
	viewItems->setHeaderData(4, Qt::Horizontal, "Item Quantity");
	viewItems->setHeaderData(5, Qt::Horizontal, "Item Resource Code");

	viewItems->select();
	ui->ItemTableView->setModel(viewItems.get());
}
