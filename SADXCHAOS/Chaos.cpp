#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <IniFile.hpp>
using std::string;
//Changelog Is Now Located inside Of Change.Log
char oldRand = -1;
char* LastEffect = new char[128];
ObjectMaster* snowboard;
extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		Init_Fixes(path, helperFunctions);
		init_FreeMovements();
		strcpy_s(LastEffect, 128, "Chaos Edition 2.0 - Beta");
	}
	ChaosS ChaosArray[116]
	{
	{ RandomSpring, nullptr, nullptr },
	{ RandomSpinnerA, nullptr, nullptr },
	{ RandomSpikeBall, nullptr, nullptr },
	{ RandomSpikeBall, nullptr, nullptr },
	{ RandomSpinnerB, nullptr, nullptr },
	{ RandomRobo, nullptr, nullptr },
	{ RandomSnake, nullptr, nullptr },
	{ RandomKeyBlock, nullptr, nullptr },
	{ RandomLeon, nullptr, nullptr },
	{ RandomSpring, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ RandomDroppedRings, nullptr, nullptr },
	{ RandomKeyBlock, nullptr, nullptr },
	{ RandomUnidus, nullptr, nullptr },
	{ RandomSpring, nullptr, nullptr },
	{ RandomBuyon, nullptr, nullptr },
	{ RandomSpinnerC, nullptr, nullptr },
	{ RandomTank, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ BigRock, nullptr, nullptr },
	{ RandomSpeedPad, nullptr, nullptr },
	{ RandomSpeedPad, nullptr, nullptr },
	{ RandomLifePowerup, nullptr, nullptr },
	{ RandomHat, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ RandomFruit, nullptr, nullptr },
	{ RandomSpikeBall, nullptr, nullptr },
	{ RandomCheckPoint, nullptr, nullptr },
	{ RandomAmebot, nullptr, nullptr },
	{ RandomPolice, nullptr, nullptr },
	{ BigRock, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ RandomEGacha, nullptr, nullptr },
	{ RandomSman, nullptr, nullptr },
	{ RandomFan, nullptr, nullptr },
	{ RandomEmblem, nullptr, nullptr },
	{ RandomAirCraft, nullptr, nullptr },
	{ RandomAirCraft, nullptr, nullptr },
	{ RandomFireBreath, nullptr, nullptr },
	{ RandomFireBreath, nullptr, nullptr },
	{ RandomCannonS1, nullptr, nullptr },
	{ RandomCannonS2, nullptr, nullptr },
	{ RandomBarrel, nullptr, nullptr },
	{ RandomKnuxRingSpring, nullptr, nullptr },
	{ nullptr, RandomVSpeed, nullptr },
	{ nullptr, RandomKillMomentum, nullptr },
	{ nullptr, RandomHSpeed, nullptr },
	{ nullptr, RandomVSpeed, nullptr },
	{ nullptr, RandomHSpeed, nullptr },
	{ nullptr, FastAccel, nullptr },
	{ nullptr, nullptr, RandomBarrier },
	{ nullptr, nullptr, RandomDPadDownCheck },
	{ nullptr, nullptr, DrunkCamera },
	{ nullptr, nullptr, ChaosPlayVoice_rng },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, Nos0und_ForYou },
	{ nullptr, nullptr, RandomCollisionSize },
	{ nullptr, nullptr, RandomControlDisable },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, RandomZGravity },
	{ nullptr, nullptr, RandomNoClip },
	{ nullptr, nullptr, RandomRotate },
	{ nullptr, nullptr, RandomTikalHint },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomPause },
	{ nullptr, nullptr, RandomCollisionSize },
	{ nullptr, nullptr, IncreaseCutsceneSkipTime },
	{ nullptr, nullptr, RandomYGravity },
	{ nullptr, nullptr, AndKnuckles },
	{ nullptr, nullptr, RandomMagneticBarrier },
	{ nullptr, nullptr, RandomZGravity },
	{ nullptr, nullptr, RandomNoClip },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, NoGravity },
	{ nullptr, nullptr, BurgerManSpin },
	{ nullptr, nullptr, DrunkCamera },
	{ nullptr, nullptr, RandomSnowboard },
	{ nullptr, nullptr, RandomNoClip },
	{ nullptr, nullptr, RandomPause },
	{ nullptr, nullptr, IncreaseCutsceneSkipTime },
	{ nullptr, nullptr, RandomXGravity },
	{ nullptr, nullptr, RandomHurt },
	{ nullptr, nullptr, RemovePowerUp },
	{ nullptr, nullptr, RandomXGravity },
	{ nullptr, nullptr, RandomPhysics },
	{ nullptr, nullptr, RandomHurt },
	{ nullptr, nullptr, InputInvert },
	{ nullptr, nullptr, Set_Sonic_Ice },
	{ nullptr, nullptr, SpinCamera },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, RandomYGravity },
	{ nullptr, nullptr, RandomTikalHint },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RingAllergy },
	{ nullptr, nullptr, RandomTeleport },
	{ nullptr, nullptr, RandomSwapMusic },
	{ nullptr, nullptr, IncreaseCutsceneSkipTime },
	{ nullptr, nullptr, DisablePausee },
	{ nullptr, nullptr, Set_Sonic_Ice },
	{ nullptr, nullptr, RandomDebug },
	{ nullptr, nullptr, RandomInvincibility },
	{ nullptr, nullptr, BurgerManSpin },
	{ nullptr, nullptr, RemovePowerUp },
	{ nullptr, nullptr, FlipCamera },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, RandomControlDisable },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomChaoo },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, UncoupleCamera },
	{ nullptr, nullptr, RingAllergy },
	{ nullptr, nullptr, NoGravity },
	{ nullptr, nullptr, RandomControlDisable },
	{ nullptr, nullptr, SideWaysCamera },
	};
	size_t ChaosSize = LengthOfArray(ChaosArray);
	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SADX
		if (GameState != 15 && GameState != 16 && TextLoaded)
		{
			ResetTextureBools();
		}
		if (!playerpwp[0] || GameState != 15 || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || CurrentLevel >= LevelIDs_SSGarden)
			return;
		ChaosTimer();
		CheckAllEffectsTimer();
		DebugPrintOutCheck();
	}
	__declspec(dllexport) void __cdecl OnControl()
	{
		 //Executed when the game processes input
		if (Controllers[0].PressedButtons & Buttons_Y) //Debug Testing
		{
		}
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}