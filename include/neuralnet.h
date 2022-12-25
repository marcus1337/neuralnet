
#ifndef NEURALNET_H
#define NEURALNET_H

#include <string>
#include <vector>
#include "neuralnet/NetworkData.h"

namespace neuralnet {

    class NeuralNet {
        NetworkData networkData;

    public:

        NeuralNet(int numInputNodes, int numOutputNodes);
        std::string serializeToString();
        void deserializeFromString(std::string serializedNeuralNet);
        int predict(std::vector<float> inputValues);
        void randomizeWeightSubset();


    };

}

#endif
