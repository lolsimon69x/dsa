#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class DArray {
	private:
		// main array
		T* data;

		// size of the array
		int size;

		// capacity of the array
		int cap;

		// default capacity of the array
		static const int INIT_CAP = 1;

	public:
		// Constructor
		DArray() {
			this->data = new T[INIT_CAP];
			this->size = 0;
			this->cap = INIT_CAP;
		}

		// paramaterized Constructor
		DArray(int initCapacity) {
			this->data = new T[initCapacity];
			this->size = 0;
			this->cap = initCapacity;
		}

		// add element to the array
		void add(int index, T element) {

			checkPositionIndex(index);

			// resize if reaching max capacity	
			if (size == cap) {
				resize(2 * cap);
			}

			// shifting array elements
			for (int i = size - 1; i >= index; i--) {
				data[i + 1] = data[i];
			}

			data[index] = element;

			size++;
		}

		// remove element from the array
		T remove(int index) {
			checkElementIndex(index);

			// shrink the array
			if (size == cap / 4) {
				resize(cap / 2);
			}

			T deleteVal = data[index];

			for (int i = index + 1; i < size; i++) {
				data[i - 1] = data[i];
			}

			data[size - 1] = T();

			size--;

			return deleteVal;
		}

		// resizing the array
		void resize(int newCap) {
			T* temp = new T[newCap];

			for (int i = 0; i < size; i++) {
				temp[i] = data[i];
			}

			// free memory
			delete[] data;

			data = temp;
			cap = newCap;
		}

		// get the element
		T get(int index) {
			checkElementIndex(index);
			return data[index];
		}

		// check if this index exists or not to access element
		void checkElementIndex(int index) {
			if (!(index >= 0 && index < size)) {
				throw std::out_of_range("Index out of bound");
			}
		}

		// check if its a valid position to insert an element
		void checkPositionIndex(int index) {
			if (!(index >= 0 && index <= size))
				throw std::out_of_range("Index out of bound");
		}
};

int main()
{
	DArray<int> array(3);

	for (int i = 0; i < 5; i++) {
		array.add(i, i);
	}

	std::cout << array.get(2) << std::endl;

	array.remove(2);
	std::cout << array.get(2) << std::endl;

	return 0;
}
