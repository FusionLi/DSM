#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

int main(int argc, char** argv) {
    
    struct statistic** count = malloc(sizeof(struct statistic*));
    *count = NULL;
    //FILE *inputFile = fopen("test.txt","r");
    FILE *inputFile = fopen("count_neg.txt", "r");
    FILE *outputFile = fopen("stat_neg.txt", "w");
    if (inputFile == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        return -1;
    }
    if (outputFile == NULL) {
        fprintf(stderr, "Can't open output file!\n");
        return -1;
    }
    int temp = 0;
    while (!feof(inputFile))
    {
        fscanf(inputFile, "%d", &temp);
        Update(count, temp);
    }
    fclose(inputFile);
    Print(*count, outputFile, 1);
    fclose(outputFile);
    Destroy(*count);
    free(count);
    return 0;
}

