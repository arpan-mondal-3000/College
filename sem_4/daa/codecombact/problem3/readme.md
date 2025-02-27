### Problem 3

Deep within the Ruins of Numeria, archaeologists have uncovered an ancient scroll written in a forgotten numeric script.
The legend says that whoever deciphers the scroll shall unlock infinite wisdom.. or be
cursed for eternity!
But there's a problem...The scroll contains a series of mysterious numbers, and scholars believe they follow a secret mapping:

"1" - 'A', "2" - 'B',..., "26" - 'Z' However, the numbers can be decoded in multiple ways, and some sequences may be impossible to read.
Your mission, brave scholar, is to determine the number of ways to interpret the scroll...before the curse consumes you!

#### Input Format

The first line **t** contains no. of test cases
Each test cases has only 1 line which contains the encoded string.

#### Constraints

1<=(length of encoded strings)<=100
Encoded string can begin with leading 0

#### Output Format

Return **t** lines of output each containing no of ways to decode the encoded string

#### Sample Input 0

```
3
12
226
06
```

#### Sample Output 0

```
2
3
0
```

#### Explanation 0

**Example 1:**
"12" could be decoded as "AB" (1 2) or "L" (12).
**Example 2:**
"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
**Example 3:**
"06" cannot be mapped to "F" because of the leading zero ("6" is different fromn "06"). In this case, the string is not a valid encoding, so return 0.
