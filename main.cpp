#include <iostream>
#include <string>
#include "pipes.h"
#include "ks.h"


using namespace std;


int main()
{
    pipes pipe_one;
    ks ks_one;
    int returned;
    string input, choise;
    printf("Enter 1 to modify Pipes and 2 to modify KS.\n");

    while(1)
    {
        cin >> choise;
        if ((choise[0] != '1' && choise[0] != '2') || choise.length() > 1)
        {
            printf("Error: not a command. Try again.\n");
        }
        else
        {
            break;
        }
    }

    if(choise[0] == '1')
    {
        printf("\nEnter command.\nTo enter identifictior, type 'id_' before it, i.e. id_174 will set ID to 174,\n'ln_' for length,\n'dm_' for diameter.\n'repair_1' or 'repair_0' to switch repairing status.\n'out' to withdraw data on screen.\n'out_f' to export data to file.\n'in_f' to import data from file.\n'ex' to close application.\n\n");
        while(1)
        {
            cin >> input;
            returned = pipe_one.update(input);
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
    else if(choise[0] == '2')
    {
        printf("\nEnter command.\nTo enter identifictior, type 'id_' before it, i.e. id_174 will set ID to 174,\n'sn_' for number of workshops,\n'startw' and 'stopw' to start and stop workshop.\n'rs_' to set amount of working workshops\n'ef_' for efficency (number between 0.0 and 1.0).\n'nm_' to change name.\n'out' to withdraw data on screen.\n'out_f' to export data to file.\n'in_f' to import data from file.\n'ex' to close application.\n\n");
        while(1)
        {
            cin >> input;
            returned = ks_one.update(input);
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


    return 0;
}
