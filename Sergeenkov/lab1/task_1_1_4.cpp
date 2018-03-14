#include <assert.h>
#include <algorithm> // std::copy
#include <cstddef> // size_t
#include <iostream>

template<typename T>
class Array
{
public:
  // (default) constructor
  Array(const size_t size = 0)
    : m_size(size)
    , m_array(m_size ? new T[m_size]() : nullptr)
  {
  }

  // Конструктор копирования
  Array(const Array& arr)
    : m_size(arr.size())
    , m_array(new T[m_size]())
  {
    try
    {
        for(int i = 0; i < m_size; i++)
        {
            m_array[i] = arr[i];
        }
    }
    catch(...)
    {
        delete [] m_array;
        throw;
    }

  }

  // Конструктор перемещения
  Array(Array&& arr)
      : m_size(arr.size())
      , m_array(arr.m_size)
  {
    arr.m_size = 0;
    arr.m_array = nullptr;
  }

  const size_t size() const
  {
    return m_size;
  }

  T& operator [](const size_t index) const
  {
    assert(index < m_size);

    return m_array[index];
  }

  // Оператор присваивания
  Array& operator =(Array const &arr)
  {
      // защита от присваивания самому себе
      if (this != &arr)
      {
          try
          {
              Array* new_arr = new Array(arr);
              m_size = new_arr->size();
              m_array = new_arr->m_array;
          }
          catch(...)
          {
              throw;
          }
      }

      return *this;
  }


  // Деструктор
  ~Array()
  {
      delete [] m_array;
  }
private:
  size_t m_size;
  T* m_array;
};
