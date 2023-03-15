//
// Created by DELL on 2023/3/9.
//

#ifndef WORDLIST_ERROR_H
#define WORDLIST_ERROR_H


#include "../var/Parameter.h"

/*
 * �ṩ�������ݴ�����ʽ
 * 1. ������ϳ�ͻ
 * 2. -h c j����ָ���ַ����󣬰���δָ���ַ���ָ���ķ��ַ���ָ���ַ����ȳ���1
 * 3. �����ڵĲ���
 * 4. �����ļ����������ļ������ڡ��ļ����ɶ����ļ����Ͳ���.txt
 * 5. δָ��-r�����ݴ��ڻ�
 */
class Error {
private:
    static void quitWithError();

public:
    static void checkParas(Parameter parameter);

    static void wrongParaCombination();

    /*
     * typeȡֵ
     * 0��δָ���ַ�
     * 1��ָ�����ַ�
     * 2��ָ���ַ����ȴ���1
     */
    static void wrongSpecificAlpha(const char *para, int type);

    static void wrongParameter();

    /*
     * typeȡֵ
     * 0���ļ�������
     * 1���ļ����ɶ�
     * 2���ļ����Ͳ���.txt
     */
    static void wrongFileStatus(int type);

    static void dataCyclicWithoutR();
};


#endif //WORDLIST_ERROR_H
