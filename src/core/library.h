#ifndef CORE_LIBRARY_H
#define CORE_LIBRARY_H

int gen_chains_all(char* words[], int len, char* result[]);

int gen_chain_word(char* words[], int len, char* result[], char head, char tail, char reject, bool enable_loop);

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, char reject, bool enable_loop);

#endif //CORE_LIBRARY_H
