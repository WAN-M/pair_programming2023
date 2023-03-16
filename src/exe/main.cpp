#include <iostream>
#include "input/Scanner.h"
#include "input/Parameter.h"
#include <libloaderapi.h>

using namespace std;

// ��̬����DLL��
void CallDll(char* words[], int len, char* result[])
{
    // ����ʱ����DLL��
    HMODULE module = LoadLibraryA("core.dll");     // ����DLL�ļ���������DLL������һ��ģ����
    if (module == nullptr)
    {
        printf("����core.dll��̬��ʧ��\n");
        return;
    }

    printf("����dll�ɹ���Ѱ�Һ���\n");
    typedef int(*AddFunc)(char* words[], int len, char* result[]);                  // ���庯��ָ������
    AddFunc add;
    // ����������ַ
    add = (AddFunc)GetProcAddress(module, "gen_chains_all");     // GetProcAddress����ָ��ĺ������ĺ�����ַ
    printf("Ѱ�Һ����ɹ�����ʼ����\n");
    int sum  = add(words, len, result);
    printf("��̬���ã�sum = %d\n",sum);
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

    // -w -c -n
    if(parameter.isW()){
        printf("w!\n");
        char ** res;
        CallDll(read, wordNumber, res);
    } else if(parameter.isC()){
        printf("c!");
    } else if(parameter.isN()){
        printf("n!");
    } else{
        //���������Լ�������
//        printf("must choose basic param");
    }


    return 0;
}

