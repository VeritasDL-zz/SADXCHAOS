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