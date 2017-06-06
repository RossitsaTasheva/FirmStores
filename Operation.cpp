/*
 * Operation.cpp
 *
 *  Created on: 23.05.2017 г.
 *      Author: Rossi
 */

#include "Operation.h"

Operation::Operation() {

}

Operation::Operation(vector<Store> stores) {
	this->stores = stores;
}

Operation::~Operation() {
}

//1Print all

void Operation::print() {
	for (unsigned i = 0; i < stores.size(); i++) {
		for (unsigned j = 0; j < stores[i].getItems().size(); j++) {
			stores[i].getItems()[j].print();

		}
	}
}
void Operation::printMap(TypeToQuantity mapp) {
	cout << "Brand" << "\t" << "Price" << endl;
	for (TypeToQuantity::const_iterator it = mapp.begin(); it != mapp.end();
			++it)
		cout << it->first << "\t" << it->second << '\n';
}

//4___________________________________________________________________
//2_Print Vector Stores
void Operation::printVectorStores() {
	for (int i = 0; i < (int) biggestIncomeStore().getItems().size(); i++) {
		biggestIncomeStore().getItems()[i].print();
	}
}
//3_Изчислете дневния доход на компанията
double Operation::companyProfit() {
	double res = 0;
	for (int i = 0; i < (int) stores.size(); i++) {
		res += stores[i].calcTotalOneStore();
	}
	return res;
}
const Store Operation::leastIncomeStore() {
	Store min1 = stores[0];
	double min = stores[0].calcTotalOneStore();
	for (unsigned i = 1; i < stores.size(); i++) {
		if (min > stores[i].calcTotalOneStore()) {
			min = stores[i].calcTotalOneStore();
			min1 = stores[i];
		}
	}
	return min1;
}
//4--------------------------------------------------
const Store Operation::biggestIncomeStore() {
	Store max1 = stores[0];
	double max = stores[0].calcTotalOneStore();
	for (unsigned i = 1; i < stores.size(); i++) {
		if (max < stores[i].calcTotalOneStore()) {
			max = stores[i].calcTotalOneStore();
			max1 = stores[i];
		}
	}
	return max1;
}

//5_Best selling item:---------------------------------------------------

TypeToQuantity Operation::typeToQuantity() {

	TypeToQuantity mapTypeQuantity;
	for (unsigned i = 0; i < stores.size(); i++) {
		for (unsigned j = 0; j < stores[i].getItems().size(); j++) {

			mapTypeQuantity[stores[i].getItems()[j].getType()] +=
					stores[i].getItems()[j].getQuantity();
		}
	}

	return mapTypeQuantity;
}
void Operation::bestSellingItem() {
	PairTypeQuantity a;
	TypeToQuantity mapp;
	mapp = typeToQuantity();
	a.type = mapp.begin()->first;
	a.quantity = mapp.begin()->second;
	for (TypeToQuantity::const_iterator it = mapp.begin(); it != mapp.end();
			++it)
		if (a.quantity < it->second) {
			a.quantity = it->second;
			a.type = it->first;
		}
	cout << a.type << "=>" << a.quantity;
}
//6_Most profitable item---------------------------------------------------

TypeToProfit Operation::typeToProfit() {

	TypeToProfit mapBrandPrice;
	for (unsigned i = 0; i < stores.size(); i++) {
		for (unsigned j = 0; j < stores[i].getItems().size(); j++) {

//			if (mapBrandPrice.find(stores[i].getItems()[j].getType())
//					!= mapBrandPrice.end()) {
			mapBrandPrice[stores[i].getItems()[j].getType()] +=
					stores[i].getItems()[j].getQuantity()
							* stores[i].getItems()[j].getPriceitem();
//			} else {
//				mapBrandPrice[stores[i].getItems()[j].getType()] =
//						stores[i].getItems()[j].getQuantity()
//								* stores[i].getItems()[j].getPriceitem();
//			}
		}
	}

	return mapBrandPrice;
}
//6-------------------------------------------------------------------------------
void Operation::MostProfitable() {
	PairTypeProfit a;
	TypeToProfit mapp;
	mapp = typeToProfit();
	a.type = mapp.begin()->first;
	a.bestincome = mapp.begin()->second;
	for (TypeToProfit::const_iterator it = mapp.begin(); it != mapp.end(); ++it)
		if (a.bestincome < it->second) {
			a.bestincome = it->second;
			a.type = it->first;
		}
	cout << a.type << "=>" << a.bestincome;
}
//7______________________________________________________________
// Search by type/Търсене по тип
void Operation::searchByType() {
	string type;
	cin >> type;
	for (unsigned i = 0; i < stores.size(); i++) {
		for (unsigned j = 0; j < stores[i].getItems().size(); j++) {

			if (stores[i].getItems()[j].getType() == type) {
				cout << stores[i].getItems()[j].getType() << "=>"
						<< stores[i].getItems()[j].getQuantity() << "=>"
						<< stores[i].getItems()[j].getPriceitem() << "\n";
			}
		}
	}
}
//7______________________________________________________________

// income By Type
void Operation::incomeByType() {

	TypeToProfit mapTypePrice;
	for (unsigned i = 0; i < stores.size(); i++) {
		for (unsigned j = 0; j < stores[i].getItems().size(); j++) {

			mapTypePrice[stores[i].getItems()[j].getType()] +=
					stores[i].getItems()[j].getQuantity()
							* stores[i].getItems()[j].getPriceitem();

		}
	}
	cout << "Type" << "\t\t\t\t" << "Income" << endl;
	for (TypeToProfit::const_iterator it = mapTypePrice.begin();
			it != mapTypePrice.end(); ++it)
		cout << it->first << "\t\t\t\t" << it->second << '\n';
}

//__5_________________________________________________________________
//Calculate company daily income/Изчислете дневния доход на компанията
//double Operation::companyDailyIncome() {
//	double sum = 0;
//
//	for (unsigned i = 0; i < itemsAll.size(); i++) {
//		sum += itemsAll[i].getQuantity() * itemsAll[i].getPriceitem();
//	}
//	return sum;
//}
//__6_________________________________________________________________
//vzema edin vector obekt ot Store i go napylva v itemsAll

//void Operation::addItemsAll(vector<Store> stores) {
//
//	for (unsigned i = 0; i < stores.size(); i++) {
//
//
//		vector<Item> tmp = stores[i].getItems();
//	for (unsigned j = 0; j < tmp.size(); j++) {
//		itemsAll.push_back(tmp[j]);
//	}
//	}
//}
