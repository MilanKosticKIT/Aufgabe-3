#include <stdio.h>
#include <stdlib.h>

int breakIntoWords(char* line, int maxWords, char* words[]);
int jumpToEndOfWord(char** actualPosition);

//MARK: - Working Code -
int breakIntoWords(char* line, int maxWords, char* words[]){
    for(int counter = 0; counter < maxWords; counter++) {
        char* wordStart = line;
        int wordLength = jumpToEndOfWord(&line);
        char* endOfword = line;
        char* wordLocation = (char*)malloc(sizeof(char) * (wordLength + 1));
        
        //Mark word end.
        *(wordStart + wordLength) = '\0';
        
    }
    
    
    return 0;
    //TODO: Return correct value at end of breakIntoWords.
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
