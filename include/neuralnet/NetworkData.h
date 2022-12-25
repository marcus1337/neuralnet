
#ifndef NETWORKDATA_H
#define NETWORKDATA_H

#include <vector>

namespace neuralnet {

    struct NetworkData {
        std::vector<float> weights, inputNodes, outputNodes;
    };

}

#endif // !NETWORKDATA_H
