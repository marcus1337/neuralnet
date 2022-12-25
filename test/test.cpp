
#include <iostream>
#include "neuralnet.h"

using namespace neuralnet;

int main() {

    NeuralNet nn(3, 0, 2);

    std::cout << "NeuralNet encoded: " << nn.encode() << "\n";

    std::cout << "Test prediction: " << nn.getOutput({0.3,0.2,0.1}) << "\n";

    return 0;
}