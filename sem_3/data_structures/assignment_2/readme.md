### Statement

_**Date:** 2 Sept, 2024_

Implement the following in C and submit a doc file with all the c programs in one file to classroom .

**1.1.** Write a program that generates n integer random numbers between a given range low to high.
**Input:** low l, high h, number of random numbers to be generated n
**Output:** n integer random numbers.

> Ans: random.c

**1.2.** Given n as input, write a program to print the nth Fibonacci Number, both recursively and iteratively.
**Output:** In recursive implementation, count and print the number of recursive calls as follows: Let fib(0) = 0 and fib(1) = 1

**Example:** fib(4)
\# of times fib(0) is called : 2
\# of times fib(1) is called : 3
\# of times fib(2) is called : 2
\# of times fib(3) is called : 1
\# of times fib(0) is called : 4
Total # of recursive calls: 12

> Ans: fib.c

**1.3.** Use the random number generation function (1.1) to generate different fibonacci number within a range. Report the time taken (use time command in linux) for iterative and recursive implementation atleast for 10 randomly generated inputs.

> Ans: random_fib_iter.c, random_fib_rec.c

**Challenge:** Write a program to print the recursion tree of fibonacci computation.

> Ans: recursion_tree.c
