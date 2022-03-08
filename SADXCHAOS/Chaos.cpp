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
int Chaos_Timer = 0;
int Debug_Timer = 0;
int Pause_Timer = 0;
int DPadDown_Timer = 0;
int DpadDown = 0;
int DisableControl_Timer = 0;
int XGravity_Timer = 0;
int YGravity_Timer = 0;
int ZGravity_Timer = 0;
int NoGravityTimer = 0;
Float XGravity = 0;
Float YGravity = 0;
Float ZGravity = 0;
int NoClip_Timer = 0;
int SnowboardTimer = 0;
int IssSowboarding = 0;
int InputInvert_Timer = 0;
int EffectMax = 0;
int FastAccel_Timer = 0;
int Camera_Timer = 0;
int s0und__Timer = 0;
int DisablePause_Timer = 0;
int RandomSpawnAmount = 0;
int Animaltyperand = 0;
int EmblemID = 0;
int CurrentLevelOld = -1;
int FruitNumb = 0;
int HatNumb = 0;
int RingAllergy_Timer = 0;
int RingCount = 0;
int EVHandyCap = 0;
int CameraFlip_Timer = 0;
int CameraSpin_Timer = 0;
int CameraSpin_Val = 0;
int DrunkCamera_Timer = 0;
int DrunkCam = 0;
int Direction = 0x50;
int AirCraftSpawerFollow_Timer = 0;
int EmeraldSpin_Timer = 0;
bool DebugToScreen = false;
bool TeleportEnabled = true;
bool EnemysEnabled = true;
bool InvertEnabled = true;
bool RPauseEnabled = true;
bool PauseDisableEnabled = true;
bool GrabAbleObjectsEnabled = true;
bool GravityChangeEnabled = true;
bool RPhysicsEnabled = true;
bool EggViperHandyCapEanbled = true;
bool AllergicToRings = true;
bool CameraEffects = true;
bool RandomEmblemEnabled = true;
char* LastEffect = new char[128];
bool EnableFontScaling = false;
bool SpinnerTextLoader = false;
bool LeonTextLoader = false;
bool RinoTextLoader = false;
bool KikiTextLoader = false;
bool SmanTextLoader = false;
bool EGachaTextLoader = false;
bool PoliceTextLoader = false;
bool SnakeTextLoader = false;
bool RoboTextLoader = false;
bool BuyonTextLoader = false;
bool AmebotTextLoader = false;
bool FSBTextLoader = false;
bool BugerManTextLoader = false;
bool FanTextLoader = false;
bool UnidusTextLoader = false;
bool AnimalTextLoader = false;
bool KeyBlockTextLoader = false;
bool ChaooManagerLoader = false;
bool EmblemTextLoader = false;
bool IceTextLoader = false;
bool WindTextLoader = false;
bool ChaoFruitTextLoader = false;
bool ChaoHatTextLoader = false;
bool BigRockTextLoader = false;
bool CarTextLoader = false;
bool AirCraftTextLoader = false;
bool FireBreathTextLoader = false;
bool CannonS1TextLoader = false;
bool CannonS2TextLoader = false;
bool ShownMenu = false;
bool TextLoaded = false;
bool DebugEnabled = false;
bool WriteOnce = false;
ObjectMaster* snowboard;
task* BURGER[7];
ObjectMaster* LoadSnowboardObject(LoadObj flags, char index, ObjectFuncPtr loadSub)
{
	return snowboard = LoadObject(flags, index, loadSub);
}
void __cdecl Snowboard_Delete_r(ObjectMaster* obj)
{
	njReleaseTexture((NJS_TEXLIST*)obj->Data1->LoopData);
	if (obj == snowboard)
		snowboard = nullptr;
}
void OverRideBigRockTex()
{
	njSetTexture(&OBJ_ICECAP_TEXLIST);
}
void LoadFETexObj()
{
	njSetTexture(&OBJ_FINALEGG_TEXLIST);
}
void LoadSDTexObj()
{
	njSetTexture(&OBJ_SKYDECK_TEXLIST);
}
void NewEffect()
{
	Chaos_Timer = EffectMax;
	return;
}
extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		EffectMax = config->getInt("General", "EffectMax", 180);
		DebugToScreen = config->getBool("General", "PrintToScreen", false);
		TeleportEnabled = config->getBool("General", "TeleportEnabled", true);
		EnemysEnabled = config->getBool("General", "EnemysEnabled", true);
		InvertEnabled = config->getBool("General", "InvertEnabled", true);
		RPauseEnabled = config->getBool("General", "PauseEnabled", true);
		PauseDisableEnabled = config->getBool("General", "PauseDisableEnabled", true);
		GrabAbleObjectsEnabled = config->getBool("General", "GrabAbleObjectsEnabled", true);
		GravityChangeEnabled = config->getBool("General", "GravityChangeEnabled", true);
		RPhysicsEnabled = config->getBool("General", "RPhysicsEnabled", true);
		AllergicToRings = config->getBool("General", "AllergicToRings", true);
		EggViperHandyCapEanbled = config->getBool("General", "EggViperHandyCap", true);
		CameraEffects = config->getBool("General", "CameraEffects", true);
		RandomEmblemEnabled = config->getBool("General", "RandomEmblem", true);
		delete config;
		InitializeRandomCoordinates();
		WriteCall((void*)0x4E9423, LoadSnowboardObject);
		WriteCall((void*)0x4E967E, LoadSnowboardObject);
		WriteCall((void*)0x4E9698, LoadSnowboardObject);
		WriteCall((void*)0x597B34, LoadSnowboardObject);
		WriteCall((void*)0x597B46, LoadSnowboardObject);
		WriteCall((void*)0x4EDD17, OverRideBigRockTex); //fix for Big Ice Cap Rock Texture
		WriteCall((void*)0x5B7581, LoadFETexObj);
		WriteCall((void*)0x5F1A52, LoadSDTexObj);//fix for AirCraft Texture
		WriteCall((void*)0x5F1A78, LoadSDTexObj); //fix for AirCraft Texture
		WriteJump(Snowboard_Delete, Snowboard_Delete_r);
		WriteData((char*)0x4EE7BB, (char)4);//Big ice rock pickup ability
		//WriteData((char*)0x639A00, (char)4);//Patch for Picking Up Car in Station Square Act 0
		WriteData((int*)0x017D0A2C, (int)0xC7C35000);//Stops the amy key block from exploding 
		WriteData((int*)0x017D0A38, (int)0xC7C35000);//Stops the amy key block from exploding
		WriteData((int*)0x017D0A44, (int)0xC7C35000);//Stops the amy key block from exploding
		WriteData((int*)0x017D0A50, (int)0xC7C35000);//Stops the amy key block from exploding
		srand((unsigned)time(nullptr));
		strcpy_s(LastEffect, 128, "Chaos Edition 2.0");
	}
	PVMEntry MinimalPVMs[]{
	{ "GOMA", &GOMA_TEXLIST },
	{ "PEN", &PEN_TEXLIST },
	{ "RAKO", &RAKO_TEXLIST },
	{ "KUJA", &KUJA_TEXLIST },
	{ "TUBA", &TUBA_TEXLIST },
	{ "OUM", &OUM_TEXLIST },
	{ "BANB", &BANB_TEXLIST },
	{ "USA", &USA_TEXLIST },
	{ "WARA", &WARA_TEXLIST },
	{ "GORI", &GORI_TEXLIST },
	{ "LION", &LION_TEXLIST },
	{ "ZOU", &ZOU_TEXLIST },
	{ "MOGU", &MOGU_TEXLIST },
	{ "KOAR", &KOAR_TEXLIST },
	{ "SUKA", &SUKA_TEXLIST },
	};
	typedef void(__cdecl* ChaosEnt)(taskwk*);
	typedef void(__cdecl* ChaosCharObj)(playerwk*);
	typedef void(__cdecl* ChaosNull)();
	struct ChaosS {
		ChaosEnt func;
		ChaosCharObj func2;
		ChaosNull func3;
	};
	ChaosS ChaosArray[109]
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
	{ nullptr, RandomVSpeed, nullptr },
	{ nullptr, RandomKillMomentum, nullptr },
	{ nullptr, RandomHSpeed, nullptr },
	{ nullptr, RandomVSpeed, nullptr },
	{ nullptr, RandomHSpeed, nullptr },
	{ nullptr, FastAccel, nullptr },
	{ nullptr, nullptr, RingAllergy },
	{ nullptr, nullptr, RandomSnowboard },
	{ nullptr, nullptr, RandomNoClip },
	{ nullptr, nullptr, RandomTeleport },
	{ nullptr, nullptr, RandomControlDisable },
	{ nullptr, nullptr, RemovePowerUp },
	{ nullptr, nullptr, RandomHurt },
	{ nullptr, nullptr, NoGravity },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomPause },
	{ nullptr, nullptr, RandomMagneticBarrier },
	{ nullptr, nullptr, RandomYGravity },
	{ nullptr, nullptr, RandomTikalHint },
	{ nullptr, nullptr, RandomXGravity },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, NoGravity },
	{ nullptr, nullptr, SpinCamera },
	{ nullptr, nullptr, RandomPhysics },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, FlipCamera },
	{ nullptr, nullptr, RandomZGravity },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, RemovePowerUp },
	{ nullptr, nullptr, AndKnuckles },
	{ nullptr, nullptr, IncreaseCutsceneSkipTime },
	{ nullptr, nullptr, RandomZGravity },
	{ nullptr, nullptr, RandomInvincibility },
	{ nullptr, nullptr, IncreaseCutsceneSkipTime },
	{ nullptr, nullptr, DrunkCamera },
	{ nullptr, nullptr, RandomNoClip },
	{ nullptr, nullptr, RandomRotate },
	{ nullptr, nullptr, RandomBarrier },
	{ nullptr, nullptr, RandomHurt },
	{ nullptr, nullptr, RandomCollisionSize },
	{ nullptr, nullptr, RandomSwapMusic },
	{ nullptr, nullptr, UncoupleCamera },
	{ nullptr, nullptr, InputInvert },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomPause },
	{ nullptr, nullptr, RandomControlDisable },
	{ nullptr, nullptr, IncreaseCutsceneSkipTime },
	{ nullptr, nullptr, RandomControlDisable },
	{ nullptr, nullptr, RandomNoClip },
	{ nullptr, nullptr, RandomXGravity },
	{ nullptr, nullptr, RandomChaoo },
	{ nullptr, nullptr, RandomYGravity },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, DisablePausee },
	{ nullptr, nullptr, Nos0und_ForYou },
	{ nullptr, nullptr, ChaosPlayVoice_rng },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, RandomDebug },
	{ nullptr, nullptr, RandomDPadDownCheck },
	{ nullptr, nullptr, RingAllergy },
	{ nullptr, nullptr, RandomTikalHint },
	{ nullptr, nullptr, RandomCollisionSize },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, DrunkCamera },
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
		CheckAllEffectsTimer();
		DebugPrintOutCheck();
		if (Chaos_Timer < EffectMax)//30 seconds is 1800
			Chaos_Timer++;
		if (Chaos_Timer >= EffectMax)
		{
			char curRand = 0;
			do {
				curRand = rand() % ChaosSize;
			} while (oldRand == curRand);
			if (ChaosArray[curRand].func != nullptr)
				ChaosArray[curRand].func(playertwp[0]);
			else if (ChaosArray[curRand].func2 != nullptr)
				ChaosArray[curRand].func2(playerpwp[0]);
			else
				ChaosArray[curRand].func3();
			oldRand = curRand;
			Chaos_Timer = 0;
		}
	}
	__declspec(dllexport) void __cdecl OnInput()
	{
	}
	__declspec(dllexport) void __cdecl OnControl()
	{
		 //Executed when the game processes input
		if (Controllers[0].PressedButtons & Buttons_Y) //Debug Testing
		{
			EmeraldSpin();
		}
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}