##
#	CH-231-A
#	hw5_p1.py
#	Henri Sota
#	h.sota@jacobs-university.de
##
import matplotlib.pyplot as plt
import pandas as pd

if __name__ == '__main__':
    data = []
    n = [round(i**1.5) for i in range(12)]
    recursive = []
    bottomUp = []
    closedForm = []
    matrix = []
    with open('dataSampled.txt', 'r') as input:
        for line in input:
            info = line.rstrip().split()
            if (info[0] == 'R:'):
                recursive.append(float(info[2]))
            elif (info[0] == 'B:'):
                bottomUp.append(float(info[2]))
            elif (info[0] == 'C:'):
                closedForm.append(float(info[2]))
            else: matrix.append(float(info[2]))

    
    for i in range(12):
        data.append([n[i], recursive[i], bottomUp[i], closedForm[i], matrix[i]])

    fig, ax = plt.subplots()

    fig.patch.set_visible(False)
    ax.axis('off')
    ax.axis('tight')

    colLabels = ['n', 'Recursive', 'Bottom Up', 'Closed Form','Matrix']
    df = pd.DataFrame(data, columns=colLabels)

    ax.table(
        cellText=df.values,
        colLabels=df.columns,
        cellLoc='center',
        loc='center'
    )

    fig.tight_layout()

    plt.savefig('SampledDataTable.png', bbox_inches='tight', pad_inches=0.05, 
                dpi=1000)