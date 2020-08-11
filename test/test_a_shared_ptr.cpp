#include "a_shared_ptr.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

namespace
{
    void char_deleter(char *i) noexcept
    {
        cout << "deleter!" << endl;
        delete i;
    }

    class TestSharedPtr : public testing::Test
    {
    private:
        a_shared_ptr<int> a;
        a_shared_ptr<char> b;

    protected:
        void SetUp() override
        {
            a = a_shared_ptr<int>(new int(100));
            b = a_shared_ptr<char>(new char('a'), &char_deleter);
        }
    };

    TEST(a_shared_ptr, constructor)
    {
        a_shared_ptr<int> a;
        EXPECT_EQ(nullptr, a.get());
        EXPECT_EQ(0, a.use_count());

        a_shared_ptr<char> b(new char('b'));
        EXPECT_NE(nullptr, b.get());
        EXPECT_EQ(1, b.use_count());

        a_shared_ptr<char> c(
            new char('c'), &char_deleter);
    }

    TEST(a_shared_ptr, copy_constructor)
    {
        a_shared_ptr<int> a(new int(100));
        EXPECT_EQ(100, *(a.get()));
        EXPECT_EQ(1, a.use_count());
        {

            a_shared_ptr<int> b(a);
            EXPECT_EQ(a.get(), b.get());
            EXPECT_EQ(2, b.use_count());
            {
                a_shared_ptr<int> c(b);
                EXPECT_EQ(c.get(), a.get());
                EXPECT_EQ(3, a.use_count());
                EXPECT_EQ(3, b.use_count());
                EXPECT_EQ(3, c.use_count());
            }
            EXPECT_EQ(2, a.use_count());
            EXPECT_EQ(2, b.use_count());
        }
        EXPECT_EQ(1, a.use_count());
    }

    TEST(a_shared_ptr, operator_assignment)
    {
        a_shared_ptr<int> a(new int(100));
        a_shared_ptr<int> b = a;
        EXPECT_EQ(a.get(), b.get());
        EXPECT_EQ(2, a.use_count());
        EXPECT_EQ(2, b.use_count());

        // self assigned.
        a_shared_ptr<int> &ref = a;
        a = ref;
        EXPECT_EQ(2, a.use_count());
    }
    class A
    {
    public:
        int a = 100;
    };

    TEST(a_shared_ptr, operator_right_arrow)
    {

        a_shared_ptr<A> a(new A());
        EXPECT_EQ(100, a->a);
    }

    TEST(a_shared_ptr, operator_star)
    {

        a_shared_ptr<int> a(new int(100));
        EXPECT_EQ(100, *a);
    }

    TEST(a_shared_ptr, reset)
    {
        a_shared_ptr<int> a(new int(100));
        a.reset();
        EXPECT_EQ(nullptr, a.get());

        a_shared_ptr<int> b(new int(200));
        a_shared_ptr<int> c(b);
        EXPECT_EQ(2, c.use_count());
        b.reset();
        EXPECT_EQ(200, *c);
        EXPECT_EQ(1, c.use_count());
    }

    TEST(a_shared_ptr, reset_with_arg)
    {
        int *i = new int(100);
        a_shared_ptr<int> a(new int(200));
        EXPECT_EQ(200, *a);
        a.reset(i);
        EXPECT_EQ(100, *a);
    }

    TEST(a_shared_ptr, get)
    {
        a_shared_ptr<int> a(new int(100));
        EXPECT_EQ(100, *(a.get()));
    }

    TEST(a_shared_ptr, swap)
    {
        a_shared_ptr<int> a(new int(100));

        a_shared_ptr<int> b(a);
        a_shared_ptr<int> c(new int(200));
        EXPECT_EQ(100, *b);
        EXPECT_EQ(2, b.use_count());
        EXPECT_EQ(200, *c);
        EXPECT_EQ(1, c.use_count());
        b.swap(c);

        EXPECT_EQ(200, *b);
        EXPECT_EQ(1, b.use_count());
        EXPECT_EQ(100, *c);
        EXPECT_EQ(2, c.use_count());
    }

    TEST(a_shared_ptr, use_count)
    {
        a_shared_ptr<int> a(new int(100));
        EXPECT_EQ(1, a.use_count());
    }
} // namespace
