#pragma once
#include <stdio.h>
#include "Container.h"
#include <memory>
#include <iostream>

template <class T>
class Vector
{
    public:
        virtual ~Vector() = default;
        void adjust();
        T& get_i(const int index) const;
        T& pop();
        bool push(const T& t);
        bool isEmpty() const;
        int size() const;
        void print() const;
        T& operator[](int index);
        int find(const T& t) const;
        bool contains(const T& y) const;
        Vector();
        Vector(const T tab[], const int s);
        Vector(const Vector& other);
    private:
        int s; //size
        int capacity;
        std::unique_ptr<T[]> storage;
};

#include "../inl/Vector.inl"
