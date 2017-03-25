#ifndef __ADDRESS_BOOK_MANGER__
#define __ADDRESS_BOOK_MANGER__

#include <vector>
#include "AddressBook.h"
#include "AddressBookManager.h"

using namespace std;

class AddressBookManager{
public:
	AddressBookManager();
    void saveAddress();
    void loadAddress();
	void printAddress();
    void addAddress(string name, string phoneNumber, string email, string address, string memo, string alias);
    void deleteAddress(string name_);
	void editAddress(string name_);
	void makeAddress();
	vector<Address> getVector() { return addressV; }
	Address Searchbyname(string name_);
	Address Searchbyphone(string number_);
    
private:
	void editing(vector<Address>::iterator it, int category_, string input_);
	void sortAddress();
    vector<Address> addressV;
};



#endif /* end of include guard: __ADDRESS_BOOK_MANGER__ */
