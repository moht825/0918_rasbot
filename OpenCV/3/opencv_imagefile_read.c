#include <opencv2/opencv.hpp>
#include <stdio.h>

#define IMG_Width     640
#define IMG_Height    480

using namespace cv;
using namespace std; 

int main(void)
{
    int img_width, img_height;
    img_width = 640;
    img_height = 480;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////OpenCV 변수 선언///////////////////////////////////////////
    
    Mat mat_image_org_color; // 이 줄이 추가되었습니다.
    Mat mat_image_org_gary_result;
    Mat image;

    Scalar GREEN(0,255,0);
    Scalar RED(0,0,255);
    Scalar BLUE(255,0,0);
    Scalar YELLOW(0,255,255);
    //////////////////////////////////////////////////////////////////////////////////////

    mat_image_org_color = imread("/home/pi/Team_aMAP/OpenCV/3/lane.bmp");
    
    if (mat_image_org_color.empty())
    {
        cerr << "빈 영상입니다. \n";
        return -1; // 빈 이미지일 때 프로그램 종료
    }

    img_width = mat_image_org_color.size().width;
    img_height = mat_image_org_color.size().height;

    printf("Image size[%3d,%3d]\n", img_width, img_height);
    
    namedWindow("Display window", CV_WINDOW_NORMAL); // CV_WINDOW_NORMAL로 유지
    resizeWindow("Display window", img_width, img_height);
    moveWindow("Display window", 10, 10);    
    
    while (1)
    {
        imshow("Display window", mat_image_org_color);
        if (waitKey(10) > 0)
            break;
    }
    
    destroyAllWindows();
    
    return 0;   
}

