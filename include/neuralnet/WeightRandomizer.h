
#ifndef WEIGHTRANDOMIZER_H
#define WEIGHTRANDOMIZER_H

#include "NetworkData.h"
#include <random>

namespace neuralnet {
    class WeightRandomizer {
        NetworkData& networkData;
        std::mt19937 rng;
        std::random_device randDevice;
        float getRandomWeight();
        int getRandomWeightIndex();
        std::vector<int> getWeightIndicesSubset();
        int getWeightIndicesSubsetSize();

    public:
        WeightRandomizer(NetworkData& _networkData);
        void radomize();
        void randomizeSubset();

    };
}

#endif
