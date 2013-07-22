/* 
 * File:   main.cpp
 * Author: spork
 */

#include "main.h"
#include "BrightnessControl.h"
#include <cstdlib>

int width, height;
cv::VideoCapture imgcapture;
cv::Mat srcimg;

BrightnessControl bc;

int setupWebcam() {
    width = 320;
    height = 240;

    imgcapture.open(0);
    if (!imgcapture.isOpened()) {
        std::cerr << "No imaging device!" << std::endl;
        return -1;
    }

    imgcapture.set(CV_CAP_PROP_FRAME_WIDTH, width);
    imgcapture.set(CV_CAP_PROP_FRAME_HEIGHT, height);
}

/*
 * 
 */
int main(int argc, char** argv) {
    cvInitSystem(argc, argv);
    setupWebcam();
    
    cv::namedWindow("Output", CV_WINDOW_AUTOSIZE); // debug
    
    while(true) {
        // get image from webcam
        imgcapture.grab();
        imgcapture.retrieve(srcimg);
        if (srcimg.empty()) {
            std::cerr << "Problem getting an image from source" << std::endl;
            return -1;
        }
        
        // convert to grayscale; that's all we really need
        cv::Mat gray;
        cv::cvtColor(srcimg, gray, CV_BGR2GRAY);
        
        int level = bc.getBrightnessFromImage(gray);
        
        std::cout << "level: " << level << std::endl;
        
        // debug: display image
        cv::imshow("Output", gray);
        if(cvWaitKey(100) >= 0) break;
    }
    
    cvDestroyWindow("Output"); 
    return 0;
}

