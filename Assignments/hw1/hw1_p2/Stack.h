/*
	CH-231-A
	hw1_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
template <class T, int initialSize = 10>
class Stack {
	private:
		T* ptrArr;
		int size;
		int lastElement;
	public:
		// Constructor with parameter size
		Stack(int size);
		// Constructor with no parameters
		Stack();
		// Copy constructor
		Stack(const Stack&);
		// Destructor
		~Stack();

		// Push an element onto the Stack
		bool push(T element);
		// Pop an element out of the Stack
		bool pop(T& out);

		// Get the last element added to the Stack
		T back(void);
		// Get the number of elements in the Stack
		int getNumEntries();
};

template <class T, int initialSize>
Stack<T, initialSize>::Stack(int size) {
	this->ptrArr = new T[size];
	this->size = size;
	this->lastElement = -1;
}

template <class T, int initialSize>
Stack<T, initialSize>::Stack() {
	this->ptrArr = new T[initialSize];
	this->size = initialSize;
	this->lastElement = -1;
}

// Copy constructor
template <class T, int initialSize>
Stack<T, initialSize>::Stack(const Stack& obj) {
	this->ptrArr = new T[obj.size];
	this->size = obj.size;
	this->lastElement = obj.lastElement;
	for (int i = 0; i < size; i++)
		this->ptrArr[i] = obj.ptrArr[i];
}

template <class T, int initialSize>
Stack<T, initialSize>::~Stack() {
	// Delete the memory pointed at by ptrArr
	delete [] ptrArr;
}

template <class T, int initialSize>
bool Stack<T, initialSize>::push(T element) {
	if (this->lastElement == this->size - 1)
		return false;
	else {
		// Add element on top of the Stack		
		this->ptrArr[lastElement + 1] = element;
		// Increase by 1 the number of elements
		lastElement++;
		return true;
	}
}

// Return true if it popped an element from the Stack successfully or false
// in case not
template <class T, int initialSize>
bool Stack<T, initialSize>::pop(T& out) {
	if (this->lastElement == -1)
		return false;
	else {
		// Decrease by 1 the number of elements
		out = this->ptrArr[lastElement];
		lastElement--;
		return true;
	}
}

// Return the last element added to the Stack
template <class T, int initialSize>
T Stack<T, initialSize>::back(void) {
	// In case no element is in the Stack
	if (lastElement == -1)
		exit(1);
	return this->ptrArr[this->lastElement];
}

// Return the number of elements in the Stack
template <class T, int initialSize>
int Stack<T, initialSize>::getNumEntries() {
	return lastElement + 1;
}