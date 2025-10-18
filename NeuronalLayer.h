#ifndef LAYER_NEURONS_H
#define LAYER_NEURONS_H
#include "list.h"
#include "neuron.h"

typedef struct ElemLayer {
    Neuron neur;
    struct ElemLayer* next;
} ElementLayer;

typedef ElementLayer* NeuronalLayer;

/**
 * Function that creates a layer and initializes its neurons.
 * @param nbNeurons Number of neurons present in the layer.
 * @param nbEntries Number of neurons input.
 * @return
 */
NeuronalLayer InitLayer(int nbNeurons, int nbEntries);

/**
 * Function that allows to calculate the list of outputs of a neurone’s skin.
 * @param layer The layer for which outputs are to be calculated.
 * @param entries List of entries of the layer.
 * @param nbEntries Number of entries of the layer.
 * @return
 */
List OutLayer(NeuronalLayer layer, List entries, int nbEntries);

#endif //LAYER_NEURONS_H
