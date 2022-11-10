#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>


#define MAX_POINT 100
char *readall(int fd);
char *fetch(char *url);
char *getQuestion(char *json);
int getAnswer(char *json);
int play(unsigned n, unsigned score, char *text, int answer);
