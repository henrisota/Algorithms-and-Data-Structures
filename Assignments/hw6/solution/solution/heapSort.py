##
#	CH-231-A
#	hw6_p2.py
#	Henri Sota
#	h.sota@jacobs-university.de
##
import time
import random

def left(i):
    # Return index of left child
    return i * 2 + 1

def right(i):
    # Return index of right child
    return i * 2 + 2

def maxHeapify(A, i, heapsize):
    l = left(i)
    r = right(i)

    # Check if left child exists and is greater than element
    if ((l < heapsize) and (A[l] > A[i])):
        # Set largest to the index of left child
        largest = l
    else:
        # Set largest to the index of element
        largest = i
    
    # Check if right child exists and is greater than the largest-th element
    if ((r < heapsize) and (A[r] > A[largest])):
        # Set largest to the index of right child
        largest = r

    # Check if largest and i are different
    if (largest != i):
        # Swap between the largest child and the parent of the child
        A[i], A[largest] = A[largest], A[i]
        # Call maxHeapify on the largest-th element which holds the value of the
        # former parent of largest-th element
        A = maxHeapify(A, largest, heapsize)
    return A

def buildMaxHeap(A, heapsize):
    # Loop from the parent of the heapsize-th element to root
    for i in range((heapsize - 1) // 2, -1, -1):
        # Maintain Max Heap property by calling maxHeapify
        A = maxHeapify(A, i, heapsize)
    return A

def heapSort(A, heapsize):
    # Build Max Heap from the unsorted array
    buildMaxHeap(A, heapsize)
    # Pop biggest element off heap and maintain Max Heap property iteratively
    for i in range(len(A) - 1, 0, -1):
        A[0], A[i] = A[i], A[0]
        heapsize -= 1
        A = maxHeapify(A, 0, heapsize)
    return A

def case(n):
    return [(n - i) for i in range(0, n)]

if (__name__ == '__main__'):
    with open('dataHeapSort.txt', 'w') as out:
        for n in range(0, 500001, 25000):
            # Calculate time taken for Heap Sort to sort an array of length n
            A = case(n)
            start = time.time()
            heapSort(A, n)
            end = time.time()
            period = end - start
            out.write(str(n) + ' ' + str(period) + '\n')
            print(str(n) + ' ' + str(period))