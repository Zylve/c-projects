#include "petal.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    ShowHelp(argc, argv);

    char mode;
    int number;
    int petals;
    int center;
    int* petalArray;
    int* fillArray;

    (void)sscanf(argv[1], "%d", &number);

    CheckPetals(&number);
    CheckMode(argc, argv, &mode);

    petals = number - 1;
    fillArray = (int*)malloc((unsigned long)petals * sizeof(int));
    petalArray = (int*)malloc((unsigned long)petals * sizeof(int));

    PopulateArray(fillArray, petals, &mode, &center);

    for(int i = 0; i < petals; i++) {
        printf("%d\n", fillArray[i]);
    }
}