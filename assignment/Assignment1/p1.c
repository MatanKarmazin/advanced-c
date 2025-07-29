#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct number {
    unsigned long long num;
    int sum;
} Number;

// Function prototypes
Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int isPrime(int);
int digitSum(unsigned long long);
void printArray(Number*, int);

int main() {
    int size;
    unsigned long long n1, n2;
    printf("Enter two numbers: ");
    scanf("%llu %llu", &n1, &n2);
    Number* result = primeSums(n1, n2, &size);
    printArray(result, size);
    printf("\nsize: %d\n", size);
    free(result);
    return 0;
}

// Function to find numbers in the range [n1, n2] with prime digit sums
Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size) {
    // Check for valid range
    if (n1 >= n2) {
        *p_size = 0;
        return NULL;
    }
    // Initial size of the result array
    *p_size = 2;  // Default size to work with
    Number* arr = (Number*)malloc(*p_size * sizeof(Number));
    assert(arr); 
    unsigned long long i;
    int sum, count = 0;
    // Iterate through the range [n1, n2]
    for (i = n1; i <= n2; i++) {
        if (count == *p_size) {
            *p_size *= 2;
            arr = (Number*)realloc(arr, *p_size * sizeof(Number));
            assert(arr);   // Check if memory reallocation is successful
        }
        sum = digitSum(i);
        // Check if the sum is prime
        if (isPrime(sum)) {
            arr[count].num = i;
            arr[count].sum = sum;
            count++;
        }
    }
    // If no valid numbers are found, free the memory and return NULL
    if (count == 0) {
        free(arr);
        arr = NULL;
    }
    // Update the size of the array and return it
    *p_size = count;
    return arr;
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;    
    if (num == 2) return 1;    
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to calculate the sum of digits of a number
int digitSum(unsigned long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void printArray(Number* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Number: %llu, Digit Sum: %d\n", arr[i].num, arr[i].sum);
    }
}
