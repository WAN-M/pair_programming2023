//
// Created by DELL on 2023/3/18.
//

#include "FileException.h"

FileException::FileException(const std::string &infomation) : infomation(infomation) {}

const std::string &FileException::getInfomation() const {
    return infomation;
}

const char *FileException::what() const noexcept {
    return infomation.c_str();
}