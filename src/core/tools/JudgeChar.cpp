//
// Created by DELL on 2023/3/8.
//

#include "JudgeChar.h"

extern bool firstOk(Parameter parameter, char first) {
    if (parameter.getH() != 0 && first != parameter.getH()) {
        return false;
    }
    if (parameter.getJ() != 0 && first == parameter.getJ()) {
        return false;
    }
    return true;
}

extern bool firstRejected(Parameter &parameter, char first) {
    return parameter.getJ() != 0 && parameter.getJ() == first;
}

extern bool lastOk(Parameter parameter, char last) {
    if (parameter.getT() != 0 && last != parameter.getT()) {
        return false;
    }
    return true;
}