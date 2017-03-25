#include "AddressBook.h"
#include <iostream>

using namespace std;

void Address::printAddress() {
	cout << "####################" << endl;
	cout << "Name : " << "\t" << "\t" << getName() << endl;
	cout << "PhoneNumber : " << "\t" << getPhoneNumber() << endl;
	cout << "EMail : " << "\t" << getEmail() << endl;
	cout << "Address : " << "\t" << getAddress() << endl;
	cout << "Alias : " << "\t" << getAlias() << endl;
	cout << "Memo : " << "\t\t" << getMemo() << endl;
	cout << "####################" << endl;
}


