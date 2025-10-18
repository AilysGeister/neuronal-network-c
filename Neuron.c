#include "Neuron.h"
#include <stdio.h>
#include <stdlib.h>

Neuron initNeur(int nbParameters, List weights, int bias) {
    //Initialization:
    Neuron newel;
    newel.bias = bias;
    newel.weights = NULL;

    //Creation of the weights list:
    Element* temp = NULL;
    for (int i = 0; i < nbParameters; i++) {
        if (weights == NULL) {
            printf("ERROR: Insufficient weight count.\n");
            exit(EXIT_FAILURE);
        }

        //Allocate a new item for the list:
        Element* newelElem = (Element*)malloc(sizeof(Element));
        newelElem->value = weights->value;
        newelElem->next = NULL;

        if (newel.weights == NULL) {
            newel.weights = newelElem;
        } else {
            temp->next = newelElem;
        }
        temp = newelElem;
        weights = weights->next;
    }
    return newel;
}

int outNeur(Neuron neur, List entries, int nbEntries) {
    //Initialization:
    int sum = 0;
    Element* currentWeights = neur.weights;

    //Calculation of weighted sum:
    for (int i = 0; i < nbEntries; i++) {
        if (currentWeights == NULL) {
            printf("ERROR: Insufficient weight for this entry.\n");
            return -1;
        }
        if (entries == NULL) {
            printf("ERREOR: Insufficient entries count.\n");
            return -1;
        }

        sum += entries->value * currentWeights->value;
        entries = entries->next;
        currentWeights = currentWeights->next;
    }

    //Activation function:
    if (sum >= neur.bias) {return 1;} else {return 0;}
}
