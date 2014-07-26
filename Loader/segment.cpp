#include "segment.h"

Segment::Segment()
{
}

void Segment::setPosition(CvPoint pos)
{
    Segment::position = pos;
}

CvPoint Segment::getPosition()
{
    return Segment::position;
}

void Segment::setImage(cv::Mat matrix)
{
    Segment::image = matrix;
}

cv::Mat Segment::getImage()
{
    return Segment::image;
}
