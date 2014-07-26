#include "frame.h"
#include "string"


void Frame::addSeg(const char* dir,const struct dirent *ent)
{
    Mat src;
    int thresh = 70;

    if (ent->d_name[0]!='.') {
        string temp = dir;
        temp += '/';
        temp += ent->d_name;
        src = imread(temp);
        cvtColor( src, src, CV_BGR2GRAY );

        /// Create Window + Show source image
        namedWindow( "Source", CV_WINDOW_AUTOSIZE );
        imshow( "Source", src );
        waitKey(0);

        /** @function thresh_callback */
        Mat threshold_output;
        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;
        /// Detect edges usingі Threshold
        threshold( src, threshold_output, thresh, 255, THRESH_BINARY );
        /// Find contours
        findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
        /// Rectangle making
        vector<Rect> boundRect( contours.size() );
        for( int i = 0; i < contours.size(); i++ )
        {
             boundRect[i] = boundingRect( Mat(contours[i]) );
        }
        /// Show in a window
        for (int i=0; i<boundRect.size();i++)
        {
            Mat drawing = src(boundRect[i]).clone();
            /*
            namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
            imshow( "Contours", drawing);
            waitKey(0);
            */
            Segment temp;
            temp.setPosition(contours[0][0]);
            temp.setImage(drawing);
            this->segments.push_back(temp);
        }
    }
}

Frame::Frame(const char* directory)
{
    DIR *dir = opendir( directory );
    if ( dir )
    {
        struct dirent *ent;
        while ((ent = readdir(dir))!=NULL)
        {
            addSeg(directory,ent);
        }
    }
    else
    {
    }
}

Segment Frame::getSegment(const uint i)
{
    return segments[i];
}

uint Frame::countSegment()
{
    return Frame::segments.size();
}
