/*
 * =========================================================================================
 * Name        : eventLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Spring 2017
 *               This library contains functions used for event management
 * =========================================================================================
 */

#ifndef A01_EVENTLIB_H
#define A01_EVENTLIB_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>

#include "listLib.h"

#define EVENT_CODE_SIZE     16
using namespace std;

typedef struct busEvent {
    char        code[EVENT_CODE_SIZE];

    busEvent() {
        strcpy(code, "0");// default event is "0"
    }
    busEvent(char* str) {
        strncpy(code, str, EVENT_CODE_SIZE - 1);
    }
    busEvent(string& str) {
        strncpy(code, str.data(), EVENT_CODE_SIZE - 1);
    }
    busEvent(busEvent& a) { // copy constructor
        memcpy(code, a.code, EVENT_CODE_SIZE);
    }
} busEvent_t;

void loadEvents(char* fName, L1List<busEvent_t> &eList);

#endif //A01_EVENTLIB_H
