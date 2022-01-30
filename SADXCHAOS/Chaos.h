#pragma once
#include "ninja.h"
#include "SADXStructs.h"
extern char oldRand;
extern int Chaos_Timer;
extern int Debug_Timer;
extern int Pause_Timer;
extern int DPadDown_Timer;
extern int DpadDown;
extern int DisableControl_Timer;
extern int XGravity_Timer;
extern int YGravity_Timer;
extern int ZGravity_Timer;
extern int NoGravityTimer;
extern Float XGravity;
extern Float YGravity;
extern Float ZGravity;
extern int NoClip_Timer;
extern int SnowboardTimer;
extern int IssSowboarding;
extern int InputInvert_Timer;
extern int EffectMax;
extern int FastAccel_Timer;
extern int Camera_Timer;
extern int s0und__Timer;
extern int DisablePause_Timer;
extern int Animaltyperand;
extern int EmblemID;
extern int CurrentLevelOld;
extern int SaveHash;
extern int FruitNumb;
extern int HatNumb;
extern int RingAllergy_Timer;
extern int RingCount;
extern int NoJumpBall_Timer;
extern bool DebugToScreen;
extern bool TeleportEnabled;
extern bool EnemysEnabled;
extern bool InvertEnabled;
extern bool RPauseEnabled;
extern bool PauseDisableEnabled;
extern bool GrabAbleObjectsEnabled;
extern bool GravityChangeEnabled;
extern bool RPhysicsEnabled;
extern bool EggViperHandyCapEanbled;
extern char* LastEffect;
extern bool EnableFontScaling;
extern bool SpinnerTextLoader;
extern bool LeonTextLoader;
extern bool RinoTextLoader;
extern bool KikiTextLoader;
extern bool SmanTextLoader;
extern bool EGachaTextLoader;
extern bool PoliceTextLoader;
extern bool SnakeTextLoader;
extern bool RoboTextLoader;
extern bool BuyonTextLoader;
extern bool AmebotTextLoader;
extern bool FSBTextLoader;
extern bool BugerManTextLoader;
extern bool UnidusTextLoader;
extern bool AnimalTextLoader;
extern bool KeyBlockTextLoader;
extern bool ChaooManagerLoader;
extern bool EmblemTextLoader;
extern bool IceTextLoader;
extern bool WindTextLoader;
extern bool ChaoFruitTextLoader;
extern bool ChaoHatTextLoader;
extern bool BigRockTextLoader;
extern bool CarTextLoader;
extern bool ShownMenu;
extern bool TextLoaded;
extern bool DebugEnabled;
extern bool AllergicToRings;
extern bool WriteOnce;
extern const unsigned char PLAYER_COUNT;
extern ObjectMaster* snowboard;
extern PVMEntry MinimalPVMs[15];
void NewEffect();