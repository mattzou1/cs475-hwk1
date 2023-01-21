/*
 * menu.c
 *
 *  Created on: Jun 16, 2015
 *      Author: dchiu
 */

#include <stdio.h>
#include "menu.h"
#include "defs.h"

int MENU_STATS = 1; 
int MENU_HISTO = 2; 
int MENU_INPUT = 3; 
int MENU_EXIT = 4; 

int getMenuOption() {
	int opt;
	printf("*** WORD STATS MENU ***\n");
	printf("Enter %d to print vowel and consonant frequency.\n", MENU_STATS);
	printf("Enter %d to print histogram.\n", MENU_HISTO);
	printf("Enter %d to return to inputting more strings.\n", MENU_INPUT);
	printf("Enter %d to quit.\n", MENU_EXIT);
	scanf("%d", &opt);
	return opt;
}

//asks user for input and stores information in histogram array until user types #
void getInput(int histogram[]){
	char input[MAX_INPUT_LEN];
	printf("Enter strings (# to stop):\n");
	while(input[0] != '#'){
		scanf("%s", &input);
		int i = 0; 
		//traverses string 
		while(input[i] != '\0'){
			//converts lowercase to uppercase 
			if (input[i] >= 'a' && input[i] <= 'z') {
				input[i] -= 32;
			}
			//converts char value to index value
			int index = (int)input[i] - 65;
			//increments histogram array at corresponding index if character is A-Z
			if(index >= 0 && index <= 25){
				histogram[index]++; 
			}
			i++; 
		}
	}
}
