#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "split.h"


#define FULL_NET_PATH "acas_xu_1_1_RELUVAL.txt"
int main(int argc, char *argv[]) {
    struct NNet* nnet = load_network(FULL_NET_PATH, 0);
    printf("LOADED NETWORK\n");
//    float counterexample[] = {-0.075, 0.075, -0.075, 0.075, -0.075};
    float groundTruth[] = {-0.126, -0.31, -0.48, -0.34, -0.48};
    float counterexample[] = {-.274, -.324, -.574, -.374, -.514};
    struct Matrix input = {groundTruth, 1, 5};
    float output_t[5];
    struct Matrix output = {output_t, 1, 5};
    forward_prop(nnet, &input, &output);
    for(int i = 0; i < 5; i++) {
       printf("%f,", output_t[i]);
    }
    printf("\n");
    struct Matrix input2 = {counterexample, 1, 5};
    forward_prop(nnet, &input2, &output);
    for(int i = 0; i < 5; i++) {
       printf("%f,", output_t[i]);
    }
}

