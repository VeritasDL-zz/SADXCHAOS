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
void BigRock(EntityData1* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!BigRockTextLoader)
	{
		LoadPVM("OBJ_ICECAP", &OBJ_ICECAP_TEXLIST);
		BigRockTextLoader = true;
		TextLoaded = true;
	}
	task* BigRock;
	BigRock = (task*)LoadObject((LoadObj)3, 3, OBiciwa);
	BigRock->twp->pos = EntityData1Ptrs[0]->Position;
	strcpy_s(LastEffect, 128, "Spawned Big Rock");
	return;
}
void BigCar(EntityData1* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!CarTextLoader)
	{
		//LoadPVM("OBJ_ICECAP", &OBJ_ICECAP_TEXLIST);
		CarTextLoader = true;
		TextLoaded = true;
	}
	task* Car;
	Car = (task*)LoadObject((LoadObj)7, 3, ORotyu);
	Car->twp->pos = EntityData1Ptrs[0]->Position;
	strcpy_s(LastEffect, 128, "Spawned Car");
	return;
}
void RandomIceKey(EntityData1* p1) // disabled for now 9/23/2021, updated to tasks, still disabled
{
	if (!GrabAbleObjectsEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!IceTextLoader)
	{
		IceTextLoader = true;
	}
	task* IceKey;
	IceKey = (task*)LoadObject((LoadObj)3, 3, IceKey_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	IceKey->ocp = objCondition;
	IceKey->twp->pos = EntityData1Ptrs[0]->Position;
	strcpy_s(LastEffect, 128, "Random IceKey");
	return;
}
void RandomWindKey(EntityData1* p1) // disabled for now 9/23/2021, updated to tasks, still disabled
{
	if (!GrabAbleObjectsEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!WindTextLoader)
	{
		LoadPVM("HANDKEY", &RUIN01_TEXLIST);
		WindTextLoader = true;
	}
	task* WindKey;
	WindKey = (task*)LoadObject((LoadObj)3, 3, OHandKey);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	WindKey->ocp = objCondition;
	WindKey->twp->pos = EntityData1Ptrs[0]->Position;
	strcpy_s(LastEffect, 128, "Random IceKey");
	return;
} // disabled for now 9/23/2021
void RandomFruit(EntityData1* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!ChaoFruitTextLoader)
	{
		LoadPVM("AL_OBJECT", &AL_OBJECT_TEXLIST); //need to change to what ever loads the chao fruit textlist
		TextLoaded = true;
		ChaoFruitTextLoader = true;
	}
	Int FruitType = (rand() % (12 + 1 - 3)) + 3;
	LoadChaoFruit(FruitType, &EntityData1Ptrs[0]->Position, 0, nullptr, nullptr);
	strcpy_s(LastEffect, 128, "Spawned Chao Fruit");
}
void RandomHat(EntityData1* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!ChaoHatTextLoader)
	{
		ChaoMain_Constructor();
		TextLoaded = true;
		ChaoHatTextLoader = true;
	}
	if (HatNumb < 10)
	{
		int HatType = rand() % 84 + 1;//chao hat 0-84 rng,
		LoadChaoHat(HatType, &EntityData1Ptrs[0]->Position, 0, nullptr, nullptr);
		strcpy_s(LastEffect, 128, "Spawned Chao Hat");
		HatNumb++;
	}
	if (HatNumb >= 10)
	{
		Chaos_Timer = EffectMax;
		return;
	}
}
void RandomCheckPoint(EntityData1* p1)
{
	task* CheckPoint;
	CheckPoint = (task*)LoadObject((LoadObj)15, 6, CheckPoint_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	CheckPoint->ocp = objCondition;
	CheckPoint->twp->pos = EntityData1Ptrs[0]->Position;
	CheckPoint->twp->ang = PlayerTaskPtr[0]->ang;
	strcpy_s(LastEffect, 128, "Random CheckPoint");
}
void RandomSpeedPad(EntityData1* p1)
{
	int number = rand() % 2;
	task* Speed;
	Speed = (task*)LoadObject((LoadObj)3, 3, DashPanel_Main);
	Speed->twp->scl.x = rand() % 5 + 10 * 2.5;
	Speed->twp->ang.y = rand() % 0x8000;
	Speed->twp->pos = EntityData1Ptrs[0]->Position;
	if (number)
	{
		task* Speed;
		Speed = (task*)LoadObject((LoadObj)3, 3, DashPanel_Main);
		Speed->twp->scl.x = rand() % 5 + 10 * 2.5;
		Speed->twp->ang.y = rand() % 0x8000;
		Speed->twp->pos = EntityData1Ptrs[0]->Position;
	}
	strcpy_s(LastEffect, 128, "Random SpeedPad");
	return;
}
void RandomBurgerMan(EntityData1* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!BugerManTextLoader)
	{
		LoadPVM("MI_3DASU", &mi_3dasu_TEXLIST);
		BugerManTextLoader = true;
		TextLoaded = true;
	}
	task* BurgerMan;
	BurgerMan = (task*)LoadObject((LoadObj)3, 3, MissionStatue_Load);
	BurgerMan->twp->pos = EntityData1Ptrs[0]->Position;
	strcpy_s(LastEffect, 128, "Spawned BurgerMan");
	return;
}

void RandomKeyBlock(EntityData1* p1)//updated untested
{
	if (!GrabAbleObjectsEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!KeyBlockTextLoader)
	{
		LoadPVM("HOTSHELTER2", &HOTSHELTER2_TEXLIST);
		KeyBlockTextLoader = true;
		TextLoaded = true;
	}
	task* KeyBlock;
	KeyBlock = (task*)LoadObject((LoadObj)3, 3, OBoxSwitch);
	KeyBlock->twp->pos = EntityData1Ptrs[0]->Position;
	KeyBlock->twp->scl.x = rand() % 3;
	strcpy_s(LastEffect, 128, "Spawned KeyBlock");
	return;
}
void RandomSnowboard()
{
	if (DebugEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (IssSowboarding == 0)
	{
		SnowboardTimer = 500;
		IssSowboarding = 1;
		if (GameMode == GameModes_Menu || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || !GetCharacterObject(0)) //Credits to MainMemory for the Code, https://github.com/MainMemory/SADXBoardSpawner
			return;
		ObjectMaster* obj = GetCharacterObject(0);
		switch (obj->Data1->CharID)
		{
		case Characters_Sonic:
			if (obj->Data1->Action >= 62 && obj->Data1->Action <= 68)
				ForcePlayerAction(0, 24);
			else
			{
				ForcePlayerAction(0, 44);
				if (!snowboard)
					snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Sonic_Load);
			}
			break;
		case Characters_Tails:
			if (obj->Data1->Action >= 48 && obj->Data1->Action <= 54)
			{
				ForcePlayerAction(0, 24);
				// fix a bug where Tails' physics data doesn't get reset to normal
				((EntityData2*)obj->Data2)->CharacterData->PhysicsData.CollisionSize = PhysicsArray[Characters_Tails].CollisionSize;
				((EntityData2*)obj->Data2)->CharacterData->PhysicsData.YOff = PhysicsArray[Characters_Tails].YOff;
				((EntityData2*)obj->Data2)->CharacterData->PhysicsData.JumpSpeed = PhysicsArray[Characters_Tails].JumpSpeed;
			}
			else
			{
				ForcePlayerAction(0, 44);
				if (!snowboard)
					snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Tails_Load);
			}
			break;
		}
		if (!snowboard)
			switch (obj->Data1->CharID)
			{
			case Characters_Sonic:
				if (obj->Data1->Action >= 62 && obj->Data1->Action <= 68)
					snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Sonic_Load);
				break;
			case Characters_Tails:
				if (obj->Data1->Action >= 48 && obj->Data1->Action <= 54)
					snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Tails_Load);
				break;
			}//Credits to MainMemory for the Code, https://github.com/MainMemory/SADXBoardSpawner
		strcpy_s(LastEffect, 128, "Snowboard");
		return;
	}
	else
	{
		Chaos_Timer = EffectMax;//forces another Chaos mod if already on snowboard
	}
}
void RandomSpring(EntityData1* p1)
{
	int number = rand() % 2;
	task* Spring;
	Spring = (task*)LoadObject((LoadObj)2, 3, SpringB_Main);
	Spring->twp->pos = EntityData1Ptrs[0]->Position;
	Spring->twp->ang = { rand() % 0x8000, rand() % 0x8000, rand() % 0x8000 };
	Spring->twp->scl.y = rand() % 4 + 1 * 2.5;
	Spring->twp->pos.z += rand() % 10 + 1 * 9;
	Spring->twp->pos.y += rand() % 10 + 1 * 9;
	if (number)
	{
		Spring = (task*)LoadObject((LoadObj)2, 3, SpringB_Main);
		Spring->twp->pos = EntityData1Ptrs[0]->Position;
		Spring->twp->ang = { rand() % 0x8000, rand() % 0x8000, rand() % 0x8000 };
		Spring->twp->scl.y = rand() % 4 + 1 * 2.5;
		Spring->twp->pos.z += rand() % 10 + 1 * 9;
		Spring->twp->pos.y += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Spring");
	return;
}
void RandomSpikeBall(EntityData1* p1)
{
	int number = rand() % 2;
	task* spike;
	spike = (task*)LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
	spike->twp->ang.y = rand() % 80 + 1000;
	spike->twp->scl.x = rand() % 5 + 10 * 2.5;
	spike->twp->pos = EntityData1Ptrs[0]->Position;
	spike->twp->pos.y += 2;
	spike->twp->pos.x += 80;
	if (number)
	{
		task* spike;
		spike = (task*)LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
		spike->twp->ang.y = rand() % 80 + 1000;
		spike->twp->scl.x = rand() % 5 + 10 * 2.5;
		spike->twp->pos = EntityData1Ptrs[0]->Position;
		spike->twp->pos.y += 2;
		spike->twp->pos.x += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Random SpikeBall");
	return;
}
void RandomEmblem(EntityData1* p1)//updated 10/04/2021 doesnt work still lol get fucked, figured out emblem id but still doesnt work, lol
{
	if (!EmblemTextLoader)
	{
		LoadPVM("EMBLEM", &EMBLEM_TEXLIST);
		EmblemTextLoader = true;
		TextLoaded = true;
	}
	task* Emblem;
	Emblem = (task*)LoadObject((LoadObj)2, 3, Emblem_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Emblem->ocp = objCondition;
	Emblem->twp->pos = EntityData1Ptrs[0]->Position;
	Emblem->twp->pos.y += rand() % 5 + 3;
	Emblem->twp->pos.z += rand() % 100 + 1 * 9;
	Emblem->twp->ang.x = rand() % 1000;
	Emblem->twp->value.l = 129; //Emblem ID, holy jesus 
	strcpy_s(LastEffect, 128, "Random Emblem");
	return;
	////WriteData((BYTE*)0x03B2B5F6, (BYTE)0x00);//resets the emblem so it can be collected again, sonic emeraldcoast
}