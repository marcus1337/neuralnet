
#include "neuralnet/WeightRandomizer.h"
#include <set>

namespace neuralnet {

    WeightRandomizer::WeightRandomizer(NetworkData& _networkData) : networkData(_networkData) {
        rng.seed(randDevice());
    }

    void WeightRandomizer::radomize() {
        auto& weights = networkData.weights;
        for (int i = 0; i < weights.size(); i++) {
            weights[i] = getRandomWeight();
        }
    }

    void WeightRandomizer::randomizeSubset() {
        auto& weights = networkData.weights;
        for (int weightIndex : getWeightIndicesSubset()) {
            weights[weightIndex] = getRandomWeight();
        }
    }

    std::vector<int> WeightRandomizer::getWeightIndicesSubset() {
        std::set<int> indices;
        for (int i = 0; i < getWeightIndicesSubsetSize(); i++) {
            indices.insert(getRandomWeightIndex());
        }
        return std::vector<int>(indices.begin(), indices.end());
    }

    int WeightRandomizer::getWeightIndicesSubsetSize() {
        int maxSize = std::max<int>(networkData.weights.size(), 4);
        int minSize = std::min<int>(1, maxSize);
        std::uniform_int_distribution<int> distribution(minSize, maxSize);
        return distribution(rng);
    }

    float WeightRandomizer::getRandomWeight() {
        std::uniform_real_distribution<float> distribution(0.f, 1.f);
        return distribution(rng);
    }

    int WeightRandomizer::getRandomWeightIndex() {
        std::uniform_int_distribution<int> distribution(0, networkData.weights.size());
        return distribution(rng);
    }

}

