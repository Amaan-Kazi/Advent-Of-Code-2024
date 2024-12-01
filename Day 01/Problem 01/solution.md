### Problem Statement
[https://adventofcode.com/2024/day/1](https://adventofcode.com/2024/day/1)\
2 Lists are provided\
The smallest number from both lists has to be compared and the difference is to be taken\
Then the second smallest number from both lists has to be compared and the difference is to be taken and so on\
Then the Total Difference is the output

### My Solution
Inputs are taken from file and stored in 2 arrays\
Then both arrays are sorted\
Since number of elements is 1000, I have used Merge Sort due to the reliable O(n log n) Time Complexity for all cases\
Then finally both arrays are iterated over and the difference is added to the total difference
