#ifndef NODE_H_
#define NODE_H_
#include <functional>
#include <type_traits>
#include <memory>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <magic_enum/magic_enum.hpp>

enum class Operation {
    // empty
    none,
    // regular
    multiply, divide, add, sub, 
    // activation
    tanh, sigmoid, relu
};

/**
 * @brief Value object
 * 
 * @tparam T type of value (default double)
 */
template <typename T = double>
class Value {
    // prevent non numeric vals
    // TODO: complex valued nodes
    static_assert(std::is_arithmetic<T>::value, "Not an arithmetic type");

public:
    /**
     * @brief Empty construct a new Value object
     * 
     */
    Value() : val{}, grad{}, op{}, backprop([] { return 0;}) {}
    
    /**
     * @brief Value construct a new Value object
     * 
     * @param val 
     */
    Value(
        T val, T grad = 0, Operation op = Operation::none, 
        std::function<T> backprop = [] { return 0; },
        std::unordered_set<std::shared_ptr<Value<T>>> children = {}) 
        : val{val}, grad{grad}, op{op}, backprop{backprop}, children{children} {}
    
    /**
     * @brief Copy construct a new Value object
     * 
     * @param val 
     */
    Value(const Value<T> &rhs) 
    : val{rhs.val}, grad{rhs.grad}, op{rhs.op}, backprop{rhs.backprop}, children{rhs.children} {}


    Value<T> operator+(Value<T> &rhs) {
        Value<T> out{this->val + rhs.val};
        out.op = Operation::add;
        
        out.backprop = [this, &rhs]() {
            this->grad += out.grad;
            rhs.grad += out.grad;
        };

        return out;
    }

    Value<T> operator-(Value<T> &rhs) {
        Value<T> out{this->val - rhs.val};
        out.op = Operation::sub;
        
        out.backprop = [this, &rhs]() {
            this->grad -= out.grad;
            rhs.grad -= out.grad;
        };

        return out;
    }

    friend std::ostream &operator<<(std::ostream &os, const Value<T> &v_obj) {
        os << "<Value [ " << (std::trunc(100 * v_obj.val) / 100) << " | op=" << magic_enum::enum_name(v_obj.op) << " ]>";
        return os;
    }
    
private:
    T val;          // underlying value
    T grad;         // gradient value
    Operation op;   // operation

    std::function<T()> backprop; // backprop functor

    std::unordered_set<std::shared_ptr<Value<T>>> children; // ptrs to child nodes


};

template <typename T = double>
struct ValHash {
    int operator()(Value<T> obj) {
        static_assert(std::is_arithmetic<T>::value, "Not an arithmetic type");

        // return std::hash<T> obj.val;
        return std::hash<T>(obj.val);
    }
};

#endif