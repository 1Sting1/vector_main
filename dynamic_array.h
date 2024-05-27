#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
using namespace std;

class ArrayIndexOutOfBoundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds!";
    }
};

class DynamicArray {
private:
    int* data_;
    int size_;
    int capacity_;
    static const int default_capacity;
    static const int max_capacity;

public:
    explicit DynamicArray(int initial_capacity = default_capacity);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    bool operator==(const DynamicArray& other) const;
    bool operator!=(const DynamicArray& other) const;
    int& operator[](int index);

    int size() const;
    int capacity() const;
    bool isEmpty() const;
    void clear();
    void ensureCapacity(int min_capacity);
    void append(int value);
    void removeAt(int index);
    void reserve(int new_capacity);

    friend ostream& operator<<(ostream& out, const DynamicArray& array);
};

#endif
