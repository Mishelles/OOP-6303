#include <assert.h>
#include <algorithm> // std::copy, std::rotate
#include <cstddef> // size_t
#include <initializer_list>
#include <stdexcept>

namespace stepik
{
  template <typename Type>
  class vector
  {
  public:
    typedef Type* iterator;
    typedef const Type* const_iterator;

    typedef Type value_type;

    typedef value_type& reference;
    typedef const value_type& const_reference;

    typedef std::ptrdiff_t difference_type;

    explicit vector(size_t count = 0)
          : m_first(count ? new value_type[count]() : nullptr)
          , m_last(count ? &m_first[count] : nullptr)
    {
        for(size_t i = 0; i < count; i++)
        {
            m_first[i] = 0;
        }
    }

    template <typename InputIterator>
    vector(InputIterator first, InputIterator last)
    {
        difference_type size = last - first;
        m_first = new value_type[size];
        m_last = &m_first[size];

        m_first[0] = *first;
        InputIterator ptr = first;

        for(size_t i = 1; i < size; i++)
        {
            m_first[i] = *(++ptr);
        }
    }

    vector(std::initializer_list<Type> init)
        : m_first(init.size() ? new value_type[init.size()] : nullptr)
        , m_last(init.size() ? &m_first[init.size()] : m_first)
    {
      int i = 0;
      for(auto it = init.begin(); it != init.end(); ++it)
      {
          m_first[i] = *it;
          i++;
      }
    }

    vector(const vector& other)
        : m_first(other.size() ? new value_type[other.size()] : nullptr)
        , m_last(other.size() ? &m_first[other.size()] : nullptr)
    {
      for (size_t i = 0; i < other.size(); i++)
      {
          m_first[i] = other[i];
      }
    }

    vector(vector&& other)
        : m_first(other.m_first)
        , m_last(other.m_last)
    {
      other.m_first = nullptr;
      other.m_last = nullptr;
    }

    ~vector()
    {
       delete [] m_first;
    }

    //insert methods
    iterator insert(const_iterator pos, const Type& value)
    {
       difference_type delta = pos - m_first;
       push_back(value);
       std::rotate(m_first + delta, m_last - 1, m_last);

       return &m_first[delta];
    }

    template <typename InputIterator>
    iterator insert(const_iterator pos, InputIterator first, InputIterator last)
    {
        difference_type keep_size = this->size();
        difference_type delta = pos - m_first;
        difference_type insert_size = last - first;
        this->resize(keep_size + insert_size);
        std::copy(first, last, m_first + keep_size);

        std::rotate(m_first + delta, m_last - (last - first), m_last);

        return &m_first[delta];
    }

    //push_back methods
    void push_back(const value_type& value)
    {
        this->resize(this->size() + 1);
        *(m_last - 1) = value;
    }

    // resize methods
    void resize(size_t count)
    {
        iterator tmp = new value_type[count];
        std::copy(m_first, (this->size() > count) ? &m_first[count] : m_last, tmp);

        if(m_first) delete [] m_first;

        m_first = tmp;
        m_last = &m_first[count];
    }

    //erase methods
    iterator erase(const_iterator pos)
    {
        if((pos < m_first) || pos >= m_last) {
            throw std::out_of_range("Pos is out of range");
        }

        difference_type delta = pos - m_first;
        std::rotate(m_first + delta, m_first + delta + 1, m_last);

        this->resize(m_last - m_first - 1);

        return &m_first[delta];
    }

    iterator erase(const_iterator first, const_iterator last)
    {
        if ((first < m_first) || (first > m_last) || (last < m_first) || (last > m_last) ) {
            throw std::out_of_range("out of range");
        }

        difference_type delta = first - m_first;
        difference_type len = last - first;
        std::rotate(m_first + delta, m_first + delta + len, m_last);

        this->resize(m_last - m_first - len);

        return &m_first[delta];
    }


    //assignment operators
    vector& operator=(const vector& other)
    {
        iterator keep_first = m_first;
        iterator keep_last = m_last;

        if(this != &other) {
            try {
                vector* new_vector = new vector(other);
                m_first = new_vector->m_first;
                m_last = new_vector->m_last;
                delete [] keep_first;
            }
            catch(...) {
                m_first = keep_first;
                m_last = keep_last;
                throw;
            }
        }

        return *this;
    }

    vector& operator=(vector&& other)
    {
        if (this != &other) {
            delete [] m_first;
            m_first = other.m_first;
            m_last = other.m_last;
            other.m_first = nullptr;
            other.m_last = nullptr;
        }

        return *this;
    }

    // assign method
    template <typename InputIterator>
    void assign(InputIterator first, InputIterator last)
    {
        if (m_first) {
            delete [] m_first;
            m_first = nullptr;
            m_last = nullptr;
        }

        difference_type size = last - first;

        try {
            m_first = new value_type[size];
            m_last = m_first[size];
        }
        catch(...) {
            throw;
        }

        for(iterator it = this->begin(); it != this->end(); ++it) {
            *it = *first;
            ++first;
        }
    }

    //at methods
    reference at(size_t pos)
    {
      return checkIndexAndGet(pos);
    }

    const_reference at(size_t pos) const
    {
      return checkIndexAndGet(pos);
    }

    //[] operators
    reference operator[](size_t pos)
    {
      return m_first[pos];
    }

    const_reference operator[](size_t pos) const
    {
      return m_first[pos];
    }

    //*begin methods
    iterator begin()
    {
      return m_first;
    }

    const_iterator begin() const
    {
      return m_first;
    }

    //*end methods
    iterator end()
    {
      return m_last;
    }

    const_iterator end() const
    {
      return m_last;
    }

    //size method
    size_t size() const
    {
      return m_last - m_first;
    }

    //empty method
    bool empty() const
    {
      return m_first == m_last;
    }

  private:
    reference checkIndexAndGet(size_t pos) const
    {
      if (pos >= size())
      {
        throw std::out_of_range("out of range");
      }

      return m_first[pos];
    }

    //your private functions

  private:
    iterator m_first;
    iterator m_last;
  };
}// namespace stepik
