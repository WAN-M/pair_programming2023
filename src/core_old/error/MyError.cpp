//
// Created by DELL on 2023/3/9.
//

#include <cstdlib>
#include <iostream>
#include "MyError.h"
#include "../var/Information.h"

using namespace std;

MyError::MyError(string reason)
{
    this->reason = reason;
}

void MyError::quitWithMyError(string reason) {
    throw MyError(reason);
}


//void MyError::checkParas(Parameter parameter) {
//    if (parameter.isN() && (parameter.isC() || parameter.isW() || parameter.isR() ||
//                            parameter.getT() != 0 || parameter.getJ() != 0 || parameter.getH() != 0)) {
//        wrongParaCombination();
//    }
//    if (parameter.isW() && parameter.isC()) {
//        wrongParaCombination();
//    }
//    if (!(parameter.isN() || parameter.isW() || parameter.isC())) {
//        wrongParaCombination();
//    }
//}

//void MyError::wrongParaCombination() {
//    cout << PARAMETERS_CRUSH << endl;
//    quitWithMyError(PARAMETERS_CRUSH);
//}

//void MyError::wrongSpecificAlpha(const char *const para, int type) {
//    cout << para << ONLY_ONE_ALPHA << endl;
//    quitWithMyError(ONLY_ONE_ALPHA);
//}

//void MyError::wrongParameter() {
//    cout << WRONG_PARAMETER << endl;
//    quitWithMyError(WRONG_PARAMETER);
//}

//void MyError::wrongFileStatus(int type) {
//    string reason = "unkown";
//    switch (type) {
//        case 0:
//            cout << FILE_NOT_EXIST << endl;
//            reason = FILE_NOT_EXIST;
//            break;
//        case 1:
//            cout << FILE_UNREADABLE << endl;
//            reason = FILE_UNREADABLE;
//            break;
//        case 2:
//            cout << FILE_NOT_TXT << endl;
//            reason = FILE_NOT_TXT;
//            break;
//        default:
//            break;
//    }
//    quitWithMyError(reason);
//}

void MyError::dataCyclicWithoutR() {
    cout << DATA_CYCLIC << endl;
    quitWithMyError(DATA_CYCLIC);
}


