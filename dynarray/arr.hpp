#ifndef ARR_HPP
#define ARR_HPP

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

template <typename T> class Array {
private:
    int size;
    T* elements; // Declare a pointer to an array of elements.

public:
    T Get(const int index) { // Self explanatory.
        if(index >= this->Size()) {
            printf("Index out of bounds\n");
            exit(1);
        }

        return elements[index];
    }

    void Set(T in, const int index) { // Self explanatory.
        if(index >= this->Size()) {
            printf("Index out of bounds\n");
            exit(1);
        }

        elements[index] = in;
    }

    void Push(T in) {
        size++; // Increment the size by one.
        elements = (T*)realloc(elements, this->Size() * sizeof(T)); // Reallocate the memory for one extra element in the array.
        elements[this->Size() - 1] = in; // Set the last element to the new value, effectively appending it.
    }

    void Pop() {
        size--; // Decrement the size by one.
        elements = (T*)realloc(elements, this->Size() * sizeof(T)); // Reallocate the memory for one less element in the array.
    }

    int Size() { return this->size; }

    Array() : size(0) {
        this->elements = (T*)malloc(0); // Create a new array with a size of 0.
    }

    ~Array() {
        free(elements); // Manually delete elements to ensure no memory leaks occur.
    }
};

#endif