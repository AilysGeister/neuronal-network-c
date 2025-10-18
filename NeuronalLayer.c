#include "NeuronalLayer.h"
#include <stdio.h>
#include <stdlib.h>

NeuronalLayer InitLayer(int nbNeurons, int nbEntries) {
    //Initialization:
    if (nbNeurons == 0) {return NULL;}
    NeuronalLayer head = NULL;
    NeuronalLayer temp = NULL;
    List weights = NULL;
    int bias;
    int weightsj;

    for (int i = 0; i < nbNeurons; i++) {
        //Initialization of weight list for current neuron:
        weights = NULL;
        for (int j = 0; j < nbEntries; j++) {
            printf("Enter the weights %d associated to the neuron %d:\n", j+1, i+1);
            scanf("%d", &weightsj);
            weights=addTail(weights,weightsj);
        }

        //Reading of neuron bias:
        printf("Enter the bias of the neuron %d:\n", i + 1);
        scanf("%d", &bias);

        //Neurone initialization with weights and bias:
        Neuron neur = initNeur(nbEntries, weights, bias);

        //Creating a new layer element:
        NeuronalLayer newel = (ElementLayer*)malloc(sizeof(ElementLayer));
        newel->neur = neur;
        newel->next = NULL;

        //Adding the neuron to the layer:
        if (head == NULL) {head = newel;} else {temp->next = newel;}
        temp = newel;
    }

    return head;
}

List OutLayer(NeuronalLayer layer, List entries, int nbEntries) {
    //Initialization:
    if (layer == NULL || entries == NULL) {return NULL;}
    List output = NULL;

    //Compute the output:
    while (layer != NULL) {
        //Compute the output of the current neuron:
        int out = outNeur(layer->neur, entries, nbEntries);

        //Ajoute la sortie à la tête de la liste:
        addHead(output,out);
        layer = layer->next;
    }
    return output;
}
