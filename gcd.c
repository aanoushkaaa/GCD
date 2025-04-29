#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int gcd(int a, int b) {
    if (b == 0) { 
        printf("Error: GCD is undefined for b = 0.\n");
        return -1; 	
    }
    if (a < 0 || b < 0) { 
        printf("Error: GCD is undefined for negative numbers.\n");
        return -1; 
    }
    while (b != 0) {     
        int temp = b;   
        b = a % b;      
        a = temp;       
    }
    return a;         
}
int main() {
    int a = 150000, b = 2;
    clock_t start = clock();
    int result = gcd(a, b);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    size_t memory_used = sizeof(a) + sizeof(b) + sizeof(result) + sizeof(start) + sizeof(end) + sizeof(time_taken);
    if (result != -1) {
        printf("GCD of %d and %d is %d\n", a, b, result);
    }
    printf("Execution time: %.6f seconds\n", time_taken);
    printf("Estimated memory usage: %zu bytes\n", memory_used);

    return 0;
}
