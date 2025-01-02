#ifndef LIN_ALG_DTYPE_H_
#define LIN_ALG_DTYPE_H_
#include "node.hpp"

typedef unsigned long long UINT64_T;


template <typename T = float>
class Matrix {
public:
    

private:
    UINT64_T w{}, h{};
    std::vector<Value<T>> data;
};








#endif