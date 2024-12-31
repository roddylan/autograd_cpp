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
public:



private:
    T val;


};







#endif