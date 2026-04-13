//
// Created by Gamidoi on 4/13/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ServerLogOnPage.h" resolved

#include "serverlogonpage.h"
#include <ui_mainwindow.h>

#include "mainwindow.h"
#include "ui_ServerLogOnPage.h"


ServerLogOnPage::ServerLogOnPage(QWidget *parent) : QWidget(parent), ui(new Ui::ServerLogOnPage) {
	ui->setupUi(this);
}

ServerLogOnPage::~ServerLogOnPage() {
	delete ui;
}


void ServerLogOnPage::EnterServerLogonAndPassword() {
	LogOnName = ui->ServerUserName->text().toStdString();
	LogOnPassword = ui->ServerPassword->text().toStdString();
}
void ServerLogOnPage::AttemptLogOn() {
	database = make_shared<sqlConnection>(LogOnName, LogOnPassword);
	if (database->open()) {
		MainWindow* mainWindow = new MainWindow(database);
		mainWindow->show();
		this->close();
	} else {
		ui->ErrorMessage->setText("The Log On Information Was Not Correct, Please Try Again.");
	}
}