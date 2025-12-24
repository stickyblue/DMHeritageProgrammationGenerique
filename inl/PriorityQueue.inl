template <class T>

inline PriorityQueue<T>::PriorityQueue() : s(0), storage()
{
}

template <class T>
inline int PriorityQueue<T>::getFilsGauche(int father)
{
    return 2 * father + 1;
}

template <class T>
inline int PriorityQueue<T>::getFilsDroit(int father)
{
    return 2 * father + 2;
}

template <class T>
inline int PriorityQueue<T>::getFather(int son)
{
    return (son - 1) / 2;
}

template <class T>
inline void PriorityQueue<T>::shiftUp(const int i)
{
    int currentIndex = i;
    while (currentIndex > 0)
    {
        int fatherIndex = getFather(currentIndex);
        if (storage[currentIndex] > storage[fatherIndex])
        {
            std::swap(storage[currentIndex], storage[fatherIndex]);
            currentIndex = fatherIndex;
        }
        else
        {
            break;
        }
    }
}

template <class T>
inline bool PriorityQueue<T>::push(const T& t)
{
    storage.push(t);
    s++;
    shiftUp(s - 1);
    return true;
}

template <class T>
inline void PriorityQueue<T>::shiftDown()
{
    int currentIndex = 0;
    while (true)
    {
        int leftChildIndex = getFilsGauche(currentIndex);
        int rightChildIndex = getFilsDroit(currentIndex);
        int largestIndex = currentIndex;
        if (leftChildIndex < s && storage[leftChildIndex] > storage[largestIndex])
        {
            largestIndex = leftChildIndex;
        }
        if (rightChildIndex < s && storage[rightChildIndex] > storage[largestIndex])
        {
            largestIndex = rightChildIndex;
        }
        if (largestIndex != currentIndex)
        {
            std::swap(storage[currentIndex], storage[largestIndex]);
            currentIndex = largestIndex;
        }
        else
        {
            break;
        }
    }

}

template <class T>
inline T PriorityQueue<T>::pop()
{
    if (s <= 0)
    {
        throw std::out_of_range("PriorityQueue vide");
    }
    T topElement = storage[0];
    storage[0] = storage.pop();
    s--;
    shiftDown();
    return topElement;
}

template <class T>
inline bool PriorityQueue<T>::isEmpty() const
{
    return s == 0;
}

template <class T>
inline int PriorityQueue<T>::size() const
{
    return s;
}

template <class T>
inline void PriorityQueue<T>::print() const
{
    storage.print();
}
