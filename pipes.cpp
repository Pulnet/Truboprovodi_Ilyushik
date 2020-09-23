#include "pipes.h"


pipes::pipes()
{

}
int pipes::update(string filter)
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
    if (filter[0] == 'i' && filter[1] == 'd' && filter[2] == '_' && filter.length() > 3)
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

    else if (filter[0] == 'l' && filter[1] == 'n' && filter[2] == '_' && filter.length() > 3)
    {
        if(characters == false)
        {
            core = filter.substr(3);
            length = std::stod(core);
        }
        else
        {
            return 2; //ошибка - не число
        }
    }

    else if (filter[0] == 'd' && filter[1] == 'm' && filter[2] == '_' && filter.length() > 3)
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

    else if (filter[0] == 'r' && filter[1] == 'e' && filter[2] == 'p' && filter[3] == 'a' && filter[4] == 'i' && filter[5] == 'r' && filter[6] == '_' && filter[7] == '1' && filter.length() == 8)
    {
        is_repaired = true;
    }

    else if (filter[0] == 'r' && filter[1] == 'e' && filter[2] == 'p' && filter[3] == 'a' && filter[4] == 'i' && filter[5] == 'r' && filter[6] == '_' && filter[7] == '0' && filter.length() == 8)
    {
        is_repaired = false;
    }

    else if (filter[0] == 'o' && filter[1] == 'u' && filter[2] == 't' && filter.length() == 3)
    {
        printf("\nID number: %d\nLength: %lf\nDiameter: %lf\nBeing repaired: ", id, length, diam);
        if(is_repaired == 1)
        {
            printf("Yes\n\n");
        }
        else
        {
            printf("No\n\n");
        }
    }

    else if (filter[0] == 'o' && filter[1] == 'u' && filter[2] == 't' && filter[3] == '_' && filter[4] == 'f' && filter.length() == 5)
    {
        //ввод и вывод из файла http://cppstudio.com/post/446/
        ofstream fout("pipes_data.txt");

        temp_im_ex = "id_" + std::to_string(id); //инт в стринг https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
        fout << temp_im_ex << endl;

        temp_im_ex = "ln_" + std::to_string(length);
        fout << temp_im_ex << endl;

        temp_im_ex = "dm_" + std::to_string(diam);
        fout << temp_im_ex << endl;

        temp_im_ex = "repair_" + std::to_string(is_repaired);
        fout << temp_im_ex << endl;

        fout << "end";

        printf("\nData was exported to pipes_data.txt\n");
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
            printf("There is no file named pipes_data.txt!\n");
        }
    }
    else if (filter[0] == 'n' && filter[1] == 'e' && filter[2] == 'x' && filter[3] == 't' && filter.length() == 4)
    {
        printf("\nSwitching to next pipe...\n");
        return 10;
    }

    else if (filter[0] == 'p' && filter[1] == 'r' && filter[2] == 'e' && filter[3] == 'v' && filter.length() == 4)
    {
        printf("\nSwitching to previous pipe...\n");
        return 11;
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

int pipes::readfile(string filter)
{
    //ввод и вывод из файла http://cppstudio.com/post/446/
    bool fileend = false;
    ifstream fin("pipes_data.txt");
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
