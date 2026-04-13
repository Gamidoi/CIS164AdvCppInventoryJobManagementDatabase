//
// Created by Gamidoi on 4/4/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_ITEM_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_ITEM_H
using namespace std;
#include <string>


class Item {
private:
	string itemName;
	string itemDescription;
	double itemValue;
	int itemQuantity;
	int isRawResource;
public:
	Item(){itemName = ""; itemDescription = ""; itemValue = 0.0; itemQuantity = 0; isRawResource = 1;}
	Item(string itemName, string itemDescription, double itemValue, int itemQuantity, int isRawResource):
		itemName(itemName), itemDescription(itemDescription), itemValue(itemValue), itemQuantity(itemQuantity), isRawResource(isRawResource){}
	string getSQLInsert();

	string getItemName() const {return itemName;}
	string getItemDescription() const {return itemDescription;}
	double getItemValue() const {return itemValue;}
	int getItemQuantity() const {return itemQuantity;}
	int getIsRawResource() const {return isRawResource;}

	void setItemName(const string &itemName) {this->itemName = itemName;}
	void setItemDescription(const string &itemDescription) {this->itemDescription = itemDescription;}
	void setItemValue(double itemValue) {this->itemValue = itemValue;}
	void setItemQuantity(int itemQuantity) {this->itemQuantity = itemQuantity;}
	void setIsRawResource(int isRawResource) {this->isRawResource = isRawResource;}
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_ITEM_H