#include <iostream>
#include <fstream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    
    // Temporary arrays
    int leftArr[size1], rightArr[size2];

    // Copy from real array to temporary arrays
    for (int i = 0; i < size1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < size2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Find smaller element among both arrays and move to real array
    int leftIndex = 0, rightIndex = 0, mainIndex = left;
    while ((leftIndex < size1) && (rightIndex < size2)) {
        if (leftArr[leftIndex] <= rightArr[rightIndex]) {
            arr[mainIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else {
            arr[mainIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mainIndex++;
    }

    // Copy any remaining elements from left or right array
    while (leftIndex < size1) {
        arr[mainIndex] = leftArr[leftIndex];
        mainIndex++;
        leftIndex++;
    }
    while (rightIndex < size2) {
        arr[mainIndex] = rightArr[rightIndex];
        mainIndex++;
        rightIndex++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Use Recursion to sort left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

int main () {
    int n = 0, difference = 0;
    int arr1[1000], arr2[1000];

    ifstream fin("inputs.txt");

    while (fin >> arr1[n] >> arr2[n]) {
        n++;
    }

    fin.close();

    mergeSort(arr1, 0, n - 1);
    mergeSort(arr2, 0, n - 1);

    int i = 0, j = 0, similarity = 0, prevSimilarity = 0;

    while ((i < n) && (j < n)) {
        if (arr1[i] < arr2[j]) {
            i++;  // Move forward in arr1 if lesser
        }
        else if (arr1[i] > arr2[j]) {
            j++;  // Move forward in arr2 if greater
        }
        else {
            int count1 = 0, count2 = 0;
            int val = arr1[i];

            // Count occurrences of arr1[i] in arr1
            while ((i < n) && (arr1[i] == val)) {
                count1++;
                i++;
            }

            // Count occurrences of arr2[j] in arr2
            while ((j < n) && (arr2[j] == val)) {
                count2++;
                j++;
            }

            // Add to similarity: occurences in left array * (val * the number of occurrences in right array)
            similarity += count1 * (val * count2); 
        }
    }

    cout << "Similarity: " << similarity << endl;

    return 0;
}
