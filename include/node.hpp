#ifndef NODE_H_
#define NODE_H_
#include <type_traits>
#include <memory>
#include <vector>


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
 * @tparam T type of value (default float)
 */
template <typename T = float>
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
        ++val;
        return *this;
    }

    /**
     * @brief postfix inc
     * 
     * @return Value<T> 
     */
    Value<T> operator++(T) {
        Value<T> temp{this->val};
        ++val;
        return temp;
    }

    /**
     * @brief prefix dec
     * 
     * @return const Value<T>& 
     */
    const Value<T> &operator--() {
        --val;
        return *this;
    }

    /**
     * @brief postfix dec
     * 
     * @return Value<T> 
     */
    Value<T> operator--(T) {
        Value<T> temp{this->val};
        --val;
        return temp;
    }

    const Value<T> &operator+(Value<T> rhs) {
        return Value<T>{this->val + rhs.val};
    }

    const Value<T> &operator+(T rhs) {
        return Value<T>{this->val + rhs};
    }

    const Value<T> &operator-(Value<T> rhs) {
        return Value<T>{this->val - rhs.val};
    }

    const Value<T> &operator-(T rhs) {
        return Value<T>{this->val - rhs};
    }

    // const Value<T> &operator/()


private:
    T val;          // underlying value
};




#endif