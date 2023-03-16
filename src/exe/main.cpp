#include <iostream>
#include "input/Scanner.h"
#include "input/Parameter.h"
#include <libloaderapi.h>

using namespace std;

HMODULE module = nullptr;
void loadModule(char* path){
    // 运行时加载DLL库
    module = LoadLibraryA(path);     // 根据DLL文件名，加载DLL，返回一个模块句柄
    if (module == nullptr)
    {
        printf("加载core.dll动态库失败\n");
    } else{
        printf("加载core.dll动态库成功\n");
    }
}

// 动态调用DLL库
void call_gen_chains_all(char* words[], int len, char* result[])
{
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
    Scanner scanner(argc, argv);
    Parameter parameter;
    scanner.setParas(parameter);
    // 全部单词
    char ** read = scanner.readFile();
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
    string path = "core.dll";
    loadModule((char *)path.c_str());
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

    return 0;
}

