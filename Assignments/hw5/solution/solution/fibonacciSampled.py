##
#	CH-231-A
#	hw5_p1.py
#	Henri Sota
#	h.sota@jacobs-university.de
##
import time
import math

def fibonacciNaiveRecursive(n):
    if (n < 2):
        return n
    else: return fibonacciNaiveRecursive(n - 1) + fibonacciNaiveRecursive(n - 2)

def fibonacciBottomUp(n):
    fibonacciSeq = [0, 1]
    for i in range(2, n+1):
        fibonacciSeq.append(fibonacciSeq[i-1] + fibonacciSeq[i-2])
    return fibonacciSeq[n]

def powerOfANumber(number, p):
    if (p ==  0):
        return 1
    elif (p == 1):
        return number
    else:
        if (p % 2 == 0):
            return powerOfANumber(number, p/2) * powerOfANumber(number, p/2)
        else:
            power = powerOfANumber(number, (p-1)/2)
            return power * power * number

def fibonacciClosedForm(n):
    powerPhi = powerOfANumber(phi, n)
    return round(powerPhi / math.sqrt(5.0))

def matrixMultiply(first, second):
    result = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                result[i][j] += first[i][k] * second[k][j]
    return result

def powerOfAMatrix(matrix, p):
    if (p ==  0):
        return [[1, 0], [0, 1]]
    elif (p == 1):
        return matrix
    else:
        if (p % 2 == 0):
            return matrixMultiply(powerOfAMatrix(matrix, p/2),
                                  powerOfAMatrix(matrix, p/2))
        else:
            power = powerOfAMatrix(matrix, (p-1)/2)
            result = matrixMultiply(power, power)
            result = matrixMultiply(result, matrix)
            return result

def fibonacciMatrix(n):
    fibonacci = [[1, 1], [1, 0]]
    result = powerOfAMatrix(fibonacci, n)
    return result[0][1]

if __name__ == '__main__':
    phi = (1 + math.sqrt(5)) / 2
    timeLimit = 10
    with open('dataSampled.txt', 'w') as out:
        samples = [round(i**1.5) for i in range(13)]
        for i in samples:
            start = time.time()
            result = fibonacciNaiveRecursive(i)
            end = time.time()
            period = end - start
            if (period >= timeLimit):
                break
            out.write('R: ' + str(i) + ' ' + str(period) + ' ' + 
                      str(result) + '\n')
            print('R: ' + str(i) + ' ' + str(period) + ' ' + str(result) +
                  '\n')
            
            start = time.time()
            result = fibonacciBottomUp(i)
            end = time.time()
            period = end - start
            if (period >= timeLimit):
                break
            out.write('B: ' + str(i) + ' ' + str(period) + ' ' + str(result) +
                      '\n')
            print('B: ' + str(i) + ' ' + str(period) + ' ' + str(result) + '\n')
            
            start = time.time()
            result = fibonacciClosedForm(i)
            end = time.time()
            period = end - start
            if (period >= timeLimit):
                break
            out.write('C: ' + str(i) + ' ' + str(period) + ' ' + str(result) +
                      '\n')
            print('C: ' + str(i) + ' ' + str(period) + ' ' + str(result) + '\n')

            start = time.time()
            result = fibonacciMatrix(i)
            end = time.time()
            period = end - start
            if (period >= timeLimit):
                break
            out.write('M: ' + str(i) + ' ' + str(period) + ' ' + str(result) +
                      '\n')
            print('M: ' + str(i) + ' ' + str(period) + ' ' + str(result) + '\n')