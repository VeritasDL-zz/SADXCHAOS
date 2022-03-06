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
void RandomTank(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (!RinoTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_SAI", &E_SAI_TEXLIST);
		RinoTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* RhinoTank;
	RhinoTank = (task*)LoadObject((LoadObj)2, 3, RhinoTank_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	RhinoTank->ocp = objCondition;
	RhinoTank->twp->pos = playertwp[0]->pos;
	RhinoTank->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		RhinoTank = (task*)LoadObject((LoadObj)2, 3, RhinoTank_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		RhinoTank->ocp = objCondition;
		RhinoTank->twp->pos = playertwp[0]->pos;
		RhinoTank->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned RhinoTank");
	return;
}
void RandomBuyon(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!BuyonTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_BUYON", &E_BUYON_TEXLIST);
		BuyonTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Buyon;
	Buyon = (task*)LoadObject((LoadObj)2, 3, EBuyon);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Buyon->ocp = objCondition;
	Buyon->twp->pos = playertwp[0]->pos;
	Buyon->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Buyon = (task*)LoadObject((LoadObj)2, 3, EBuyon);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Buyon->ocp = objCondition;
		Buyon->twp->pos = playertwp[0]->pos;
		Buyon->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Buyon");
	return;
}
void RandomUnidus(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!UnidusTextLoader)
	{
		CheckAnimalTexture();
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
	Unidus->twp->pos = playertwp[0]->pos;
	Unidus->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Unidus = (task*)LoadObject((LoadObj)2, 3, UnidusA_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Unidus->ocp = objCondition;
		Unidus->twp->pos = playertwp[0]->pos;
		Unidus->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Unidus");
	return;
}
void RandomAmebot(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!AmebotTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_AMENBO", &E_AMENBO_TEXLIST);
		AmebotTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Amebot;
	Amebot = (task*)LoadObject((LoadObj)2, 3, Sweep_Load);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Amebot->ocp = objCondition;
	Amebot->twp->pos = playertwp[0]->pos;
	Amebot->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Amebot = (task*)LoadObject((LoadObj)2, 3, Sweep_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Amebot->ocp = objCondition;
		Amebot->twp->pos = playertwp[0]->pos;
		Amebot->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Amebot");
	return;
}
void RandomPolice(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!PoliceTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("NISEPAT", &NISEPAT_TEXLIST);
		PoliceTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* CopSpeeder;
	CopSpeeder = (task*)LoadObject((LoadObj)2, 3, EPolice);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	CopSpeeder->ocp = objCondition;
	CopSpeeder->twp->pos = playertwp[0]->pos;
	CopSpeeder->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		CopSpeeder = (task*)LoadObject((LoadObj)2, 3, EPolice);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		CopSpeeder->ocp = objCondition;
		CopSpeeder->twp->pos = playertwp[0]->pos;
		CopSpeeder->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned The Police");
	return;
}
void RandomSnake(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!SnakeTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_SNAKE", &E_SNAKE_TEXLIST);
		SnakeTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Snake;
	Snake = (task*)LoadObject((LoadObj)2, 3, BoaBoa_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Snake->ocp = objCondition;
	Snake->twp->pos = playertwp[0]->pos;
	Snake->twp->pos.z += rand() % 90 + 1 * 9;
	if (number)
	{
		Snake = (task*)LoadObject((LoadObj)2, 3, BoaBoa_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Snake->ocp = objCondition;
		Snake->twp->pos = playertwp[0]->pos;
		Snake->twp->pos.z += rand() % 90 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Boa-Boa");
	return;
}
void RandomRobo(taskwk* p1)//updated to task, untested 10/04/2021
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (!RoboTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_ROBO", &E_ROBO_TEXLIST);
		SnakeTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Robo;
	Robo = (task*)LoadObject((LoadObj)2, 3, ERobo_0);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Robo->ocp = objCondition;
	Robo->twp->pos = playertwp[0]->pos;
	Robo->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Robo = (task*)LoadObject((LoadObj)2, 3, ERobo_0);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Robo->ocp = objCondition;
		Robo->twp->pos = playertwp[0]->pos;
		Robo->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Robo");
	return;
}
void RandomLeon(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!LeonTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_LEON", &E_LEON_TEXLIST);
		LeonTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* Leon;
	Leon = (task*)LoadObject((LoadObj)2, 3, Leon_Load);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	Leon->ocp = objCondition;
	Leon->twp->pos = playertwp[0]->pos;
	Leon->twp->pos.z += rand() % 10 + 1 * 9;
	if (number)
	{
		Leon = (task*)LoadObject((LoadObj)2, 3, Leon_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Leon->ocp = objCondition;
		Leon->twp->pos = playertwp[0]->pos;
		Leon->twp->pos.z += rand() % 10 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Leon");
	return;
}
void RandomKiki(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!KikiTextLoader)
	{
		CheckAnimalTexture();
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
	Kiki->twp->pos = playertwp[0]->pos;
	Kiki->twp->pos.z += rand() % 10 + 1 * 9;
	Kiki->twp->pos.y += rand() % 2 + 1 * 9;
	if (number)
	{
		Kiki = (task*)LoadObject((LoadObj)2, 3, Kiki_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Kiki->ocp = objCondition;
		Kiki->twp->pos = playertwp[0]->pos;
		Kiki->twp->pos.z += rand() % 10 + 1 * 9;
		Kiki->twp->pos.y += rand() % 2 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Kiki");
	return;
}
void RandomFallingSpikeBall(taskwk* p1)
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
	FallingSpikeBall->twp->pos = playertwp[0]->pos;
	FallingSpikeBall->twp->pos.z += rand() % 30 + 1 * 9;
	FallingSpikeBall->twp->scl.z = 60;
	FallingSpikeBall->twp->scl.x = 60;
	FallingSpikeBall->twp->scl.y = 1;
	if (number)
	{
		FallingSpikeBall = (task*)LoadObject((LoadObj)2, 3, FallingSpikeBall_Load);
		FallingSpikeBall->twp->pos = playertwp[0]->pos;
		FallingSpikeBall->twp->pos.y += rand() % 30 + 1 * 9;
		FallingSpikeBall->twp->pos.z += rand() % 30 + 1 * 9;
		FallingSpikeBall->twp->scl.z = 60;
		FallingSpikeBall->twp->scl.x = 60;
		FallingSpikeBall->twp->scl.y = 1;
	}
	strcpy_s(LastEffect, 128, "Falling SpikeBall");
	return;
}
void RandomSpinnerA(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!SpinnerTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* SpinnerA;
	SpinnerA = (task*)LoadObject((LoadObj)2, 3, SpinnerA_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	SpinnerA->ocp = objCondition;
	SpinnerA->twp->pos = playertwp[0]->pos;
	SpinnerA->twp->pos.z += rand() % 10 + 1 * 9;
	SpinnerA->twp->pos.y += rand() % 2 + 1 * 9;
	if (number)
	{
		SpinnerA = (task*)LoadObject((LoadObj)2, 3, SpinnerA_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerA->ocp = objCondition;
		SpinnerA->twp->pos = playertwp[0]->pos;
		SpinnerA->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerA->twp->pos.y += rand() % 2 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Spinner A");
	return;
}
void RandomSpinnerB(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!SpinnerTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	int number = rand() % 2;
	task* SpinnerB;
	SpinnerB = (task*)LoadObject((LoadObj)2, 3, SpinnerB_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	SpinnerB->ocp = objCondition;
	SpinnerB->twp->pos = playertwp[0]->pos;
	SpinnerB->twp->pos.z += rand() % 10 + 1 * 9;
	SpinnerB->twp->pos.y += rand() % 2 + 1 * 9;
	if (number)
	{
		SpinnerB = (task*)LoadObject((LoadObj)2, 3, SpinnerB_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerB->ocp = objCondition;
		SpinnerB->twp->pos = playertwp[0]->pos;
		SpinnerB->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerB->twp->pos.y += rand() % 2 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Spinner B");
	return;
}
void RandomSpinnerC(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!SpinnerTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* SpinnerC;
	SpinnerC = (task*)LoadObject((LoadObj)2, 3, SpinnerC_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	SpinnerC->ocp = objCondition;
	SpinnerC->twp->pos = playertwp[0]->pos;
	SpinnerC->twp->pos.z += rand() % 10 + 1 * 9;
	SpinnerC->twp->pos.y += rand() % 2 + 1 * 9;
	if (number)
	{
		SpinnerC = (task*)LoadObject((LoadObj)2, 3, SpinnerC_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerC->ocp = objCondition;
		SpinnerC->twp->pos = playertwp[0]->pos;
		SpinnerC->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerC->twp->pos.y += rand() % 2 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Spinner C");
	return;
}
void RandomSman(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (CurrentCharacter == Characters_Gamma)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_EggViper)
	{
		NewEffect();
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
	ESMAN->twp->pos = playertwp[0]->pos;
	ESMAN->twp->pos.z += rand() % 10 + 1 * 9;
	ESMAN->twp->pos.y += rand() % 2 + 1 * 9;
	strcpy_s(LastEffect, 128, "Spawned IceBall");
}
void RandomEGacha(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return;
	}
	if (!EGachaTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("GACHAPON", &GACHAPON_TEXLIST);
		EGachaTextLoader = true;
		TextLoaded = true;
	}
	int number = rand() % 2;
	task* GACHAPON;
	GACHAPON = (task*)LoadObject((LoadObj)2, 3, OEGacha);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	GACHAPON->ocp = objCondition;
	GACHAPON->twp->pos = playertwp[0]->pos;
	GACHAPON->twp->pos.z += rand() % 10 + 1 * 9;
	GACHAPON->twp->pos.y += rand() % 10 + 1 * 9;
	if (number)
	{
		GACHAPON = (task*)LoadObject((LoadObj)2, 3, OEGacha);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		GACHAPON->ocp = objCondition;
		GACHAPON->twp->pos = playertwp[0]->pos;
		GACHAPON->twp->pos.z += rand() % 35 + 1 * 9;
		GACHAPON->twp->pos.y += rand() % 30 + 1 * 9;
	}
	strcpy_s(LastEffect, 128, "Spawned Beat");
	return;
}
void RandomAirCraft(taskwk* p1) //if you use this please give me credits as this took 5 days to figure out. 
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_EggViper)
	{
		NewEffect();
		return;
	}
	if (!AirCraftTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_AIRCRAFT", &E_AIRCRAFT_TEXLIST);
		LoadPVM("Air_signal", &AIR_SIGNAL_TEXLIST);
		LoadPVM("OBJ_SKYDECK", &OBJ_SKYDECK_TEXLIST);
		AirCraftTextLoader = true;
		TextLoaded = true;
	}
	task* AirCraft;
	AirCraft = (task*)LoadObject((LoadObj)2, 3, EnemyAir);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	AirCraft->ocp = objCondition;
	AirCraft->twp->pos = playertwp[0]->pos;
	AirCraft->twp->pos.z += rand() % 10 + 1 * 9;
	AirCraft->twp->pos.y += rand() % 10 + 15 * 9;
	AirCraft->twp->mode = 2;
	int number = rand() % 2;
	if (number)
	{
		AirCraft = (task*)LoadObject((LoadObj)2, 3, EnemyAir);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		AirCraft->ocp = objCondition;
		AirCraft->twp->pos = playertwp[0]->pos;
		AirCraft->twp->pos.z += rand() % 10 + 10 * 9;
		AirCraft->twp->pos.y += rand() % 11 + 20 * 9;
		AirCraft->twp->mode = 2;
	}
	if (AirCraftSpawerFollow_Timer == 0)
	{
		AirCraftSpawerFollow_Timer = 350;
	}
	strcpy_s(LastEffect, 128, "Spawned AirCraft");
}
void RandomFireBreath(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_EggViper)
	{
		NewEffect();
		return;
	}
	if (!FireBreathTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("OBJ_MOUNTAIN", &OBJ_MOUNTAIN_TEXLIST);
		FireBreathTextLoader = true;
		TextLoaded = true;
	}
	task* FireBreath;
	FireBreath = (task*)LoadObject((LoadObj)6, 3, O_honoo_Main);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	FireBreath->ocp = objCondition;
	FireBreath->twp->pos = playertwp[0]->pos;
	FireBreath->twp->pos.x = playertwp[0]->pos.x - 10;
	FireBreath->twp->ang = playertwp[0]->ang;
	strcpy_s(LastEffect, 128, "Spawned FireBreath");
}
void RandomCannonS1(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_EggViper)
	{
		NewEffect();
		return;
	}
	if (!CannonS1TextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("OBJ_SKYDECK", &OBJ_SKYDECK_TEXLIST);
		CannonS1TextLoader = true;
		TextLoaded = true;
	}
	task* CannonS1;
	CannonS1 = (task*)LoadObject((LoadObj)6, 3, Cannon_s1);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	CannonS1->ocp = objCondition;
	CannonS1->twp->pos = playertwp[0]->pos;
	CannonS1->twp->pos.x = playertwp[0]->pos.x - 10;
	CannonS1->twp->ang = playertwp[0]->ang;
	strcpy_s(LastEffect, 128, "Spawned Cannon");
}
void RandomCannonS2(taskwk* p1)
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return;
	}
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return;
	}
	if (CurrentLevel == LevelIDs_EggViper)
	{
		NewEffect();
		return;
	}
	if (!CannonS2TextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("OBJ_SKYDECK", &OBJ_SKYDECK_TEXLIST);
		CannonS2TextLoader = true;
		TextLoaded = true;
	}
	task* CannonS2;
	CannonS2 = (task*)LoadObject((LoadObj)6, 3, Cannon_s2);
	OBJ_CONDITION* objCondition = new OBJ_CONDITION();
	CannonS2->ocp = objCondition;
	CannonS2->twp->pos = playertwp[0]->pos;
	CannonS2->twp->pos.x = playertwp[0]->pos.x - 10;
	CannonS2->twp->ang = playertwp[0]->ang;
	strcpy_s(LastEffect, 128, "Spawned Cannon");
}
