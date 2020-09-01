/*
	CH-231-A
	hw3_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <vector>
#include <fstream>

void selectionSort(std::vector<int>& seq, int n);

// Produce best case vector of size n
std::vector<int> bestCase(int n);
// Produce average case vector of size n
std::vector<int> averageCase(int n);
// Produce worst case vector of size n
std::vector<int> worstCase(int n);

// Range of values of the elements in the cases
int interval = 100000;

int main() {
    std::fstream worstFile("worstCaseData.txt", std::ios::out);
    std::fstream averageFile("averageCaseData.txt", std::ios::out);
    std::fstream bestFile("bestCaseData.txt", std::ios::out);
    int iterations = 5;
    int maxSize = 34000;
    int caseStep = 1000;
    srand(time(NULL));
    
    if (worstFile.is_open() && averageFile.is_open() && bestFile.is_open()) {
        std::vector<int> worstTimes, averageTimes, bestTimes;

        for (int n = 0; n <= maxSize; n += caseStep) {
            std::chrono::system_clock::time_point start, end;
            std::chrono::duration<double> period;

            // Initialize times vectors with first element 0
            if (n == 0) {
                worstFile << n << " " << 0 << std::endl;
                averageFile << n << " " << 0 << std::endl;
                bestFile << n << " " << 0 << std::endl;
                worstTimes.push_back(0);
                averageTimes.push_back(0);
                bestTimes.push_back(0);
                continue;
            }

            // Calculate time for worst case
            double worstCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                std::vector<int> worstCaseGen = worstCase(n);
                // Calculate time taken for case
                start = std::chrono::system_clock::now();
                selectionSort(worstCaseGen, (int) worstCaseGen.size());
                end = std::chrono::system_clock::now();
                period = end - start;
                // Add time to overall iteration sum
                worstCaseIterationSum += period.count();
            }
            // Output average time for iterations
            worstFile << n << " " 
                      << worstCaseIterationSum / iterations << std::endl;
            std::cout << n << " " 
                      << worstCaseIterationSum / iterations << std::endl;

            // Calculate time for average case
            double averageCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                std::vector<int> averageCaseGen = averageCase(n);
                // Calculate time taken for case
                start = std::chrono::system_clock::now();
                selectionSort(averageCaseGen, (int) averageCaseGen.size());
                end = std::chrono::system_clock::now();
                period = end - start;
                // Add time to overall iteration sum
                averageCaseIterationSum += period.count();
            }
            // Output average time for iterations
            averageFile << n << " " 
                        << averageCaseIterationSum / iterations << std::endl;
            std::cout << n << " " 
                      << averageCaseIterationSum / iterations << std::endl;

            // Calculate time for best case
            double bestCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                std::vector<int> bestCaseGen = bestCase(n);
                // Calculate time taken for case
                start = std::chrono::system_clock::now();
                selectionSort(bestCaseGen, (int) bestCaseGen.size());
                end = std::chrono::system_clock::now();
                period = end - start;
                // Add time to overall iteration sum
                bestCaseIterationSum += period.count();
            }
            // Output average time for iterations
            bestFile << n << " " 
                     << bestCaseIterationSum / iterations << std::endl;
            std::cout << n << " "
                      << bestCaseIterationSum / iterations << std::endl;
        }
    }

    worstFile.close();
    averageFile.close();
    bestFile.close();

    return 0;
}

void selectionSort(std::vector<int>& seq, int n) {
    for (int i = 0; i < n - 1; i++) {
        int temp, min = i;
        for (int j = i + 1; j < n; j++)
            if (seq[j] < seq[min])
                min = j;
        if (min != i) {
            temp = seq[min];
            seq[min] = seq[i];
            seq[i] = temp;
        }
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
    int firstIndex, swappingNumber = 0;
    std::vector<int> sample;
    std::vector<int> indices;
    std::vector<int> worst(n);

    // Create a vector of indices with elements from 0 to n - 1
    for (int i = 0; i < n; i++)
        indices.push_back(i);

    // Create a vector made of random integers from interval
    for (int i = 0; i < n; i++)
        sample.push_back(rand() % interval);
    // Sort vector to begin single cycle chain
    std::sort(sample.begin(), sample.end());

    // Choose a random index for the first element of the chain
    firstIndex = rand() % n;
    std::vector<int>::const_iterator it;
    // Move iterator to match firstIndex
    for (it = indices.begin(); it != indices.end(); it++)
        if (*it == firstIndex)
            break;

    // Remove index in order to not be used along the chain
    indices.erase(it);

    // Loop through n elements
    for (int i = 0; i < n; i++) {
        // Check if iteration is at the end
        if (i != (n - 1)) {
            // Choose random index from indices vector as position to move
            // swappingNumber (number replaced from the previous iteration)
            int swapIndex = indices[rand() % ((int) indices.size())];

            // Move iterator to match swapIndex
            for (it = indices.begin(); it != indices.end(); it++)
                if (*it == swapIndex)
                    break;
            indices.erase(it);

            // Check if iteration is at the beginning
            if (i == 0)
                // Place element at firstIndex of sample in worst to start 
                // building worst case vector
                worst[swapIndex] = sample[firstIndex];
            else
                // Place swappingNumber, replaced from swap in the previous
                // iteration into its position in worst case vector
                worst[swapIndex] = swappingNumber;
            // Save the swapped number at that index to place in the next
            // swapIndex of the following iteration
            swappingNumber = sample[swapIndex];
        } else 
            // Place the last element which got swapped in the last iteration
            // into the firstIndex which is empty to complete the cycle
            worst[firstIndex] = swappingNumber;
    }
    return worst;    
}