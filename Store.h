/*
 * Store.h
 *
 *  Created on: 2.06.2017 г.
 *      Author: Rossi
 */

#ifndef TESTFIRM_H_
#define TESTFIRM_H_

#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include <vector>
#include <iterator>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <map>
#include "Item.h"




class Store {
public:
	Store();
	Store(vector <Item> items);

	void readXML(const char * filename);
	double calcTotalOneStore();
	void print();

	virtual ~Store();
	const vector<Item>& getItems() const;
	void setItems(const vector<Item>& items);

private:

	vector <Item> items;
};

#endif /* STORE_H_ */
