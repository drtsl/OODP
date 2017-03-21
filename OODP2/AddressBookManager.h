#ifndef __ADDRESS_BOOK_MANGER__
#define __ADDRESS_BOOK_MANGER__

#include <vector>
#include "AddressBook.h"
#include "AddressBookManager.h"

using namespace std;

class AddressBookManager{
public:
    void saveAddress();
    void loadAddress();
    void addressManagement();
	void printAddress(int type);
    void addAddress(string name, string phoneNumber, string email, string address, string memo, string alias);
	//void addBasicAddress(string name, string phoneNumber, string email);
	void printoneAddress(string name_);
	void editAddress(vector<Address>::iterator it, int category_, string input_);
    void deleteAddress(vector<Address>::iterator it);
    void showAddress();
    void sortAddress();
	void makeAddress();
    
private:

    vector<Address> addressV;
};



#endif /* end of include guard: __ADDRESS_BOOK_MANGER__ */
