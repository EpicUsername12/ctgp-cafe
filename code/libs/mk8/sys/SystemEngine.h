#ifndef _SYS_SYSTEM_ENGINE_H
#define _SYS_SYSTEM_ENGINE_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/nn/erreula/erreula_AppearArg.h>
#include <mk8/sys/CommonModuleManager.h>
#include <mk8/sys/SystemSaveDataManager.h>
#include <mk8/sys/ResourceLoader.h>

namespace sys {
class SystemEngine {
  public:
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
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
    int field_D4; // instance of ??
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
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
    sys::ResourceLoader mResLoader;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;                 // sys::ControllerManager*
    SaveDataManager* mSaveDataMgr; // sys::SaveDatamanager*
    int field_2CC;
    int field_2D0; // sys::AccountSetting*
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320;
    int field_324;
    int field_328;
    int field_32C;
    int field_330;
    int srcrev;
    int resourcerev;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    int field_364;
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
    int field_380;
    int field_384;
    int field_388;
    int field_38C;
    int field_390;
    int field_394;
    int field_398;
    int field_39C;
    int field_3A0;
    int field_3A4;
    int field_3A8;
    int field_3AC;
    int field_3B0;
    int field_3B4;
    int field_3B8;
    int field_3BC;
    int field_3C0;
    int field_3C4;
    int field_3C8;
    int field_3CC;
    int field_3D0;
    int field_3D4;
    int field_3D8;
    int field_3DC;
    int field_3E0;
    int field_3E4;
    int field_3E8;
    int field_3EC;
    int field_3F0;
    int field_3F4;
    CommonModuleManager* moduleManager;
    int field_3FC;

    SystemEngine();

    int launchErrorViewer(nn::erreula::AppearArg const* pAppearData);

    static SystemEngine* getEngine();
};
} // namespace sys

static_assert(sizeof(sys::SystemEngine) == 0x400, "Class doesn't match game class size");

#endif