#include "NeuronalNetwork.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

NeuronalNetwork CreatNetwork(int nbLayer, List NbNeurons, int nbEntries) {
    //Initialization:
    if (nbLayer == 0 || NbNeurons == NULL) {return NULL;}
    NeuronalNetwork net = NULL;

    //Creation of the entry layer:
    printf("First layer:\n");
    net = addHeadNet(net, InitLayer(NbNeurons->value, nbEntries));

    //Creation of the next layers:
    for (int i = 1; i < nbLayer; i++) {
        if (NbNeurons->next == NULL) {
            printf("ERROR: The neuron list ist too short for the number specified by the layer.\n");
            exit(EXIT_FAILURE);
        }
        nbEntries = NbNeurons->value;
        NbNeurons = NbNeurons->next;
        printf("Layer %d:\n",i+1);
        net = addTailNet(net, InitLayer(NbNeurons->value, nbEntries));
    }

    //Return the created network:
    return net;
}

NeuronalNetwork InitNetwork() {
    //Initialization:
    int NbLayer, value;
    List NbNeurons=NULL;

    //Initialization of the neural layers:
    printf("Enter the numbrr of layer of the network:\n");
    scanf("%d",&NbLayer);
    //Initialisation du nom de neurones par couche de neurones:
    for (int i=0;i<NbLayer;i++) {
        printf("Enter the number of neurons in the layer %d:",i+1);
        scanf("%d",&value);
        NbNeurons=addHead(NbNeurons,value);
    }
    //Initialization of the number of network entries:
    printf("Enter the number of entries of the network:\n");
    scanf("%d",&value);
    //Choice of network name (for list of all networks):
    printf("Enter the name of the new network:\n");
    return CreatNetwork(NbLayer,NbNeurons,value);
}

List OutNetwork(NeuronalNetwork net, List entries) {
    return NULL;
}

NeuronalNetwork addHeadNet(NeuronalNetwork net, NeuronalLayer layer) {
    //We creat a new element:
    NeuronalNetwork newel = (ElementNetwork*) malloc(sizeof(ElementNetwork));

    //We assign the layer to this element:
    newel->layer = layer;

    //Because we add in the top the following element is the network:
    newel->next = next;

    //Return the new network:
    return newel;
}

NeuronalNetwork addTailNet(NeuronalNetwork net, NeuronalLayer layer) {
    //We creat a new element:
    NeuronalNetwork newel = (NeuronalNetwork*) malloc(sizeof(NeuronalNetwork));

    //We assign the layer to this element:
    newel->layer = layer;

    //Because the following is added to be necessarily nil:
    newel->next = NULL;

    //If the network is empty just return on the created element:
    if (net == NULL) {
        return newel;
    }

    //Otherwise, the network is scanned with a temporary pointer and the last item in the list is linked to the new item:
    NeuronalNetwork temp = net;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newel;

    //Return the new network:
    return net;
}