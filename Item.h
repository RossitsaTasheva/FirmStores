/*
 * Item.h
 *
 *  Created on: 29.05.2017 г.
 *      Author: Rossi
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include <string>
using namespace std;

class Item {
public:
	Item();
	Item(string type, string brand, string model, int quantity,
			double priceitem);

	virtual ~Item();

	void print() const;

	const string& getBrand() const;
	void setBrand(const string& brand);

	const string& getModel() const;
	void setModel(const string& model);

	double getPriceitem() const;
	void setPriceitem(double priceitem);

	int getQuantity() const;
	void setQuantity(int quantity);

	const string& getType() const;
	void setType(const string& type);

private:
	string type;
	string brand;
	string model;
	int quantity;
	double priceitem;

};

#endif /* ITEM_H_ */
