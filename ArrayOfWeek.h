// ArrayOfWeek.h
// Ryan Evans
// Project 1
// prototypes functions for the weekly array

#ifndef _ARRAY_LIST_W_
#define _ARRAY_LIST_W_

#include <iostream>
#include <string>
#include "LinkedListDaily.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::abs;

// Array-based list implementation
class AList
{
public:

    AList();
    ~AList();
    bool isEmpty() const;
    LList getDailyList();
    LList prevDailyList();
    void remove();
    void insertReading(float x, LList& day);
    void nextDay();
    float	sumWeeklyReadings();
    float	maxWeeklyReading();
    float	minWeeklyReading();
    int length();
    int	countWeeklyReadings();
    string getDay() const;
    string getDaySpecific(int day) const;
    string getWeek() const;
    string weeklyDelta();
    string weekSummary();
    void promptUser();

private:
    LList & modifyDailyList();
    int MAX_SIZE = 14;
    LList* listArray[14];  //Array holding list elements
    int listSize;   //Current number of list items
    int curr = 0;   //Position of current element
};
#endif