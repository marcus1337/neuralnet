
#ifndef NEURALNET_H
#define NEURALNET_H

#include <string>
#include <vector>
#include "neuralnet/Layer.h"

namespace neuralnet {

    class NeuralNet {
        std::vector<Layer> layers;
        Layer& inputLayer();
    public:
        NeuralNet(int numInputNodes, int numHiddenNodes, int numOutputNodes);
        NeuralNet(const std::string& serializedLayers);
        std::string encode();
        int getOutput(std::vector<float> inputValues);
        void randomizeWeightSubset();
        int getNumLayers();
        std::vector<float> getInWeights(int layerIndex);
    };

}

#endif
