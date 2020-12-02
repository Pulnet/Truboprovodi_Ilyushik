#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "ks.h"
#include "pipes.h"
using namespace std;

vector <int> search(vector <pipes> pipe_arr, vector <ks> ks_arr, int &pipes_or_ks);
void parcer(vector <int> &searchids, string sinput);
