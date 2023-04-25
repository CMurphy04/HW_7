#include "appointment.h"
#include <iostream>

using namespace std;

string Appointment::rtrim(string s) { // gets rid of extra spaces from the right
    string trimmed;
    for(int i = s.length()-1; i > 0; i--){
        if(s[i] != ' ' && i != s.length()-1){
            trimmed = s.erase(i+1);
            return trimmed;
        }
    }
}

string Appointment::ltrim(string s) { // gets rid of extra spaces from the left
    string trimmed = s.substr(s.find_first_not_of(" "));
    return trimmed;
}

string Appointment::trim(string s) {
    return rtrim(ltrim(s));
}

string Appointment::tolower(string s) {
    string output = "";
    char temp;
    for(int i = 0; i < s.length(); i++){
        temp = s[i];
        if(temp >= 'z' || temp <= 'a'){
		    temp += ('z' - 'Z');
	    }
        output += temp;
    }
}

Appointment::Appointment() {
    title = "N/A";
    year = 1;
    month = 1;
    day = 1;
    time = 0;
    duration = 1;
}

Appointment::Appointment(string appData) {
    stringstream ss(appData);
    string item;
    int i = 0;
    while(getline(ss, item, '|')) {
        if (i == 0) title = trim(item);
        if (i == 1) year = stoi(item);
        if (i == 2) month = stoi(item);
        if (i == 3) day = stoi(item);
        // get and parse time
        if (i == 4){
            stringstream st(item);
            string stdtime;
            string ampm;
            getline(st, stdtime, ' ');
            getline(st, ampm);
            string hours;
            string minutes;
            stringstream stdt(stdtime);
            getline(stdt, hours, ':');
            getline(stdt, minutes);
            time = stoi(hours)*100 + stoi(minutes);
            if(tolower(trim(ampm)) == "pm")
                time = time + 1200;
        }
        i++;
    }
    getline(ss, item);
    duration = stoi(item);
}

string Appointment::getTitle() {
    return title;
}

int Appointment::getYear() {
    return year;
}

int Appointment::getMonth() {
    return month;
}

int Appointment::getDay() {
    return day;
}

int Appointment::getTime() {
    return time;
}

int Appointment::getDuration() {
    return duration;
}

string Appointment::getDate() {
    string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    return date;
}

string Appointment::getStandardTime() {
    int hours = time/100;
    string ampm = "AM";
    if (hours > 12) {
        hours = hours - 12;
        ampm = "PM";
    }

    int minutes = time % 100;

    string output = to_string(hours) + ":" + to_string(minutes) + " " + ampm;

    return output;
}

void Appointment::setTitle(string newTitle) {
    title = newTitle;
}

void Appointment::setYear(int newYear) {
    year = newYear;
}

void Appointment::setMonth(int newMonth) {
    month = newMonth;
}

void Appointment::setDay(int newDay) {
    day = newDay;
}

void Appointment::setTime(int newTime) {
    time = newTime;
}

void Appointment::setDuration(int newDuration) {
    duration = newDuration;
}

void Appointment::setDate(int newYear, int newMonth, int newDay) {
    year = newYear;
    month = newMonth;
    day = newDay;
}

string Appointment::militaryToStandard(int t) {
    int hours = t/100;
    string ampm = "AM";
    if (hours > 12) {
        hours = hours - 12;
        ampm = "PM";
    }

    int minutes = t % 100;

    string stdTime = to_string(hours) + ":" + to_string(minutes) + " " + ampm;

    return stdTime;
}

int Appointment::standardToMilitary(std::string t) {
    int milTime;
    stringstream st(t);
    string stdtime;
    string ampm;
    getline(st, stdtime, ' ');
    getline(st, ampm);
    string hours;
    string minutes;
    stringstream stdt(stdtime);
    getline(stdt, hours, ':');
    getline(stdt, minutes);
    milTime = stoi(hours)*100 + stoi(minutes);
    if(tolower(trim(ampm)) == "pm")
        milTime = milTime + 1200;

    return milTime;
}