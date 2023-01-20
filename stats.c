/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"

// TODO: function definitions for dealing with histogram below

void printFreq(int histogram[]){
    int vcount = 0; 
    int ccount = 0; 
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
            vcount += histogram[i];
        }
        else{
            ccount += histogram[i]; 
        }
    }
    float total = vcount + ccount; 
    float vpercent = vcount/total * 100; 
    float cpercent = ccount/total * 100;
    if(total == 0.0){
        cpercent = 0.0;
        vpercent = 0.0; 
    }
    printf("Vowels = %d(%.2f%%), Consonants = %d(%.2f%%), Total = %d\n\n", vcount, vpercent, ccount, cpercent, vcount + ccount);
}

void printHist(int histogram[]){
    int max = 0; 
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(histogram[i] > max){
            max = histogram[i];
        }
    }
    for(int i = max; i > 0; i--){
        for(int j = 0; j < ALPHABET_SIZE; j++){
            if(histogram[j] >= i){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < ALPHABET_SIZE; i++){
        printf("%c ", i + 97);
    }
    printf("\n");
    for(int i = 0; i < ALPHABET_SIZE; i++){
        printf("%d ", histogram[i]);
    }
    printf("\n\n");
}