#pragma once

#include"AddressBook.h"
#include"AddressBookManager.h"
#include"Call.h"

class CallManager {
public:
	void loadCallHistory();
	void saveCallHistory();
	void printCallhistory();
	void manageHistory();
	void deleteHistory();
private:
	string currentTime();
	void call_to();
	void call_from();
	void sortHistory();
	bool comparetime(Call& lhs, Call &rhs);
	vector<Call> callV;
};


