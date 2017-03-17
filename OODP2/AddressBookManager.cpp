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
void AddressBookManager::printAddress(){
    for(vector<Address>::iterator it = addressV.begin(); it != addressV.end(); it++){
		cout << it->getName() << endl;
    }
	cout << "@@@@@@@@@@@@@@@" << endl;
	cout << "Type \"back\" to return" << endl;
	cout << "Type \"edit\" to edit profile" << endl;
	cout << "@@@@@@@@@@@@@@@" << endl;
	string name;
	while (1) {

		cin >> name;
		if (name == "back") {
			break;
		}
		else if (name == "edit") {
			string igo, change;
			cout << "Who do you want to edit profile?" << endl;
			cin >> name;
			displayperson(name);
			for (int i = 0; i < 6; ++i) {
				cout << "Change " << templist[i] << " ? (y/n)";
				cin >> igo;
				if (igo == "y") {
					editprofile(name, i, change);
				}
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
			cout << "Name : " << "\t" << "\t" << i->getName() << endl;
			cout << "PhoneNumber : " << "\t" << i->getPhoneNumber() << endl;
			cout << "EMail : " << "\t" << i->getEmail() << endl;
			cout << "Address : " << "\t" << i->getAddress() << endl;
			cout << "Alias : " << "\t" << i->getAlias() << endl;
			cout << "Memo : " << "\t" << i->getMemo() << endl;
		}
	}
}

void AddressBookManager::editprofile(string name_, int category_, string input_) {
	for (auto i = addressV.begin(); i != addressV.end(); i++) {
		if (name_ == i->getName()) {
			switch (category_)
			{
			case 1:
				i->setName(input_);
			case 2:
				i->setPhoneNumber(input_);
			case 3:
				i->setEmail(input_);
			case 4:
				i->setAddress(input_);
			case 5:
				i->setMemo(input_);
			case 6:
				i->setAlias(input_);
			}
		
		}
	}
}