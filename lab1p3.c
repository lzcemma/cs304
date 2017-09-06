/*
 * File name: lab1p3.c
 * Author: Linyong Nan; Zichang Liu
 * Date: Feb 12, 2017
 * Description: This program simulates the game "Rock Paper Scissors"
 * between user and computer.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	//declare enumerate type with three options
	enum options{
		rock, scissor, paper
	};
	//declare and initialize variables
	enum options userOption;
	enum options computerOption;
	char userInput;
	char exitStatus = 'Y';

	int random;


	while(exitStatus != 'N'){
		//prompt for user's option
		printf("Please type your choice. R for rock, S for scissor, P for paper: (Capital Letter only)\n");
		userInput = getchar();
		//get rid of '\n'
		getchar();

		//error handling: prompt if user type invalid input, and extract input again.
		while((userInput != 'R') && (userInput != 'S') && (userInput != 'P')){
			printf("\nInvalid option. You need to type either R, S or P and press enter.\n");
			printf("Please type your choice. R for rock, S for scissor, P for paper: (Capital Letter only)\n");
			userInput = getchar();
			//get rid of '\n'
			getchar();
		}

		//use switch statement to read user input
		switch(userInput){
		case 'R':
			userOption = rock;
			break;
		case 'S':
			userOption = scissor;
			break;
		case 'P':
			userOption = paper;
			break;
		}

		//use random method to determine the computer option
		random = rand() % 3;

		//use switch to declare winners
		switch(random){
		case 0:
			computerOption = rock;
			printf("\nComputer option: rock.\n");
			//computer option is rock: lose to paper, win scissor
			//and even with rock.
			switch(userOption){
			case rock:
				printf("\n\nEven.");
				break;
			case scissor:
				printf("\n\nUnfortunately, you lose.");
				break;
			case paper:
				printf("\n\nCongratulations! You win!");
				break;
			}
			break;
		case 1:
			computerOption = scissor;
			printf("\nComputer option: scissor.\n");
			//computer option is scissor: lose to rock, win paper
			//and even with scissor.
			switch(userOption){
			case rock:
				printf("\n\nCongratulations! You win!");
				break;
			case scissor:
				printf("\n\nEven.");
				break;
			case paper:
				printf("\n\nUnfortunately, you lose.");
				break;
			}
			break;
		case 2:
			computerOption = paper;
			printf("\nComputer option: paper.\n");
			//computer option is paper: lose to scissor, win rock
			//and even with paper.
			switch(userOption){
			case rock:
				printf("\n\nUnfortunately, you lose.");
				break;
			case scissor:
				printf("\n\nCongratulations! You win!");
				break;
			case paper:
				printf("\n\nEven.");
				break;
			}
			break;
		}

		//ask user whether continue or not
		printf("\nWant another round? Y/N: (Capital Letter only)\n");
		exitStatus = getchar();
		//get rid of the '\n'
		getchar();

		//error handling: prompt if user type invalid input and extract input again.
		while((exitStatus != 'Y') && (exitStatus != 'N')){
			printf("\nInvalid option. You need to type either Y or N and press enter.\n");
			printf("Want another round? Y/N: (Capital Letter only)\n");
			exitStatus = getchar();
			//get rid of the '\n'
			getchar();
		}


	}
	printf("\n\nYou have exited the game.\n");

	return 0;
}
