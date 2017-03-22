#include "Call.h"
#include"CallManager.h"
#include"AddressBook.h"
#include<fstream>
#include<iostream>
#include<algorithm>
#include<ctime>


void CallManager::saveCallHistory() {
	ofstream callhistory;
	callhistory.open("Callhistory.txt");
	if (!callhistory.is_open()) {
		cerr << "file FAILED to open!" << endl;
		callhistory.close();
	}
	else {
		// save address to file.
		for (auto it = callV.begin(); it != callV.end(); it++) {
			callhistory << it->getphonenum << " " << it->getfromto() << " " << it->getmissedcall() << " "
				<< it->getcalltime() << " " << it->getcallstarttime() << endl;
		}
		cout << "Save Succesful!" << endl;
		callhistory.close();
	}
}
void CallManager::loadCallHistory() {
	ifstream callhistory;
	callhistory.open("callhistory.txt");
	if (!callhistory.is_open()) {
		cerr << "file FAILED to open!" << endl;
		callhistory.close();
	}
	else {
		callV.clear();
		// load address from file.
		while (callhistory.eof()) {
			string phonenum, callstartT;
			int fromto, missed, callT;
			callhistory >> phonenum >> fromto >> missed >> callT >> callstartT;
			callV.push_back(Call(phonenum, fromto, missed, callT, callstartT));
		}
		cout << "Load Succesful!" << endl;
		callhistory.close();
		void sortHistory();
	}
}
void CallManager::sortHistory() {
	sort(callV.begin(), callV.end(), comparetime);
}
bool CallManager::comparetime(Call &lhs, Call &rhs) {
	return lhs.getcallstarttime() < rhs.getcallstarttime();
}
string CallManager::currentTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%y-%m-%d.%x", &tstruct);
	return buf;
}
void CallManager::call_to() {
	string input, calltime_;
	cout << "Type the name or Phone number" << endl;
	cin >> input;
	while (1) {

	}
	sortHistory();
}
void CallManager::call_from() {

	sortHistory();
}