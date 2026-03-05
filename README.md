# TKU211231 Algoritma dan Struktur Data - Assignment 03

## Student Information

- **Name:** Vania Carmia
- **Student ID (NIM):** 24/533643/TK/59126

## Description

- **Problem 1, 3B, and 4 (Written Analysis):** Contains the step-by-step mathematical analysis of algorithm complexities. This includes exact operation counting for nested loops, Big-O asymptotic simplification, amortized analysis of the dynamic array doubling strategy, and complexity comparison between linear and binary search. Submitted as a separate PDF.
- **Problem 2 (`problem2.cpp`):** A procedural implementation of a resizable dynamic array (`DynArray`) in C++. It manages heap memory manually using `new` and `delete` without relying on classes or `std::vector`. Features include `pushBack` with automatic resizing (doubling capacity), `insertAt` with right-to-left shifting, and `removeAt` with left-to-right shifting.
- **Problem 3 (`problem3.cpp`):** An implementation and empirical comparison of Linear Search and Binary Search algorithms. It tests both algorithms on dynamically generated sorted arrays of varying sizes ($n=10, 100, 1000$) for both existing and non-existing targets, ensuring index matching between the two methods.

## Compilation Commands

All code must be compiled with `g++ -std=c++17 -Wall -Wextra` as per the assignment instructions.

To compile and run `problem2.cpp`:

```bash
g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2
./problem2
```

To compile and run `problem3.cpp`:

```bash
g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3
./problem3
```

## Known Issues or Limitations

- Both `problem2.cpp` and `problem3.cpp` compile successfully without any warnings or memory leaks.
- **Limitation for Problem 3:** The `binarySearch` implementation requires the input array to be strictly sorted. Passing an unsorted array will result in undefined behavior.
- **Limitation for Problem 2:** The `insertAt` and `removeAt` functions assume that the provided index is always valid within the current array size bounds.

## Time Spent on the Assignment

- Approximately 10 hours.
