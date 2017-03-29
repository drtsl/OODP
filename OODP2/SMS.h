#ifndef __SMS__
#define __SMS__
#include "time.h"
#include "AddressBook.h"

using namespace std;

class SMS {
public:
	SMS(string from_, bool sent_, string message_, CurrentTime time_);
	void setFrom(string from_) { from = from_; }
	string getFrom() { return from; }
	void setSent(bool sent_) { sent = sent_; }
	bool getSent() { return sent; }
	void setMessage(string message_) { message = message_; }
	string getMessage() { return message; }
	void setAddress(Address add_) { address = add_; }
	string PhoneFromAddress();
	string NameFromAddress();
	string getTime();

private:
	string from; // Phone number
	bool sent; // 1: sent by me  0: received
	string message;
	CurrentTime time;
	Address address;
};

#endif