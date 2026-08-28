#include <iostream>
#include <list>

using namespace std;

template<typename E>
class MyLinkedQueue {
    private:
        list<E> qlist;

    public:
        void push(const E &e) {
            qlist.push_back(e);
        }

        E pop() {
            E front = qlist.front();
            qlist.pop_front();
            return front;
        }

        E peek() {
            return qlist.front();
        }

        int size() {
            return qlist.size();
        }
};

int main() {
    MyLinkedQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << queue.peek() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.peek() << endl;

    return 0;
}
