/*
	CH-231-A
	hw1_p3.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
template <class T>
class Node { 
    public:
        T data;
        Node *previous = NULL;
        Node *next = NULL;
        Node(T Data);
};

template <class T>
class List {
    private:
        int size;
        Node<T> *Front;
        Node<T> *Back;
    public:
        // Constructor with no parameters
        List();
        // Destructor
        ~List();

        // Push element on the back of the List
        void push_back(T element);
        // Push element on the front of the List
        void push_front(T element);
        // Pop element from the back of the List
        T pop_back();
        // Pop element from the front of the List
        T pop_front();
        // Get the element at the front of the List
        T front();
        // Get the element at the back of the List
        T back();
        // Get the number of the elements in the List
        int elementNumber();
};

template <class T>
List<T>::List() {
    this->Front = NULL;
    this->Back = NULL;
    this->size = 0;
}

template <class T>
List<T>::~List() {
    // Check if list is empty
    if (this->Front != NULL) {
        Node<T> *cursor = this->Front;
        Node<T> *temp;
        // Delete each element from the list while going through the list
        while (cursor != NULL) {
            temp = cursor;
            cursor = cursor->next;
            delete temp;
        }
    }
}

template <class T>
void List<T>::push_back(T element) {
    Node<T> *newElement = new Node<T>(element);
    newElement->previous = this->Back;
    newElement->next = NULL;

    // Check if list is empty
    if (this->size == 0)
        // Assign newElement as the front of the List
        this->Front = newElement;
    else
        // Add the element at the end of the List
        this->Back->next = newElement;

    // Set newElement as the back of the List
    this->Back = newElement;
    this->size++;
}

template <class T>
void List<T>::push_front(T element) {
    Node<T> *newElement = new Node<T>(element);
    newElement->previous = NULL;
    newElement->next = this->Front;

    if (this->size == 0)
        // Assign new Element as the back of the List
        this->Back = newElement;
    else
        // Add the element at the front of the List
        this->Front->previous = newElement;

    // Set newElement as the front of the List
    this->Front = newElement;
    this->size++;
}

template <class T>
T List<T>::pop_back() {
    Node<T> *temp = NULL;

    // Check if List is non-empty
    if (this->size > 0) {
        // Save the data of the element in the back and delete it
        T data;
        data = this->Back->data;
        temp = this->Back;
        this->Back = this->Back->previous;
        this->size--;
        delete temp;
        return data;
    } else {
        std::cout << "Unable to pop when List is empty!" 
                  << std::endl;
        exit(1);
    }
}

template <class T>
T List<T>::pop_front() {
    Node<T> *temp = NULL;

    // Check if List is non-empty
    if (this->size > 0) {
        // Save the data of the element in the front and delete it
        T data;
        data = this->Front->data;
        temp = this->Front;
        this->Front = this->Front->next;
        this->size--;
        delete temp;
        return data;
    } else {
        std::cout << "Unable to pop when List is empty!"
                  << std::endl;
        exit(1);
    }
}

template <class T>
int List<T>::elementNumber() {
    return this->size;
}

template <class T>
T List<T>::front() {
    return this->Front->data;
}

template <class T>
T List<T>::back(){
    return this->Back->data;
}

template <class T>
Node<T>::Node(T Data) {
    this->data = Data;
}