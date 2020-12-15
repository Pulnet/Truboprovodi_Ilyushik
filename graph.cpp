#include "graph.h"

graph::graph()
{

}

int graph::initial(map <int, pipes> pipe_arr, map <int, ks> ks_arr)
{

    string ginput;
    matrix.resize(ks_arr.size(), vector<double>(ks_arr.size()));

    printf("\nDo you want to modify the net? ('1'/'0')");
    cin >> ginput;
    switch(std::stoi(ginput))
    {
    case 1:
        build(pipe_arr, ks_arr);
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

void graph::build(map<int, pipes> pipe_arr, map<int, ks> ks_arr)
{
    unsigned int count = 0, j, i;
    int station_1, station_2, max_pipe = pipe_arr.size();
    bool noninteger = false, valid = false;
    string ginput;
    while(count < max_pipe)
    {
        printf("\nPipe %d:\n", pipe_arr[count].id);

        printf("\nPipe together ------------------- %d:\n", pipe_arr.size());

        pipe_arr[count].display();
        printf("\nChoose the first station:\n");
        for(auto &i: ks_arr)
        {
            printf("%d\n", i.first);
        }
        cin >> ginput;

        for(j = 0; j < ginput.length(); j++)
        {
            if(ginput[j] < '0' || ginput[j] > '9')
            {
                noninteger = true;
            }
        }
        if(noninteger == false)
        {
            for(auto &i: ks_arr)
            {
                if(i.first == std::stoi(ginput))
                {
                    valid = true;
                }
            }
        }
        if(noninteger == false && valid == true)
        {
            valid = false;
            station_1 = std::stoi(ginput);

            printf("\nChoose the second station:\n");
            cin >> ginput;

            for(j = 0; j < ginput.length(); j++)
            {
                if(ginput[j] < '0' || ginput[j] > '9')
                {
                    noninteger = true;
                }
            }
            if(noninteger == false)
            {
                for(auto &i: ks_arr)
                {
                    if(i.first == std::stoi(ginput))
                    {
                        valid = true;
                    }
                }
            }
            if(noninteger == false && valid == true)
            {
                station_2 = std::stoi(ginput);
                count++;
                valid = false;

            }else
            {
                printf("\nNot a valid ID!\n");
                noninteger = false;

            }
        }else
        {
            printf("\nNot a valid ID!\n");
            noninteger = false;
        }

        matrix[station_1][station_2] = pipe_arr[count].diam;
    }

    printf("\nResult graph (Adjacency matrix):\n");
    for(j = 0; j < ks_arr.size(); j++)
    {
        for(i = 0; i < ks_arr.size(); i++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
}
