#include <iostream>
#include "input/Scanner.h"
#include "input/Parameter.h"
#include <libloaderapi.h>

using namespace std;

HMODULE module = nullptr;
void loadModule(char* path){
    // ����ʱ����DLL��
    module = LoadLibraryA(path);     // ����DLL�ļ���������DLL������һ��ģ����
    if (module == nullptr)
    {
        printf("����core.dll��̬��ʧ��\n");
    } else{
        printf("����core.dll��̬��ɹ�\n");
    }
}

// ��̬����DLL��
void call_gen_chains_all(char* words[], int len, char* result[])
{
    typedef int(*AddFunc)(char* words[], int len, char* result[]);
    // ���庯��ָ������
    AddFunc callFunc;
    // ����������ַ
    callFunc = (AddFunc)GetProcAddress(module, "gen_chains_all");
    // GetProcAddress����ָ��ĺ������ĺ�����ַ
    if(callFunc != nullptr){
        printf("Ѱ�Һ����ɹ�����ʼ����\n");
    } else{
        printf("δ�ҵ�����!\n");
    }
    try {
        int res  = callFunc(words, len, result);
        printf("��̬���ã�������� %d\n", res);
        for (int i = 0; i < res; i++){
            printf("%s\n", result[i]);
        }
    }
    catch (exception &e){
        printf(e.what());
    }
}

// ��̬����DLL��
void call_gen_chain_word(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop)
{
    typedef int(*AddFunc)(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop);
    // ���庯��ָ������
    AddFunc callFunc;
    // ����������ַ
    callFunc = (AddFunc)GetProcAddress(module, "gen_chain_word");
    // GetProcAddress����ָ��ĺ������ĺ�����ַ
    if(callFunc != nullptr){
        printf("Ѱ�Һ����ɹ�����ʼ����\n");
    } else{
        printf("δ�ҵ�����!\n");
    }
    try {
        int res  = callFunc(words, len, result, head, tail, reject, enable_loop);
        printf("��̬���ã�������� %d\n", res);
        for (int i = 0; i < res; i++){
            printf("%s\n", result[i]);
        }
    }
    catch (exception &e){
        printf(e.what());
    }
}

// ��̬����DLL��
void call_gen_chain_char(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop)
{
    typedef int(*AddFunc)(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop);
    // ���庯��ָ������
    AddFunc callFunc;
    // ����������ַ
    callFunc = (AddFunc)GetProcAddress(module, "gen_chain_char");
    // GetProcAddress����ָ��ĺ������ĺ�����ַ
    if(callFunc != nullptr){
        printf("Ѱ�Һ����ɹ�����ʼ����\n");
    } else{
        printf("δ�ҵ�����!\n");
    }
    try {
        int res  = callFunc(words, len, result, head, tail, reject, enable_loop);
        printf("��̬���ã�������� %d\n", res);
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
    // ȫ������
    char ** read = scanner.readFile();
    if(read == nullptr){
        printf("wrong input!");
        return 0;
    }
    // ���ʸ���
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

