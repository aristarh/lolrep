#ifndef SEGMENT_H
#define SEGMENT_H
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

class Segment
{
public:
    Segment();
    void setPosition( CvPoint pos);
    CvPoint getPosition();
    void setImage( cv::Mat matrix);
    cv::Mat getImage();
private:
    CvPoint position;
    cv::Mat image;
};

#endif // SEGMENT_H
