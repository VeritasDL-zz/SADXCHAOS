#pragma once
#include <math.h>
DataPointer(NJS_TEXLIST, texlist_l_sibuki, 0x2F3E234);
DataPointer(NJS_ACTION, action_l_sibuki, 0x2F3F3B4);
DataPointer(NJS_ACTION, action_l_circle, 0x2F3F614);
DataPointer(NJS_OBJECT, objPillar, 0x3C84CC0);
DataPointer(NJS_OBJECT, object_l_hasira_l_hasira, 0x2F3F0A0);
DataPointer(NJS_TEXLIST*, njds_texList, 0x03ABD950);
DataPointer(int, njds_texNum, 0x03AB9934);
FunctionPointer(void*, MAlloc, (int size), 0x40B220);
void __cdecl destTaskGeneric(task* tp);
extern task* p_WaterPillarTask;
void __cdecl createSplashTask(float pos_x, float pos_y, float pos_z, float play_spd, float scale);
struct __declspec(align(4)) PillarWork
{
	NJS_POINT3 scl;
	NJS_POINT3 dscl;
	NJS_ARGB col;
	NJS_ARGB dcol;
	__int16 uvscr_spd;
};
void __cdecl WaterPillarOn(float pos_x, float pos_y, float pos_z, float play_spd, float scale);
void __cdecl WaterPillarOff();
void __cdecl createPillar(float pos_x, float pos_y, float pos_z, float play_spd, float scale);

