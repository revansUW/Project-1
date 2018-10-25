// ArrayOfWeek.cpp
// Ryan Evans
// Project 1
// defines functions for the weekly array

#include"ArrayOfWeek.h"

// constructor (day list)
// create a new list element with maximum size "MAX_SIZE (14)"
AList::AList() : listSize(0)
{
    for (int k = 0; k < MAX_SIZE; k++)
    {
        listArray[k] = new LList();
        listSize++;
    }
}

// destructor (day list)
AList::~AList()
{
    while (!isEmpty())
    {
        remove(); // remove nodes until list is empty
    }
}

// checks if the array is empty (list of days)
bool AList::isEmpty() const
{
    return listSize == 0;
}

// returns the day's list
LList AList::getDailyList()
{
    LList dayList = *listArray[curr];
    return dayList;
}

// returns a pass-by-ref version of the day's list
// this function is private
LList& AList::modifyDailyList()
{
    LList& dayList = *listArray[curr];
    return dayList;
}

// returns the list prior to the current day's
LList AList::prevDailyList()
{
    if (curr == 0) // to avoid looking for lists at negative 'curr'
    {
        LList dayList = *listArray[curr];
        return dayList;
    }
    LList dayList = *listArray[curr - 1];
    return dayList;
}

// remove and return the current element (list of days)
void AList::remove() {
    if (!(curr < 0) || (curr >= listSize)) {  // Exists current element
        LList dayList = *listArray[curr];      // Copy the element
        for (int i = curr; i < listSize; i++)   // Shift them down
            listArray[i] = listArray[i + 1];
        listSize--;                             // Decrement size
    }
}

// inserts a reading into a LList passed by reference
void AList::insertReading(float x, LList& day)
{
    day.insert(x);
}

// increments curr to the next day
void AList::nextDay()
{
    if (curr < MAX_SIZE)
    {
        curr++;
    }
    else
    {
        curr = 0;
    }
}

// sum the readings from each day of the week
float	AList::sumWeeklyReadings()
{
    int temp = curr;
    curr = 0;
    float sum = 0;
    while(curr < MAX_SIZE)
    {
        sum += getDailyList().sum();
        curr++;
    }
    curr = temp;    // reset curr to position in was in before function start
    return sum;
}

// find the largest reading from all days of the week
float	AList::maxWeeklyReading()
{
    int temp = curr;
    curr = 0;
    float max = getDailyList().maxReading();
    while (curr < MAX_SIZE)
    {
        if (max < getDailyList().maxReading())
        {
            max = getDailyList().maxReading();
        }
        curr++;
    }
    curr = temp;    // reset curr to position in was in before function start
    return max;
}

// find the smallest reading from all days of the week
float	AList::minWeeklyReading()
{
    int temp = curr;
    curr = 0;
    float min = getDailyList().minReading();
    while (curr < MAX_SIZE)
    {
        if (min > getDailyList().minReading())
        {
            min = getDailyList().minReading();
        }
        curr++;
    }
    curr = temp;    // reset curr to position in was in before function start
    return min;
}

// return list size
int AList::length()
{
    return listSize;
}

// count all readings from all days of the week
int	AList::countWeeklyReadings()
{
    int temp = curr;
    curr = 0;
    int readings = 0;
    while (curr < MAX_SIZE)
    {
        readings += getDailyList().size();
        curr++;
    }
    curr = temp;    // reset curr to position in was in before function start
    return readings;
}

// determine the day based on the value of curr
string AList::getDay() const
{
    if (curr == 0 || curr == 7)
    {
        return "Sunday";
    }
    if (curr == 1 || curr == 8)
    {
        return "Monday";
    }
    if (curr == 2 || curr == 9)
    {
        return "Tuesday";
    }
    if (curr == 3 || curr == 10)
    {
        return "Wednesday";
    }
    if (curr == 4 || curr == 11)
    {
        return "Thursday";
    }
    if (curr == 5 || curr == 12)
    {
        return "Friday";
    }
    if (curr == 6 || curr == 13)
    {
        return "Saturday";
    }
    else
    {
        return "Invalid curr value";
    }
}

// looks up a day according to int value
string AList::getDaySpecific(int day) const
{
    if (day == 0 || day == 7)
    {
        return "Sunday";
    }
    if (day == 1 || day == 8)
    {
        return "Monday";
    }
    if (day == 2 || day == 9)
    {
        return "Tuesday";
    }
    if (day == 3 || day == 10)
    {
        return "Wednesday";
    }
    if (day == 4 || day == 11)
    {
        return "Thursday";
    }
    if (day == 5 || day == 12)
    {
        return "Friday";
    }
    if (day == 6 || day == 13)
    {
        return "Saturday";
    }
    else
    {
        return "Invalid day value";
    }
}

// returns the week
string AList::getWeek() const
{
    string week = "Week 1";
    if (curr >= 7)
    {
        week = "Week 2";
    }
    return week;
}

// find the largest delta from all days of the week
string AList::weeklyDelta()
{
    int temp = curr;
    curr = 0;
    string deltaString = "\nThe max delta of the week was ";
    int delta = 0;
    int day = 0;
    int prevDay = 0;
    for (int i = 0; i < listSize; i++)
    {
        int temp = abs(getDailyList().size() - prevDailyList().size());
        if (delta < temp)
        {
            delta = temp;
            day = curr; // save the date where max was found
            prevDay = curr - 1; // and the day before
        }
        curr++;
    }
    deltaString += to_string(delta);
    deltaString += " from ";
    deltaString += getDaySpecific(prevDay);  // get string of the saved date
    deltaString += " to ";
    deltaString += getDaySpecific(day);
    curr = temp;     // reset curr to position in was in before function start
    return deltaString;
}

// summarize the week in a string
string AList::weekSummary()
{
    string wsummary;
    wsummary += "****** WEEKLY SUMMARY ******";
    wsummary += "The sum of the week's readings is ";
    wsummary += to_string(sumWeeklyReadings());
    wsummary += "\nThe maximum reading of the week was ";
    wsummary += to_string(maxWeeklyReading());
    wsummary += "\nThe minimum reading of the week was ";
    wsummary += to_string(minWeeklyReading());
    wsummary += "\nThe count of the week's readings was ";
    wsummary += to_string(countWeeklyReadings());
    wsummary += weeklyDelta();
    wsummary += "\n";
    return wsummary;
}

// prompts the user for inputs
void AList::promptUser()
{
    string input;
    cout << "Enter 'Q' to quit at any time" << endl;
    while (curr < MAX_SIZE) {
        cout << endl << getWeek() << endl
            << "The current day is " << getDay() << endl
            << getDailyList() << endl
            << "Enter 'D' or 'Day' for daily summary" << endl
            << "Enter 'W' or 'Week' for weekly summary" << endl
            << "Enter 'N' or 'Next' to go to the next day" << endl
            << "Enter a numerical reading to add it to the current day" << endl;
        cin >> input;
        cout << endl;
        if (input == "D" || input == "d" || input == "Day" || input == "day")
        {
            cout << getDailyList().daySummary() << endl;
        }
        else if (input == "W" || input == "w" || input == "Week" || input == "week")
        {
            cout << weekSummary() << endl;
        }
        else if (input == "N" || input == "n" || input == "Next" || input == "next")
        {
            if (curr == (MAX_SIZE - 1) // outputs both summaries on the last day
            {
                cout << getDailyList().daySummary() << endl
                    << weekSummary() << endl;
            }
            nextDay();
        }
        else if (input == "Q" || input == "q")
        {
            break;
        }
        else
        {
            float finput = (float)(atof(input.c_str())); // converts input numbers to float
            insertReading(finput, modifyDailyList());
        }
    }
}
