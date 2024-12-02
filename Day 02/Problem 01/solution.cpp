#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main () {
    int safeReports = 0;
    vector<vector<int>> inputs;
    ifstream fin("inputs.txt");

    string line;
    int lineCount = 0;
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<int> row;
        int num;

        while (ss >> num) {
            row.push_back(num);
        }
        inputs.push_back(row);
    }


    for (int i = 0; i < inputs.size(); i++) {
        bool asc = false, desc = false;

        for (int j = 1; j < inputs[i].size(); j++) {
            int diff = abs(inputs[i][j] - inputs[i][j-1]);

            if (diff < 1 || diff > 3) {
                safeReports--;
                break;
            }

            if (inputs[i][j] < inputs[i][j-1])
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
