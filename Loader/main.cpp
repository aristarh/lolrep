#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "film.h"

using namespace cv;
using namespace std;

int main()
{
    Film ololo("AL_E102_s00025");
    /*Frame ololo("Segmentation/AL_E102_s00014_723");
    for (int i = 0;i<ololo.countSegment();i++)
    {
        namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
        imshow( "Contours", ololo.getSegment(i).getImage());
        waitKey(0);
    }*/
    return 0;
}

