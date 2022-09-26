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


// Mode_Controller 1.3.1
int Mode_Controller(string mode_set, int error_signal, int error_check) {

    // Manual Mode Controller_On  1.3.2
    if (mode_set == "1") {
        error_signal++;
        return manual_mode_on(error_signal); 

    }

    // Manual Mode Controller_OFF 1.3.2
    else if (mode_set == "2") {
        if (error_check != 0) {
            return error_num;
        }
        error_signal = 0;
        return error_signal; 
    }

    // Auto Mode Controller_ON 1.3.3
    else if (mode_set == "4") {
        error_check++;
        error_signal++;
        if (error_signal > 1) {
            return error_num;
        }
        else {
            return error_signal; // Auto Mode Control ON 1.3.3.1
        }
    }
    // Auto Mode Controller_OFF 1.3.3
    else if (mode_set == "5") {
        error_signal = 0;
        error_check++;
        if (error_check > 1) {
            return error_num;
        }
        return auto_mode_off(); 

    }
    //else return error_num;

}

int manual_mode_on(int error_signal) {     
    if (error_signal > 1) {
        return error_num;
    }
    return error_signal;
}

int manual_mode_off() {  

    return manual_off_succeed;
}

int auto_mode_off() {    
    return auto_off_succeed;
}
// Auto Mode Control Succeed 1.3.3.1, Auto Mode Control Fail 1.3.3.2     
int Auto_Controller(int auto_control, float humidity, float temperature, int error_signal) {
    error_signal++;
    if (error_signal > 1) {
        return error_num;
    }

    if (auto_control == auto_control_succeed) {

        if (temperature >= 30 || temperature < 18) {
            return error_num;
        }
        else if (humidity > 90) {
            return error_num;
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족 1.3.3.1 
        else if (24 <= temperature && 40 <= humidity) {
            return auto_humi_succeed();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족X 1.3.3.2
        else if (24 <= temperature && humidity < 40) {
            return  auto_humi_fail();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족 1.3.3.1 
        else if (21 <= temperature <= 23 && 50 <= humidity) {
            return auto_humi_succeed();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족X 1.3.3.2
        else if (21 <= temperature <= 23 && humidity < 50) {
            return auto_humi_fail();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족 1.3.3.1 
        else if (18 <= temperature <= 20 && 60 <= humidity) {
            return auto_humi_succeed();
        }
        // 자동설정 켜진 상태에서 온도별 습도 만족X 1.3.3.2
        else if (18 <= temperature <= 20 && humidity < 60) {
            return auto_humi_fail();
        }
    }

}


int auto_humi_succeed() {        

    return auto_on_succeed;

}
int auto_humi_fail() {

    return auto_on_fail;
}

int setting_mode_on(int error_signal) {     
    if (error_signal > 1) {
        return error_num;
    }
    else {
        return error_signal;
    }
}
int setting_mode_off() {  
    return set_off_succeed;

}
int setting_mistake() {    

    return set_mistake;
}

int Set_Controller(string input_humi, float user_humi, int only_set, int higher_humi, float humidity) {
    if (input_humi == "std") {
        only_set = 1;
        if (only_set == 1 && humidity < user_humi) {
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

int SetOff_Controller(int pause, float humidity, float user_humi, int error_signal) {
    if (pause == 35 && humidity >= user_humi) {
        user_humi = 0;
        error_signal = 0;
        return setting_mode_off();
    }
    else {
        return error_signal;
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