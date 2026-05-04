//
// Created by Gamidoi on 5/3/2026.
//

#include "Job.h"

string Job::getSQLInsert() {
    string sqlInsert = "INSERT INTO Job (jobCustomer) VALUES (";
    sqlInsert += to_string(customerID);
    sqlInsert += ");";
    return sqlInsert;
}
string Job::getSQLWorkOrderInsert(string JobNumber){
    string sqlInsert = "INSERT INTO WorkOrder (workOrderJobNumber, workOrderOrderedItem, workOrderItemQuantity) VALUES ";
    bool hasFirstRow = false;

    if (productID1 != 0 && quantity1 != 0) {
        hasFirstRow = true;
        sqlInsert += "(" + JobNumber + ", " + to_string(productID1) + ", " + to_string(quantity1) + ")";
    }
    if (productID2 != 0 && quantity2 != 0) {
        if (hasFirstRow) {sqlInsert += ", ";
        } else {hasFirstRow = true;}
        sqlInsert += "(" + JobNumber + ", " + to_string(productID2) + ", " + to_string(quantity2) + ")";
    }
    if (productID3 != 0 && quantity3 != 0) {
        if (hasFirstRow) {sqlInsert += ", ";
        } else {hasFirstRow = true;}
        sqlInsert += "(" + JobNumber + ", " + to_string(productID3) + ", " + to_string(quantity3) + ")";
    }
    if (productID4 != 0 && quantity4 != 0) {
        if (hasFirstRow) {sqlInsert += ", ";
        } else {hasFirstRow = true;}
        sqlInsert += "(" + JobNumber + ", " + to_string(productID4) + ", " + to_string(quantity4) + ")";
    }
    if (productID5 != 0 && quantity5 != 0) {
        if (hasFirstRow) {sqlInsert += ", ";
        } else {hasFirstRow = true;}
        sqlInsert += "(" + JobNumber + ", " + to_string(productID5) + ", " + to_string(quantity5) + ")";
    }
    if (productID6 != 0 && quantity6 != 0) {
        if (hasFirstRow) {sqlInsert += ", ";
        } else {hasFirstRow = true;}
        sqlInsert += "(" + JobNumber + ", " + to_string(productID6) + ", " + to_string(quantity6) + ")";
    }
    if (productID7 != 0 && quantity7 != 0) {
        if (hasFirstRow) {sqlInsert += ", ";
        } else {hasFirstRow = true;}
        sqlInsert += "(" + JobNumber + ", " + to_string(productID7) + ", " + to_string(quantity7) + ")";
    }
    if (productID8 != 0 && quantity8 != 0) {
        if (hasFirstRow) {sqlInsert += ", ";
        }
        sqlInsert += "(" + JobNumber + ", " + to_string(productID8) + ", " + to_string(quantity8) + ")";
    }
    return sqlInsert;
}
string Job::getSQLUpdate() {
    string sqlInsert = "UPDATE Job set jobCustomer = ";
    sqlInsert += to_string(customerID);
    sqlInsert += " where jobID = " + to_string(jobID);
    return sqlInsert;
}
string Job::getSQLWorkOrderDelete() {
    return "Delete from WorkOrder where workOrderID = " + to_string(workOrderID);
}