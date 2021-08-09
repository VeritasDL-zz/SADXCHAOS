#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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
//added random debug
//random powerup was crashing due to bomb power up? havent fixed
//sometimes the other give powerup codes i have kill the player depending on the state? 
//fixed random power up crash, by taking soras random power up code form sadxvschat
//updated random pause to make you unpause a few times, (currently 10 frames) idk how i would make it pause, unpause, automaticly cuz setting gamestate in ONFrame just makes it happen so fast you dont even see it, 
//removed set scale
//removed my own random powerups, (still in code, just unused)
//made debug last a set amount of frames (75 currently) and force the player out of debug movement.
//added press Dpad Down or die
//changed random camera to Swap Camera lol
//added random control disable 
//added Random Y Gravity
//added Random NoClip
//fixed Random NoClip Crash?
//made debug mode work again
//made debug mod last longer might make shorter
//fixed Camera Swap Code
//made Control Disable look better
//made Control Disable last longer? might shorten
//fixed random Gavity values maybe?



char oldRand = -1;
int Chaos_Timer = 0;
int Debug_Timer = 0;
int Pause_Timer = 0;
int DPadDown_Timer = 0;
int DpadDown = 0;
int DisableControl_Timer = 0;
int Gravity_Timer = 0;
int NoClip = 0;
int NoClip_Timer = 0;
int ClipTest = 0;
int bstimer = 0;
int fuckt = 0;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.

		srand((unsigned)time(nullptr));
	}

	void RandomSpring(EntityData1* p1) 
	{
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

	void RandomSpeedPad(EntityData1* p1) 
	{
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
	void RandomSpikeBall(EntityData1* p1) 
	{
		int number = rand() % 2;


		ObjectMaster* spike = LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
		spike->Data1->Rotation.y = rand() % 80 + 1000;
		spike->Data1->Scale.x = rand() % 5 + 10 * 2.5;
		spike->Data1->Position = p1->Position;
		spike->Data1->Position.y += 2;
		spike->Data1->Position.x += 80;

		if (number) 
		{
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
	void RandomKillMomentum(CharObj2* p1) 
	{

		p1->Speed = { 0, 0, 0 };
		PrintDebug("Kill Momentum\n");
		return;
	}

	void RandomVSpeed(CharObj2* p1) 
	{
		p1->Speed.y = p1->PhysicsData.VSpeedCap;
		PrintDebug("Random VSpeed\n");
		return;
		
	}

	void RandomHSpeed(CharObj2* p1) 
	{
			p1->Speed.x = p1->PhysicsData.HSpeedCap;
			PrintDebug("Random HSpeed\n");
			return;
	}

	void RandomHurt() 
	{
		if (Rings > 0)
			PrintDebug("Hurt\n");
			return HurtCharacter(0);
		
	}

	void RandomPowerUP(EntityData1* p1)
	{
		int id = 0;
		if (id < 0 || id > 8) //failsafe
			id = rand() % 9;
		DoThingWithItemBoxPowerupIndex(id);
		PrintDebug("Random PowerUp\n");
	}

	void MGiantScale(EntityData1* p1) 
	{
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
		if (GameMode == GameModes_Adventure_Field)//made it so it only changes if you are in adventure field
		{
			SetTimeOfDay(rand() % 3);
			PrintDebug("Random Time Of Day\n");
			
		}
		else
		{
			Chaos_Timer = 1800;//forces another Chaos mod if not in Adventure 
		}

	}

	void RandomDroppedRings(EntityData1* p1)
	{
		SpawnDroppedRings(EntityData1Ptrs[0]->Position.x, EntityData1Ptrs[0]->Position.y, EntityData1Ptrs[0]->Position.z, rand() % 254); //spawns random ammount of rings 0-255 at the player
		PrintDebug("Random Dropped Rings\n");
	}
	void RandomClipLevel()//currently disabled, may be removed. updated to only change 
	{
			ClipLevel = rand() % 3;
			PrintDebug("Clip Level Set \n");

	}
	void RandomPause() //randomly pauses the game LOL get good, time
	{
		//GameState = 16; //pauses game, keeps music running, oh well. 
		Pause_Timer = 5; //how long in frames? to pause unpause?
		PrintDebug("Random Pause\n");
	}
	void RandomChar()//works but disabled
	{
		SetCharacter(rand() % 7);
		PrintDebug("Random Char\n");
	}


	//DisablePause
	//Disable input? lol
	//Fast Pause Unpase // kinda have this? it forces you to unpause a few times, lol 

	void SwapCamera()//Swaps Camera lmfao
	{
		if (GetCameraMode_() == 0)
		{
			SetCameraMode_(1);
		}
		else if (GetCameraMode_() == 1 ) //new code
		{
			SetCameraMode_(0);
		}
		PrintDebug("Camera Swapped\n");
	}

	void RandomDebug() //debug mode currently lasts for 75ish? frames
	{
		DebugMode = 1;
		Debug_Timer = 333;
		PrintDebug("Debug Mode on \n");
		
	}

	void  RandomXGravity()//currently disabled,
	{
		Gravity.x = rand() % 2 + (1.5);
		PrintDebug("Random X Gravity\n");

	}
	void  RandomYGravity()//currently disabled,
	{
		Gravity_Timer = 222;
		Gravity.y = rand() % 2 + (-1.5);
		PrintDebug("Random Y Gravity\n");
	}
	void  RandomZGravity()//currently disabled,
	{
		Gravity.z = rand() % 2 + (-1.5);
		PrintDebug("Random Z Gravity\n");
	}
	void RandomBarrier()//currently disabled, might be killing the player? lol
	{
		GiveBarrier(0);
		PrintDebug("Give Barrier\n");
	}
	void RandomMagneticBarrier()//currently disabled, might be killing the player? lol
	{
		GiveMagneticBarrier(0);
		PrintDebug("Give Magnetic Barrier\n");
	}
	void RandomInvincibility()//currently disabled, might be killing the player? lol
	{
		GiveInvincibility(0);
		PrintDebug("Give Invincibility\n");
	}

	void RandomControlDisable()
	{
		DisableControl_Timer = 90;
		PrintDebug("Disabled Controller\n");
	}

	void MSmallScale(EntityData1* p1)//disabled this?
	{
		for (int i = 0; i < 21; i++) {
			SONIC_OBJECTS[i]->scl[0] = 0.5;
			SONIC_OBJECTS[i]->scl[1] = 0.5;
			SONIC_OBJECTS[i]->scl[2] = 0.5;
		}
		PrintDebug("Small Scale\n");
		return;
	}

	void RandomSwapMusic() 
	{

		do {
			CurrentSong = rand() % 125;
		} while (LastSong == CurrentSong);

		LastSong = CurrentSong;
		PrintDebug("Random Song\n");
		return;
	}

	void ChaosPlayVoice_rng() 
	{
		int a1 = rand() % 2043;
		PlayVoice(a1);
		PrintDebug("Random Voice\n");
		return;
	}

	void RandomDPadDownCheck()
	{
		//enable dpaddown check timer
		DPadDown_Timer = 90; //90 frames?
		DpadDown = 0;
		PrintDebug("Timer set to 90 \n");
	}


	void RandomNoClip()
	{
		NoClip = 1;
		NoClip_Timer = 400;
		PrintDebug("NoClip Enabled\n");
	}
	typedef void(__cdecl* ChaosEnt)(EntityData1*);
	typedef void(__cdecl* ChaosCharObj)(CharObj2*);
	typedef void(__cdecl* ChaosNull)();
	struct ChaosS {
		ChaosEnt func;
		ChaosCharObj func2;
		ChaosNull func3;
	};

	FunctionPointer(ObjectMaster*, LoadAutoHint, (const char** textes, int voice), 0x7A1BE0);



	const char* Texts[]
	{
		"The frog you are looking for\nis up ahead.",
		"TestTestTest",
		nullptr
	};

	void AnyFunction()
	{
		//int RandomText = rand() % 3 + 1;
		LoadAutoHint(Texts, 1596);
		PrintDebug("Random Hint Test\n");
		fuckt = 1;
	}


	ChaosS ChaosArray[16]{

	{ RandomSpring, nullptr, nullptr, },
	{ RandomSpeedPad, nullptr, nullptr, },
	{ RandomSpikeBall, nullptr, nullptr, },
	//{ RandomDroppedRings, nullptr, nullptr },
	//{ RandomPowerUP, nullptr, nullptr },
	{ nullptr, RandomKillMomentum, nullptr, },
	{ nullptr, RandomVSpeed, nullptr, },
	{ nullptr, RandomHSpeed, nullptr, },
	{ nullptr, nullptr, RandomSwapMusic },
	{ nullptr, nullptr, ChaosPlayVoice_rng},
	//{ nullptr, nullptr, RandomHurt },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomPause },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, RandomDebug },
	{ nullptr, nullptr, RandomYGravity },
	{ nullptr, nullptr, RandomDPadDownCheck },
	{ nullptr, nullptr, RandomControlDisable },
	{ nullptr, nullptr, RandomNoClip },

	};
	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SADX
		if (!CharObj2Ptrs[0] || GameState != 15 || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || CurrentLevel >= LevelIDs_SSGarden)
			return;
		
		if (NoClip_Timer <= 400 && NoClip_Timer != 0)
		{
			NoClip_Timer--;
			if (NoClip == 1 && ClipTest == 0)
			{
				WriteData((int*)0x00444C1D, (int)0x90909090);
				WriteData((int*)0x00444C21, (int)0x10C48390);
				WriteData((int*)0x0044A66B, (int)0x90909090);
				WriteData((int*)0x0044A66F, (int)0x14C48390);
				WriteData((int*)0x007887D9, (int)0x90909090);
				WriteData((int*)0x007887DD, (int)0x74C08590);
				ClipTest = 1;
			}
			if (NoClip_Timer == 1 && NoClip_Timer != 0)
			{
				PrintDebug("NoClip Disabled\n");
				WriteData((int*)0x00444C1D, (int)0xFF37EEE8);
				WriteData((int*)0x00444C21, (int)0x10C483FF);
				WriteData((int*)0x0044A66B, (int)0xFFA430E8);
				WriteData((int*)0x0044A66F, (int)0x14C483FF);
				WriteData((int*)0x007887D9, (int)0x00D042E8);
				WriteData((int*)0x007887DD, (int)0x74C08500);
				NoClip_Timer = 0;
				NoClip = 0;
				ClipTest = 0;
			}
		}

		if (Gravity_Timer <= 222 && Gravity_Timer != 0)
		{
			Gravity_Timer--;
		}
		if (Gravity_Timer == 1 && Gravity_Timer != 0)
		{
			ResetGravity();
			Gravity_Timer = 0;
		}

		if (DisableControl_Timer <= 90 && DisableControl_Timer != 0)
		{
			ControlEnabled = 0;
			//WriteData((int*)0x00909FB0, 0x00);
			DisableControl_Timer--;
			
		}
		if (DisableControl_Timer == 1 && DisableControl_Timer != 0)
		{
			PrintDebug("Enabled Control\n");
			ControlEnabled = 1;
			//WriteData((int*)0x00909FB0, 0x01);
			DisableControl_Timer = 0;
		}

		if (DPadDown_Timer <= 90 && DPadDown_Timer != 0)
		{

			SetDebugFontColor(0xFFFF0000);
			SetDebugFontSize(18);
			DisplayDebugString(NJM_LOCATION(15, 40), "- PRESS DPAD DOWN OR DIE!!! -");
			if (ControllerPointers[0]->HeldButtons & Buttons_Down) //checks if dpad pressed down?
			{
				DpadDown = 1; // sets dpadcheck to 1
			}
			DPadDown_Timer--;
		}
		if (DPadDown_Timer == 1 && DpadDown != 1)//if timer is less then or 1 and DPadDown is not 1 
		{
			PrintDebug("Failed Button Check \n");
			KillPlayer(0);
			DPadDown_Timer = 0;
		}
		
		if (Pause_Timer <= 5 && Pause_Timer != 0)
		{
			GameState = 16;
			Pause_Timer--;
		}

		if (bstimer <= 200 && bstimer != 0)
		{
			bstimer--;
		}


		if (Debug_Timer <= 333 && Debug_Timer != 0)
			Debug_Timer--;

		if (DebugMode == 1 && Debug_Timer <= 5)
		{
			DebugMode = 0;
			Debug_Timer = 0;
			EntityData1Ptrs[0]->Action = 1;
			PrintDebug("Debug turned Off Action Set\n");
		}

		if (Chaos_Timer < 180)
			Chaos_Timer++;

		if (Chaos_Timer >= 180)
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
		if (ControllerPointers[0]->HeldButtons & Buttons_Down) //checks if dpad pressed down?
		{
			bstimer = 200;
			
			if (bstimer == 200 && fuckt ==0)
			{
				AnyFunction();
				fuckt = 1;
				
			}
			bstimer--;
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}