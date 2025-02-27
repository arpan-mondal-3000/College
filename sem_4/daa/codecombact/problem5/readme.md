### Problem 5

Sherlock Holmes is once again on the trail of Professor X, who has left behind a string of numbers. Hidden within this string are secret fornmulas created by inserting mathematical operators (+, , \*) between the digits or group of digits. However, Professor X is tricky only certain formulas evaluate to the target number!

**Your mission? Count how many valid ways exist to form an expression that equals the target.**

**But beware! There are rules:**

1. No leading zeros (e.g., "05" is illegal!).
2. Digits must be used in order (no rearranging!).
3. 0nly +, , and \* are allowed. No division!
4. Can you crack the professor's code before time runs out?

#### Input Format

The first line contains a single integer n (1 sns 1000), the number of test cases.
The next **n** lines each contain:
A string of the mystery number and target number separated by space.

#### Constraints

1<=len(mystery string)<=10
Each string consists of digits from 0-9
(-2^31 <= target <= 2^31 - 1).

#### Output Format

Return **n** lines each line containing no of ways to decode the string to form the target

#### Sample Input 0

```
1
123 6
```

#### Sample Output 0

```
2
```

#### Explanation 0

"1\*2\*3" and "1+2+3" Both evaluate to 6
