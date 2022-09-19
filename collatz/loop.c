#include <stdlib.h>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>
#define xlong unsigned long long int

xlong max1[] = { 0, 0 };
xlong max2[] = { 0, 0 };
xlong max3[] = { 0, 0 };
xlong max4[] = { 0, 0 };
xlong max5[] = { 0, 0 };
xlong max6[] = { 0, 0 };
xlong max7[] = { 0, 0 };

xlong* max[7] = { max1, max2, max3, max4, max5, max6, max7 };

xlong iter;

int n = 0;

struct data {
    int start;
    xlong arr[];
};

void* Calculate(void* start) {
    struct data* data = start;

    for(xlong i = data->start; i <= iter; i += 7) {
        xlong n = i;
        xlong j = 0;

        while(n != 1) {
            if(n % 2 == 0) {
                n /= 2;
            } else {
                n *= 3;
                n += 1;
            }

            j++;
        }

        if(j > data->arr[1]) {
            data->arr[0] = i;
            data->arr[1] = j;
        }
    }

    n++;
    return NULL;
}

int main(int argc, char* argv[]) {
    sscanf(argv[1], "%d", &iter);

    initscr();
    curs_set(0);

    pthread_t thread;

    for(int i = 0; i < 7; i++) {
        struct data* data = malloc(sizeof(struct data));
        data->start = i + 1;
        // data->arr = max[i];

        pthread_create(&thread, NULL, Calculate, data);
    }

    // pthread_exit(NULL);
    return 0;
}