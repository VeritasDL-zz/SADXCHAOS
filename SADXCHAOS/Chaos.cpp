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


//Changelog
//Started Mod 8/5/2021
//Added code base from Soar's scrapped "mania" mode
//Added debug print out for mods being enabled
//Added random time of day
//Added random dropped rings
//Added random Clip level (not sure if it works)
//Added randompause (not sure if it works)
//Added random char
//Added random camera (not sure if it works)
//Added random debug (not sure if it works and i need a way to turn it off after a short period
//Added random xyz gravity (havent enabled them or tested them)
//Added random barrier
//Added random mag barrier
//Added invincibility
//Added random debug
//Random powerup was crashing due to bomb power up? havent fixed
//Sometimes the other give powerup codes i have kill the player depending on the state? 
//Fixed random power up crash, by taking soras random power up code form sadxvschat
//Updated random pause to make you unpause a few times, (currently 10 frames) idk how i would make it pause, unpause, automaticly cuz setting gamestate in ONFrame just makes it happen so fast you dont even see it, 
//Removed set scale
//Removed my own random powerups, (still in code, just unused)
//Made debug last a set amount of frames (75 currently) and force the player out of debug movement.
//Added press Dpad Down or die
//Changed random camera to Swap Camera lol
//Added random control disable 
//Added Random Y Gravity
//Added Random NoClip
//Fixed Random NoClip Crash?
//Made debug mode work again
//Made debug mod last longer might make shorter
//Fixed Camera Swap Code
//Made Control Disable look better
//Made Control Disable last longer? might shorten
//Fixed random Gavity values maybe?
//Started working on random tikal hints - thanks for the help kell, main and refrag, 
//Finished random tikal hint, just need to add more hints, 
//Added more hints and the first custom hint with custom voice file!
//Re-Enabled Random Dropped Rings (8/11/2021)
//Fixed a bug with RandomTimeOfDay setting the chao timer to 1800
//Fixed debug mode crash, gg 
//Credits to MainMemory for the Snowboard spawn Code, https://github.com/MainMemory/SADXBoardSpawner
//Cleaned up no clip code
//Cleaned up control disable code
//Changed y grav rand math
//Cleaned up ints
//Made Kill Momentum play the custom roblox OOF sound,
//Added random checkpoint (might not work as a real checkpoint but funny af)
//Added Movement Stick Invert code thanks to Sora!
//Added support for knux, amy, and metal sonic to movement debug, Tails, gamma and big dont have movement debug thanks to stars for pointing out im dumb,
//Added random rotate
//Trying to add support for editing the chaos timer, shits fucked 
//Started adding Random Telport with the help of Refrag :)
//Added Ability to edit How often things happen in the config menu
//Cleaned up debug Output a little
//Changed how long Gravity, noclip, and snowboard last before being disabled
//Finished sonic casino act 0 teleports
//Started working on casino act 1 teleport (might work for tails and sonic)
//Changed gravity random math again
//Finished Casino act 1 teleports
//Finished teleports to emeraldcoast act 0
//Finished icecap act 0 and 1 teleports
//Finished speedhighway act 0 sonic teleports
//Started working on act 2 speedhighway sonic teleports
//Added Random Life PowerUp
//Finished randomteleport crashing when not in a level/act that have teleports thanks to refrag again!
//Finished twinkle park teleports
//Added Option for Last Effect to Be Printed to Game Screen
//Changed size, color and position of Last Effect text, also render a paque/translucent box around it.
//Re Enabled Random Hurt
//Added Option to print last effet to screen
//Added Ability to spawn Enemys
//Added more Enemys lol
//Added RandomBurgerMan
//Actully enabled Random Rotate.
//Added 24 new tikal hints
//Added more new "hints"
//Sadly i have a crash with enemys in hub-worlds, only Beat, and Spinners can spawn in hubworlds currently 
//Added randomchao, thanks to sora for the help and shuch
//Added config options for, Random Enemys, Input Invert and RandomPause
//Added FastAccel (for now) 
//Added random physics thanks to MainMemory (https://github.com/MainMemory/SADXPhysicsSwapMod) and Refrag  
//Added Decoupple Camera
//Added no sound,
//Fixed a bug with fast accel
//Added Disable Pause
//Fixed a few warnings
//Added Random Key Block
//Added random colors for the random key block, 
//Added random emblem.
//Fixed a bug with the texture loader resetter 
//Added config to disable, disable pause
//Removed OOF from Kill momentum
//Updated Effect Table
//Tikal Hint now 20% less likely
//RandomKillMomentum 20% less likly
//Changed no_s0und_ to 222 frames from 110 frames
//Ghetto fix for Y offset change with Random Phys.
//Fix for Debug Scaling thanks to PKR's Debug mod https://github.com/PiKeyAr/sadx-debug-mode/
//Fix for debug mod stacking
//Added Random Chao Fruit and Chao Hat, thanks to kell and pkr
//Changed most spawn things to using tasks, removed creation of setdata for objects that dont need it.
//Fixed RandomFallingSpikeBall moving up and down 
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
//Split up code into multipul CPP files
//Moved Tikal Hints to its own .h/.cpp file
//Moved debug draw to its own .h/.cpp file too
//Added Ring Allergy and Config For Ring Allergy, 
//Fixed Ring Allergy (I think)
//Added A EggViper HandyCap, with config option, (1/22/2022)
//Removed IceBall from spawning while playing as gamma (1/22/2022)
//Fixed RandomSnowboard trying to run when not playing as Sonic Or Tails (1/22/2022)
//Temp Commented out All Random Char Init Fixes (1/22/2022)
//Added Check for Big Fishing to make playing a big a little bit easier (1/22/2022)
//Disabled Enemies From Spawning Durring E101R boss fight (1/25/2022)
//fixed bug with big fishing code (1/22/2022)
//Stopped sman for spawning durring egg viper (1/22/2022)
//Added IncreaseCutsceneSkipTime - Sets Frames needed to skip to 1A2 (1/29/2022)
//Started working on remove powerup (1/29/2022)
//Still working on remove powerup (1/30/2022)
//Created a NewEffect function and made all skipped mods call the function (1/30/2022)
//Fixed a bug with DisablePause and RingAllergy (1/30/2022)
//Enabled RingAllergy (2/1/2022)
//Enabled BigRock (2/1/2022)
//Changed RandomDroppedRings to Use TakeRingsInterval1 rather then set rings to 0 (2/15/2022)
//Added FlipCamera thanks to Skoob (2/18/2022)
//Added SpinCamera (2/18/2022)
//Added FlipCamera and SpinCamera to ChaosArray (2/18/2022)
//Shuffled ChaosArray because why not (2/18/2022)
//Added DrunkCamera (2/20/2022)
//Added DrunkCamera to the array (2/25/2022)
//Added Config Option for The Three Camera Effects (2/25/2022)
//Added Custom Teleports for all three acts of Sonic's Final Egg (2/25/2022)
//Workin on adding the fans from final egg act 2 to the object spawn list, (2/25/2022)
//Finished RandomFan thanks to Sora! (2/25/2022)
//Moved texture reset bools to its own .cpp file (2/26/2022)
//Fixed a small "bug" with FastAccel (2/26/2022)
//Shuffled chaos array again (2/26/2022)
//Small change to randompowerup removal (2/27/2022)
//Added 12 new Tikal Hints (2/28/2022)
//Fixed Random Emblem (3/1/2022)
//Added Config Option for Random Emblem (3/1/2022) 
//Working on Random Air Craft (3/3/2022)
//Sorta Finished Random Air Craft (3/4/2022)
//Random AirCraft finished thanks to Sora for the help (3/5/2022)
//Moved Animal Text Loader to its own.cpp/.h file (3/5/2022)
//Switched all Enemeys to use CheckAnimalTexture(); (3/5/2022)
//Started RandomFireBreath (3/5/2022)
//Removed all use of EntityData1Ptrs[0] in use of playertwp[0] (3/5/2022)
//Finished RandomFireBreath (3/5/2022)
// 
// 
// 
// 
//---------TO-DO---------
// Test Stuff
// Log Known Crashes
// Add More Custom Tikal Hints
// Add More Random Teleport Locations
// More Camera Effects? (Sideways?)
// Need to Fix Ice&Wind Key
// Need to fix or scrap Big Car
// AddCannon_s1 and Cannon_s2
// 
// 
// 
//Todo
//Random emblem broke 
//Kill momentum doesn't always work?
//Beat has bad texture in redmountain? 
//Gamma hs, ham crashed 7 times, in a row
//Seems to be related to gamma locking onto enemys he was never intended to? idk

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
int SaveHash = -1;
int FruitNumb = -1;
int HatNumb = -1;
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
		char P1Action = playertwp[0]->mode;
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
	ChaosS ChaosArray[107]
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
		if (!CharObj2Ptrs[0] || GameState != 15 || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || CurrentLevel >= LevelIDs_SSGarden)
			return;
		if (NoClip_Timer <= 800 && NoClip_Timer != 0)
		{
			NoClip_Timer--;
			if (NoClip_Timer == 1 && NoClip_Timer != 0)
			{
				WalkThruWallsReset();
				NoClip_Timer = 0;
				strcpy_s(LastEffect, 128, "Walk Thru Walls Disabled");
				return;
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
			if (ControllerPointers[0]->HeldButtons & Buttons_Down) //Checks if dpad pressed down
			{
				DpadDown = 1; //Sets dpadcheck to 1
			}
			DPadDown_Timer--;
		}
		if (DPadDown_Timer == 1 && DpadDown != 1)//If timer is 1 and DPadDown is not 1 
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
			playertwp[0]->mode = 1;
			strcpy_s(LastEffect, 128, "Snowboard Off");
		}
		if (FastAccel_Timer <= 400 && FastAccel_Timer != 0)
		{
			FastAccel_Timer--;
		}
		if (FastAccel_Timer <= 2 && FastAccel_Timer != 0)
		{
			CharObj2Ptrs[0]->PhysicsData.MaxAccel = OldMaxAccel;
			CharObj2Ptrs[0]->PhysicsData.AirAccel = OldAirAccel;
			CharObj2Ptrs[0]->PhysicsData.HangTime = OldHangTime;
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
		if (CameraFlip_Timer <= 480 && CameraFlip_Timer != 0)
		{
			CameraFlip_Timer--;//subtract timer
			SetCameraMode_(0);//Force AutoCam
			WriteData((int*)0x03B2C68C, (int)0x8000); //force upside down
		}
		if (CameraFlip_Timer == 1 && CameraFlip_Timer != 0)
		{
			CameraReset();//resets camera ASM
			CameraFlip_Timer = 0;//set timer to 0 
		}
		if (CameraSpin_Timer <= 480 && CameraSpin_Timer != 0)
		{
			SetCameraMode_(0);//Force AutoCam
			CameraSpin_Val += 0x300; //spins camera 
			CameraSpin_Timer--;//subtract timer
			WriteData((int*)0x03B2C68C, (int)CameraSpin_Val); //force camera spin
		}
		if (CameraSpin_Timer == 1 && CameraSpin_Timer != 0)
		{
			CameraReset();//resets camera ASM
			CameraSpin_Timer = 0;//set timer to 0 
			CameraSpin_Val = 0;//set spin val to 0 
		}
		if (DrunkCamera_Timer <= 550 && DrunkCamera_Timer != 0)
		{
			SetCameraMode_(0);//Force AutoCam
			CameraNOP();
			DrunkCam = *(int*)0x03B2C68C;
			DrunkCam += Direction;
			if (DrunkCam >= 4269)
			{
				Direction = -0x40;
			}
			else if (DrunkCam <= -4269)
			{
				Direction = +0x40;
			}
			WriteData((int*)0x03B2C68C, (int)DrunkCam); //force camera sway
			DrunkCamera_Timer--;//subtract timer
		}
		if (DrunkCamera_Timer == 1 && DrunkCamera_Timer != 0)
		{
			CameraReset();//resets camera ASM
			DrunkCamera_Timer = 0;//set timer to 0 
			DrunkCam = 0;
			Direction = 0x50;//resets direction 
			WriteData((int*)0x03B2C68C, (int)0x0); //force camera reset
		}
		if (Debug_Timer <= 333 && Debug_Timer != 0)
		{
			Debug_Timer--;
		}
		if (Debug_Timer <= 2 && Debug_Timer != 0)
		{
			playertwp[0]->mode = 1;
			strcpy_s(LastEffect, 128, "Debug Off");
			Debug_Timer = 0;
			DebugEnabled = false;
		}
		if (AirCraftSpawerFollow_Timer <= 350 && AirCraftSpawerFollow_Timer != 0)
		{
			RandomSpawnAmount = rand() % 50;
			if (RandomSpawnAmount == 0)
			{
				RandomAirCraft(0);
			}
			AirCraftSpawerFollow_Timer--;
		}
		if (AirCraftSpawerFollow_Timer == 1)
		{
			AirCraftSpawerFollow_Timer = 0;
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
			RandomFireBreath(0);
		}
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}