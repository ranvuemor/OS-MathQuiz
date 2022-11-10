#include "quiz.h"

char *getQuestion(char * json) {
    char *p1;
    char *p2;
    char *question;
    question = malloc(1024);
    if (!question){
	    fprintf(stderr, "Error allocating memory (question)\n");
	    exit(EXIT_FAILURE);
    }
    // printf("Success allocating memory (question)\n");
    p1 = strstr(json, "\"text\": ");
    p1 += 9;
    p2 = strstr(p1, "\"number\": ");
    p2 -= 4;
    memcpy(question, p1, p2-p1);
    return question;
}

int getAnswer(char *json) {
    char *answer=json;
    
    int ans;
    answer = strstr(json, "\"number\": ");
    answer += 10;
    ans = strtol(answer, &answer, 10);
    return ans;
}
