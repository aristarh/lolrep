#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "film.h"

using namespace cv;
using namespace std;

int main()
{
    Film ololo("Segmentation","AL_E102_s00025");
    Frame lol = ololo.getFrame(1) ;
    for (int i = 0;i<lol.countSegment();i++)
    {
        namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
        imshow( "Contours", lol.getSegment(i).getImage());
        waitKey(0);
    }
    return 0;
}

