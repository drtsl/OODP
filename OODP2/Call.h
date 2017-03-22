#pragma once

#include"AddressBook.h"
#include"AddressBookManager.h"

class Call {
public:
	Call(string phonenum,int calledbyyou_, int missedcall_, int calltime_, string callstarttime_);
	void setcalleraddress(Address address_) { calleraddress = address_; }
	string getphonenum() { return PhoneNumber; }
	int getfromto() { return calledbyyou; } //1=to, 0=from
	int getmissedcall() { return missedcall; } //1=got a call,0=missed call
	int getcalltime() { return calltime; }
	string getcallstarttime() { return callstarttime; }
private:
	string PhoneNumber;
	Address calleraddress;
	int calledbyyou;
	int missedcall;
	int calltime;
	string callstarttime;
};


