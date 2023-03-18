//
// Created by DELL on 2023/3/18.
//

#include "CommandException.h"

CommandException::CommandException(const std::string &infomation) : infomation(infomation) {}

const std::string &CommandException::getInfomation() const {
    return infomation;
}
