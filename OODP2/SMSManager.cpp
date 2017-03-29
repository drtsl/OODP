#include "SMS.h"
#include "SMSManager.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "AddressBookManager.h"



using namespace std;


SMSManager::SMSManager()
{
	Load();
}

void SMSManager::DisplaySMSHistory(){
	int index = 1;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	for (auto e : SMSManager::SMSV) {
		cout << index++ << "  ";
		if (e.getSent() == 1) {
			cout << "->  ";
		}
		else {
			cout << "<-  ";
		}
		if (e.NameFromAddress() == "not_exist") {
			cout << e.getFrom() << endl;
		}
		else {
			cout << e.NameFromAddress() << endl;
		}
		if (e.getMessage().length() > 10) {
			string cut = e.getMessage().substr(0, 10);
			cout << cut << endl << endl;
		}
		else {
			cout << e.getMessage() << endl << endl;
		}
	}
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

void SMSManager::printoneSMS(int index_){
	index_--;
	if (index_ <= SMSV.size()) {
		auto e = SMSV.begin();
		for (int i = 0; i < index_; ++i) {
			e++;
		}
		cout << "--------------------" << endl;
		if (e->NameFromAddress() == "not_exist") {
			cout << e->PhoneFromAddress() << endl;
		}
		else {
			cout << e->NameFromAddress() << endl;
		}
		cout << "********************" << endl;
		cout << e->getTime() << endl;
		cout << "********************" << endl;
		//print message,if longer than 10 letters,cut and print in next line
		int count = 1;
		string text = e->getMessage();
		while (1) {
			if (text.length()>10) {
				string temp = text.substr(0, 11);
				cout << temp << endl;
				text.erase(0, 11);
			}
			else {
				cout << text << endl;
				break;
			}
		}
		cout << "--------------------" << endl;
	}
}

void SMSManager::addressSet(vector<Address> addressv_) {
	for (auto adv = addressv_.begin(); adv != addressv_.end(); ++adv) {
		for (auto chv = SMSV.begin(); chv != SMSV.end(); ++chv) {
			if (chv->getFrom() == adv->getPhoneNumber()) {
				chv->setAddress(*adv);
			}
		}
	}
}


bool existInVector(vector<string>& v, string s){
    for(vector<string>::iterator it = v.begin(); it != v.end(); it++){
        if(*(it) == s)
            return true;
    }
    return false;
}

void SMSManager::SendSMS(string phone_){
	cout << "Type the message to send" << endl;
	string input;
	cin >> input;
	CurrentTime now;
	SMSV.push_back(SMS(phone_, 1, input, now));
}

void SMSManager::ReceiveSMS(string phone_){
	cout << "Type the message to receive" << endl;
	string input;
	cin >> input;
	CurrentTime now;
	SMSV.push_back(SMS(phone_, 0, input, now));
}

void SMSManager::Save(){
    ofstream SMSFile;
    SMSFile.open("SMSFile.txt");
    if(!SMSFile.is_open()){
        cerr << "file FAILED to open!!" << endl;
        SMSFile.close();
    }
    else{
        // save # of SMS
        SMSFile << SMSV.size() << endl;
        for(vector<SMS>::iterator it = SMSV.begin(); it != SMSV.end(); it++){
            SMSFile << it->getFrom() << " " << it->getSent() << " " << it->getMessage() << " " << it->getTime() << endl;
        }
    }

    SMSFile.close();
}

void SMSManager::Load(){
    ifstream SMSFile;
    SMSFile.open("SMSFile.txt");
    if(!SMSFile.is_open()){
        cerr << "file FAILED to open!!" << endl;
        SMSFile.close();
    }
    else{
        SMSV.clear();
		string from, message, record;
        bool sent;
        int size, year, month, day, hour, min, sec;
        SMSFile >> size;
        for(int i = 0; i < size; i++){
			SMSFile >> from >> sent >> message >> record;
            SMS sms(from, sent, message, CurrentTime(record));
            SMSV.push_back(sms);
        }
    }

    SMSFile.close();
}

void SMSManager::deleteSMS(int index_){
	index_--;
	if (index_ <= SMSV.size()) {
		auto e = SMSV.begin();
		for (int i = 0; i < index_; ++i) {
			e++;
		}
		SMSV.erase(e);
	}
}

string SMSManager::SearchByIndex(int index_) {
	index_--;
	if (index_ <= SMSV.size()) {
		auto e = SMSV.begin();
		for (int i = 0; i < index_; ++i) {
			e++;
		}
		return e->PhoneFromAddress();
	}
	return "error";
}
