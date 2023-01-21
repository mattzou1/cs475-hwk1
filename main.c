/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	// declare and initialize the histogram
	int histogram[ALPHABET_SIZE];
	for(int i = 0; i < ALPHABET_SIZE; i++){
		histogram[i] = 0; 
	}

	// TODO: start by getting strings from users until # is input
	getInput(histogram);
	
	//opens word stats menu until you type 4
	int option = 0;
	while(option != 4){
		option = getMenuOption();
		if(option < 1 || option > 4){
			printf("Error: Unknown option: %d\n\n", option);
		}
		else if(option == 1){
			printFreq(histogram);
		}
		else if(option == 2){
			printHist(histogram);
		}
		else if(option == 3){
			getInput(histogram);
		}
		
	}
	printf("Exiting...\n");
	return 0;
}
