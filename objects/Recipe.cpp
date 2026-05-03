//
// Created by Gamidoi on 5/3/2026.
//

#include "Recipe.h"


string Recipe::getSQLInsert() {
	string query = "INSERT into ItemComponentItems (itemID, component, componentPerItemRatio) values ";
	bool hasFirstRow = false;
	if (componentID1 != 0 && ratio1 != 0) {
		hasFirstRow = true;
		query += "(" + to_string(productID) + ", " + to_string(componentID1) + ", " + to_string(ratio1) + ")";
	}
	if (componentID2 != 0 && ratio2 != 0) {
		if (hasFirstRow) {query += ", ";
		} else {hasFirstRow = true;}
		query += "(" + to_string(productID) + ", " + to_string(componentID2) + ", " + to_string(ratio2) + ")";
	}
	if (componentID3 != 0 && ratio3 != 0) {
		if (hasFirstRow) {query += ", ";
		} else {hasFirstRow = true;}
		query += "(" + to_string(productID) + ", " + to_string(componentID3) + ", " + to_string(ratio3) + ")";
	}
	if (componentID4 != 0 && ratio4 != 0) {
		if (hasFirstRow) {query += ", ";
		} else {hasFirstRow = true;}
		query += "(" + to_string(productID) + ", " + to_string(componentID4) + ", " + to_string(ratio4) + ")";
	}
	if (componentID5 != 0 && ratio5 != 0) {
		if (hasFirstRow) {query += ", ";
		} else {hasFirstRow = true;}
		query += "(" + to_string(productID) + ", " + to_string(componentID5) + ", " + to_string(ratio5) + ")";
	}
	if (componentID6 != 0 && ratio6 != 0) {
		if (hasFirstRow) {query += ", ";
		} else {hasFirstRow = true;}
		query += "(" + to_string(productID) + ", " + to_string(componentID6) + ", " + to_string(ratio6) + ")";
	}
	if (componentID7 != 0 && ratio7 != 0) {
		if (hasFirstRow) {query += ", ";
		} else {hasFirstRow = true;}
		query += "(" + to_string(productID) + ", " + to_string(componentID7) + ", " + to_string(ratio7) + ")";
	}
	if (componentID8 != 0 && ratio8 != 0) {
		if (hasFirstRow) {query += ", ";
		} else {hasFirstRow = true;}
		query += "(" + to_string(productID) + ", " + to_string(componentID8) + ", " + to_string(ratio8) + ")";
	}

	return query;
}