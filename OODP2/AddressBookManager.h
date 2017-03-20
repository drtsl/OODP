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
    void Addresscontroller();
	void printAddress(int range);
    void addAddress(string name, string phoneNumber, string email, string address, string memo, string alias);
	void addbasicAddress(string name, string phoneNumber, string email);
	void displayperson(string name_);
	void editprofile(vector<Address>::iterator it, int category_, string input_);
    void deleteAddress(vector<Address>::iterator it);


private:
    vector<Address> addressV;
};



#endif /* end of include guard: __ADDRESS_BOOK_MANGER__ */
