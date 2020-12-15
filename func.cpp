#include "func.h"
#include "ks.h"
#include "pipes.h"

vector <int> search(map <int, pipes> pipe_arr, map <int, ks> ks_arr, int &pipes_or_ks)
{
    int switchsearch;
    unsigned int j;
    vector <int> searchids;
    string sinput;

    //поиск
    printf("\nSelect search type:\n\n'1' - KS by name, \n'2' - KS by efficiency, \n'3' - Pipes by name,\n'4' - Pipes by repair status.\n");
    cin >> sinput;
    switchsearch = std::stoi(sinput);
    switch(switchsearch)
    {
    case 1:
        printf("\nEnter name:\n");
        pipes_or_ks = 2;
        cin >> sinput;
        for(j = 0; j < ks_arr.size(); j++)
        {
            if (ks_arr[j].name == sinput)
            {
                searchids.emplace_back(j);
            }
        }
        break;

    case 2:
        printf("\nEnter efficiency:\n");
        pipes_or_ks = 2;
        cin >> sinput;
        for(j = 0; j < ks_arr.size(); j++)
        {
            if (ks_arr[j].efficiency == std::stod(sinput))
            {
                searchids.emplace_back(j);
            }
        }
        break;

    case 3:
        printf("\nEnter name:\n");
        pipes_or_ks = 1;
        cin >> sinput;
        for(j = 0; j < pipe_arr.size(); j++)
        {
            if (pipe_arr[j].name == sinput)
            {
                searchids.emplace_back(j);
            }
        }
        break;

    case 4:
        printf("\nEnter repairing status: ('1' or '0')\n");
        pipes_or_ks = 1;
        cin >> sinput;
        for(j = 0; j < pipe_arr.size(); j++)
        {
            if (pipe_arr[j].is_repaired == std::stoi(sinput))
            {
                searchids.emplace_back(j);
            }
        }
        break;

    default:
        printf("\nError.\n");
        searchids.clear();
        return searchids;
        break;
    }


    //редактирование
    printf("\n%d results, IDs:\n", searchids.size());
    for(j = 0; j < searchids.size(); j++)
    {
        if(pipes_or_ks == 2)
        {
           printf("%d ", ks_arr[searchids[j]].id);
        }
        if(pipes_or_ks == 1)
        {
           printf("%d ", pipe_arr[searchids[j]].id);
        }

    }

    printf("\nProceed to editing? ('1' or '0')\n");
    cin >> sinput;
    if(std::stod(sinput) != 1)
    {
        searchids.clear();
        pipes_or_ks = 0;
    }
    return searchids;

}

