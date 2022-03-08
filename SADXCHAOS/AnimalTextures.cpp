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
PVMEntry MinimalPVMs[]{
{ "GOMA", &GOMA_TEXLIST },
{ "PEN", &PEN_TEXLIST },
{ "RAKO", &RAKO_TEXLIST },
{ "KUJA", &KUJA_TEXLIST },
{ "TUBA", &TUBA_TEXLIST },
{ "OUM", &OUM_TEXLIST },
{ "BANB", &BANB_TEXLIST },
{ "USA", &USA_TEXLIST },
{ "WARA", &WARA_TEXLIST },
{ "GORI", &GORI_TEXLIST },
{ "LION", &LION_TEXLIST },
{ "ZOU", &ZOU_TEXLIST },
{ "MOGU", &MOGU_TEXLIST },
{ "KOAR", &KOAR_TEXLIST },
{ "SUKA", &SUKA_TEXLIST },
};

void CheckAnimalTexture()
{
	if (!AnimalTextLoader)
	{
		for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
			LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
		}
		AnimalTextLoader = true;
		return;
	}
	else
	{
		return;
	}
}