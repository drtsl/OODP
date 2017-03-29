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
	Address add("not_exist", "1111111111", "0");
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
string Call::calltime() {
	int year = callendtime.year_ - callstarttime.year_;
	int month = callendtime.month_ - callstarttime.month_;
	int day = callendtime.day_ - callstarttime.day_;
	int hour = callendtime.hour_ - callstarttime.hour_;
	int minute = callendtime.minute_ - callstarttime.minute_;
	int second = callendtime.second_ - callstarttime.second_;
	if (year != 0 || month != 0 || day != 0 ) {
		return "talked tooooooooo long";
	}
	if (second < 0) {
		minute--;
		second = second + 60;
	}
	if (minute < 0) {
		hour--;
		minute = minute + 60;
	}
	if (hour < 0) {
		return "unbelievable result. i can't understand it";
	}
	return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}