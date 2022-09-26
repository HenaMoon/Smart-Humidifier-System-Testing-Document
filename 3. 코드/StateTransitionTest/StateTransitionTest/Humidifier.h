#pragma once
#include <iostream>
#include <stdbool.h>
#include <string>
using namespace std;

int Mode_Controller(string mode_set, int error_signal, int error_check);
int manual_mode_on(int error_signal);
int manual_mode_off();
int auto_mode_off();
int Auto_Controller(int auto_control, float humidity, float temperature, int error_signal);
int auto_humi_succeed();
int auto_humi_fail();
int Set_Controller(string input_humi, float user_humi, int only_set, int higher_humi, float humidity);
int SetOn_Controller(int only_set, int higher_humi, int error_signal);
int setting_mode_on(int error_signal);
int SetOff_Controller(int pause, float humidity, float user_humi, int error_signal);
int setting_mode_off();
int Set_Mistake(int user_humi);
int setting_mistake();
#pragma once
