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
    
    // The user enters seconds, so we need to convert that into milliseconds.
    long milliseconds = enteredParameter * 1000;
    
    printf("Sleeping for %d seconds.\n", enteredParameter);
    
    Sleep(milliseconds);

	return 0;
}

void printUsageMessage()
{
    printf("\nsleep for Windows.\n");
    printf("Waits a certain amount of seconds before returning.\n");
    printf("---------------------------------------------------\n\n");
    printf("Usage: sleep AmountOfSeconds\n");
    printf("where AmountOfSeconds is the number of seconds\n");
    printf("to wait before returning.\n\n");
    printf("Example:\n");
    printf("\tsleep 300\n");
    printf("\tThis will wait 300 seconds (5 minutes) before\n");
    printf("\treturning.\n\n");
}
