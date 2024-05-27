#include "dynamic_array.h"

const int DynamicArray::default_capacity = 10;
const int DynamicArray::max_capacity = 100000;

DynamicArray::DynamicArray(int initial_capacity) {
    capacity_ = (initial_capacity > 0 && initial_capacity < max_capacity) ? initial_capacity : default_capacity;
    data_ = new int[capacity_];
    size_ = 0;
}

DynamicArray::~DynamicArray() {
    delete[] data_;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = new int[capacity_];
    for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] data_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

bool DynamicArray::operator==(const DynamicArray& other) const {
    if (size_ != other.size_) return false;
    for (int i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i]) return false;
    }
    return true;
}

bool DynamicArray::operator!=(const DynamicArray& other) const {
    return !(*this == other);
}

int& DynamicArray::operator[](int index) {
    if (index < 0 || index >= size_) throw ArrayIndexOutOfBoundsException();
    return data_[index];
}

int DynamicArray::size() const {
    return size_;
}

int DynamicArray::capacity() const {
    return capacity_;
}

bool DynamicArray::isEmpty() const {
    return size_ == 0;
}

void DynamicArray::clear() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

void DynamicArray::ensureCapacity(int min_capacity) {
    if (min_capacity > capacity_) {
        capacity_ = (min_capacity > 2 * capacity_) ? min_capacity : 2 * capacity_;
        int* new_data = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
    }
}

void DynamicArray::append(int value) {
    if (size_ == capacity_) ensureCapacity(size_ + 1);
    data_[size_++] = value;
}

void DynamicArray::removeAt(int index) {
    if (index < 0 || index >= size_) throw ArrayIndexOutOfBoundsException();
    for (int i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }
    size_--;
}

void DynamicArray::reserve(int new_capacity) {
    if (new_capacity > capacity_) ensureCapacity(new_capacity);
}

ostream& operator<<(ostream& out, const DynamicArray& array) {
    out << "Total size: " << array.size_ << endl;
    for (int i = 0; i < array.size_; ++i) {
        out << array.data_[i] << endl;
    }
    return out;
}
