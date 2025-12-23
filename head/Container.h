#pragma once


template <class T>
class Container
{
    public:
        T& pop();
        bool push(const T& t);
        bool isEmpty() const;
        int size() const;
        void print() const;
        virtual ~Container() = default;

    private:

        int s; //size
};
