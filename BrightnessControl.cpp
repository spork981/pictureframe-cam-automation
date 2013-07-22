/* 
 * File:   BrightnessControl.cpp
 * Author: spork
 */

#include "BrightnessControl.h"
#include "main.h"

BrightnessControl::BrightnessControl() {
    
}

BrightnessControl::BrightnessControl(const BrightnessControl& orig) {
}

BrightnessControl::~BrightnessControl() {
}

int BrightnessControl::getBrightnessFromImage(cv::Mat img) {
    cv::Scalar s = cv::mean(img);
        
    int lvl = s[0];
    return lvl;
}
    
int BrightnessControl::setBrightness(int level) {
        
    return 0;
}