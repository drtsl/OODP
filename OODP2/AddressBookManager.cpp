#include "AddressBookManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "AddressBook.h"
#include <string>

using namespace std;
//template <typename T>;
string templist[6] = { "name", "phone number", "email", "address", "memo", "alias" };

AddressBookManager::AddressBookManager() {
	loadAddress();
}
void AddressBookManager::saveAddress() {
	ofstream addressFile;
	addressFile.open("addressFile.txt");
	if (!addressFile.is_open()) {
		cerr << "file FAILED to open!" << endl;
		addressFile.close();
	}
	else {
		// save # of addresses
		addressFile << addressV.size() << endl;
		// save address to file.
		for (vector<Address>::iterator it = addressV.begin(); it != addressV.end(); it++) {
			addressFile << it->getName() << " " << it->getPhoneNumber() << " " << it->getEmail() << " "
				<< it->getAddress() << " " << it->getMemo() << " " << it->getAlias() << endl;
		}
		cout << "Save Succesful!" << endl;
		addressFile.close();
	}
}

void AddressBookManager::loadAddress() {
	ifstream addressFile;
	addressFile.open("addressFile.txt");
	if (!addressFile.is_open()) {
		cerr << "file FAILED to open!" << endl;
		addressFile.close();
	}
	else {
		addressV.clear();
		// get # of addresses
		int num_adresses;
		addressFile >> num_adresses;
		// load address from file.
		for (int i = 0; i < num_adresses; i++) {
			string name, phoneNumber, email, address, memo, alias;
			addressFile >> name >> phoneNumber >> email >> address >> memo >> alias;
			addressV.push_back(Address(name, phoneNumber, email, address, memo, alias));
		}
		cout << "Load Succesful!" << endl;
		addressFile.close();
		sortAddress();
	}
}

void AddressBookManager::addAddress(string name, string phoneNumber, string email,
	string address, string memo, string alias) {
	//cin >> name >> phoneNumber >> email >> address >> memo >> alias;
	addressV.push_back(Address(name, phoneNumber, email, address, memo, alias));
}

void AddressBookManager::printAddress() {
		cout << "--------------------" << endl;
		for (vector<Address>::iterator it = addressV.begin(); it != addressV.end(); it++) {
			cout << it->getName() << endl;
		}
		cout << "--------------------" << endl;
}


void AddressBookManager::editAddress(string name_) {
	int input;
	string change;
	bool isFound = false;
	vector<Address>::iterator target_iter;
	for (auto t = addressV.begin(); t != addressV.end(); ++t) {
		if (t->getName() == name_) {
			target_iter = t;
			isFound = true;
			t->printAddress();
		}
	}
	if (isFound == true) {
		while (1){
			cout << "1. name    : " << target_iter->getName() << endl
				<< "2. phone#  : " << target_iter->getPhoneNumber() << endl
				<< "3. email   : " << target_iter->getEmail() << endl
				<< "4. address : " << target_iter->getAddress() << endl
				<< "5. alias   : " << target_iter->getAlias() << endl
				<< "6. memo    :" << target_iter->getMemo() << endl;
			cout << "7.save and quit" << endl << endl << "Type number to edit   ";
			cin >> input;
			switch (input)
			{
			case 1:
				cout << "name: ";
				cin >> change;
				target_iter->setName(change);
				break;
			case 2:
				cout << "phone number: ";
				cin >> change;
				target_iter->setPhoneNumber(change);
				break;
			case 3:
				cout << "email: ";
				cin >> change;
				target_iter->setEmail(change);
				break;
			case 4:
				cout << "address: ";
				cin >> change;
				target_iter->setAddress(change);
				break;
			case 5:
				cout << "alias: ";
				cin >> change;
				target_iter->setAlias(change);
				break;
			case 6:
				cout << "memo: ";
				cin >> change;
				target_iter->setMemo(change);
				break;
			case 7:
				break;
			}
			if (input == 7) {
				break;
			}
		
		}
	}

}

void AddressBookManager::editing(vector<Address>::iterator it, int category_, string input_) {
	++category_;
	switch (category_)
	{
	case 1:
		it->setName(input_);
		break;
	case 2:
		it->setPhoneNumber(input_);
		break;
	case 3:
		it->setEmail(input_);
		break;
	case 4:
		it->setAddress(input_);
		break;
	case 5:
		it->setMemo(input_);
		break;
	case 6:
		it->setAlias(input_);
		break;
	}
}

void AddressBookManager::deleteAddress(string name_) {
	vector<Address>::iterator it;
	bool is_found = false;
	for (auto t = addressV.begin(); t != addressV.end(); ++t) {
		if (t->getName() == name_) {
			it = t;
			is_found = true;
		}
	}
	if (is_found) {
		addressV.erase(it);
	}
}

bool compareString(Address& lhs, Address& rhs) {
	return lhs.getName() < rhs.getName();
}

void AddressBookManager::sortAddress() {
	sort(addressV.begin(), addressV.end(), compareString);
}

void AddressBookManager::makeAddress() {
	string strarray[6];
	string yes_or_no;
	int input;
	for (int i = 0; i < 6; ++i) {
		strarray[i] = " ";
	}
	while (1) {
		cout << "1. name    : " << strarray[0] << endl
			<< "2. phone#  : " << strarray[1] << endl
			<< "3. email   : " << strarray[2] << endl
			<< "4. address : " << strarray[3] << endl
			<< "5. alias   : " << strarray[4] << endl
			<< "6. memo    :" << strarray[5] << endl;
		cout << "7.save and quit" << endl << endl << "Type number to edit   ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "name: ";
			cin >> strarray[input - 1];
			break;
		case 2:
			cout << "phone number: ";
			cin >> strarray[input - 1];
			break;
		case 3:
			cout << "email: ";
			cin >> strarray[input - 1];
			break;
		case 4:
			cout << "address: ";
			cin >> strarray[input - 1];
			break;
		case 5:
			cout << "alias: ";
			cin >> strarray[input - 1];
			break;
		case 6:
			cout << "memo: ";
			cin >> strarray[input - 1];
			break;
		case 7:
			break;
		}
		if (input == 7) {
			if (strarray[0] != " ") {
				if (strarray[1] != " ") {
					break;
				}
			}
			cout << endl << "     **You must input Name and Phone Number**" << endl << endl;
		}
	}
	for (int i = 0; i < 6; ++i) {
		if (strarray[i] == " ") {
			strarray[i] = "None";
		}
	}
	addAddress(strarray[0], strarray[1], strarray[2], strarray[3], strarray[4], strarray[5]);
	sortAddress();
}

Address AddressBookManager::Searchbyname(string name_) {
	Address searchresult("not_exist", "1", "0");
	for (auto e : AddressBookManager::addressV) {
		if (e.getName() == name_) searchresult = e;
	}
	return searchresult;
}
Address AddressBookManager::Searchbyphone(string phone_) {
	Address searchresult("not_exist", "1", "0");
	for (auto e : AddressBookManager::addressV) {
		if (e.getPhoneNumber() == phone_) searchresult = e;
	}
	return searchresult;
}
