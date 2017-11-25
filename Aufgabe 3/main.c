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
//            char* endOfword = line;
            char* wordLocation = (char*)malloc(sizeof(char) * (wordLength + 1));
            
            //Mark word end.
            *(wordStart + wordLength) = '\0';
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
        }
    }
    return wordCounter;
}


int jumpToEndOfWord(char** actualPostion){
    //Sets the line pointer to the end of the word or char*.
    int counter;
    for(counter = 0; **actualPostion != '\0' || **actualPostion != ' '; *actualPostion++, counter++){}
    return counter;
}

int jumpToStart(int* going,char** line){
    //Jumps over all ' ' that are at the begininig of the current (possible)
    for(;**line == ' ' && **line != '\0';*line++){}
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
    int actualWords;
    int maxWords;
}TestCase;

typedef struct{
    char** words;
    int wordsCount;
}TestResult;


void Testing(TestCase test, int testNumber){
    int seizeOfLine = size(test.line);
    char** words = (char**)malloc(sizeof(char) * (seizeOfLine + 1));
    int countOfWords = breakIntoWords(test.line, test.maxWords, words);
}

void printTest(TestResult result, TestCase test){
    
}

int size(char* line){
    int counter;
    for (counter = 0; line != '\0'; counter++, line++) {}
    return counter;
}

//MARK: -
int main(int argc, const char* argv[]){
    
    
    return 0;
}
