#include "Call.h"
#include"AddressBook.h"


Call::Call(string phonenum_, int calledbyyou_, int missedcall_, int calltime_, string callstarttime_) {
	PhoneNumber = phonenum_;
	calledbyyou = calledbyyou_;
	missedcall = missedcall_;
	calltime = calltime_;
	callstarttime = callstarttime_;
	Address add("garbage!", "1", "0");
	calleraddress = add;
}
