#include "AddressBookManager.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string templist[6] = { "name", "phone number", "email", "address", "memo", "alias" };

void AddressBookManager::saveAddress(){
    ofstream addressFile;
    addressFile.open("addressFile.txt");
    if(!addressFile.is_open()){
        cerr << "file FAILED to open!" << endl;
        addressFile.close();
        return;
    }

    // save # of addresses
    addressFile << addressV.size() << endl;
    // save address to file.
    for(vector<Address>::iterator it = addressV.begin(); it != addressV.end(); it++){
        addressFile << it->getName() << " " << it->getPhoneNumber() << " " << it->getEmail() << " "
            << it->getAddress() << " " << it->getMemo() << " " << it->getAlias() << endl;
    }
	cout << "Save Succesful!" << endl;
    addressFile.close();
}

void AddressBookManager::loadAddress(){
    ifstream addressFile;
    addressFile.open("addressFile.txt");
    if(!addressFile.is_open()){
        cerr << "file FAILED to open!" << endl;
        addressFile.close();
    }

    addressV.clear();
    // get # of addresses
    int num_adresses;
    addressFile >> num_adresses;
    // load address from file.
    for(int i = 0; i < num_adresses; i++){
        string name, phoneNumber, email, address, memo, alias;
        addressFile >> name >> phoneNumber >> email >> address >> memo >> alias;
        addressV.push_back(Address(name, phoneNumber, email, address, memo, alias));
    }
	cout << "Load Succesful!" << endl;
    addressFile.close();
}

void AddressBookManager::addAddress(string name, string phoneNumber, string email,
    string address, string memo, string alias){
    //cin >> name >> phoneNumber >> email >> address >> memo >> alias;
    addressV.push_back(Address(name, phoneNumber, email, address, memo, alias));
}
void AddressBookManager::addbasicAddress(string name, string phoneNumber, string email) {
	addressV.push_back(Address(name, phoneNumber, email));
}
void AddressBookManager::printAddress(int range) {
	switch (range)
	{
	case 1:
		/*
		----------
		aaa
		bbb
		ccc
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
	}


	
}
void AddressBookManager::Addresscontroller(){
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
			string igo, change;
			vector<Address>::iterator changei;
			cout << "Who do you want to edit profile?" << endl;
			printAddress(1);
			cin >> name;
			displayperson(name);
			for (auto t = addressV.begin(); t != addressV.end(); ++t) {
				if (t->getName() == name) {
					changei = t;
					igo = "find";
				}
			}
			if (igo == "find") {
				for (int i = 0; i < 6; ++i) {
					cout << "Change " << templist[i] << " ? (y/n)   ";
					cin >> igo;
					if (igo == "y") {
						cout << "type the " << templist[i] << endl;
						cin >> change;
						editprofile(changei, i, change);
					}
				}
			}
			else {
				cout << "Can't find that name!" << endl << endl;
			}
		}
		else {
			displayperson(name);
		}
	}
}

void AddressBookManager::displayperson(string name_) {
	for (auto i = addressV.begin(); i != addressV.end(); i++) {
		if (name_ == i->getName()) {
			cout << endl << endl;
			cout << "####################" << endl;
			cout << "Name : " << "\t" << "\t" << i->getName() << endl;
			cout << "PhoneNumber : " << "\t" << i->getPhoneNumber() << endl;
			cout << "EMail : " << "\t" << i->getEmail() << endl;
			cout << "Address : " << "\t" << i->getAddress() << endl;
			cout << "Alias : " << "\t" << i->getAlias() << endl;
			cout << "Memo : " << "\t" << i->getMemo() << endl;
			cout << "####################" << endl << endl << endl;
		}
	}
}

void AddressBookManager::editprofile(vector<Address>::iterator it, int category_, string input_) {
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