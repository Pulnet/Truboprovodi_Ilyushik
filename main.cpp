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
    bool switched = false;
    string input, choise;


    printf("Enter 1 to modify Pipes\n2 to modify KS\n3 to load from file.\n");

    while(1)
    {
        cin >> choise;
        if ((choise[0] != '1' && choise[0] != '2' && choise[0] != '3') || choise.length() > 1)
        {
            printf("Error: not a command. Try again.\n");
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(choise[0] == '1')
        {
            printf("\nEnter the command.\nTo enter identifictior, type 'id_' before it, i.e. id_174 will set ID to 174,\n'ln_' for length,\n'dm_' for diameter.\n'repair_1' or 'repair_0' to switch repairing status.\n\n'out' to withdraw data on screen.\n'out_fall' to export data to file.\n'next' and 'prev' to to modify next and pervious pipe.\n\n'ks' to switch to KS.\n'ex' to close application.\n\n");
            while(1)
            {
                cin >> input;
                returned = pipe_arr[count].update(input, count);
                if (returned == 21)
                {
                    count = 0;
                    while (count < pipe_arr.size())
                    {
                        returned = pipe_arr[count].update("out_f", count);
                        count++;
                        if(count < pipe_arr.size())
                        {
                            returned = pipe_arr[count].update("spr_f", count);
                        }
                    }
                    count = 0;
                    returned = pipe_arr[count].update("swt_f", count);
                    while (count < ks_arr.size())
                    {
                        returned = ks_arr[count].update("out_f", count);
                        count++;
                        if(count < ks_arr.size())
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
                if (returned == 12)
                {
                    choise[0] = '2';
                    count = 0;
                    break;
                }
            }

        }
        else if(choise[0] == '2')
        {
            printf("\nEnter the command.\nTo enter identifictior, type 'id_' before it, i.e. id_174 will set ID to 174,\n'sn_' for number of workshops,\n'startw' and 'stopw' to start and stop workshop.\n'rs_' to set amount of working workshops\n'ef_' for efficency (number between 0.0 and 1.0).\n'nm_' to change name.\n\n'out' to withdraw data on screen.\n'out_fall' to export data to file.\n'next' and 'prev' to to modify next and pervious KS.\n\n'pipe' to switch to Pipes.\n'ex' to close application.\n\n");
            while(1)
            {
                cin >> input;
                returned = ks_arr[count].update(input, count);
                if (returned == 21)
                {

                    count = 0;
                    while (count < pipe_arr.size())
                    {
                        returned = pipe_arr[count].update("out_f", count);
                        count++;
                        if(count < pipe_arr.size())
                        {
                            returned = pipe_arr[count].update("spr_f", count);
                        }
                    }
                    count = 0;
                    returned = pipe_arr[count].update("swt_f", count);
                    while (count < ks_arr.size())
                    {
                        returned = ks_arr[count].update("out_f", count);
                        count++;
                        if(count < ks_arr.size())
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
                if (returned == 12)
                {
                    choise[0] = '1';
                    count = 0;
                    break;
                }


            }
        }
        else if(choise[0] == '3')
        {
            ifstream fin("all_data.txt");
            count = 0;
            while(1)
            {

                fin >> input;
                if (!fin.is_open())
                {
                    printf("An error occured.\n");
                    break;
                }
                if(switched == false)
                {
                    if (input[0] == 's' && input[1] == 'w' && input[2] == 'i' && input[3] == 't' && input.length() == 4)
                    {
                        switched = true;
                        count = 0;
                    }else
                    {
                        returned = pipe_arr[count].update(input, count);
                    }

                    if (returned == 10)
                    {
                        count++;
                        pipe_arr.emplace_back();
                    }

                }else
                {
                    if (input[0] == 'e' && input[1] == 'n' && input[2] == 'd' && input.length() == 3)
                    {
                        break;
                    }
                    returned = ks_arr[count].update(input, count);
                    if (returned == 10)
                    {
                        count++;
                        ks_arr.emplace_back();
                    }

                }
            }
            printf("Success!\n");
            count = 0;
            choise[0] = '1';

        }
    }



    return 0;
}
