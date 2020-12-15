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
    string name, filename;
    double length = 0, diam  = 0;
    bool is_repaired = false;
    static int staticid;
    int update(string filter);
    int return_id();
    int changes(string filter, bool isdouble, bool characters, int pointer);
    void display();
    void this_to_file();
    void all_to_file(int pointer);
};

