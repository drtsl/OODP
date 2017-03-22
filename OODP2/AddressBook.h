#ifndef __ADDRESS_BOOK__
#define __ADDRESS_BOOK__

#include <string>
#include <vector>
#include "AddressBook.h"

using namespace std;

class Address {
public:
    Address(){};
    Address(string name_, string phoneNumber_, string email_, string address_, string memo_, string alias_)
    : name(name_), phoneNumber(phoneNumber_), email(email_), address(address_), memo(memo_), alias(alias_) {}
	Address(string name_, string phoneNumber_, string email_)
    : name(name_), phoneNumber(phoneNumber_), email(email_), address("None"), memo("None"), alias("None"){}
    string getName(){return name;}
    void setName(string name_){name = name_;}
    string getPhoneNumber(){return phoneNumber;}
    void setPhoneNumber(string phoneNumber_){phoneNumber = phoneNumber_;}
    string getEmail(){return email;}
    void setEmail(string email_){email = email_;}
    string getAddress(){return address;}
    void setAddress(string address_){address = address_;}
    string getMemo(){return memo;}
    void setMemo(string memo_){memo = memo_;}
    string getAlias(){return alias;}
    void setAlias(string alias_){alias = alias_;}
	void printAddress();

private:
    string name;
    string phoneNumber;
    string email;
    string address;
    string memo;
    string alias;
};

class Date{
public:
    Date() : day(0), month(0), year(0), hour(0), min(0){}
    Date(int year_, int month_, int day_, int hour_, int min_)
    : year(year_), month(month_), day(day_), hour(hour_), min(min_){}
    int day;
    int month;
    int year;
    int hour;
    int min;
};

class SMS {
public:
    void setFrom(string from_){from = from_;}
    string getFrom(){return from;}
    void setTo(string to_){to = to_;}
    string getTo(){return to;}
    void setMessage(string message_){message = message_;}
    string getMessage(){return message;}
    void setDate(Date date_){date = date_;}
    void setDate(int year, int month, int day, int hour, int min){date = Date(year, month, day, hour, min);}
    Date getDate(){return date;}

private:
    string from;
    string to;
    string message;
    Date date;
};




#endif /* end of include guard: __ADDRESS_BOOK__ */
