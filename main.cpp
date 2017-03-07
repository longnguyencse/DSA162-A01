#include <iostream>

#include "listLib.h"
#include "eventLib.h"
#include "dbLib.h"

using namespace std;

/// NOTE: student must defined this function if they use dynamically allocated global data.
/// If student do not use any dynamic global data, please define this function as empty function
/// in your code (file processData.cpp) as follows
/// void releaseBusGlobalData() {}
void releaseBusGlobalData();

/// This function displays the content of database
void display(L1List<BusInfo_t>& bList) {
    cout.flush();
    bList.traverse(printBusInfo);
}

int main(int narg, char** argv) {
    L1List<busEvent_t>  eventList;
    L1List<BusInfo_t>   db;// database of BusInfo
    loadEvents(argv[1], eventList);
    loadBusDB(argv[2], db);

    /// Process events
    process(eventList, db);

    /// Release any global allocaed data
    releaseBusGlobalData();
    return 0;
}