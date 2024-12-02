### Problem Statement
[https://adventofcode.com/2024/day/2](https://adventofcode.com/2024/day/2)\
Multidimensional list is provided\
In each sublist all elements must either be ascending or descending\
The difference between elements of the sublist must be 1, 2 or 3\
Count the number of sublists that follow all rules

### My Solution
Inputs are taken from file and stored in a multidimensional vector\
Nested loop that goes over each element of each sublist\
if difference in previous element and current is not 1, 2 or 3 then sublist doesnt follow the rules\
store whether the previous element is lesser or greater\
if both lesser and greater (including previous comparisions) then sublist doesnt follow the rules\
else add to the count of sublist that follows the rules