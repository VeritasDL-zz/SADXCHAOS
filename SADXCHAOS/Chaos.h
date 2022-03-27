#pragma once
#include "ninja.h"
#include "SADXStructs.h"
extern char oldRand;
extern char* LastEffect;
extern uint32_t Veritas;
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
extern ChaosS ChaosArray[119];
