##
#	CH-231-A
#	hw7_p1.cpp
#	Henri Sota
#	h.sota@jacobs-university.de
##
def countingSort(A, B, k):
    # Initialize array C with values 0
    C = [0 for _ in range(k)]

    # Populate C with frequencies of indices in A
    for j in range(len(A)):
        C[A[j]] = C[A[j]] + 1

    # Fill C with number of elements smaller or equal to index
    for i in range(1, k):
        C[i] = C[i] + C[i - 1]
    
    # Place each element in its stable position by traversing the array
    # backwards and inserting at index of elements smaller or equal to it
    for j in range(len(A) - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        # Lower the frequency count of element and prepare to place the next
        # element with that value in the index before it to maintain stability
        C[A[j]] -= 1
    
    return B

if (__name__ == '__main__'):
    A = [9, 1, 6, 7, 6, 2, 1]

    # Preprocess storage and size of frequency table
    B = [None for _ in range(len(A))]
    k = max(A) + 1

    print('Counting Sort:')
    print(countingSort(A, B, k))