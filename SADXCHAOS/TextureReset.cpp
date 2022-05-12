#include "pch.h"
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
bool BurgerSpinTextLoader = false;
bool ConveyorTextLoader = false;
bool CartTextLoader = false;
bool WaterPillerTextLoader = false;
bool AsciiTextLoader = false;
bool FountainTextLoader = false;
bool TargetTextLoader = false;
bool GravityTextLoader = false;
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
	ConveyorTextLoader = false;
	CartTextLoader = false;
	WaterPillerTextLoader = false;
	FountainTextLoader = false;
	AsciiTextLoader = false;
	TargetTextLoader = false;
	GravityTextLoader = false;
	WriteOnce = false;
	HatNumb = 0;
	FruitNumb = 0;
	if (BurgerSpinTextLoader && burgerManSpawned != 0)
	{
		deleteRotaryEmeraldTask();
		burgerManSpawned = 0;
	}
	BurgerSpinTextLoader = false;
	deleteRotaryEmeraldTask();
	EV_FreeObject(&BURGER1);
	EV_FreeObject(&BURGER2);
	EV_FreeObject(&BURGER3);
	EV_FreeObject(&BURGER4);
	EV_FreeObject(&BURGER5);
	EV_FreeObject(&BURGER6);
	EV_FreeObject(&BURGER7);
	AirCraftSpawerFollow_Timer = 0;
	g_RotaryEmerald_p = 0;
	burgerManSpawned = 0;
	FreeChaoTexlists();
	if (PanelNopped)
	{
		PanelRestore();
	}

	WriteData((int*)0x5B56D2, (int)0xE5FE69E8); //target_man_exec_nop LoadLevelResults Reset Nopped ASM 
	WriteData((int*)0x5B56D6, (int)0x43E857FF); //target_man_exec_nop LoadLevelResults Reset Nopped ASM 
}