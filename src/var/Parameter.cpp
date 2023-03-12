//
// Created by DELL on 2023/3/7.
//

#include "Parameter.h"

bool Parameter::isN() const {
    return n;
}

void Parameter::setN(bool n) {
    Parameter::n = n;
}

bool Parameter::isW() const {
    return w;
}

void Parameter::setW(bool w) {
    Parameter::w = w;
}

bool Parameter::isC() const {
    return c;
}

void Parameter::setC(bool c) {
    Parameter::c = c;
}

bool Parameter::isR() const {
    return r;
}

void Parameter::setR(bool r) {
    Parameter::r = r;
}

char Parameter::getH() const {
    return h;
}

void Parameter::setH(char h) {
    Parameter::h = h;
}

char Parameter::getT() const {
    return t;
}

void Parameter::setT(char t) {
    Parameter::t = t;
}

char Parameter::getJ() const {
    return j;
}

void Parameter::setJ(char j) {
    Parameter::j = j;
}
