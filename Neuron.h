#ifndef NEURON_H
#define NEURON_H
#include "List.h"

typedef struct {
    List weights;
    int bias;
}Neuron;

/**
 * Function that initialize a new neuron with given parameters.
 * @param nbParameters Number of entry that the neuron can take.
 * @param weights The weights associated to each entry.
 * @param bias The way du neurone.
 * @return The new neuron.
 */
Neuron initNeur(int nbParameters, List weights, int bias);

/**
 * Function that compute the output of a neuron in depend of a given list of entries.
 * @param neur Neuron that we compute the output.
 * @param entries Entries list.
 * @param nbEntries Entries number.
 * @return
 */
int outNeur(Neuron neur, List entries, int nbEntries);

#endif //NEURON_H
