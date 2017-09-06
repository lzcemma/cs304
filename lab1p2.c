/*
 * File name: lab1p2.c
 * Author: Linyong Nan; Zichang Liu
 * Date: Feb 12, 2017
 * Description: This program read in one line of integer from 0 to 100
 * and output the average values to two decimal places.
 */

#include <stdio.h>

int main(void){
	//declare constants
	const int emptyDigit = -1;

	//declare variables
	char temp;
	int sum = 0;
	int count = 0;

	//declare and initialize digit counter
	int d1 = emptyDigit;
	int d2 = emptyDigit;
	int d3 = emptyDigit;

	// prompt for user input
	printf("Type the grades(integer values from 0 to 100) sequentially separated by one space and then press enter: \n");

	//read data
	temp = getchar();
	while (temp != '\n'){
		while(temp != ' ' && temp != '\n'){
			if(d1 == emptyDigit){
				//give digit to c1 and read one more
				d1 = temp - '0';
				temp = getchar();
			}
			else if(d2 == emptyDigit){
				//give digit to c2 and read one more
				d2 = temp - '0';
				temp = getchar();
			}
			else{
				//give digit to c3 and read one more
				d3 = temp - '0';
				temp = getchar();
			}
		}

		//save data
		if(d2 == emptyDigit){
			//number has only one digit
			sum += d1;
		}
		else if(d3 == emptyDigit){
			//number has two digits
			sum += d1 * 10 + d2;
		}
		else{
			//number has three digits, i.e. 100
			sum += d1 * 100 + d2 * 10 + d3;
		}
		//count number of grades
		count++;
		//stop reading when encounter a new line character.
		if (temp == '\n'){
			break;
		}
		//keep reading when encounter space characters
		while(temp == ' '){
			temp = getchar();
		}

		//reset the digit counter
		d1 = emptyDigit;
		d2 = emptyDigit;
		d3 = emptyDigit;
	}

	printf("\n\nYou have %d input grades. The average of them is: %.2f\n", count, (float) sum / count);

	return 0;
}
