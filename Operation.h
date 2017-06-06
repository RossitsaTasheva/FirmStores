/*
 * Operation.h
 *
 *  Created on: 23.05.2017 г.
 *      Author: Rossi
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include "Store.h"

struct PairTypeProfit {
	string type;
	double bestincome;
};
struct PairTypeQuantity {
	string type;
	int quantity;
};

typedef map<string, int> TypeToQuantity;
typedef map<string, double> TypeToProfit;

class Operation {
public:
	Operation();
	Operation(vector<Store>);
	virtual ~Operation();
	void print();
	void printMap(TypeToQuantity mapp);
	void printVectorStores();
	double companyProfit(); //Pechalbata na companiata
	//Least income store/Магазин за най-малък доход
	const Store leastIncomeStore();
	// Biggest income store/Най-големият магазин за доходи
	const Store biggestIncomeStore();
	TypeToQuantity typeToQuantity();
	TypeToProfit typeToProfit();
	void MostProfitable();
	void bestSellingItem();
	// Search by type/Търсене по тип
	void searchByType();
	void incomeByType();

private:
	vector<Store> stores;
};

#endif /* OPERATION_H_ */
