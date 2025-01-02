#include "../include/autograd/node.hpp"
#include <xtensor.hpp>
#include <iostream>



int main() {
    Value v{5.0};
    v = v - (1.0/3);
    std::cout << v << std::endl;

    return 0;
}
