#ifndef _UI_COURSE_HPP
#define _UI_COURSE_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

namespace ui {

class ECup {

    int id;

  public:
    inline ECup(int id) {
        this->id = id;
    }

    inline int operator*() {
        return this->id;
    }

    static int GetCupName(ECup cup);
    static int gCupNames[];
};

class CourseInfo {
  public:
    int id;
    int classicNameId;
    int courseNameId;
    bool isBattle;

    CourseInfo();
};

class CourseInfoList {
  public:
    CourseInfo courses[8];

    CourseInfoList();
};

class CupInfo {
  public:
    int cupIndex;
    int trackIndex;

    CupInfo();

    CupInfo(ECup cupId, int track);
};

class UICourseList {
  public:
    CourseInfoList cups[12];
    CourseInfoList battle;
    CupInfo cupPointers[80];
    CupInfo battlePointers[80];
    int currentCupId;
    int randoms1[4][4];
    int randoms2[4][4];
};

class CourseInfoListEx {
  public:
    int field_00;
    int field_04;
    CourseInfo courseInfo[48];
    int field_308; // -1
    int field_30C;
    int field_310;
    int field_314;
    int field_318; // -1
    int field_31C; // -1
};

enum MenuMode {
    LOCAL_SP = 1,
    LOCAL_MP = 2,
    WIFI_SP = 3,
    WIFI_MP = 4,
    SHOP = 5,
};

enum GameMode {
    GRAND_PRIX = 0,
    TIME_TRIAL = 1,
    VS_COURSE = 2,
    BATTLE = 3,
};

class CourseRelatedArray {
  public:
    MenuMode selectedMenuMode;
    int field_04;
    GameMode gameMode;
    int array0[4];
    int array1[4];
    int array2[4];
    int array3[4];
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int currentlySelectedCup;
    CourseInfo courseInfo;
    int field_A0;
    int field_A4;
};

class CourseData {
  public:
    UICourseList courseList;
    CourseInfoListEx courseInfoList;
    int field_F24;
    int field_F28;
    int field_F2C;
    int field_F30;
    int field_F34;
    int field_F38;
    int field_F3C;
    int field_F40;
    int field_F44;
    int field_F48;
    int field_F4C;
    int field_F50;
    int field_F54;
    int field_F58;
    int field_F5C;
    int field_F60;
    int field_F64;
    int field_F68;
    int field_F6C;
    int field_F70;
    int field_F74;
    int field_F78;
    int field_F7C;
    int field_F80;
    int field_F84;
    int field_F88;
    int field_F8C;
    int field_F90;
    int field_F94;
    int field_F98;
    int field_F9C;
    int field_FA0;
    int field_FA4;
    int field_FA8;
    int field_FAC;
    int field_FB0;
    int field_FB4;
    int field_FB8;
    int field_FBC;
    int field_FC0;
    int field_FC4;
    int field_FC8;
    int field_FCC;
    int field_FD0;
    int field_FD4;
    int field_FD8;
    int field_FDC;
    int field_FE0;
    int field_FE4;
    int field_FE8;
    int field_FEC;
    int field_FF0;
    int field_FF4;
    int field_FF8;
    int field_FFC;
    int field_1000;
    int field_1004;
    int field_1008;
    int field_100C;
    int field_1010;
    int field_1014;
    int field_1018;
    int field_101C;
    int field_1020;
    int field_1024;
    int field_1028;
    int field_102C;
    int field_1030;
    int field_1034;
    int field_1038;
    int field_103C;
    int field_1040;
    int field_1044;
    int field_1048;
    int field_104C;
    int field_1050;
    int field_1054;
    int field_1058;
    int field_105C;
    int field_1060;
    int field_1064;
    int field_1068;
    int field_106C;
    int field_1070;
    int field_1074;
    int field_1078;
    int field_107C;
    int field_1080;
    int field_1084;
    int field_1088;
    int field_108C;
    int field_1090;
    int field_1094;
    int field_1098;
    int field_109C;
    int field_10A0;
    int field_10A4;
    int field_10A8;
    int field_10AC;
    int field_10B0;
    int field_10B4;
    int field_10B8;
    int field_10BC;
    int field_10C0;
    int field_10C4;
    int field_10C8;
    int field_10CC;
    int field_10D0;
    int field_10D4;
    int field_10D8;
    int field_10DC;
    int field_10E0;
    int field_10E4;
    int field_10E8;
    int field_10EC;
    int field_10F0;
    int field_10F4;
    int field_10F8;
    int field_10FC;
    int field_1100;
    int field_1104;
    int field_1108;
    int field_110C;
    int field_1110;
    int field_1114;
    int field_1118;
    int field_111C;
    int field_1120;
    int field_1124;
    int field_1128;
    int field_112C;
    int field_1130;
    int field_1134;
    int field_1138;
    int field_113C;
    int field_1140;
    int field_1144;
    int field_1148;
    int field_114C;
    int field_1150;
    int field_1154;
    int field_1158;
    int field_115C;
    int field_1160;
    int field_1164;
    int field_1168;
    int field_116C;
    int field_1170;
    int field_1174;
    int field_1178;
    int field_117C;
    int field_1180;
    int field_1184;
    int field_1188;
    int field_118C;
    int field_1190;
    int field_1194;
    int field_1198;
    int field_119C;
    int field_11A0;
    int field_11A4;
    int field_11A8;
    int field_11AC;
    int field_11B0;
    int field_11B4;
    int field_11B8;
    int field_11BC;
    int field_11C0;
    int field_11C4;
    int field_11C8;
    int field_11CC;
    int field_11D0;
    int field_11D4;
    int field_11D8;
    int field_11DC;
    int field_11E0;
    int field_11E4;
    int field_11E8;
    int field_11EC;
    int field_11F0;
    int field_11F4;
    int field_11F8;
    int field_11FC;
    int field_1200;
    int field_1204;
    int field_1208;
    int field_120C;
    int field_1210;
    int field_1214;
    int field_1218;
    int field_121C;
    int field_1220;
    int field_1224;
    int field_1228;
    int field_122C;
    int field_1230;
    int field_1234;
    int field_1238;
    int field_123C;
    int field_1240;
    int field_1244;
    int field_1248;
    int field_124C;
    int field_1250;
    int field_1254;
    int field_1258;
    int field_125C;
    int field_1260;
    int field_1264;
    int field_1268;
    int field_126C;
    int field_1270;
    int field_1274;
    int field_1278;
    int field_127C;
    int field_1280;
    int field_1284;
    int field_1288;
    int field_128C;
    int field_1290;
    int field_1294;
    int field_1298;
    int field_129C;
    int field_12A0;
    int field_12A4;
    int field_12A8;
    int field_12AC;
    int field_12B0;
    int field_12B4;
    int field_12B8;
    int field_12BC;
    int field_12C0;
    int field_12C4;
    int field_12C8;
    int field_12CC;
    int field_12D0;
    int field_12D4;
    int field_12D8;
    int field_12DC;
    int field_12E0;
    int field_12E4;
    int field_12E8;
    int field_12EC;
    int field_12F0;
    int field_12F4;
    int field_12F8;
    int field_12FC;
    int field_1300;
    int field_1304;
    int field_1308;
    int field_130C;
    int field_1310;
    int field_1314;
    int field_1318;
    int field_131C;
    int field_1320;
    int field_1324;
    int field_1328;
    int field_132C;
    int field_1330;
    int field_1334;
    int field_1338;
    int field_133C;
    int field_1340;
    int field_1344;
    int field_1348;
    int field_134C;
    int field_1350;
    int field_1354;
    int field_1358;
    int field_135C;
    int field_1360;
    int field_1364;
    int field_1368;
    int field_136C;
    int field_1370;
    int field_1374;
    int field_1378;
    int field_137C;
    int field_1380;
    int field_1384;
    int field_1388;
    int field_138C;
    int field_1390;
    int field_1394;
    int field_1398;
    int field_139C;
    int field_13A0;
    int field_13A4;
    int field_13A8;
    int field_13AC;
    int field_13B0;
    int field_13B4;
    int field_13B8;
    int field_13BC;
    int field_13C0;
    int field_13C4;
    int field_13C8;
    int field_13CC;
    int field_13D0;
    int field_13D4;
    int field_13D8;
    int field_13DC;
    int field_13E0;
    int field_13E4;
    int field_13E8;
    int field_13EC;
    int field_13F0;
    int field_13F4;
    int field_13F8;
    int field_13FC;
    int field_1400;
    int field_1404;
    int field_1408;
    int field_140C;
    int field_1410;
    int field_1414;
    int field_1418;
    int field_141C;
    int field_1420;
    int field_1424;
    int field_1428;
    int field_142C;
    CourseRelatedArray courseRelatedData;
    int field_14D8;
    int field_14DC;
    int field_14E0;
    int field_14E4;
    int field_14E8;
    int field_14EC;
    int field_14F0;
    int field_14F4;
    int field_14F8;
    int field_14FC;
    int field_1500;
    int field_1504;
    int field_1508;
    int field_150C;
    int field_1510;
    int field_1514;
    int field_1518;
    int field_151C;
    int field_1520;
    int field_1524;
    int field_1528;
    int field_152C;
    int field_1530;
    int field_1534;
    int field_1538;
    int field_153C;
    int field_1540;
    int field_1544;
    int field_1548;
    int field_154C;
    int field_1550;
    int field_1554;
    int field_1558;
    int field_155C;
    int field_1560;
    int field_1564;
    int field_1568;
    int field_156C;
    int field_1570;
    int field_1574;
    int field_1578;
    int field_157C;
    int field_1580;
    int field_1584;
};
} // namespace ui

static_assert(sizeof(ui::CourseInfo) == 0x10, "Class doesn't match game class size");
static_assert(sizeof(ui::CourseInfoList) == 0x80, "Class doesn't match game class size");
static_assert(sizeof(ui::CupInfo) == 0x8, "Class doesn't match game class size");
static_assert(sizeof(ui::UICourseList) == 0xC04, "Class doesn't match game class size");
static_assert(sizeof(ui::CourseInfoListEx) == 0x320, "Class doesn't match game class size");
static_assert(sizeof(ui::CourseRelatedArray) == 0xA8, "Class doesn't match game class size");
static_assert(sizeof(ui::CourseData) == 0x1588, "Class doesn't match game class size");

#endif