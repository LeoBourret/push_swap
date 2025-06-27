# 🧮 Push_Swap: Optimal Sorting with Minimal Operations

![Language: C](https://img.shields.io/badge/Language-C-blue.svg)
![Build: Makefile](https://img.shields.io/badge/Build-Makefile-green.svg)
![School: 42 Paris](https://img.shields.io/badge/School-42_Paris-orange.svg)
![Grade: 107/100](https://img.shields.io/badge/Grade-107/100-brightgreen.svg)

## ✨ Overview

`Push_Swap` is a highly challenging algorithmic project from 42 Paris. The core task is to **sort a stack of integers using the smallest possible number of predefined operations**, by manipulating two stacks (stack `a` and stack `b`). This project rigorously tests problem-solving skills, algorithmic design, and optimization capabilities in C.

It requires developing a custom sorting algorithm that outputs a sequence of operations (e.g., `sa`, `pb`, `ra`) to efficiently sort stack `a` while adhering to strict performance constraints. Alongside, a `checker` program validates the generated instructions.

## 🌟 Key Features & Implementation Details

This project involves the implementation of two distinct programs:

### **1. `push_swap` Program**

*   **Optimal Sorting Algorithm:** Implemented a custom sorting algorithm to sort a given list of integers in ascending order into stack `a`. The primary objective was to find the **minimum (or near-minimum) number of operations** to achieve the sorted state.
*   **Restricted Operations:** Utilizes a specific set of allowed operations:
    *   **Swap:** `sa` (swap a), `sb` (swap b), `ss` (sa and sb).
    *   **Push:** `pa` (push a), `pb` (push b).
    *   **Rotate:** `ra` (rotate a), `rb` (rotate b), `rr` (ra and rb).
    *   **Reverse Rotate:** `rra` (reverse rotate a), `rrb` (reverse rotate b), `rrr` (rra and rrb).
*   **Output:** Prints the generated sequence of operations to standard output, each separated by a newline.
*   **Error Handling:** Robustly handles invalid inputs (non-integers, duplicates, numbers outside int range) by displaying an "Error" message.

### **2. `checker` Program**

*   **Instruction Validator:** Takes a list of integers as arguments and then reads operations from standard input.
*   **Execution & Validation:** Executes the received operations on the stacks and verifies if stack `a` is sorted and stack `b` is empty.
*   **Output:** Displays "OK" if sorted, "KO" otherwise, and "Error" for invalid inputs or instructions.

### **3. Extended Functionality (Bonus Part - Achieved)**

*   **File I/O for Instructions:** The `checker` program was extended to **read instructions from a specified input file** and the `push_swap` program was adapted to **write its generated instructions to an output file**.

## 🛠️ Technologies Used

*   **Language:** C
*   **Build System:** Makefile
*   **Data Structures:** Custom stack implementation, likely using linked lists or dynamic arrays.
*   **Algorithms:** Custom sorting algorithms (e.g., variations of Insertion Sort, Quick Sort tailored for two stacks, or specific strategies for small/large number sets).
*   **Memory Management:** Explicit `malloc` and `free` for dynamic allocations.

## 🚀 How to Use

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/yourusername/push_swap.git
    cd push_swap
    ```
2.  **Compile the programs:**
    ```bash
    make
    # This will generate both 'push_swap' and 'checker' executables.
    ```
3.  **Run `push_swap` (to generate instructions):**
    ```bash
    ./push_swap 2 1 3 6 5 8
    # Output will be a sequence of operations like:
    # sa
    # pb
    # ...
    ```
4.  **Run `checker` (to validate instructions):**
    *   **Via pipe (standard usage):**
        ```bash
        ./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
        # Expected output: OK (if correctly sorted) or KO
        ```
    *   **Via file (bonus usage):**
        ```bash
        # Generate instructions to a file
        ./push_swap 2 1 3 6 5 8 > instructions.txt
        # Check instructions from the file
        ./checker 2 1 3 6 5 8 < instructions.txt
        # Expected output: OK or KO
        ```

## 🎓 Learning Outcomes

This project was pivotal in deepening my understanding of:

*   **Algorithmic Design & Optimization:** Developing and optimizing complex sorting algorithms under specific constraints.
*   **Data Structures:** Efficient manipulation of stack-based data structures.
*   **Problem-Solving:** Breaking down a complex problem into manageable sub-problems and devising creative solutions.
*   **Efficiency & Complexity Analysis:** Understanding the trade-offs in different algorithmic approaches to minimize operations.
*   **C Programming:** Reinforcing skills in C, memory management, and robust error handling.
*   **Inter-process Communication (via pipes):** Understanding how two programs can interact.
