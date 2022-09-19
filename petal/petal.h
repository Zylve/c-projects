#ifndef PETAL_PETAL_H
#define PETAL_PETAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShowHelp(int argc, char* argv[]) {
    if(argc == 1 || !strcmp(argv[1], "help") || !strcmp(argv[1], "-h") ||
       !strcmp(argv[1], "--help")) {

        printf("Usage: %s <number> [mode]\n\n", argv[0]);
        printf(
            "<number> - Input an odd number, if the number is even then 1 will be added to it\n\n");
        printf("[mode] - Dictates which number will be used as the center of the flower, defaults "
               "to n\n");
        printf("1 - 1 will be used as the center\n");
        printf("n - <number> will be used as the center\n");
        printf("m - [ (<number> / 2) + 0.5 ] will be used as the center\n\n");

        exit(0);
    }
}

inline void CheckMode(int argc, char* argv[], char* out) {
    if(argc == 2) {
        *out = 'n';
        return;
    }

    if(!strcmp(argv[2], "1")) {
        *out = '1';
        return;
    }

    if(!strcmp(argv[2], "m")) {
        *out = 'm';
        return;
    }

    if(!strcmp(argv[2], "n")) {
        *out = 'n';
        return;
    }
}

inline void CheckPetals(int* number) {
    if(*number <= 1) {
        printf("Please input a number or a number that is greater than 1\n");

        exit(0);
    }

    if(!(*number % 2)) { *number = *number + 1; }
}

inline void PopulateArray(int* array, int petals, char* mode, int* center) {
    if(!strcmp(mode, "1")) {
        *center = 1;
        for(int i = 0; i < petals; i++) {
            array[i] = i + 2;
        }

        return;
    }

    if(!strcmp(mode, "m")) {
        *center = (petals / 2) + 1;
        for(int i = 0; i < petals / 2; i++) {
            array[i] = i + 1;
        }

        for(int i = petals / 2; i < petals; i++) {
            array[i] = i + 2;
        }

        return;
    }

    if(!strcmp(mode, "n")) {
        *center = petals + 1;

        for(int i = 0; i < petals; i++) {
            array[i] = i + 1;
        }
    }
}
#endif