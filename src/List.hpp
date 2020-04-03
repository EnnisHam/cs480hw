/*
 * Template class that will be used to hold pointers to things
 * Sorted array list, depends on operator< existing for the type being held
 */

#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

typedef unsigned int uint;

// Any necessary includes
#include <stdexcept>
#include <utility>
#include <iostream>

// It's a template class
template <typename T>
class List {
public:
    // Default Constructor
    List();
    List(const T& object);
    List(T&& rObject);
    // Copy Constructor
    List(const List& lval);
    // Move Constructor
    List(List&& rval);
    // Destructor
    ~List();

    // Accessors
    const uint size() noexcept { return _size; };
    const uint capacity() noexcept { return _capacity; };
    T& at(uint index);
    const T at(uint index) const;

    const int search(const T& object);

    // Copy assignment operator overload
    const List& operator =(const List<T>& lval);
    // Move assignment operator overload
    const List& operator =(List<T>&& rval);

    // Mutators
    void erase(const T& object);
    void stretch(const uint& delta);
    void insert(const T& object) noexcept;
    void insert(T&& rObject) noexcept;
    void sort(); //Michael Buble sort

private:
    // variable that gives us our dynamic array
    uint _size;
    uint _capacity;
    T *_arr;
};

// LIST CLASS FUNCTION IMPLEMENTATIONS
template <typename T>
List<T>::List():
    _size(0),
    _capacity(0),
    _arr(nullptr)
{}

template <typename T>
List<T>::List(const T& object):
    _size(1),
    _capacity(1)
{
    _arr = new T[_size];
    _arr[0] = object;
}

template <typename T>
List<T>::List(T&& rObject):
    _size(1),
    _capacity(1)
{
    _arr = new T[_size];
    _arr[0] = rObject;
}

template <typename T>
List<T>::List(const List& lval):
    _size(lval._size),
    _capacity(lval._size),
    _arr(nullptr)
{
    _arr = new T[_capacity];
    
    for(uint i = 0; i < lval._size; ++i)
        _arr[i] = lval._arr[i];
}

template <typename T>
const List<T>& List<T>::operator =(const List<T>& lval) 
{
    if(_arr == lval._arr)
        return *this;
    else
    {
        _size = lval._size;
        _capacity = lval._size;
        _arr = new T[_capacity];

        for(uint i = 0; i < lval._size; ++i)
            _arr[i] = lval._arr[i];
        return *this;
    }
}

template <typename T>
List<T>::List(List&& rval):
    _size(rval._size),
    _capacity(rval._capacity),
    _arr(rval._arr)
{
    if(rval._arr != nullptr)
        rval._arr = nullptr;
}

template <typename T>
const List<T>& List<T>::operator =(List<T>&& rval)
{
    if(_arr == rval._arr)
        return *this;
    else
    {
        if(_arr != nullptr)
            delete[] _arr;
        _size = rval._size;
        _capacity = rval._capacity;
      
        _arr = rval._arr;
        rval._arr = nullptr;
        return *this;
    }
}

template <typename T>
List<T>::~List()
{
    if(_arr != nullptr)
        delete[] _arr;
};

template <typename T>
T& List<T>::at(uint index)
{
    if(index >= _size || index < 0)
        throw std::out_of_range("out of bounds");
    return _arr[index];
}

template <typename T>
const T List<T>::at(uint index) const
{
    if(index >= _size || index < 0)
        throw std::out_of_range("out of bounds");
    return _arr[index];
}

template <typename T>
void List<T>::stretch(const uint& delta)
{
    T* temp;
    _capacity = delta;
    temp = _arr;
    _arr = new T[_capacity];
    for(uint i = 0; i < _capacity; i++)
    {
        if(i < _size)
            _arr[i] = temp[i];
    }
    delete[] temp;
}

template <typename T>
void List<T>::insert(const T& object) noexcept
{
    if(_capacity == 0)
        stretch(1);
    if((_size == _capacity) && (_size != 0))
        stretch(_capacity*2);
    _arr[_size++] = object;
    sort();
}

template <typename T>
void List<T>::insert(T&& rObject) noexcept
{
    if(_capacity == 0)
        stretch(1);
    if((_size == _capacity) && (_size != 0))
        stretch(_capacity*2);
    _arr[_size++] = rObject;
    sort();

}

template <typename T>
void List<T>::erase(const T& object)
{
    uint index;

    if(_arr == nullptr)
        throw std::underflow_error("list does not exist");
    if(_size == 0 && _capacity != 0)
        throw std::out_of_range("can't erase an empty list\n");
    
    try
    {
        index = search(object);
    }
    catch(std::domain_error &jalopnik)
    {
        throw std::range_error("Object not found");
        return;
    }
    std::swap(_arr[index], _arr[_size-1]);
    _size--;
    sort();
}

template <typename T>
const int List<T>::search(const T& object)
{
    for(uint i = 0; i < _size; ++i)
    {
        if(_arr[i] == object)
            return i;
    }
    throw std::domain_error("item not found\n");
}

template <typename T>
void List<T>::sort()
{
    // T temp;
    bool tachanka; // tachanka is used as a break flag for when the
                   // list is sorted
    for(uint i = 0; i < _size; i++)
    {
        tachanka = false;
        for(uint j = 1; j < _size; j++)
        {
            if(*_arr[j-1] > *_arr[j])
            {
                std::swap(_arr[j], _arr[j-1]);
                tachanka = true;
            }
        }
        if(!tachanka)
            break;
    }
}
#endif
