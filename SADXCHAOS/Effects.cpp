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
void DisablePausee()
{
	if (!PauseDisableEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	PauseEnabled = false;
	DisablePause_Timer = 420;
	strcpy_s(LastEffect, 128, "Pause Disabled");
}
PhysicsData_t PhyData[38]  //credits to MainMemory For this data, https://github.com/MainMemory/SADXPhysicsSwapMod
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
		Chaos_Timer = EffectMax;
		return;
	}
	int Phyrand = rand() % 38;
	int OldYOffset = CharObj2Ptrs[0]->PhysicsData.YOff; //store current Y Offset
	PhysicsData tmp = (PhysicsData)PhyData[Phyrand];
	memcpy(&CharObj2Ptrs[0]->PhysicsData, &tmp, sizeof(PhysicsData));
	CharObj2Ptrs[0]->PhysicsData.YOff = OldYOffset;//restores Saved Y Offset.
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
	Camera_Data1->Action = 3; //uncouples camera from char
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
	int chaotype = rand() % 25;
	ChaoData* chaodata = new ChaoData();
	chaodata->data.Happiness = rand() % 100;
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
	chaodata->data.UnknownStat = rand() % 3266; //why not lol
	chaodata->data.UnknownLevel = rand() % 99;
	chaodata->data.IntelligenceLevel = rand() % 99;
	chaodata->data.RunnyNoseLevel = rand() % 200 - 100; //hopfully generates a number between -100 and +100
	chaodata->data.SADXAnimalBehaviors = rand() % 32767; //not sure if it works
	chaodata->data.FavoriteFruit = rand() % 7;
	chaodata->data.Texture = rand() % 16;
	chaodata->data.Garden = rand() % (6 - 4 + 1) + 4;
	chaodata->data.SADXCharacterBonds->a = rand() % 100;
	chaodata->data.SADXCharacterBonds->b = rand() % 100;
	int bodychangechance = rand() % 10;
	if (bodychangechance == 1)
	{
		int bodyrand = rand() % 3;
		chaodata->data.BodyType = (SADXBodyType)bodyrand;
	}
	int headgearchance = rand() % 10;
	if (headgearchance == 1)
	{
		chaodata->data.Headgear = rand() % 84;
	}
	int medalchance = rand() % 4;
	if (medalchance == 1)
	{
		chaodata->data.Medal = rand() % 15;
	}
	int shinychance = rand() % 4;
	if (shinychance == 1)
	{
		chaodata->data.Shiny = 1;
	}
	RandomChaooAnimal();
	chaodata->data.ArmType = (SADXAnimal)Animaltyperand;
	RandomChaooAnimal();
	chaodata->data.WingType = (SADXAnimal)Animaltyperand;
	RandomChaooAnimal();
	chaodata->data.TailType = (SADXAnimal)Animaltyperand;
	RandomChaooAnimal();
	chaodata->data.LegType = (SADXAnimal)Animaltyperand;
	RandomChaooAnimal();
	chaodata->data.EarType = (SADXAnimal)Animaltyperand;
	RandomChaooAnimal();
	chaodata->data.ForeheadType = (SADXAnimal)Animaltyperand;
	RandomChaooAnimal();
	chaodata->data.EyebrowType = (SADXAnimal)Animaltyperand;
	RandomChaooAnimal();
	chaodata->data.UnknownType = (SADXAnimal)Animaltyperand; //why not lol
	chaodata->data.MouthType = rand() % 15;
	chaodata->data.EyeType = rand() % 13;
	chaodata->data.BallType = rand() % 3;
	chaodata->data.Alignment = rand() % 2 - 1; //test
	ObjectMaster* Chao = CreateChao(chaodata, 0, 0, &EntityData1Ptrs[0]->Position, 0);
	//chaodata->data.Type = (ChaoType)chaotype; idk why this wasnt working disabled for now,
	chaodata->data.Color = rand() % 15;
	chaodata->data.BodyTypeAnimal = 127;
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
	chaodata->data.UnknownGrade = rand() % 5;
	strcpy_s(LastEffect, 128, "Spawned Random Chao");
}
void RandomKillMomentum(CharObj2* p1)
{
	p1->Speed = { 0, 0, 0 };
	strcpy_s(LastEffect, 128, "Killed Momentum");
	return;
}
void FastAccel(CharObj2* p1)
{
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	if (CurrentCharacter == Characters_Big && FishingRod_ptr != 0x00000000)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	FastAccel_Timer = 400;
	CharObj2Ptrs[0]->PhysicsData.MaxAccel = 10.0f;
	CharObj2Ptrs[0]->PhysicsData.AirAccel = 0.10f;
	CharObj2Ptrs[0]->PhysicsData.HangTime = 120;
	strcpy_s(LastEffect, 128, "Fast Accel Enabled");
	return;
}
void RandomVSpeed(CharObj2* p1)
{
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	if (CurrentCharacter == Characters_Big && FishingRod_ptr != 0x00000000)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	p1->Speed.y = p1->PhysicsData.VSpeedCap;
	strcpy_s(LastEffect, 128, "Random V Speed");
	return;
}
void RandomHSpeed(CharObj2* p1)
{
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	if (CurrentCharacter == Characters_Big && FishingRod_ptr != 0x00000000)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	p1->Speed.x = p1->PhysicsData.HSpeedCap;
	strcpy_s(LastEffect, 128, "Random H Speed");
	return;
}
void RandomHurt()
{
	if (CurrentCharacter == Characters_Big && FishingRod_ptr != 0x00000000)
	{
		Chaos_Timer = EffectMax;
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
		Chaos_Timer = EffectMax;
		return;
	}

}
void RandomPowerUP(EntityData1* p1)
{
	int id = 0;
	if (id < 0 || id > 8) //failsafe
		id = rand() % 9;
	DoThingWithItemBoxPowerupIndex(id);
	strcpy_s(LastEffect, 128, "Random PowerUp");
}
void MGiantScale(EntityData1* p1)
{
	for (int i = 0; i < 21; i++) {
		SONIC_OBJECTS[i]->scl[0] = 4;
		SONIC_OBJECTS[i]->scl[1] = 4;
		SONIC_OBJECTS[i]->scl[2] = 4;
	}
	return;
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
		Chaos_Timer = EffectMax;//forces another Chaos mod if not in Adventure 
	}
}
void RandomDroppedRings(EntityData1* p1)
{
	int randomrings = rand() % 254;
	SpawnDroppedRings(EntityData1Ptrs[0]->Position.x, EntityData1Ptrs[0]->Position.y, EntityData1Ptrs[0]->Position.z, randomrings); //spawns random ammount of rings 0-255 at the player
	Rings = 0;
	strcpy_s(LastEffect, 128, "Dropped Rings");
}
void RandomClipLevel()//currently disabled, may be removed
{
	ClipLevel = rand() % 3;
}
void RandomPause() //randomly pauses the game LOL get good
{
	if (!RPauseEnabled)
	{
		Chaos_Timer = EffectMax;
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
	else if (GetCameraMode_() == 1) //new code
	{
		SetCameraMode_(0);
	}
	strcpy_s(LastEffect, 128, "Camera Swapped");
}
void RandomDebug() //debug mode currently lasts for 75ish? frames
{
	if (DebugEnabled)
	{
		Chaos_Timer = EffectMax; //get new chaos effect because debug movement is enabled already
		return;
	}
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	if (IssSowboarding == 1)//get new effect because user is on snowboard
	{
		Chaos_Timer = EffectMax;
		return;
	}
	switch (CurrentCharacter)
	{
	case Characters_Sonic:
	case Characters_MetalSonic:
		EntityData1Ptrs[0]->Action = 87;
		break;
	case Characters_Knuckles:
		EntityData1Ptrs[0]->Action = 57;
		break;
	case Characters_Amy:
		EntityData1Ptrs[0]->Action = 53;
		break;
	default:
		Chaos_Timer = EffectMax;
		return;
	}
	Debug_Timer = 333;
	DebugEnabled = true;
	strcpy_s(LastEffect, 128, "Debug Mode Enabled");
}
void RandomXGravity()//Updated 11/06/2021, Enabled For Now
{
	/*if (XGravity_Timer == 0)
	{
		XGravity = Gravity.x;
	}*/
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	if (CurrentCharacter == Characters_Big && FishingRod_ptr != 0x00000000)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!GravityChangeEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	XGravity_Timer = 1000;
	Gravity.x = (float)rand() / RAND_MAX + (-1.5);
	strcpy_s(LastEffect, 128, "Random X Gravity");
}
void RandomYGravity()
{
	/*if (YGravity_Timer == 0)
	{
		YGravity = Gravity.y;
	}*/
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	if (CurrentCharacter == Characters_Big && FishingRod_ptr != 0x00000000)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!GravityChangeEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	YGravity_Timer = 1000;
	Gravity.y = (float)rand() / RAND_MAX + (-1.5);
	strcpy_s(LastEffect, 128, "Random Y Gravity");
}
void RandomZGravity()//Updated 11/06/2021, Enabled For Now
{
	/*if (ZGravity_Timer == 0)
	{
		ZGravity = Gravity.z;
	}*/
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	if (CurrentCharacter == Characters_Big && FishingRod_ptr != 0x00000000)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!GravityChangeEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	ZGravity_Timer = 1000;
	Gravity.z = (float)rand() / RAND_MAX + (-1.5);
	strcpy_s(LastEffect, 128, "Random Z Gravity");
	//PrintDebug("Random Z Gravity\n");
}
void NoGravity()
{
	if (CurrentCharacter == Characters_Big && FishingRod_ptr != 0x00000000)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!GravityChangeEnabled)
	{
		Chaos_Timer = EffectMax;
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
void MSmallScale(EntityData1* p1)//disabled this
{
	for (int i = 0; i < 21; i++) {
		SONIC_OBJECTS[i]->scl[0] = 0.5;
		SONIC_OBJECTS[i]->scl[1] = 0.5;
		SONIC_OBJECTS[i]->scl[2] = 0.5;
	}
	strcpy_s(LastEffect, 128, "Small Scale");
	return;
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
		Chaos_Timer = EffectMax;
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
	strcpy_s(LastEffect, 128, "Dpad Down Or Die");
}
void RandomNoClip()
{
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	NoClip_Timer = 800;
	WriteData((int*)0x00444C1D, (int)0x90909090);
	WriteData((int*)0x00444C21, (int)0x10C48390);
	WriteData((int*)0x0044A66B, (int)0x90909090);
	WriteData((int*)0x0044A66F, (int)0x14C48390);
	WriteData((int*)0x007887D9, (int)0x90909090);
	WriteData((int*)0x007887DD, (int)0x74C08590);
	strcpy_s(LastEffect, 128, "Walk Thru Walls Enabled");
}
void InputInvert()
{
	if (!InvertEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	WriteData<1>((int*)0x40F2A2, 0xC6);
	WriteData<1>((int*)0x40F2A1, 0x1);
	InputInvert_Timer = 420;
	strcpy_s(LastEffect, 128, "Input Inverted");
}
void RandomRotate()
{
	int Rotaterand = rand() % 65535;
	RotatePlayer(0, Rotaterand);
	strcpy_s(LastEffect, 128, "Random Rotation");
}
void RingAllergy()
{

	if (!AllergicToRings)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				Chaos_Timer = EffectMax;
				return;
			}
		}
	}
	RingCount = Rings;
	RingAllergy_Timer = 500;
	strcpy_s(LastEffect, 128, "Ring Allergy");
}
void TeleportRandomTask()
{
	//CustomObjectArray[1023]

}