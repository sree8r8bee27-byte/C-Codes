template <typename T>
class MyVector {
    T* arr;
    int capacity;
    int current;

public:
    MyVector() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) temp[i] = arr[i];
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current++] = data;
    }

    T get(int index) { return arr[index]; }
    ~MyVector() { delete[] arr; }
};
