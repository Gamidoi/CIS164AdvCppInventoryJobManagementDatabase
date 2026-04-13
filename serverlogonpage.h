//
// Created by Gamidoi on 4/13/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_SERVERLOGONPAGE_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_SERVERLOGONPAGE_H

#include <QWidget>

#include "util/sqlConnection.h"
using namespace std;


QT_BEGIN_NAMESPACE

namespace Ui {
	class ServerLogOnPage;
}

QT_END_NAMESPACE

class ServerLogOnPage : public QWidget {
	Q_OBJECT

public:
	string LogOnName;
	string LogOnPassword;
	shared_ptr<sqlConnection> database;

	explicit ServerLogOnPage(QWidget *parent = nullptr);
	shared_ptr<sqlConnection> getDatabase(){return database;}
	~ServerLogOnPage() override;

private slots:
	void EnterServerLogonAndPassword();
	void AttemptLogOn();
private:
	Ui::ServerLogOnPage *ui;
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_SERVERLOGONPAGE_H