### Problem Statement
[https://adventofcode.com/2024/day/1#part2](https://adventofcode.com/2024/day/1#part2)\
2 Lists are provided -> Sorted in the previous Problem\
Each element in first list has to be checked\
count the number of times it appeared in the second list\
Total Similarity = element in list 1 * count of occurence in list 2

### My Solution
Inputs are taken from file and stored in 2 arrays then sorted [in previous problem]\
A loop that runs until either indexes of the arrays reaches the end\
if element in first array is lesser than second, then increment index 1\
if element in first array is greater than second, then increment index 2\
else they are equal so create a new loop to count the number of occurences in first array\
and then a loop to count the number of occurences in second array\
Total Similarity += occurences in array 1 * (value * occurences in array 2)
