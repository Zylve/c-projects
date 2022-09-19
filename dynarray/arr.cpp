#include "arr.hpp"

int main(void) {
    Array<int>* a = new Array<int>(); // Initialize new Array pointer.

    while(true) {
        char in[10];
        (void)scanf("%s", in); // Get user input.

        if(!strcmp(in, "exit")) { // Print array and exit.
            printf("\n");
            for(int i = 0; i < a->Size(); i++) {
                printf("%d\n", a->Get(i));
            }

            free(a);
            return 0;
        }

        if(!strcmp(in, "size")) { printf("Size: %d\n", a->Size()); } // Get array size.
        if(!strcmp(in, "in")) { // Insert element into array.
            int num;
            printf("Input your number:\n");
            (void)scanf("%d", &num);
            a->Push(num);
        }

        if(!strcmp(in, "get")) { // Get element at index.
            int index;
            printf("Input your index:\n");
            (void)scanf("%d", &index);
            printf("%d\n", a->Get(index));
        }
    }
}