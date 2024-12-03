### Problem Statement
[https://adventofcode.com/2024/day/2](https://adventofcode.com/2024/day/3)\
String is provided containing mul(num1,num2) instructions\
Instructions that are not corrupted (should match syntax exactly [no spaces]) should perform the multiplication then add to a total sum

### My Solution
A loop reads one char at a time\
add char to instruction if it is continuing to follow the syntax\
the previous character must be as the syntax defines, else clear the instruction\
When ')' is encountered, extract the 2 numbers, multiply them, then add to total sum
