#include <stdio.h>

int breakIntoWords(char* line, int maxWords, char* words[]);
void jumpToEndOfWord(char** actualPosition);

//MARK: - Working Code -
int breakIntoWords(char* line, int maxWords, char* words[]){
    for(int counter = 0; counter < maxWords; counter++) {
        char* wordStart = line;
        jumpToEndOfWord(&line);
        char* endOfword = line;
        
    }
    
    
    return 0;
    //TODO: Return correct value at end of breakIntoWords.
}


void jumpToEndOfWord(char** actualPostion){
    //Sets the line pointer to the end of the word or char*.
    for(; **actualPostion != '\0' || **actualPostion != ' '; *actualPostion++){
        
    }
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
