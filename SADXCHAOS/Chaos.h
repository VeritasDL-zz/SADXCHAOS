#pragma once
#include "ninja.h"
#include "SADXStructs.h"
extern char oldRand;
extern int DpadDown;
extern int EffectMax;
extern int RingCount;
extern int IssSowboarding;
extern char* LastEffect;
extern bool DebugEnabled;
extern int CameraSpin_Val;
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
extern ChaosS ChaosArray[116];
