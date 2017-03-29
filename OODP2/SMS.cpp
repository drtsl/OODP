#include "SMS.h"
#include "AddressBook.h"
#include "AddressBookManager.h"
#include "time.h"

SMS::SMS(string from_, bool sent_, string message_, CurrentTime time_)
{
	from = from_;
	sent = sent_;
	message = message_;
	time = time_;
	Address nowhere("not_exist", "1111111111", "0");
	address = nowhere;
}

string SMS::PhoneFromAddress() {
	return address.getPhoneNumber();

}
string SMS::NameFromAddress() {
	return address.getName();
}
string SMS::getTime() {
	return time.get_time_string() + "/" + time.get_hour_string();
}