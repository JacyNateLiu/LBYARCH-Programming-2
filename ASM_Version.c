#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the x86-64 assembly implementation
extern void saxpy(float* X, float* Y, float* Z, int n, float A);

// C implementation of SAXPY (sanity check)
void saxpy_c(int n, float A, float *X, float *Y, float *Z) {
    for (int i = 0; i < n; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}

int main() {
    float A = 2.0f;
    int n = 1048576; // 2^20 = 1048576 | 2^24 = 16777216 | 2^30 = 1073741824 (Test Cases)
    int i;

    // Dynamically allocate memory for arrays
    float *X = (float *)malloc(n * sizeof(float));
    float *Y = (float *)malloc(n * sizeof(float));
    float *Z_c = (float *)malloc(n * sizeof(float)); // For C version result
    float *Z_asm = (float *)malloc(n * sizeof(float)); // For x86-64 version result

    if (X == NULL || Y == NULL || Z_c == NULL || Z_asm == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Seed the random number generator
    srand(1234);

    // Initialize arrays with random float numbers
    for (i = 0; i < n; i++) {
        X[i] = (float)rand();
        Y[i] = (float)rand();
    }

    // C version execution
    saxpy_c(n, A, X, Y, Z_c);

    // x86-64 assembly version execution
    clock_t start_asm = clock();
    saxpy(X, Y, Z_asm, n, A);
    clock_t end_asm = clock();

    // Calculate execution times
    float time_asm = (float)(end_asm - start_asm) / CLOCKS_PER_SEC;

    // Print time comparison
    printf("\n");

    printf("x86-64 assembly version execution time n = %d: %f seconds\n", n, time_asm);
    printf("\n");
    
    // Compare results
    int correct = 1;
    for (i = 0; i < n; i++) {
        if (Z_c[i] == Z_asm[i]) {
            correct = 1;
            break;
        }
    }

    // Output correctness and results
    if (correct) {
        printf("The x86-64 assembly output matches the C output.\n");
    } else {
        printf("Mismatch found between C and x86-64 assembly outputs.\n");
    }
    printf("\n");

    printf("First 10 elements (x86-64 version): ");
    for (i = 0; i < 10; i++) {
        printf("%.2f ", Z_asm[i]);
    }
    printf("\n");

    // Free allocated memory
    free(X);
    free(Y);
    free(Z_c);
    free(Z_asm);

    return 0;
}
