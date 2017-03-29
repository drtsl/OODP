#ifndef __CALLMANAGER__
#define __CALLMANAGER
#include<vector>

class CallManager {
public:
	CallManager();
	
	void printdetailHistory(int index_);
	void addressSet(vector<Address> addressv_);
	void loadCallHistory();
	void saveCallHistory();
	void printCallhistory();
	void deleteHistory(int index_);
	void call_to(string phone_);
	void call_from(string phone);
	string gotphonebyindex(int index_);
private:
	vector<Call> callV;
};

#endif // !__CALLMANAGER__
