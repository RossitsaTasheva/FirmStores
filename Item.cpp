/*
 * Item.cpp
 *
 *  Created on: 29.05.2017 г.
 *      Author: Rossi
 */

#include "Item.h"

Item::Item() {
	setType("N");
	setBrand("N");
	setModel("N");
	setQuantity(0);
	setPriceitem(0.0);
}

Item::Item(string type, string brand, string model, int quantity,
		double priceitem) {
	setType(type);
	setBrand(brand);
	setModel(model);
	setQuantity(quantity);
	setPriceitem(priceitem);
}

Item::~Item() {

}

const string& Item::getBrand() const {
	return brand;
}

void Item::setBrand(const string& brand) {
	this->brand = brand;
}

const string& Item::getModel() const {
	return model;
}

void Item::setModel(const string& model) {
	this->model = model;
}

double Item::getPriceitem() const {
	return priceitem;
}

void Item::setPriceitem(double priceitem) {
	this->priceitem = priceitem;
}

int Item::getQuantity() const {
	return quantity;
}

void Item::setQuantity(int quantity) {
	this->quantity = quantity;
}

const string& Item::getType() const {
	return type;
}

void Item::print() const {
	cout << "\n|" << getType() << "|" << getBrand() << "|" << getModel() << "|"
			<< getQuantity() << "|" << getPriceitem() << "|" << endl;
}

void Item::setType(const string& type) {
	this->type = type;
}

