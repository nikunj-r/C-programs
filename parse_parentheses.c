#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "stack_header.h"

const char closeMiss[] = "Close parantheses missing at line";
const char openMiss[] = "Open parantheses missing at line";

int main()
{
    STACK *stack;
    char token;
    char *dataptr;
    const char fileID[100];
    FILE *fpIn;
    int lineCount = 1;

    stack = createstack();
    printf("Enter a file ID for a file to be parsed\n");
    scanf("%s",&fileID);

    fpIn = fopen(fileID,"r");

    if(!fpIn)
    {
        printf("Error opening %s\n",fileID);
        exit(0);
    }

    while((token = fgetc(fpIn)) != EOF)
    {
        if(token == '\n')
        lineCount++;
        if(token == '(')
        {
            dataptr = (char*)malloc(sizeof(char));
            pushStack(stack,dataptr);
        }
        else
        {
            if(token == ')')                        //1 extra closing bracket
            {
                if(emptyStack(stack))
                {
                    printf("%s %d\n",openMiss,lineCount);
                    return 1;
                }
                else
                popStack(stack);

            }
        }
    }

    if(!emptyStack(stack))
    {
        printf("%s %d\n",closeMiss,lineCount);
        return 1;
    }

    printf("Parsing is done %d lines parsed\n",lineCount);

    return 0;
}
