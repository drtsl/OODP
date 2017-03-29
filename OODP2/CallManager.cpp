#include "Call.h"
#include"CallManager.h"
#include"AddressBook.h"
#include"AddressBookManager.h"
#include<fstream>
#include<iostream>
#include<time.h>
#include<algorithm>
#include<cstdlib>

CallManager::CallManager() {
	loadCallHistory();
}

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
			callhistory << it->getphonenum() << " " << it->getfromto() << " " << it->getmissedcall() << " "
				<< it->getcallstarttime() << " " << it->getcallendtime() << endl;
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
		while (!callhistory.eof()) {
			string phonenum, callstartS, callendS;
			int fromto, missed;
			callhistory >> phonenum >> fromto >> missed >> callstartS >> callendS;
			if (phonenum == "") {
				break;
			}
			CurrentTime callstartT(callstartS);
			CurrentTime callendT(callendS);
			
			callV.push_back(Call(phonenum, fromto, missed, callstartT, callendT));
		}
		cout << "Load Succesful!" << endl;
		callhistory.close();
	}
}
/*
bool comparetime(Call &lhs, Call &rhs) {
	if (lhs.getcallstarttime().year_ == lhs.getcallstarttime().year_) {
		if (lhs.getcallstarttime().month_ == lhs.getcallstarttime().month_) {
			if (lhs.getcallstarttime().day_ == lhs.getcallstarttime().day_) {
				if (lhs.getcallstarttime().hour_ == lhs.getcallstarttime().hour_) {
					if (lhs.getcallstarttime().second_ == lhs.getcallstarttime().second_) {
							return lhs.getcallstarttime().minute_ < rhs.getcallstarttime().minute_;
					}
					else {
						return lhs.getcallstarttime().second_ < rhs.getcallstarttime().second_;
					}
				}
				else {
					return lhs.getcallstarttime().hour_ < rhs.getcallstarttime().hour_;
				}
			}
			else {
				return lhs.getcallstarttime().day_ < rhs.getcallstarttime().day_;
			}
		}
		else {
			return lhs.getcallstarttime().month_ < rhs.getcallstarttime().month_;
		}
	}
	else {
		return lhs.getcallstarttime().year_ < rhs.getcallstarttime().year_;
	}
}

void CallManager::sortHistory() {
	sort(callV.begin(), callV.end(), comparetime);
}
*/


void CallManager::call_to(string phone_) {
	string input, calltime_;
	int probability;
	int calledby = 1;
	int missedcall = 0;
	srand((unsigned int)time(NULL));
	CurrentTime callstart, callend;
	probability = (rand() % 10);
	if (probability > 7) missedcall = 1; //you didn't got my call!
	switch (missedcall)
	{
	case 0:
		cout << "Type \"stop\" to stop call" << endl;
		while (input != "stop") {
			cin >> input;
		}
		callend.setnow();
		callV.push_back(Call(phone_, calledby, missedcall, callstart, callend));
		break;
	case 1:
		cout << "He didn't response. Maybe bad timing. Try later!" << endl;
		callV.push_back(Call(phone_, calledby, missedcall, callstart, callend));
		break;
	}
}


void CallManager::call_from(string phone_) {
	string input, calltime_;
	int calledby = 0;
	int missedcall = 1;
	cout << "You got a call! Type \"y\" to got a call. else you will reject phone call" << endl;
	cin >> input;
	if (input == "y") {
		missedcall = 0;
		CurrentTime callstart;
		cout << "Type \"stop\" to stop call" << endl;
		while (input != "stop") {
			cin >> input;
		}
		CurrentTime callend;
		callV.push_back(Call(phone_, calledby, missedcall, callstart, callend));
	}
	else {
		CurrentTime callstart;
		callV.push_back(Call(phone_, calledby, missedcall, callstart, callstart));
	}
	
}




void CallManager::printCallhistory() {
	int index = 1;
	for (auto e : CallManager::callV) {
		cout << index << ".  ";
		if (e.nameinaddress() != "not_exist") {
			cout << e.nameinaddress() << "   ";
		}
		else {
			cout << e.getphonenum() << "   ";
		}
		if (e.getmissedcall()) {
			cout << "(missed call)" << endl;
		}
		else {
			cout << endl;
		}
		cout << e.getcallstarttime()<< "   ";
		if (e.getfromto()) {
			cout << "  to  " << endl << endl;
		}
		else {
			cout << "from" << endl << endl;
		}
		++index;
	}
}

void CallManager::addressSet(vector<Address> addressv) {
	for (auto adv = addressv.begin(); adv != addressv.end();++adv) {
		for (auto chv = callV.begin(); chv != callV.end(); ++chv) {
			if (chv->getphonenum() == adv->getPhoneNumber()) {
				chv->setcalleraddress(*adv);
			}
		}
	}
}

void CallManager::deleteHistory(int index_) {
	
	if (index_ <= callV.size()) {
		index_--;
		auto e = callV.begin();
		for (int i = 0; i < index_; ++i) {
			e++;
		}
		callV.erase(e);
	}
}
void CallManager::printdetailHistory(int index_) {
	
	if (index_ <= callV.size()) {
		index_--;
		auto e = callV.begin();
		for (int i = 0; i < index_; ++i) {
			e++;
		}
		if (e->nameinaddress() == "not_exist") {
			cout << e->getphonenum() << endl;
		}
		else {
			cout << e->nameinaddress() << endl;
		}
		cout << e->getphonenum() << endl;
		if (e->getfromto()) {
			cout << "called   to    /";
		}
		else {
			cout << "called from    ||";
		}
		if (e->getmissedcall()) {
			cout << "     missed call" << endl;
		}
		else {
			cout << "     not missed" << endl;
		}
		cout << "call started : " << e->getcallstarttime() << endl;
		cout << "call ended   : " << e->getcallendtime() << endl;
		cout << "call time    : " << e->calltime() << endl;
	}

}

string CallManager::gotphonebyindex(int index_) {
	index_--;
	if (index_ <= callV.size()) {
		auto e = callV.begin();
		for (int i = 0; i < index_; ++i) {
			e++;
		}
		return e->getphonenum();
	}
	return "error";
}


