
#include <iostream>
#include "neuralnet.h"

using namespace neuralnet;

int main() {

    NeuralNet nn(4, 2);
    std::cout << "Test prediction: " << nn.predict({0.5,0.4,0.3,0.2}) << "\n";
    
    std::string exitStr = "n";
    while (exitStr != "y") {
        std::cout << "Type 'y' to exit.\n";
        std::cin >> exitStr;
    }

    return 0;
}