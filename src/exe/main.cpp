#include <iostream>
#include "input/Scanner.h"
#include "input/Parameter.h"
#include <libloaderapi.h>
#define AS_GUI_MODULE false

using namespace std;

HMODULE module = nullptr;
bool loadModule(char* path){
    // 运行时加载DLL库
    module = LoadLibraryA(path);     // 根据DLL文件名，加载DLL，返回一个模块句柄
    if (module == nullptr)
    {
        printf("加载core.dll动态库失败\n");
        return false;
    } else{
        printf("加载core.dll动态库成功\n");
        return true;
    }
}

void myPrint(char * words[], int length){
    for(int i = 0; i < length; i++){
        printf("%s\n", words[i]);
    }
}

// 动态调用DLL库
void call_gen_chains_all(char* words[], int len, char* result[])
{
//    myPrint(words, len);
    typedef int(*AddFunc)(char* words[], int len, char* result[]);
    // 定义函数指针类型
    AddFunc callFunc;
    // 导出函数地址
    callFunc = (AddFunc)GetProcAddress(module, "gen_chains_all");
    // GetProcAddress返回指向的函数名的函数地址
    if(callFunc != nullptr){
        printf("寻找函数成功，开始运行\n");
    } else{
        printf("未找到函数!\n");
    }
    try {
        int res  = callFunc(words, len, result);
        printf("动态调用，结果个数 %d\n", res);
        for (int i = 0; i < res; i++){
            printf("%s\n", result[i]);
        }
    }
    catch (exception &e){
        printf(e.what());
    }
}

// 动态调用DLL库
void call_gen_chain_word(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop)
{
    typedef int(*AddFunc)(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop);
    // 定义函数指针类型
    AddFunc callFunc;
    // 导出函数地址
    callFunc = (AddFunc)GetProcAddress(module, "gen_chain_word");
    // GetProcAddress返回指向的函数名的函数地址
    if(callFunc != nullptr){
        printf("寻找函数成功，开始运行\n");
    } else{
        printf("未找到函数!\n");
    }
    try {
        int res  = callFunc(words, len, result, head, tail, reject, enable_loop);
        printf("动态调用，结果个数 %d\n", res);
        for (int i = 0; i < res; i++){
            printf("%s\n", result[i]);
        }
    }
    catch (exception &e){
        printf(e.what());
    }
}

// 动态调用DLL库
void call_gen_chain_char(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop)
{
    typedef int(*AddFunc)(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop);
    // 定义函数指针类型
    AddFunc callFunc;
    // 导出函数地址
    callFunc = (AddFunc)GetProcAddress(module, "gen_chain_char");
    // GetProcAddress返回指向的函数名的函数地址
    if(callFunc != nullptr){
        printf("寻找函数成功，开始运行\n");
    } else{
        printf("未找到函数!\n");
    }
    try {
        int res  = callFunc(words, len, result, head, tail, reject, enable_loop);
        printf("动态调用，结果个数 %d\n", res);
        for (int i = 0; i < res; i++){
            printf("%s\n", result[i]);
        }
    }
    catch (exception &e){
        printf(e.what());
    }
}

int main(int argc, char *argv[]) {
    char* path = (char *) &"core.dll";
    if(AS_GUI_MODULE){
        path = argv[argc - 1];
        printf("检测到作为GUI模块使用，core.dll路径输入为: %s\n", path);
        argc = argc - 1;
    } else{
        printf("检测到作为独立模块使用\n");
    }
//    return 0;
    Scanner scanner(argc, argv);
    Parameter parameter;
    scanner.setParas(parameter);
    // 全部单词
    scanner.readFile();

    char** read = scanner.words;

    if(read == nullptr){
        printf("wrong input!");
        return 0;
    }
    // 单词个数
    int wordNumber = scanner.wordNumber;

    for (int i = 0; i < wordNumber; i++){
        printf("%s\n", *(read + i));
    }

    printf("%d\n", wordNumber);

    // head tail reject
    char head = parameter.getH();
    char tail = parameter.getT();
    char reject = parameter.getJ();

    // loop
    bool loop = parameter.isR();
    int maxLength = 20001;

    // result
    char ** res = (char **) malloc(sizeof (char *) * maxLength);

    // load dll
    if(!loadModule(path))
        return 0;
    // -w -c -n
    if(parameter.isW()){
        printf("w!\n");
        call_gen_chain_word(read, wordNumber, res, head, tail, reject, loop);
    }
    if(parameter.isC()){
        printf("c!\n");
        call_gen_chain_char(read, wordNumber, res, head, tail, reject, loop);
    }
    if(parameter.isN()){
        printf("n!\n");
        call_gen_chains_all(read, wordNumber, res);
    }

    free(res);
    free(read);

    return 0;
}

