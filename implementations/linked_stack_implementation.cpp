// Implement a stack using linked list as the underlying data structure
#include <list>
#include <iostream>

template<typename E>
class MyLinkedStack {
private:
    std::list<E> list;

public:
    // Add an element to the top of the stack, time complexity O(1)
    void push(const E &e) {
        list.push_back(e);
    }

    // Pop an element from the top of the stack, time complexity O(1)
    E pop() {
        E value = list.back();
        list.pop_back();
        return value;
    }

    // Look at the element at the top of the stack, time complexity O(1)
    E peek() const {
        return list.back();
    }

    // Return the number of elements in the stack, time complexity O(1)
    int size() const {
        return list.size();
    }
};

int main() {
    MyLinkedStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    while (stack.size() > 0) {
        std::cout << stack.pop() << std::endl;
    }
    return 0;
}
