### Problem Statement
[https://adventofcode.com/2024/day/2](https://adventofcode.com/2024/day/2)\
Multidimensional list is provided\
In each sublist all elements must either be ascending or descending\
The difference between elements of the sublist must be 1, 2 or 3\
Each sublist is given one extra chance to follow all rules by removing any one element\
Count the number of sublists that follow all rules

### My Solution
Inputs are taken from file and stored in a vector\
Loop goes over each element of the sublist\
if difference in previous element and current is not 1, 2 or 3 then sublist doesnt follow the rules\
store whether the previous element is lesser or greater\
if both lesser and greater (including previous comparisions) then sublist doesnt follow the rules\
else add to the count of sublist that follows the rules\
if the sublist didnt follow all rules, try loop removing one element at a time in order and seeing if the sublist now follows all rules
