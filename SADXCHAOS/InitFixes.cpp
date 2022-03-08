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
void Init_Fixes()
{
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
}