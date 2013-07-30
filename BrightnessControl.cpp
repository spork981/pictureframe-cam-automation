/* 
 * File:   BrightnessControl.cpp
 * Author: spork
 */

#include "BrightnessControl.h"
#include "main.h"
#include <fstream>
#include <cstdio>
#include <cstdlib>

BrightnessControl::BrightnessControl() {
    
}

BrightnessControl::BrightnessControl(const BrightnessControl& orig) {
}

BrightnessControl::~BrightnessControl() {
}

bool BrightnessControl::setupBrightnessControl() {
    // only works on linux systems for now, requires xbacklight to change backlight settings
    std::ifstream backlightfile("/usr/bin/xbacklight");
    if(!backlightfile) return false;
    return true;
}

int BrightnessControl::getBrightnessFromImage(cv::Mat img) {
    cv::Scalar s = cv::mean(img);
        
    int lvl = s[0];
    return lvl;
}
    
int BrightnessControl::setBrightness(int level) {
    // < 1 is not valid
    if(level <= 0) level = 1;
    if(level > 100) level = 100;
    std::cout << "xbacklight -set " << level << std::endl;
    std::stringstream ss;
    ss <<  "xbacklight -set " << level;
    system(ss.str().c_str());
    return 0;
}