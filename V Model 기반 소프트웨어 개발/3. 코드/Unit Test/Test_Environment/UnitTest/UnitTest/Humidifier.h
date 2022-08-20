#pragma once
#include <iostream>
#include <stdbool.h>
#include <string>
using namespace std;

bool WaterLevelInspection(int waterlevel);
int Mode_Controller(string mode_set, int error_signal);
int manual_mode_on(int error_signal);
int manual_mode_off();
int auto_mode_off();
int Auto_Controller(int auto_control, float h, float t, int error_signal);
int auto_humi_succeed();
int auto_humi_fail();
int Set_Controller(string input_humi, float user_humi, int only_set, int higher_humi, float h);
int SetOn_Controller(int only_set, int higher_humi, int error_signal);
int setting_mode_on(int error_signal);
int SetOff_Controller(int pause, float h, float user_humi, int error_signal);
int setting_mode_off();
int Set_Mistake(int user_humi);
int setting_mistake();
string LCD_SET(float temp, float humi);