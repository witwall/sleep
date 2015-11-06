#include <stdio.h>
#include "sleep.h"
#include <windows.h>

int main(int argc, CHAR* argv[])
{
    if(argc != 2)
    {
        printUsageMessage();
        return 0;
    }
   
    long enteredParameter = strtol(argv[1], NULL, 10);
    
    
    long milliseconds = enteredParameter //* 1000;
    
    printf("Sleeping for %d milliseconds.\n", enteredParameter);
    
    Sleep(milliseconds);

	return 0;
}

void printUsageMessage()
{
    printf("\nsleep for Windows.\n");
    printf("Waits a certain amount of milliseconds before returning.\n");
    printf("---------------------------------------------------\n\n");
    printf("Usage: sleep AmountOfMilliseconds\n");
    printf("where AmountOfMilliseconds is the number of milliseconds\n");
    printf("to wait before returning.\n\n");
    printf("Example:\n");
    printf("\tsleep 300\n");
    printf("\tThis will wait 300 milliseconds (0.5 second) before\n");
    printf("\treturning.\n\n");
}
