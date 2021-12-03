
#include "test_class.h"

//#define test_copy_elision

test_class::test_class(const int val)
    : m_some_int(val)
{
}

test_class::test_class()
{
}

test_class::~test_class()
{
}

auto test_class::create_using_shared_ptr(const int val) -> test_class_ptr
{
#ifdef test_copy_elision
    auto ptr = test_class_ptr(new test_class(val));
    return ptr;
#else
    return test_class_ptr(new test_class(val));
#endif
}


auto test_class::create_using_custom(const int val) -> test_class_ptr
{
#ifdef test_copy_elision
    test_class_ptr a = test_class_ptr(test_class_ptr(), new test_class(val));
    return a;
#else
    return test_class_ptr(test_class_ptr(), new test_class(val));
#endif
}


auto test_class::create_using_make_shared(const int val) -> test_class_ptr
{
#ifdef test_copy_elision
    auto ptr = std::make_shared<test_class>(val);
    return ptr;
#else
    return std::make_shared<test_class>(val);
#endif
}


auto test_class::create_using_allocator(const int val) -> test_class_ptr
{
#ifdef test_copy_elision
    std::allocator<test_class> std_alloc;
    auto ptr = std::allocate_shared<test_class>(std_alloc, val);
    return ptr;
#else
    std::allocator<test_class> std_alloc;
    return std::allocate_shared<test_class>(std_alloc, val);
#endif
}

