/*
	CH-231-A
	hw10_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
class Node {
    public:
        int key;
        int value;
        Node(int key, int value);
};

class HashTable {
    private:
        Node **arr;
        int maxSize;
        int currentSize;
    public:
        // Constructor
        HashTable();

        // Destructor
        ~HashTable();

        // Hash Code method to calculate hash using division method
        int hashCode(int key);

        void insertNode(int key, int value);
        int get(int key);
        bool isEmpty();

        void printHashTable();
};