#include <iostream>
#include <stdexcept>
#include <vector>
#include <ostream>

template<typename T>
class CycleArray {
    vector<T> arr;
    int start;
    int end;
    int count;

    // helper function for automatic resizing
    void resize(int newSize) {
        // create a new array and copy elements
        vector<T> newArr(newSize);
        for (int i = 0; i < count; ++i) {
            newArr[i] = arr[(start + i) % arr.size()];
        }
        arr = move(newArr);
        // reset the start and end pointers
        start = 0;
        end = count;
    }

public:
    CycleArray() : CycleArray(1) {}

    explicit CycleArray(int size) 
        : arr(size), start(0), end(0), count(0) {}

    // add an element to the front of the array, time complexity O(1)
    void addFirst(const T &val) {
        // if the array is full, double its size
        if (isFull()) {
            resize(arr.size() * 2);
        }
        // since start is a closed interval, move left first, then assign
        start = (start - 1 + arr.size()) % arr.size();
        arr[start] = val;
        count++;
    }

    // remove an element from the front of the array, time complexity O(1)
    T removeFirst() {
        if (isEmpty()) {
            throw runtime_error("Array is empty");
        }
        // since start is a closed interval, assign first, then move right
        T val = arr[start];
        arr[start] = T();
        start = (start + 1) % arr.size();
        count--;
        // if the number of elements in the array decreases to a quarter
        // of the original size, halve the size of the array
        if (count > 0 && count == arr.size() / 4) {
            resize(arr.size() / 2);
        }
        return val;
    }

    // add an element to the end of the array, time complexity O(1)
    void addLast(const T &val) {
        if (isFull()) {
            resize(arr.size() * 2);
        }
        // since end is an open interval, assign first, then move right
        arr[end] = val;
        end = (end + 1) % arr.size();
        count++;
    }

    // remove an element from the end of the array, time complexity O(1)
    T removeLast() {
        if (isEmpty()) {
            throw runtime_error("Array is empty");
        }
        // since end is an open interval, move left first, then assign
        end = (end - 1 + arr.size()) % arr.size();
        T val = arr[end];
        arr[end] = T();
        count--;
        // reduce the size
        if (count > 0 && count == arr.size() / 4) {
            resize(arr.size() / 2);
        }
        return val;
    }

    // get the first element of the array, time complexity O(1)
    T getFirst() const {
        if (isEmpty()) {
            throw runtime_error("Array is empty");
        }
        return arr[start];
    }

    // get the last element of the array, time complexity O(1)
    T getLast() const {
        if (isEmpty()) {
            throw runtime_error("Array is empty");
        }
        // end is an open interval, pointing to the next element's position, so subtract 1
        return arr[(end - 1 + arr.size()) % arr.size()];
    }

    bool isFull() const {
        return count == arr.size();
    }
    
    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }
};
