#pragma once

#include <iostream>
#include "Vector.h"

template <typename T>
class PriorityQueue
{
    public:
        virtual ~PriorityQueue() = default;
        void shiftUp(const int i);
        void shiftDown();
        T pop();
        bool push(const T& t);
        bool isEmpty() const;
        int size() const;
        void print() const;
        PriorityQueue();

        // Ajout de fonctions static d'après l'aide:

        static int getFilsGauche(int father);
        static int getFilsDroit(int father);
        static int getFather(int son);

        
    private:
        int s;
        Vector<T> storage;
};

#include "../inl/PriorityQueue.inl"
