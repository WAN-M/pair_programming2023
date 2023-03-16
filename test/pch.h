//
// pch.h
//

#pragma once

//#include "gtest/gtest.h"

// 自动化
int get25HeadTailConnectLongWords(char* words[]);
int getFullHeadTailConnectWords(char** words);
int getPlentyLinks(char** words);
int getPlentyCircles(char** words);

// 手动化
int getCircle(char** words);
int getSelfCircle(char** words, int* resNumber, int* maxLen);
int getSelfCircleWithUpperChar(char** words);
int getCircleWithUpperChar(char** words);
int getRepeat(char** words);
int getCircleWithRepeat(char** words);
int getDifferentCircle(char** words);
