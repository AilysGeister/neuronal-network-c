#include "examples.h"

int exemplesMenu() {
    //Initialization:
    int n, choice=0, value, output;
    List entries=NULL;

    while (choice!=6) {
        //Choice of the network:
        printf("\nWhich network did you want ?\n1) AND\n2) OR\n3) NOT\n4) (A AND (NOT B) AND C) OR (A AND (NOT C))\n5) Orals\n6) Main Menu\n");
        scanf("%d",&choice);

        switch (choice) {
            default:
                return EXIT_SUCCESS;
                break;
            case 1:
                //Reading input number:
                printf("Enter the number of entries for the network AND: ");
                scanf("%d", &n);

                //Creation of the entries:
                printf("Enter the value of the input (0 or 1):\n");
                for (int i = 0; i < n; i++) {
                    while (value!=0 && value!=1) {
                        printf("Entry %d : ", i + 1);
                        scanf("%d", &value);
                    }
                    entries = addTail(entries, value);
                }
                output=networkAND(n, entries);
                break;
            case 2:
                //Reading input number:
                printf("Enter the number of entries for the network OR: ");
                scanf("%d", &n);

                //Creation of the entries:
                printf("Enter the value of the input (0 or 1):\n");
                for (int i = 0; i < n; i++) {
                    while (value!=0 && value!=1) {
                        printf("Entry %d : ", i + 1);
                        scanf("%d", &value);
                    }
                    entries = addTail(entries, value);
                }
                output=networkOR(n, entries);
                break;
            case 3:
                //Reading user input:
                while (value!=0 && value!=1) {
                    printf("Enter the value taken into account by the network NOT:\n");
                }
                output=networkNOT(value);
                break;
            case 4:
                output=network4();
                break;
            case 5:
                output=viva();
                break;
        }
        //Printing the output of the selected network:
        printf("The output of the selected network is: %d\n",output);
    }
}

int networkAND(int n, List entries) {
    //Initialization:
    List weights=NULL;

    //Creation of the weights: all egals to 1:
    for (int i = 0; i < n; i++) {
        weights = addTail(weights, 1);
    }

    //Neuron initialization with bias equal to n:
    Neuron neuronAND = initNeur(n, weights, n);

    //Compute the ouput:
    return outNeur(neuronAND, entries, n);
}

int networkOR(int n, List entries) {
    //Initialization:
    List weights=NULL;

    //Weight allocation:
    for (int i = 0; i < n; i++) {
        weights = addTail(weights, 1);
    }

    //Neuron initialization with bias equal to 1:
    Neuron neuronOR = initNeur(n, weights, 1);

    //Compute the output:
    return  outNeur(neuronOR, entries, n);
}

int networkNOT(int entry) {
    //Initialization:
    List weights = NULL, entries = NULL;
    weights = addTail(weights, -1);
    Neuron neuronNOT = initNeur(1, weights, 0);

    //Creation of the input list:
    entries = addTail(entries, entries);

    //Compute the output:
    return outNeur(neuronNOT, entries, 1);
}

int network4() {
    //Initialization:
    int value=-1;
    List entries=NULL, output=NULL, currentEntry=NULL;

    //Reading the input:
    for (int i=0;i<3;i++) {
        while (value!=1 && value!=0) {
            printf("Enter the value of %c (0 oR 1):",65+i);
            scanf("%d",&value);
        }
        entries=addTail(entries,value);
        value=-1;
    }

    //Compute the output of the first layer:
    currentEntry=addHead(currentEntry,entries->value);
    entries=entries->next;
    currentEntry=addTail(currentEntry,networkNOT(entries->value));
    output=addTail(output,networkAND(2,currentEntry));

    currentEntry=NULL;
    entries=entries->next;
    currentEntry=addHead(currentEntry,entries->value);
    currentEntry=addHead(currentEntry,networkNOT(entries->value));
    output=addTail(output,networkAND(2,currentEntry));

    //Compute the output:
    return networkOR(2,output);
}

int orals() {
    //Initialization:
    int value=-1;
    List entries=NULL, output=NULL, currentEntry=NULL;

    //Reading the input:
    for (int i=0;i<3;i++) {
        while (value!=1 && value!=0) {
            printf("Enter the value of %c (0 oR 1):",65+i);
            scanf("%d",&value);
        }
        entries=addTail(entries,value);
        value=-1;
    }

    //Compute the output of the first layer:
    output=addHead(output,networkOR(3,entries));
    output=addTail(output,networkOR(3,entries));
    C=entries->next->next->value;
    output=addTail(output,networkNOT(C));

    //Compute the ouput:
    return networkAND(3,output);
}
