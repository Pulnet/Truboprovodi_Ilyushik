#include "ks.h"

ks::ks()
{
//    int id = 0, shopnumber = 0, shopsworking = 0;
//    string name;
//    double efficency = 0;

}

int ks::update()
{
    unsigned int i;
    int dotcounter = 0;
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
            dotcounter++;
            isdouble = true;
        }
        else if(filter[i] < '0' || filter[i] > '9' || dotcounter > 1 || filter[0] == '.')
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

    else if (filter[0] == 's' && filter[1] == 'n' && filter[2] == '_')
    {
        if(isdouble == false && characters == false)
        {
            core = filter.substr(3);
            shopnumber = std::stoi(core);
        }
        else
        {
            return 1; //ошибка - не целое число
        }
    }

    else if (filter[0] == 'e' && filter[1] == 'f' && filter[2] == '_')
    {
        if(characters == false)
        {
            core = filter.substr(3);
            if(std::stod(core) <= 1 && std::stod(core) >= 0)
            {
                efficiency = std::stod(core);
            }
            else
            {
                return 2; //ошибка - не число
            }
        }
        else
        {
            return 2; //ошибка - не число
        }
    }
    else if (filter[0] == 'n' && filter[1] == 'm' && filter[2] == '_')
    {
        core = filter.substr(3);
        name = core;
    }

    else if (filter[0] == 's' && filter[1] == 't' && filter[2] == 'a' && filter[3] == 'r' && filter[4] == 't' && filter[5] == 'w' && filter.length() == 6)
    {
        shopsworking++;
    }

    else if (filter[0] == 's' && filter[1] == 't' && filter[2] == 'o' && filter[3] == 'p' && filter[4] == 'w'  && filter.length() == 5)
    {
        if(shopsworking > 0)
        {
            shopsworking--;
        }else
        {
            return 5; //ошибка - не запущено ни одного цеха
        }

    }

    else if (filter[0] == 'o' && filter[1] == 'u' && filter[2] == 't' && filter.length() == 3)
    {
        printf("\nID number: %d\nName: ", id);
        for(i = 0; i < name.length(); i++)
        {
            printf("%c", name[i]);
        }
        printf("\nNumber of workshops: %d\nNumber of running workshops: %d\nOverall efficiency: %lf\n\n", shopnumber, shopsworking, efficiency);
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
