/* 
 * File:   BrightnessControl.h
 * Author: spork
 */

#ifndef BRIGHTNESSCONTROL_H
#define	BRIGHTNESSCONTROL_H

#include "main.h"

class BrightnessControl {
public:
    BrightnessControl();
    BrightnessControl(const BrightnessControl& orig);
    virtual ~BrightnessControl();
    int setBrightness(int lvl);
    int getBrightnessFromImage(cv::Mat img);
private:
    

};

#endif	/* BRIGHTNESSCONTROL_H */

