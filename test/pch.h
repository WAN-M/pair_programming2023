//
// pch.h
//

#pragma once

//#include "gtest/gtest.h"

// �Զ���
int get25HeadTailConnectLongWords(char* words[]);
int getFullHeadTailConnectWords(char** words);
int getPlentyLinks(char** words);
int getPlentyCircles(char** words);

// �ֶ���
int getCircle(char** words, int* resNumber, int* maxLen);
int getSelfCircle(char** words, int* resNumber, int* maxLen);
int getSelfCircleWithUpperChar(char** words, int* resNumber, int* maxLen);
int getCircleWithUpperChar(char** words, int* resNumber, int* maxLen);
int getRepeat(char** words, int* resNumber, int* maxLen);
int getCircleWithRepeat(char** words, int* resNumber, int* maxLen);
int getDifferentCircle(char** words, int* resNumber, int* maxLen);
