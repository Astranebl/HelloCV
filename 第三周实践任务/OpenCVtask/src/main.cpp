#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

int main(){
    //定义输入与输出路径
    string input_path = "/home/astra/OpenCVtask/resource/TrafficLight.mp4";
    string output_path = "/home/astra/OpenCVtask/resource/result.avi";
    VideoCapture cap(input_path);
    if (!cap.isOpened()){
        cout<<"无法打开视频"<<endl;
        return 0;
    }
    //获取视频的各项数据
    double fps = cap.get(CAP_PROP_FPS);
    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);
    int total_frames = cap.get(CAP_PROP_FRAME_COUNT);
    cout<<"视频信息:"<<endl;
    cout<<"尺寸"<<width<<"x"<<height<<endl;
    cout<<"帧率"<<fps<<endl;
    cout<<"总帧数"<<total_frames<<endl;

    //设置要写入视频的属性
    VideoWriter writer;
    int fourcc =VideoWriter::fourcc('M','J','P','G');
    writer.open(output_path,fourcc,fps,Size(width,height));
    if (!writer.isOpened()){
        cout<<"无法创建输出视频"<<endl;
        return 0;
    }

    cout<<"开始处理视频"<<endl;

    Mat frame;
    vector<vector<Point>> contours1,contours2;
    while(true){
        cap.read(frame);

        Mat gray1,gray2,hsv;
        cvtColor(frame,hsv,COLOR_BGR2HSV);

        //定义红绿灯颜色的阈值
        Scalar lower_green(80,150,150);
        Scalar upper_green(100,255,255);
        Scalar lower_red(170,50,50);
        Scalar upper_red(180,255,255);


        Mat green_mask,red_mask;
        inRange(hsv,lower_red,upper_red,red_mask);
        inRange(hsv,lower_green,upper_green,green_mask);
        
       
        Mat green_result,red_result;
        bitwise_and(hsv,hsv,green_result,green_mask);
        bitwise_and(hsv,hsv,red_result,red_mask);
        
       
        Mat sec_frame1,sec_frame2;
        cvtColor(red_result,sec_frame1,COLOR_HSV2BGR);
        cvtColor(green_result,sec_frame2,COLOR_HSV2BGR);
        cvtColor(sec_frame1,gray1,COLOR_BGR2GRAY);
        cvtColor(sec_frame2,gray2,COLOR_BGR2GRAY);
        
        
        Mat edges1,edges2;
        Canny(gray1,edges1,50,150);
        Canny(gray2,edges2,50,150);
       
       
        Mat kernel1 = getStructuringElement(MORPH_RECT,Size(27,27));
        Mat kernel2 = getStructuringElement(MORPH_RECT,Size(15,15));
        Mat dil1,dil2;
        dilate(edges1,dil1,kernel1);
        dilate(edges2,dil2,kernel2);
        findContours(dil1,contours1,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
        findContours(dil2,contours2,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
        
        for (size_t i = 0 ; i<contours1.size() ; i++){//对红色帧进行处理
            double area = contourArea(contours1[i]);
            if (area>55000){
                Moments m = moments(contours1[i]);
                Point center(m.m10/m.m00,m.m01/m.m00);
                line(frame,Point(center.x-100,center.y+100),Point(center.x+100,center.y+100),Scalar(255,0,0),5);
                line(frame,Point(center.x-100,center.y+100),Point(center.x-100,center.y-100),Scalar(255,0,0),5);
                line(frame,Point(center.x-100,center.y-100),Point(center.x+100,center.y-100),Scalar(255,0,0),5);
                line(frame,Point(center.x+100,center.y+100),Point(center.x+100,center.y-100),Scalar(255,0,0),5);
                putText(frame,"Red",Point(0,300),FONT_HERSHEY_SIMPLEX,6,Scalar(255,0,0),5);
            }
            
        }
        for (size_t i = 0 ; i<contours2.size() ; i++){//对绿色帧进行处理
            double area = contourArea(contours2[i]);
            if (area>36000){
                Moments m = moments(contours2[i]);
                Point center(m.m10/m.m00,m.m01/m.m00);
                line(frame,Point(center.x-100,center.y+100),Point(center.x+100,center.y+100),Scalar(255,0,0),5);
                line(frame,Point(center.x-100,center.y+100),Point(center.x-100,center.y-100),Scalar(255,0,0),5);
                line(frame,Point(center.x-100,center.y-100),Point(center.x+100,center.y-100),Scalar(255,0,0),5);
                line(frame,Point(center.x+100,center.y+100),Point(center.x+100,center.y-100),Scalar(255,0,0),5);
                putText(frame,"Green",Point(0,300),FONT_HERSHEY_SIMPLEX,6,Scalar(255,0,0),5);
            }
            
        }
        writer.write(frame);
        if(waitKey(1)==27)break;
    }
    cap.release();
    writer.release();
    destroyAllWindows();
    return 0;
}
