//
// Created by Gamidoi on 4/4/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_ITEM_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_ITEM_H
using namespace std;
#include <string>;


class Item {
private:
	string itemName;
	string itemDescription;
	double itemValue;
	int itemQuantity;
	int isRawResource;
public:
	Item(){itemName = ""; itemDescription = ""; itemValue = 0.0; itemQuantity = 0; isRawResource = 1;}
	string getSQLInsert();
	void setDetails();
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_ITEM_H