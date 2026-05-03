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
	this->viewCustomers = make_shared<QSqlTableModel>(this, database->getDatabase());
	this->viewJobs = make_shared<QSqlQueryModel>();
	this->viewWorkOrders = make_shared<QSqlQueryModel>();
	this->viewRecipes = make_shared<QSqlQueryModel>();
	PopulateViewItemsTable();
	PopulateViewCustomersTable();
	PopulateViewJobsTable();
	PopulateViewWorkOrdersTable();
	PopulateViewRecipesTable();
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
		ui->ConfirmationOfNewItemTextBox->setText(("The Item contains invalid characters, has incomplete data,\n or has negative values for Value, or Quantity."));
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

void MainWindow::setNewCustomerDetails(){
	try {
		string CustomerName = ui->CustomerName->text().toStdString();
		if (checkStringHasDangeousChars(CustomerName)){
			ui->ConfirmationOfNewCustomerTextBox->setText(("Invalid Customer Name, cannot include characters: \"" + DANGEROUSCHARS + "\"").data());
			throw runtime_error("");
		}
		newCustomer.setName(CustomerName);
	} catch (...) {
		newCustomer.setName("");
	}
	try {
		string CustomerAddress = ui->CustomerAddress->toPlainText().toStdString();
		if (checkStringHasDangeousChars(CustomerAddress)){
			ui->ConfirmationOfNewCustomerTextBox->setText(("Invalid Customer Address, cannot include characters: \"" + DANGEROUSCHARS + "\"").data());
			throw runtime_error("");
		}
		newCustomer.setAddress(CustomerAddress);
	} catch (...) {
		newCustomer.setAddress("");
	}
	try {
		string CustomerPhone = ui->CustomerPhone->text().toStdString();
		if (checkStringHasDangeousChars(CustomerPhone)){
			ui->ConfirmationOfNewCustomerTextBox->setText(("Invalid Customer Phone, cannot include characters: \"" + DANGEROUSCHARS + "\"").data());
			throw runtime_error("");
		}
		newCustomer.setPhone(CustomerPhone);
	} catch (...) {
		newCustomer.setPhone("");
	}
}
bool checkCustomerHasIncompleteData(Customer newCustomer) {
	if (newCustomer.getName().empty() || checkStringHasDangeousChars(newCustomer.getName())) {
		return true;
	}
	if (newCustomer.getAddress().empty() || checkStringHasDangeousChars(newCustomer.getAddress())) {
		return true;
	}
	if (newCustomer.getPhone().empty() || checkStringHasDangeousChars(newCustomer.getPhone())) {
		return true;
	}
	return false;
}
void MainWindow::submitNewCustomerToDatabase() {
	if (checkCustomerHasIncompleteData(newCustomer)) {
		ui->ConfirmationOfNewCustomerTextBox->setText(("The Customer contains invalid characters, or has incomplete data"));
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->insertCustomer(newCustomer);
	ui->ConfirmationOfNewCustomerTextBox->setText(confirmationMessage.data());
	viewCustomers->select();
}
void MainWindow::PopulateViewCustomersTable() {
	viewCustomers->setTable("Customer");
	viewCustomers->setHeaderData(1, Qt::Horizontal, "Customer ID");
	viewCustomers->setHeaderData(1, Qt::Horizontal, "Customer Name");
	viewCustomers->setHeaderData(2, Qt::Horizontal, "Customer Address");
	viewCustomers->setHeaderData(3, Qt::Horizontal, "Customer Phone");

	viewCustomers->select();
	ui->CustomersTableView->setModel(viewCustomers.get());
}

void MainWindow::setNewJobDetails(){}
void MainWindow::submitNewJobToDatabase(){}

void MainWindow::PopulateViewJobsTable() {
	viewJobs->setQuery("(select jobID, customerName, customerAddress, customerPhone from Job join Customer on Job.jobCustomer = Customer.customerID)");
	viewJobs->setHeaderData(0, Qt::Horizontal, "Job Number");
	viewJobs->setHeaderData(1, Qt::Horizontal, "Customer Name");
	viewJobs->setHeaderData(2, Qt::Horizontal, "Customer Address");
	viewJobs->setHeaderData(3, Qt::Horizontal, "Customer Phone");

	ui->JobsTableView->setModel(viewJobs.get());
}
void MainWindow::PopulateViewWorkOrdersTable() {
	viewWorkOrders->setQuery("select workOrderJobNumber, workOrderID, workOrderItemQuantity, itemName, itemID from WorkOrder join Item on WorkOrder.workOrderOrderedItem = Item.itemID");
	viewWorkOrders->setHeaderData(0, Qt::Horizontal, "Job Number");
	viewWorkOrders->setHeaderData(1, Qt::Horizontal, "Work Order");
	viewWorkOrders->setHeaderData(2, Qt::Horizontal, "Quantity");
	viewWorkOrders->setHeaderData(3, Qt::Horizontal, "Item Name");
	viewWorkOrders->setHeaderData(4, Qt::Horizontal, "Item ID");

	ui->WorkOrdersTableView->setModel(viewWorkOrders.get());
}
void MainWindow::setNewRecipeDetails(){}
void MainWindow::submitNewRecipeToDatabase(){}
void MainWindow::PopulateViewRecipesTable() {
	QString query = "select product.itemID, product.itemName, component.itemName, ItemComponentItems.componentPerItemRatio from ItemComponentItems ";
	query += "join Item as product on ItemComponentItems.itemID = product.itemID ";
	query += "join Item as component on ItemComponentItems.component = component.itemID";
	viewRecipes->setQuery(query);
	viewRecipes->setHeaderData(0, Qt::Horizontal, "Product ID");
	viewRecipes->setHeaderData(1, Qt::Horizontal, "Product Name");
	viewRecipes->setHeaderData(2, Qt::Horizontal, "Component Name");
	viewRecipes->setHeaderData(3, Qt::Horizontal, "Component per Product Ratio");

	ui->RecipeTableView->setModel(viewRecipes.get());
}