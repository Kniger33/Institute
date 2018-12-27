#include <iostream>
#include <string>
#include "Product.h"

    // ŒÕ—“–” “Œ–
	Product::Product(int i, string n, string d, int c, string inf)
    {
        id = i;
        name = n;
        department = d;
        cost = c;
        information = inf;
	}
	string Product::getDep(){return department;}
	string Product::getName(){return name;}
	string Product::getInfo(){return information;}
	char Product::FirstSymbolOfName(){return name[0];}
	int Product::getCost(){return cost;}
	int Product::getId(){return id;}
