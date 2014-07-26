#include "film.h"
#include "iostream"
#include "algorithm"

Film::Film(char* mainDirectory,char* mask)
{
    DIR *dir = opendir(mainDirectory);
    if ( dir )
    {
        struct dirent *ent;
        vector <string> directories;
        while ((ent = readdir(dir))!=NULL)
        {
            if (strstr(ent->d_name,mask)!=NULL)
            {
                string tempStr=mainDirectory;
                tempStr+='/';
                tempStr+=ent->d_name;
                directories.push_back(tempStr);
            }
        }
        std::sort(directories.begin(),directories.end());
        for ( int i = 0; i < directories.size(); i++)
        {
            Frame temp(directories[i].data());
            Film::frames.push_back(temp);
        }
    }
    else
    {
        cout<<"Directory not found"<<endl;
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
