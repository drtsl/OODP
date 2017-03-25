#include "Call.h"
#include"AddressBook.h"


Call::Call(string phonenum_, int calledbyyou_, int missedcall_, CurrentTime callstarttime_, CurrentTime callendtime_) {
	PhoneNumber = phonenum_;
	calledbyyou = calledbyyou_;
	missedcall = missedcall_;
	callendtime = callendtime_;
	callstarttime = callstarttime_;
	Address add("not_exist", "1", "0");
	calleraddress = add;
}

string Call::nameinaddress() {
	return calleraddress.getName();
}
