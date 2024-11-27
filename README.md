# LBYARCH-Programming-2
Jacy Liu &amp; Ponj Elazegui

# Execution Times (in seconds)

## Test Cases: n = 2<sup>20</sup>, 2<sup>24</sup>, 2<sup>30</sup>


| Iteration | C Program (n = 2<sup>20</sup>) | C Program (n = 2<sup>24</sup>) | C Program (n = 2<sup>30</sup>) | x86-64 (n = 2<sup>20</sup>) | x86-64 (n = 2<sup>24</sup>) | x86-64 (n = 2<sup>30</sup>) |
|-----------|---------------------|---------------------|---------------------|------------------|------------------|------------------|
| 1         | 0.002              | 0.035              | 30.830             | 0.002           | 0.015           | 6.198           |
| 2         | 0.002              | 0.027              | 52.513             | 0.001           | 0.019           | 32.246          |
| 3         | 0.002              | 0.028              | 24.010             | 0.000           | 0.022           | 9.947           |
| 4         | 0.003              | 0.027              | 21.381             | 0.000           | 0.013           | 1.625           |
| 5         | 0.003              | 0.027              | 2.515              | 0.001           | 0.014           | 0.963           |
| 6         | 0.002              | 0.028              | 1.708              | 0.001           | 0.015           | 1.037           |
| 7         | 0.003              | 0.026              | 1.712              | 0.001           | 0.013           | 1.137           |
| 8         | 0.002              | 0.028              | 1.706              | 0.001           | 0.016           | 0.943           |
| 9         | 0.002              | 0.027              | 1.702              | 0.001           | 0.014           | 0.949           |
| 10        | 0.003              | 0.027              | 1.711              | 0.001           | 0.017           | 0.988           |
| 11        | 0.002              | 0.033              | 1.713              | 0.000           | 0.013           | 1.094           |
| 12        | 0.004              | 0.028              | 1.722              | 0.000           | 0.016           | 1.060           |
| 13        | 0.003              | 0.027              | 1.701              | 0.001           | 0.015           | 0.986           |
| 14        | 0.002              | 0.027              | 1.707              | 0.001           | 0.016           | 0.928           |
| 15        | 0.001              | 0.027              | 1.712              | 0.001           | 0.016           | 0.932           |
| 16        | 0.003              | 0.026              | 1.704              | 0.001           | 0.015           | 0.957           |
| 17        | 0.002              | 0.028              | 1.705              | 0.001           | 0.015           | 0.926           |
| 18        | 0.002              | 0.026              | 1.708              | 0.001           | 0.019           | 1.022           |
| 19        | 0.002              | 0.027              | 1.704              | 0.000           | 0.019           | 0.925           |
| 20        | 0.001              | 0.027              | 1.708              | 0.001           | 0.019           | 0.944           |
| 21        | 0.002              | 0.027              | 1.707              | 0.001           | 0.016           | 0.965           |
| 22        | 0.002              | 0.027              | 1.707              | 0.001           | 0.018           | 1.009           |
| 23        | 0.002              | 0.027              | 1.702              | 0.001           | 0.018           | 1.103           |
| 24        | 0.002              | 0.032              | 3.694              | 0.001           | 0.017           | 1.061           |
| 25        | 0.002              | 0.028              | 3.254              | 0.001           | 0.014           | 0.965           |
| 26        | 0.001              | 0.026              | 1.712              | 0.001           | 0.013           | 0.958           |
| 27        | 0.002              | 0.029              | 1.704              | 0.001           | 0.015           | 3.188           |
| 28        | 0.002              | 0.027              | 1.705              | 0.002           | 0.014           | 26.221          |
| 29        | 0.002              | 0.028              | 1.707              | 0.002           | 0.014           | 39.357          |
| 30        | 0.002              | 0.026              | 1.702              | 0.001           | 0.012           | 49.667          |

**Average Execution Times (in seconds):**

| Metric            |  C Program (n = 2<sup>20</sup>) | C Program (n = 2<sup>24</sup>) | C Program (n = 2<sup>30</sup>) | x86-64 (n = 2<sup>20</sup>) | x86-64 (n = 2<sup>24</sup>) | x86-64 (n = 2<sup>30</sup>) |
|--------------------|---------------------|---------------------|---------------------|------------------|------------------|------------------|
| Average           | 0.00217            | 0.0276             | 5.92               | 0.0010333       | 0.0157           | 6.3434           |

---
## Screenshot of the program output with the correctness check (C)
![Image Alt](/Screenshots/cCorrectnessCheck.png)

## Screenshot of the program output, including the correctness check (x86-64)
![Image Alt](/Screenshots/x86-64CorrectnessCheck.png)

## Analysis

In the 3 test cases with n having values of 2<sup>20</sup>, 2<sup>24</sup>, 2<sup>30</sup>, it is seen in the table above that execution times for both programs were faster for smaller array sizes and slower for larger sizes. For the C program, it is observed in the table that the first few iterations out of 30 of the tests are often slower than the rest of the iterations. This is also observed in the x86-64 program. As seen in the screenshots above, the elements displayed in both the C and x86-64 assembly versions of the program are the same because we used a seed to generate consistent random numbers throughout the different tests. Moreover, the x86-64 assembly version generally has a faster execution time than the C version.

## Screenshots

### C Program Outputs (Last 4 out of 30)
**N = 1,048,576**  
![Image Alt](/Screenshots/C1048576.png)

**N = 16,777,216**  
![Image Alt](/Screenshots/C16777216.png)

**N = 1,073,741,824**  
![Image Alt](/Screenshots/C1073741824.png)

### x86-64 Assembly Outputs (Last 4 out of 30)
**N = 1,048,576**  
![Image Alt](/Screenshots/x86_641048576.png)

**N = 16,777,216**  
![Image Alt](/Screenshots/x86-6416777216.png)

**N = 1,073,741,824**  
![Image Alt](/Screenshots/x86_641073741824.png)

---

## Video

[Video Presentation Link](/Elazegui_Liu_Video.mp4)






