#include "AddressBook.h"
#include "AddressBookManager.h"
#include <iostream>

using namespace std;

int main(){
    AddressBookManager adbm;

    while(1){
        int input;
        cout << "----------"<<endl
        << "1. Save" << endl
        << "2. Load" << endl
        << "3. View Addresses" << endl
        << "4. Add" << endl
        << "5. Adressbook" << endl
        << "6. Quit" << endl
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
            adbm.printAddress(3);
            break;
        case 4:
			adbm.makeAddress();
            break;
        case 5:
            adbm.addressManagement();
            break;
        case 6:
            break;
        default:
            cout << "default" << endl;
        }
        if(input == 6)
            break;
    }

    return 0;
}
