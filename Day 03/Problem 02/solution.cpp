#include <iostream>
#include <fstream>
#include <cctype>
#include <deque>
using namespace std;

int main () {
    ifstream file("inputs.txt");
    string instruction;
    char ch;
    bool secondNum = false, doInstruction = true;
    unsigned long long sum = 0;
    int commas = 0;
    deque<char> buffer1;
    deque<char> buffer2;

    while(file.get(ch)) {
        buffer1.push_back(ch);
        buffer2.push_back(ch);

        if (buffer1.size() > 4)
            buffer1.pop_front();

        if (buffer2.size() > 7)
            buffer2.pop_front();

        string currentBuffer1(buffer1.begin(), buffer1.end());
        string currentBuffer2(buffer2.begin(), buffer2.end());

        if (currentBuffer1 == "do()")
            doInstruction = true;

        if (currentBuffer2 == "don't()")
            doInstruction = false;

        if (instruction.empty()) {
            if (ch == 'm')
                instruction.push_back('m');
        }
        else {
            if      (instruction.back() == 'm' && ch == 'u')    instruction.push_back('u');
            else if (instruction.back() == 'u' && ch == 'l')    instruction.push_back('l');
            else if (instruction.back() == 'l' && ch == '(')    instruction.push_back('(');
            else if (instruction.back() == '(' && isdigit(ch))  instruction.push_back(ch);
            else if (isdigit(instruction.back()) && isdigit(ch))instruction.push_back(ch);
            else if (isdigit(instruction.back()) && ch == ',' && commas == 0) {
                commas++;
                instruction.push_back(',');
                secondNum = true;
            }
            else if (instruction.back() == ',' && isdigit(ch))  instruction.push_back(ch);
            else if (isdigit(instruction.back()) && ch == ')' && secondNum) {
                instruction.push_back(')');

                int n1 = 0, n2 = 0;
                bool secNum = false;

                for (int i = 4; i < instruction.length() - 1; i++) {
                    if (instruction[i] == ',')
                        secNum = true;
                    else if (!secNum)
                        n1 = (n1 * 10) + (instruction[i] - '0');
                    else
                        n2 = (n2 * 10) + (instruction[i] - '0');
                }

                if (doInstruction) {
                    cout << instruction << " [ " << n1 << " * " << n2 << " = " << n1 * n2 << " ] " << endl;
                    sum += n1 * n2;
                }

                secondNum = false;
                commas = 0;
                instruction.clear();
            }
            else {
                secondNum = false;
                commas = 0;
                instruction.clear();
            }
        }
    }

    cout << endl << sum << endl;
    return 0;
}
