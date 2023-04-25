/**
 * @file appointment.h
 * @author Collin Murphy 
 * @brief header file for the appointment class
 * @version 0.1
 * @date 2023-04-25
 */

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <cstdlib>
#include <string>
#include <sstream>

class Appointment{

    public:

        //constructors
        Appointment();
        Appointment(std::string appData);

        //getters
        std::string getTitle();
        int getYear();
        int getMonth();
        int getDay();
        int getTime();
        int getDuration();
        std::string getDate();
        std::string getStandardTime();

        //setters
        void setTitle(std::string newTitle);
        void setYear(int newYear);
        void setMonth(int newMonth);
        void setDay(int newDay);
        void setTime(int newTime);
        void setDuration(int newDuration);
        void setDate(int newYear, int newMonth, int newDay);

        //helpers
        std::string militaryToStandard(int t);
        int standardToMilitary(std::string t);

        std::string rtrim(std::string s);
        std::string ltrim(std::string s);
        std::string trim(std::string s);
        std::string tolower(std::string s);

    private:
        std::string title;
        int year;
        int month;
        int day;
        int time;
        int duration;

};

#endif