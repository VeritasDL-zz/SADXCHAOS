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
extern int RingAllergy_Timer;
extern int RingCount;
extern int AirCraftSpawerFollow_Timer;
extern char* LastEffect;
extern bool EnableFontScaling;
extern bool DebugEnabled;
extern bool AllergicToRings;
extern bool UpsideDownCameraEnabled;
extern bool DrunkCameraEnabled;
extern bool SpinCameraEnabled;
extern bool FireBreathTextLoader;
extern bool CannonS1TextLoader;
extern bool CannonS2TextLoader;
extern bool KnuxEffTextLoader;
extern bool IceTextLoader;
extern int CameraFlip_Timer;
extern int CameraSpin_Timer;
extern int CameraSpin_Val;
extern int DrunkCamera_Timer;
extern int RandomSpawnAmount;
extern int DrunkCam;
extern int Direction;
extern ObjectMaster* snowboard;
extern size_t ChaosSize;
typedef void(__cdecl* ChaosEnt)(taskwk*);
typedef void(__cdecl* ChaosCharObj)(playerwk*);
typedef void(__cdecl* ChaosNull)();
struct ChaosS 
{
	ChaosEnt func;
	ChaosCharObj func2;
	ChaosNull func3;
};
extern ChaosS ChaosArray[115];
