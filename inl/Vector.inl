template<class T>
inline Vector<T>::Vector()
{
    s = 0;
    capacity = 1;
    storage = std::make_unique<T[]>(capacity);
}

template<class T>
inline Vector<T>::Vector(const T tab[], const int s) : s(s), capacity(s)
{
    storage = std::make_unique<T[]>(capacity);
    for (int i = 0; i < s; i++)
    {
        storage[i] = tab[i];
    }
}

template<class T>
inline void Vector<T>::adjust()
{
    if (s >= capacity)
    {
        capacity *= 2;
        std::unique_ptr<T[]> newStorage = std::make_unique<T[]>(capacity);
        for (int i = 0; i < s; i++)
        {
            newStorage[i] = storage[i];
        }
        storage = std::move(newStorage);
    }
}

template<class T>
inline T& Vector<T>::pop()
{
    if (s <= 0)
    {
        throw std::out_of_range("Vector vide");
    }
    s--;
    return storage[s-1];


}

template<class T>
inline bool Vector<T>::push(const T& t)
{
    if (s == 0 && capacity == 1)
    {
        storage[0] = t;
        s++;
        return true;
    }
    adjust();
    storage[s] = t;
    s++;
    return true;
}

template<class T>
inline bool Vector<T>::isEmpty() const
{
    return s == 0;
}

template<class T>
inline void Vector<T>::print() const
{
    for (int i = 0; i < s; i++)
    {
        std::cout << storage[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
inline T& Vector<T>::get_i(const int index) const
{
    if (index < 0 || index >= s)
    {
        throw std::out_of_range("Index hors limites");
    }
    return storage[index];
}

template<class T>
inline T& Vector<T>::operator[](int index)
{
    return get_i(index);
}

template<class T>
inline int Vector<T>::find(const T& t) const
{
    for (int i = 0; i < s; i++)
    {
        if (storage[i] == t)
        {
            return i;
        }
    }
    return -1;
}

template<class T>
inline bool Vector<T>::contains(const T& y) const
{
    return find(y) != -1;
}

template<class T>
inline int Vector<T>::size() const
{
    return s;
}

template<class T>
inline Vector<T>::Vector(const Vector& other) : s(other.s), capacity(other.capacity)
{
    storage = std::make_unique<T[]>(capacity);
    for (int i = 0; i < s; i++)
    {
        storage[i] = other.storage[i];
    }
}
