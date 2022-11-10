#include "quiz.h"


int play(int n, int score, char *text, int answer) {
    int try = 0;
    int addscore = 8;
    int ans;
    int check = 0;
    printf("Q%d: What is %s?\n", n, text);
    while (addscore != 1  && check == 0) {
        printf("%d pt> ", addscore);
	if (scanf("%d", &ans) == EOF){
		printf("Exiting...\n");
		exit(1);
	};
	try += 1;
	if (ans > answer){
		printf("Too high, try again\n");
		addscore = addscore/2;
	}

	else if (ans < answer){
		printf("Too low, try again\n");
		addscore = addscore/2;
	}

	else {
		score += addscore;
		printf("Congratulations, your answer %d is correct.\n", ans);
		check = 1;
		try = -1;
		break;

    	}
    }
    if (try == 3){
	    printf("1 pt> ");
	    if (scanf("%d", &ans) == EOF){
			    printf("EOF\n");
			    exit(1);
	    };
	    try += 1;
	    if (ans == answer){
	    	score += 1;
	    	printf("Congratulations, your answer %d is correct.\n", ans);
	    	
	    }
	    else {
		addscore = addscore/2;
	    	if (ans > answer){
			printf("Too high, ");
		}
		else {
			printf("Too low, ");
		}
		printf("the correct answer was %d,\n", answer);
		
	    }
    } 
    
    return score;
}
