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
    string name, filename;
    double efficiency = 0;
    static int staticid2;
    int update(string filter);
    int changes(string filter, bool isdouble, bool characters, int pointer);
    void display();
    void this_to_file();
    void all_to_file(int pointer);
};

