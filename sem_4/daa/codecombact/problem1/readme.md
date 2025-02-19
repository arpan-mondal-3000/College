### Problem 1

You've just infiltrated the top-secret Matrix Command Center of the digital overlords.
But wait! They've locked up all their binary data in a fancy grid system. Your task is to maximize the Score of this matrix.

**How, you ask?** Each row of the matrix represents a binary number. The matrix's score is the sum of these numbers(decimal value of binary representation represented in a row). Your mission is to toggle (flip) rows and columns, maximizing the sum of these binary numbers.

**How do you toggle?** Toggling a row: flip every element in that row (i.e., change all 0's to 1's and all 1's to 0's). Toggling a column: flip every element in that column.

You can perform any number of toggles (including zero). The question is: What is the highest possible score you can achieve after toggling any rows and columns?

#### Input Format

The first line **t** contains no of test cases.
The next line contains two values **m** and **n** separated by space representing no. of rows and columns respectively.
The next **m** lines each contain, **n** numbers separated by space representing value of each cell in the matrix
This will represent the m x n matrix.

**Constraints**
1<=**m**, **n**<=20

Each cell in matrix has either 0 or 1 value.

#### Output Format

Return **t** lines each containing the maximum decimal value sum obtained by toggling the matrix.

#### Sample lnput 0:

```
1
3 4
0 0 1 1
1 0 1 0
1 1 0 0
```

#### Sample Output 0

```
39
```

#### Explanation 0

```
Ob1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
```
