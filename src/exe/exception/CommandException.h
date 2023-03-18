//
// Created by DELL on 2023/3/18.
//

#ifndef CORE_COMMANDEXCEPTION_H
#define CORE_COMMANDEXCEPTION_H

#include <string>

class CommandException : std::exception {
private:
    std::string infomation;
public:
    explicit CommandException(const std::string &infomation);

    const std::string &getInfomation() const;
};


#endif //CORE_COMMANDEXCEPTION_H
