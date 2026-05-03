//
// Created by Gamidoi on 5/3/2026.
//

#ifndef FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_RECIPE_H
#define FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_RECIPE_H
using namespace std;
#include <string>

class Recipe {
private:
	int productID;
	int componentID1;
	int componentID2;
	int componentID3;
	int componentID4;
	int componentID5;
	int componentID6;
	int componentID7;
	int componentID8;
	double ratio1;
	double ratio2;
	double ratio3;
	double ratio4;
	double ratio5;
	double ratio6;
	double ratio7;
	double ratio8;
public:
	Recipe() {
		productID = componentID1 = componentID2 = componentID3 = componentID4 = componentID5 = componentID6 = componentID7 = componentID8 = 0;
		ratio1 = ratio2 = ratio3 = ratio4 = ratio5 = ratio6 = ratio7 = ratio8 = 0;
	}
	string getSQLInsert();

	void setProductID(int newProductID) { productID = newProductID; }
	void setComponentID1(int newComponentID1) { componentID1 = newComponentID1; }
	void setComponentID2(int newComponentID2) { componentID2 = newComponentID2; }
	void setComponentID3(int newComponentID3) { componentID3 = newComponentID3; }
	void setComponentID4(int newComponentID4) { componentID4 = newComponentID4; }
	void setComponentID5(int newComponentID5) { componentID5 = newComponentID5; }
	void setComponentID6(int newComponentID6) { componentID6 = newComponentID6; }
	void setComponentID7(int newComponentID7) { componentID7 = newComponentID7; }
	void setComponentID8(int newComponentID8) { componentID8 = newComponentID8; }

	int getProductID() const { return productID; }
	int getComponentID1() const { return componentID1; }
	int getComponentID2() const { return componentID2; }
	int getComponentID3() const { return componentID3; }
	int getComponentID4() const { return componentID4; }
	int getComponentID5() const { return componentID5; }
	int getComponentID6() const { return componentID6; }
	int getComponentID7() const { return componentID7; }
	int getComponentID8() const { return componentID8; }


};


#endif //FINALPROJECTCIS164INVENTORYJOBMANAGEMENTDATABASE_RECIPE_H