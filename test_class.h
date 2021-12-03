
#pragma once

#include <memory>

class test_class;
using test_class_ptr = std::shared_ptr<test_class>;

class test_class
{
public:
    // I want this to be private, but must be public for testing purposes
    test_class(const int some_val);

private:
    test_class();
    test_class(test_class &&) = default;
    test_class(const test_class &) = default;
    test_class &operator=(test_class &&) = default;
    test_class &operator=(const test_class &) = default;

public:
    ~test_class();

    auto get_some_value() -> int const { return m_some_int;  }

    static auto create_using_shared_ptr(const int val) -> test_class_ptr;

    static auto create_using_custom(const int val) -> test_class_ptr;

    // These are out since they need public constructors
     static auto create_using_make_shared(const int val) -> test_class_ptr;

    // These are out since they need public constructors
    static auto create_using_allocator(const int val) -> test_class_ptr;

private:
    int m_some_int;
};

