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
void ResetTextureBools()
{
	SpinnerTextLoader = false;
	LeonTextLoader = false;
	KikiTextLoader = false;
	RinoTextLoader = false;
	SmanTextLoader = false;
	EGachaTextLoader = false;
	PoliceTextLoader = false;
	SnakeTextLoader = false;
	RoboTextLoader = false;
	BuyonTextLoader = false;
	AmebotTextLoader = false;
	FSBTextLoader = false;
	BugerManTextLoader = false;
	UnidusTextLoader = false;
	AnimalTextLoader = false;
	ChaooManagerLoader = false;
	KeyBlockTextLoader = false;
	EmblemTextLoader = false;
	IceTextLoader = false;
	WindTextLoader = false;
	TextLoaded = false;
	DebugEnabled = false;
	ChaoFruitTextLoader = false;
	ChaoHatTextLoader = false;
	BigRockTextLoader = false;
	CarTextLoader = false;
	FanTextLoader = false;
	WriteOnce = false;
	HatNumb = -1;
}