#pragma once

#include <type_traits>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

// helper type for the visitor
template <class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};

#define HasField(StructType, Field)                                                                                          \
    []() {                                                                                                                   \
        return overloaded{[]<typename T>(int) -> decltype(std::declval<T>().Field, void(), std::true_type()) { return {}; }, \
                          []<typename T>(...) { return std::false_type{}; }}                                                 \
            .                                                                                                                \
            operator()<StructType>(0);                                                                                       \
    }()

#define OffsetOf(StructType, Field)                                                                                                                                 \
    []() {                                                                                                                                                          \
        return overloaded{[]<typename T>(int) -> decltype(std::declval<T>().Field, void(), std::integral_constant<size_t, offsetof(T, T::Field)>{}) { return {}; }, \
                          []<typename T>(...) { return std::integral_constant<size_t, 0>{}; }}                                                                      \
            .                                                                                                                                                       \
            operator()<StructType>(0);                                                                                                                              \
    }()

#define SizeOf(StructType, Field)                                                                                                                              \
    []() {                                                                                                                                                     \
        return overloaded{[]<typename T>(int) -> decltype(std::declval<T>().Field, void(), std::integral_constant<size_t, sizeof(T::Field)>{}) { return {}; }, \
                          []<typename T>(...) { return std::integral_constant<size_t, 0>{}; }}                                                                 \
            .                                                                                                                                                  \
            operator()<StructType>(0);                                                                                                                         \
    }()