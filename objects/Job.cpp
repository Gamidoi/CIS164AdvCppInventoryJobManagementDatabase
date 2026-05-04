//
// Created by Gamidoi on 5/3/2026.
//

#include "Job.h"

string Job::getSQLInsert() {
    string sqlInsert = "INSERT INTO Job (customerID) VALUES (";
    sqlInsert += to_string(customerID);
    sqlInsert += ");";
    return sqlInsert;
}
string Job::getSQLWorkOrderInsert(string JobNumber){
    string sqlInsert = "INSERT INTO WorkOrder (workOrderJobNumber, workOrderOrderedItem, workOrderItemQuantity) VALUES (";
    sqlInsert += "(" + JobNumber + ", " + to_string(productID1) + ", " + to_string(quantity1) + ")";
    sqlInsert += to_string(productID2) + ", " + to_string(quantity2) + ", ";
    sqlInsert += to_string(productID3) + ", " + to_string(quantity3) + ", ";
    sqlInsert += to_string(productID4) + ", " + to_string(quantity4) + ", ";
    sqlInsert += to_string(productID5) + ", " + to_string(quantity5) + ", ";
    sqlInsert += to_string(productID6) + ", " + to_string(quantity6) + ", ";
    sqlInsert += to_string(productID7) + ", " + to_string(quantity7) + ", ";
    sqlInsert += to_string(productID8) + ", " + to_string(quantity8);
    return sqlInsert;
}