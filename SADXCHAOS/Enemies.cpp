#include "pch.h"
#define LengthOfArray(x) \
	((int)(((sizeof(x) / sizeof(x[0]))) / \
	(size_t)(!(sizeof(x) % sizeof(x[0])))))
bool EnemyCheck()
{
	if (!EnemysEnabled)
	{
		NewEffect();
		return false;
	}
	return true;
}
bool E101RCheck()
{
	if (CurrentLevel == LevelIDs_E101R)
	{
		NewEffect();
		return true;
	}
	return false;
}
bool AdventureCheck()
{
	if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
	{
		NewEffect();
		return true;
	}
	return false;
}
bool GammaCheck()
{
	if (CurrentCharacter == Characters_Gamma)
	{
		NewEffect();
		return true;
	}
	return false;
}
bool EggViperCheck()
{
	if (CurrentLevel == LevelIDs_EggViper)
	{
		NewEffect();
		return true;
	}
	return false;
}
void RandomTank(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (!RinoTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_SAI", &E_SAI_TEXLIST);
		RinoTextLoader = true;
		TextLoaded = true;
	}
	if (E_SAI_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned RhinoTank");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomBuyon(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (!BuyonTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_BUYON", &E_BUYON_TEXLIST);
		BuyonTextLoader = true;
		TextLoaded = true;
	}
	if (E_BUYON_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Buyon");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomUnidus(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
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
	if (UNI_A_UNIBODY_TEXLIST.textures->texaddr && UNI_C_UNIBODY_TEXLIST.textures->texaddr && TOGEBALL_TOGEBALL_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Unidus");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomAmebot(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (!AmebotTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_AMENBO", &E_AMENBO_TEXLIST);
		AmebotTextLoader = true;
		TextLoaded = true;
	}
	if (E_AMENBO_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Amebot");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomPolice(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (!PoliceTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("NISEPAT", &NISEPAT_TEXLIST);
		PoliceTextLoader = true;
		TextLoaded = true;
	}
	if (NISEPAT_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Police Dispatched.");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomSnake(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (!SnakeTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_SNAKE", &E_SNAKE_TEXLIST);
		SnakeTextLoader = true;
		TextLoaded = true;
	}
	if (E_SNAKE_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Snake");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomRobo(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (!RoboTextLoader)
	{
		CheckAnimalTexture();
		//LoadPVM("OBJ_FEgg", &OBJ_FINALEGG_TEXLIST);
		LoadPVM("E_ROBO", &E_ROBO_TEXLIST);
		RoboTextLoader = true;
		TextLoaded = true;
	}
	if (E_ROBO_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Robo");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomLeon(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (!LeonTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_LEON", &E_LEON_TEXLIST);
		LeonTextLoader = true;
		TextLoaded = true;
	}
	if (E_LEON_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Leon");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomKiki(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
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
	if (E_SARU_TEXLIST.textures->texaddr && E_BOMB_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Kiki");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomFallingSpikeBall(taskwk* p1)
{
	if (!FallingSpikeBallEnabled)
	{
		NewEffect();
		return;
	}
	if (!FSBTextLoader)
	{
		LoadPVM("TOGEBALL_TOGEBALL", &TOGEBALL_TOGEBALL_TEXLIST);
		FSBTextLoader = true;
		TextLoaded = true;
	}
	if (TOGEBALL_TOGEBALL_TEXLIST.textures->texaddr)
	{
		int number = rand() % 2;
		task* FallingSpikeBall;
		strcpy_s(LastEffect, 128, "Falling SpikeBall");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomSpinnerA(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (!SpinnerTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	if (SUPI_SUPI_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Spinner A");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomSpinnerB(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (!SpinnerTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	if (SUPI_SUPI_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Spinner B");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomSpinnerC(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (!SpinnerTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
		SpinnerTextLoader = true;
		TextLoaded = true;
	}
	if (SUPI_SUPI_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Spinner C");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomSman(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (GammaCheck())
	{
		return;
	}
	if (EggViperCheck())
	{
		return;
	}
	if (!SmanTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("E_SNOWMAN", &E_SNOWMAN_TEXLIST);
		LoadNoNamePVM(&stx_ice0_TEXLIST);
		SmanTextLoader = true;
		TextLoaded = true;
	}
	if (E_SNOWMAN_TEXLIST.textures->texaddr && stx_ice0_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned IceBall");
		task* ESMAN;
		ESMAN = (task*)LoadObject((LoadObj)2, 3, ESman);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		ESMAN->ocp = objCondition;
		ESMAN->twp->pos = playertwp[0]->pos;
		ESMAN->twp->pos.z += rand() % 10 + 1 * 9;
		ESMAN->twp->pos.y += rand() % 2 + 1 * 9;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomEGacha(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (E101RCheck())
	{
		return;
	}
	if (!EGachaTextLoader)
	{
		CheckAnimalTexture();
		//LoadPVM("OBJ_FEgg", &OBJ_FINALEGG_TEXLIST); //disabled on 4/7/2022 
		LoadPVM("GACHAPON", &GACHAPON_TEXLIST);
		EGachaTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_FINALEGG_TEXLIST.textures->texaddr && GACHAPON_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Beat");
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
		return;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomAirCraft(taskwk* p1) //if you use this please give me credits as this took 5 days to figure out. 
{
	if (!EnemyCheck())
	{
		return;
	}
	if (EggViperCheck())
	{
		return;
	}
	if (BigFishingCheck())
	{
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
	if (E_AIRCRAFT_TEXLIST.textures->texaddr && AIR_SIGNAL_TEXLIST.textures->texaddr && OBJ_SKYDECK_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned AirCraft");
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
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomFireBreath(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (EggViperCheck())
	{
		return;
	}
	if (BigFishingCheck())
	{
		return;
	}
	if (!FireBreathTextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("OBJ_MOUNTAIN", &OBJ_MOUNTAIN_TEXLIST);
		FireBreathTextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_MOUNTAIN_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned FireBreath");
		task* FireBreath;
		FireBreath = (task*)LoadObject((LoadObj)6, 3, O_honoo_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		FireBreath->ocp = objCondition;
		FireBreath->twp->pos = playertwp[0]->pos;
		PlaceX = FireBreath->twp->pos.x + (rand() % 30);
		PlaceZ = FireBreath->twp->pos.z + (rand() % 30);
		PosOffset = rand() % 10 + (59); //59-69?
		PlaceInFront();
		FireBreath->twp->pos.x = PlaceX;
		FireBreath->twp->pos.z = PlaceZ;
		FaceX = FireBreath->twp->pos.x - playertwp[0]->pos.x;
		FaceZ = FireBreath->twp->pos.z - playertwp[0]->pos.z;
		FacePlayer();
		FireBreath->twp->ang.y = FaceAng;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomCannonS1(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (EggViperCheck())
	{
		return;
	}
	if (BigFishingCheck())
	{
		return;
	}
	if (!CannonS1TextLoader && !CannonS2TextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("OBJ_SKYDECK", &OBJ_SKYDECK_TEXLIST);
		CannonS1TextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_SKYDECK_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Cannon");
		task* CannonS1;
		CannonS1 = (task*)LoadObject((LoadObj)6, 3, Cannon_s1);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		CannonS1->ocp = objCondition;
		CannonS1->twp->pos = playertwp[0]->pos;
		CannonS1->twp->pos.x = playertwp[0]->pos.x - 10;
		PlaceX = CannonS1->twp->pos.x;
		PlaceZ = CannonS1->twp->pos.z;
		PosOffset = rand() % 10 + (59); //59-69?
		PlaceInFront();
		CannonS1->twp->pos.x = PlaceX;
		CannonS1->twp->pos.z = PlaceZ;
		FaceX = CannonS1->twp->pos.x - playertwp[0]->pos.x;
		FaceZ = CannonS1->twp->pos.z - playertwp[0]->pos.z;
		FacePlayer();
		CannonS1->twp->ang.y = FaceAng;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}
void RandomCannonS2(taskwk* p1)
{
	if (!EnemyCheck())
	{
		return;
	}
	if (AdventureCheck())
	{
		return;
	}
	if (EggViperCheck())
	{
		return;
	}
	if (BigFishingCheck())
	{
		return;
	}
	if (!CannonS2TextLoader && !CannonS1TextLoader)
	{
		CheckAnimalTexture();
		LoadPVM("OBJ_SKYDECK", &OBJ_SKYDECK_TEXLIST);
		CannonS2TextLoader = true;
		TextLoaded = true;
	}
	if (OBJ_SKYDECK_TEXLIST.textures->texaddr)
	{
		strcpy_s(LastEffect, 128, "Spawned Cannon");
		task* CannonS2;
		CannonS2 = (task*)LoadObject((LoadObj)6, 3, Cannon_s2);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		CannonS2->ocp = objCondition;
		CannonS2->twp->pos = playertwp[0]->pos;
		PlaceX = CannonS2->twp->pos.x;
		PlaceZ = CannonS2->twp->pos.z;
		PosOffset = rand() % 10 + (59); //59-69?
		PlaceInFront();
		CannonS2->twp->pos.x = PlaceX;
		CannonS2->twp->pos.z = PlaceZ;
		CannonS2->twp->ang = playertwp[0]->ang;
		FaceX = CannonS2->twp->pos.x - playertwp[0]->pos.x;
		FaceZ = CannonS2->twp->pos.z - playertwp[0]->pos.z;
		FacePlayer();
		CannonS2->twp->ang.y = FaceAng;
	}
	else //new effect dueo texlist not being loaded
	{
		NewEffect();
		return;
	}
}