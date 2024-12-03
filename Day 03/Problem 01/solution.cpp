#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main () {
    ifstream file("inputs.txt");
    string instruction;
    char ch;
    bool secondNum = false;
    unsigned long long sum = 0;
    int commas = 0;

    while(file.get(ch)) {
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

                cout << instruction << " [ " << n1 << " * " << n2 << " = " << n1 * n2 << " ] " << endl;
                sum += n1 * n2;

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
