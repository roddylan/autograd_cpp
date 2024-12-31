#ifndef NODE_H_
#define NODE_H_
#include <type_traits>

enum class Operation {
    // regular
    multiply, divide, add, sub, 
    // activation
    tanh, sigmoid, relu
};


/**
 * @brief 
 * 
 * @tparam T 
 */
template <typename T>
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
    Value(const T &val) : val{val} {}

    /**
     * @brief Value construct a new Value object
     * 
     * @param val 
     */
    Value(Value<T> &rhs) : val{rhs.val} {}

    /**
     * @brief assignment
     * 
     * @param rval 
     * @return Value<T>& 
     */
    Value<T> &operator=(const Value<T> &rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        this->val = rhs.val;
        return *this;
    }


private:
    T val;
    Operation op;
};







#endif