#ifndef NODE_H_
#define NODE_H_
#include <type_traits>
#include <memory>
#include <iostream>
#include <cmath>

enum class Operation {
    // regular
    multiply, divide, add, sub, 
    // activation
    tanh, sigmoid, relu
};

template <typename T>
struct BPF {
    virtual const T &operator()();
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
    Value() : val{} {}
    
    /**
     * @brief Value construct a new Value object
     * 
     * @param val 
     */
    Value(T val) : val{val} {}
    
    /**
     * @brief Copy construct a new Value object
     * 
     * @param val 
     */
    Value(const Value<T> &rhs) : val{rhs.val} {}

    /**
     * @brief prefix inc
     * 
     * @return const Value<T>& 
     */
    const Value<T> &operator++() {
        val += 1;
        return *this;
    }

    /**
     * @brief postfix inc
     * 
     * @return Value<T> 
     */
    Value<T> operator++(int) {
        Value<T> temp{this->val};
        val += 1;
        return temp;
    }

    /**
     * @brief prefix dec
     * 
     * @return const Value<T>& 
     */
    const Value<T> &operator--() {
        val -= 1;
        return *this;
    }

    /**
     * @brief postfix dec
     * 
     * @return Value<T> 
     */
    Value<T> operator--(int) {
        Value<T> temp{this->val};
        val -= 1;
        return temp;
    }

    Value<T> operator+(Value<T> rhs) const {
        return Value<T>{this->val + rhs.val};
    }

    Value<T> operator+(T rhs) const {
        return Value<T>{this->val + rhs};
    }

    Value<T> operator-(Value<T> rhs) const {
        return Value<T>{this->val - rhs.val};
    }

    Value<T> operator-(T rhs) const {
        return Value<T>{this->val - rhs};
    }

    friend std::ostream &operator<<(std::ostream& os, const Value<T>& v_obj) {
        os << "<Value [ " << (std::trunc(100 * v_obj.val) / 100) << " ]>";
        return os;
    }


private:
    T val;          // underlying value
};


#endif