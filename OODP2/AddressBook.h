#ifndef __ADDRESS_BOOK__
#define __ADDRESS_BOOK__
#include <iostream>

using namespace std;

class Address {
public:
	Address() {tag = "None";}
	Address(string name_, string phoneNumber_, string email_, string address_, string memo_, string alias_);
	Address(string name_, string phoneNumber_, string email_);
   
	string getName() { return name; }
    void setName(string name_){name = name_;}
    string getPhoneNumber(){return phoneNumber;}
	void setPhoneNumber(string phoneNumber_);
    string getEmail(){return email;}
    void setEmail(string email_){email = email_;}
    string getAddress(){return address;}
    void setAddress(string address_){address = address_;}
    string getMemo(){return memo;}
    void setMemo(string memo_){memo = memo_;}
    string getAlias(){return alias;}
    void setAlias(string alias_){alias = alias_;}
	string getTag() { return tag; }
	void printAddress();

private:
	string tag;
    string name;
    string phoneNumber;
    string email;
    string address;
    string memo;
    string alias;
};





#endif /* end of include guard: __ADDRESS_BOOK__ */
