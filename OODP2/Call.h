#pragma once

#include"AddressBook.h"
#include"AddressBookManager.h"
struct CurrentTime {
	int year_;
	int month_;
	int day_;
	int hour_;
	int minute_;
	int second_;
};

class Call {
public:
	Call(string phonenum, int calledbyyou_, int missedcall_, CurrentTime callstarttime_, CurrentTime callendtime_);
	void setcalleraddress(Address address_) { calleraddress = address_; }
	string getphonenum() { return PhoneNumber; }
	int getfromto() { return calledbyyou; } //1=to, 0=from
	int getmissedcall() { return missedcall; } //1=got a call,0=missed call
	CurrentTime getcallendtime() { return callendtime; }
	CurrentTime getcallstarttime() { return callstarttime; }
	string nameinaddress();

private:
	string PhoneNumber;
	Address calleraddress;
	int calledbyyou;//1=to, 0=from
	int missedcall;//0=got a call,1=missed call
	CurrentTime callendtime;
	CurrentTime callstarttime;
};


