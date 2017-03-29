#include "AddressBook.h"
#include "AddressBookManager.h"
#include "Call.h"
#include "CallManager.h"
#include "SMS.h"
#include "SMSManager.h"
#include <iostream>

using namespace std;

void AddressBookMessage(int num_);
void CallControllGuide();

inline bool is_only_digit(string to_check_) {
	return to_check_.find_first_not_of("0123456789") == string::npos;
}

int main(){
    AddressBookManager adbm;
	CallManager callm;
	SMSManager smsm;
	string input1,input2,command,index;

	callm.addressSet(adbm.getVector());
	smsm.addressSet(adbm.getVector());
    while(1){
        cout << "----------"<<endl
        << "1. Addressbook" << endl
        << "2. Sms" << endl
        << "3. Call" << endl
        << "4. Quit" << endl
        << "----------" << endl;
        cin >> input1;
		
		if (input1 == "1" || input1=="addressbook" || input1=="Addressbook") {
			while (1) {
				adbm.printAddress();
				AddressBookMessage(1);
				cin >> input2;
				if (input2 == "back") {
					break;
				}
				else if (input2 == "delete") {
					cout << "Type the name you want to delete" << endl;
					cin >> input2;
					adbm.deleteAddress(input2);
				}
				else if (input2 == "add") {
					adbm.makeAddress();
					callm.addressSet(adbm.getVector());
				}
				else if (input2 == "save") {
					adbm.saveAddress();
				}
				else if (input2 == "load") {
					adbm.loadAddress();
				}
				else {
					//searchbyinput2
					Address target = adbm.Searchbyname(input2);
					if (target.getName() == "not_exist") {
						target = adbm.Searchbyphone(input2);
					}
					if (target.getName() != "not_exist") {
						while (command != "back") {
							target.printAddress();
							AddressBookMessage(2);
							command = "";
							cin >> command;
							if (command == "call") {
								callm.call_to(target.getPhoneNumber());
							}
							else if (command == "sms") {
								smsm.SendSMS(target.getPhoneNumber());
							}
							else if (command == "delete") {
								break;
							}
							else if (command == "edit") {
								adbm.editAddress(input2);
							}
						}
					}
					if (command == "delete") {
						adbm.deleteAddress(input2);
					}
					command = "";
				}
			}
			
		}
		else if (input1 == "2" || input1=="sms" || input1 == "Sms" || input1 == "SMS") {
			while (1) {
				cout << "----------------------------------------------" << endl;
				cout << "Type \"save\" to save" << endl;
				cout << "Type \"load\" to load" << endl;
				cout << "Type \"send\" to send a message" << endl;
				cout << "type \"receive\" to receive a message" << endl;
				cout << "Type \"history\" to view history" << endl;
				cout << "Type \"back\" to go back" << endl;
				cout << "----------------------------------------------" << endl;
				cin >> input2;
				if (input2 == "save" || input2 == "Save" || input2 == "SAVE") {
					smsm.Save();
				}
				else if (input2 == "load" || input2 == "Load" || input2 == "LOAD") {
					smsm.Load();
				}
				else if (input2 == "send" || input2 == "Send" || input2 == "SEND") {
					cout << "Type the phone number or name" << endl;
					cin >> input2;
					string receiver = adbm.Searchbyname(input2).getName();
					if (receiver != "not_exist") {
						smsm.SendSMS(adbm.Searchbyname(input2).getPhoneNumber());
					}
					else {
						smsm.SendSMS(input2);
					}
				}
				else if (input2 == "receive" || input2 == "Receive" || input2 == "RECEIVE") {
					cout << "Type the phone number" << endl;
					cin >> input2;
					if (adbm.Searchbyphone(input2).getName() == "not_exist") {
						cout << "SMS from " << input2 << endl;
						smsm.ReceiveSMS(input2);
					}
					else {
						cout << "SMS from " << adbm.Searchbyphone(input2).getName() << endl;
						smsm.ReceiveSMS(input2);
					}
				}
				else if (input2 == "back" || input2 == "Back" || input2 == "BACK") {
					break;
				}
				else if (input2 == "history" || input2 == "History" || input2 == "HISTORY") {
					string target;
					smsm.addressSet(adbm.getVector());
					smsm.DisplaySMSHistory();
					cout << "------------------------------------------" << endl;
					cout << "type number to view full message" << endl;
					cout << "type \"back\" to get back" << endl;
					cout << "type \"delete\" to delete" << endl;
					cout << "------------------------------------------" << endl;
					cin >> index;
					if (is_only_digit(index)) {
						smsm.printoneSMS(stoi(index));
						cout << "------------------------------------------" << endl;
						cout << "type \"SMS\" to send a message" << endl;
						cout << "type \"delete\" to delete" << endl;
						cout << "type \"call\" to call" << endl;
						cout << "type anything to get back" << endl;
						cout << "------------------------------------------" << endl;
						cin >> target;
						if (target == "SMS"||target=="sms"||target=="Sms") {
							smsm.SendSMS(smsm.SearchByIndex(stoi(index)));
						}
						else if (target == "delete"||target=="Delete"||target=="DELETE") {
							smsm.deleteSMS(stoi(index));
						}
						else if (target == "call" || target == "Call" || target == "CALL") {
							callm.call_to(smsm.SearchByIndex(stoi(index)));
						}

					}
					else if (index == "back") {
						break;
					}
					else if (index == "delete") {
						cout << "Type the index to delete     ";
						cin >> target;
						if (is_only_digit(target)) {
							smsm.deleteSMS(stoi(target));
						}
					}
				}
				
			}
		}
		else if (input1 == "3" || input1 == "Call" || input1 == "call") {
			while (1) {
				CallControllGuide();
				cin >> input2;
				if (input2 == "history") {
					string target;
					while (1) {
						callm.addressSet(adbm.getVector());
						callm.printCallhistory();
						cout << "------------------------------------------" << endl;
						cout << "type number to view detailed history" << endl;
						cout << "type \"back\" to get back" << endl;
						cout << "type \"delete\" to delete" << endl;
						cout << "------------------------------------------" << endl;
						cin >> index;
						if (is_only_digit(index)) {
							callm.printdetailHistory(stoi(index));
							cout << "------------------------------------------" << endl;
							cout << "type \"call\" to give a call" << endl;
							cout << "type \"SMS\" to send message" << endl;
							cout << "type \"delete\" to delete" << endl;
							cout << "type anything to get back" << endl;
							cout << "------------------------------------------" << endl;
							cin >> target;
							if (target == "call") {
								callm.call_to(callm.gotphonebyindex(stoi(index)));
							}
							else if (target == "delete") {
								callm.deleteHistory(stoi(index));
							}
							else if (target == "SMS" || target == "Sms" || target == "sms") {
								smsm.SendSMS(callm.gotphonebyindex(stoi(index)));
							}

						}				
						else if (index == "back") {
							break;
						}
						else if (index == "delete") {
							cout << "Type the index to delete     ";
							cin >> target;
							if (is_only_digit(target)) {
								callm.deleteHistory(stoi(target));
							}
						}
					}
				}
				else if (input2 == "call_to") {
					cout << "Type the phone number or name" << endl;
					cin >> input2;
					string receiver = adbm.Searchbyname(input2).getName();
					if (receiver != "not_exist") {
						callm.call_to(adbm.Searchbyname(input2).getPhoneNumber());
					}
					else {
						callm.call_to(input2);
					}
				}
				else if (input2 == "call_from") {
					cout << "Type the phone number" << endl;
					cin >> input2;
					if (adbm.Searchbyphone(input2).getName() == "not_exist") {
						cout << "call from " << input2 << endl;
						callm.call_from(input2);
					}
					else {
						cout << "call from " << adbm.Searchbyphone(input2).getName() << endl;
						callm.call_from(input2);
					}

				}
				else if (input2 == "save") {
					callm.saveCallHistory();
				}
				else if (input2 == "load") {
					callm.loadCallHistory();
				}
				else if (input2 == "back") {
					break;
				}
				callm.addressSet(adbm.getVector());
			}
		}
		else if (input1 == "4" || input1 == "quit" || input1 == "Quit") {
			break;
		}
    }

    return 0;
}


void AddressBookMessage(int num_) {
	switch (num_)
	{
	case 1:
		cout << "@@@@@@@@@@@@@" << endl;
		cout << "Type \"save\" to save" << endl;
		cout << "Type \"load\" to load" << endl;
		cout << "Type \"back\" to return" << endl;
		cout << "Type \"add\" to add profile" << endl;
		cout << "Type \"delete\" to delete" << endl;
		cout << "Type name to view profile" << endl;
		cout << "@@@@@@@@@@@@@" << endl << endl;
		break;
	case 2:
		cout << "@@@@@@@@@@@@@" << endl;
		cout << "Type \"edit\" to edit" << endl;
		cout << "Type \"back\" to return" << endl;
		cout << "Type \"delete\" to delete" << endl;
		cout << "Type \"sms\" to send message" << endl;
		cout << "Type \"call\" to call" << endl;
		cout << "@@@@@@@@@@@@@" << endl << endl;
		break;
	}
}

void CallControllGuide() {
	cout << "@@@@@@@@@@@@@" << endl;
	cout << "Type \"save\" to save" << endl;
	cout << "Type \"load\" to load" << endl;
	cout << "Type \"back\" to return" << endl;
	cout << "Type \"history\" to view history" << endl;
	cout << "Type \"call_to\" to call" << endl;
	cout << "Type \"call_from\" receive a call" << endl;
	cout << "@@@@@@@@@@@@@" << endl;
}

