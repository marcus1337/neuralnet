
#include <iostream>
#include "neuralnet.h"

using namespace neuralnet;

int main() {

    NeuralNet nn(3, 0, 2);
    std::cout << "NeuralNet encoded: " << nn.encode() << "\n";
    std::vector<float> inputValues = { 0.3,0.2,0.1 };

    if (nn.isValidInput(inputValues)) {
        auto output = nn.getOutput(inputValues);
        std::cout << "Test prediction: " << NeuralNet::selectMaxOutputIndex(output) << "\n";
    }
    else {
        std::cout << "Invalid input format!\n";
    }

    return 0;
}