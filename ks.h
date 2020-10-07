#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//классы закоммичены до 23 сентября

class ks
{
public:
    ks();
    int id = 0, shopnumber = 0, shopsworking = 0;
    string name;
    double efficiency = 0;
    int update(string filter, unsigned int count);
    int readfile(string filter, unsigned int count);
};

