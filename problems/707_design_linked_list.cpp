class Node {
	public:
		int value;
		Node* next;

		Node (int x){
			this->value = x;
			this->next = nullptr;
		}
};

class MyLinkedList {
private:
	Node* head;
	int size = 0;
public:
	MyLinkedList(){
		head = new Node(0);
		size = 0;
	}

	bool validIndex(int index) {
		if (index >= 0 && index < size) {
			return 1;
		}
		else
			return 0;
	}
    	int get(int index) {
		if (!(validIndex(index))) {
			return -1;
		}

	    	Node* p = head;
	    	for (int i = 0; i < index; i++) {
		    	p = p->next;
	    	}

	    	return p->next->value;
    	}
    
    	void addAtHead(int val) {
	    	Node* toBeAdded = new Node(val);

	    	toBeAdded->next = head->next;

	    	head->next = toBeAdded;
	    	size++;
    	}
    
    	void addAtTail(int val) {
	    	Node* toBeAdded = new Node(val);

	    	Node* p = head;
	    	while (p->next != nullptr) {
		    	p = p->next;
	    	}

	    	p->next = toBeAdded;
	    	size++;
    	}
    
    	void addAtIndex(int index, int val) {

	    	Node* toBeAdded = new Node(val);

	    	Node* p = head;
	    	for (int i = 0; i < index; i++) {
		    	p = p->next;
	    	}

	    	toBeAdded->next = p->next;
	    	p->next = toBeAdded;
	    	size++;
    	}
    
    	void deleteAtIndex(int index) {
		if (!validIndex(index)) {
			return;
		}

	    	Node* toBeDeleted;
		Node* p = head;
		if (index == 0) {
			toBeDeleted = head->next;
			head->next = toBeDeleted->next;
			toBeDeleted->next = nullptr;
			delete toBeDeleted;
		} else if (index == size - 1) {
			while (p->next->next != nullptr) {
				p = p->next;
			}
			toBeDeleted = p->next;
			p->next = nullptr;
			delete toBeDeleted;
		} else {
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
			toBeDeleted = p->next;
			p->next = toBeDeleted->next;
			toBeDeleted->next = nullptr;
			delete toBeDeleted;
		}
		size--;

    	}


};
