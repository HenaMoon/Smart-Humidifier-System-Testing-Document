#include "pch.h"
#include "../UnitTest/Humidifier.h"
#include <stdbool.h>
#include <string>
using namespace std;

TEST(LcdSetTest, lcdinput) {
    EXPECT_EQ(LCD_SET(30, 90), "LCD SET ON");
}
TEST(WaterLevelInspectionTest, waterinput) {
    EXPECT_EQ(WaterLevelInspection(90), true);
}
TEST(WaterLevelLackInspectionTest, waterinput) {
    EXPECT_EQ(WaterLevelInspection(100), false);
}
TEST(ManualOnControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("1", 0), 30);
}
TEST(ManualOffControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("2", 0), 31);
}
TEST(AutoOnControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("4", 0), 41);
}
TEST(AutoOffControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("5", 0), 34);
}
TEST(ModeControllerErrorTest, modeinput) {
    EXPECT_EQ(Mode_Controller("*", 0), 40);
}
TEST(AutoOnControllerHumiSucceedTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", 0), 45, 24, 0), 32);
}
TEST(AutoOnControllerHumiSucceedTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", 0), 55, 22, 0), 32);
}
TEST(AutoOnControllerHumiSucceedTest3, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", 0), 65, 19, 0), 32);
}
TEST(AutoOnControllerHumiFailTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", 0), 30, 24, 0), 33);
}
TEST(AutoOnControllerHumiFailTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", 0), 40, 22, 0), 33);
}
TEST(AutoOnControllerHumiFailTest3, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", 0), 40, 19, 0), 33);
}
TEST(AutoOnControlErrorTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", 0), 100, 35, 0), 40);
}
TEST(AutoOnControlErrorTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", 0), 100, 15, 0), 40);
}
TEST(SetControllerTest, setinput) {
    EXPECT_EQ(Set_Controller("std", 60, 0, 0, 50), 1);
}
TEST(SetControllerErrorTest, setinput) {
    EXPECT_EQ(Set_Controller("error", 60, 0, 0, 50), 40);
}
TEST(SetOnControllerTest, setoninput) {
    EXPECT_EQ(SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), 0), 35);
}
TEST(SetOnControllerErrorTest, setoninput) {
    EXPECT_EQ(SetOn_Controller(1, Set_Controller("error", 60, 0, 0, 50), 0), 40);
}
TEST(SetOffControllerTest, setoffinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, 1, 0), 61, 60, 0), 36);
}
TEST(SetOffControllerErrorTest, setoffinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, 1, 0), 59, 60, 0), 40);
}
TEST(SetMistakeTest1, setoffinput) {
    EXPECT_EQ(Set_Mistake(91), 37);
}
TEST(SetMistakeTest2, setoffinput) {
    EXPECT_EQ(Set_Mistake(-10), 37);
}