Practice Sheet
---
| Problem | Status |
|---------|--------|
| 1       | Done   |
| 2       | Done   |
| 3       | Done   |
| 4       | Done   |
| 5       | Done   |
| 6       | Done   |
| 7       | Done   |
| 8       | Done   |
| 9       | Done   |
| 10      | Done   |
| 11      | Done   |

##### Problem P.1 STL CONTAINERS
Which list is the longest list with containers in which you can you use the insert method?
- 4) vector, list, deque, set, multiset, map, multimap

##### Problem P.2 Templates I
Write down the output of the following C++ program:
```cpp
#include <iostream>
using namespace std;
template <class T>
class Test {
    private:
        T val;
    public:
        static int count;
        Test() { count++; }
};
template<class T>
int Test<T>::count = 0;
int main() {
    Test<int> a;
    Test<int> b;
    Test<double> c;
    cout << Test<int>::count << endl;
    cout << Test<double>::count << endl;
    return 0;
}
```
Output:
2
1

##### Problem P.3 Templates II
Create the C++ template function named multiples so that it has three parameters: sum, x, and
n. The function should use the sum variable to ”return by reference” sum = 1+x+2x+3x+...+nx.
```cpp
template <class T1, class T2> // T2 can be of type int since those are n integers summed up
T1 multiples(T1 &sum, T1 x, T2 n) {
    sum = 1;
    for (T2 i = 1; i <= n; i++)
        sum += i * x;
    return sum;
}
```
```cpp
// Driver Function
int main() {
    int sum = 1231;
    int x = 1;
    int n = 10;
    std::cout << multiples(sum, x, n) << std::endl;
    return 0;
}
```

##### Problem P.4 Search in Data Structures
The following data structures can perform a search operation in time of O(n log n):
(Note: Should be just O(log(n)) as all of them are correct)
- 5) Red Black Tree

Only RBTs provide the time complexity of search operation to be performed in O(log(n)) all the time due to their 5 properties.
Note: The solution is actually following the O(n log n) question. It is not a typo. Therefore all apply.

##### Problem P.5 Asymptotic Time Complexity
Consider the recurrence T(n) = 3T(n/2) + Θ(n) with T(1) = Θ(1).
- True / False T(n) in Theta(nlog(n))
- True / False T(n) in Theta(n^3log(n))
- True / False T(n) in Theta(log(n))
- True / False T(n) in Theta(n^3)
- True / false T(n) in Theta(3nlog(n))

By Master Theorem method, a = 3, b = 2, and f(n) = n as Theta(n) => n. Would yield a time complexity of Theta(n^(log_2(3))) approximately Theta(n^(1.585)). Technically all are False in this case.

##### Problem P.6 Fast Multiplication
Recall the divide and conquer formula of fast exponentiation of a number a ∈ R to a power n ∈ N:
a^n = a^(n/2) * a^(n/2) if n is even and = a^(floor(n/2)) * a^(floor(n/2)) * a if n is odd
a) Give a similar formula for a divide and conquer approach to the fast multiplication problem of a ∈ R and n ∈ N.
```cpp
a * n = {
    a * (n / 2) + a * (n / 2)                 // If n is even
    a * floor(n / 2) + a * floor(n / 2) + a        // If n is odd
}
```

b) Write a pseudocode implementation of a function that uses the derived formula to multiply a and n.
```cpp
Real fastMultiplication(a, n) {
    if (n = 1)
        return a;

    // * 2 if multiplication is allowed by right / left shift allowed
    // + itself if multiplication is not allowed
    if (n % 2 == 0) {
        subcase = fastMultiplication(a, n / 2);
        return subcase * 2;
    } else {
        subcase = fastMultiplication(a, floor(n / 2));
        return subcase * 2 + a;
}
```
c) Derive and prove the asymptotic time complexity (upper and lower bound) of your algorithm.

Finding a recurrence formula for the divide and conquer approach:
T(n) = T(n / 2) + Theta(1)
By the Master Theorem, this falls under case 2, which yields a time complexity of T(n) = O(log(n)). In the best case, this would be only O(1).

##### Problem P.7 Binary Search Tree
Study the given code. The goal of the transform function is to convert a binary search tree into a new one that meets the following requirements:
- It is still a binary search tree.
- Every vertex has only one child.
- If a vertex is the left child of it’s parent it can’t have a left child. If it is a right child it can’t have a right child.
- It contains the exact same nodes as the initial tree.

Implement or write pseudocode for the transform function using the other given functions.
The root of the resulting tree should be returned through the given parameter of the function.
```cpp
struct node {
    int data;
    
    node *left;
    node *right;
    node *parent;
};

void replace(node **root, node *x, node *y) {
    if(x == *root)
        *root = y;
    else {
        if(y != NULL)
            y->parent = x->parent;
            
        if(x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
}

node* find_min(node **root){
    node ∗min = NULL;
    node *tmp = *root;
    
    while(tmp != NULL)
        min = tmp,
        tmp = tmp->left;
    return min;
}

node* extract_min(node **root) {
    node *min = find_min(root);
    
    if(min == NULL)
        return NULL;
        
    replace(root, min, min->right);
    min->right = NULL;
    
    return min;
}
node* find_max(node **root) {
    node *max = NULL;
    node *tmp = *root;
    
    while (tmp != NULL)
        max = tmp,
        tmp = tmp->right;
        
    return max;
}

node* extract_max(node **root) {
    node *max = find_max(root);
    
    if (max == NULL)
        return NULL;
        
    replace(root, max, max->left);
    max->left = NULL;
    
    return max;
}
void transform(node **root);
```

Solution will not yield a correct tree following the rules, but it follows the idea.
Solution from the Practice Sheet just creates a new tree and it gets the first
minimum from the tree and then it enters a loop until the root becomes NULL.
It switches each time from choosing the minimum or maximum of the root and it adds that to the solution.
Solution:
```cpp
void transform(node **root) {
    if (*root == NULL)
        return;
    
    if (*root->parent != NULL) {
        if (*root == *root->parent->left && *root->right != NULL) {
            node* max_subtree = extract_max(*root->right);
            node* temp = *root->right;
            *root->right = max_subtree;
            max_subtree->parent = *root;
            max_subtree->left = temp;
            temp->parent = max_subtree;
            transform(max_subtree);
        } else if (*root == *root->parent->right && *root->left != NULL) {
            node* min_subtree = extract_min(*root->left);
            node* temp = *root->left;
            *root->left = min_subtree;
            min_subtree->parent = *root;
            min_subtree->right= temp;
            temp->parent = min_subtree;
            transform(min_subtree);
        } else return;
    } else {
        node* leftMin = extract_min(*root->left);
        node* rightMax = extract_max(*root->right);

        node* tempLeft = *root->left;
        node* tempRight = *root->right;

        *root->left = leftMin;
        *root->right = rightMax;

        leftMin->right = tempLeft;
        tempLeft->parent = leftMin;

        rightMax->left = tempRight;
        tempRight->parent = rightMax;

        transform(leftMin);
        transform(rightMax);
    }
}
```

##### Problem P.8 Quicksort
Write down the complete pseudocode for randomized Quicksort including functions which are required for partitioning.
```cpp
Randomized-Partition(A, p, r) {
    rand = random(p, r)     // Choose random number between p and r (inclusive)
    Swap(A[rand]. A[r])     // Swap elements at random position and last position
    return Partition(A, p, r)      // Perform normal partition procedure
}

Partition(A, p, r) {
    x = A[r]
    i = p - 1
    j = p
    while (j != r) {
        if (A[j] <= x) {
            i = i + 1
            Swap(A[i], A[j])
        }
        j = j + 1
    }
    Swap(A[i + 1], A [r])
    return i + 1
}

Quicksort(A, p, r) {
    If (p < r) {
        part = Randomized-Partition(A, 0, A.length - 1)
        Quicksort(A, p, part - 1)
        Quicksort(A, part + 1, A.length - 1)
    }
}
```

##### Problem P.9 Red Black Trees
Make an example of a red black tree with the height of 3. You do not need to draw a tree. Just list the nodes per level from left to right and indicate the parent, left or right child, the value and the color for each node.
Structure: Node (Name: , Value: , Color: , Parent: , Left Child: , Right Child: )

Level 1: Root Node (Name: A, Value: 10, Color: Black, Parent: None, Left Child: Node B, Right Child: Node C)

Level 2: Node (Name: B, Value: 5, Color: Red, Parent: Node A, Left Child: Node D, Right Child: Node E), Node (Name: C, Value: 13, Color: Red, Parent: Node A, Left Child: Node F, Right Child: Node G)

Level 3: Node (Name: D, Value: 2, Color: Black, Parent: Node B, Left Child: Nil, Right Child: Nil), Node (Name: E, Value: 6, Color: Black, Parent: Node B, Left Child: Nil, Right Child: Nil), Node (Name: F, Value: 11, Color: Black, Parent: Node C, Left Child: Nil, Right Child: Nil), Node (Name: G, Value: 15, Color: Black, Parent: Node C, Left Child: Nil, Right Child: Nil)

Level 4: Level filled full of Nil Black nodes representing trees.

// This was based on the assumption that height of the tree is the length of longest path from the root to a leaf node. In case that height of the tree in your definition is based on the number of nodes, removing the third level and having only 4 Nil Black nodes on the third level would work by your definition.

##### Problem P.10 Greedy Algorithm
Consider the following minimizing lateness problem for multiple jobs/tasks:
- Only one job can be processed at a time.
- Job j requires tj units of processing time and is due at time dj.
- If j starts at time sj , it finishes at time fj = sj + tj.
- The lateness: lj = max{0, fj − dj}
- Develop a greedy algorithm to schedule all jobs to minimize the maximum lateness L = max lj.

a) Prove that greedy algorithms that make the greedy choices of shortest processing time first tj and smallest slack dj − tj both fail to produce a globally optimal solution.
Solution:
- Shortest Processing Time tj will not yield the globally optimal solution. Given a test case: Task 1 (t = 5, d = 5), Task 2 (t = 2, d = 8), Task 3 (t = 3, d = 8)
The solution given by the shortest processing time greedy approach would be: T2 -> T3 -> T1 with maximum lateness 5 for Task 1. Though the globally optimal solutions would be: T1 -> T2 -> T3, T1 -> T3 -> T2, both with maximum lateness 2.
- Smallest Slack dj - tj will not yield the globally optimal solution. Given a test case: Task 1 (t = 8, d = 8), Task 2 (t = 2, d = 5), Task 3 (t = 3, d = 4). The solution given by the smallest slack greeedy approach would be: T1 -> T3 -> T2 with maximum lateness 8. Though one better solution would be: T3 -> T2 -> T1 with maximum lateness 5.

b) Develop the greedy algorithm in pseudocode that makes the correct greedy choice. Use the example in the problem to verify your solution (the optimal solution has a maximum lateness of 1).
```cpp
Sort tasks by their deadline on deadlines array
Start[]: n element Array
Finish[]: n element Array
timer = 0
max = 0
for i = 0 to n - 1
    Start[i] = timer
    Finish[i] = timer + durations[i]
    timer += durations[i]
    if (Finish[i] > deadlines[i] && max < Finish[i] - deadlines[i]>)
        max = Finish[i] - deadlines[i]
return max
```

##### Problem P.11 Graph Algorithms
Run the Breadth-First-Search algorithm starting from node 0 on the following example graph. Write down the detailed steps below.

Breadth-First-Search Algorithm would start searching from the first node given and search the graph level by level based on the distance of the nodes found in the graph from the start node. Initially, every node is set to be White, distance property set to infinity and predecessor set to NIL. The starting node 0 would be set to have distance 0, color Gray and predecessor to NIL. The start node would be enqueued into a queue structure. The following loop would run until the queue would be empty. The first step inside the body of the loop would be to dequeue one node from the queue and would iterate through all the nodes in the adjacency list of the dequeued node. In the first step, for node 0, it would find node 1 and node 2. Their color would be set to Gray and their distance from node 0 to be 1 (0 + 1). Node 1 and node 2 are then enqueued onto the queue. On the next iteration of the loop, node 1 would be dequeued and node 3 would be set to Gray and its distance would be set to 2 (1 + 1). Node 3 would then be queued onto the queue and node 1 would be set to Black. On the next iteration, node 2 would be dequeued and no other node would be enqueued as its only adjacent node is 3 which was already added to the queue through node 1. Node 2 is set to Black. On the next iteration, node 3 would be dequeued from the queue and node 4 would be set to distance 3 (2 + 1) and color Gray due to being in the adjacency list of 3 and not yet having been found. Node 3 would be set to black. Node 4 would then be dequeued on the following iteration. Node 5 would be set to distance 4 (3 + 1) and color to be Gray. Node 4 would be set to black. On the next iteration node 5 would be dequeued and would be set to Black as it has no elements in its adjacency list. The next iteration of the loop would not be executed as queue would be empty. The result from running Breadth-First-Search starting from node 0 would be:
- Level 1 (distance 0): Node 0
- Level 2 (distance 1): Node 1, Node 2
- Level 3 (distance 2): Node 3
- Level 4 (distance 3): Node 4
- Level 5 (distance 4): Node 5