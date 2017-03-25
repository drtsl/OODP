#include "AddressBook.h"
#include "AddressBookManager.h"
#include "Call.h"
#include "CallManager.h"
#include <iostream>

using namespace std;

void AddressBookMessage(int num_);

int main(){
    AddressBookManager adbm;
	CallManager callm;
	string name;
	string command;
	callm.addressSet(adbm.getVector());
    while(1){
        int input;
        cout << "----------"<<endl
        << "1. Addressbook" << endl
        << "2. Sms" << endl
        << "3. Call" << endl
        << "4. Quit" << endl
        << "----------" << endl;
        cin >> input;
		switch (input) {
		case 1:
			while (1) {
				adbm.printAddress();
				AddressBookMessage(1);
				cin >> name;
				if (name == "back") {
					break;
				}
				else if (name == "delete") {
					cout << "Type the name you want to delete" << endl;
					cin >> name;
					adbm.deleteAddress(name);
				}
				else if (name == "add") {
					adbm.makeAddress();
					callm.addressSet(adbm.getVector());
				}
				else {
					//searchbyname
					Address target=adbm.Searchbyname(name);
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

							}
							else if (command == "delete") {
								break;
							}
							else if (command == "edit") {
								adbm.editAddress(name);
							}	
						}
					}
					if (command == "delete") {
						adbm.deleteAddress(name);
					}
					command = "";
				}
			}
            break;
        case 2:
            //sms잘좀짜봐호준아 제발 이상한 마법눈깔가서 술쳐먹고 잠퍼자지말고
            break;
        case 3:
			callm.printCallhistory();
			cin >> name;
			
            break;
        case 4:
            break;
        default:
            cout << "default" << endl;
        }
        if(input == 4)
            break;
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

