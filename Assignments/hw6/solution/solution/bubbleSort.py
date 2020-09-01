##
#	CH-231-A
#	hw6_p1.cpp
#	Henri Sota
#	h.sota@jacobs-university.de
##
def bubbleSort(A):
    # Set swapped to True to enter while loop
    swapped = True
    # Iterate infinitely while a swap is available
    while (swapped):
        # Set swapped to False as there is no swap yet
        swapped = False
        # Iterate through the array from i to length of array
        for i in range(len(A) - 1):
            # Check if element in index i is bigger than element in index i + 1
            if (A[i] > A[i + 1]):
                # Swap elements in indices i and i + 1
                A[i], A[i + 1] = A[i + 1], A[i]
                # Set swapped to True
                swapped = True
    return A