#include <iostream>
#include <memory>

#include <typeinfo>
namespace stepik
{
  template <typename T>
  class shared_ptr
  {
  public:
    explicit shared_ptr(T *ptr = 0)
          : m_object(ptr)
          , m_ref_count(ptr ? new long(1) : 0)
    {

    }

    ~shared_ptr()
    {
          release();
    }

    shared_ptr(const shared_ptr & other)
    {
        m_object = other.get();
        if(other.m_ref_count) ++(*other.m_ref_count);
        m_ref_count = other.m_ref_count;
    }

    template <typename Y>
    shared_ptr(shared_ptr<Y> & other)
    {
        try {
            m_object = dynamic_cast<T*>(other.get());
        } catch(std::bad_cast &ex) {
            throw ex;
        }
        m_ref_count = other.count_ptr();
        if (m_ref_count) {
            (*m_ref_count)++;
        }
    }

    shared_ptr& operator=(const shared_ptr & other)
    {
        if(this != &other) {
            release();
            m_object = other.get();
            if(other.m_ref_count) ++(*other.m_ref_count);
            *m_ref_count = other.use_count();
        }
        return *this;
    }

    template<typename Y>
    shared_ptr& operator=(const shared_ptr<Y> &other)
    {
        this->release();
        try {
            m_object = dynamic_cast<T*>(other.get());
        } catch(std::bad_cast &ex) {
            throw ex;
        }
        m_ref_count = other.count_ptr();
        if (m_ref_count) {
            (*m_ref_count)++;
        }

        return *this;
    }

    explicit operator bool() const
    {
        return m_object != nullptr;
    }

    T* get() const
    {
        return m_object;
    }

    long use_count() const
    {
        return m_ref_count ? *m_ref_count : 0;
    }

    long* count_ptr() const
    {
        return m_ref_count;
    }


    T& operator*() const
    {
        return *m_object;
    }

    T* operator->() const
    {
        return m_object;
    }

    void swap(shared_ptr& x) noexcept
    {
        T* tmp_object = m_object;
        long *tmp_count = m_ref_count;
        m_object = x.m_object;
        m_ref_count = x.m_ref_count;
        x.m_object = tmp_object;
        x.m_ref_count = tmp_count;
    }

    void reset(T *ptr = 0)
    {
        release();
        m_object = ptr;
        m_ref_count = ptr ? new long(1) : 0;

    }

  private:
    void release()
    {
        if(m_ref_count) {
            if(--(*m_ref_count) == 0) {
                delete m_object;
                delete m_ref_count;
            }
        }
    }

    T* m_object;
    long* m_ref_count;
  };

  // compare operators
  template <class T, class U>
  bool operator==(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs)
  {
        return lhs.get() == rhs.get();
  }

  template <class T, class U>
  bool operator!=(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs)
  {
        return !(lhs == rhs);
  }

  template <class T, class U>
  bool operator<(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs)
  {
        return std::less<T*>()(lhs.get(), rhs.get());
  }

  template <class T, class U>
  bool operator>(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs)
  {
        return !(rhs < lhs);
  }

  template <class T, class U>
  bool operator<=(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs)
  {
        return !(lhs < rhs);
  }

  template <class T, class U>
  bool operator>=(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs)
  {
        return !lhs;
  }

  template <class T>
  bool operator==(const shared_ptr<T>& lhs, std::nullptr_t rhs)
  {
        return !rhs;
  }

  template <class T>
  bool operator==(std::nullptr_t lhs, const shared_ptr<T>& rhs)
  {
        return (bool)lhs;
  }

  template <class T>
  bool operator!=(const shared_ptr<T>& lhs, std::nullptr_t rhs)
  {
        return lhs.get() != rhs;
  }

  template <class T>
  bool operator!=(std::nullptr_t lhs, const shared_ptr<T>& rhs)
  {
        return (bool)rhs;
  }

  template <class T>
  bool operator<(const shared_ptr<T>& lhs, std::nullptr_t rhs)
  {
        return std::less<T*>()(lhs.get(), nullptr);
  }

  template <class T>
  bool operator<(std::nullptr_t lhs, const shared_ptr<T>& rhs)
  {
        return std::less<T*>()(nullptr, rhs.get());
  }

  template <class T>
  bool operator<=(const shared_ptr<T>& lhs, std::nullptr_t rhs)
  {
        return nullptr < lhs;
  }

  template <class T>
  bool operator<=(std::nullptr_t lhs, const shared_ptr<T>& rhs)
  {
        return rhs < nullptr;
  }

  template <class T>
  bool operator>(const shared_ptr<T>& lhs, std::nullptr_t rhs)
  {
        return !(nullptr < lhs);
  }

  template <class T>
  bool operator>(std::nullptr_t lhs, const shared_ptr<T>& rhs)
  {
        return !(rhs < nullptr);
  }

  template <class T>
  bool operator>=(const shared_ptr<T>& lhs, std::nullptr_t rhs)
  {
        return !(lhs < nullptr);
  }

  template <class T>
  bool operator>=(std::nullptr_t lhs, const shared_ptr<T>& rhs)
  {
        return !(nullptr < rhs);
  }
} // namespace stepik

// Test polymorphic objects
class A {
public:
    A() {
        std::cout << "Object A created" << std::endl;
    }
    void whoAmI() {
        std::cout << "I am object A" << std::endl;
    }
};

class B :public A {
public:
    B() {
        std::cout << "Object B created" << std::endl;
    }
    void whoAmI() {
        std::cout << "I am object B" << std::endl;
    }
};

int main()
{
    stepik::shared_ptr<A> a_ptr(new A());
    stepik::shared_ptr<A> b_ptr(new B());
    return 0;
}
