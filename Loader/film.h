#ifndef FILM_H
#define FILM_H
#include "frame.h"
#include "vector"
#include <sys/types.h>
#include <dirent.h>
#include "string"

class Film
{
public:
    Film(char* mainDirectory,char* mask);
    Frame getFrame(uint i);
    uint countFrames();
private:
    vector <Frame> frames;
};

#endif // FILM_H
