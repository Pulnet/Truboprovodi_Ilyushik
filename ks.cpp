#include "ks.h"

int ks::staticid2 = 0;
ks::ks():id(staticid2++)
{

}


int ks::update(string filter)
{
    unsigned int i;
    int dotcounter = 0;
    bool isdouble = false;
    bool characters = false;
    string core, temp_im_ex;


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
    if (filter[0] == 'i' && filter[1] == 'd' && filter[2] == '_' && filter.length() > 3)
    {
        return changes(filter, isdouble, characters, 1);
    }

    else if (filter[0] == 's' && filter[1] == 'n' && filter[2] == '_' && filter.length() > 3)
    {
        return changes(filter, isdouble, characters, 2);
    }

    else if (filter[0] == 'e' && filter[1] == 'f' && filter[2] == '_' && filter.length() > 3)
    {
        return changes(filter, isdouble, characters, 3);
    }

    else if (filter[0] == 'n' && filter[1] == 'm' && filter[2] == '_' && filter.length() > 3)
    {
        return changes(filter, isdouble, characters, 4);
    }

    else if (filter[0] == 'r' && filter[1] == 's' && filter[2] == '_' && filter.length() > 3)
    {
        return changes(filter, isdouble, characters, 5);
    }
    else if (filter[0] == 'f' && filter[1] == 'n' && filter[2] == '_' && filter.length() > 3)
    {
        return changes(filter, isdouble, characters, 6);
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
       display();
    }

    else if (filter[0] == 'o' && filter[1] == 'u' && filter[2] == 't' && filter[3] == '_' && filter[4] == 'f' && filter.length() == 5)
    {
        this_to_file();
    }
    else if (filter[0] == 'o' && filter[1] == 'u' && filter[2] == 't' && filter[3] == '_' && filter[4] == 'f' && filter[5] == 'a' && filter[6] == 'l' && filter[7] == 'l' && filter.length() == 8)
    {

        ofstream fout(filename);
        return 21;

    }

    else if (filter[0] == 'o' && filter[1] == 'u' && filter[2] == 't' && filter[3] == '_' && filter[4] == 'a' && filter[5] == 'l' && filter[6] == 'l'  && filter.length() == 7)
    {
        ofstream fout(filename);
        return 22;
    }

    else if (filter[0] == 's' && filter[1] == 'p' && filter[2] == 'r' && filter[3] == '_' && filter[4] == 'f' && filter.length() == 5)
    {
        ofstream fout(filename, ios_base::app);
        fout << "next" << endl;
    }

    else if (filter[0] == 'a' && filter[1] == 'l' && filter[2] == 'l' && filter[3] == '_'  && filter.length() == 5)
    {
        all_to_file(filter[4] - '0');
    }

    else if (filter[0] == 'n' && filter[1] == 'e' && filter[2] == 'x' && filter[3] == 't' && filter.length() == 4)
    {
        printf("\nSwitching to next KS...\n");
        return 10;
    }

    else if (filter[0] == 'p' && filter[1] == 'r' && filter[2] == 'e' && filter[3] == 'v' && filter.length() == 4)
    {
        printf("\nSwitching to previous KS...\n");
        return 11;
    }

    else if (filter[0] == 'a' && filter[1] == 'u' && filter[2] == 't' && filter[3] == 'o' && filter.length() == 4)
    {
        return 100;
    }

    else if (filter[0] == 's' && filter[1] == 'e' && filter[2] == 'a' && filter[3] == 'r' && filter[4] == 'c' && filter[5] == 'h' && filter.length() == 6)
    {
        return 101;
    }

    else if (filter[0] == 'e' && filter[1] == 'x' && filter.length() == 2)
    {
        return 3;
    }

    else if (filter[0] == 'p' && filter[1] == 'i' && filter[2] == 'p' && filter[3] == 'e' && filter.length() == 4)
    {
        return 12;
    }
    else
    {
        return 4; //ошибка - не команда
    }

    return 0;
}

int ks::changes(string filter, bool isdouble, bool characters, int pointer)
{
    string core;
    switch (pointer)
    {
    case 1:
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
        break;
    case 2:
        if(isdouble == false && characters == false)
        {
            core = filter.substr(3);
            shopnumber = std::stoi(core);
        }
        else
        {
            return 1; //ошибка - не целое число
        }
        break;
    case 3:
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
        break;
    case 4:
        core = filter.substr(3);
        name = core;
        break;
    case 5:
        if(isdouble == false && characters == false)
        {
            core = filter.substr(3);
            shopsworking = std::stoi(core);
        }
        else
        {
            return 1; //ошибка - не целое число
        }
        break;
    case 6:
        core = filter.substr(3);
        filename = core;
        break;
    }

    return 0;
}

void ks::display()
{
    unsigned int i;
    printf("\nID number: %d\nName: ", id);
    for(i = 0; i < name.length(); i++)
    {
        printf("%c", name[i]);
    }
    printf("\nNumber of workshops: %d\nNumber of running workshops: %d\nOverall efficiency: %lf\n\n", shopnumber, shopsworking, efficiency);
}

void ks::this_to_file()
{
    string temp_im_ex;
    //ввод и вывод из файла http://cppstudio.com/post/446/
    ofstream fout(filename, ios_base::app);
    temp_im_ex = "id_" + std::to_string(id); //инт в стринг https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
    fout << temp_im_ex << endl;

    temp_im_ex = "sn_" + std::to_string(shopnumber);
    fout << temp_im_ex << endl;

    temp_im_ex = "ef_" + std::to_string(efficiency);
    fout << temp_im_ex << endl;

    temp_im_ex = "nm_" + name;
    fout << temp_im_ex << endl;

    temp_im_ex = "rs_" + std::to_string(shopsworking);
    fout << temp_im_ex << endl;
}

void ks::all_to_file(int pointer)
{
    ofstream fout(filename, ios_base::app);
    switch (pointer)
    {
    case 1:
        fout << "next" << endl;
        break;
    case 2:
        fout << "swit" << endl;
        break;
    case 3:
        fout << "end";
        printf("\nSuccess!\n");
        break;
    }
}
