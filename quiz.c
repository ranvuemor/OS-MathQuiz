#include "quiz.h"

int main(int argc, char *argv[]) {
    int gameNumber = 1;
    int score = 0;
    int addscore;
    printf("Answer questions with numbers in the range [1..100].\n");
    printf("You score points for each correctly answered question.\n");
    printf("If you need multiple attempts to answer a question, the points you score for a correct answer go down.\n\n");

    while (1) {
        char *json;
	
        json = fetch("http://numbersapi.com/random/math?min=1&max=100&fragment&json");
        addscore = play(gameNumber++, 0, getQuestion(json), getAnswer(json));
        
	score = score + addscore;
	printf("Your total score is %d/%d points.\n\n", score, ((gameNumber-1) * 8));
	
        free(json);
    }
    return 0;
}
