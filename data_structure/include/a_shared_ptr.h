#pragma once
/**
 *
 * 简单的shared_ptr的实现
 *
 */
#include <algorithm>
#include <stdio.h>

template <typename T>
class a_shared_ptr;

template <class T>
void swap(a_shared_ptr<T> &lhs, a_shared_ptr<T> &rhs) noexcept
{
    lhs.swap(rhs);
}

template <typename T>
class a_shared_ptr
{
    using DelFuncPtr = void (*)(T *) noexcept;

private:
    T *m_ptr_;               // 指向被管理资源
    size_t *count_ptr_;      // 指向计数器
    DelFuncPtr deleter_ptr_; // 指向删除函数
    void clear() noexcept
    {
        if (*count_ptr_ <= 1) // 准备释放工作
        {
            if (m_ptr_)
            {
                if (deleter_ptr_)
                    (*deleter_ptr_)(m_ptr_);
                else
                    delete m_ptr_;
            }

            delete count_ptr_;
            return;
        }
        // 自动减一
        --(*count_ptr_);
    }

public:
    a_shared_ptr()
        : m_ptr_(nullptr),
          count_ptr_(new size_t(0)),
          deleter_ptr_(nullptr) {}

    explicit a_shared_ptr(T *p, DelFuncPtr del = nullptr)
        : m_ptr_(p),
          deleter_ptr_(del)
    {
        if (m_ptr_ == nullptr)
            count_ptr_ = new size_t(0);
        else
            count_ptr_ = new size_t(1);
    }

    a_shared_ptr(const a_shared_ptr<T> &rhs)
        : m_ptr_(rhs.m_ptr_),
          count_ptr_(rhs.count_ptr_),
          deleter_ptr_(rhs.deleter_ptr_) // 拷贝构造
    {
        if (m_ptr_)
            ++(*count_ptr_);
    }

    ~a_shared_ptr()
    {
        clear();
    }

    a_shared_ptr<T> &operator=(const a_shared_ptr<T> &rhs) // 拷贝赋值
    {
        // 减一或直接释放当前资源
        clear();

        m_ptr_ = rhs.m_ptr_;
        count_ptr_ = rhs.count_ptr_;
        deleter_ptr_ = rhs.deleter_ptr_;
        if (m_ptr_)
            ++(*count_ptr_);
        return *this;
    }

    T *operator->() const noexcept { return m_ptr_; }

    T &operator*() const noexcept { return *m_ptr_; }

    explicit operator bool() const noexcept // 防止本对象到bool的隐式转换
    {
        return m_ptr_ != nullptr;
    }

    void reset() noexcept
    {
        a_shared_ptr<T>().swap(*this); // 交换后，退出函数作用域，自动减一或释放内存
    }

    void reset(T *p, DelFuncPtr del = nullptr)
    {
        a_shared_ptr<T>(p, del).swap(*this); // 交换后，本对象管理p资源，退出作用域后新对象自动减一或释放内存
    }

    T *get() const noexcept { return m_ptr_; }

    DelFuncPtr *get_deleter() const noexcept { return deleter_ptr_; }

    void swap(a_shared_ptr<T> &rhs) noexcept
    {
        using std::swap;
        swap(m_ptr_, rhs.m_ptr_);
        swap(count_ptr_, rhs.count_ptr_);
        swap(deleter_ptr_, rhs.deleter_ptr_);
    }

    long use_count() const noexcept
    {
        return (*count_ptr_);
    }
};
