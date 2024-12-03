### Problem Statement
[https://adventofcode.com/2024/day/2](https://adventofcode.com/2024/day/3#part2)\
String is provided containing mul(num1,num2), do(), don't() instructions\
do() enables mul instruction and don't() disables it\
mul instructions that are not corrupted (should match syntax exactly [no spaces]) should perform the multiplication then add to a total sum

### My Solution
A loop reads one char at a time\
char is added to the 2 double ended queues of sizes 4 and 7 and first char is removed\
if queue matches do() then enable instruction\
if queue matches don't() then disable instruction\
add char to instruction if it is continuing to follow the syntax\
the previous character must be as the syntax defines, else clear the instruction\
When ')' is encountered, extract the 2 numbers, multiply them and add to total sum only if instruction is enabled
