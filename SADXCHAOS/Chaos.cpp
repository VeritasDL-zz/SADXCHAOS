#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
//changelog
//started Mod 8/5/2021
//added code base from Soar's scrapped "mania" mode
//added debug print out for mods being enabled
//added random time of day
//added random dropped rings
//added random Clip level (not sure if it works)
//added randompause (not sure if it works)
//added random char
//added random camera (not sure if it works)
//added random debug (not sure if it works and i need a way to turn it off after a short period
//added random xyz gravity (havent enabled them or tested them)
//added random barrier
//added random mag barrier
//added invincibility
char oldRand = -1;
int Chaos_Timer = 0;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.
	}

	__declspec(dllexport) void __cdecl OnInitEnd()
	{
		// Executed after every mod has been initialized, mainly used to check if a specific mod is also enabled.
	}

	void RandomSpring(EntityData1* p1) {
		int number = rand() % 2;

		ObjectMaster* spring = LoadObject((LoadObj)2, 2, SpringB_Main);
		spring->Data1->Rotation = { rand() % 0x8000, rand() % 0x8000, rand() % 0x8000 };
		spring->Data1->Scale.y = rand() % 4 + 1 * 2.5;
		spring->Data1->Position = p1->Position;

		if (number)
		{
			ObjectMaster* spring2 = LoadObject((LoadObj)2, 2, SpringB_Main);
			spring2->Data1->Rotation = { rand() % 0x8000, rand() % 0x8000, rand() % 0x8000 };
			spring2->Data1->Scale.y = rand() % 5 + 10 * 2.5;
			spring2->Data1->Position = p1->Position;
			spring2->Data1->Position.y += rand() % 10 + 1 * 9;
			spring2->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		PrintDebug("Random Spring\n");
		return;
	}

	void RandomSpeedPad(EntityData1* p1) {
		int number = rand() % 2;

		ObjectMaster* speed = LoadObject((LoadObj)3, 3, DashPanel_Main);
		speed->Data1->Scale.x = rand() % 5 + 10 * 2.5;
		speed->Data1->Rotation.y = rand() % 0x8000;
		speed->Data1->Position = p1->Position;

		if (number)
		{
			ObjectMaster* speed2 = LoadObject((LoadObj)3, 3, DashPanel_Main);
			speed2->Data1->Scale.x = rand() % 5 + 10 * 2.5;
			speed2->Data1->Rotation.y = rand() % 0x8000;
			speed2->Data1->Position = p1->Position;
			speed2->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		PrintDebug("Random SpeedPad\n");
		return;
	}

	void RandomSpikeBall(EntityData1* p1) {
		int number = rand() % 2;


		ObjectMaster* spike = LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
		spike->Data1->Rotation.y = rand() % 80 + 1000;
		spike->Data1->Scale.x = rand() % 5 + 10 * 2.5;
		spike->Data1->Position = p1->Position;
		spike->Data1->Position.y += 2;
		spike->Data1->Position.x += 80;

		if (number) {
			ObjectMaster* spike2 = LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
			spike2->Data1->Rotation.y = rand() % 80 + 1000;
			spike2->Data1->Scale.x = rand() % 5 + 10 * 2.5;
			spike2->Data1->Position = p1->Position;
			spike2->Data1->Position.y += 2;
			spike2->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		PrintDebug("Random Spike Balls\n");
		return;
	}
	void RandomKillMomentum(CharObj2* p1) {
		p1->Speed = { 0, 0, 0 };
		PrintDebug("Kill Momentum\n");
		return;
	}

	void RandomVSpeed(CharObj2* p1) {
		p1->Speed.y = p1->PhysicsData.VSpeedCap;
		PrintDebug("Random VSpeed\n");
		return;
		
	}



	void RandomHSpeed(CharObj2* p1) {
		p1->Speed.x = p1->PhysicsData.HSpeedCap;
		PrintDebug("Random HSpeed\n");
		return;
	}

	void RandomHurt() {
		if (Rings > 0)
			PrintDebug("Hurt\n");
			return HurtCharacter(0);
		
	}

	void RandomPowerUP(EntityData1* P1) {

		int randomUp = rand() % 9;

		if (!randomUp)
		{
			GiveSpeedShoes(0); //fix funny crash
			PrintDebug("Give SpeedShoes?\n");
		}
		else
			ItemBoxPowerups[randomUp].Function(0);
		PrintDebug("Random PowerUp\n");

		DoThingWithItemBoxPowerupIndex(randomUp);
	}

	void MGiantScale(EntityData1* p1) {
		for (int i = 0; i < 21; i++) {
			SONIC_OBJECTS[i]->scl[0] = 4;
			SONIC_OBJECTS[i]->scl[1] = 4;
			SONIC_OBJECTS[i]->scl[2] = 4;
		}
		PrintDebug("Giant Scale\n");
		return;
	}

	void RandomTimeOfDay() //sets time of day to a random time,
	{
		SetTimeOfDay(rand() % 3);
		PrintDebug("Random Time Of Day\n");
	}

	void RandomDroppedRings(EntityData1* p1)
	{
		SpawnDroppedRings(EntityData1Ptrs[0]->Position.x, EntityData1Ptrs[0]->Position.y, EntityData1Ptrs[0]->Position.z, rand() % 254); //spawns random ammount of rings 0-255 at the player
		PrintDebug("Random Dropped Rings\n");
	}
	void RandomClipLevel()
	{
		ClipLevel = rand() % 3;
		PrintDebug("Clip Level Set To " + ClipLevel);
	}
	void RandomPause()
	{
		DisplayPauseMenu();
		PrintDebug("Random Pause\n");
	}
	void RandomChar()
	{
		SetCharacter(rand() % 7);
		PrintDebug("Random Char\n");
	}
	//DisablePause
	//Fast Pause Unpase
	//Set Debug Mode?
	//
	void RandomCamera()
	{
		FreeCam = rand() % 1;
		PrintDebug("Random Camera\n");
	}

	void RandomDebug() //debug mode need a way to turn this off after maybe  10? seconds
	{
		DebugMode = 1;
		PrintDebug("Debug Mode\n");
		
	}

	void  RandomXGravity()
	{
		Gravity.x = rand() % 5 + (-5);
		PrintDebug("Random X Gravity\n");

	}
	void  RandomYGravity()
	{
		Gravity.y = rand() % 5 + (-5);
		PrintDebug("Random Y Gravity\n");
	}
	void  RandomZGravity()
	{
		Gravity.z = rand() % 5 + (-5);
		PrintDebug("Random Z Gravity\n");
	}
	void RandomBarrier()
	{
		GiveBarrier(0);
		PrintDebug("Give Barrier\n");
	}
	void RandomMagneticBarrier()
	{
		GiveMagneticBarrier(0);
		PrintDebug("Give Magnetic Barrier\n");
	}
	void RandomInvincibility()
	{
		GiveInvincibility(0);
		PrintDebug("Give Invincibility\n");
	}

	void MSmallScale(EntityData1* p1) {
		for (int i = 0; i < 21; i++) {
			SONIC_OBJECTS[i]->scl[0] = 0.5;
			SONIC_OBJECTS[i]->scl[1] = 0.5;
			SONIC_OBJECTS[i]->scl[2] = 0.5;
		}
		PrintDebug("Small Scale\n");
		return;
	}

	void RandomSwapMusic() {

		do {
			CurrentSong = rand() % 125;
		} while (LastSong == CurrentSong);

		LastSong = CurrentSong;
		PrintDebug("Random Song\n");
		return;
	}

	void ChaosPlayVoice_rng() {
		int a1 = rand() % 2043;
		PlayVoice(a1);
		PrintDebug("Random Voice\n");
		return;
	}







	typedef void(__cdecl* ChaosEnt)(EntityData1*);
	typedef void(__cdecl* ChaosCharObj)(CharObj2*);
	typedef void(__cdecl* ChaosNull)();

	struct ChaosS {
		ChaosEnt func;
		ChaosCharObj func2;
		ChaosNull func3;
	};

	ChaosS ChaosArray[20]{

	{ RandomSpring, nullptr, nullptr, },
	{ RandomSpeedPad, nullptr, nullptr, },
	{ RandomSpikeBall, nullptr, nullptr, },
	{ RandomPowerUP, nullptr, nullptr, },
	{ RandomDroppedRings, nullptr, nullptr },
	{ nullptr, RandomKillMomentum, nullptr, },
	{ nullptr, RandomVSpeed, nullptr, },
	{ nullptr, RandomHSpeed, nullptr, },
	{ nullptr, nullptr, RandomSwapMusic },
	{ nullptr, nullptr, ChaosPlayVoice_rng},
	{ nullptr, nullptr, RandomHurt },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomClipLevel },
	{ nullptr, nullptr, RandomPause },
	{ nullptr, nullptr, RandomChar },
	{ nullptr, nullptr, RandomCamera },
	{ nullptr, nullptr, RandomBarrier },
	{ nullptr, nullptr, RandomMagneticBarrier },
	{ nullptr, nullptr, RandomInvincibility },

	};

	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SADX
		if (!CharObj2Ptrs[0] || GameState != 15 || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || CurrentLevel >= LevelIDs_SSGarden)
			return;

		if (Chaos_Timer < 50)
			Chaos_Timer++;

		if (Chaos_Timer >= 50)
		{
			char curRand = 0;

			do {
				curRand = rand() % LengthOfArray(ChaosArray);
			} while (oldRand == curRand);

			if (ChaosArray[curRand].func != nullptr)
				ChaosArray[curRand].func(EntityData1Ptrs[0]);
			else if (ChaosArray[curRand].func2 != nullptr)
				ChaosArray[curRand].func2(CharObj2Ptrs[0]);
			else
				ChaosArray[curRand].func3();

			oldRand = curRand;
			Chaos_Timer = 0;
		}
	}

	__declspec(dllexport) void __cdecl OnInput()
	{
		// Executed before the game processes input
	}

	__declspec(dllexport) void __cdecl OnControl()
	{
		// Executed when the game processes input
	}

	__declspec(dllexport) void __cdecl OnRenderDeviceReset()
	{
		// Executed when the window size changes
	}

	__declspec(dllexport) void __cdecl OnRenderDeviceLost()
	{
		// Executed when the game fails to render the scene
	}

	__declspec(dllexport) void __cdecl OnRenderSceneStart()
	{
		// Executed before the game starts rendering the scene
	}

	__declspec(dllexport) void __cdecl OnRenderSceneEnd()
	{
		// Executed when the game finishes rendering the scene
	}

	__declspec(dllexport) void __cdecl OnExit()
	{
		// Executed when the game is about to terminate
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}