#ifndef EXAMPLES_H
#define EXAMPLES_H
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Neuron.h"

/**
 * Function that allow user to load the examples network.
 * @return 0
 */
int examplesMenu();

/**
 * Function that compute the output of a neuron corresponding to the logical AND.
 * @param n Number of entries of the network.
 * @param entries List of the entries of the network.
 * @return The out value (0 ou 1).
 */
int networkAND(int n, List entries);

/**
 * Function that compute the output of a neuron corresponding to the logical OR.
 * @param n Number of entries of the network.
 * @param entries List of the entries of the network.
 * @return The out value (0 ou 1).
 */
int networkOR(int n, List entries);

/**
 * Function that compute the output of a neuron corresponding to the logical NOT.
 * @param entry Value will be reverses.
 * @return The out value (0 ou 1).
 */
int networkNOT(int entry);

/**
 * Function that compute the output of a network corresponding to this logical expression: (A AND (NOT B) AND C) OR (A AND (NOT C)).
 * @return The out value (0 ou 1).
 */
int network4();

/**
 * Function that compute the asked network during my LO21 orals.
 * @return The out value (0 ou 1).
 */
int orals();

#endif //EXAMPLES_H
