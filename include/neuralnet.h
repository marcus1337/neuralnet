
#ifndef NEURALNET_H
#define NEURALNET_H

#include <string>
#include <vector>

namespace neuralnet {

    class NeuralNet {
        std::vector<float> weights, inputNodes, outputNodes;

    public:

        NeuralNet(int numInputNodes, int numOutputNodes);
        void randomizeAllWeights();
        void randomizeSomeWeights();
        std::string serializeToString();
        void deserializeFromString(std::string serializedNeuralNet);
        int predict(std::vector<float> inputValues);


    };

}

#endif
