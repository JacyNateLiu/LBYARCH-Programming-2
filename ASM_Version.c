#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the saxpy function as implemented in assembly
extern void saxpy(int n, float A, float *X, float *Y, float *Z);

int main() {
    float A = 2.0f;
    int n = 10; // 2^20 = 1048576 | 2^24 = 16777216 | 2^30 = 1073741824 (Test Cases)
    int i = 0;

    // Dynamically allocate memory for arrays
    float *X = (float *)malloc(n * sizeof(float));
    float *Y = (float *)malloc(n * sizeof(float));
    float *Z = (float *)malloc(n * sizeof(float));

    if (X == NULL || Y == NULL || Z == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    
    // Seed the random number generator
    srand(time(NULL));

    // Initialize arrays with random float numbers
    for (i = 0; i < n; i++) {
        X[i] = (float)rand();
        Y[i] = (float)rand();
    }

    // Measure time
    clock_t start = clock();
    saxpy(n, A, X, Y, Z); // Call the assembly implementation
    clock_t end = clock();

    // Calculate and print time taken
    float time_taken = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for n = %d: %f seconds\n", n, time_taken);

    // Print the first 10 elements of Z
    printf("Result (Z): ");
    for (i = 0; i < 10; i++) {
        printf("%.2f ", Z[i]);
    }
    printf("\n");

    // Free allocated memory
    free(X);
    free(Y);
    free(Z);

    return 0;
}
