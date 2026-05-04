//
// Created by Gamidoi on 5/3/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_JOB_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_JOB_H

using namespace std;
#include <string>

class Job {
private:
    int customerID;
    int jobID;
    int workOrderID;

    int productID1;
    int quantity1;
    int productID2;
    int quantity2;
    int productID3;
    int quantity3;
    int productID4;
    int quantity4;
    int productID5;
    int quantity5;
    int productID6;
    int quantity6;
    int productID7;
    int quantity7;
    int productID8;
    int quantity8;
public:
    Job() {
        customerID = productID1 = quantity1 = productID2 = quantity2 = productID3 = quantity3 =
        productID4 = quantity4 = productID5 = quantity5 = productID6 = quantity6 = productID7 =
        quantity7 = productID8 = quantity8 = 0;
    }
    string getSQLInsert();
    string getSQLWorkOrderInsert(string JobNumber);
    string getSQLUpdate();
    string getSQLWorkOrderDelete();

    void setCustomerID(int id) {customerID = id;}
    void setJobID(int id) {jobID = id;}
    void setWorkOrderID(int id) {workOrderID = id;}
    void setProductID1(int id) {productID1 = id;}
    void setProductID2(int id) {productID2 = id;}
    void setProductID3(int id) {productID3 = id;}
    void setProductID4(int id) {productID4 = id;}
    void setProductID5(int id) {productID5 = id;}
    void setProductID6(int id) {productID6 = id;}
    void setProductID8(int id) {productID8 = id;}
    void setProductID7(int id) {productID7 = id;}
    void setQuantity1(int quantity) {quantity1 = quantity;}
    void setQuantity2(int quantity) {quantity2 = quantity;}
    void setQuantity3(int quantity) {quantity3 = quantity;}
    void setQuantity4(int quantity) {quantity4 = quantity;}
    void setQuantity5(int quantity) {quantity5 = quantity;}
    void setQuantity6(int quantity) {quantity6 = quantity;}
    void setQuantity7(int quantity) {quantity7 = quantity;}
    void setQuantity8(int quantity) {quantity8 = quantity;}

    int getCustomerID() {return customerID;}
    int getJobID() {return jobID;}
    int getWorkOrderID() {return workOrderID;}
    int getProductID1() {return productID1;}
    int getProductID2() {return productID2;}
    int getProductID3() {return productID3;}
    int getProductID4() {return productID4;}
    int getProductID5() {return productID5;}
    int getProductID6() {return productID6;}
    int getProductID7() {return productID7;}
    int getProductID8() {return productID8;}
    int getQuantity1() {return quantity1;}
    int getQuantity2() {return quantity2;}
    int getQuantity3() {return quantity3;}
    int getQuantity4() {return quantity4;}
    int getQuantity5() {return quantity5;}
    int getQuantity6() {return quantity6;}
    int getQuantity7() {return quantity7;}
    int getQuantity8() {return quantity8;}
};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_JOB_H