#include "Call.h"
#include"AddressBook.h"
#include"AddressBookManager.h"
#include"time.h"

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
string Call::getcallendtime() {
	return callendtime.get_time_string() +"/"+ callendtime.get_hour_string();
}
string Call::getcallstarttime() {
	return callstarttime.get_time_string() + "/" + callstarttime.get_hour_string();
}