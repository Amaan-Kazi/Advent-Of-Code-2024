#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main () {
    int safeReports = 0;
    ifstream fin("inputs.txt");
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        vector<int> inputs;
        int num;

        bool asc = false, desc = false;

        while (ss >> num) {
            inputs.push_back(num);
        }

        for (int i = 1; i < inputs.size(); i++) {
            int diff = abs(inputs[i] - inputs[i-1]);

            if (diff < 1 || diff > 3) {
                safeReports--;
                break;
            }

            if (inputs[i]< inputs[i-1])
                desc = true;
            else
                asc = true;

            if (asc && desc) {
                safeReports--;
                break;
            }
        }

        safeReports++;
    }

    cout << "Safe Reports: " << safeReports << endl;
}
