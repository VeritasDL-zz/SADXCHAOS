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
void BigRock(taskwk* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
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
	BigRock->twp->pos = playertwp[0]->pos;
	strcpy_s(LastEffect, 128, "Spawned Big Rock");
	return;
}
void BigCar(taskwk* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
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
	Car->twp->pos = playertwp[0]->pos;
	strcpy_s(LastEffect, 128, "Spawned Car");
	return;
}
void RandomIceKey(taskwk* p1) // disabled for now 9/23/2021, updated to tasks, still disabled
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
		return;
	}
	if (!IceTextLoader)
	{
		//LoadPVM("HOTSHELTER2", &HOTSHELTER2_TEXLIST);
		IceTextLoader = true;
	}
	task* IceKey;
	IceKey = (task*)LoadObject((LoadObj)3, 3, IceKey_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	IceKey->ocp = objCondition;
	IceKey->twp->pos = playertwp[0]->pos;
	strcpy_s(LastEffect, 128, "Random IceKey");
	return;
}
void RandomWindKey(taskwk* p1) // disabled for now 9/23/2021, updated to tasks, still disabled
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
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
	WindKey->twp->pos = playertwp[0]->pos;
	strcpy_s(LastEffect, 128, "Random WindKey");
	return;
} // disabled for now 9/23/2021
void RandomFruit(taskwk* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
		return;
	}
	if (!ChaoFruitTextLoader)
	{
		LoadPVM("AL_OBJECT", &AL_OBJECT_TEXLIST);
		TextLoaded = true;
		ChaoFruitTextLoader = true;
	}
	if (FruitNumb < 10)
	{
		Int FruitType = (rand() % (12 + 1 - 3)) + 3;
		LoadChaoFruit(FruitType, &playertwp[0]->pos, 0, nullptr, nullptr);
		strcpy_s(LastEffect, 128, "Spawned Chao Fruit");
		FruitNumb++;
	}
	if (FruitNumb >= 10)
	{
		NewEffect();
		return;
	}
}
void RandomHat(taskwk* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
		return;
	}
	if (!ChaoHatTextLoader)
	{
		LoadPVM("AL_OBJECT", &AL_OBJECT_TEXLIST);
		ChaoMain_Constructor();
		TextLoaded = true;
		ChaoHatTextLoader = true;
	}
	if (HatNumb < 10)
	{
		int HatType = rand() % 84 + 1;//chao hat 0-84 rng,
		LoadChaoHat(HatType, &playertwp[0]->pos, 0, nullptr, nullptr);
		strcpy_s(LastEffect, 128, "Spawned Chao Hat");
		HatNumb++;
	}
	if (HatNumb >= 10)
	{
		NewEffect();
		return;
	}
}
void RandomCheckPoint(taskwk* p1)
{
	task* CheckPoint;
	CheckPoint = (task*)LoadObject((LoadObj)15, 6, CheckPoint_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	CheckPoint->ocp = objCondition;
	CheckPoint->twp->pos = playertwp[0]->pos;
	CheckPoint->twp->ang = PlayerTaskPtr[0]->ang;
	strcpy_s(LastEffect, 128, "Random CheckPoint");
}
void RandomSpeedPad(taskwk* p1)
{
	if (EggViperHandyCapEanbled)
	{
		int EVHandyCap = rand() % 5;
		if (CurrentLevel == LevelIDs_EggViper)
		{
			if (EVHandyCap != 0)
			{
				NewEffect();
				return;
			}
		}
	}
	int number = rand() % 2;
	task* Speed;
	Speed = (task*)LoadObject((LoadObj)3, 3, DashPanel_Main);
	Speed->twp->scl.x = rand() % 5 + 10 * 2.5;
	Speed->twp->ang.y = rand() % 0x8000;
	Speed->twp->pos = playertwp[0]->pos;
	if (number)
	{
		task* Speed;
		Speed = (task*)LoadObject((LoadObj)3, 3, DashPanel_Main);
		Speed->twp->scl.x = rand() % 5 + 10 * 2.5;
		Speed->twp->ang.y = rand() % 0x8000;
		Speed->twp->pos = playertwp[0]->pos;
	}
	strcpy_s(LastEffect, 128, "Random SpeedPad");
	return;
}
void RandomFan(taskwk* p1)
{
	//need to figure out fan power?
	if (!FanTextLoader)
	{
		LoadPVM("OBJ_FINALEGG", &OBJ_FINALEGG_TEXLIST); 
		FanTextLoader = true;
		TextLoaded = true;
	}
	task* Fan;
	Fan = (task*)LoadObject((LoadObj)2, 4, OFun);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Fan->ocp = objCondition;
	Fan->twp->pos = playertwp[0]->pos;
	Fan->twp->pos.y = playertwp[0]->pos.y - 9.0f;
	//Fan->twp->ang = PlayerTaskPtr[0]->ang;
	strcpy_s(LastEffect, 128, "Random Fan");
}
void RandomBurgerMan(taskwk* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
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
	BurgerMan->twp->pos = playertwp[0]->pos;
	strcpy_s(LastEffect, 128, "Spawned BurgerMan");
	return;
}
void RandomKeyBlock(taskwk* p1)
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
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
	KeyBlock->twp->pos = playertwp[0]->pos;
	KeyBlock->twp->scl.x = rand() % 3;
	strcpy_s(LastEffect, 128, "Spawned KeyBlock");
	return;
}
void RandomSnowboard()
{
	if (CurrentCharacter != Characters_Sonic && CurrentCharacter != Characters_Tails)
	{
		NewEffect();
		return;
	}
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
	if (DebugEnabled)
	{
		NewEffect();
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
		NewEffect();//forces another Chaos mod if already on snowboard
		return;
	}
}
void RandomSpring(taskwk* p1)
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
	int number = rand() % 2;
	task* Spring;
	Spring = (task*)LoadObject((LoadObj)2, 3, SpringB_Main);
	Spring->twp->pos = playertwp[0]->pos;
	Spring->twp->ang = { rand() % 0x8000, rand() % 0x8000, rand() % 0x8000 };
	Spring->twp->scl.y = rand() % 4 + 1 * 2.5;
	Spring->twp->pos.z += rand() % 10 + 1 * 9;
	Spring->twp->pos.y += rand() % 10 + 1 * 9;
	if (number)
	{
		Spring = (task*)LoadObject((LoadObj)2, 3, SpringB_Main);
		Spring->twp->pos = playertwp[0]->pos;
		Spring->twp->ang = { rand() % 0x8000, rand() % 0x8000, rand() % 0x8000 };
		Spring->twp->scl.y = rand() % 4 + 1 * 2.5;
		Spring->twp->pos.z += rand() % 10 + 1 * 9;
		Spring->twp->pos.y += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Spring");
	return;
}
void RandomSpikeBall(taskwk* p1)
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
	int number = rand() % 2;
	task* spike;
	spike = (task*)LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
	spike->twp->ang.y = rand() % 80 + 1000;
	spike->twp->scl.x = rand() % 5 + 10 * 2.5;
	spike->twp->pos = playertwp[0]->pos;
	spike->twp->pos.y += 2;
	spike->twp->pos.x += 80;
	if (number)
	{
		task* spike;
		spike = (task*)LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
		spike->twp->ang.y = rand() % 80 + 1000;
		spike->twp->scl.x = rand() % 5 + 10 * 2.5;
		spike->twp->pos = playertwp[0]->pos;
		spike->twp->pos.y += 2;
		spike->twp->pos.x += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Random SpikeBall");
	return;
}
void RandomEmblem(taskwk* p1)//UPDATED (3/1/2022) IT WORKS
{
	if (!RandomEmblemEnabled)
	{
		NewEffect();
		return;
	}
	CHAR FIELDEMBLEM = *(CHAR*)0x03B2B5F6;
	FIELDEMBLEM &= ~(1 << 6);
	WriteData((CHAR*)0x03B2B5F6, (CHAR)FIELDEMBLEM);
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
	Emblem->twp->pos = playertwp[0]->pos;
	Emblem->twp->pos.y += rand() % 5 + 3;
	Emblem->twp->pos.z += rand() % 100 + 1 * 9;
	Emblem->twp->ang.x = rand() % 500 * 1.6969f; //speed it rotates at
	Emblem->twp->value.l = 129; //Emblem ID, holy jesus 
	strcpy_s(LastEffect, 128, "Random Emblem");
	return;
	
}