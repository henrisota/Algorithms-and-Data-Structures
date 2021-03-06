set terminal png size 1600, 1200
set output "mergeSortInsertionSortOptimizedAnalysis50000.png"

set xlabel 'k'
set ylabel 'Time'
# Axes ranges
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 2
set style line 3 linecolor rgb '#44ee66' linetype 1 linewidth 2

plot "worstCaseData-50000.txt" using 1:2 title "Worst Case" with lines linestyle 1, \
     "averageCaseData-50000.txt" using 1:2 title "Average Case" with lines linestyle 2, \
     "bestCaseData-50000.txt" using 1:2 title "Best Case" with lines linestyle 3