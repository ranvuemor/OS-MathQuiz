#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>


char *readall(int fd);
char *fetch(char *url);
char *getQuestion(char *json);
int getAnswer(char *json);
int play(int n, int score, char *text, int answer);
