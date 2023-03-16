#include <iostream>
#include "input/Scanner.h"
#include "input/Parameter.h"
#include <libloaderapi.h>

using namespace std;

// 动态调用DLL库
void CallDll(char* words[], int len, char* result[])
{
    // 运行时加载DLL库
    HMODULE module = LoadLibraryA("core.dll");     // 根据DLL文件名，加载DLL，返回一个模块句柄
    if (module == nullptr)
    {
        printf("加载core.dll动态库失败\n");
        return;
    }

    printf("加载dll成功，寻找函数\n");
    typedef int(*AddFunc)(char* words[], int len, char* result[]);                  // 定义函数指针类型
//    typedef int(*AddFunc)(int num);
    AddFunc add;
    // 导出函数地址
    add = (AddFunc)GetProcAddress(module, "gen_chains_all");
//    add = (AddFunc)GetProcAddress(module, "myFunc");     // GetProcAddress返回指向的函数名的函数地址
    if(add != nullptr){
        printf("寻找函数成功，开始运行\n");
    } else{
        printf("未找到函数!\n");
    }
    try {
        int sum  = add(words, len, result);
//        int sum = add(100);
        printf("动态调用，输入个数 %d\n",len);
        for (int i = 0; i < len; i++){
            printf("%s\n", words[i]);
        }
        printf("动态调用，结果个数 %d\n",sum);
        for (int i = 0; i < 8; i++){
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
    // -w -c -n
    if(parameter.isW()){
        printf("w!\n");
        char ** res = (char **) malloc(sizeof (char *) * maxLength);
        CallDll(read, wordNumber, res);
    } else if(parameter.isC()){
        printf("c!");
    } else if(parameter.isN()){
        printf("n!");
    } else{
        //参数合理性检验已有
//        printf("must choose basic param");
    }


    return 0;
}

