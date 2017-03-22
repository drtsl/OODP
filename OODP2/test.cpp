#include "AddressBook.h"
#include "AddressBookManager.h"
#include "Call.h"
#include "CallManager.h"
#include <iostream>

using namespace std;

int main(){
    AddressBookManager adbm;

    while(1){
        int input;
        cout << "----------"<<endl
        << "1. Save" << endl
        << "2. Load" << endl
        << "3. Add" << endl
        << "4. Adressbook" << endl
        << "5. Quit" << endl
        << "----------" << endl;
        cin >> input;
        switch(input){
        case 1:
            adbm.saveAddress();
            break;
        case 2:
            adbm.loadAddress();
            break;
        case 3:
			adbm.makeAddress();
            break;
        case 4:
            adbm.addressManagement();
            break;
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
