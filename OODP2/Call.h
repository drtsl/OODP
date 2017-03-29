#pragma once
#include "time.h"
#include "AddressBook.h"

class Call {
public:
	Call(string phonenum, int calledbyyou_, int missedcall_, CurrentTime callstarttime_, CurrentTime callendtime_);
	void setcalleraddress(Address address_) { calleraddress = address_; }
	string getphonenum() { return PhoneNumber; }
	int getfromto() { return calledbyyou; } //1=to, 0=from
	int getmissedcall() { return missedcall; } //0=got a call,1=missed call
	string getcallendtime();
	string getcallstarttime();
	string nameinaddress();

private:
	string PhoneNumber;
	Address calleraddress;
	int calledbyyou;//1=to, 0=from
	int missedcall;//0=got a call,1=missed call
	CurrentTime callendtime;
	CurrentTime callstarttime;
};


