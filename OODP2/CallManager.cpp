#include "Call.h"
#include"CallManager.h"
#include"AddressBook.h"
#include"AddressBookManager.h"
#include<fstream>
#include<iostream>
#include<time.h>
#include<ctime>
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
				<< time_to_string(it->getcallstarttime()) << " " << time_to_string(it->getcallendtime()) << endl;
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
			string phonenum, callstartS, callendS;
			int fromto, missed, callT;
			CurrentTime callstartT, callendT;
			callhistory >> phonenum >> fromto >> missed >> callstartS >> callendS;
			callstartT = string_to_time(callstartS);
			callendT = string_to_time(callendS);
			callV.push_back(Call(phonenum, fromto, missed, callstartT, callendT));
		}
		cout << "Load Succesful!" << endl;
		callhistory.close();
		sortHistory();
	}
}
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


CurrentTime CallManager::getcurrentTime() {
	time_t now;
	struct tm *tm;
	time(&now);
	tm = localtime(&now);
	CurrentTime time_now;
	time_now.year_ = (tm->tm_year) + 1900;
	time_now.month_ = (tm->tm_mon) + 1;
	time_now.day_ = (tm->tm_mday);
	time_now.hour_ = (tm->tm_hour);
	time_now.minute_ = (tm->tm_min);
	time_now.second_ = tm->tm_sec;
	return time_now;
}

void CallManager::call_to(string phone_) {
	string input, calltime_;
	int probability;
	int calledby = 1;
	int missedcall = 0;
	srand((unsigned int)time(NULL));
	CurrentTime callstart = getcurrentTime();
	probability = (rand() % 10);
	if (probability > 7) missedcall = 1; //you didn't got my call!
	switch (missedcall)
	{
	case 0:
		cout << "Type \"stop\" to stop call" << endl;
		while (input != "stop") {
			cin >> input;
		}
		CurrentTime callend = getcurrentTime();
		callV.push_back(Call(phone_, calledby, missedcall, callstart, callend));
		break;
	case 1:
		callV.push_back(Call(phone_, calledby, missedcall, callstart, callstart));
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
		CurrentTime callstart = getcurrentTime();
		cout << "Type \"stop\" to stop call" << endl;
		while (input != "stop") {
			cin >> input;
		}
		CurrentTime callend = getcurrentTime();
		callV.push_back(Call(phone_, calledby, missedcall, callstart, callend));
	}
	else {
		CurrentTime callstart = getcurrentTime();
		callV.push_back(Call(phone_, calledby, missedcall, callstart, callstart));
	}
	
}
string CallManager::time_to_string(CurrentTime time_) {
	return to_string(time_.year_) + "." + to_string(time_.month_) + "." + to_string(time_.day_) + "." + to_string(time_.hour_) + "." + to_string(time_.minute_) + "." + to_string(time_.second_);
}
CurrentTime CallManager::string_to_time(string time_) {
	CurrentTime recordtime;
	size_t pos;
	string token;
	//getyear
	pos = time_.find(".");
	token = time_.substr(0, pos);
	recordtime.year_ = stoi(token);
	time_.erase(0, pos + 1);
	//getmonth
	pos = time_.find(".");
	token = time_.substr(0, pos);
	recordtime.month_ = stoi(token);
	time_.erase(0, pos + 1);
	//getday
	pos = time_.find(".");
	token = time_.substr(0, pos);
	recordtime.day_ = stoi(token);
	time_.erase(0, pos + 1);
	//gethour
	pos = time_.find(".");
	token = time_.substr(0, pos);
	recordtime.hour_ = stoi(token);
	time_.erase(0, pos + 1);
	//getminute
	pos = time_.find(".");
	token = time_.substr(0, pos);
	recordtime.minute_ = stoi(token);
	time_.erase(0, pos + 1);

	//getsecond
	recordtime.second_ = stoi(token);
	return recordtime;
	
}

void CallManager::printCallhistory() {
	for (auto e : CallManager::callV) {
		if (e.nameinaddress() != "not_exist") {
			cout << e.nameinaddress() << "   ";
		}
		else {
			cout << e.getphonenum() << "   ";
		}
		if (e.getmissedcall()) {
			cout << endl;
		}
		else {
			cout << "(missed call)" << endl;
		}
		cout << time_to_string(e.getcallstarttime()) << "   ";
		if (e.getfromto()) {
			cout << "  to  " << endl;
		}
		else {
			cout << "from" << endl;
		}
	}
}

void CallManager::addressSet(vector<Address> addressv) {
	for (auto adv : addressv) {
		for (auto chv : CallManager::callV) {
			if (chv.getphonenum() == adv.getPhoneNumber()) {
				chv.setcalleraddress(adv);
			}
		}
	}
}