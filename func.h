#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
#include "ks.h"
#include "pipes.h"
using namespace std;

vector <int> search(map <int, pipes> pipe_arr, map <int, ks> ks_arr, int &pipes_or_ks);
void parcer(vector <int> &searchids, string sinput);
