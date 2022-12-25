
#include "neuralnet.h"
#include "neuralnet/WeightRandomizer.h"
#include "neuralnet/NetworkCodec.h"
#include <algorithm>

namespace neuralnet {

    NeuralNet::NeuralNet(int numInputNodes, int numHiddenNodes, int numOutputNodes) {
        Layer inputLayer(numInputNodes, 0);
        layers.push_back(inputLayer);
        if (numHiddenNodes > 0) {
            Layer hiddenLayer(numHiddenNodes, layers[layers.size() - 1].getNumNodes());
            layers.push_back(hiddenLayer);
        }
        Layer outputLayer(numOutputNodes, layers[layers.size() - 1].getNumNodes());
        layers.push_back(outputLayer);
    }

    NeuralNet::NeuralNet(const std::string& serializedLayers) {
        layers = NetworkCodec::decode(serializedLayers);
    }

    std::string NeuralNet::encode() {
        return NetworkCodec::encode(layers);
    }

    void NeuralNet::randomizeWeightSubset() {
        for (Layer& layer : layers)
            layer.randomizeWeightSubset();
    }

    Layer& NeuralNet::inputLayer() {
        return layers[0];
    }

    int NeuralNet::getOutput(std::vector<float> inputValues) {
        if (inputValues.size() != inputLayer().getNumNodes())
            return -1;
        for (Layer& layer : layers) {
            inputValues = layer.getOutput(inputValues);
        }
        return std::distance(inputValues.begin(), std::max_element(inputValues.begin(), inputValues.end()));
    }

    int NeuralNet::getNumLayers() {
        return layers.size();
    }

    std::vector<float> NeuralNet::getInWeights(int layerIndex) {
        return layers[layerIndex].getInWeights();
    }

}