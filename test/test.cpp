
#include <iostream>
#include "neuralnet.h"

using namespace neuralnet;

int main() {

    NeuralNet nn(4, 2);
    std::cout << "Test prediction: " << nn.predict({0.5,0.4,0.3,0.6}) << "\n";

    return 0;
}