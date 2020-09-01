/*
	CH-231-A
	hw9_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "RedBlackTree.h"

int main() {
    std::set<std::string> results;
    std::vector<int> elements = {1,2,3,4};
    int counter = 0;

    do {
        RedBlackTree rbt;
        for (int element : elements)
            rbt.insert(element);
        std::string result = rbt.inOrder();
        results.insert(rbt.inOrder());
        counter++;
    } while (std::next_permutation(elements.begin(), elements.end()));

    std::cout << "All " << counter << " permutations of inserting {1,2,3,4} "
              << "into a Red Black Tree yield only "
              << results.size() << " unique possible states of the Red Black"
              << " Tree!"
              << std::endl;
    std::cout << "These 4 possible states, read using inorder traversal are: "
              << std::endl;

    for (std::string result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}