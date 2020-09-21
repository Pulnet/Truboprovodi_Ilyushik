#pragma once
#include <string>
#include <iostream>
using namespace std;

class pipes
{
public:
    pipes();
    int id  = 0;
    double length = 0, diam  = 0;
    bool is_repaired = false;
    int update();
};

