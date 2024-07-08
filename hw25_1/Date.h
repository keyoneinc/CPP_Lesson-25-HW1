#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

struct Date {
	int year;
	int month;
	int day;
};

bool compareDates(const Date& d1, const Date& d2) {
	if (d1.year < d2.year) return true;
	else if (d1.year > d2.year) return false;
	else if (d1.month < d2.month) return true;
	else if (d1.month > d2.month) return false;
	else return d1.day < d2.day;
}

bool isPastDate(const Date& d) {
	time_t now = time(nullptr);
	tm* timeinfo = localtime(&now);
	Date currentDate{ timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday };
	return compareDates(d, currentDate);
}