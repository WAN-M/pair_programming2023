//
// Created by DELL on 2023/3/18.
//

#ifndef CORE_RUNTIMEEXCEPTION_H
#define CORE_RUNTIMEEXCEPTION_H

#include <string>

class RuntimeException : public std::exception {
private:
    std::string infomation;
public:
    explicit RuntimeException(const std::string &infomation);
    const char* what() const noexcept override;
    const std::string &getInfomation() const;
};


#endif //CORE_RUNTIMEEXCEPTION_H
