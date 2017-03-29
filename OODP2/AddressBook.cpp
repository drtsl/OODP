#include "AddressBook.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Address::Address(string name_, string phoneNumber_, string email_, string address_, string memo_, string alias_) {
	name=name_;
	phoneNumber=phoneNumber_;
	email=email_;
	address=address_;
	memo=memo_;
	alias=alias_;
	tag = phoneNumber_.substr(3, 4);
}
Address::Address(string name_, string phoneNumber_, string email_) {
	name = name_;
	phoneNumber = phoneNumber_;
	email = email_;
	address = "None";
	memo = "None";
	alias = "None";
	tag = phoneNumber_.substr(3, 4);
}
void Address::setPhoneNumber(string phoneNumber_) {
	phoneNumber = phoneNumber_;
}




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


