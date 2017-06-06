//============================================================================
// Name        : mai.cpp
// Author      :
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Operation.h"

int enterChoice();
enum CHOICE {
	DAILIALLSTORE = 1,
	DAILIEACHSTORE,
	LEAST,
	BIGGEST,
	BESTSITEM,
	MOST,
	INCOMEBYTYPE,
	SEARCHBYNAME,
	END
};

int main() {
	Store store1;
	Store store2;
	Store store3;
	vector<Store> stores;
	store1.readXML("Store01.xml");
	store2.readXML("Store02.xml");
	store3.readXML("Store03.xml");
	stores.push_back(store1);
	stores.push_back(store2);
	stores.push_back(store3);
	Operation op(stores);
	//op.print();
	int enterChoice();
	int choice;

	while ((choice = enterChoice()) != END) {
		switch (choice) {
		case DAILIALLSTORE:
			cout << "Total profit: " << op.companyProfit() << " BGL" << endl;
			break;
		case DAILIEACHSTORE:
			cout << "Store 1 Income: " << store1.calcTotalOneStore() << " BGL"
					<< endl;
			cout << "Store 2 Income: " << store2.calcTotalOneStore() << " BGL"
					<< endl;
			cout << "Store 3 Income: " << store3.calcTotalOneStore() << " BGL"
					<< endl;
			break;
		case LEAST:
			cout << "Least income store's information" << endl;
			for (int i = 0; i < (int) op.leastIncomeStore().getItems().size();
					i++) {
				op.leastIncomeStore().getItems()[i].print();
			}
			cout << endl;
			break;
		case BIGGEST:
			cout << "Biggest income store's information" << endl;
			for (int i = 0; i < (int) op.biggestIncomeStore().getItems().size();
					i++) {
				op.biggestIncomeStore().getItems()[i].print();
			}
			cout << endl;
			break;
		case BESTSITEM:
			cout << "Best selling item: ";
			op.bestSellingItem();
			cout << endl;
			break;
		case MOST:
			cout << "Most profitable item: ";
			op.MostProfitable();
			cout << endl;
			break;
		case INCOMEBYTYPE:
			op.incomeByType();
			cout << endl;
			break;
		case SEARCHBYNAME:
			cout << "Enter item name to search for:";
			op.searchByType();
			break;
			break;
		default:
			cerr << "Wrong choice";
			break;

		}
	}

	return 0;
}

int enterChoice() {

	cout << "\n\t-----------------MENU---------------------";
	cout << "\n\t|    (1)Daily income of all store         |";
	cout << "\n\t|    (2)Daily income of each store        |";
	cout << "\n\t|    (3)Least income store                |";
	cout << "\n\t|    (4)Biggest income store              |";
	cout << "\n\t|    (5)Best selling item                 |";
	cout << "\n\t|    (6)Most profitable item              |";
	cout << "\n\t|    (7)Income by Type                    |";
	cout << "\n\t|    (8)Search by item name               |";
	cout << "\n\t|    (9)END                               |";
	cout << "\n\t----------------------------------------\n\n\t";

	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}
