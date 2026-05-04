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
	newCustomer = Customer();
	newJob = Job();
	newRecipe = Recipe();
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
	try {newItem.setItemID(ui->itemNumber->text().toInt());} catch (...){newItem.setItemID(0);}
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
void MainWindow::submitEditItem() {
	if (checkItemHasIncompleteData(newItem)) {
		ui->ConfirmationOfEditedItemTextBox->setText(("The Item contains invalid characters, has incomplete data,\n or has negative values for Value, or Quantity."));
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->updateItem(newItem);
	ui->ConfirmationOfEditedItemTextBox->setText(confirmationMessage.data());
	viewItems->select();
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
	try {newCustomer.setID(ui->UpdateCustomerID->text().toInt());} catch (...){newCustomer.setID(0);}
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
void MainWindow::submitEditCustomer() {
	if (checkCustomerHasIncompleteData(newCustomer)) {
		ui->ConfirmationOfUpdateCustomerTextBox->setText(("The Customer contains invalid characters, or has incomplete data"));
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->UpdateCustomer(newCustomer);
	ui->ConfirmationOfUpdateCustomerTextBox->setText(confirmationMessage.data());
	viewCustomers->select();
	PopulateViewJobsTable();
}

void MainWindow::setNewJobDetails(){
	try {newJob.setCustomerID(ui->CustomerID->text().toInt());} catch (...){newJob.setCustomerID(0);}
	try {newJob.setJobID(ui->UpdateJobNumber->text().toInt());} catch (...){newJob.setJobID(0);}
	try {newJob.setWorkOrderID(ui->deleteWorkOrderNumber->text().toInt());} catch (...){newJob.setWorkOrderID(0);}

	try {newJob.setProductID1(ui->jobItem1->text().toInt());} catch (...){newJob.setProductID1(0);}
	try {newJob.setProductID2(ui->jobItem2->text().toInt());} catch (...){newJob.setProductID2(0);}
	try {newJob.setProductID3(ui->jobItem3->text().toInt());} catch (...){newJob.setProductID3(0);}
	try {newJob.setProductID4(ui->jobItem4->text().toInt());} catch (...){newJob.setProductID4(0);}
	try {newJob.setProductID5(ui->jobItem5->text().toInt());} catch (...){newJob.setProductID5(0);}
	try {newJob.setProductID6(ui->jobItem6->text().toInt());} catch (...){newJob.setProductID6(0);}
	try {newJob.setProductID7(ui->jobItem7->text().toInt());} catch (...){newJob.setProductID7(0);}
	try {newJob.setProductID8(ui->jobItem8->text().toInt());} catch (...){newJob.setProductID8(0);}

	try {newJob.setQuantity1(ui->jobItemQuantity1->text().toInt());} catch (...){newJob.setQuantity1(0);}
	try {newJob.setQuantity2(ui->jobItemQuantity2->text().toInt());} catch (...){newJob.setQuantity2(0);}
	try {newJob.setQuantity3(ui->jobItemQuantity3->text().toInt());} catch (...){newJob.setQuantity3(0);}
	try {newJob.setQuantity4(ui->jobItemQuantity4->text().toInt());} catch (...){newJob.setQuantity4(0);}
	try {newJob.setQuantity5(ui->jobItemQuantity5->text().toInt());} catch (...){newJob.setQuantity5(0);}
	try {newJob.setQuantity6(ui->jobItemQuantity6->text().toInt());} catch (...){newJob.setQuantity6(0);}
	try {newJob.setQuantity7(ui->jobItemQuantity7->text().toInt());} catch (...){newJob.setQuantity7(0);}
	try {newJob.setQuantity8(ui->jobItemQuantity8->text().toInt());} catch (...){newJob.setQuantity8(0);}
}
void MainWindow::submitNewJobToDatabase() {
	if (newJob.getCustomerID() < 1) {
		ui->ConfirmationOfNewJobTextBox->setText("Invalid Customer ID");
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->insertJob(newJob);
	ui->ConfirmationOfNewJobTextBox->setText(confirmationMessage.data());
	PopulateViewJobsTable();
	PopulateViewWorkOrdersTable();
}
void MainWindow::PopulateViewJobsTable() {
	viewJobs->setQuery("(select jobID, customerName, customerAddress, customerPhone from Job join Customer on Job.jobCustomer = Customer.customerID order by jobID)");
	viewJobs->setHeaderData(0, Qt::Horizontal, "Job Number");
	viewJobs->setHeaderData(1, Qt::Horizontal, "Customer Name");
	viewJobs->setHeaderData(2, Qt::Horizontal, "Customer Address");
	viewJobs->setHeaderData(3, Qt::Horizontal, "Customer Phone");

	ui->JobsTableView->setModel(viewJobs.get());
}
void MainWindow::submitEditJob() {
	if (newJob.getCustomerID() < 1) {
		ui->ConfirmationOfUpdateJobTextBox->setText("Invalid Customer ID");
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->updateJob(newJob);
	ui->ConfirmationOfUpdateJobTextBox->setText(confirmationMessage.data());
	PopulateViewJobsTable();
	PopulateViewWorkOrdersTable();
}
void MainWindow::submitDeleteWorkOrder() {
	string confirmationMessage = "";
	confirmationMessage = database->deleteWorkOrder(newJob);
	ui->ConfirmationOfDeleteWorkOrderTextBox->setText(confirmationMessage.data());
	PopulateViewWorkOrdersTable();
}
void MainWindow::PopulateViewWorkOrdersTable() {
	viewWorkOrders->setQuery("select workOrderJobNumber, workOrderID, workOrderItemQuantity, itemName, itemID from WorkOrder join Item on WorkOrder.workOrderOrderedItem = Item.itemID order by workOrderID");
	viewWorkOrders->setHeaderData(0, Qt::Horizontal, "Job Number");
	viewWorkOrders->setHeaderData(1, Qt::Horizontal, "Work Order");
	viewWorkOrders->setHeaderData(2, Qt::Horizontal, "Quantity");
	viewWorkOrders->setHeaderData(3, Qt::Horizontal, "Item Name");
	viewWorkOrders->setHeaderData(4, Qt::Horizontal, "Item ID");

	ui->WorkOrdersTableView->setModel(viewWorkOrders.get());
}
void MainWindow::setNewRecipeDetails(){
	try {newRecipe.setProductID(ui->RecipeProductID->text().toInt());} catch (...){newRecipe.setProductID(0);}

	try {newRecipe.setComponentID1(ui->RecipeComponentID1->text().toInt());} catch (...){newRecipe.setComponentID1(0);}
	try {newRecipe.setComponentID2(ui->RecipeComponentID2->text().toInt());} catch (...){newRecipe.setComponentID2(0);}
	try {newRecipe.setComponentID3(ui->RecipeComponentID3->text().toInt());} catch (...){newRecipe.setComponentID3(0);}
	try {newRecipe.setComponentID4(ui->RecipeComponentID4->text().toInt());} catch (...){newRecipe.setComponentID4(0);}
	try {newRecipe.setComponentID5(ui->RecipeComponentID5->text().toInt());} catch (...){newRecipe.setComponentID5(0);}
	try {newRecipe.setComponentID6(ui->RecipeComponentID6->text().toInt());} catch (...){newRecipe.setComponentID6(0);}
	try {newRecipe.setComponentID7(ui->RecipeComponentID7->text().toInt());} catch (...){newRecipe.setComponentID7(0);}
	try {newRecipe.setComponentID8(ui->RecipeComponentID8->text().toInt());} catch (...){newRecipe.setComponentID8(0);}

	try {newRecipe.setRatio1(ui->RecipeComponentRatio1->text().toDouble());} catch (...){newRecipe.setRatio1(0);}
	try {newRecipe.setRatio2(ui->RecipeComponentRatio2->text().toDouble());} catch (...){newRecipe.setRatio2(0);}
	try {newRecipe.setRatio3(ui->RecipeComponentRatio3->text().toDouble());} catch (...){newRecipe.setRatio3(0);}
	try {newRecipe.setRatio4(ui->RecipeComponentRatio4->text().toDouble());} catch (...){newRecipe.setRatio4(0);}
	try {newRecipe.setRatio5(ui->RecipeComponentRatio5->text().toDouble());} catch (...){newRecipe.setRatio5(0);}
	try {newRecipe.setRatio6(ui->RecipeComponentRatio6->text().toDouble());} catch (...){newRecipe.setRatio6(0);}
	try {newRecipe.setRatio7(ui->RecipeComponentRatio7->text().toDouble());} catch (...){newRecipe.setRatio7(0);}
	try {newRecipe.setRatio8(ui->RecipeComponentRatio8->text().toDouble());} catch (...){newRecipe.setRatio8(0);}
}
void MainWindow::submitNewRecipeToDatabase() {
	if (newRecipe.getProductID() < 1) {
		ui->ConfirmationOfNewRecipeTextBox->setText("Invalid Item ID");
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->insertRecipe(newRecipe);
	ui->ConfirmationOfNewRecipeTextBox->setText(confirmationMessage.data());

	PopulateViewRecipesTable();
}
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
void MainWindow::submitEditRecipe() {
	if (newRecipe.getProductID() < 1) {
		ui->ConfirmationOfUpdateRecipeTextBox->setText("Invalid Item ID");
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->updateRecipe(newRecipe);
	ui->ConfirmationOfUpdateRecipeTextBox->setText(confirmationMessage.data());

	PopulateViewRecipesTable();
}
void MainWindow::SubmitDeleteRecipe() {
	if (newRecipe.getProductID() < 1) {
		ui->ConfirmationOfUpdateRecipeTextBox->setText("Invalid Item ID");
		return;
	}
	string confirmationMessage = "";
	confirmationMessage = database->deleteRecipe(newRecipe);
	ui->ConfirmationOfUpdateRecipeTextBox->setText(confirmationMessage.data());

	PopulateViewRecipesTable();
}