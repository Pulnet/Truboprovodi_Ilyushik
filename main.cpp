#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "pipes.h"
#include "ks.h"


using namespace std;


int main()
{
    vector <pipes> pipe_arr;
    pipe_arr.emplace_back();
    vector <ks> ks_arr;
    ks_arr.emplace_back();
    int returned;
    unsigned int count = 0, maxcount;
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
        printf("\nEnter command.\nTo enter identifictior, type 'id_' before it, i.e. id_174 will set ID to 174,\n'ln_' for length,\n'dm_' for diameter.\n'repair_1' or 'repair_0' to switch repairing status.\n'out' to withdraw data on screen.\n'out_fall' to export data to file.\n'in_f' to import data from file.\n'next' and 'prev' to to modify next and pervious pipe.\n'ex' to close application.\n\n");
        while(1)
        {
            cin >> input;
            returned = pipe_arr[count].update(input, count);
            while (returned == 20)
            {
                pipe_arr.emplace_back();
                count++;
                maxcount = max(maxcount, count);
                returned = pipe_arr[count].update("in_f", count);
            }
            if (returned == 21)
            {
                maxcount = count;
                count = 0;
                while (count <= maxcount)
                {
                    returned = pipe_arr[count].update("out_f", count);
                    count++;
                    if(count <= maxcount)
                    {
                        returned = pipe_arr[count].update("spr_f", count);
                    }
                }
                count--;
                returned = pipe_arr[count].update("cls_f", count);

            }

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
            if (returned == 10)
            {
                if(pipe_arr.size() - 1 == count)
                {
                    pipe_arr.emplace_back();
                }
                count++;
                maxcount = max(maxcount, count);
            }
            if (returned == 11)
            {
                if(count == 0)
                {
                    printf("Error: this is the first pipe in the database.\n");
                }
                else
                {
                    count--;
                }
            }
            //system("cls"); потом доработаю чистку консоли
        }

    }
    else if(choise[0] == '2')
    {
        printf("\nEnter command.\nTo enter identifictior, type 'id_' before it, i.e. id_174 will set ID to 174,\n'sn_' for number of workshops,\n'startw' and 'stopw' to start and stop workshop.\n'rs_' to set amount of working workshops\n'ef_' for efficency (number between 0.0 and 1.0).\n'nm_' to change name.\n'out' to withdraw data on screen.\n'out_fall' to export data to file.\n'in_f' to import data from file.\n'next' and 'prev' to to modify next and pervious KS.\n'ex' to close application.\n\n");
        while(1)
        {
            cin >> input;
            returned = ks_arr[count].update(input, count);
            while (returned == 20)
            {
                ks_arr.emplace_back();
                count++;
                maxcount = max(maxcount, count);
                returned = ks_arr[count].update("in_f", count);
            }
            if (returned == 21)
            {
                maxcount = count;
                count = 0;
                while (count <= maxcount)
                {
                    returned = ks_arr[count].update("out_f", count);
                    count++;
                    if(count <= maxcount)
                    {
                        returned = ks_arr[count].update("spr_f", count);
                    }
                }
                count--;
                returned = ks_arr[count].update("cls_f", count);

            }
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
            if (returned == 10)
            {
                if(ks_arr.size() - 1 == count)
                {
                    ks_arr.emplace_back();
                }
                count++;
                maxcount = max(maxcount, count);
            }
            if (returned == 11)
            {
                if(count == 0)
                {
                    printf("Error: this is the first KS in the database.\n");
                }
                else
                {
                    count--;
                }
            }

        }
    }


    return 0;
}
