#include "appointment.h"
#include <iostream>

using namespace std;

string Appointment::rtrim(string s) { // gets rid of extra spaces from the right, iterates from the end of the string until it hits a non-space character
    string trimmed;
    for(int i = s.length()-1; i > 0; i--){
        if(s[i] != ' ' && i != s.length()-1){
            trimmed = s.erase(i+1); //erases the spaces on the right
            return trimmed;
        }
    }
}

string Appointment::ltrim(string s) { // gets rid of extra spaces from the left, iterates from the beginning of the string until it hits a non-space character
    string trimmed = s.substr(s.find_first_not_of(" ")); //makes a new string without the spaces on the left
    return trimmed;
}

string Appointment::trim(string s) { //trims a string's extra spaces by doing the left then the right
    return rtrim(ltrim(s));
}

string Appointment::tolower(string s) { //converts a string to lower case by iterating through and returning a new string of characters all in lower case
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

Appointment::Appointment() { //default constructor
    title = "N/A";
    year = 1;
    month = 1;
    day = 1;
    time = 0;
    duration = 1;
}

Appointment::Appointment(string appData) { //constructor
    stringstream ss(appData);
    string item;
    int i = 0;
    while(getline(ss, item, '|')) { //read in the information from appData into the item string
        if (i == 0) title = trim(item); //sets title
        if (i == 1) year = stoi(item); //sets year
        if (i == 2) month = stoi(item); //etc.
        if (i == 3) day = stoi(item);
        //get and parse time
        if (i == 4){
            stringstream st(item);
            string stdtime;
            string ampm;
            getline(st, stdtime, ' '); //read in the time
            getline(st, ampm); //read in am or pm
            string hours;
            string minutes;
            stringstream stdt(stdtime);
            getline(stdt, hours, ':'); //parse the time by hours:minutes
            getline(stdt, minutes);
            time = stoi(hours)*100 + stoi(minutes); //converts to military
            if(tolower(trim(ampm)) == "pm")
                time = time + 1200;
        }
        i++;
    }
    getline(ss, item);
    duration = stoi(item); //sets the duration
}


//getters
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

string Appointment::getStandardTime() { //convert time into standard time
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

//setters
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

string Appointment::militaryToStandard(int t) { //takes military time int as arguments, returns as standard time string
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

int Appointment::standardToMilitary(std::string t) { //takes a standard time string and returns a military time int
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
