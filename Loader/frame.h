#ifndef FRAME_H
#define FRAME_H
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "vector"
#include "segment.h"
#include <sys/types.h>
#include <dirent.h>

using namespace cv;
using namespace std;

class Frame
{
public:
    Frame(const char* directory);
    Segment getSegment(const uint i);
    uint countSegment();
private:
    void addSeg(const char* dir,const struct dirent *ent);
    vector <Segment> segments;
};

#endif // FRAME_H
