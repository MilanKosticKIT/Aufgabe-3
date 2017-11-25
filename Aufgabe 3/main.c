//
//  main.c
//  Aufgabe 3
//
//  Created by Milan Kostic on 15.11.17.
//  Copyright © 2017 Milan Kostic. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int breakIntoWords(char* line, int maxwords, char* words[]);
void cutFirstWord(char** restLine, char seperator, char** words[], int wordNumber);
void printTestMethod1(int testNumber,int status, int maxW, int w);

int breakIntoWords(char* line, int maxwords, char* words[]){
    int wordCounter;
    char* restLine = line;
    for(wordCounter = 0; wordCounter < maxwords && *restLine != '\0'; wordCounter++){
//        Solange es weniger Wörter im Array gibt als die Maximale Anzahl der
//        erwünschten Wörter. (sollen weitere Wörter abgetrennt werden.)
//        Erstes Wort abtrennen
        cutFirstWord(&restLine, ' ', &words, wordCounter);
    }
    return wordCounter;
}

void cutFirstWord(char** restLine, char seperator, char** words[],
                  int wordNumber){
    words[wordNumber] = restLine;
//    Mögliche Fehlerquelle
    for(; **restLine == seperator || **restLine == '\0'; restLine++){ }
//    Ende des ersten Wortes oder des Satzes gefunden
    if(*restLine != '\0') {
//        Sofern ein weiteres Wort gefunden wurde das nicht am Ende des Satzes ist.
        **restLine = '\0';
        *restLine++;
    } else{
//        Wenn der Satz zuende ist
    }
}

typedef struct{
    char* sentence;
    char seperator;
    int wordCount;
    int maxWords;
} TestCase;

void TestMethod1(TestCase testCase, int testNumber){
    
    char **wordssss = NULL;
    int words = breakIntoWords(testCase.sentence, testCase.maxWords, wordssss);
    if(words == testCase.maxWords){
        printTestMethod1(testNumber, 1, testCase.maxWords, words);
    }else{
        printTestMethod1(testNumber, 0, testCase.maxWords, words);
    }
}

void printTestMethod1(int testNumber,int status, int maxW, int w){
    printf("Test %d:\n", testNumber);
     printf("\tStatus: ");
    if(status == 1){
        printf("OK/n");
    }else{
        printf("FAIL\n");
    }
    printf("\tMaxWords: %d\n", maxW);
    printf("\tActualWords: %d\n", w);
}

int main(int argc, const char * argv[]) {
    TestCase tests[0] = {
        {"Test No 2", ' ', 3, 2}
    };
    tests[0].sentence =  malloc(50);
    tests[0].sentence = "Hallo ich du";
    TestMethod1(tests[0], 0);
    return 0;
}
