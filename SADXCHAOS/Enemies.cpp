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
#define LengthOfArray(x) \
	((int)(((sizeof(x) / sizeof(x[0]))) / \
	(size_t)(!(sizeof(x) % sizeof(x[0])))))
void RandomTank(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!RinoTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("E_SAI", &E_SAI_TEXLIST);
		RinoTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* RhinoTank;
	RhinoTank = (task*)LoadObject((LoadObj)2, 3, RhinoTank_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	RhinoTank->ocp = objCondition;
	RhinoTank->twp->pos = EntityData1Ptrs[0]->Position;
	RhinoTank->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		RhinoTank = (task*)LoadObject((LoadObj)2, 3, RhinoTank_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		RhinoTank->ocp = objCondition;
		RhinoTank->twp->pos = EntityData1Ptrs[0]->Position;
		RhinoTank->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned RhinoTank");
	return;
}
void RandomBuyon(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!BuyonTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("E_BUYON", &E_BUYON_TEXLIST);
		BuyonTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Buyon;
	Buyon = (task*)LoadObject((LoadObj)2, 3, EBuyon);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Buyon->ocp = objCondition;
	Buyon->twp->pos = EntityData1Ptrs[0]->Position;
	Buyon->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Buyon = (task*)LoadObject((LoadObj)2, 3, EBuyon);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Buyon->ocp = objCondition;
		Buyon->twp->pos = EntityData1Ptrs[0]->Position;
		Buyon->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Buyon");
	return;
}
void RandomUnidus(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!UnidusTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("UNI_A_UNIBODY", &UNI_A_UNIBODY_TEXLIST);
		LoadPVM("UNI_C_UNIBODY", &UNI_C_UNIBODY_TEXLIST);
		LoadPVM("TOGEBALL_TOGEBALL", &TOGEBALL_TOGEBALL_TEXLIST);
		UnidusTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Unidus;
	Unidus = (task*)LoadObject((LoadObj)2, 3, UnidusA_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Unidus->ocp = objCondition;
	Unidus->twp->pos = EntityData1Ptrs[0]->Position;
	Unidus->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Unidus = (task*)LoadObject((LoadObj)2, 3, UnidusA_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Unidus->ocp = objCondition;
		Unidus->twp->pos = EntityData1Ptrs[0]->Position;
		Unidus->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Unidus");
	return;
}
void RandomAmebot(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!AmebotTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("E_AMENBO", &E_AMENBO_TEXLIST);
		AmebotTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Amebot;
	Amebot = (task*)LoadObject((LoadObj)2, 3, Sweep_Load);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Amebot->ocp = objCondition;
	Amebot->twp->pos = EntityData1Ptrs[0]->Position;
	Amebot->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Amebot = (task*)LoadObject((LoadObj)2, 3, Sweep_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Amebot->ocp = objCondition;
		Amebot->twp->pos = EntityData1Ptrs[0]->Position;
		Amebot->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Amebot");
	return;
}
void RandomPolice(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!PoliceTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("NISEPAT", &NISEPAT_TEXLIST);
		PoliceTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* CopSpeeder;
	CopSpeeder = (task*)LoadObject((LoadObj)2, 3, EPolice);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	CopSpeeder->ocp = objCondition;
	CopSpeeder->twp->pos = EntityData1Ptrs[0]->Position;
	CopSpeeder->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		CopSpeeder = (task*)LoadObject((LoadObj)2, 3, EPolice);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		CopSpeeder->ocp = objCondition;
		CopSpeeder->twp->pos = EntityData1Ptrs[0]->Position;
		CopSpeeder->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned The Police");
	return;
}
void RandomSnake(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!SnakeTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("E_SNAKE", &E_SNAKE_TEXLIST);
		SnakeTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Snake;
	Snake = (task*)LoadObject((LoadObj)2, 3, BoaBoa_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Snake->ocp = objCondition;
	Snake->twp->pos = EntityData1Ptrs[0]->Position;
	Snake->twp->pos.z += rand() % 90 + 1 * 9;
	if (number)
	{
		Snake = (task*)LoadObject((LoadObj)2, 3, BoaBoa_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Snake->ocp = objCondition;
		Snake->twp->pos = EntityData1Ptrs[0]->Position;
		Snake->twp->pos.z += rand() % 90 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Boa-Boa");
	return;
}
void RandomRobo(EntityData1* p1)//updated to task, untested 10/04/2021
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!RoboTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("E_ROBO", &E_ROBO_TEXLIST);
		SnakeTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Robo;
	Robo = (task*)LoadObject((LoadObj)2, 3, ERobo_0);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Robo->ocp = objCondition;
	Robo->twp->pos = EntityData1Ptrs[0]->Position;
	Robo->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Robo = (task*)LoadObject((LoadObj)2, 3, ERobo_0);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Robo->ocp = objCondition;
		Robo->twp->pos = EntityData1Ptrs[0]->Position;
		Robo->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Robo");
	return;
}
void RandomLeon(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!LeonTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("E_LEON", &E_LEON_TEXLIST);
		LeonTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Leon;
	Leon = (task*)LoadObject((LoadObj)2, 3, Leon_Load);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Leon->ocp = objCondition;
	Leon->twp->pos = EntityData1Ptrs[0]->Position;
	Leon->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Leon = (task*)LoadObject((LoadObj)2, 3, Leon_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Leon->ocp = objCondition;
		Leon->twp->pos = EntityData1Ptrs[0]->Position;
		Leon->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Leon");
	return;
}
void RandomKiki(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!KikiTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("E_SARU", &E_SARU_TEXLIST);
		LoadPVM("E_BOMB", &E_BOMB_TEXLIST);
		KikiTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Kiki;
	Kiki = (task*)LoadObject((LoadObj)2, 3, Kiki_Load);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Kiki->ocp = objCondition;
	Kiki->twp->pos = EntityData1Ptrs[0]->Position;
	Kiki->twp->pos.z += rand() % 10 + 1 * 9;
	Kiki->twp->pos.y += rand() % 2 + 1 * 9;
	if (number)
	{
		Kiki = (task*)LoadObject((LoadObj)2, 3, Kiki_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Kiki->ocp = objCondition;
		Kiki->twp->pos = EntityData1Ptrs[0]->Position;
		Kiki->twp->pos.z += rand() % 10 + 1 * 9;
		Kiki->twp->pos.y += rand() % 2 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Kiki");
	return;
}
void RandomFallingSpikeBall(EntityData1* p1)
{
	if (!FSBTextLoader)
	{
		LoadPVM("TOGEBALL_TOGEBALL", &TOGEBALL_TOGEBALL_TEXLIST);
		FSBTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* FallingSpikeBall;
	FallingSpikeBall = (task*)LoadObject((LoadObj)2, 3, FallingSpikeBall_Load);
	FallingSpikeBall->twp->pos = EntityData1Ptrs[0]->Position;
	FallingSpikeBall->twp->pos.z += rand() % 30 + 1 * 9;
	FallingSpikeBall->twp->scl.z = 60;
	FallingSpikeBall->twp->scl.x = 60;
	FallingSpikeBall->twp->scl.y = 1;
	if (number)
	{
		FallingSpikeBall = (task*)LoadObject((LoadObj)2, 3, FallingSpikeBall_Load);
		FallingSpikeBall->twp->pos = EntityData1Ptrs[0]->Position;
		FallingSpikeBall->twp->pos.y += rand() % 30 + 1 * 9;
		FallingSpikeBall->twp->pos.z += rand() % 30 + 1 * 9;
		FallingSpikeBall->twp->scl.z = 60;
		FallingSpikeBall->twp->scl.x = 60;
		FallingSpikeBall->twp->scl.y = 1;
	}
	strcpy_s(LastEffect, 128, "Falling SpikeBall");
	return;
}
void RandomSpinnerA(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!SpinnerTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* SpinnerA;
	SpinnerA = (task*)LoadObject((LoadObj)2, 3, SpinnerA_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	SpinnerA->ocp = objCondition;
	SpinnerA->twp->pos = EntityData1Ptrs[0]->Position;
	SpinnerA->twp->pos.z += rand() % 10 + 1 * 9;
	SpinnerA->twp->pos.y += rand() % 2 + 1 * 9;
	if (number)
	{
		SpinnerA = (task*)LoadObject((LoadObj)2, 3, SpinnerA_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerA->ocp = objCondition;
		SpinnerA->twp->pos = EntityData1Ptrs[0]->Position;
		SpinnerA->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerA->twp->pos.y += rand() % 2 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Spinner A");
	return;
}
void RandomSpinnerB(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!SpinnerTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* SpinnerB;
	SpinnerB = (task*)LoadObject((LoadObj)2, 3, SpinnerB_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	SpinnerB->ocp = objCondition;
	SpinnerB->twp->pos = EntityData1Ptrs[0]->Position;
	SpinnerB->twp->pos.z += rand() % 10 + 1 * 9;
	SpinnerB->twp->pos.y += rand() % 2 + 1 * 9;
	if (number)
	{
		SpinnerB = (task*)LoadObject((LoadObj)2, 3, SpinnerB_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerB->ocp = objCondition;
		SpinnerB->twp->pos = EntityData1Ptrs[0]->Position;
		SpinnerB->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerB->twp->pos.y += rand() % 2 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Spinner B");
	return;
}
void RandomSpinnerC(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!SpinnerTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* SpinnerC;
	SpinnerC = (task*)LoadObject((LoadObj)2, 3, SpinnerC_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	SpinnerC->ocp = objCondition;
	SpinnerC->twp->pos = EntityData1Ptrs[0]->Position;
	SpinnerC->twp->pos.z += rand() % 10 + 1 * 9;
	SpinnerC->twp->pos.y += rand() % 2 + 1 * 9;
	if (number)
	{
		SpinnerC = (task*)LoadObject((LoadObj)2, 3, SpinnerC_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerC->ocp = objCondition;
		SpinnerC->twp->pos = EntityData1Ptrs[0]->Position;
		SpinnerC->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerC->twp->pos.y += rand() % 2 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Spinner C");
	return;
}
void RandomSman(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (CurrentCharacter == Characters_Gamma)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!SmanTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("E_SNOWMAN", &E_SNOWMAN_TEXLIST);
		LoadNoNamePVM(&stx_ice0_TEXLIST);
		SmanTextLoader = true;
		TextLoaded = true;
	}
	task* ESMAN;
	ESMAN = (task*)LoadObject((LoadObj)2, 3, ESman);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	ESMAN->ocp = objCondition;
	ESMAN->twp->pos = EntityData1Ptrs[0]->Position;
	ESMAN->twp->pos.z += rand() % 10 + 1 * 9;
	ESMAN->twp->pos.y += rand() % 2 + 1 * 9;
	strcpy_s(LastEffect, 128, "Spawned IceBall");
}
void RandomEGacha(EntityData1* p1)
{
	if (!EnemysEnabled)
	{
		Chaos_Timer = EffectMax;
		return;
	}
	if (!EGachaTextLoader)
	{
		if (!AnimalTextLoader)
		{
			for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
				LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
			}
			AnimalTextLoader = true;
		}
		LoadPVM("GACHAPON", &GACHAPON_TEXLIST);
		EGachaTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* GACHAPON;
	GACHAPON = (task*)LoadObject((LoadObj)2, 3, OEGacha);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	GACHAPON->ocp = objCondition;
	GACHAPON->twp->pos = EntityData1Ptrs[0]->Position;
	GACHAPON->twp->pos.z += rand() % 10 + 1 * 9;
	GACHAPON->twp->pos.y += rand() % 10 + 1 * 9;
	if (number)
	{
		GACHAPON = (task*)LoadObject((LoadObj)2, 3, OEGacha);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		GACHAPON->ocp = objCondition;
		GACHAPON->twp->pos = EntityData1Ptrs[0]->Position;
		GACHAPON->twp->pos.z += rand() % 30 + 1 * 9;
		GACHAPON->twp->pos.y += rand() % 30 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Beat");
	return;
}