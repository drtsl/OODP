#include "AddressBook.h"
#include "AddressBookManager.h"
#include <iostream>

using namespace std;

int main(){
    AddressBookManager adbm;

    while(1){
        int input;
        cout << "----------"<<endl << "1.save" << endl << "2.load" << endl << "3.add" << endl
        << "4.print" << endl << "5.quit" << endl << "----------" << endl;
        cin >> input;
        switch(input){
        case 1:
            adbm.saveAddress();
            break;
        case 2:
            adbm.loadAddress();
            break;
        case 3:
            {
                cout << "1.(name) 2.(phone#) 3.(email)" << endl;
				string name, phoneNumber, email;
				name = phoneNumber = email = ' ';
                cin >> name >> phoneNumber >> email;
                adbm.addbasicAddress(name, phoneNumber, email);
            }
            break;
        case 4:
            adbm.printAddress();
        case 5:
            break;
        default:
            cout << "default" << endl;
        }
        if(input == 5)
            break;
    }

    return 0;
}
