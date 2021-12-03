
#include "test_class.h"

#include <vector>
#include <functional>

static std::vector<test_class_ptr> s_storage_for_test;

typedef test_class_ptr(*factory_func)(const int);
template <factory_func fact_func>
void test_allocating_shared_ptr(const uint32_t test_count)
{
  // Just a number for incrementing
    auto result = 0;

    // TODO: Add a profiler flag

    // A simple loop to increment our memory usage
    for (auto i = 0; i < test_count; i++)
    {
        auto ptr = fact_func(i);
        s_storage_for_test.push_back(ptr);

        const auto val = ptr->get_some_value();
        result += val;
    }

    printf("some value %d\n", result);
    // TODO: Add a profiler flag
}

int main()
{
    const auto max_test_count = 1000000;

    test_allocating_shared_ptr<test_class::create_using_shared_ptr>(max_test_count);
    s_storage_for_test.clear();

    test_allocating_shared_ptr<test_class::create_using_make_shared>(max_test_count);
    s_storage_for_test.clear();

    test_allocating_shared_ptr<test_class::create_using_custom>(max_test_count);
    s_storage_for_test.clear();

    return 0;
}

void test_shared_ptr(const uint32_t test_count)
{
    int result = 0;
    for (auto i = 0; i < test_count; i++)
    {
        auto ptr = test_class::create_using_shared_ptr(i);
        s_storage_for_test.push_back(ptr);

        const auto val = ptr->get_some_value();
        result += val;
    }

    printf("some value %d\n", result);
}

void test_make_shared(const uint32_t test_count)
{
    int result = 0;
    for (auto i = 0; i < test_count; i++)
    {
        auto ptr = test_class::create_using_make_shared(i);
        s_storage_for_test.push_back(ptr);

        const auto val = ptr->get_some_value();
        result += val;
    }

    printf("some value %d\n", result);
}

void test_custom(const uint32_t test_count)
{
    int result = 0;
    for (auto i = 0; i < test_count; i++)
    {
        auto ptr = test_class::create_using_custom(i);
        s_storage_for_test.push_back(ptr);

        const auto val = ptr->get_some_value();
        result += val;
    }

    printf("some value %d\n", result);
}