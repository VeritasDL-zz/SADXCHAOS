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
#include <SADXModLoader.h>


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
//started working on random tikal hints - thanks for the help kell, main and refrag, 
//finished random tikal hint, just need to add more hints, 
//added more hints and the first custom hint with custom voice file!
//Re-Enabled Random Dropped Rings (8/11/2021)
//fixed a bug with RandomTimeOfDay setting the chao timer to 1800
//fixed debug mode crash, gg 
//Credits to MainMemory for the Snowboard spawn Code, https://github.com/MainMemory/SADXBoardSpawner
//cleaned up no clip code
//cleaned up control disable code
//changed y grav rand math
//cleaned up ints
//made Kill Momentum play the custom roblox OOF sound,
//added random checkpoint (might not work as a real checkpoint but funny af)
//added Movement Stick Invert code thanks to Sora!
//added support for knux, amy, and metal sonic to movement debug, Tails, gamma and big dont have movement debug thanks to stars for pointing out im dumb,
//added random rotate
//trying to add support for editing the chaos timer, shits fucked 
//started adding Random Telport with the help of Refrag :)
//added Ability to edit How often things happen in the config menu




char oldRand = -1;
int Chaos_Timer = 0;
int Debug_Timer = 0;
int Pause_Timer = 0;
int DPadDown_Timer = 0;
int DpadDown = 0;
int DisableControl_Timer = 0;
int Gravity_Timer = 0;
int NoClip_Timer = 0;
int bstimer = 0;
int fuckt = 0;
int SnowboardTimer = 0;
int IssSowboarding = 0;
int InputInvert_Timer = 0;
int EffectMax = 0;
ObjectMaster* snowboard;

ObjectMaster* LoadSnowboardObject(LoadObj flags, char index, ObjectFuncPtr loadSub)
{
	return snowboard = LoadObject(flags, index, loadSub);
}

void __cdecl Snowboard_Delete_r(ObjectMaster* obj)
{
	njReleaseTexture((NJS_TEXLIST*)obj->Data1->LoopData);
	if (obj == snowboard)
		snowboard = nullptr;
}
std::unordered_map<LevelAndActIDs, std::vector<NJS_VECTOR>> customLocationsMap;

NJS_VECTOR GetRandomCoordinates(LevelAndActIDs levelAndAct)
{
	std::vector<NJS_VECTOR> coordsvector = customLocationsMap[levelAndAct];
	int random = 0;

	int fuckyou = coordsvector.size();
	if (fuckyou != 0)
	{
		fuckyou--;
		random = rand() % fuckyou;
	}
	PrintDebug("%i", fuckyou);
	PrintDebug("%I", (int)levelAndAct);

	return coordsvector[random];
}

void InitializeRandomCoordinates()
{
	customLocationsMap[LevelAndActIDs_EmeraldCoast1] =
	{
	{-9.0f,4.0f,4.0f },
	{1647.5f,115.0f,840.6f },
	{4042.8f,8.52f,363.5f },
	{5596.6f,3.21f,1096.52f }
	};

	customLocationsMap[LevelAndActIDs_EmeraldCoast2] =
	{
	{-986.50f,1106.5f,-2865.5f},
	{465.78f,635.85f,-798.99f},
	{1551.2f,545.98f,-958.93f},
	{2974.0f,2.6099f,-1529.03f},
	{3174.804f, 4.0f, -1588.66f},
	{2873.81f,292.30f,-2274.51f},
	{2959.53f,384.59f,-2724.012f},
	{3408.735f,70.0f,-2577.899f},
	{3687.43f,508.0f,-2827.662f},
	{4129.233f,496.0f,-2793.12f},
	{5378.593f,56.033f,-2648.15f}
	};

	customLocationsMap[LevelAndActIDs_WindyValley1] =
	{
	{1230.0f,-484.0f,-140.0f}, //sonic spawn act 0
	{2047.50f,-467.0f,5.63f}, //near flower clip
	{2303.77f,-415.22f,-280.37f}, //after checkpoint, near wind
	{2934.96f,-535.97f,-1479.40f}, //near torando
	{2903.87f,-505.80f,-914.59f}, //trampoline lol
	{2996.993f,-434.81f,-1517.76f}, //near life near torando
	};
	customLocationsMap[LevelAndActIDs_WindyValley2] =
	{
	{-5.379f,235.476f,-51.534f},//ontop of tikal orb bottom of torando,
	{-5.176f,493.717f,-75.79f},//ontop of tikal orb near jump pannel 1
	{-42.50f,986.0f,-11.105f}, //near trampoline
	{20.395f,1131.01f,19.717f},//on bridge
	{-25.182f,1800.824f,20.471f}//top of torando
	};

	customLocationsMap[LevelAndActIDs_WindyValley3] =
	{
	{1095.47f,-338.0f,-1250.59f},//top of act 3 sonic/tails spawn
	{1343.82f,-2661.0f,1324.48f},//near first rocket
	{3834.417f,-4492.0f,-1161.63f},//near wind
	{4140.870f,-4125.0268f,-1632.09f},//midair spring
	{4881.035f,-4043.27f,-2132.892f},//near checkpoint after springs
	{5718.33f,-6361.026f,665.40f},//near old sonic act 3 skip
	{5780.81f,-10700.34f,-574.620f}//end of act 3
	};

	customLocationsMap[LevelAndActIDs_Casinopolis1] =
	{
	{75.0f,201.0f,270.0f},//sonic spawn
	{}

	};

	customLocationsMap[LevelAndActIDs_Casinopolis2] =
	{
	{17.861f,-1840.0f,2869.292f},//sonic/tails spawn
	{-1415.618f,-680.0f,2868.097f},//top path of first wind tunnel
	{}

	};

}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{

		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.

		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		EffectMax = config->getInt("General", "EffectMax", 180);
		delete config;



		InitializeRandomCoordinates();
		WriteCall((void*)0x4E9423, LoadSnowboardObject);
		WriteCall((void*)0x4E967E, LoadSnowboardObject);
		WriteCall((void*)0x4E9698, LoadSnowboardObject);
		WriteCall((void*)0x597B34, LoadSnowboardObject);
		WriteCall((void*)0x597B46, LoadSnowboardObject);
		WriteJump(Snowboard_Delete, Snowboard_Delete_r);


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

	void RandomCheckPoint(EntityData1* p1)
	{

		ObjectMaster* checkpoint = LoadObject((LoadObj)15, 6, CheckPoint_Main);
		PrintDebug("Random checkpoint\n");
		SETObjData* CheckPointSETData = new SETObjData();
		checkpoint->SETData.SETData = CheckPointSETData;
		checkpoint->Data1->Rotation = p1->Rotation;
		checkpoint->Data1->Position = p1->Position;
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
		PlayVoice(55555);//OOF
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
			Chaos_Timer = EffectMax;//forces another Chaos mod if not in Adventure 
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
		switch (CurrentCharacter)
		{
		case Characters_Sonic:
		case Characters_MetalSonic:
			EntityData1Ptrs[0]->Action = 87;
			break;
		case Characters_Knuckles:
			EntityData1Ptrs[0]->Action = 57;
			break;
		case Characters_Amy:
			EntityData1Ptrs[0]->Action = 53;
			break;
		default:
			Chaos_Timer = EffectMax;
			return;
		}
		Debug_Timer = 333;
		PrintDebug("Debug Mode on \n");
		
	}

	void  RandomXGravity()//currently disabled,
	{
		Gravity.x = rand() % 2 + (1.5);
		PrintDebug("Random X Gravity\n");

	}
	void  RandomYGravity()
	{
		Gravity_Timer = 222;
		Gravity.y = rand() % 2 + (-1.5);
		PrintDebug("Random Y Gravity\n");
	}
	void  RandomZGravity()//currently disabled,
	{
		Gravity.z = rand() % 2 + (-1.0);
		PrintDebug("Random Z Gravity\n");
	}
	void FakeEmblem()
	{
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
		ControlEnabled = 0;
		PrintDebug("Disabled Controller\n");
	}

	void MSmallScale(EntityData1* p1)//disabled this
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

	void RandomTeleport()
	{
		NJS_VECTOR RandomTeleport = GetRandomCoordinates((LevelAndActIDs)(GetLevelAndAct()));
		EntityData1Ptrs[0]->Position = RandomTeleport;
	}

	void RandomNoClip()
	{
		NoClip_Timer = 400;
		WriteData((int*)0x00444C1D, (int)0x90909090);
		WriteData((int*)0x00444C21, (int)0x10C48390);
		WriteData((int*)0x0044A66B, (int)0x90909090);
		WriteData((int*)0x0044A66F, (int)0x14C48390);
		WriteData((int*)0x007887D9, (int)0x90909090);
		WriteData((int*)0x007887DD, (int)0x74C08590);
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


	//"The frog you are looking for Test 123456 is up ahead Testing How 123456789abcde", //max char for entire text box without new line can be 79 characters 
	//	"The frog you are looking for Test 123456\nis up ahead Testing How123456789abcdefg", //max char for each line with new line can be up to 81 characters (counting the new line)
	//A hint with \n can be 81 character (\n counts as 2)
	//A hint with no new line can be 79 charaters

	const HintText_Text Hint0[] = {
	{ "Watch out for the cars!.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint1[] = {
	{ "Aim for Chaos' head when he's off guard.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint2[] = {
	{ "You can punch the small bubbles of\nwater.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint3[] = {
	{ "Jump on panel number one. It will take\nyou to panels two and three. Jump as", 260 }, // text, time
	{ "soon as you land on a panel\nor else you'll fall.", 120 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint4[] = {
	{ "Insert the plug in the\nopening next to the door.", 130 }, // text, time
	{ "You need to grab hold of\nthe end of the plug.", 140 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};//if you read this
	  //you mom gay
	const HintText_Text Hint5[] = {
	{ "If you're hanging from a cord;\nuse the directional pad to sway.", 180 }, // text, time
	{ "By touching the cord next to you;\nyou will be able to switch cords.", 180 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint6[] = {
	{ "To pull out a plug; hold it and shake it.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint7[] = {
	{ "Even if you're frozen; jump a couple of\ntimes.", 160 }, // text, time
	{ "and you should be able to crack through.",140 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint8[] = {
	{ "Try and find places\nwhere it's not windy.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint9[] = {
	{ "Get a load of this!", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text Hint10[] = {
	{ "You can break through the wall if you use dynamite.", 180 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};
	const HintText_Text CustomHint1[] = {
	{ "OOF", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	};

	const HintText_Text const Hints[12][3] = {
	{
	{ "Watch out for the cars!.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Aim for Chaos' head when he's off guard.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "You can punch the small\nbubbles of water.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Jump on panel number one. It will take\nyou to panels two and three. Jump as", 260 }, // text, time
	{ "soon as you land on a panel\nor else you'll fall.", 120 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Insert the plug in the\nopening next to the door.", 130 }, // text, time
	{ "You need to grab hold of\nthe end of the plug.", 140 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},//if you read this
	  //you mom gay
	{
	{ "If you're hanging from a cord,\nuse the directional pad to sway.", 180 }, // text, time
	{ "By touching the cord next to you,\nyou will be able to switch cords.", 180 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "To pull out a plug, hold it and shake it.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Even if you're frozen, jump a couple of\ntimes.", 160 }, // text, time
	{ "and you should be able to crack through.",140 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Try and find places\nwhere it's not windy.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Get a load of this!", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "You can break through the wall if you use dynamite.", 180 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "OOF", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	};

	size_t HintSize = LengthOfArray(Hints);
	int Voices[] = {
	1857,
	181,
	182,
	1550,
	1595,
	1596,
	1597,
	1606,
	2043,
	174, //Get a load of this!
	1955,
	55555 //Custom OOF Voice
	};



	void RandomTikalHint()
	{
		int hintrand = rand() % HintSize;
		//PrintDebug("%i\n", hintrand);
		//LoadAutoHint(Hints[0], Voices[0]);
		LoadAutoHint(Hints[hintrand], Voices[hintrand]);
	    PrintDebug("%i Random Hint Test\n", hintrand);
		fuckt = 1;
	}

	void InputInvert()
	{
		WriteData<1>((int*)0x40F2A2, 0xC6);
		WriteData<1>((int*)0x40F2A1, 0x1);
		InputInvert_Timer = 420;
		PrintDebug("Input Inverted");
	}

	Void RandomRotate()
	{
		int Rotaterand = rand() % 65535;
			RotatePlayer(0, Rotaterand);
	}

	void RandomSnowboard()
	{
		if (IssSowboarding == 0)
		{
			SnowboardTimer = 333;
			IssSowboarding = 1;
			if (GameMode == GameModes_Menu || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || !GetCharacterObject(0)) //Credits to MainMemory for the Code, https://github.com/MainMemory/SADXBoardSpawner
				return;
			ObjectMaster* obj = GetCharacterObject(0);
			switch (obj->Data1->CharID)
			{
			case Characters_Sonic:
				if (obj->Data1->Action >= 62 && obj->Data1->Action <= 68)
					ForcePlayerAction(0, 24);
				else
				{
					ForcePlayerAction(0, 44);
					if (!snowboard)
						snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Sonic_Load);
				}
				break;
			case Characters_Tails:
				if (obj->Data1->Action >= 48 && obj->Data1->Action <= 54)
				{
					ForcePlayerAction(0, 24);
					// fix a bug where Tails' physics data doesn't get reset to normal
					((EntityData2*)obj->Data2)->CharacterData->PhysicsData.CollisionSize = PhysicsArray[Characters_Tails].CollisionSize;
					((EntityData2*)obj->Data2)->CharacterData->PhysicsData.YOff = PhysicsArray[Characters_Tails].YOff;
					((EntityData2*)obj->Data2)->CharacterData->PhysicsData.JumpSpeed = PhysicsArray[Characters_Tails].JumpSpeed;
				}
				else
				{
					ForcePlayerAction(0, 44);
					if (!snowboard)
						snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Tails_Load);
				}
				break;
			}
			if (!snowboard)
				switch (obj->Data1->CharID)
				{
				case Characters_Sonic:
					if (obj->Data1->Action >= 62 && obj->Data1->Action <= 68)
						snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Sonic_Load);
					break;
				case Characters_Tails:
					if (obj->Data1->Action >= 48 && obj->Data1->Action <= 54)
						snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Tails_Load);
					break;
				}//Credits to MainMemory for the Code, https://github.com/MainMemory/SADXBoardSpawner
			return;
			PrintDebug("Snowbaord Spawned\n");
		}
		else
		{
			Chaos_Timer = EffectMax;//forces another Chaos mod if already on snowboard?
		}
	}

	ChaosS ChaosArray[45]{

	{ RandomSpring, nullptr, nullptr, },
	{ RandomSpring, nullptr, nullptr, },
	{ RandomSpring, nullptr, nullptr, },
	{ RandomSpeedPad, nullptr, nullptr, },
	{ RandomSpeedPad, nullptr, nullptr, },
	{ RandomSpikeBall, nullptr, nullptr, },
	{ RandomSpikeBall, nullptr, nullptr, },
	{ RandomSpikeBall, nullptr, nullptr, },
	{ RandomDroppedRings, nullptr, nullptr },
	{ RandomCheckPoint, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ RandomPowerUP, nullptr, nullptr },
	{ nullptr, RandomKillMomentum, nullptr, },
	{ nullptr, RandomKillMomentum, nullptr, },
	{ nullptr, RandomVSpeed, nullptr, },
	{ nullptr, RandomVSpeed, nullptr, },
	{ nullptr, RandomHSpeed, nullptr, },
	{ nullptr, RandomHSpeed, nullptr, },
	{ nullptr, nullptr, RandomSwapMusic },
	{ nullptr, nullptr, ChaosPlayVoice_rng},
	{ nullptr, nullptr, RandomSnowboard },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomTimeOfDay },
	{ nullptr, nullptr, RandomPause },
	{ nullptr, nullptr, RandomPause },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, SwapCamera },
	{ nullptr, nullptr, RandomDebug },
	{ nullptr, nullptr, RandomYGravity },
	{ nullptr, nullptr, RandomYGravity },
	{ nullptr, nullptr, RandomDPadDownCheck },
	{ nullptr, nullptr, RandomControlDisable },
	{ nullptr, nullptr, RandomNoClip },
	{ nullptr, nullptr, RandomTikalHint },
	{ nullptr, nullptr, RandomTikalHint },
	{ nullptr, nullptr, RandomTikalHint },
	{ nullptr, nullptr, RandomTikalHint },
	{ nullptr, nullptr, InputInvert },

	};
	size_t ChaosSize = LengthOfArray(ChaosArray);

	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SADX

		if (!CharObj2Ptrs[0] || GameState != 15 || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || CurrentLevel >= LevelIDs_SSGarden)
			return;

		if (NoClip_Timer <= 400 && NoClip_Timer != 0)
		{
			NoClip_Timer--;

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
			}
		}
		if (InputInvert_Timer <= 420 && InputInvert_Timer != 0)
		{
			InputInvert_Timer--;
		}
		if (InputInvert_Timer == 1 && InputInvert_Timer != 0)
		{
			WriteData<1>((int*)0x40F2A2, 0xF0);
			WriteData<1>((int*)0x40F2A1, 0x2B);
			InputInvert_Timer = 0;
			PrintDebug("Input RE-Inverted\n");
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
			
			DisableControl_Timer--;
			
		}
		if (DisableControl_Timer == 1 && DisableControl_Timer != 0)
		{
			ControlEnabled = 1;
			DisableControl_Timer = 0;
			PrintDebug("Enabled Control\n");
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

		if (bstimer <= 100 && bstimer != 0)
		{
			bstimer--;
		}
		if (bstimer == 0 && fuckt == 1)
		{
			fuckt = 0;
		}
		if (SnowboardTimer <= 333 && SnowboardTimer != 0)
		{
			SnowboardTimer--;
		}
		if (SnowboardTimer == 1 && SnowboardTimer <= 5 && IssSowboarding == 1)
		{
			SnowboardTimer = 0;
			IssSowboarding = 0;
			EntityData1Ptrs[0]->Action = 1;
			PrintDebug("Snowbaord off Action Set\n");
		}
		if (Debug_Timer <= 333 && Debug_Timer != 0)
		{
			Debug_Timer--;
		}
		if (Debug_Timer <= 5 && Debug_Timer != 0)
		{
			Debug_Timer = 0;
			EntityData1Ptrs[0]->Action = 1;
			PrintDebug("Debug turned Off Action Set\n");
		}

		if (Chaos_Timer < EffectMax)//30 seconds is 1800
			Chaos_Timer++;

		if (Chaos_Timer >= EffectMax)
		{
			char curRand = 0;

			do {
				curRand = rand() % ChaosSize;
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

	__declspec(dllexport) void __cdecl OnControl(EntityData1* p1)
	{
		 //Executed when the game processes input
		if (Controllers[0].PressedButtons & Buttons_Y) //checks if A L R and Y are pressed
		{
			bstimer = 100;
			
			if (bstimer == 100 && fuckt == 0)
			{
				//PrintDebug("a%i", GetLevelAndAct());
				//PrintDebug("b%i", (int)LevelAndActIDs_EmeraldCoast1);
				//NJS_VECTOR RandomTeleport = GetRandomCoordinates((LevelAndActIDs)(GetLevelAndAct()));
				//EntityData1Ptrs[0]->Position = RandomTeleport;
				//fuckt = 0;
				
			}

		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}