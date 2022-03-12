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
int RNG = 0;
int RNG2 = 0;
int DpadDown = 0;
int RingCount = 0;
int IssSowboarding = 0;
int CameraSide = 0;
int Animaltyperand = 0;
int EVHandyCap = 0;
float OldMaxAccel = 0;
float OldAirAccel = 0;
float OldHangTime = 0;
void NewEffect()
{
	Chaos_Timer = EffectMax;
	return;
}
void DisablePausee()
{
	if (!PauseDisableEnabled)
	{
		NewEffect();
		return;
	}
	PauseEnabled = false;
	DisablePause_Timer = 420;
	strcpy_s(LastEffect, 128, "Pause Disabled");
}
void EggViperHandiCapCheck()
{
	if (EggViperHandyCapEanbled)
	{
		if (CurrentLevel == LevelIDs_EggViper)
		{
			int EVHandyCap = rand() % 5;
			if (EVHandyCap != 0)
			{
				NewEffect();
				return;
			}
		}
	}
	return;
}
void CameraNOP()
{
	WriteData<7>((int*)0x0046261B, 0x90); //nops ASM
	WriteData<3>((int*)0x0046620A, 0x90); //nops ASM
	WriteData<6>((int*)0x004372DD, 0x90); //nops ASM
	WriteData<3>((int*)0x00465E83, 0x90); //nops ASM
	WriteData<3>((int*)0x00465EDA, 0x90); //nops ASM
	WriteData<3>((int*)0x00468299, 0x90); //nops ASM
	return;
}
void CameraReset()
{
	WriteData((int*)0x0046261B, (int)0x002C42C7); //Reset Nopped ASM
	WriteData((int*)0x0046261F, (int)0x83000000); //Reset Nopped ASM
	WriteData((int*)0x0046620A, (int)0x8B2C4889); //Reset Nopped ASM
	WriteData((int*)0x004372DD, (int)0xC68C3589); //Reset Nopped ASM 
	WriteData((int*)0x004372E1, (int)0x05C703B2); //Reset Nopped ASM
	WriteData((int*)0x00465E83, (int)0xD92C4A89); //Reset Nopped ASM
	WriteData((int*)0x00465EDA, (int)0xA1909090); //Reset Nopped ASM
	WriteData((int*)0x00468299, (int)0xE82C6989); //Reset Nopped ASM
	return;
}
void WalkThruWallsNop()
{
	WriteData((int*)0x00444C1D, (int)0x90909090);
	WriteData((int*)0x00444C21, (int)0x10C48390);
	WriteData((int*)0x0044A66B, (int)0x90909090);
	WriteData((int*)0x0044A66F, (int)0x14C48390);
	WriteData((int*)0x007887D9, (int)0x90909090);
	WriteData((int*)0x007887DD, (int)0x74C08590);
	return;
}
void WalkThruWallsReset()
{
	WriteData((int*)0x00444C1D, (int)0xFF37EEE8);
	WriteData((int*)0x00444C21, (int)0x10C483FF);
	WriteData((int*)0x0044A66B, (int)0xFFA430E8);
	WriteData((int*)0x0044A66F, (int)0x14C483FF);
	WriteData((int*)0x007887D9, (int)0x00D042E8);
	WriteData((int*)0x007887DD, (int)0x74C08500);
	return;
}
player_parameter PhyData[38]  //credits to MainMemory For this data, https://github.com/MainMemory/SADXPhysicsSwapMod
{
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,3,16,16,3,1,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.06,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,8.5,18,0.08,7,5.3,
	60,1.5,16,16,2,0.6,1.66,3,0.23,0.49,1.39,2.8,3.7,5.09,0.076,0.06,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,3.5,9,0.08,6,4.5,
	60,2,16,16,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,4,11.4,0.08,9,5.7,
	60,2,16,16,3,1,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.06,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,4,10,0.08,7,5,
	60,1.5,16,16,0.05,0.5,1.3,3,0.23,0.46,1.39,2.3,3.7,5.09,0.013,0.045,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,3.5,10,0.04,7,5,
	60,2,16,16,2.5,0.6,2,3,0.23,1,2,2.5,3.7,5.09,0.09,0.06,0.031,-0.06,-0.25,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.9,0.3,4,21,0.1,20,14,
	60,2,5,8,1,0.2,2,3,0.23,0.32,1.39,2.3,3.7,5.09,0.1,0.08,0.031,-0.08,-0.18,-0.17,-0.028,-0.04,-0.01,-0.4,-0.1,-0.6,-0.2,0.3,9.5,17,0.135,15,8,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.05,-0.06,-0.18,-0.17,-0.002,-0.001,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	40,1.5,16,16,0.6,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,4,0.076,0.048,0.031,-0.06,-0.18,-0.17,-0.028,-0.01,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,3.5,9,0.08,6,4.5,
	0,3,16,16,3,1,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.06,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,8.5,15.5,0.08,14.5,10,
	60,2,16,16,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,4,11.4,0.08,9,5.7,
	60,2,16,16,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,4,11.4,0.08,9,5.7,
	16,3,16,16,1,1,2.6,3,0.23,0.46,1.39,1.8,2,3,0.19,0.1,0.031,-0.1,-0.18,-0.17,-0.028,-0.014,-0.02,-0.4,-0.1,-0.6,-0.3375,0.3,8,21,0.2,20,15,
	16,3,16,16,1,1,2.6,3,0.23,0.46,1.39,1.8,2,3,0.19,0.1,0.031,-0.1,-0.18,-0.17,-0.028,-0.014,-0.02,-0.4,-0.1,-0.6,-0.3375,0.3,8,21,0.2,20,15,
	60,2,16,16,1.3,0.6,1.3,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.048,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,2.52,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.2,0.05,-0.01,-0.02,-0.03,-0.028,-0.008,-0.01,-0.4,-0.4,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	16,3,16,16,1.4,1,2.6,3,0.23,0.46,1.39,1.8,2,3,0.19,0.2,0.046,-0.1,-0.18,-0.17,-0.028,-0.014,-0.02,-0.4,-0.4,-0.6,-0.3375,0.3,8,21,0.2,20,15,
	16,3,16,16,0.7,1,2.6,3,0.23,0.46,1.39,1.8,2,3,0.19,0.07,0.025,-0.1,-0.18,-0.17,-0.028,-0.014,-0.02,-0.4,-0.07,-0.6,-0.3375,0.3,8,21,0.2,20,15,
	60,2,16,16,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.06,0.031,-0.06,-0.2,-0.17,-0.028,-0.008,-0.01,-0.4,-0.3,-0.6,-0.45,0.3,4,11.4,0.08,9,5.7,
	60,2,16,16,1,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.09,-0.6,-0.3375,0.3,4,11.4,0.08,9,5.7,
	60,2,32,32,6,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.1,0.031,-0.09,-0.15,-0.14,-0.028,-0.008,-0.01,-0.4,-0.25,-0.8,-0.6,0.3,4,10,0.08,7,5.4,
	60,2,32,32,2.5,0.6,1.66,3,0.18,0.46,1.39,2.3,3.7,5.09,0.076,0.048,0.035,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.35,-0.85,-0.35,0.5,4,10,0.08,7,5.4,
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,4,10,0.08,7,5.4,
	60,2,32,32,6,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.1,0.031,-0.09,-0.15,-0.14,-0.028,-0.008,-0.01,-0.4,-0.25,-0.8,-0.6,0.3,4,10,0.08,7,5.4,
	60,2,32,32,2.5,0.6,1.66,3,0.18,0.46,1.39,2.3,3.7,5.09,0.076,0.048,0.035,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.35,-0.85,-0.35,0.5,6,15,0.08,14,7.5,
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,4,10,0.08,7,5.7,
	60,2,32,32,4.5,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.09,0.031,-0.06,-0.18,-0.14,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,32,32,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,8.5,18,0.08,18,9,
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,3.5,9,0.08,6,4.5,
	60,2,32,32,6,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.1,0.031,-0.09,-0.15,-0.14,-0.028,-0.008,-0.01,-0.4,-0.25,-0.8,-0.6,0.3,4,10,0.08,7,5.4,
	60,2,32,32,2.5,0.6,1.66,3,0.18,0.46,1.39,2.3,3.7,5.09,0.076,0.048,0.035,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.35,-0.85,-0.35,0.5,8,17,0.08,16,8.5,
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,3.5,9,0.08,6,4.5
};
static const char* Physnames[] = {
	"Sonic",
	"Eggman",
	"Tails",
	"Knuckles",
	"Tikal",
	"Amy",
	"Gamma",
	"Big",
	"Super Sonic",
	"Sa2b Sonic",
	"Sa2b Shadow",
	"Sa2b Tails",
	"Sa2b Eggman",
	"Sa2b Knuckles",
	"Sa2b Rouge",
	"Sa2b Mech Tails",
	"Sa2b Mech Eggman",
	"Sa2b Amy",
	"Sa2b Super Sonic",
	"Sa2b Super Shadow",
	"Sa2b Unused",
	"Sa2b Metal Sonic",
	"Sa2b Chao Walker",
	"Sa2b Dark Chao Walker",
	"Sa2b Tikal",
	"Sa2b Chaos",
	"Sa2b Unused2",
	"Sa2b Unused3",
	"Heroes Sonic",
	"Heroes Knuckles",
	"Heroes Tails",
	"Heroes Shadow",
	"Heroes Omega",
	"Heroes Rouge",
	"Heroes Amy",
	"Heroes Big",
	"Heroes Cream",
	"Heroes Espio",
	"Heroes Vector",
	"Heroes Charmy"
};
void RandomPhysics()
{
	if (!RPhysicsEnabled)
	{
		NewEffect();
		return;
	}
	int Phyrand = rand() % 38;
	int OldYOffset = playerpwp[0]->p.center_height; //store current Y Offset
	player_parameter tmp = (player_parameter)PhyData[Phyrand];
	memcpy(&playerpwp[0]->p, &tmp, sizeof(player_parameter));
	playerpwp[0]->p.center_height = OldYOffset;//restores Saved Y Offset.
	snprintf(LastEffect, 128, "%s Physics", Physnames[Phyrand]);
}
void Nos0und_ForYou()
{
	PauseSound();
	EnableBGM = 0;
	VoicesEnabled = false;
	WriteData((int*)0x03B29CE0, (int)0xFFFFFFFF);
	strcpy_s(LastEffect, 128, "s0und_ Disabled");
	s0und__Timer = 222;
}
void UncoupleCamera()
{
	camera_twp->mode = 3; //uncouples camera from char
	Camera_Timer = 100;
	strcpy_s(LastEffect, 128, "Camera Detached");
}
void RandomChaooAnimal()
{
	Animaltyperand = rand() % 15 - 1;
	return;
}
void RandomChaoo()
{
	if (!ChaooManagerLoader)
	{
		ChaoMain_Constructor();
		al_confirmload_load();
		ChaoManager_Load();
		ChaooManagerLoader = true;
	}
	int chaotype = rand() % 24;
	ChaoData* chaodata = new ChaoData();
	chaodata->data.Happiness = rand() % 99;
	chaodata->data.Energy = rand() % 32767;
	chaodata->data.Hunger = rand() % 32767;
	chaodata->data.StaminaStat = rand() % 3266;
	chaodata->data.StaminaLevel = rand() % 99;
	chaodata->data.FlyStat = rand() % 3266;
	chaodata->data.FlyLevel = rand() % 99;
	chaodata->data.PowerStat = rand() % 3266;
	chaodata->data.PowerLevel = rand() % 99;
	chaodata->data.RunStat = rand() % 3266;
	chaodata->data.RunLevel = rand() % 99;
	chaodata->data.SwimStat = rand() % 3266;
	chaodata->data.SwimLevel = rand() % 99;
	chaodata->data.UnknownLevel = rand() % 99;
	chaodata->data.IntelligenceLevel = rand() % 99;
	chaodata->data.FavoriteFruit = rand() % 7;
	chaodata->data.Texture = rand() % 15;
	int bodychangechance = rand() % 10;
	if (bodychangechance == 1)
	{
		int bodyrand = rand() % 3;
		chaodata->data.BodyType = (SADXBodyType)bodyrand;
	}
	int shinychance = rand() % 4;
	if (shinychance == 1)
	{
		chaodata->data.Shiny = 1;
	}
	chaodata->data.MouthType = rand() % 14;
	chaodata->data.EyeType = rand() % 12;
	chaodata->data.BallType = rand() % 3;
	chaodata->data.Alignment = rand() % 2 - 1; //test
	ObjectMaster* Chao = CreateChao(chaodata, 0, 0, &playertwp[0]->pos, 0);
	chaodata->data.Color = rand() % 14;
	chaodata->data.Name[0] = rand() % 255;
	chaodata->data.Name[1] = rand() % 255;
	chaodata->data.Name[2] = rand() % 255;
	chaodata->data.Name[3] = rand() % 255;
	chaodata->data.Name[4] = rand() % 255;
	chaodata->data.Name[5] = rand() % 255;
	chaodata->data.Name[6] = rand() % 255;
	chaodata->data.FlyGrade = rand() % 5;
	chaodata->data.IntelligenceGrade = rand() % 5;
	chaodata->data.LuckyGrade = rand() % 5;
	chaodata->data.PowerGrade = rand() % 5;
	chaodata->data.RunGrade = rand() % 5;
	chaodata->data.StaminaGrade = rand() % 5;
	chaodata->data.SwimGrade = rand() % 5;
	strcpy_s(LastEffect, 128, "Spawned Random Chao");
}
void RandomKillMomentum(playerwk* p1)
{
	playerpwp[0]->spd = { 0, 0, 0 };
	strcpy_s(LastEffect, 128, "Killed Momentum");
	return;
}
void FastAccel(playerwk* p1)
{
	EggViperHandiCapCheck();
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	FastAccel_Timer = 400;
	OldMaxAccel = playerpwp[0]->p.max_x_spd;
	OldAirAccel = playerpwp[0]->p.air_accel;
	OldHangTime = playerpwp[0]->p.jump2_timer;
	playerpwp[0]->p.max_x_spd = 10.0f;
	playerpwp[0]->p.air_accel = 0.10f;
	playerpwp[0]->p.jump2_timer = 120;
	strcpy_s(LastEffect, 128, "Fast Accel Enabled");
	return;
}
void RandomVSpeed(playerwk* p1)
{
	EggViperHandiCapCheck();
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	playerpwp[0]->spd.y = playerpwp[0]->p.lim_v_spd;
	strcpy_s(LastEffect, 128, "Random V Speed");
	return;
}
void RandomHSpeed(playerwk* p1)
{
	EggViperHandiCapCheck();
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	playerpwp[0]->spd.x = playerpwp[0]->p.lim_h_spd;
	strcpy_s(LastEffect, 128, "Random H Speed");
	return;
}
void RandomHurt()
{
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	if (Rings > 0)
	{
		HurtCharacter(0);
		strcpy_s(LastEffect, 128, "Hurt");
		return;
	}
	else
	{
		NewEffect();
		return;
	}
}
void RandomPowerUP(taskwk* p1)
{
	int id = 0;
	if (id < 0 || id > 8) //failsafe
		id = rand() % 9;
	DoThingWithItemBoxPowerupIndex(id);
	strcpy_s(LastEffect, 128, "Random PowerUp");
}
void RandomTimeOfDay() //sets time of day to a random time,
{
	if (GameMode == GameModes_Adventure_Field)//made it so it only changes if you are in adventure field
	{
		SetTimeOfDay(rand() % 3);
		strcpy_s(LastEffect, 128, "Random Time Of Day");
		return;
	}
	else
	{
		NewEffect();
		return;//forces another Chaos mod if not in Adventure 
	}
}
void RandomDroppedRings(taskwk* p1)
{
	int randomrings = rand() % 254;
	SpawnDroppedRings(playertwp[0]->pos.x, playertwp[0]->pos.y, playertwp[0]->pos.z, randomrings); //spawns random ammount of rings 0-255 at the player
	TakeRingsInterval1(randomrings);
	strcpy_s(LastEffect, 128, "Dropped Rings");
}
void RandomPause() //randomly pauses the game LOL get good
{
	if (!RPauseEnabled)
	{
		NewEffect();
		return;
	}
	Pause_Timer = 5; //how long in frames? to pause unpause?
	strcpy_s(LastEffect, 128, "Random Pause");
}
void SwapCamera()//Swaps Camera lmfao
{
	if (GetCameraMode_() == 0)
	{
		SetCameraMode_(1);
	}
	else if (GetCameraMode_() == 1)
	{
		SetCameraMode_(0);
	}
	strcpy_s(LastEffect, 128, "Camera Swapped");
}
void RandomDebug()
{
	if (DebugEnabled)
	{
		NewEffect(); //get new chaos effect because debug movement is enabled already
		return;
	}
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	EggViperHandiCapCheck();
	if (IssSowboarding == 1)//get new effect because user is on snowboard
	{
		NewEffect();
		return;
	}
	switch (CurrentCharacter)
	{
	case Characters_Sonic:
	case Characters_MetalSonic:
		playertwp[0]->mode = 87;
		break;
	case Characters_Tails:
		playertwp[0]->mode = 110;
		break;
	case Characters_Knuckles:
		playertwp[0]->mode = 57;
		break;
	case Characters_Amy:
		playertwp[0]->mode = 53;
		break;
	case Characters_Big:
		playertwp[0]->mode = 110;
		break;
	case Characters_Gamma:
		playertwp[0]->mode = 110;
		break;
	default:
		NewEffect();
		return;
	}
	Debug_Timer = 333;
	DebugEnabled = true;
	strcpy_s(LastEffect, 128, "Debug Mode Enabled");
}
void RandomXGravity()
{
	EggViperHandiCapCheck();
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	if (!GravityChangeEnabled)
	{
		NewEffect();
		return;
	}
	XGravity_Timer = 500;
	Gravity.x = (float)rand() / RAND_MAX + (-1.5);
	strcpy_s(LastEffect, 128, "Random X Gravity");
}
void RandomYGravity()
{
	EggViperHandiCapCheck();
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	if (!GravityChangeEnabled)
	{
		NewEffect();
		return;
	}
	YGravity_Timer = 500;
	Gravity.y = (float)rand() / RAND_MAX + (-1.5);
	strcpy_s(LastEffect, 128, "Random Y Gravity");
}
void RandomZGravity()
{
	EggViperHandiCapCheck();
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	if (!GravityChangeEnabled)
	{
		NewEffect();
		return;
	}
	ZGravity_Timer = 500;
	Gravity.z = (float)rand() / RAND_MAX + (-1.5);
	strcpy_s(LastEffect, 128, "Random Z Gravity");
}
void NoGravity()
{
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	if (!GravityChangeEnabled)
	{
		NewEffect();
		return;
	}
	NoGravityTimer = 400;
	Gravity.x = 0;
	Gravity.y = 0;
	Gravity.z = 0;
	strcpy_s(LastEffect, 128, "Gravity Disabled");
}
void RandomControlDisable()
{
	DisableControl_Timer = 90;
	ControlEnabled = 0;
	strcpy_s(LastEffect, 128, "Control Disabled");
}
void AndKnuckles()
{
	int Knuckles = rand() % 4;
	if (Knuckles == 0)
	{
		PlayVoice(66666);//Custom Knuckles Meme Song Clip,
		strcpy_s(LastEffect, 128, "&Knuckles");
		return;
	}
	else
	{
		NewEffect();
		return;
	}
}
void RandomSwapMusic()
{
	do {
		CurrentSong = rand() % 125;
	} while (LastSong == CurrentSong);
	LastSong = CurrentSong;
	strcpy_s(LastEffect, 128, "Random Song");
	return;
}
void ChaosPlayVoice_rng()
{
	int Voice = rand() % 2043;
	PlayVoice(Voice);
	strcpy_s(LastEffect, 128, "Random Voice");
	return;
}
void RandomDPadDownCheck()
{
	//enable dpaddown check timer
	DPadDown_Timer = 90; //90 frames?
	DpadDown = 0; //resets dpad down check, 
	strcpy_s(LastEffect, 128, "DPad Down Or Die!");
}
void RandomNoClip()
{
	EggViperHandiCapCheck();
	NoClip_Timer = 800;
	WalkThruWallsNop();
	strcpy_s(LastEffect, 128, "Walk Thru Walls Enabled");
}
void InputInvert()
{
	if (!InvertEnabled)
	{
		NewEffect();
		return;
	}
	WriteData<1>((int*)0x40F2A2, 0xC6);
	WriteData<1>((int*)0x40F2A1, 0x1);
	InputInvert_Timer = 420;
	strcpy_s(LastEffect, 128, "Input Inverted");
}
void RandomRotate()
{
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	int Rotaterand = rand() % 65535;
	RotatePlayer(0, Rotaterand);
	strcpy_s(LastEffect, 128, "Random Rotation");
}
void RingAllergy()
{
	if (!AllergicToRings)
	{
		NewEffect();
		return;
	}
	if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
	{
		NewEffect();
		return;
	}
	if (RingAllergy_Timer != 0)
	{
		NewEffect();//stops from getting ringallergy when already having it
		return; 
	}
	EggViperHandiCapCheck();
	RingCount = Rings;
	RingAllergy_Timer = 250;
	strcpy_s(LastEffect, 128, "Ring Allergy");
	return;
}
void TeleportRandomTask()
{
}
void IncreaseCutsceneSkipTime()
{
	if (EV_MainThread_ptr == 0)
	{
		NewEffect();
		return;
	}
	if (!WriteOnce) //temp.walker may not need, may remove check
	{
		WriteOnce = true;
		WriteData((int*)0x03B2C580, (int)0x01A2);
		strcpy_s(LastEffect, 128, "Long Cutscene Time");
		return;
	}
}
void RemovePowerUp()
{
	RNG = rand() % 3; //retail value
	RNG2 = rand() % 3;
	//RNG = 0; //DEBUG TESTING
	if (RNG == 0)
	{
		if (CurrentCharacter == Characters_Sonic)
		{
			if (RNG2 == 0 && CharObj2Ptrs[0]->Upgrades & Upgrades_LightShoes)
			{
				CharObj2Ptrs[0]->Upgrades &= ~Upgrades_LightShoes;
				WriteData<1>((int*)0x3B18895, 0x00);
				strcpy_s(LastEffect, 128, "Removed Light Speed Shoes");
			}
			if (RNG2 == 1 && CharObj2Ptrs[0]->Upgrades & Upgrades_CrystalRing)
			{
				CharObj2Ptrs[0]->Upgrades &= ~Upgrades_CrystalRing;
				WriteData<1>((int*)0x3B18896, 0x00);
				strcpy_s(LastEffect, 128, "Removed Crystal Ring");
			}
			if (RNG2 == 2 && CharObj2Ptrs[0]->Upgrades & Upgrades_AncientLight)
			{
				CharObj2Ptrs[0]->Upgrades &= ~Upgrades_AncientLight;
				WriteData<1>((int*)0x03B188A7, 0x00);
				strcpy_s(LastEffect, 128, "Removed Ancient Light");
			}
			else
			{
				NewEffect();
				return;
			}
		}
		if (CurrentCharacter == Characters_Tails)
		{
			if (RNG2 == 0 && CharObj2Ptrs[0]->Upgrades & Upgrades_JetAnklet)
			{
				CharObj2Ptrs[0]->Upgrades &= ~Upgrades_JetAnklet;
				WriteData<1>((int*)0x3B188D5, 0x00);
				strcpy_s(LastEffect, 128, "Removed Jet Anklet");
			}
			else
			{
				NewEffect();
				return;
			}
		}
		if (CurrentCharacter == Characters_Knuckles)
		{
			if (RNG2 == 0 && CharObj2Ptrs[0]->Upgrades & Upgrades_FightingGloves)
			{
				CharObj2Ptrs[0]->Upgrades &= ~Upgrades_FightingGloves;
				WriteData<1>((int*)0x3B18922, 0x00);
				strcpy_s(LastEffect, 128, "Removed Fighting Gloves");
			}
			if (RNG2 == 1 && CharObj2Ptrs[0]->Upgrades & Upgrades_ShovelClaw)
			{
				CharObj2Ptrs[0]->Upgrades &= ~Upgrades_ShovelClaw;
				WriteData<1>((int*)0x3B18921, 0x00);
				strcpy_s(LastEffect, 128, "Removed Shovel Claw");
			}
			else
			{
				NewEffect();
				return;
			}
		}
		if (CurrentCharacter == Characters_Big)
		{
			if (CurrentCharacter == Characters_Big && Big_Fish_Ptr != 0x00000000)
			{
				NewEffect();
				return;
			}
			if (RNG2 == 0 && CharObj2Ptrs[0]->Upgrades & Upgrades_LifeRing)
			{
				CharObj2Ptrs[0]->Upgrades &= ~Upgrades_LifeRing;
				WriteData<1>((int*)0x3B189D8, 0x00);
				strcpy_s(LastEffect, 128, "Removed Life Ring");
			}
			if (RNG2 == 1 && CharObj2Ptrs[0]->Upgrades & Upgrades_PowerRod)
			{
				CharObj2Ptrs[0]->Upgrades &= ~Upgrades_PowerRod;
				WriteData<1>((int*)0x3B189D9, 0x00);
				strcpy_s(LastEffect, 128, "Removed Power Rod");
			}
			else
			{
				NewEffect();
				return;
			}
		}
	}
	else
	{
		NewEffect();
		return;
	}
}
void RandomCollisionSize()
{
	int CSize = rand() % 10 + (2.5f);//adds 2.5f to ensure CSize is never 0/1
	playerpwp[0]->p.height = CSize;
	strcpy_s(LastEffect, 128, "Random Collision Size");
	return;
}
void CheckCameraEffects()
{
	if (DrunkCamera_Timer != 0 && CameraSpin_Timer != 0 && CameraFlip_Timer != 0 && SideWaysCamera_Timer != 0)
	{
		NewEffect();
		return;
	}
	return;
}
void FlipCamera()
{
	if (!UpsideDownCameraEnabled)
	{
		NewEffect();
		return;
	}
	CheckCameraEffects();
	CameraNOP();
	CameraFlip_Timer = 250;
	strcpy_s(LastEffect, 128, "Flipped Camera");
	return;
}
void SpinCamera()
{
	if (!SpinCameraEnabled)
	{
		NewEffect();
		return;
	}
	CheckCameraEffects();
	CameraNOP();
	strcpy_s(LastEffect, 128, "Camera Spin");
	CameraSpin_Timer = 240;
	return;
}
void DrunkCamera()
{
	if (!DrunkCameraEnabled)
	{
		NewEffect();
		return;
	}
	CheckCameraEffects();
	CameraNOP();
	strcpy_s(LastEffect, 128, "Drunk");
	DrunkCamera_Timer = 275;
	return;
}

void SideWaysCamera()
{
	if (!SideWaysCameraEnabled)
	{
		NewEffect();
		return;
	}
	CheckCameraEffects();
	CameraNOP();
	strcpy_s(LastEffect, 128, "SideWays Camera");
	CameraSide = rand() % 2;
	SideWaysCamera_Timer = 240;
	return;
}

void Set_Sonic_Ice()
{
	if (CurrentCharacter != Characters_Sonic && CurrentCharacter != Characters_Knuckles)
	{
		NewEffect();
		return;
	}
	if (!IceTextLoader)
	{
		LoadNoNamePVM(&stx_ice0_TEXLIST);
		TextLoaded = true;
	}
	DisableControl_Timer = 70;
	ControlEnabled = 0;
	ForcePlayerAction(0, 38); //forces frozen state for sonic/Knuckles
	SetSonicIce(playertwp[0]->counter.b[0]);
	strcpy_s(LastEffect, 128, "Froze Player");
}
void EmeraldShardMa()
{
	LoadPVM("Obj_ruin", &OBJ_RUIN_TEXLIST); //test for shard texture loading or not
	EmeraldShard_Create(20);
	WriteData<4>((int*)0x3C851D0, 0x00); //3C851D0 needs to be 0 to spawn more

}
void RandomKnuxRingSpring(taskwk* p1)
{
	if (!KnuxEffTextLoader)
	{
		LoadPVM("Knu_eff", &KNU_EFF_TEXLIST);
		KnuxEffTextLoader = true;
		TextLoaded = true;
	}
	task* KnuxRingSpring;
	KnuxRingSpring = (task*)LoadObject((LoadObj)2, 6, KnuEffectRingSpring);
	KnuxRingSpring->twp->pos = playertwp[0]->pos;
	strcpy_s(LastEffect, 128, "Dug Up Rings");
}