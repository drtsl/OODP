#ifndef __SMS_MANAGER__
#define __SMS_MANAGER__

#include "AddressBook.h"
#include <vector>

class SMSManager {
public:
	SMSManager();
	void DisplaySMSHistory();
	void printoneSMS(int index_);
	void addressSet(vector<Address> addressv_);
	void SendSMS(string phone_);
	void ReceiveSMS(string phone_);
	void Save();
	void Load();
	void deleteSMS(int index_);
	string SearchByIndex(int index_);

private:
	vector<SMS> SMSV;
};


#endif /* end of include guard: __SMS_MANAGER_H__ */
