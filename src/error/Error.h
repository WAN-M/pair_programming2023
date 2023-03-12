//
// Created by DELL on 2023/3/9.
//

#ifndef WORDLIST_ERROR_H
#define WORDLIST_ERROR_H


#include "../var/Parameter.h"

/*
 * 提供各种数据错误处理方式
 * 1. 参数组合冲突
 * 2. -h c j参数指定字符错误，包括未指定字符、指定的非字符和指定字符长度超过1
 * 3. 不存在的参数
 * 4. 数据文件出错，包括文件不存在、文件不可读和文件类型不是.txt
 * 5. 未指定-r但数据存在环
 */
class Error {
private:
    static void quitWithError();

public:
    static void checkParas(Parameter parameter);

    static void wrongParaCombination();

    /*
     * type取值
     * 0：未指定字符
     * 1：指定非字符
     * 2：指定字符长度大于1
     */
    static void wrongSpecificAlpha(const char *para, int type);

    static void wrongParameter();

    /*
     * type取值
     * 0：文件不存在
     * 1：文件不可读
     * 2：文件类型不是.txt
     */
    static void wrongFileStatus(int type);

    static void dataCyclicWithoutR();
};


#endif //WORDLIST_ERROR_H
