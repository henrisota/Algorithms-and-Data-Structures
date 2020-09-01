/*
	CH-231-A
	hw4_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <vector>

// Merge procedure to merge the subarrays, p to q and q to r into one sorted
// subarray from p to r
void merge(std::vector<int> &arr, int p, int q, int r);
// Insertion Sort function to sort a subarray from p to r of arr
void insertionSort(std::vector<int> &arr, int p, int r);
// Merge Sort function to sort a subarray from p to r of arr recursively using 
// Insertion Sort when subarray of recursive case is of size k or smaller
void mergeSort(std::vector<int> &arr, int p, int r, int k);

// Produce best case vector of size n
std::vector<int> bestCase(int n);
// Produce average case vector of size n
std::vector<int> averageCase(int n);
// Produce worst case vector of size n
std::vector<int> worstCase(int n);

// Range of values of the elements in the cases
int interval = 100000;

int main() {
    std::fstream worstFile("worstCaseData-100000.txt", std::ios::out);
    std::fstream averageFile("averageCaseData-100000.txt", std::ios::out);
    std::fstream bestFile("bestCaseData-100000.txt", std::ios::out);
    int iterations = 3;
    int maxSize = 100000;
    srand(time(NULL));
    
    if (worstFile.is_open() && averageFile.is_open() && bestFile.is_open()) {
        std::vector<int> worstTimes, averageTimes, bestTimes;
        for (int k = 10; k <= 1000; k += 10) {
            std::chrono::system_clock::time_point start, end;
            std::chrono::duration<double> period;

            // Calculate time for worst case
            double worstCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                std::vector<int> worstCaseGen = worstCase(maxSize);
                // Calculate time taken for case
                start = std::chrono::system_clock::now();
                mergeSort(worstCaseGen, 0, maxSize - 1, k);
                end = std::chrono::system_clock::now();
                period = end - start;
                // Add time to overall iteration sum
                worstCaseIterationSum += period.count();
            }
            // Output average time for iterations
            worstFile << k << " " 
                      << worstCaseIterationSum / iterations << std::endl;
            std::cout << k << " " 
                      << worstCaseIterationSum / iterations << std::endl;

            // Calculate time for average case
            double averageCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                std::vector<int> averageCaseGen = averageCase(maxSize);
                // Calculate time taken for case
                start = std::chrono::system_clock::now();
                mergeSort(averageCaseGen, 0, maxSize - 1, k);
                end = std::chrono::system_clock::now();
                period = end - start;
                // Add time to overall iteration sum
                averageCaseIterationSum += period.count();
            }
            // Output average time for iterations
            averageFile << k << " " 
                        << averageCaseIterationSum / iterations << std::endl;
            std::cout << k << " " 
                      << averageCaseIterationSum / iterations << std::endl;

            // Calculate time for best case
            double bestCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                std::vector<int> bestCaseGen = bestCase(maxSize);
                // Calculate time taken for case
                start = std::chrono::system_clock::now();
                mergeSort(bestCaseGen, 0, maxSize - 1, k);
                end = std::chrono::system_clock::now();
                period = end - start;
                // Add time to overall iteration sum
                bestCaseIterationSum += period.count();
            }
            // Output average time for iterations
            bestFile << k << " " 
                     << bestCaseIterationSum / iterations << std::endl;
            std::cout << k << " "
                      << bestCaseIterationSum / iterations << std::endl;
        }
    }

    worstFile.close();
    averageFile.close();
    bestFile.close();

    return 0;
}

void merge(std::vector<int> &arr, int p, int q, int r) {
    std::vector<int> left, right;
    // Fill left vector with elements from p to q of arr
    for (int i = p; i <= q; i++)
        left.push_back(arr[i]);
    // FIll right vector with elements from q+1 to r of arr
    for (int i = q + 1; i <= r; i++)
        right.push_back(arr[i]);
    // Add sentinel value interval as biggest element of each array
    left.push_back(interval);
    right.push_back(interval);
    // Merge both subarrays into one by comparing left[i] and right[j] and
    // choosing the smaller one first
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}

void insertionSort(std::vector<int> &arr, int p, int r) {
    for (int j = p + 1; j <= r; j++) {
        int key = arr[j];
        int i = j - 1;
        // Search for the position where to place key value in the sorted
        // subarray arr[0..i]
        while (i > p - 1 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

void mergeSort(std::vector<int> &arr, int p, int r, int k) {
    if (r - p + 1 <= k) {
        // Sort using Insertion Sort
        insertionSort(arr, p, r);
    } else {
        // Sort using Merge Sort
        // Calculate middle position of the array
        int q = (p + r - 1) / 2;
        // Recursively call Merge Sort on the subarray left to middle position
        mergeSort(arr, p, q, k);
        // Recursively call Merge Sort on the subarray right to middle position
        mergeSort(arr, q + 1, r, k);
        // Merge both sorted subarrays into one sorted subarray
        merge(arr, p, q, r);
    }
}

std::vector<int> bestCase(int n) {
    std::vector<int> best;
    // Create a vector made of random integers from interval
    for (int i = 0; i < n; i++)
        best.push_back(rand() % interval);
    // Sort the vector using sort() function
    std::sort(best.begin(), best.end());
    return best;
}

std::vector<int> averageCase(int n) {
    std::vector<int> average;
    // Create a vector made of random integers from interval
    for (int i = 0; i < n; i++)
        average.push_back(rand() % interval);
    return average;
}

std::vector<int> worstCase(int n) {
    std::vector<int> worst;
    // Create a vector of indices with elements from 0 to n - 1
    for (int i = 0; i < n; i++)
        worst.push_back(rand() % interval);
    // Reverse sort the vector using sort() function
    std::sort(worst.begin(), worst.end(), std::greater<int>());
    return worst;    
}