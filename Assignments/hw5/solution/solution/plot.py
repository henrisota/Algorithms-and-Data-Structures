##
#	CH-231-A
#	hw5_p1.py
#	Henri Sota
#	h.sota@jacobs-university.de
##
import matplotlib.pyplot as plt

if __name__ == '__main__':
    n = [round(i**1.5) for i in range(120)]
    recursive = []
    bottomUp = []
    closedForm = []
    matrix = []
    with open('data.txt', 'r') as input:
        for line in input:
            info = line.rstrip().split()
            if (info[0] == 'R:'):
                recursive.append(float(info[2]))
            elif (info[0] == 'B:'):
                bottomUp.append(float(info[2]))
            elif (info[0] == 'C:'):
                closedForm.append(float(info[2]))
            else: matrix.append(float(info[2]))
        plt.plot(n[:len(recursive)], recursive, color='blue', linewidth=0.5, 
                 label='Recursive')
        plt.plot(n, bottomUp, color='red', linewidth=0.5, label='Bottom Up')
        plt.plot(n, closedForm, color='green', linewidth=0.5, label='Closed Form')
        plt.plot(n, matrix, color='yellow', linewidth=0.5, label='Matrix')

        plt.yscale('log')
        plt.xlabel('n')
        plt.ylabel('Time (s)')
        plt.title('Fibonacci Unbounded')
        plt.legend()
        plt.grid(True)
        plt.savefig('fibonacci.png', format='png', dpi=1000)