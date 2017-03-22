#include "AddressBookManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
//template <typename T>;
string templist[6] = { "name", "phone number", "email", "address", "memo", "alias" };

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
    string address, string memo, string alias){
    //cin >> name >> phoneNumber >> email >> address >> memo >> alias;
    addressV.push_back(Address(name, phoneNumber, email, address, memo, alias));
}

void AddressBookManager::printAddress(int type) {
    // type 1 : print only names
    // type 2 : print names for editing
    // type 3 : print all info
	switch (type)
	{
	case 1:
		/*
		----------
		name1
		name2
		name3
		----------
		*/
		cout << "--------------------" << endl;
		for (vector<Address>::iterator it = addressV.begin(); it != addressV.end(); it++) {
			cout << it->getName() << endl;
		}
		cout << "--------------------" << endl;
		break;
	case 2:
		cout << "--------------------" << endl;
		for (vector<Address>::iterator it = addressV.begin(); it != addressV.end(); it++) {
			cout << it->getName() << endl;
		}
		cout << "--------------------" << endl;
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "Type \"back\" to return" << endl;
		cout << "Type \"edit\" to edit profile" << endl;
		cout << "Type \"delete\" to delete" << endl;
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
        break;
    default:
        cout << "print default?" << endl;
        break;
	}
}


void AddressBookManager::addressManagement(){
	//printaddress 1=only name 2=name+guide
	string name;
	while (1) {
		printAddress(2);
		cin >> name;
		if (name == "back") {
			break;
		}
		else if (name == "delete") {
			vector<Address>::iterator delit;
			cout << "Type the name you want to delete" << endl;
			cin >> name;
			for (auto t = addressV.begin(); t != addressV.end(); ++t) {
				if (t->getName() == name) {
					delit = t;
				}
			}
			deleteAddress(delit);
		}
		else if (name == "edit") {
            bool isFound = false;
			vector<Address>::iterator changeIter;
			cout << "Who do you want to edit profile?" << endl;
			printAddress(1);
			cin >> name;
			printoneAddress(name);
			for (auto t = addressV.begin(); t != addressV.end(); ++t) {
				if (t->getName() == name) {
					changeIter = t;
                    isFound = true;
				}
			}
			if (isFound == true) {
                string input;
                string change;
				for (int i = 0; i < 6; ++i) {
					cout << "Change " << templist[i] << " ? (y/n)   ";
					cin >> input;
					if (input == "y") {
						cout << "type the " << templist[i] << endl;
						cin >> change;
						editAddress(changeIter, i, change);
					}
				}
			}
			else {
				cout << "Can't find that name!" << endl << endl;
			}
		}
		else {
			printoneAddress(name);
		}
	}
}

void AddressBookManager::printoneAddress(string name_) {
	for (auto i = addressV.begin(); i != addressV.end(); i++) {
		if (name_ == i->getName()) {
			cout << "####################" << endl;
			cout << "Name : " << "\t" << "\t" << i->getName() << endl;
			cout << "PhoneNumber : " << "\t" << i->getPhoneNumber() << endl;
			cout << "EMail : " << "\t" << i->getEmail() << endl;
			cout << "Address : " << "\t" << i->getAddress() << endl;
			cout << "Alias : " << "\t" << i->getAlias() << endl;
			cout << "Memo : " << "\t\t" << i->getMemo() << endl;
			cout << "####################" << endl << endl << endl;
		}
	}
}

void AddressBookManager::editAddress(vector<Address>::iterator it, int category_, string input_) {
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

void AddressBookManager::deleteAddress(vector<Address>::iterator it) {
	addressV.erase(it);
}

bool compareString(Address& lhs, Address& rhs) {
    return lhs.getName() < rhs.getName();
}

void AddressBookManager::sortAddress(){
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
		cout << "7.save and quit" << endl <<endl << "Type number to edit   ";
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
			cout<<endl << "     **You must input Name and Phone Number**" << endl<<endl;
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
