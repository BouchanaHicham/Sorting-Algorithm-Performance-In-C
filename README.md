# Sorting Algorithm Performance

This C program compares the performance of three sorting algorithms: selection sort, quicksort, and merge sort. It generates random arrays of integers for different sizes and measures the execution time of each sort. The goal is to analyze and compare the efficiency of these algorithms.

## Algorithms Implemented

1. Selection Sort
2. Quick Sort
3. Merge Sort

## How to Run

1. Make sure you have a C compiler installed (e.g., GCC).
2. Clone the repository or download the source code.
3. Navigate to the project directory in the terminal.
4. Compile the program: `gcc -o main main.c`
5. Run the program: `./main` On Linux/Mac or `maine.exe` on Windows

## Execution
### Array Sizes
The program tests the sorting algorithms on the following array sizes:

*100, 500, 1000, 3000, 5000, 7000, 10000, 20000, 30000, 50000, 100000*
### Output

The program displays the execution time for each sorting algorithm for each array size.
```
 Array_Size | Selection_Sort | Quick_Sort | Merge_Sort
-------------------------------------------------------
 100        | [0.000000]     | [0.000000] | [0.000000]
 500        | [0.000000]     | [0.000000] | [0.000000]
 1000       | [0.001000]     | [0.000000] | [0.000000]
 3000       | [0.009000]     | [0.000000] | [0.002000]
 5000       | [0.026000]     | [0.001000] | [0.000000]
 7000       | [0.052000]     | [0.001000] | [0.000000]
 10000      | [0.104000]     | [0.002000] | [0.001000]
 20000      | [0.437000]     | [0.006000] | [0.002000]
 30000      | [0.940000]     | [0.011000] | [0.004000]
 50000      | [2.588000]     | [0.029000] | [0.006000]
 100000     | [10.328000]    | [0.107000] | [0.013000]
 ```

## License

This project is licensed under the MIT License. You can find the full text of the license in the [LICENSE](LICENSE) file.

## Contributions

Contributions to this project are more than welcome. If you have any suggestions, bug fixes, or new features to add, please feel free to fork the repository and submit a pull request. We value your feedback and contributions!

## Author

**Bouchana Hicham**
