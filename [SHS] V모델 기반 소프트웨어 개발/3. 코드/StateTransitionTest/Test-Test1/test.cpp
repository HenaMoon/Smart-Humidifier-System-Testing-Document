#include "pch.h"
#include "../StateTransitionTest/Humidifier.h"
#include <stdbool.h>
#include <string>
using namespace std;

TEST(AutoOntoManualOnControllerTest1, modeinput) {
    EXPECT_EQ(Mode_Controller("1", Mode_Controller("4", 0, 0), 0), 40);
}

TEST(SetOntoManualOnControllerTest1, modeinput) {
    EXPECT_EQ(Mode_Controller("1", SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), 0), 0), 40);
}
TEST(AutoOntoManualOffControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("2", Mode_Controller("4", 0, 0), 1), 40);
}

TEST(SetOntoManualOffControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("2", SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), 0), 1), 40);
}
TEST(AutoOfftoManualOffControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("2", Mode_Controller("5", 0, 0), 0), 0);
}
TEST(SetofftoManualOffControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("2", SetOff_Controller(SetOn_Controller(1, 1, 0), 61, 60, 0), 0), 0);
}
TEST(SetOfftoManualOnControllerTest, modeinput) {
    EXPECT_EQ(Mode_Controller("1", SetOff_Controller(SetOn_Controller(1, 1, 0), 61, 60, 0), 0), 1);
}
TEST(AutoOntoManualOnControllerTest2, modeinput) {
    EXPECT_EQ(Mode_Controller("1", Mode_Controller("4", 0, 0), 1), 40);
}
TEST(SetOntoManualOnControllerTest2, modeinput) {
    EXPECT_EQ(Mode_Controller("1", SetOn_Controller(1, 1, 0), 1), 40);
}
TEST(AutoOntoAutoOffControllerTest1, modeinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", 0, 0), 45, 24, 0), 0), 34);
}
TEST(AutoOntoAutoOffControllerTest2, modeinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", 0, 0), 55, 22, 0), 0), 34);
}
TEST(AutoOntoAutoOffControllerTest3, modeinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", 0, 0), 65, 19, 0), 0), 34);
}
TEST(AutoOntoAutoOffControllerTest4, modeinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", 0, 0), 30, 24, 0), 0), 34);
}
TEST(AutoOntoAutoOffControllerTest5, modeinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", 0, 0), 40, 22, 0), 0), 34);
}
TEST(AutoOntoAutoOffControllerTest6, modeinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", 0, 0), 40, 19, 0), 0), 34);
}
TEST(AutoOfftoAutoOntoAutoOffController1, autoinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 45, 24, 0), 0), 34);
}
TEST(AutoOfftoAutoOntoAutoOffController2, autoinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 55, 22, 0), 0), 34);
}
TEST(AutoOfftoAutoOntoAutoOffController3, autoinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 65, 19, 0), 0), 34);
}
TEST(AutoOfftoAutoOntoAutoOffController4, autoinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 30, 24, 0), 0), 34);
}
TEST(AutoOfftoAutoOntoAutoOffController5, autoinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 40, 22, 0), 0), 34);
}

TEST(AutoOfftoAutoOntoAutoOffController6, autoinput) {
    EXPECT_EQ(Mode_Controller("5", Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 40, 19, 0), 0), 34);
}
TEST(ManualOntoAutoOnControllerTest, autoinput) {
    EXPECT_EQ(Mode_Controller("4", Mode_Controller("1", 0, 0), 0), 40);
}
TEST(ManualOntoAutoOffControllerTest, autoinput) {
    EXPECT_EQ(Mode_Controller("5", Mode_Controller("1", 0, 0), 1), 40);
}
TEST(SetOntoAutoOffControllerTest2, autoinput) {
    EXPECT_EQ(Mode_Controller("5", SetOn_Controller(1, 1, 0), 1), 40);
}
TEST(ManualOfftoAutoOffControllerTest, autoinput) {
    EXPECT_EQ(Mode_Controller("5", Mode_Controller("2", 0, 0), 0), 34);
}
TEST(SetOntoAutoOffControllerTest1, autoinput) {
    EXPECT_EQ(Mode_Controller("5", SetOn_Controller(1, 1, 0), 0), 34);
}
TEST(AutoOfftoAutoOnControllerHumiSucceedTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 45, 24, 0), 1);
}
TEST(AutoOfftoAutoOnControllerHumiSucceedTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 55, 22, 0), 1);
}
TEST(AutoOfftoAutoOnControllerHumiSucceedTest3, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 65, 19, 0), 1);
}
TEST(ManualOfftoAutoOnControllerHumiSucceedTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("2", 0, 0), 0), 45, 24, 0), 1);
}
TEST(ManualOfftoAutoOnControllerHumiSucceedTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("2", 0, 0), 0), 55, 22, 0), 1);
}
TEST(ManualOfftoAutoOnControllerHumiSucceedTest3, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("2", 0, 0), 0), 65, 19, 0), 1);
}
TEST(SetOntoSetOfftoAutoOnControllerHumiSucceedTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", SetOff_Controller(SetOn_Controller(1, 1, 0), 59, 60, 0), 0), 45, 24, 0), 1);
}
TEST(SetOntoSetOfftoAutoOnControllerHumiSucceedTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", SetOff_Controller(SetOn_Controller(1, 1, 0), 59, 60, 0), 0), 55, 22, 0), 1);
}
TEST(SetOntoSetOfftoAutoOnControllerHumiSucceedTest3, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", SetOff_Controller(SetOn_Controller(1, 1, 0), 59, 60, 0), 0), 65, 19, 0), 1);
}
TEST(AutoOfftoAutoOnControllerHumiFailTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 30, 24, 0), 1);
}
TEST(AutoOfftoAutoOnControllerHumiFailTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 40, 22, 0), 1);
}

TEST(AutoOfftoAutoOnControllerHumiFailTest3, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("5", 0, 0), 0), 40, 19, 0), 1);
}

TEST(ManualOfftoAutoOnControllerHumiFailTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("2", 0, 0), 0), 30, 24, 0), 1);
}
TEST(ManualOfftoAutoOnControllerHumiFailTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("2", 0, 0), 0), 40, 22, 0), 1);
}

TEST(ManualOntoAutoOffControllerHumiFailTest3, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", Mode_Controller("2", 0, 0), 0), 40, 19, 0), 1);
}

TEST(SetOntoSetOfftoAutoOnControllerHumiFailTest1, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", SetOff_Controller(SetOn_Controller(1, 1, 0), 59, 60, 0), 0), 30, 24, 0), 1);
}
TEST(SetOntoSetOfftoAutoOnControllerHumiFailTest2, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", SetOff_Controller(SetOn_Controller(1, 1, 0), 59, 60, 0), 0), 40, 22, 0), 1);
}

TEST(SetOntoSetOfftoAutoOnControllerHumiFailTest3, autoinput) {
    EXPECT_EQ(Auto_Controller(Mode_Controller("4", SetOff_Controller(SetOn_Controller(1, 1, 0), 59, 60, 0), 0), 40, 19, 0), 1);
}

TEST(RepeatSetOnControllerTest, setinput) {
    EXPECT_EQ(SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), SetOff_Controller(SetOn_Controller(Set_Controller("std", 60, 0, 0, 50), Set_Controller("std", 60, 0, 0, 50), 0), 61, 60, 0)), 1);
}
TEST(RepeatSetOffControllerTest1, setinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, 1, 0), 61, 60, SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), SetOff_Controller(SetOn_Controller(Set_Controller("std", 60, 0, 0, 50), Set_Controller("std", 60, 0, 0, 50), 0), 61, 60, 0))), 1);
}

TEST(RepeatSetOffControllerTest2, setinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), SetOff_Controller(SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), Mode_Controller("2", 0, 0)), 61, 60, 0)), 61, 60, 0), 0);
}
TEST(RepeatSetOffControllerTest3, setinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), SetOff_Controller(SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), Mode_Controller("5", 0, 0)), 61, 60, 0)), 61, 60, 0), 0);
}
TEST(AutoOntoSetOntoSetOffControllerTest, setoffinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, 1, Mode_Controller("4", 0, 0)), 61, 60, 0), 0);
}
TEST(AutoOfftoSetOntoSetOffControllerTest, setoffinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, 1, Mode_Controller("5", 0, 0)), 61, 60, 0), 0);
}
TEST(ManualOntoSetOntoSetOffControllerTest, setoffinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, 1, Mode_Controller("1", 0, 0)), 61, 60, 0), 0);
}
TEST(ManualOfftoSetOntoSetOffControllerTest, setoffinput) {
    EXPECT_EQ(SetOff_Controller(SetOn_Controller(1, 1, Mode_Controller("2", 0, 0)), 61, 60, 0), 0);
}
TEST(AutoOntoSetOnControllerTest, setoffinput) {
    EXPECT_EQ(SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), Mode_Controller("4", 0, 0)), 40);
}
TEST(ManualOntoSetOnControllerTest, setoffinput) {
    EXPECT_EQ(SetOn_Controller(1, Set_Controller("std", 60, 0, 0, 50), Mode_Controller("1", 0, 0)), 40);
}