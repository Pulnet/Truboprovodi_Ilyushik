#include <iostream>
#include <string>
#include "pipes.h"


using namespace std;


int main()
{
    pipes pipe_one;
    int returned;
    printf("Enter number.\nTo enter identifictior, type 'id_' before it,\n'ln_' for length,\n'dm_' for diameter.\nType 'repair' to switch repairing status.\nType 'ex' to close application.\n\n");
    while(1)
    {
        returned = pipe_one.update();
        if (returned == 1)
        {
            printf("Error: not an integer number. Try again.\n");
        }
        if (returned == 2)
        {
            printf("Error: not a number. Try again.\n");
        }
        if (returned == 3)
        {
            return 0;
        }
        if (returned == 4)
        {
            printf("Error: not a command. Try again.\n");
        }
    }
    return 0;
}
