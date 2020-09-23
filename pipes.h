#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class pipes
{
public:
    pipes();
    int id  = 0;
    double length = 0, diam  = 0;
    bool is_repaired = false;
    int update(string filter, unsigned int count);
    int readfile(string filter, unsigned int count);
};

