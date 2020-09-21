#pragma once
#include <string>
#include <iostream>
using namespace std;

class ks
{
public:
    ks();
    int id = 0, shopnumber = 0, shopsworking = 0;
    string name;
    double efficiency = 0;
    int update();
};

