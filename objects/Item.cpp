//
// Created by Gamidoi on 4/4/2026.
//

#include "Item.h"
#include <iostream>

string Item::getSQLInsert() {
	string query = "INSERT into Item (itemName, itemDescription, itemValue, itemQuantity, ResourceCode) VALUES ('" +
		itemName + "', '" + itemDescription + "', " + to_string(itemValue) + ", " + to_string(itemQuantity) + ", " + to_string(isRawResource) + ")";
	return query;
}
