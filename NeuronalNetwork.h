#ifndef NETWORK_H
#define NETWORK_H
#include "NeuronalLayer.h"

typedef struct ElemNet {
    NeuronalLayer layer;
    struct ElemNet* next;
}ElementNetwork;

typedef ElementNetwork* NeuronalNetwork;

/**
 * Function that creates a neural network with a fixed number of layers and inputs.
 * @param nbLayer The number of layer in the network.
 * @param NbNeurons The number of neurons per layer.
 * @param nbEntries The number of entries of the network.
 * @return
 */
NeuronalNetwork CreatNetwork(int nbLayer, List NbNeurons, int nbEntries);

/**
 * Function that initializes a neural network.
 * @return
 */
NeuronalNetwork InitNetwork();

/**
 * Function that calculates the output of a neural network in the form of a chained list.
 * @param net The network from which the output is calculated.
 * @param entries List of the entries of the network.
 * @return
 */
List OutNetwork(NeuronalNetwork net, List entries);

/**
 * Function that adds a layer at the top of a network.
 * @param net The network to which you want to add a layer.
 * @param layer The layer to add.
 * @return
 */
NeuronalNetwork addHeadNet(NeuronalNetwork net, NeuronalLayer layer);

/**
 * Function that adds a layer at the end of a network.
 * @param net The network to which you want to add a layer.
 * @param layer The layer to add.
 * @return
 */
NeuronalNetwork addTailNet(NeuronalNetwork net, NeuronalLayer layer);
#endif //NETWORK_H
