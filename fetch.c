#include "quiz.h"
#include <errno.h>

char *fetch(char *url) {
    char *data;
    int fd[2], sz;
    if(pipe(fd) == -1){
	    perror("Error making pipe!!");
    }
    /*else{
	    printf("Success making pipe!\n");
    }*/

    pid_t pid = fork();
    if(pid == -1){
	    perror("Error forking!!");
    }
    /*else{
	    printf("Success forking!!\n");
    }*/

    char **arglist;
    arglist = (char **)malloc(4 * sizeof(char *));
    if(arglist == NULL){
	    perror("Error allocating memory!");
    }
    /*else{
	    printf("Success allocating memory!\n");
    }*/
    arglist[0] = "curl";
    arglist[1] = "-s";
    arglist[2] = url;
    arglist[3] = NULL;

    if (pid == 0){
	    close(fd[0]);
	    dup2(fd[1], STDOUT_FILENO);
	    execvp(arglist[0], arglist);
	    perror("Error curl!");
	    close(fd[1]);
    }

    else{
	    close(fd[1]);
            data = (char *)malloc(4096 * sizeof(char));	   
	    if (data == NULL){
		    perror("Error allocating memory!!!");
	    }
	    // printf("Success allocating memory!!!!\n");
	    sz = read(fd[0], data, 4095);
	    data[sz] = '\0';
	    close(fd[0]);

	    
    }

    return data;
 }	
