//
// Created by DELL on 2023/3/18.
//

#include "RuntimeException.h"

RuntimeException::RuntimeException(const std::string &infomation) : infomation(infomation) {}

const std::string &RuntimeException::getInfomation() const {
    return infomation;
}