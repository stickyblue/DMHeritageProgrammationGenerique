template <class T>

inline PriorityQueue<T>::PriorityQueue() : s(0)
{
    storage = Vector<T>();
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


