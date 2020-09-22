#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ks
{
public:
    ks();
    int id = 0, shopnumber = 0, shopsworking = 0;
    string name;
    double efficiency = 0;
    int update(string filter);
    int readfile(string filter);
};

