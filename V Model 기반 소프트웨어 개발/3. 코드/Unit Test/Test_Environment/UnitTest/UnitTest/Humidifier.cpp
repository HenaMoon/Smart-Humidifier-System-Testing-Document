#include "Humidifier.h"
#include <stdbool.h>
#include <string>
using namespace std;


enum mode_type {
    manual_on_succeed = 30,
    manual_off_succeed,
    auto_on_succeed,
    auto_on_fail,
    auto_off_succeed,
    set_on_succeed,
    set_off_succeed,
    set_mistake,
    error_num = 40,
    auto_control_succeed = 41
};

string LCD_SET(float temp, float humi) {
    printf("temperature : %d , humidity : %d ", temp, humi);
    return "LCD SET ON";

}

// Water Level Inspection 1.2.1
bool WaterLevelInspection(int waterlevel) {

    if (waterlevel < 100) {

        return true;
    }

    else {

        return false;
    }

}

// Mode_Controller 1.3.1
int Mode_Controller(string mode_set, int error_signal) {

    // Manual Mode Controller_On  1.3.2
    if (mode_set == "1") {
        error_signal++;
        return manual_mode_on(error_signal); // 수동모드 ON을 실행하기 위한 함수 

    }

    // Manual Mode Controller_OFF 1.3.2
    else if (mode_set == "2") {
        error_signal = 0;
        return manual_mode_off(); // 수동모드 OFF를 실행하기 위한 함수
    }

    // Auto Mode Controller_ON 1.3.3
    else if (mode_set == "4") {
        error_signal++;
        if (error_signal > 1) {
            return error_signal;
        }
        return auto_control_succeed; // Auto Mode Control ON 1.3.3.1

    }
    // Auto Mode Controller_OFF 1.3.3
    else if (mode_set == "5") {
        error_signal = 0;
        return auto_mode_off(); // 자동모드 OFF를 실행하기 위한 함수

    }
    else return error_num;

}

int manual_mode_on(int error_signal) {     // 수동모드 기능을 ON 할때 실행
    if (error_signal > 1) {
        return error_num;
    }
    return manual_on_succeed;
}

int manual_mode_off() {    // 수동모드 기능을 OFF 할때 실행

    return manual_off_succeed;
}

int auto_mode_off() {    // 수동모드 기능을 OFF 할때 실행
    return auto_off_succeed;
}
// Auto Mode Control Succeed 1.3.3.1, Auto Mode Control Fail 1.3.3.2     
int Auto_Controller(int auto_control, float h, float t, int error_signal) {
    error_signal++;
    if (error_signal > 1) {
        return error_num;
    }

    if (auto_control == auto_control_succeed) {

        if (t >= 30 && h > 90) {
            return error_num;
        }
        else if (t < 18 && h > 90) {
            return error_num;
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족 1.3.3.1 
        else if (24 <= t <= 30 && 45 <= h) {           // t >= 32 && h >= 70
            return auto_humi_succeed();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족X 1.3.3.2
        else if (24 <= t <= 30 && h <= 35) {       // t >= 32 && h <= 60
            return  auto_humi_fail();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족 1.3.3.1 
        else if (21 <= t <= 23 && 55 <= h) { // 29 <= t <= 31 && h >= 65
            return auto_humi_succeed();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족X 1.3.3.2
        else if (21 <= t <= 23 && h <= 45) {  // 29 <= t <= 31 && h <= 55
            return auto_humi_fail();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족 1.3.3.1 
        else if (18 <= t <= 20 && 65 <= h) {  // 27 <= t <= 29 && h >= 55
            return auto_humi_succeed();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족X 1.3.3.2
        else if (18 <= t <= 20 && h <= 55) {  // 27 <= t <= 29 && h <= 50
            return auto_humi_fail();
        }
    }

}


int auto_humi_succeed() {        // 자동모드 기능에서 온도별 적정 습도를 벗어날 때 실행

    return auto_on_succeed;

}
int auto_humi_fail() {

    return auto_on_fail;
}

int setting_mode_on(int error_signal) {     // 습도 설정모드 기능 사용시 설정습도가 현재 습도 보다 높을 때 실행
    if (error_signal > 1) {
        return error_num;
    }
    return set_on_succeed;
}
int setting_mode_off() {   // 습도 설정모드 기능 사용시 설정습도가 현재습도보다 높게 셋팅 된 상태에서 현재습도가 설정습도값보다 클때
    return set_off_succeed;

}
int setting_mistake() {    // 습도 설정을 0미만 또는 90초과로 설정시 실행

    return set_mistake;
}

int Set_Controller(string input_humi, float user_humi, int only_set, int higher_humi, float h) {
    if (input_humi == "std") {
        only_set = 1;
        if (only_set == 1 && h < user_humi) {
            higher_humi = 1;
            return higher_humi;
        }
    }
    else {
        return error_num;
    }
}

int SetOn_Controller(int only_set, int higher_humi, int error_signal) {
    if (higher_humi == 1) {
        only_set = 0;
        error_signal++;
        return setting_mode_on(error_signal);
    }
    else {
        return error_num;
    }
}

int SetOff_Controller(int pause, float h, float user_humi, int error_signal) {
    if (pause == 35 && h >= user_humi) {
        user_humi = 0;
        error_signal = 0;
        return setting_mode_off();
    }
    else {
        return error_num;
    }
}
int Set_Mistake(int user_humi) {
    if (user_humi > 90 || user_humi < 0) {
        return setting_mistake();
    }
    else {
        return error_num;
    }
}
