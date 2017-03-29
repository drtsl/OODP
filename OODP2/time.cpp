#include "time.h"

CurrentTime::CurrentTime(string time_) {
	size_t pos;
	string token;
	//getyear
	pos = time_.find(".");
	token = time_.substr(0, pos);
	year_ = stoi(token);
	time_.erase(0, pos + 1);
	//getmonth
	pos = time_.find(".");
	token = time_.substr(0, pos);
	month_ = stoi(token);
	time_.erase(0, pos + 1);
	//getday
	pos = time_.find("/");
	token = time_.substr(0, pos);
	day_ = stoi(token);
	time_.erase(0, pos + 1);
	//gethour
	pos = time_.find(":");
	token = time_.substr(0, pos);
	hour_ = stoi(token);
	time_.erase(0, pos + 1);
	//getminute
	pos = time_.find(":");
	token = time_.substr(0, pos);
	minute_ = stoi(token);
	time_.erase(0, pos + 1);

	//getsecond
	second_ = stoi(token);
}
CurrentTime::CurrentTime() {
	time_t now;
	struct tm *tm;
	time(&now);
	tm = localtime(&now);
	year_ = (tm->tm_year) + 1900;
	month_ = (tm->tm_mon) + 1;
	day_ = (tm->tm_mday);
	hour_ = (tm->tm_hour);
	minute_ = (tm->tm_min);
	second_ = tm->tm_sec;
}

void CurrentTime::setnow() {
	time_t now;
	struct tm *tm;
	time(&now);
	tm = localtime(&now);
	year_ = (tm->tm_year) + 1900;
	month_ = (tm->tm_mon) + 1;
	day_ = (tm->tm_mday);
	hour_ = (tm->tm_hour);
	minute_ = (tm->tm_min);
	second_ = tm->tm_sec;
}

string CurrentTime::get_time_string() {
	return to_string(year_) + "." + to_string(month_) + "." + to_string(day_);
}
string CurrentTime::get_hour_string() {
	return to_string(hour_) + ":" + to_string(minute_) + ":" + to_string(second_);
}