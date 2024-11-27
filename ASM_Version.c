#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void saxpy(float* X, float* Y, float* Z, int n, float A);

int main() {
    float X[3] = {1.0, 2.0, 3.0};
    float Y[3] = {11.0, 12.0, 13.0};
    float Z[3] = {0.0, 0.0, 0.0};
    float A = 2.0;
    int n = 3; // 2^20 = 1048576 | 2^24 = 16777216 | 2^30 = 1073741824 (Test Cases)
    int i = 0;
    int s = 0;

    // Measure time
    clock_t start = clock();
    saxpy(X, Y, Z, n, A); // Call the assembly function
    clock_t end = clock();
    
    // Calculate and print time taken
    float time_taken = (float)(end - start) / CLOCKS_PER_SEC;
    //    printf("%f\n", time_taken);
    printf("Time taken for n = %d: %f seconds\n", n, time_taken);

    // Print the first 10 elements of Z
    printf("Result (Z): ");
    for (i = 0; i < 10; i++) {
        printf("%.2f ", Z[i]);
    }
    printf("\n");
    
    return 0;
}
