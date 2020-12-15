#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "ks.h"
#include "pipes.h"
using namespace std;


class graph
{
public:
    graph();

    vector <vector <double>> matrix;

    int initial(map <int, pipes> pipe_arr, map <int, ks> ks_arr);
    void build(map <int, pipes> pipe_arr, map <int, ks> ks_arr);
    void redact(map <int, pipes> pipe_arr, map <int, ks> ks_arr);
};

