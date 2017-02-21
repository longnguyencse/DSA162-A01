/*
 * =========================================================================================
 * Name        : eventLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Spring 2017
 *               This library contains functions used for event management
 * =========================================================================================
 */

#include "eventLib.h"


/// NOTE: each event will be separated by spaces, or endline character
void loadEvents(char* fName, L1List<busEvent_t> &eList) {
    ifstream inFile(fName);

    if (inFile) {
        string line;
        while (getline(inFile , line)) {
            istringstream iss(line);
            while (iss) {
                string sub;
                iss >> sub;
                busEvent_t __e(sub);
                eList.insertHead(__e);
            }
        }
        eList.reverse();
        inFile.close();
    }
    else {
        cout << "The file is not found!";
    }
}
