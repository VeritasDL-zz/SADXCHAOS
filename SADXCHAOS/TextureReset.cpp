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
bool SpinnerTextLoader = false;
bool LeonTextLoader = false;
bool RinoTextLoader = false;
bool KikiTextLoader = false;
bool SmanTextLoader = false;
bool EGachaTextLoader = false;
bool PoliceTextLoader = false;
bool SnakeTextLoader = false;
bool RoboTextLoader = false;
bool BuyonTextLoader = false;
bool AmebotTextLoader = false;
bool FSBTextLoader = false;
bool BugerManTextLoader = false;
bool FanTextLoader = false;
bool UnidusTextLoader = false;
bool AnimalTextLoader = false;
bool KeyBlockTextLoader = false;
bool ChaooManagerLoader = false;
bool EmblemTextLoader = false;
bool IceTextLoader = false;
bool WindTextLoader = false;
bool ChaoFruitTextLoader = false;
bool ChaoHatTextLoader = false;
bool BigRockTextLoader = false;
bool CarTextLoader = false;
bool AirCraftTextLoader = false;
bool FireBreathTextLoader = false;
bool CannonS1TextLoader = false;
bool CannonS2TextLoader = false;
bool KnuxEffTextLoader = false;
bool BarrelTextLoader = false;
bool TextLoaded = false;
bool WriteOnce = false;
int FruitNumb = 0;
int HatNumb = 0;
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
	AirCraftTextLoader = false;
	FireBreathTextLoader = false;
	CannonS1TextLoader = false;
	CannonS2TextLoader = false;
	KnuxEffTextLoader = false;
	IceTextLoader = false;
	BarrelTextLoader = false;
	WriteOnce = false;
	HatNumb = 0;
	FruitNumb = 0;
	burgerManSpawned = 0;
	AirCraftSpawerFollow_Timer = 0;
	FreeChaoTexlists();
}