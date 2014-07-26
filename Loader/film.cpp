#include "film.h"
#include "iostream"

const string mainDir = "Segmentation";

Film::Film(char* mask)
{
    DIR *dir = opendir(mainDir.data());
    if ( dir )
    {
        struct dirent *ent;
        while ((ent = readdir(dir))!=NULL)
        {

            if (strstr(ent->d_name,mask)!=NULL)
            {
                cout << ent->d_name << endl;
                string tempStr=mainDir + '/';
                tempStr+=ent->d_name;
                Frame temp(tempStr.data());
                Film::frames.push_back(temp);
            }
        }
    }
    else
    {
    }
}

Frame Film::getFrame(uint i)
{
    return frames[i];
}

uint Film::countFrames()
{
    return frames.size();
}
