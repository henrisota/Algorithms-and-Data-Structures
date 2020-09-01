##
#	CH-231-A
#	hw7_p2.cpp
#	Henri Sota
#	h.sota@jacobs-university.de
##
import math

def findHighestDigitCount(A):
    # Get biggest element in array
    maxElement = max(A)
    exp = 1

    # Iteratively raise the exponent until biggest number over 10 to exp is < 1
    while (maxElement / exp > 1.0):
        exp *= 10

    return int(math.log(exp, 10))

def radixSortMSD(A, i, longest):
    # Check if array contains one or less elements or if digit being compared
    # is bigger than the number of digits of the biggest element
    if ((len(A) < 2) or (i >= longest)):
        return A

    sorted = []

    # Create buckets corresponding to each digit of the base
    B = [[] for x in range(10)]

    # Traverse each number in the array
    for number in A:
        # Retrieve the digit by dividing by power of 10 to (longest - 1 - i)
        # and calculating the remainder of division by 10
        digit = (number // (10**(longest - i - 1))) % 10
        # Place number in bucket which corresponds to the digit being compared
        B[digit].append(number)

    # Recursively sort buckets
    for j in range(len(B)):
        B[j] = radixSortMSD(B[j], i + 1, longest)

    # Concatenate lists together to yield sorted array
    for j in B:
        for number in j:
            sorted.append(number)

    return sorted

if (__name__ == '__main__'):
    A = [6797, 4404, 236, 1360, 8490, 5076, 8455, 7015, 47, 7179, 444, 0, 997,
        4404, 530, 2269, 120, 6876, 9999, 951, 4147, 3250, 13015, 586, 3502]

    # Find the number of digits of the biggest number in array
    longest = findHighestDigitCount(A)
    
    print('Radix Sort MSD:')
    print(radixSortMSD(A, 0, longest))