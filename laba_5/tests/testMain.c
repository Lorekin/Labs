//
// Created by Kirill Zhukov on 14.12.2022.
//


#include <assert.h>
#include "stdio.h"
#include "common.h"

#define SIZE 5
const char* URL = "/Users/kirillzhukov/Desktop/kmbo--20/lab_4-10/laba_5/build/text.txt";
#define EQ(a, b) ((a) == (b))
#define N_EQ(a, b) !EQ(a, b)

void nothing(const char *str) {
    puts(str);
}

void test(hlhandler handler) {
//    assert(sum(1, 3) == 4);
    FILE *filePtr = fopen(URL, "wr");
    assert(N_EQ(proceed_hyperlinks(filePtr, URL, handler), 0));
}

void passing_function(hlhandler hlhandler1) {
    hlhandler1("hello world");
}

int main(int argc, char** argv) {
    test(nothing);

//    void (*fun_ptr)(const char*) = &nothing;
//    char ch;
//    // Printing what is written in file
//    // character by character using loop.
//    printf("content from file:");
//    do {
//        ch = fgetc(filePtr);
//        printf("%c", ch);
//
//        // Checking if character is not EOF.
//        // If it is EOF stop reading.
//    } while (ch != EOF);
//    char *greeting = "hello";
//    printf("Res#2: %s\n", c_oncat(greeting, (size_t) SIZE));
//    char *newDest = static_cast<char *>(malloc(SIZE));
//    memcpy(newDest, greeting, SIZE);
//    newDest[SIZE] = 'a';
//    newDest[SIZE+1] = '\0';
//    printf("Res#3: %s\n", newDest);
}
