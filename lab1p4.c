/*
 * File name: lab1p4.c
 * Author: Linyong Nan; Zichang Liu
 * Date: Fab 12, 2017
 * Description: This program reads from a text file and encode the message in
 * it by reversing each word and keep non-alphabetic character in original position.
 * Output will be all upper-case.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toupper(int aChar);

int main(void){
	//declare constants
	const int MAX_LEN = 100;	//to be encoded message will not exceed 100

	//declare and initialize variables
	char message[MAX_LEN];
	char inFile[] = "lab1p4in", outFile[] = "lab1p4out";
	FILE *fileIn = fopen(inFile, "r");
	FILE *fileOut = fopen(outFile, "w");

	char *ptrStart = message;		//pointer that marked the start of a word
	char *ptrEnd = message;			//pointer that marked the end of a word
	char *ptrNonAlpha = message;	//pointer that travel through and stopped at non-alphabet character

	//error handling: file opened successfully
	if (fileIn == 0){
		fprintf(stderr, "Failed to open lab1p4in\n");
		exit(1);
	}

	//read message into the char array character by character until the end of file
	char *ptrRead = message;
	int c;
	while((c = fgetc(fileIn)) !=  EOF){
		*ptrRead = c;
		ptrRead++;
	}
	//attach empty symbol at the end, and close the input file.
	*ptrRead = '\0';
	fclose(fileIn);

	while(*ptrNonAlpha != '\0'){
		//ptrNonAlpha and ptrEnd go to the next char until encountering an non-alphabetic symbol
		 if((*ptrNonAlpha > 64 && *ptrNonAlpha < 91) || (*ptrNonAlpha > 96 && *ptrNonAlpha < 123) ){
			 ptrEnd ++;
			 ptrNonAlpha ++;

		 }
		//after encounter an non-alphabetic symbol, reverse the preserved word
		else{
			//change "_" to " "
			 if(*ptrEnd == 95){
				 *ptrEnd = ' ';
			 }

			 //reverse the preserved word by swapping characters
			 ptrEnd--;
			 while(ptrStart <= ptrEnd){
				 char temp;
				 temp = *ptrEnd;
				 *ptrEnd = toupper(*ptrStart);
				 *ptrStart = toupper(temp);
				 ptrEnd --;
				 ptrStart ++;
			 }

			 //if encounter the end, stop iterating
			 if(*ptrNonAlpha == '\0'){
				 break;
			 }

			//after reversing the word, adjust pointer positions.
			ptrNonAlpha ++;
			ptrStart = ptrNonAlpha;
			ptrEnd = ptrNonAlpha;

		 }
	}
	//process last word before '\0', which is not processed in while loop
	ptrEnd--;
	while(ptrStart <= ptrEnd){
		char temp;
		temp = *ptrEnd;
		*ptrEnd = toupper(*ptrStart);
		*ptrStart = toupper(temp);
		ptrEnd --;
		ptrStart ++;
	}

	//write the processed message to output file, and close.
	if(fileOut != NULL){
		fputs(message, fileOut);
		fclose(fileOut);
	}

	return 0;
}
