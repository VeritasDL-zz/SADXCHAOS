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


//changelog
//started Mod 8/5/2021
//added code base from Soar's scrapped "mania" mode
//added debug print out for mods being enabled
//added random time of day
//added random dropped rings
//added random Clip level (not sure if it works)
//added randompause (not sure if it works)
//added random char
//added random camera (not sure if it works)
//added random debug (not sure if it works and i need a way to turn it off after a short period
//added random xyz gravity (havent enabled them or tested them)
//added random barrier
//added random mag barrier
//added invincibility
//added random debug
//random powerup was crashing due to bomb power up? havent fixed
//sometimes the other give powerup codes i have kill the player depending on the state? 
//fixed random power up crash, by taking soras random power up code form sadxvschat
//updated random pause to make you unpause a few times, (currently 10 frames) idk how i would make it pause, unpause, automaticly cuz setting gamestate in ONFrame just makes it happen so fast you dont even see it, 
//removed set scale
//removed my own random powerups, (still in code, just unused)
//made debug last a set amount of frames (75 currently) and force the player out of debug movement.
//added press Dpad Down or die
//changed random camera to Swap Camera lol
//added random control disable 
//added Random Y Gravity
//added Random NoClip
//fixed Random NoClip Crash?
//made debug mode work again
//made debug mod last longer might make shorter
//fixed Camera Swap Code
//made Control Disable look better
//made Control Disable last longer? might shorten
//fixed random Gavity values maybe?
//started working on random tikal hints - thanks for the help kell, main and refrag, 
//finished random tikal hint, just need to add more hints, 
//added more hints and the first custom hint with custom voice file!
//Re-Enabled Random Dropped Rings (8/11/2021)
//fixed a bug with RandomTimeOfDay setting the chao timer to 1800
//fixed debug mode crash, gg 
//Credits to MainMemory for the Snowboard spawn Code, https://github.com/MainMemory/SADXBoardSpawner
//cleaned up no clip code
//cleaned up control disable code
//changed y grav rand math
//cleaned up ints
//made Kill Momentum play the custom roblox OOF sound,
//added random checkpoint (might not work as a real checkpoint but funny af)
//added Movement Stick Invert code thanks to Sora!
//added support for knux, amy, and metal sonic to movement debug, Tails, gamma and big dont have movement debug thanks to stars for pointing out im dumb,
//added random rotate
//trying to add support for editing the chaos timer, shits fucked 
//started adding Random Telport with the help of Refrag :)
//added Ability to edit How often things happen in the config menu
//cleaned up debug Output a little
//changed how long Gravity, noclip, and snowboard last before being disabled
//finished sonic casino act 0 teleports
//started working on casino act 1 teleport (might work for tails and sonic)
//changed gravity random math again
//finished Casino act 1 teleports
//finished teleports to emeraldcoast act 0
//finished icecap act 0 and 1 teleports
//finished speedhighway act 0 sonic teleports
//started working on act 2 speedhighway sonic teleports
//added Random Life PowerUp
//finished randomteleport crashing when not in a level/act that have teleports thanks to refrag again!
//finished twinkle park teleports
//added Option for Last Effect to Be Printed to Game Screen
//changed size, color and position of Last Effect text, also render a paque/translucent box around it.
//Re Enabled Random Hurt
//Added Option to print last effet to screen
//added Ability to spawn Enemys
//added more Enemys lol
//added RandomBurgerMan
//actully enabled Random Rotate.
//added 24 new tikal hints
//added more new "hints"
//sadly i have a crash with enemys in hub-worlds, only Beat, and Spinners can spawn in hubworlds currently 
//added randomchao, thanks to sora for the help and shuch
// 
//added config options for, Random Enemys, Input Invert and RandomPause
//added FastAccel (for now) 
//added random physics thanks to MainMemory (https://github.com/MainMemory/SADXPhysicsSwapMod) and Refrag  
//added Decoupple Camera
//added no sound,
//fixed a bug with fast accel
//added Disable Pause
//fixed a few warnings
//added Random Key Block
//added random colors for the random key block, 
//added random emblem.
//fixed a bug with the texture loader resetter 
//added config to disable, disable pause
//Removed OOF from Kill momentum
//updated Effect Table
//Tikal Hint now 20% less likely
//RandomKillMomentum 20% less likly
//changed no_s0und_ to 222 frames from 110 frames
//ghetto fix for Y offset change with Random Phys.
//fix for Debug Scaling thanks to PKR's Debug mod https://github.com/PiKeyAr/sadx-debug-mode/
//fix for debug mod stacking
//added Random Chao Fruit and Chao Hat, thanks to kell and pkr
//changed most spawn things to using tasks, removed creation of setdata for objects that dont need it.
//fixed RandomFallingSpikeBall moving up and down 
//Started Working on Big Ice Cap Rock
//Big IceCap Rock Finished
//AndKnuckles added 
//Made it So Big's Rock can be picked up by others!
//Fixed Random Chao (sorta)
//Fixed Random KeyBlock again,
//Added Config Option to Disabled Spawning of Grab-Able Objects
//Started working on bigCar
//Started Woking on Random X and Z gravity
//Added No Gravity
//Re-Enabled Random Invincibility Random Magnetic Barrier and Random Barrier
//Added Config Option For Gravity Mods
//Added Config Option for Random Physics
//Fixed a bug with Debug Movement
//Fixed a bug with Random Snowboard 
//Fixed Another Bug With Debug Movement
//Re-enabled Random X and Z Gravity
//Hopfully Fixed a Crash/Memory Leak with Last Effect, 
//Still Working on Random Character 
//split up code into multipul CPP files
//moved Tikal Hints to its own .h/.cpp file
//moved debug draw to its own .h/.cpp file too
//Added Ring Allergy and Config For Ring Allergy, 
//Fixed Ring Allergy (I think)
//Added A EggViper HandyCap, with config option, (1/22/2022)
//Removed IceBall from spawning while playing as gamma (1/22/2022)
//Fixed RandomSnowboard trying to run when not playing as Sonic Or Tails (1/22/2022)
//Temp Commented out All Random Char Init Fixes (1/22/2022)
//Added Check for Big Fishing to make playing a big a little bit easier (1/22/2022)
//Disabled Enemies From Spawning Durring E101R boss fight (1/25/2022)
//fixed bug with big fishing code (1/22/2022)
//stopped sman for spawning durring egg viper (1/22/2022)
//Added IncreaseCutsceneSkipTime - Sets Frames needed to skip to 1A2 (1/29/2022)
//started working on remove powerup (1/29/2022)
//still working on remove powerup (1/30/2022)
//Created a NewEffect function and made all skipped mods call the function (1/30/2022)
//fixed a bug with DisablePause and RingAllergy (1/30/2022)
//Enabled RingAllergy (2/1/2022)
//Enabled BigRock (2/1/2022)
//Changed RandomDroppedRings to Use TakeRingsInterval1 rather then set rings to 0 (2/15/2022)
// 
// 
//Todo
//random emblem broke 
//Kill momentum doesn't always work?
//boss battles, might be like the hub worlds where enemys being killed can just randomly crash even tho i load all the animal textures?
//beat has bad texture in redmountain? 
//gamma hs, ham crashed 7 times, in a row
//seems to be related to gamma locking onto enemys he was never intended to? idk

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
int Animaltyperand = 0;
int EmblemID = 0;
int CurrentLevelOld = -1;
int SaveHash = -1;
int FruitNumb = -1;
int HatNumb = -1;
int RingAllergy_Timer = 0;
int RingCount = 0;
int EVHandyCap = 0;
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
bool ShownMenu = false;
bool TextLoaded = false;
bool DebugEnabled = false;
bool WriteOnce = false;
const unsigned char PLAYER_COUNT = 4;
ObjectMaster* snowboard;

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
ObjectFuncPtr charfuncs[] = {
	Sonic_Main,
	Eggman_Main,
	Tails_Main,
	Knuckles_Main,
	Tikal_Main,
	Amy_Main,
	Gamma_Main,
	Big_Main
};

void OverRideBigRockTex()
{
	njSetTexture(&OBJ_ICECAP_TEXLIST);
}
void NewEffect()
{
	Chaos_Timer = EffectMax;
	return;
}
__int16 selectedcharacter[PLAYER_COUNT] = { -1, -1, -1, -1 }; //this is taken from https://github.com/MainMemory/SADXCharSel
int GetCharacter0ID() //this is taken from https://github.com/MainMemory/SADXCharSel
{
	return GetCharacterID(0);
}
int GetSelectedCharacter() //this is taken from https://github.com/MainMemory/SADXCharSel
{
	return selectedcharacter[0];
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
		delete config;
		InitializeRandomCoordinates();
		WriteCall((void*)0x4E9423, LoadSnowboardObject);
		WriteCall((void*)0x4E967E, LoadSnowboardObject);
		WriteCall((void*)0x4E9698, LoadSnowboardObject);
		WriteCall((void*)0x597B34, LoadSnowboardObject);
		WriteCall((void*)0x597B46, LoadSnowboardObject);
		WriteCall((void*)0x4EDD17, OverRideBigRockTex);
		WriteJump(Snowboard_Delete, Snowboard_Delete_r);
		WriteData((char*)0x4EE7BB, (char)4);//big ice rock pickup ability
		//WriteData((char*)0x639A00, (char)4);//Patch for Picking Up Car in Station Square Act 0
		WriteData((int*)0x017D0A2C, (int)0xC7C35000);//stops the amy key block from exploding 
		WriteData((int*)0x017D0A38, (int)0xC7C35000);//stops the amy key block from exploding
		WriteData((int*)0x017D0A44, (int)0xC7C35000);//stops the amy key block from exploding
		WriteData((int*)0x017D0A50, (int)0xC7C35000);//stops the amy key block from exploding



		//all of this is taken from https://github.com/MainMemory/SADXCharSel, //Temp Disabled as of 1/22/2022
		//WriteData((Uint8*)0x007A4DC4, PLAYER_COUNT); // Spring_Main
		//WriteData((Uint8*)0x007A4FF7, PLAYER_COUNT); // SpringB_Main
		//WriteData((Uint8*)0x0079F77C, PLAYER_COUNT); // SpringH_Main
		//WriteData((Uint8*)0x004418B8, PLAYER_COUNT); // IsPlayerInsideSphere (could probably use a better name!)
		//WriteJump((void*)0x490C6B, (void*)0x490C80); // prevent Big from automatically loading Big's HUD
		//WriteCall((void*)0x426005, GetCharacter0ID); // fix ResetTime() for Gamma
		//WriteCall((void*)0x427F2B, GetCharacter0ID); // fix ResetTime2() for Gamma
		//WriteData((char*)0x41486D, (char)0xEB); // fix time reset at level load for Gamma
		//WriteData((__int16**)0x414A0C, &selectedcharacter[0]); // fix 1min minimum at level restart for Gamma
		//WriteCall((void*)0x426081, GetCharacter0ID); // fix Gamma's timer
		//WriteCall((void*)0x4266C9, GetCharacter0ID); // fix Gamma's time bonus
		//WriteCall((void*)0x426379, GetCharacter0ID); // fix Gamma's time display
		//WriteJump((void*)0x47A907, (void*)0x47A936); // prevent Knuckles from automatically loading Emerald radar
		//WriteData<6>((void*)0x475E7C, 0x90u); // make radar work when not Knuckles
		//WriteData<6>((void*)0x4764CC, 0x90u); // make Tikal hints work when not Knuckles
		//WriteCall((void*)0x4D677C, GetCharacter0ID); // fix item boxes for Gamma
		//WriteCall((void*)0x4D6786, GetCharacter0ID); // fix item boxes for Big
		//WriteCall((void*)0x4D6790, GetCharacter0ID); // fix item boxes for Sonic
		//WriteCall((void*)0x4C06D9, GetCharacter0ID); // fix floating item boxes for Gamma
		//WriteCall((void*)0x4C06E3, GetCharacter0ID); // fix floating item boxes for Big
		//WriteCall((void*)0x4C06ED, GetCharacter0ID); // fix floating item boxes for Sonic
		//WriteCall((void*)0x424D0A, GetSelectedCharacter); // fix character sfx for Casinopolis
		//WriteData((void**)0x424F88, (void*)0x424E41); // ''
		//WriteData((void**)0x424F8C, (void*)0x424E5C); // ''
		//WriteData((void**)0x424F90, (void*)0x424E77); // ''
		//WriteCall((void*)0x424E08, GetSelectedCharacter); // fix character sfx
		//WriteCall((void*)0x4245F0, GetSelectedCharacter); // fix character voices in Chao Garden
		//WriteCall((void*)0x4BFFEF, GetCharacter0ID); // fix 1up icon
		//WriteCall((void*)0x4C02F3, GetCharacter0ID); // ''
		//WriteCall((void*)0x4D682F, GetCharacter0ID); // ''
		//WriteCall((void*)0x4D69AF, GetCharacter0ID); // ''
		//WriteCall((void*)0x425E62, GetCharacter0ID); // fix life icon
		//WriteData((char*)0x4879C1, (char)0x90);
		//WriteCall((void*)0x61CB77, GetCurrentCharacterID); // make Twinkle Park playable
		//WriteCall((void*)0x61CF8D, GetCurrentCharacterID); // ''
		//WriteCall((void*)0x79D7E2, GetCharacter0ID); // fix cart jump voice
		//WriteData<6>((void*)0x48ADA5, 0x90u); // prevent Amy from loading the bird
		//WriteCall((void*)0x4E966C, GetCharacter0ID); // fix ice cap snowboard 1
		//WriteCall((void*)0x4E9686, GetCharacter0ID); // fix ice cap snowboard 2
		//WriteCall((void*)0x597B1C, GetCharacter0ID); // fix sand hill snowboard
		//WriteData<1>((int*)0x7B52A0, 0x2); //remove Eggman debug mode		
		//WriteData<1>((int*)0x7b5290, 0x2); //remove Eggman debug mode	
		//WriteData<21>((int*)0x7b52a1, 0x90);
		//WriteData<1>((int*)0x7b43bc, 0x2); //remove Tikal debug mode //Temp Disabled as of 1/22/2022
		srand((unsigned)time(nullptr));
		strcpy_s(LastEffect, 128, "Chaos Edition");
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
	void RandomChar()//Still doesnt work 1/22/2022 trying to make work but man this shits hard
	{
		int CurrentCharID = GetCurrentCharacterID();
		char P1Action = EntityData1Ptrs[0]->Action;
		CharObj2* co2 = CharObj2Ptrs[0];
		EntityData1* P1Data = EntityData1Ptrs[0];
		ObjectMaster* player1 = GetCharacterObject(0);
		EntityData1* data = player1->Data1;
		short powerups = co2->Powerups;
		short jumptime = co2->JumpTime;
		short underwatertime = co2->UnderwaterTime;
		float loopdist = co2->LoopDist;
		NJS_VECTOR speed = co2->Speed;
		CheckThingButThenDeleteObject(player1);
		player1->Data1->CollisionInfo = nullptr;
		int RandomCharID = rand() % 8;
		while (RandomCharID == P1Data->CharID)
		{
			RandomCharID = rand() % 8;
		}
		while (RandomCharID == 6 || RandomCharID == 7)
		{
			RandomCharID = rand() % 8;
		}
		player1->MainSub = charfuncs[RandomCharID];
		P1Data->CharID = RandomCharID;
		P1Data->Action = 0;
		Collision_Free(player1);
		P1Data->Status = 0;
		player1->MainSub(player1);
		CharObj2Ptrs[0]->Powerups = powerups;
		CharObj2Ptrs[0]->JumpTime = jumptime;
		CharObj2Ptrs[0]->UnderwaterTime = underwatertime;
		CharObj2Ptrs[0]->LoopDist = loopdist;
		CharObj2Ptrs[0]->Speed = speed;
		data->Action++;
		strcpy_s(LastEffect, 128, "Random Char");
	}
	typedef void(__cdecl* ChaosEnt)(EntityData1*);
	typedef void(__cdecl* ChaosCharObj)(CharObj2*);
	typedef void(__cdecl* ChaosNull)();
	struct ChaosS {
		ChaosEnt func;
		ChaosCharObj func2;
		ChaosNull func3;
	};
	ChaosS ChaosArray[97]
	{
	{ RandomSpring, nullptr, nullptr, },
	{ RandomSpring, nullptr, nullptr, },
	{ RandomSpring, nullptr, nullptr, },
	{ RandomSpeedPad, nullptr, nullptr, },
	{ RandomSpeedPad, nullptr, nullptr, },
	{ RandomSpikeBall, nullptr, nullptr, },
	{ RandomSpikeBall, nullptr, nullptr, },
	{ RandomSpikeBall, nullptr, nullptr, },
	{ RandomDroppedRings, nullptr, nullptr },
	{ RandomCheckPoint, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ RandomLifePowerup, nullptr, nullptr },
	{ RandomTank, nullptr, nullptr },
	{ RandomEGacha, nullptr, nullptr },
	{ RandomLeon, nullptr, nullptr },
	{ RandomSpinnerA, nullptr, nullptr },
	{ RandomSpinnerB, nullptr, nullptr },
	{ RandomSpinnerC, nullptr, nullptr },
	{ RandomRobo, nullptr, nullptr },
	{ RandomSnake, nullptr, nullptr },
	{ RandomPolice, nullptr, nullptr },
	{ RandomAmebot, nullptr, nullptr },
	{ RandomUnidus, nullptr, nullptr },
	{ RandomBuyon, nullptr, nullptr },
	{ RandomSman, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ RandomKeyBlock, nullptr, nullptr },
	{ RandomKeyBlock, nullptr, nullptr },
	{ RandomFruit, nullptr, nullptr },
	{ RandomHat, nullptr, nullptr },
	{ BigRock, nullptr, nullptr },
	{ BigRock, nullptr, nullptr },
	{ nullptr, RandomKillMomentum, nullptr, },
	{ nullptr, RandomVSpeed, nullptr, },
	{ nullptr, RandomVSpeed, nullptr, },
	{ nullptr, RandomHSpeed, nullptr, },
	{ nullptr, RandomHSpeed, nullptr, },
	{ nullptr, FastAccel, nullptr },
	{ nullptr, nullptr, RandomSwapMusic},
	{ nullptr, nullptr, ChaosPlayVoice_rng},
	{ nullptr, nullptr, RandomSnowboard},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomPause},
	{ nullptr, nullptr, RandomPause},
	{ nullptr, nullptr, SwapCamera},
	{ nullptr, nullptr, SwapCamera},
	{ nullptr, nullptr, SwapCamera},
	{ nullptr, nullptr, SwapCamera},
	{ nullptr, nullptr, RandomDebug},
	{ nullptr, nullptr, RandomXGravity},
	{ nullptr, nullptr, RandomXGravity},
	{ nullptr, nullptr, RandomYGravity},
	{ nullptr, nullptr, RandomYGravity},
	{ nullptr, nullptr, RandomZGravity},
	{ nullptr, nullptr, RandomZGravity},
	{ nullptr, nullptr, RandomDPadDownCheck},
	{ nullptr, nullptr, RandomControlDisable},
	{ nullptr, nullptr, RandomControlDisable},
	{ nullptr, nullptr, RandomControlDisable},
	{ nullptr, nullptr, RandomNoClip},
	{ nullptr, nullptr, RandomNoClip},
	{ nullptr, nullptr, RandomNoClip},
	{ nullptr, nullptr, RandomTikalHint},
	{ nullptr, nullptr, RandomTikalHint},
	{ nullptr, nullptr, InputInvert},
	{ nullptr, nullptr, RandomTeleport},
	{ nullptr, nullptr, RandomHurt},
	{ nullptr, nullptr, RandomHurt},
	{ nullptr, nullptr, RandomRotate},
	{ nullptr, nullptr, RandomChaoo},
	{ nullptr, nullptr, RandomPhysics},
	{ nullptr, nullptr, UncoupleCamera},
	{ nullptr, nullptr, Nos0und_ForYou},
	{ nullptr, nullptr, DisablePausee},
	{ nullptr, nullptr, AndKnuckles},
	{ nullptr, nullptr, NoGravity},
	{ nullptr, nullptr, NoGravity},
	{ nullptr, nullptr, RandomBarrier},
	{ nullptr, nullptr, RandomInvincibility},
	{ nullptr, nullptr, RandomMagneticBarrier},
	{ nullptr, nullptr, IncreaseCutsceneSkipTime},
	{ nullptr, nullptr, IncreaseCutsceneSkipTime},
	{ nullptr, nullptr, IncreaseCutsceneSkipTime},
	{ nullptr, nullptr, RemovePowerUp},
	{ nullptr, nullptr, RemovePowerUp},
	{ nullptr, nullptr, RandomCollisionSize},
	{ nullptr, nullptr, RandomCollisionSize},
	{ nullptr, nullptr, RingAllergy},
	{ nullptr, nullptr, RingAllergy},
	};

	size_t ChaosSize = LengthOfArray(ChaosArray);
	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SADX
		if (GameState != 15 && GameState != 16 && TextLoaded)
		{
			SpinnerTextLoader = false;
			LeonTextLoader = false;
			KikiTextLoader = false;
			RinoTextLoader = false;
			SmanTextLoader = false;
			EGachaTextLoader = false;
			PoliceTextLoader = false;
			SnakeTextLoader = false;
			RoboTextLoader = false;
			BuyonTextLoader = false;
			AmebotTextLoader = false;
			FSBTextLoader = false;
			BugerManTextLoader = false;
			UnidusTextLoader = false;
			AnimalTextLoader = false;
			ChaooManagerLoader = false;
			KeyBlockTextLoader = false;
			EmblemTextLoader = false;
			IceTextLoader = false;
			WindTextLoader = false;
			TextLoaded = false;
			DebugEnabled = false;
			ChaoFruitTextLoader = false; //@temp.walker may remove
			ChaoHatTextLoader = false;
			BigRockTextLoader = false;
			CarTextLoader = false;
			WriteOnce = false;
			HatNumb = -1;
		}
		if (!CharObj2Ptrs[0] || GameState != 15 || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || CurrentLevel >= LevelIDs_SSGarden)
			return;
		if (NoClip_Timer <= 800 && NoClip_Timer != 0)
		{
			NoClip_Timer--;
			if (NoClip_Timer == 1 && NoClip_Timer != 0)
			{
				WriteData((int*)0x00444C1D, (int)0xFF37EEE8);
				WriteData((int*)0x00444C21, (int)0x10C483FF);
				WriteData((int*)0x0044A66B, (int)0xFFA430E8);
				WriteData((int*)0x0044A66F, (int)0x14C483FF);
				WriteData((int*)0x007887D9, (int)0x00D042E8);
				WriteData((int*)0x007887DD, (int)0x74C08500);
				NoClip_Timer = 0;
				strcpy_s(LastEffect, 128, "Walk Thru Walls Disabled");
			}
		}
		if (InputInvert_Timer <= 420 && InputInvert_Timer != 0)
		{
			InputInvert_Timer--;
		}
		if (InputInvert_Timer == 1 && InputInvert_Timer != 0)
		{
			WriteData<1>((int*)0x40F2A2, 0xF0);
			WriteData<1>((int*)0x40F2A1, 0x2B);
			InputInvert_Timer = 0;
			strcpy_s(LastEffect, 128, "Input Set to Default");
		}
		if (Camera_Timer <= 100 && Camera_Timer != 0)
		{
			Camera_Timer--;
		}
		if (Camera_Timer == 1 && Camera_Timer != 0)
		{
			Camera_Data1->Action = 2;
			Camera_Timer = 0;
			strcpy_s(LastEffect, 128, "Camera Attached");
		}
		if (XGravity_Timer <= 1000 && XGravity_Timer != 0)
		{
			XGravity_Timer--;
		}
		if (XGravity_Timer == 1 && XGravity_Timer != 0)
		{
			ResetGravity();
			XGravity_Timer = 0;
			strcpy_s(LastEffect, 128, "X Gravity Reset");
		}
		if (YGravity_Timer <= 1000 && YGravity_Timer != 0)
		{
			YGravity_Timer--;
		}
		if (YGravity_Timer == 1 && YGravity_Timer != 0)
		{
			ResetGravity();
			YGravity_Timer = 0;
			strcpy_s(LastEffect, 128, "Y Gravity Reset");
		}
		if (ZGravity_Timer <= 1000 && ZGravity_Timer != 0)
		{
			ZGravity_Timer--;
		}
		if (ZGravity_Timer == 1 && ZGravity_Timer != 0)
		{
			ResetGravity();
			ZGravity_Timer = 0;
			strcpy_s(LastEffect, 128, "Z Gravity Reset");
		}
		if (NoGravityTimer <= 400 && NoGravityTimer != 0)
		{
			NoGravityTimer--;
		}
		if (NoGravityTimer == 1 && NoGravityTimer != 0)
		{
			ResetGravity();
			strcpy_s(LastEffect, 128, "Gravity Restored");
		}
		if (DebugToScreen)
		{
			ScaleDebugFont(15);
			SetDebugFontColor(0xFFFFFFFF);
			DrawDebugRectangle(0.30f, 7.90f, 17.9f, 6.2f);
			DisplayDebugStringFormatted(NJM_LOCATION(0, 7), " %s", LastEffect);
		}
		if (DisableControl_Timer <= 90 && DisableControl_Timer != 0)
		{
			DisableControl_Timer--;
		}
		if (DisableControl_Timer == 1 && DisableControl_Timer != 0)
		{
			ControlEnabled = 1;
			DisableControl_Timer = 0;
			strcpy_s(LastEffect, 128, "Control Enabled");
		}
		if (DPadDown_Timer <= 90 && DPadDown_Timer != 0)
		{
			SetDebugFontColor(0xFFFF0000);
			ScaleDebugFont(18);
			DisplayDebugString(NJM_LOCATION(15, 40), "- PRESS DPAD DOWN OR DIE!!! -");
			if (ControllerPointers[0]->HeldButtons & Buttons_Down) //checks if dpad pressed down
			{
				DpadDown = 1; // sets dpadcheck to 1
			}
			DPadDown_Timer--;
		}
		if (DPadDown_Timer == 1 && DpadDown != 1)//if timer is less then or 1 and DPadDown is not 1 
		{
			KillPlayer(0);
			DPadDown_Timer = 0;
		}
		if (Pause_Timer <= 5 && Pause_Timer != 0)
		{
			GameState = 16;
			Pause_Timer--;
		}
		if (SnowboardTimer <= 500 && SnowboardTimer != 0)
		{
			SnowboardTimer--;
		}
		if (SnowboardTimer == 1 && SnowboardTimer <= 2 && IssSowboarding == 1)
		{
			SnowboardTimer = 0;
			IssSowboarding = 0;
			EntityData1Ptrs[0]->Action = 1;
			strcpy_s(LastEffect, 128, "Snowboard Off");
		}
		if (FastAccel_Timer <= 400 && FastAccel_Timer != 0)
		{
			FastAccel_Timer--;
		}
		if (FastAccel_Timer <= 2 && FastAccel_Timer != 0)
		{
			CharObj2Ptrs[0]->PhysicsData.MaxAccel = 3.0f;
			CharObj2Ptrs[0]->PhysicsData.AirAccel = 0.03099999949f;
			CharObj2Ptrs[0]->PhysicsData.HangTime = 60;
			strcpy_s(LastEffect, 128, "Fast Accel Disabled");
			FastAccel_Timer = 0;
		}
		if (s0und__Timer <= 222 && s0und__Timer != 0)
		{
			s0und__Timer--;
		}
		if (s0und__Timer == 1 && s0und__Timer != 0)
		{
			ResumeSound();
			EnableBGM = 1;
			VoicesEnabled = true;
			WriteData((int*)0x03B29CE0, (int)0x00000000);
			strcpy_s(LastEffect, 128, "s0und_ Enabled");
			s0und__Timer = 0;
		}
		if (RingAllergy_Timer <= 500 && RingAllergy_Timer != 0)
		{
			if (Rings != RingCount)
			{
				KillPlayer(0);
			}
			RingAllergy_Timer--;
		}
		if (RingAllergy_Timer == 1 && RingAllergy_Timer != 0)
		{
			RingAllergy_Timer = 0;
		}
		if (DisablePause_Timer <= 420 && DisablePause_Timer != 0)
		{
			DisablePause_Timer--;
		}
		if (DisablePause_Timer == 1 && DisablePause_Timer != 0)
		{
			PauseEnabled = true;
			strcpy_s(LastEffect, 128, "Pause Enabled");
			DisablePause_Timer = 0;
		}
		if (Debug_Timer <= 333 && Debug_Timer != 0)
		{
			Debug_Timer--;
		}
		if (Debug_Timer <= 2 && Debug_Timer != 0)
		{
			EntityData1Ptrs[0]->Action = 1;
			strcpy_s(LastEffect, 128, "Debug Off");
			Debug_Timer = 0;
			DebugEnabled = false;
		}
		if (Chaos_Timer < EffectMax)//30 seconds is 1800
			Chaos_Timer++;
		if (Chaos_Timer >= EffectMax)
		{
			char curRand = 0;
			do {
				curRand = rand() % ChaosSize;
			} while (oldRand == curRand);
			if (ChaosArray[curRand].func != nullptr)
				ChaosArray[curRand].func(EntityData1Ptrs[0]);
			else if (ChaosArray[curRand].func2 != nullptr)
				ChaosArray[curRand].func2(CharObj2Ptrs[0]);
			else
				ChaosArray[curRand].func3();
			oldRand = curRand;
			Chaos_Timer = 0;
		}
	}
	__declspec(dllexport) void __cdecl OnInput()
	{
	}
	__declspec(dllexport) void __cdecl OnControl(EntityData1* p1)
	{
		 //Executed when the game processes input
		if (Controllers[0].PressedButtons & Buttons_Y) //Debug Testing
		{
			RandomDroppedRings(0);
		}
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}