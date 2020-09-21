#include <iostream>
#include <string>
#include "pipes.h"
#include "ks.h"


using namespace std;


int main()
{
    pipes pipe_one;
    ks ks_one;
    int returned, choise;
    printf("Enter 1 to modify Pipes and 2 to modify KS.\n");
    cin >> choise;
    if(choise == 1)
    {
        printf("Enter number.\nTo enter identifictior, type 'id_' before it,\n'ln_' for length,\n'dm_' for diameter.\nType 'repair_1' or 'repair_0' to switch repairing status.\nType 'out' to withdraw data on screen.\nType 'ex' to close application.\n\n");
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

    }
    else if(choise == 2)
    {
        printf("Enter number.\nTo enter identifictior, type 'id_' before it,\n'sn_' for number of workshops,\nstartw' and 'stopw' to start and stop workshop.\n'ef_' for efficency (number from 0.0 to 1.0).\nType 'nm_' to change name.\nType 'out' to withdraw data on screen.\nType 'ex' to close application.\n\n");
        while(1)
        {
            returned = ks_one.update();
            if (returned == 1)
            {
                printf("Error: not an integer number. Try again.\n");
            }
            if (returned == 2)
            {
                printf("Error: not a valid number. Try again.\n");
            }
            if (returned == 3)
            {
                return 0;
            }
            if (returned == 4)
            {
                printf("Error: not a command. Try again.\n");
            }
            if (returned == 5)
            {
                printf("Error: no workshops are currently running.\n");
            }
        }
    }
    else
    {
        printf("Error: not a command. Try again.\n");
    }

    return 0;
}
