#pragma once

#include<time.h>
#include <iostream>
#include<string>
using namespace std;

class CurrentTime {
public:
	CurrentTime();
	CurrentTime(string time_);

	void setnow();

	string get_time_string();
	string get_hour_string();

	int year_;
	int month_;
	int day_;
	int hour_;
	int minute_;
	int second_;
	
};