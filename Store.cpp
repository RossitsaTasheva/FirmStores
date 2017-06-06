/*
 * Store.cpp
 *
 *  Created on: 2.06.2017 г.
 *      Author: Rossi
 */

#include "Store.h"

Store::Store() {

}
Store::Store(vector <Item> items) {

}


Store::~Store() {
}

void Store::readXML(const char * filename) {
	Item itemTemp;
	pugi::xml_document doc;
	if (!doc.load_file(filename)) {
		cout << "Error loading file!";
	} else {

		pugi::xml_node catalog = doc.child("catalog");
		for (pugi::xml_node item = catalog.first_child(); item;
				item = item.next_sibling()) {

			itemTemp.setType(item.child("type").text().as_string());
			itemTemp.setBrand(item.child("brand").text().as_string());
			itemTemp.setModel(item.child("model").text().as_string());
			itemTemp.setQuantity(item.child("quantity").text().as_int());
			itemTemp.setPriceitem(item.child("priceitem").text().as_double());

			items.push_back(itemTemp);
		}
	}
}
//Print vector
void Store::print() {
	for (unsigned i = 0; i < items.size(); i++) {
		items[i].print();
	}
}

const vector<Item>& Store::getItems() const {
	return items;
}

void Store::setItems(const vector<Item>& items) {
	this->items = items;
}

//Смята общия оборот
double Store::calcTotalOneStore() {
	double total = 0;

	for (unsigned i = 0; i < items.size(); i++) {

		total += items[i].getQuantity() * items[i].getPriceitem();

	}
	return total;
}


