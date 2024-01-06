#ifndef KART_VEHICLE_H
#define KART_VEHICLE_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace object {
typedef class KartVehicle KartVehicle;
}

#include <mk8/object/Kart/KartBalloon.h>
#include <mk8/object/Kart/KartChassis.h>
#include <mk8/object/Kart/KartChassisAnim.h>
#include <mk8/object/Kart/KartCollision.h>
#include <mk8/object/Kart/KartHeadLight.h>
#include <mk8/object/Kart/KartJugemRecover.h>
#include <mk8/object/Kart/KartParameter.h>
#include <mk8/object/Kart/KartSusKit.h>
#include <mk8/object/Kart/KartUnit.h>
#include <mk8/object/Kart/KartVehicleBody.h>
#include <mk8/object/Kart/KartVehicleControl.h>
#include <mk8/object/Kart/KartVehicleCpu.h>
#include <mk8/object/Kart/KartVehicleMove.h>
#include <mk8/object/Kart/KartVehicleNet.h>
#include <mk8/object/Kart/KartVehicleReact.h>
#include <mk8/object/Kart/KartVehicleTrick.h>
#include <mk8/object/Recorder/RecorderForKart.h>
#include <mk8/object/Recorder/RecorderKartEvent.h>
#include <mk8/object/Recorder/RecorderKartVehicle.h>

namespace object {
class KartVehicle {
  public:
    void* vtable;
    KartUnit* unit;
    KartVehicleControl* vehicleControl;
    KartVehicleCpu* vehicleCpu;
    KartVehicleNet* vehicleNet;
    KartVehicleMove* vehicleMove;
    KartVehicleTrick* vehicleTrick; // should be a gsys::model*
    KartVehicleBody* vehicleBody;
    KartVehicleReact* vehicleReact;
    KartCollision* collision;
    KartChassis* chassis;
    KartChassisAnim* chassisAnim;
    KartHeadLight* headLight;
    KartSusKit* susKit;
    KartBalloon* balloon;
    KartParameter* parameter;
    RecorderForKart* recorder;
    RecorderKartEvent* recorderEvent;
    RecorderKartVehicle* recorderVehicle;
    KartJugemRecover* jugemRecover;
    int playerID;
    int bodyID;
    int driverID;
    int field_5C;
    int field_60;
    uint8_t isMaster;
    uint8_t field_65;
    uint8_t isCpu;
    uint8_t isCpuOrKiller;
    int field_68;
    uint8_t isBike;
    uint8_t field_6D;
    uint8_t field_6E;
    uint8_t field_6F;
    int field_70;
    int field_74;
    uint8_t field_78;
    uint8_t isZombie;
    uint8_t isZombieTrigger;
    uint8_t field_7B;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    float waterDepth;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int action;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int isGoal;
    int field_140;
    /*
        Binary AND
        (kartState>>12) & 1 -> isAntiG
        (kartState>>6) & 1 -> isInWheelSpin
        (kartState>>7) & 1 -> isScrew
        (kartState>>8) & 1 -> isWet
        (kartState>>9) & 1 -> isInStar
        (kartState>>14) & 1 -> isAccident
        (kartState>>17) & 1 -> isJumpDone
        (kartState>>18) & 1 -> isDuringJump
        (kartState>>22) & 1 -> isJugemHang
        (kartState>>25) & 1 -> isVanish

    */
    int kartState;
    int field_148;
    int field_14C;
    int field_150;
    float antiGravityRemainingTime; // 1 == 0.5 second
    int field_158;
    float startCharge;
    int starStateRemainingFramesCount;
    int isGesso;
    int field_168;
    int field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    int pressedStateRemainingFramesCount;
    int field_194;
    int field_198;
    int thunderStateRemainingFramesCount;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;

    void setEnableControl(bool state);
    void startStar();
    void startKiller();
    void startGesso();
    void startThunder();
};
} // namespace object

static_assert(sizeof(object::KartVehicle) == 0x264, "Class doesn't match game class size");

#endif