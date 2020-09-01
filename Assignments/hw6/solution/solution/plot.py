##
#	CH-231-A
#	hw6_p2.py
#	Henri Sota
#	h.sota@jacobs-university.de
##
import matplotlib.pyplot as plt

if __name__ == '__main__':
    n = [i for i in range(0, 500001, 25000)]
    normalResults, variantResults = [], []
    with open('dataHeapSort.txt', 'r') as normal:
         for line in normal:
            info = line.rstrip().split()
            normalResults.append(float(info[1]))
    
    with open('dataHeapSortVariant.txt', 'r') as variant:
        for line in variant:
            info = line.rstrip().split()
            variantResults.append(float(info[1]))

    plt.plot(n, normalResults, color='blue', linewidth=0.5, 
                label='Heap Sort')
    plt.plot(n, variantResults, color='red', linewidth=0.5, 
                label='Heap Sort Variant')
    plt.xlabel('n')
    plt.ylabel('Time (s)')
    plt.title('Heap Sort')
    plt.legend()
    plt.grid(True)
    plt.savefig('heapSort.png', format='png', dpi=1000)