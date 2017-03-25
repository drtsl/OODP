#pragma once

#include"AddressBook.h"
#include"AddressBookManager.h"
#include"Call.h"

class CallManager {
public:
	CallManager();
	void addressSet(vector<Address> addressv_);
	void loadCallHistory();
	void saveCallHistory();
	void printCallhistory();
	void deleteHistory();
	void call_to(string phone_);
	void call_from(string phone);
private:
	CurrentTime getcurrentTime();
	string time_to_string(CurrentTime time_);
	CurrentTime string_to_time(string time_);
	void sortHistory();
	vector<Call> callV;
};


