#include <assert.h>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <utility>

namespace stepik
{
  template <class Type>
  class list
  {
  public:
    typedef Type value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
  private:
      template<class T>
      struct node
      {
        T value;
        node* next;
        node* prev;

        node(const T& value, node<T>* next, node<T>* prev)
          : value(value), next(next), prev(prev)
        {
        }
      };
   public:

      template <class T>
      class list_iterator
      {
      public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef size_t size_type;
        typedef std::forward_iterator_tag iterator_category;

        list_iterator()
          : m_node(NULL)
        {
        }

        list_iterator(node<T>* p)
          : m_node(p)
        {
        }

        list_iterator(const list_iterator& other)
          : m_node(other.m_node)
        {
        }

        list_iterator& operator = (const list_iterator& other)
        {
            m_node = other.m_node;
            return *this;
        }

        bool operator == (const list_iterator& other) const
        {
            return (m_node == other.m_node);
        }

        bool operator != (const list_iterator& other) const
        {
            return (m_node != other.m_node);
        }

        reference operator * ()
        {
            return m_node->value;
        }

        pointer operator -> ()
        {
            return &m_node->value;
        }

        list_iterator& operator ++ ()
        {
            m_node = m_node->next;
            return *this;
        }

        list_iterator operator ++ (int)
        {
            m_node = m_node->next;
            return *this;
        }

      private:

        node<T>* m_node;
      };

    typedef list_iterator<Type> iterator;

    list()
      : m_head(nullptr), m_tail(nullptr)
    {
    }

    ~list()
    {
        this->clear();
    }

    iterator begin()
    {
      return iterator(m_head);
    }

    iterator end()
    {
      return iterator();
    }

    list(const list& other)
    {
        list* new_list = new list();
        for(node<value_type>* ptr = other.m_head; ptr != nullptr; ptr = ptr->next) {
            new_list->push_back(ptr->value);
        }
        m_head = new_list->m_head;
        m_tail = new_list->m_tail;
    }

    list(list&& other)
        : m_head(other.m_head)
        , m_tail(other.m_tail)
    {
        other.m_head = nullptr;
        other.m_tail = nullptr;
    }

    list& operator= (const list& other)
    {
        if(this != &other) {
            this->clear();
            list* new_list = new list(other);
            m_head = new_list->m_head;
            m_tail = new_list->m_tail;
        }

        return *this;
    }

    void push_back(const value_type& value)
    {
        node<value_type>* new_node = new node<value_type>(value, nullptr, m_tail);
        if(m_tail) m_tail->next = new_node;
        m_tail = new_node;
        if(!m_head) m_head = new_node;
    }

    iterator insert(iterator pos, const Type& value)
    {
        node<value_type>* new_node = new node<value_type>(value, pos.m_node, pos.m_node->prev);
        if(this->begin() == pos) {
            m_head = new_node;
        } else {
            pos.m_node->prev->next = new_node;
        }
        pos.m_node->prev = new_node;

        pos.m_node = new_node;

        return pos;
    }

    iterator erase(iterator pos)
    {
       if(pos.m_node) {
           if(pos.m_node == m_head) {
               this->pop_front();
               pos.m_node = m_head;
           } else if(pos.m_node == m_tail) {
               this->pop_back();
               pos = this->end();
           } else {
               pos.m_node->prev->next = pos.m_node->next;
               pos.m_node->next->prev = pos.m_node->prev;
               node<value_type>* delete_node = pos.m_node;
               pos.m_node = pos.m_node->next;
               delete delete_node;
           }
           return pos;
       }

        return this->end();
    }

    void push_front(const value_type& value)
    {
        node<value_type>* new_node = new node<value_type>(value, m_head, nullptr);
        if(m_head) m_head->prev = new_node;
        m_head = new_node;
        if(!m_tail) m_tail = new_node;
    }

    reference front()
    {
        return m_head->value;
    }

    const_reference front() const
    {
        return m_head->value;
    }

    reference back()
    {
        return m_tail->value;
    }

    const_reference back() const
    {
        return m_tail->value;
    }

    void pop_front()
    {
        if(m_head) {
            node<value_type>* next_node = m_head->next;
            delete m_head;
            m_head = next_node;
            if(m_head) {
                m_head->prev = nullptr;
            } else {
                m_tail = nullptr;
            }
        }
    }

    void pop_back()
    {
        if(m_tail) {
            node<value_type>* prev_node = m_tail->prev;
            delete m_tail;
            m_tail = prev_node;
            if(m_tail) {
                m_tail->next = nullptr;
            } else {
                m_head = nullptr;
            }
        }
    }

    void clear()
    {
        node<value_type>* ptr = m_head;

        while(ptr) {
            node<value_type>* node_to_delete = ptr;
            ptr = ptr->next;
            delete node_to_delete;
        }
    }

    bool empty() const
    {
      return (m_head == nullptr);
    }

    size_t size() const
    {
        size_t count = 0;

        for (node<value_type>* ptr = m_head; ptr != nullptr; ptr = ptr->next) {
            ++count;
        }

        return count;
    }

  private:
    //your private functions

    node<Type>* m_head;
    node<Type>* m_tail;
  };

}// namespace stepik
