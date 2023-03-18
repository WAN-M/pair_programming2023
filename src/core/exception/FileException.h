//
// Created by DELL on 2023/3/18.
//

#ifndef CORE_FILEEXCEPTION_H
#define CORE_FILEEXCEPTION_H

#include <string>

class FileException : std::exception {
private:
    std::string infomation;
public:
    explicit FileException(const std::string &infomation);

    const std::string &getInfomation() const;
};


#endif //CORE_FILEEXCEPTION_H
