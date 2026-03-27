#include <iostream>

template <typename T>
class MyUniquePtr {
private:
    T* ptr;
public:
    explicit MyUniquePtr(T* p = nullptr) : ptr(p) {}
    
    // Destructor: Automatic memory cleanup
    ~MyUniquePtr() { delete ptr; }

    // Disable Copying (Unique ownership)
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // Enable Moving
    MyUniquePtr(MyUniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};

int main() {
    MyUniquePtr<int> p1(new int(42));
    std::cout << "Value: " << *p1 << std::endl;
    return 0;
}
