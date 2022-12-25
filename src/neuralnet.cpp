
#include "neuralnet.h"
#include "neuralnet/WeightRandomizer.h"

namespace neuralnet {

    NeuralNet::NeuralNet(int numInputNodes, int numOutputNodes) {
        WeightRandomizer(networkData).radomize();
    }

    void NeuralNet::randomizeWeightSubset() {
        WeightRandomizer(networkData).randomizeSubset();
    }

    std::string NeuralNet::serializeToString() {
        return "";
    }

    void NeuralNet::deserializeFromString(std::string serializedNeuralNet) {

    }

    int NeuralNet::predict(std::vector<float> inputValues) {
        return 0;
    }

}