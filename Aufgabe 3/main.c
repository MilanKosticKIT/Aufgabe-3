#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int breakIntoWords(char* line, int maxWords, char* words[]);
int jumpToEndOfWord(char** actualPosition);
int jumpToStart(int* going,char** line);
int size(char* line);

//MARK: - Working Code -
int breakIntoWords(char* line, int maxWords, char* words[]){
    int wordCounter;
    int goinig = 1; //Wheter the algoriythm should go on.
    for(wordCounter = 0; wordCounter < maxWords && goinig == 1; wordCounter++) {
        if(jumpToStart(&goinig, &line)){
            char* wordStart = line;
            int wordLength = jumpToEndOfWord(&line);
            line = wordStart;
            //            char* endOfword = line;
            char* wordLocation = (char*)malloc(sizeof(char) * (wordLength + 1));
            
            //Mark word end.
            //*(wordStart + wordLength) = '\0';
            //USEFULL when i store it osomewhere else?
            //Possibility to leave the check for end of line into for-statement
            
            words[wordCounter] = wordLocation;
            
            //Write word into new location.
            for (int writingCounter = 0; writingCounter < wordLength; writingCounter++) {
                *wordLocation = *line;
                wordLocation++;
                line++;
            }
            *wordLocation = '\0';
            
            //Checking whether the line is at its end.
            if (*line == '\0') {
                goinig = 0;
            } else {
                //                *line = '\0';
                //Not Neccessary when using malloc
                line++;
            }
        }else if (!wordCounter){
            wordCounter = wordCounter - 1;
        }
    }
    return wordCounter;
}


int jumpToEndOfWord(char** actualPostion){
    //Sets the line pointer to the end of the word or char*.
    int counter;
    for(counter = 0; **actualPostion != '\0' && **actualPostion != ' ';counter++){
        (*actualPostion)++;
    }
    return counter;
}

int jumpToStart(int* going,char** line){
    //Jumps over all ' ' that are at the begininig of the current (possible)
    for(;**line == ' ' && **line != '\0'; (*line)++){}
    if (**line != '\0') {
        *going = 1;
    } else {
        *going = 0;
    }
    return *going;
}

//MARK: - Testing Area -
typedef struct{
    char* line;
    char* input[20];//Contains all words of line
    int actualWords;
    int maxWords;
}TestCase;

typedef struct{
    char** words;
    int wordsCount;
    int stauts;
}TestResult;


void printTest(TestResult result, TestCase test, int testNumber){
    printf("TEST %d: ", testNumber);
    if(result.stauts){
        printf("SUCESS\n");
    }else{
        printf("FAIL\n");
    }
    
    //Input
    printf("Line: \"%s\"\n", test.line);
//    printf("\tInput:\n");
    for(int counter = 0; counter < test.actualWords; counter++){
        printf("\tInput:\t\"%s\"\n",test.input[counter]);
    }
    printf("\tActualWords: %d\n", test.actualWords);
    printf("\tMaxWords: %d\n", test.maxWords);
    printf("\n");
    //Output
    printf("\tReturnedWords: %d\n", result.wordsCount);
    for (int counter = 0; counter < result.wordsCount; counter++) {
        printf("\tOutput:\t\"%s\"\n", result.words[counter]);
    }
    printf("________________________\n\n");
}


void Testing(TestCase test, int testNumber){
    int seizeOfLine = size(test.line);
    char** words = (char**)malloc(sizeof(char) * (seizeOfLine + 1));
    TestResult result;
    result.wordsCount = breakIntoWords(test.line, test.maxWords, words);
    result.words = words;
    if(result.wordsCount == test.maxWords){
        if (result.wordsCount > test.actualWords) {
            result.stauts = 0;
        } else {
            result.stauts = 1;
        }
    } else if(result.wordsCount == test.actualWords){
        result.stauts = 1;
    } else {
        result.stauts = 0;
    }
    printTest(result, test, testNumber);
}


int size(char* line){
    int counter;
    for (counter = 0; *line != '\0'; counter++, line++) {}
    return counter;
}

//MARK: -
int main(int argc, const char* argv[]){
    int testCounter = 8;
    TestCase tests[] = {
        {"Hallo du", {"Hallo", "du"}, 2, 2},
        {"Wenn du kommst", {"Wenn", "du", "kommst"}, 3, 2},
        {"Heute nicht", {"Heute", "nicht"}, 2, 3},
        {"Das wird nichts", {"Das", "wird", "nichts"}, 3, 0},
        {"", {""}, 0, 6},
        {" Achtung Leerzeichen vorne", {"Achtung", "Leerzeichen", "vorne"}, 3, 3},
        {"Mittendrin   Genügend", {"Mittendrin", "Genügend"}, 2, 2},
        {"Einsamkeit", {"Einsamkeit"}, 1, 1}
    };
    for(int counter = 0; counter < testCounter; counter++){
        Testing(tests[counter], counter);
    }
    
    return 0;
}
