#include <stdio.h>
#include <stdlib.h>

int breakIntoWords(char* line, int maxWords, char* words[]);
int jumpToEndOfWord(char** actualPosition);

//MARK: - Working Code -
int breakIntoWords(char* line, int maxWords, char* words[]){
    int wordCounter;
    for(wordCounter = 0; wordCounter < maxWords; wordCounter++) {
        char* wordStart = line;
        int wordLength = jumpToEndOfWord(&line);
        //TODO: Check whether line is at its end or wehter is just the words end.
        char* endOfword = line;
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
        //TODO: Think about advancing line.
        //TODO: Check whether line is at its end or wehter is just the words end.
    }
    
    
    return wordCounter;
}


int jumpToEndOfWord(char** actualPostion){
    //Sets the line pointer to the end of the word or char*.
    int counter;
    for(counter = 0; **actualPostion != '\0' || **actualPostion != ' '; *actualPostion++, counter++){}
    return counter;
}


//MARK: - Testing Area -
typedef struct{
char* line;
int actualWords;
int maxWords;
}TestCase;


int Testing(TestCase test, int testNumber){
    
    
    return 0;
    //TODO: Return correct value at end of Testing.
}



//MARK: -
int main(int argc, const char* argv[]){
    
    
    return 0;
}
