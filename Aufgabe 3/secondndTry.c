//#include <stdio.h>
//#include <stdlib.h>
//
//int strcmp(char* first, char* second);
//
//int breakIntoWords(char* line, int maxwords, char* words[]) {
//    int count = 0;
//    char* current = line;
//
//    while(*current != '\0') {
//        if (count < maxwords) {
//            // if ' ' is found, it is set to '\0', so that line now represents the current word
//            if (*current == ' ') {
//                *current = '\0';
//                words[count] = line;
//                count++;
//                line = current + 1; // sets the current word (line) to the current position
//            }
//            current++;
//        } else {
//            return count;
//        }
//    }
//    words[count] = line;
//    count++;
//    return count;
//}
//
//int strcmp(char* first, char* second) {
//    while (*first != '\0' && *second != '\0') {
//        if (*first != *second) {
//            return 0;
//        }
//        first++;
//        second++;
//    }
//    if (*first != *second) {
//        return 0;
//    }
//    return 1;
//}
//
//char* copyString(char* string) {
//    int size = 0;
//    char* current = string;
//    char* copy;
//
//    // gets the size of the string
//    while (*current != '\0') {
//        size++;
//        current++;
//    }
//    size++;
//
//    // copy the string
//    copy = malloc((size) * sizeof(char));
//    current = copy;
//    while (size != 0) {
//        *current = *string;
//        string++;
//        current++;
//        size--;
//    }
//
//    return copy;
//}
//
//typedef enum {
//    OK,
//    FAIL
//} Test;
//
//typedef struct {
//    char* input;
//    int maxwords;
//    char* expected[15];
//    int wordCount;
//} TestCase;
//
//Test testBreakIntoWords(char* input, int maxwords, char* expected[], int wordCountExpected) {
//    Test t;
//    int i;
//
//    char** output = (char**) malloc(maxwords * sizeof(char*));
//    int wordCount = breakIntoWords(input, maxwords, output);
//
//    t = OK;
//    if(wordCountExpected != wordCount) {
//        t = FAIL;
//    }
//    for (i = 0; i < wordCount; i++, output++) {
//        if (!strcmp(*output, expected[i])) {
//            t = FAIL;
//        }
//    }
//
//    return t;
//}
//
//void runTestBreakIntoWords(int no, TestCase test[]) {
//    Test t;
//    int i;
//    int k;
//    char* input;
//    char** output;
//    int wordCount;
//
//    printf("breakIntoWords: \n\n");
//    for(i=0; i < no; i++) {
//        input = copyString(test[i].input);
//        t = testBreakIntoWords(test[i].input, test[i].maxwords, test[i].expected, test[i].wordCount);
//        output = (char**) malloc(test[i].maxwords * sizeof(char*));
//        wordCount = breakIntoWords(copyString(input), test[i].maxwords, output);
//
//        printf("\tTest %d: ", i);
//        if(OK == t)
//            printf("OK \n");
//        if(FAIL == t)
//            printf("FAIL \n");
//        printf("\tEingabe:\n\t\tString: %s\n\t\tMaxwords: %d\n", input, test[i].maxwords);
//        for(k = 0; k < test[i].wordCount; k++) {
//            printf("\t\tExpected(%d): %s\n", k, test[i].expected[k]);
//        }
//        printf("\t\tWordCount: %d\n", test[i].wordCount);
//        printf("\tAusgabe: \n");
//        for(k = 0; k < wordCount; k++, output++) {
//            printf("\t\tOutput(%d): %s\n", k, *output);
//        }
//        printf("\t\tWordCount: %d\n\n\n", wordCount);
//    }
//
//}
//
//
//
//
//
//int main() {
//    int z;
//
//
//
//    const int testNo = 4;
//    TestCase tests[4] = {
//        {copyString("Das ist ein Beispieltext fuer die Aufgabe 3"), 4, {"Das", "ist", "ein", "Beispieltext"}, 4},
//        {copyString("as df gh"), 3, {"as", "df", "gh"}, 3},
//        {copyString("Das ist ein Beispieltext fuer die Aufgabe 3"), 10, {"Das", "ist", "ein", "Beispieltext", "fuer", "die", "Aufgabe", "3"}, 8},
//        {copyString("as df gh"), 1, {"as"}, 1}
//    };
//
//    runTestBreakIntoWords(testNo, tests);
//
//    /*
//     char string[] = "Das ist ein Beispieltext f¸r die Aufgabe 3";
//     int maxwords = 3;
//     char* output[3];
//     printf("breakIntoWords:\n");
//     z = breakIntoWords(string, maxwords, output);
//     printf("\n\t%s\n\t%s\n\t%s\n\t%d\n\n", output[0], output[1], output[2], z);
//     printf("Hallo");
//     */
//
//
//
//    scanf("%d", &z);
//    return 0;
//}
//
