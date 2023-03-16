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
//    typedef int(*AddFunc)(int num);
    AddFunc add;
    // ����������ַ
    add = (AddFunc)GetProcAddress(module, "gen_chains_all");
//    add = (AddFunc)GetProcAddress(module, "myFunc");     // GetProcAddress����ָ��ĺ������ĺ�����ַ
    if(add != nullptr){
        printf("Ѱ�Һ����ɹ�����ʼ����\n");
    } else{
        printf("δ�ҵ�����!\n");
    }
    try {
        int sum  = add(words, len, result);
//        int sum = add(100);
        printf("��̬���ã�������� %d\n",len);
        for (int i = 0; i < len; i++){
            printf("%s\n", words[i]);
        }
        printf("��̬���ã�������� %d\n",sum);
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
        //���������Լ�������
//        printf("must choose basic param");
    }


    return 0;
}

