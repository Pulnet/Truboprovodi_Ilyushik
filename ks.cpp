#include "ks.h"

ks::ks()
{

}


int ks::update(string filter)
{
    unsigned int i;
    int dotcounter = 0, error = 0;
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

    else if (filter[0] == 'r' && filter[1] == 's' && filter[2] == '_')
    {
        if(isdouble == false && characters == false)
        {
            core = filter.substr(3);
            shopsworking = std::stoi(core);
        }
        else
        {
            return 1; //ошибка - не целое число
        }
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

    else if (filter[0] == 'o' && filter[1] == 'u' && filter[2] == 't' && filter[3] == '_' && filter[4] == 'f' && filter.length() == 5)
    {
        //ввод и вывод из файла http://cppstudio.com/post/446/
        ofstream fout("ks_data.txt");

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

        fout << "end";

        printf("\nData was exported to ks_data.txt\n");
    }

    else if (filter[0] == 'i' && filter[1] == 'n' && filter[2] == '_' && filter[3] == 'f' && filter.length() == 4)
    {
        printf("\nImporting data...\n");
        error = this->readfile(filter);
        if(error == 0)
        {
            printf("Success!\n");
        }else
        {
            printf("There is no file named ks_data.txt!\n");
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


int ks::readfile(string filter)
{
    //ввод и вывод из файла http://cppstudio.com/post/446/
    bool fileend = false;
    ifstream fin("ks_data.txt");
    if (!fin.is_open())
    {
        return 1;
    }
    while(fileend == false)
    {
        if(filter == "end")
        {
            fileend = true;
        }

        fin >> filter;
        this->update(filter);
    }
    return 0;
}
