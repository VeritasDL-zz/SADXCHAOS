#include "pch.h"
#include <cmath>
uint32_t IlDuce = (0x0000000000183A88+0x00000000000C1F44+0x00000000000C2544-0x00000000002461CC);
bool GrabAbleObjects()
{
	if (!GrabAbleObjectsEnabled)
	{
		NewEffect();
		return false;
	}
	return true;
}
bool EggViperHandiCapCheck()
{
	if (EggViperHandyCapEanbled)
	{
		if (CurrentLevel == LevelIDs_EggViper)
		{
			int EVHandyCap = rand() % 5;
			if (EVHandyCap != 0)
			{
				NewEffect();
				return true;
			}
		}
	}
	return false;
}
void BigRock(taskwk* p1)
{
	if (!GrabAbleObjects())
	{
		return;
	}
	if (!BigRockTextLoader)
	{
		LoadPVM("OBJ_ICECAP", &OBJ_ICECAP_TEXLIST);
		BigRockTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_ICECAP_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Big Rock");
		task* BigRock;
		BigRock = (task*)LoadObject((LoadObj)3, 3, OBiciwa);
		BigRock->twp->pos = playertwp[0]->pos;
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomFruit(taskwk* p1)
{
	if (!GrabAbleObjects())
	{
		return;
	}
	if (!ChaoFruitTextLoader)
	{
		LoadPVM("AL_OBJECT", &AL_OBJECT_TEXLIST);
		TextLoaded = true;
		ChaoFruitTextLoader = true;
	}
	if (AL_OBJECT_TEXLIST.textures->texaddr)
	{
		if (FruitNumb < 10)
		{
			Int FruitType = (rand() % (12 + 1 - 3)) + 3;
			strcpy_s(LastEffect, 128, "Spawned Chao Fruit");
			LoadChaoFruit(FruitType, &playertwp[0]->pos, 0, nullptr, nullptr);
			FruitNumb++;
		}
		if (FruitNumb >= 10)
		{
			NewEffect();
			return;
		}
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomHat(taskwk* p1)
{
	if (!GrabAbleObjects())
	{
		return;
	}
	if (!ChaoHatTextLoader)
	{
		LoadPVM("AL_OBJECT", &AL_OBJECT_TEXLIST);
		ChaoMain_Constructor();
		TextLoaded = true;
		ChaoHatTextLoader = true;
	}
	if (AL_OBJECT_TEXLIST.textures->texaddr)
	{
		if (HatNumb < 10)
		{
			int HatType = rand() % 80 + 1;//chao hat 0-84 rng, idk changed it to 0-81 for now (4/21/2022)
			strcpy_s(LastEffect, 128, "Spawned Chao Hat");
			LoadChaoHat(HatType, &playertwp[0]->pos, 0, nullptr, nullptr);
			HatNumb++;
		}
		if (HatNumb >= 10)
		{
			NewEffect();
			return;
		}
	}
	else
	{
		NewEffect();
		return;
	}
}
void RandomCheckPoint(taskwk* p1)
{
	if (CurrentLevel == LevelIDs_Chaos4)
	{
		NewEffect();
		return;
	}
	strcpy_s(LastEffect, 128, "Random CheckPoint");
	task* CheckPoint;
	CheckPoint = (task*)LoadObject((LoadObj)15, 6, CheckPoint_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	CheckPoint->ocp = objCondition;
	CheckPoint->twp->pos = playertwp[0]->pos;
	CheckPoint->twp->ang = playertwp[0]->ang;
}
void RandomSpeedPad(taskwk* p1)
{
	if (EggViperHandiCapCheck())
	{
		return;
	}
	strcpy_s(LastEffect, 128, "Random SpeedPad");
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
	return;
}
void RandomFan(taskwk* p1)
{
	if (CurrentLevel == LevelIDs_Chaos4)
	{
		NewEffect();
		return;
	}
	if (!FanTextLoader)
	{
		LoadPVM("OBJ_FINALEGG", &OBJ_FINALEGG_TEXLIST); 
		FanTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_FINALEGG_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Random Fan");
		task* Fan;
		Fan = (task*)LoadObject((LoadObj)2, 4, OFun);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Fan->ocp = objCondition;
		Fan->twp->pos = playertwp[0]->pos;
		Fan->twp->pos.y = playertwp[0]->pos.y - 9.0f;
		//float CustomFanAcc = (float(rand()) / float((RAND_MAX)) * 0.99);
		//WriteData((float*)0x1AC4854, CustomFanAcc);
	}
	else
	{
		NewEffect();
		return;
	}
}
void RandomBurgerMan(taskwk* p1)
{
	if (!GrabAbleObjects())
	{
		return;
	}
	if (!BugerManTextLoader)
	{
		LoadPVM("SS_PEOPLE", ADV00_TEXLISTS[6]);
		BugerManTextLoader = true;
		TextLoaded = true;
	}
	strcpy_s(LastEffect, 128, "Spawned BurgerMan");
	task* BurgerMan;
	BurgerMan = (task*)LoadObject((LoadObj)3, 3, BurgerShopStatue_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	BurgerMan->ocp = objCondition;
	BurgerMan->twp->pos = playertwp[0]->pos;
	return;
}
void RandomKeyBlock(taskwk* p1)
{
	if (!GrabAbleObjects())
	{
		return;
	}
	if (!KeyBlockTextLoader)
	{
		LoadPVM("HOTSHELTER2", &HOTSHELTER2_TEXLIST);
		KeyBlockTextLoader = true;
		TextLoaded = true;
	}
	if (HOTSHELTER2_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned KeyBlock");
		task* KeyBlock;
		KeyBlock = (task*)LoadObject((LoadObj)3, 3, OBoxSwitch);
		KeyBlock->twp->pos = playertwp[0]->pos;
		KeyBlock->twp->scl.x = rand() % 3;
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomSnowboard()
{
	if (CurrentCharacter != Characters_Sonic && CurrentCharacter != Characters_Tails)
	{
		NewEffect();
		return;
	}
	if (EggViperHandiCapCheck())
	{
		return;
	}
	if (DebugEnabled)
	{
		NewEffect();
		return;
	}
	if (PerfectChaosCheck())
	{
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
	if (EggViperHandiCapCheck())
	{
		return;
	}
	int number = rand() % 2;
	strcpy_s(LastEffect, 128, "Spawned Spring");
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
	return;
}
void RandomSpikeBall(taskwk* p1)
{
	if (EggViperHandiCapCheck())
	{
		return;
	}
	int number = rand() % 2;
	strcpy_s(LastEffect, 128, "Random SpikeBall");
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
	return;
}
void RandomEmblem(taskwk* p1)
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
	if (EMBLEM_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Random Emblem");
		task* Emblem;
		Emblem = (task*)LoadObject((LoadObj)2, 3, Emblem_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Emblem->ocp = objCondition;
		Emblem->twp->pos = playertwp[0]->pos;
		Emblem->twp->pos.y += rand() % 5 + 3;
		Emblem->twp->pos.z += rand() % 100 + 1 * 9;
		Emblem->twp->ang.x = rand() % 500 * 1.6969f; //speed it rotates at
		Emblem->twp->value.l = 129; //Emblem ID, holy jesus 
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomBarrel(taskwk* p1)
{
	if (!BarrelTextLoader)
	{
		LoadPVM("Obj_twinkle", &OBJ_TWINKLE_TEXLIST);
		BarrelTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_TWINKLE_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Random Barrel");
		task* Barrel;
		Barrel = (task*)LoadObject((LoadObj)3, 3, OBarrel);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Barrel->ocp = objCondition;
		Barrel->twp->pos = playertwp[0]->pos;
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomConveyorBelt(taskwk* p1)
{
	if (!ConveyorTextLoader)
	{
		LoadPVM("Obj_finalegg", &OBJ_FINALEGG_TEXLIST);
		ConveyorTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_FINALEGG_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Random Conveyor Belt");
		task* Conveyor;
		Conveyor = (task*)LoadObject((LoadObj)6, 3, OConv_belt);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Conveyor->ocp = objCondition;
		Conveyor->twp->pos = playertwp[0]->pos;
		Conveyor->twp->pos.y = playertwp[0]->pos.y - 1;
		Conveyor->twp->scl.z = (float(rand()) / float((RAND_MAX)) * 1.3);
		Conveyor->twp->ang = playertwp[0]->ang;
		Conveyor->twp->ang.x = rand() % 119 + (-59);
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomConveyorStop(taskwk* p1)
{
	if (!ConveyorTextLoader)
	{
		LoadPVM("Obj_finalegg", &OBJ_FINALEGG_TEXLIST);
		ConveyorTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_FINALEGG_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Spike");
		task* ConveyorStop;
		ConveyorStop = (task*)LoadObject((LoadObj)3, 3, OConv_stop);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		ConveyorStop->ocp = objCondition;
		ConveyorStop->twp->pos = playertwp[0]->pos;
		ConveyorStop->twp->pos.x =+ playertwp[0]->pos.x + 69;
		ConveyorStop->twp->pos.z =+ playertwp[0]->pos.z + 69;
		ConveyorStop->twp->pos.y =- playertwp[0]->pos.y - 30;
		double gradientZ = (ConveyorStop->twp->pos.z - playertwp[0]->pos.z);
		double gradientX = (ConveyorStop->twp->pos.x - playertwp[0]->pos.x);
		double angle = round((M_PI / 2 - atan2(gradientZ, gradientX)) * 10430.378);
		if (playertwp[0]->pos.z < ConveyorStop->twp->pos.z)
			angle += 32768;
		ConveyorStop->twp->ang.y = angle;
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomFountain(taskwk* p1)
{
	if (!FountainTextLoader)
	{
		LoadPVM("OBJ_HIGHWAY2", &OBJ_HIGHWAY2_TEXLIST);
		FountainTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_HIGHWAY2_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Random Fountain");
		task* Fountain;
		Fountain = (task*)LoadObject((LoadObj)10, 3, OFount);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Fountain->ocp = objCondition;
		Fountain->twp->pos = playertwp[0]->pos;
		Fountain->twp->pos.y = playertwp[0]->pos.y - 9.0f;
		return;
	}
	else //new effect 
	{
		NewEffect();
		return;
	}
}
void RandomTarget(taskwk* p1)
{
	if (!TargetTextLoader)
	{
		LoadPVM("Obj_finalegg", &OBJ_FINALEGG_TEXLIST);
		TargetTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_FINALEGG_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Random Sonic Target");
		task* Target;
		Target = (task*)LoadObject((LoadObj)2, 3, OTarget);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Target->ocp = objCondition;
		Target->twp->pos = playertwp[0]->pos;
		Target->twp->pos.y = playertwp[0]->pos.y - 9.0f;
		Target->twp->scl.x = rand() % 200; //Distance Target Moves Back and Forth
		if (CurrentCharacter != Characters_Gamma && CurrentLevel != LevelIDs_FinalEgg)
		{
			WriteData<5>((int*)0x5B56D2, 0x90);//target_man_exec_nop LoadLevelResults NOP
		}
		return;
	}
	else //new effect 
	{
		NewEffect();
		return;
	}
}
void RandomPopUpTarget(taskwk* p1)
{
	if (!TargetTextLoader)
	{
		LoadPVM("Obj_finalegg", &OBJ_FINALEGG_TEXLIST);
		TargetTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_FINALEGG_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Random Target");
		task* Target;
		Target = (task*)LoadObject((LoadObj)2, 3, OUpTarget1);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Target->ocp = objCondition;
		Target->twp->pos = playertwp[0]->pos;
		Target->twp->pos.y = playertwp[0]->pos.y - 8.0f;
		Target->twp->scl.y = 0; //0 = random, 1 = sonic, 2 = knux, 3 = tails
		return;
	}
	else //new effect 
	{
		NewEffect();
		return;
	}
}