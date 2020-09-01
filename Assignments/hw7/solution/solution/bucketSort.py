##
#	CH-231-A
#	hw7_p1.cpp
#	Henri Sota
#	h.sota@jacobs-university.de
##
import math

def insertionSort(Bucket):
    for j in range(1, len(Bucket)):
        key = Bucket[j]
        i = j - 1
        # Search for the position where to place key value in the sorted
        # subarray Bucket[0..i]
        while (i > -1 and Bucket[i] > key):
            Bucket[i + 1] = Bucket[i]
            i -= 1
        Bucket[i + 1] = key
    return Bucket

def bucketSort(A):
    sorted = []
    n = len(A)

    # Declare each element of B as a list
    B = [[] for _ in range(n)]

    # Insert each element into its corresponding bucket
    for i in range(n):
        B[int(math.floor(n * A[i]))].append(A[i])

    # Sort elements inside the bucket i with Insertion Sort
    # Note: Other sorting algorithms with better time complexity can be used
    for i in range(n):
        B[i] = insertionSort(B[i])

    # Concatenate lists together to yield sorted array
    for i in range(n):
        sorted += B[i]

    return sorted

if (__name__ == '__main__'):
    A = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]

    print('Bucket Sort:')
    print(bucketSort(A))