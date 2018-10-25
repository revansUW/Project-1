// LinkedListDaily.cpp
// Ryan Evans
// Project 1
// Defines functions for the LList (day) class

#include "LinkedListDaily.h"
#include <utility>
#include <string>
using std::to_string;

// default constructor
LList::LList() : first_(NULL)
{}


// copy constructor
LList::LList(const LList & other) : first_(clone(other.first_))
{}

// destructor
LList::~LList()
{
    while (!empty())
    {
        removeFirst(); // remove nodes until list is empty
    }
}

// checks if this list is empty
bool LList::empty() const
{
    return first_ == NULL;
}

// add a new node in the last position
void LList::insert(float x)
{
    if (x > 0) 
    {
        if (!empty())
        {
            Node * ptr = first_;
            Node * last = first_;
            ptr = ptr->next_;
            while (ptr != NULL)
            {
                last = last->next_;
                ptr = ptr->next_;
            }
            last->next_ = new Node(x, ptr);
        }
        else
        {
            first_ = new Node(x, first_);
        }
    }
}

// to allow the overloaded '<<' operator to work
void LList::print(ostream & outfile) const
{
    outfile << "Readings: [ ";
    if (!empty())
    {
        // The first entry is printed separately because no comma
        // is needed.
        outfile << first_->entry_;
        Node * ptr = first_->next_;
        while (ptr != NULL)
        {
            outfile << ", " << ptr->entry_;
            ptr = ptr->next_;
        }
    }
    outfile << " ]";
}

// removes the first node in the list
float LList::removeFirst()
{
    float item = first_->entry_;
    Node * tempPtr = first_;
    first_ = first_->next_;
    delete tempPtr;  // deallocate the memory
    return item;
}

// returns size of the list
int LList::size() const
{
    int size = 1;
    if (empty())
    {
        return 0;
    }
    else {
        Node * ptr = first_->next_;
        while (ptr != NULL)
        {
            ptr = ptr->next_;
            size++;
        }
    }
    return size;
}

// sums the day's readings
float LList::sum() const
{
    float sum_ = 1;
    if (empty())
    {
        return 0;
    }
    else
    {
        sum_ = first_->entry_;
        Node * ptr = first_->next_;
        while (ptr != NULL)
        {
            sum_ += ptr->entry_;
            ptr = ptr->next_;
        }
        return sum_;
    }
}

// finds the reading with the lowest value
float	LList::minReading() const
{
    float min_ = 1;
    if (empty())
    {
        return 0;
    }
    else
    {
        min_ = first_->entry_;
        Node * ptr = first_->next_;
        while (ptr != NULL)
        {
            if (min_ > ptr->entry_) 
            {
                min_ = ptr->entry_;
            }
            ptr = ptr->next_;
        }
        return min_;
    }
}

// finds the reading with the largest value
float	LList::maxReading() const
{
    double max_ = 1;
    if (empty())
    {
        return 0;
    }
    else
    {
        max_ = first_->entry_;
        Node * ptr = first_->next_;
        while (ptr != NULL)
        {
            if (max_ < ptr->entry_)
            {
                max_ = ptr->entry_;
            }
            ptr = ptr->next_;
        }
        return max_;
    }
}

// summarize the day in a string
string LList::daySummary() const
{
    string dsummary;
    dsummary += "------ DAILY SUMMARY ------";
    dsummary += "The sum of the day's readings is ";
    dsummary += to_string(sum());
    dsummary += "\nThe maximum reading of the day was ";
    dsummary += to_string(maxReading());
    dsummary += "\nThe minimum reading of the day was ";
    dsummary += to_string(minReading());
    dsummary += "\nThe count of the day's readings was ";
    dsummary += to_string(size());
    dsummary += "\n";
    return dsummary;
}

// walks down the linked structure making a
// new Node for each float in the structure.
Node * LList::clone(Node * ptr)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    Node * first = new Node(ptr->entry_);
    Node * last = first;
    ptr = ptr->next_;
    while (ptr != NULL)
    {
        last->next_ = new Node(ptr->entry_);
        last = last->next_;
        ptr = ptr->next_;
    }
    return first;
}

// overloaded output operator
ostream & operator<<(ostream & outfile, const LList & list)
{
    list.print(outfile);
    return outfile;
}
