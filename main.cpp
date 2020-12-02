#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "pipes.h"
#include "ks.h"
#include "func.h"


using namespace std;


int main()
{
    vector <pipes> pipe_arr;
    pipe_arr.emplace_back();
    vector <ks> ks_arr;
    vector <int> searchids;
    ks_arr.emplace_back();
    int returned, pipes_or_ks = 0;
    unsigned int count = 0, maxcount, autoedit_step = 1, i = 0;
    bool switched = false, autoe = false;
    string input, choise, filename, error[20] = {"", "Error: not an integer number. Try again.\n",
                                       "Error: not a valid number. Try again.\n", "Error: not a command. Try again.\n",
                                       "Error: not a command. Try again.\n", "Error: no workshops are currently running.\n",
                                       "An error occured.\n", "", "", "", "Error: this is the first pipe in the database.\n",
                                       "Error: this is the first KS in the database.\n"};

    printf("Enter 1 to modify Pipes\n2 to modify KS\n3 to load from file.\n");

    while(1)
    {
        cin >> choise;
        if ((choise[0] != '1' && choise[0] != '2' && choise[0] != '3') || choise.length() > 1)
        {
            printf("%s", error[3].c_str());
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
            printf("\nEnter the command.\n\nType 'auto' to start automatic input.\n\nType 'search' to search Pipes.\n\nTo enter identifictior, type 'id_' before it, i.e. id_174 will set ID to 174,\n'ln_' for length,\n'dm_' for diameter.\n'repair_1' or 'repair_0' to switch repairing status.\n'nm_' to change name.\n\n'out' to withdraw data on screen.\n'out_fall' to export data to file.\n'next' and 'prev' to to modify next and pervious pipe.\n\n'ks' to switch to KS.\n'ex' to close application.\n\n");
            while(1)
            {
                //основной ввод
                if(autoe == false && pipes_or_ks == 0)
                {
                    cin >> input;
                    returned = pipe_arr[count].update(input);
                }
                if(autoe == true && pipes_or_ks == 0)
                {
                    //автоввод
                    switch (autoedit_step)
                    {
                    case 1:
                        printf("\nEnter length:\n");
                        cin >> input;
                        input = "ln_" + input;
                        returned = pipe_arr[count].update(input);
                        break;

                    case 2:
                        printf("\nEnter diameter:\n");
                        cin >> input;
                        input = "dm_" + input;
                        returned = pipe_arr[count].update(input);
                        break;

                    case 3:
                        printf("\nIs it under repair? ('1' or '0') \n");
                        cin >> input;
                        input = "repair_" + input;
                        returned = pipe_arr[count].update(input);
                        break;

                    case 4:
                        printf("\nEnter name:\n");
                        cin >> input;
                        input = "nm_" + input;
                        returned = pipe_arr[count].update(input);
                        break;

                    case 5:
                        printf("\nProceed to next pipe?('1' or '0')\n");
                        cin >> input;
                        autoedit_step = 0;
                        if(std::stod(input) == 1)
                        {
                            returned = pipe_arr[count].update("next");
                        }else
                        {
                            autoe = false;
                        }
                        break;
                    }
                    autoedit_step++;

                }


                if(pipes_or_ks != 0)
                {

                    if(pipes_or_ks == 1)
                    {
                        printf("\nEditing:\n");
                        pipe_arr[i].display();
                        switch (autoedit_step)
                        {
                        case 1:
                            printf("\nDo you want to edit this Pipe? ('1' or '0')\n");
                            cin >> input;
                            if(std::stod(input) != 1)
                            {
                                if(i + 1 != searchids.size())
                                {
                                    i++;
                                }else
                                {
                                    pipes_or_ks = 0;
                                }
                                autoedit_step = 0;
                            }
                            else
                            {
                                returned = 0;
                            }
                            break;

                        case 2:
                            printf("\nEnter length:\n");
                            cin >> input;
                            input = "ln_" + input;
                            returned = pipe_arr[searchids[i]].update(input);
                            break;

                        case 3:
                            printf("\nEnter diameter:\n");
                            cin >> input;
                            input = "dm_" + input;
                            returned = pipe_arr[searchids[i]].update(input);
                            break;

                        case 4:
                            printf("\nIs it under repair? ('1' or '0') \n");
                            cin >> input;
                            input = "repair_" + input;
                            returned = pipe_arr[searchids[i]].update(input);
                            break;

                        case 5:
                            printf("\nEnter name:\n");
                            cin >> input;
                            input = "nm_" + input;
                            returned = pipe_arr[searchids[i]].update(input);
                            break;

                        case 6:
                            printf("\nProceed to next Pipe?('1' or '0')\n");
                            cin >> input;
                            autoedit_step = 0;
                            if(std::stod(input) != 1 && i + 1 == searchids.size())
                            {
                                pipes_or_ks = 0;
                            }else
                            {
                                i++;
                            }
                            break;
                        }
                        autoedit_step++;


                    }
                }


                //вывод всего
                if (returned == 21)
                {
                    printf("\nEnter filename (default: 'all_data.txt'):\n");
                    cin >> filename;
                    pipe_arr[count].update("fn_" + filename);
                    ks_arr[count].update("fn_" + filename);

                    count = 0;
                    pipe_arr[count].update("out_fall");
                    while (count < pipe_arr.size())
                    {
                        returned = pipe_arr[count].update("out_f");
                        count++;
                        if(count < pipe_arr.size())
                        {
                            returned = pipe_arr[count].update("all_1");
                        }
                    }
                    count = 0;
                    returned = pipe_arr[count].update("all_2");
                    while (count < ks_arr.size())
                    {
                        returned = ks_arr[count].update("out_f");
                        count++;
                        if(count < ks_arr.size())
                        {
                            returned = ks_arr[count].update("all_1");
                        }
                    }

                    count--;
                    returned = ks_arr[count].update("all_3");

                }

                //вывод кода ошибки
                if (returned == 1 || returned == 2 || returned == 4)
                {
                    printf("%s", error[returned].c_str());
                    //про c_str https://stackoverflow.com/questions/10865957/printf-with-stdstring
                }
                if (returned == 3)
                {
                    return 0;
                }

                //создание новой трубы или переключение на следующую
                if (returned == 10)
                {
                    if(pipe_arr.size() - 1 == count)
                    {
                        pipe_arr.emplace_back();
                    }
                    count++;
                    maxcount = max(maxcount, count);
                }
                //переключение на предыдущую
                if (returned == 11)
                {
                    if(count == 0)
                    {
                        printf("%s", error[10].c_str());
                    }
                    else
                    {
                        count--;
                    }
                }
                //автоввод
                if (returned == 100)
                {
                    autoe = true;
                }

                //поиск
                if (returned == 101)
                {
                   searchids = search(pipe_arr, ks_arr, pipes_or_ks);
                   returned = 0;
                }

                //переключение на кс
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
            printf("\nEnter the command.\n\nType 'auto' to start automatic input.\n\nType 'search' to search Pipes and KS.\n\nTo enter identifictior, type 'id_' before it, i.e. id_174 will set ID to 174,\n'sn_' for number of workshops,\n'startw' and 'stopw' to start and stop workshop.\n'rs_' to set amount of working workshops\n'ef_' for efficency (number between 0.0 and 1.0).\n'nm_' to change name.\n\n'out' to withdraw data on screen.\n'out_fall' to export data to file.\n'next' and 'prev' to to modify next and pervious KS.\n\n'pipe' to switch to Pipes.\n'ex' to close application.\n\n");
            while(1)
            {
                //основной ввод
                if(autoe == false && pipes_or_ks == 0)
                {
                    cin >> input;
                    returned = ks_arr[count].update(input);
                }
                if(autoe == true && pipes_or_ks == 0)
                {
                    switch (autoedit_step)
                    {
                    case 1:
                        printf("\nEnter number of workshops:\n");
                        cin >> input;
                        input = "sn_" + input;
                        returned = ks_arr[count].update(input);
                        break;

                    case 2:
                        printf("\nEnter number of working workshops:\n");
                        cin >> input;
                        input = "rs_" + input;
                        returned = ks_arr[count].update(input);
                        break;

                    case 3:
                        printf("\nEnter efficency (number between 0.0 and 1.0):\n");
                        cin >> input;
                        input = "ef_" + input;
                        returned = ks_arr[count].update(input);
                        break;

                    case 4:
                        printf("\nEnter name:\n");
                        cin >> input;
                        input = "nm_" + input;
                        returned = ks_arr[count].update(input);
                        break;

                    case 5:
                        printf("\nProceed to next ks?('1' or '0')\n");
                        cin >> input;
                        autoedit_step = 0;
                        if(std::stod(input) == 1)
                        {
                            returned = ks_arr[count].update("next");
                        }else
                        {
                            autoe = false;
                        }
                        break;
                    }
                    autoedit_step++;
                }


                //редактирование поиска
                if(pipes_or_ks != 0)
                {

                    if(pipes_or_ks == 2)
                    {
                        printf("\nEditing:\n");
                        ks_arr[i].display();
                        switch (autoedit_step)
                        {
                        case 1:
                            printf("\nDo you want to edit this KS? ('1' or '0')\n");
                            cin >> input;
                            if(std::stod(input) != 1)
                            {
                                if(i + 1 != searchids.size())
                                {
                                    i++;
                                }else
                                {
                                    pipes_or_ks = 0;
                                }

                                autoedit_step = 0;
                            }
                            else
                            {
                                returned = 0;
                            }
                            break;

                        case 2:
                            printf("\nEnter number of workshops:\n");
                            cin >> input;
                            input = "sn_" + input;
                            returned = ks_arr[searchids[i]].update(input);
                            break;

                        case 3:
                            printf("\nEnter number of working workshops:\n");
                            cin >> input;
                            input = "rs_" + input;
                            returned = ks_arr[searchids[i]].update(input);
                            break;

                        case 4:
                            printf("\nEnter efficency (number between 0.0 and 1.0):\n");
                            cin >> input;
                            input = "ef_" + input;
                            returned = ks_arr[searchids[i]].update(input);
                            break;

                        case 5:
                            printf("\nEnter name:\n");
                            cin >> input;
                            input = "nm_" + input;
                            returned = ks_arr[searchids[i]].update(input);
                            break;

                        case 6:
                            printf("\nProceed to next ks?('1' or '0')\n");
                            cin >> input;
                            autoedit_step = 0;
                            if(std::stod(input) != 1 && i + 1 == searchids.size())
                            {
                                pipes_or_ks = 0;
                            }else
                            {
                                i++;
                            }
                            break;
                        }
                        autoedit_step++;


                    }
                }


                //вывод всего
                if (returned == 21)
                {
                    printf("\nEnter filename (default: 'all_data.txt'):\n");
                    cin >> filename;
                    pipe_arr[count].update("fn_" + filename);
                    ks_arr[count].update("fn_" + filename);

                    count = 0;
                    pipe_arr[count].update("out_fall");
                    while (count < pipe_arr.size())
                    {
                        returned = pipe_arr[count].update("out_f");
                        count++;
                        if(count < pipe_arr.size())
                        {
                            returned = pipe_arr[count].update("all_1");
                        }
                    }
                    count = 0;
                    returned = pipe_arr[count].update("all_2");
                    while (count < ks_arr.size())
                    {
                        returned = ks_arr[count].update("out_f");
                        count++;
                        if(count < ks_arr.size())
                        {
                            returned = ks_arr[count].update("all_1");
                        }
                    }

                    count--;
                    returned = ks_arr[count].update("all_3");
                }

                //вывод кода ошибки
                if (returned == 1 || returned == 2 || returned == 4 || returned == 5)
                {
                    printf("%s", error[returned].c_str());
                    //про c_str https://stackoverflow.com/questions/10865957/printf-with-stdstring
                }

                if (returned == 3)
                {
                    return 0;
                }

                //создание новой кс или переключение на следующую
                if (returned == 10)
                {
                    if(ks_arr.size() - 1 == count)
                    {
                        ks_arr.emplace_back();
                    }
                    count++;
                    maxcount = max(maxcount, count);
                }

                //переключение на предыдущую
                if (returned == 11)
                {
                    if(count == 0)
                    {
                        printf("%s", error[11].c_str());
                    }
                    else
                    {
                        count--;
                    }
                }

                //автоввод
                if (returned == 100)
                {
                    autoe = true;
                }

                //поиск
                if (returned == 101)
                {
                   searchids = search(pipe_arr, ks_arr, pipes_or_ks);
                   returned = 0;
                }

                //переключение на трубу
                if (returned == 12)
                {
                    choise[0] = '1';
                    count = 0;
                    break;
                }
            }
        }

        //считывание с файла
        else if(choise[0] == '3')
        {

            printf("\nEnter filename (default: 'all_data.txt'):\n");
            cin >> filename;
            ifstream fin(filename);
            count = 0;
            while(1)
            {

                fin >> input;
                if (!fin.is_open())
                {
                    printf("%s", error[6].c_str());
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
                        returned = pipe_arr[count].update(input);
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
                    returned = ks_arr[count].update(input);
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
