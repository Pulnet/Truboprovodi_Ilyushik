#include "pipes.h"


pipes::pipes()
{

}
int pipes::update()
{
    unsigned int i;
    //int temp = 0;
    bool isdouble = false;
    bool characters = false;
    string filter, core;

    //считывание введенной строки
    cin >> filter;

    //проверяем ее на наличие точек и прочих символов
    for(i = 3; i < filter.length(); i++)
    {
        if(filter[i] == '.')
        {
            isdouble = true;
        }
        else if(filter[i] < '0' || filter[i] > '9')
        {
            characters = true;
        }
    }

    //выясняем команду и обрабатываем данные
    if (filter[0] == 'i' && filter[1] == 'd' && filter[2] == '_')
    {
        if(isdouble == false && characters == false)
        {
            //о субстракте http://www.cplusplus.com/reference/string/string/substr/
            core = filter.substr(3);
            id = std::stoi(core);
        }
        else
        {
            return 1; //ошибка - не целое число
        }
    }

    else if (filter[0] == 'l' && filter[1] == 'n' && filter[2] == '_')
    {
        if(characters == false)
        {
            core = filter.substr(3);
            length = std::stod(core);
            //printf("%lf", diam);
        }
        else
        {
            return 2; //ошибка - не число
        }
    }

    else if (filter[0] == 'd' && filter[1] == 'm' && filter[2] == '_')
    {
        if(characters == false)
        {
            core = filter.substr(3);
            diam = std::stod(core);
            //printf("%lf", diam);
        }
        else
        {
            return 2; //ошибка - не число
        }
    }

    else if (filter[0] == 'r' && filter[1] == 'e' && filter[2] == 'p' && filter[3] == 'a' && filter[4] == 'i' && filter[5] == 'r' && filter.length() == 6)
    {
        if(is_repaired == false)
        {
            is_repaired = true;
        }
        else
        {
            is_repaired = false;
        }
    }
    else if (filter[0] == 'e' && filter[1] == 'x' && filter.length() == 2)
    {
        return 3;
    }
    else
    {
        return 4; //ошибка - не команда
    }



    return 0;
}
