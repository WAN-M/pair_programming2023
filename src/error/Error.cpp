//
// Created by DELL on 2023/3/9.
//

#include <cstdlib>
#include <iostream>
#include "Error.h"
#include "../var/Information.h"

using namespace std;

void Error::quitWithError() {
    exit(-1);
}

void Error::checkParas(Parameter parameter) {

}

void Error::wrongParaCombination() {
    cout << PARAMETERS_CRUSH << endl;
    quitWithError();
}

void Error::wrongSpecificAlpha(const char *const para, int type) {
    cout << para << ONLY_ONE_ALPHA << endl;
    quitWithError();
}

void Error::wrongParameter() {
    cout << WRONG_PARAMETER << endl;
    quitWithError();
}

void Error::wrongFileStatus(int type) {
    switch (type) {
        case 0:
            cout << FILE_NOT_EXIST << endl;
            break;
        case 1:
            cout << FILE_UNREADABLE << endl;
            break;
        case 2:
            cout << FILE_NOT_TXT << endl;
            break;
        default:
            break;
    }
    quitWithError();
}

void Error::dataCyclicWithoutR() {
    cout << DATA_CYCLIC << endl;
    quitWithError();
}


