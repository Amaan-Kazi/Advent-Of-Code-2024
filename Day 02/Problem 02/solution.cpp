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
        bool dampened = false;

        while (ss >> num) {
            inputs.push_back(num);
        }

        for (int i = 1; i < inputs.size(); i++) {
            int diff = abs(inputs[i] - inputs[i-1]);

            if (diff < 1 || diff > 3) {
                safeReports--;
                dampened = true;
                break;
            }

            if (inputs[i]< inputs[i-1])
                desc = true;
            else
                asc = true;

            if (asc && desc) {
                safeReports--;
                dampened = true;
                break;
            }
        }

        safeReports++;

        if (dampened) {
            bool unsafe = true;
            int removedElement = -1;
            int size = inputs.size();

            while (unsafe && (size > removedElement)) {
                asc = false;
                desc = false;

                unsafe = false;
                removedElement++;

                vector<int> arr = inputs;
                arr.erase(arr.begin() + removedElement);

                for (int k = 1; k < arr.size(); k++) {
                    int diff = abs(arr[k] - arr[k-1]);

                    if (diff < 1 || diff > 3) {
                        unsafe = true;
                        break;
                    }

                    if (arr[k] < arr[k-1])
                        desc = true;
                    else
                        asc = true;

                    if (asc && desc) {
                        unsafe = true;
                        break;
                    }
                }

                if (!unsafe) {
                    safeReports++;
                    break;
                }
            }
        }
    }

    cout << "Safe Reports: " << safeReports << endl;
}
