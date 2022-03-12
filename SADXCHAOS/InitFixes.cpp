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
#include "Chaos.h"
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
void OverRideEmeraldShardObj()
{
	njSetTexture(&OBJ_RUIN_TEXLIST);
}
void Init_Fixes(const char* path, const HelperFunctions& helperFunctions)
{
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
	UpsideDownCameraEnabled = config->getBool("Camera", "UpsideDownCameraEnabled", true);
	DrunkCameraEnabled = config->getBool("Camera", "DrunkCameraEnabled", true);
	SpinCameraEnabled = config->getBool("Camera", "SpinCameraEnabled", true);
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
	WriteCall((void*)0x6F4BD5, OverRideEmeraldShardObj);//test
	WriteCall((void*)0x6F4D81, OverRideEmeraldShardObj);//test
	WriteCall((void*)0x6F4EE0, OverRideEmeraldShardObj);//test
	WriteJump(Snowboard_Delete, Snowboard_Delete_r);
	WriteData((char*)0x4EE7BB, (char)4);//Big ice rock pickup ability
	//WriteData((char*)0x639A00, (char)4);//Patch for Picking Up Car in Station Square Act 0
	WriteData((int*)0x017D0A2C, (int)0xC7C35000);//Stops the amy key block from exploding 
	WriteData((int*)0x017D0A38, (int)0xC7C35000);//Stops the amy key block from exploding
	WriteData((int*)0x017D0A44, (int)0xC7C35000);//Stops the amy key block from exploding
	WriteData((int*)0x017D0A50, (int)0xC7C35000);//Stops the amy key block from exploding
	srand((unsigned)time(nullptr));
}