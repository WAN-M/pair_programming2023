//
// Created by Administrator on 2023/3/19.
//
#include <windows.h>
#include <iostream>
#include <fstream>
#include "input/Scanner.h"
#include "input/Parameter.h"
#include <libloaderapi.h>
#include "exception/Information.h"
#include "exception/FileException.h"
#define AS_GUI_MODULE false
#define debug true
#define res_path "solution.txt"
#define test true
using namespace std;
//
//#ifdef test
#include "forTest.h"
#include <io.h>
//#endif

HMODULE module = nullptr;
bool loadModule(char* path) {
    // ����ʱ����DLL��
    printf("%s\n", path);
    module = LoadLibraryA(path);     // ����DLL�ļ���������DLL������һ��ģ����
    if (module == nullptr)
    {
        throw FileException(NO_MODULE);
    }
    return true;
}

void tappend(string path, char* str)
{
    ofstream ofs;						//����������
    ofs.open(path, ios::app);		//��д�ķ�ʽ���ļ�
    ofs << str << endl;//д��
    ofs.close();
}

void tcreate(string path)
{
    ofstream ofs;						//����������
    ofs.open(path, ios::out);		//��д�ķ�ʽ���ļ�
    ofs << "";//д��
    ofs.close();
}

// ��̬����DLL��
void call_gen_chains_all(char* words[], int len, char* result[])
{
    //    myPrint(words, len);
    typedef int(*AddFunc)(char* words[], int len, char* result[]);
    // ���庯��ָ������
    AddFunc callFunc;
    // ����������ַ
    callFunc = (AddFunc)GetProcAddress(module, "gen_chains_all");
    // GetProcAddress����ָ��ĺ������ĺ�����ַ
    if (callFunc == nullptr) {
        throw FileException(NO_FUNCTION);
    }

    try {
        int res = callFunc(words, len, result);
        if (debug) {
            printf("��̬���ã�������� %d\n", res);
        }
        for (int i = 0; i < res; i++) {
            printf("%s\n", result[i]);
        }
    }
    catch (exception& e) {
        printf(e.what());
    }
}

// ��̬����DLL��
void call_gen_chain_word(char* words[], int len, char* result[], char head, char tail, char reject, bool enable_loop)
{
    typedef int(*AddFunc)(char* words[], int len, char* result[], char head, char tail, char reject, bool enable_loop);
    // ���庯��ָ������
    AddFunc callFunc;
    // ����������ַ
    callFunc = (AddFunc)GetProcAddress(module, "gen_chain_word");
    // GetProcAddress����ָ��ĺ������ĺ�����ַ
    if (callFunc == nullptr) {
        throw FileException(NO_FUNCTION);
    }
    try {
        int res = callFunc(words, len, result, head, tail, reject, enable_loop);
        if (debug) {
            printf("��̬���ã�������� %d\n", res);
        }
        try {
            tcreate(res_path);
            for (int i = 0; i < res; i++) {
                //            printf("%s\n", result[i]);
                tappend(res_path, result[i]);
            }
        }
        catch (exception& e) {
            throw FileException(FILE_WRITE_ERROR);
        }
    }
    catch (exception& e) {
        printf(e.what());
    }
}

// ��̬����DLL��
void call_gen_chain_char(char* words[], int len, char* result[], char head, char tail, char reject, bool enable_loop)
{
    typedef int(*AddFunc)(char* words[], int len, char* result[], char head, char tail, char reject, bool enable_loop);
    // ���庯��ָ������
    AddFunc callFunc;
    // ����������ַ
    callFunc = (AddFunc)GetProcAddress(module, "gen_chain_char");
    // GetProcAddress����ָ��ĺ������ĺ�����ַ
    if (callFunc == nullptr) {
        throw FileException(NO_FUNCTION);
    }
    try {
        int res = callFunc(words, len, result, head, tail, reject, enable_loop);
        if (debug) {
            printf("��̬���ã�������� %d\n", res);
        }
        try {
            tcreate(res_path);
            for (int i = 0; i < res; i++) {
                //            printf("%s\n", result[i]);
                tappend(res_path, result[i]);
            }
        }
        catch (exception& e) {
            throw FileException(FILE_WRITE_ERROR);
        }
    }
    catch (exception& e) {
        printf(e.what());
    }
}
//
//#ifdef test
int mainTest(int argc, char* argv[]) {
    try {
        char* path = (char*)&"D:\\pair_programming2023\\src\\core\\cmake-build-debug\\core.dll";
        if (AS_GUI_MODULE) {
            path = argv[argc - 1];
            argc = argc - 1;
            if (debug) {
                printf("��⵽��ΪGUIģ��ʹ�ã�core.dll·������Ϊ: %s\n", path);
            }
        }
        else {
            if (debug) {
                printf("��⵽��Ϊ����ģ��ʹ��\n");
            }
        }
        //    return 0;
        Scanner scanner(argc, argv);
        Parameter parameter;
        scanner.setParas(parameter);
        // ȫ������
        scanner.readFile();

        char** read = scanner.words;

        //        if(read == nullptr){
        //            printf("wrong input!");
        //            return 0;
        //        }
                // ���ʸ���
        int wordNumber = scanner.wordNumber;

        if (debug) {
            for (int i = 0; i < wordNumber; i++) {
                printf("%s\n", *(read + i));
            }
            printf("%d\n", wordNumber);
        }

        // head tail reject
        char head = parameter.getH();
        char tail = parameter.getT();
        char reject = parameter.getJ();

        // loop
        bool loop = parameter.isR();
        int maxLength = 20001;

        // result
        char** res = (char**)malloc(sizeof(char*) * maxLength);

        //// load dll
        //if (!loadModule(path))
        //    return 0;
        //// -w -c -n
        //if (parameter.isW()) {
        //    //            printf("w!\n");
        //    call_gen_chain_word(read, wordNumber, res, head, tail, reject, loop);
        //}
        //else if (parameter.isC()) {
        //    //            printf("c!\n");
        //    call_gen_chain_char(read, wordNumber, res, head, tail, reject, loop);
        //}
        //else if (parameter.isN()) {
        //    //            printf("n!\n");
        //    call_gen_chains_all(read, wordNumber, res);
        //}
        try {
            tcreate(res_path);
            for (int i = 0; i < argc; i++) {
                //            printf("%s\n", result[i]);
                tappend(res_path, argv[i]);
            }
        }
        catch (exception& e) {
            throw FileException(FILE_WRITE_ERROR);
        }

        free(res);
        free(read);
    }
    catch (exception& e) {
        printf("%s\n", e.what());
    }

    return 0;
}
//#else
//int main(int argc, char *argv[]) {
//    try{
//        char* path = (char *) &"core.dll";
//        if(AS_GUI_MODULE){
//            path = argv[argc - 1];
//            argc = argc - 1;
//            if(debug){
//                printf("��⵽��ΪGUIģ��ʹ�ã�core.dll·������Ϊ: %s\n", path);
//            }
//        } else{
//            if(debug){
//                printf("��⵽��Ϊ����ģ��ʹ��\n");
//            }
//        }
////    return 0;
//        Scanner scanner(argc, argv);
//        Parameter parameter;
//        scanner.setParas(parameter);
//        // ȫ������
//        scanner.readFile();
//
//        char** read = scanner.words;
//
////        if(read == nullptr){
////            printf("wrong input!");
////            return 0;
////        }
//        // ���ʸ���
//        int wordNumber = scanner.wordNumber;
//
//        if(debug){
//            for (int i = 0; i < wordNumber; i++){
//                printf("%s\n", *(read + i));
//            }
//            printf("%d\n", wordNumber);
//        }
//
//        // head tail reject
//        char head = parameter.getH();
//        char tail = parameter.getT();
//        char reject = parameter.getJ();
//
//        // loop
//        bool loop = parameter.isR();
//        int maxLength = 20001;
//
//        // result
//        char ** res = (char **) malloc(sizeof (char *) * maxLength);
//
//        // load dll
//        if(!loadModule(path))
//            return 0;
//        // -w -c -n
//        if(parameter.isW()){
////            printf("w!\n");
//            call_gen_chain_word(read, wordNumber, res, head, tail, reject, loop);
//        }
//        else if(parameter.isC()){
////            printf("c!\n");
//            call_gen_chain_char(read, wordNumber, res, head, tail, reject, loop);
//        }
//        else if(parameter.isN()){
////            printf("n!\n");
//            call_gen_chains_all(read, wordNumber, res);
//        }
//
//        free(res);
//        free(read);
//    }
//    catch (exception &e){
//        printf("%s\n", e.what());
//    }
//
//    return 0;
//}
//
//#endif // test