##
#	CH-231-A
#	hw7_p1.cpp
#	Henri Sota
#	h.sota@jacobs-university.de
##
def sortAlphabetically(A, i):
    # Create empty list for each character of the alphabet and for the result
    # with one extra element to hold empty positions of smaller sized words
    C = [0 for _ in range(27)]
    sorted = ['' for _ in range(len(A))]

    # Populate C with the frequencies of the characters of the alphabet
    for j in range(len(A)):
        if (len(A[j]) > i):
            ch = ord(A[j][i]) - 96
        else: ch = 0
        C[ch] += 1
    
    # Fill C with the number of characters "smaller" than or equal to the letter
    # at j-th position of the alphabet from the existing frequency list
    for j in range(1, 27):
        C[j] += C[j - 1]

    # Place each word in its stable position by traversing the array
    # backwards and inserting at index of characters smaller or equal to it
    for j in range(len(A)-1, -1, -1):
        if (len(A[j]) > i):
            ch = ord(A[j][i]) - 96
        else: ch = 0
        sorted[C[ch] - 1] = A[j]
        # Lower the frequency count of letter and prepare to place the next
        # word with that character in the index before it to maintain stability
        C[ch] -= 1
    
    return sorted

def sortStringsLinear(A):
    d = max([len(i) for i in A]) - 1
    for i in range(d, -1 , -1):
        A = sortAlphabetically(A, i)
    return A

if (__name__ == '__main__'):
    A = ['word', 'category', 'cat', 'new', 'news', 'world', 'bear', 'at',
         'work', 'time']
    print('Alphabetical Sorting of Strings:')
    sorted = sortStringsLinear(A)
    for i, j in enumerate(sorted):
        if (i == 0):
            print(j, end='')
        else: print(', ' + j, end='')