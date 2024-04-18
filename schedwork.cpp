#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here


// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below
    std::vector<int> whrs;
    for(unsigned int i=0; i<avail[0].size();i++)
    {
        whrs.push_back(0);
    }
    sched.resize(avail.size());
    bool b = ched(avail, dailyNeed, maxShifts,sched,0,whrs,0);
    return b;
}
bool ched(const AvailabilityMatrix& avail, const size_t dailyNeed, const size_t maxShifts, DailySchedule& sched, unsigned int day,std::vector<int> whrs,unsigned int dhrs)
{
    if(day>=avail.size())
    {
        return true;
    }
    if(dhrs==dailyNeed)
    {
        return ched(avail,dailyNeed,maxShifts,sched,day+1,whrs,0);
    }
    else
    {
        for(unsigned int i=0; i<avail[day].size();i++)
        {
            if(avail[day][i]!=true)
            {
                continue;
            }
            if(whrs[i]<maxShifts)
            {
                sched[day].push_back(i);
                whrs[i]=whrs[i]+1;
                bool state= ched(avail,dailyNeed,maxShifts,sched,day,whrs,dhrs+1);
                if(state)
                {
                    return true;
                }
                sched[day].pop_back();
                whrs[i]=whrs[i]-1;
            }
        }
    }
    return false;
}


