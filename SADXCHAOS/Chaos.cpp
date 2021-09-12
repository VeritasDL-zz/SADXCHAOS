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
using std::string;


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
//cleaned up debug Output a little
//changed how long Gravity, noclip, and snowboard last before being disabled
//finished sonic casino act 0 teleports
//started working on casino act 1 teleport (might work for tails and sonic)
//changed gravity random math again
//finished Casino act 1 teleports
//finished teleports to emeraldcoast act 0
//finished icecap act 0 and 1 teleports
//finished speedhighway act 0 sonic teleports
//started working on act 2 speedhighway sonic teleports
//added Random Life PowerUp
//finished randomteleport crashing when not in a level/act that have teleports thanks to refrag again!
//finished twinkle park teleports
//added Option for Last Effect to Be Printed to Game Screen
//changed size, color and position of Last Effect text, also render a paque/translucent box around it.
//Re Enabled Random Hurt
//Added Option to print last effet to screen
//added Ability to spawn Enemys
//added more Enemys lol
//added RandomBurgerMan
//actully enabled Random Rotate.
//added 24 new tikal hints
//added more new "hints"
//sadly i have a crash with enemys in hub-worlds, only Beat, and Spinners can spawn in hubworlds currently 
//added randomchao, thanks to sora for the help and shuch
//added config options for, Random Enemys, Input Invert and RandomPause
//added FastAccel (for now) 






char oldRand = -1;
int Chaos_Timer = 0;
int Debug_Timer = 0;
int Pause_Timer = 0;
int DPadDown_Timer = 0;
int DpadDown = 0;
int DisableControl_Timer = 0;
int Gravity_Timer = 0;
int NoClip_Timer = 0;
int SnowboardTimer = 0;
int IssSowboarding = 0;
int InputInvert_Timer = 0;
int EffectMax = 0;
int FastAccel_Timer = 0;
int Animaltyperand = 0;
bool DebugToScreen = false;
bool TeleportEnabled = true;
bool EnemysEnabled = true;
bool InvertEnabled = true;
bool RPauseEnabled = true;
char* LastEffect = new char(128);
bool EnableFontScaling = false;
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
bool UnidusTextLoader = false;
bool AnimalTextLoader = false;
bool ChaooManagerLoader = false;

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
	UINT coordsSize = coordsvector.size();
	if (coordsSize == 0)
		return {0.0f,0.0f,0.0f};
	UINT random = rand() % (coordsSize - 1);
	return coordsvector[random];
}

struct PhyData[37]
{
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,3,16,16,3,1,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.06,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,8.5,18,0.08,7,5.3,
	60,1.5,16,16,2,0.6,1.66,3,0.23,0.49,1.39,2.8,3.7,5.09,0.076,0.06,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,3.5,9,0.08,6,4.5,
	60,2,16,16,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,4,11.4,0.08,9,5.7,
	60,2,16,16,3,1,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.06,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,4,10,0.08,7,5,
	60,1.5,16,16,0.05,0.5,1.3,3,0.23,0.46,1.39,2.3,3.7,5.09,0.013,0.045,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,3.5,10,0.04,7,5,
	60,2,16,16,2.5,0.6,2,3,0.23,1,2,2.5,3.7,5.09,0.09,0.06,0.031,-0.06,-0.25,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.9,0.3,4,21,0.1,20,14,
	60,2,5,8,1,0.2,2,3,0.23,0.32,1.39,2.3,3.7,5.09,0.1,0.08,0.031,-0.08,-0.18,-0.17,-0.028,-0.04,-0.01,-0.4,-0.1,-0.6,-0.2,0.3,9.5,17,0.135,15,8,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.05,-0.06,-0.18,-0.17,-0.002,-0.001,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	40,1.5,16,16,0.6,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,4,0.076,0.048,0.031,-0.06,-0.18,-0.17,-0.028,-0.01,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,3.5,9,0.08,6,4.5,
	0,3,16,16,3,1,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.06,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,8.5,15.5,0.08,14.5,10,
	60,2,16,16,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,4,11.4,0.08,9,5.7,
	60,2,16,16,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,4,11.4,0.08,9,5.7,
	16,3,16,16,1,1,2.6,3,0.23,0.46,1.39,1.8,2,3,0.19,0.1,0.031,-0.1,-0.18,-0.17,-0.028,-0.014,-0.02,-0.4,-0.1,-0.6,-0.3375,0.3,8,21,0.2,20,15,
	16,3,16,16,1,1,2.6,3,0.23,0.46,1.39,1.8,2,3,0.19,0.1,0.031,-0.1,-0.18,-0.17,-0.028,-0.014,-0.02,-0.4,-0.1,-0.6,-0.3375,0.3,8,21,0.2,20,15,
	60,2,16,16,1.3,0.6,1.3,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.048,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,16,16,3,0.6,2.52,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.2,0.05,-0.01,-0.02,-0.03,-0.028,-0.008,-0.01,-0.4,-0.4,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	16,3,16,16,1.4,1,2.6,3,0.23,0.46,1.39,1.8,2,3,0.19,0.2,0.046,-0.1,-0.18,-0.17,-0.028,-0.014,-0.02,-0.4,-0.4,-0.6,-0.3375,0.3,8,21,0.2,20,15,
	16,3,16,16,0.7,1,2.6,3,0.23,0.46,1.39,1.8,2,3,0.19,0.07,0.025,-0.1,-0.18,-0.17,-0.028,-0.014,-0.02,-0.4,-0.07,-0.6,-0.3375,0.3,8,21,0.2,20,15,
	60,2,16,16,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.06,0.031,-0.06,-0.2,-0.17,-0.028,-0.008,-0.01,-0.4,-0.3,-0.6,-0.45,0.3,4,11.4,0.08,9,5.7,
	60,2,16,16,1,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.09,-0.6,-0.3375,0.3,4,11.4,0.08,9,5.7,
	60,2,32,32,6,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.1,0.031,-0.09,-0.15,-0.14,-0.028,-0.008,-0.01,-0.4,-0.25,-0.8,-0.6,0.3,4,10,0.08,7,5.4,
	60,2,32,32,2.5,0.6,1.66,3,0.18,0.46,1.39,2.3,3.7,5.09,0.076,0.048,0.035,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.35,-0.85,-0.35,0.5,4,10,0.08,7,5.4,
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,4,10,0.08,7,5.4,
	60,2,32,32,6,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.1,0.031,-0.09,-0.15,-0.14,-0.028,-0.008,-0.01,-0.4,-0.25,-0.8,-0.6,0.3,4,10,0.08,7,5.4,
	60,2,32,32,2.5,0.6,1.66,3,0.18,0.46,1.39,2.3,3.7,5.09,0.076,0.048,0.035,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.35,-0.85,-0.35,0.5,6,15,0.08,14,7.5,
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,4,10,0.08,7,5.7,
	60,2,32,32,4.5,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.09,0.031,-0.06,-0.18,-0.14,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.2825,0.3,4,10,0.08,7,5.4,
	60,2,32,32,2.5,0.6,1.66,3,0.23,0.46,1.39,3.1,3.7,5.09,0.076,0.05,0.031,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.1,-0.6,-0.3375,0.3,8.5,18,0.08,18,9,
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,3.5,9,0.08,6,4.5,
	60,2,32,32,6,0.6,1.66,3,0.23,0.46,1.39,2.3,3.7,5.09,0.076,0.1,0.031,-0.09,-0.15,-0.14,-0.028,-0.008,-0.01,-0.4,-0.25,-0.8,-0.6,0.3,4,10,0.08,7,5.4,
	60,2,32,32,2.5,0.6,1.66,3,0.18,0.46,1.39,2.3,3.7,5.09,0.076,0.048,0.035,-0.06,-0.18,-0.17,-0.028,-0.008,-0.01,-0.4,-0.35,-0.85,-0.35,0.5,8,17,0.08,16,8.5,
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,3.5,9,0.08,6,4.5,
};

static const string Physnames[] = {
	"sonic",
	"eggman",
	"tails",
	"knuckles",
	"tikal",
	"amy",
	"gamma",
	"big",
	"supersonic",
	"sa2bsonic",
	"sa2bshadow",
	"sa2btails",
	"sa2beggman",
	"sa2bknuckles",
	"sa2brouge",
	"sa2bmechtails",
	"sa2bmecheggman",
	"sa2bamy",
	"sa2bsupersonic",
	"sa2bsupershadow",
	"sa2bunused",
	"sa2bmetalsonic",
	"sa2bchaowalker",
	"sa2bdarkchaowalker",
	"sa2btikal",
	"sa2bchaos",
	"sa2bunused2",
	"sa2bunused3",
	"heroessonic",
	"heroesknuckles",
	"heroestails",
	"heroesshadow",
	"heroesomega",
	"heroesrouge",
	"heroesamy",
	"heroesbig",
	"heroescream",
	"heroesespio",
	"heroesvector",
	"heroescharmy"
};
void InitializeRandomPhys()
{

}

void InitializeRandomCoordinates()
{
	customLocationsMap[LevelAndActIDs_EmeraldCoast1] =
	{
	{-9.0f,4.0f,4.0f},//spawn
	{1647.5f,115.0f,840.6f},
	{4042.8f,8.52f,363.5f},
	{5596.6f,3.21f,1096.52f},
	{-643.81f,46.0f,1381.965f},//bridge
	{-276.18f,55.228f,1205.669f},//near loop
	{829.321f,79.94f,636.158f},//near monkeys where gamma finds froggy
	{1051.650f,75.887f,865.474f}, //dashpad
	{1877.094f,198.0f,890.83f}, //spikes near lol
	{6090.589f,96.60f,1177.66f},//spring 
	{6298.54f,316.899f,1271.01f} //life
	};

	customLocationsMap[LevelAndActIDs_EmeraldCoast2] =
	{
	{-986.50f,1106.5f,-2865.5f},//spawn
	{465.78f,635.85f,-798.99f},
	{1551.2f,545.98f,-958.93f},
	{2974.0f,2.6099f,-1529.03f},
	{3174.804f,4.0f,-1588.66f},
	{2873.81f,292.30f,-2274.51f},
	{2959.53f,384.59f,-2724.012f},
	{3408.735f,70.0f,-2577.899f},
	{3687.43f,508.0f,-2827.662f},
	{4129.233f,496.0f,-2793.12f},
	{5378.593f,56.033f,-2648.15f}//end of level?
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
	{75.0f,201.0f,270.0f},//sonic/knux? spawn
	{698.775f,-195.46f,-292.370f},//where the claw takes your rings
	{347.270f,230.0f,-181.365f},//top of funny building
	{-291.916f,-196.0f,133.45f},//water fountain
	{-290.42f,-198.77f,-585.83f},//in the shower
	{308.82f,-195.891f,133.98f},//about to enter pinball
	{694.279f,-291.726f,-204.414f},//out of bounds on the ring platform,
	{838.22f,-133.06f,-282.697f}//near emerald/capsul
	};

	customLocationsMap[LevelAndActIDs_Casinopolis2] =
	{
	{17.861f,-1840.0f,2869.292f},//sonic/tails spawn
	{-1415.618f,-680.0f,2868.097f},//top path of first wind tunnel
	{-1256.346f,-887.597f,3082.240f},//mid path first wind tunnel
	{-1254.956f,-1080.0f,2719.986f},//lwoer path first wind tunnel
	{-1904.54f,-1510.0f,3018.261f},//top path of second wind tunnel
	{-2057.164f,-1910.0f,3176.71f},//lower path of second wind tunnel
	{-1568.430f,-2205.0f,2643.35f},//end of underground
	{-1569.90f,-2205.0f,1824.0f}//near tails emerald/ladder up
	};

	customLocationsMap[LevelAndActIDs_IceCap1] =
	{
	{1579.99f,-26.32f,1074.0f}, //sonic spawn
	{435.28f,92.64f,1010.76f},//tikal orb first ice room
	{487.92f,253.26f,1149.01f}, //life top first ice room
	{643.67f,213.49f,926.17f}, //rocket end of first ice room
	{1100.46f,336.22f,462.15f} //entering act 1
	};

	customLocationsMap[LevelAndActIDs_IceCap2] =
	{
	{1043.91f,-339.13f,252.92f}, //sonic spawn
	{1178.48f,5.248f,-92.66f},//spring bottom of ice room
	{1555.46f,366.689f,70.93f}, //3 ring box area
	{1177.05f,333.83f,-266.294f}, //switch to spawn icepath
	{1448.57f,576.399f,-256.989f}, //jumppad 1
	{1106.45f,320.0f,-76.74f}//past falling bridge
	};

	customLocationsMap[LevelAndActIDs_SpeedHighway1] =
	{
	{-673.0f,-10.0f,5.0f},//sonic spawn
	{2555.71f,-1263.25f,768.49f}, //first moving path
	{4755.08f,-1281.989f,-221.058f}, //bell
	{5608.82f,-1763.28f,1250.75f}, //first ball move thing
	{4728.29f,-1433.25f,1650.03f}, //speed shoes
	{2347.30f,-1303.02f,1797.20f},//after helecopter
	{1890.57f,-1326.0f,2255.44f}, //rocket
	{4272.64f,-1888.99f,4256.925f}, //rocket
	{4038.78f,-1500.0f,4672.31f}//after rocket near end
	};

	customLocationsMap[LevelAndActIDs_SpeedHighway3] =
	{
	{72.0f,24.5f,192.0f},//sonic spawn
	{-1519.54f,109.795f,-984.970f},//spring
	{-227.27f,150.0f,-1724.74f} //end
	};

	customLocationsMap[LevelAndActIDs_TwinklePark2] =
	{
	{-15.041f,142.0f,-1001.32f},//after rollercoaster sonic
	{-87.866f,0.0f,-490.0f},//pinball 1 
	{435.429f,0.0f,718.42f},//pinball 2
	{724.193f,50.0f,-362.295f},//amy spawn
	{323.486f,230.04f,608.35f},//near first floating platform
	{-87.82f,412.65f,14.078f},//spring
	{102.069f,532.58f,74.430f},//spring
	};

}

HMODULE moduleHandle;




extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		EffectMax = config->getInt("General", "EffectMax", 180);
		DebugToScreen = config->getBool("General", "PrintToScreen", false);
		TeleportEnabled = config->getBool("General", "TeleportEnabled", true);
		EnemysEnabled = config->getBool("General", "EnemysEnabled", true);
		InvertEnabled = config->getBool("General", "InvertEnabled", true);
		RPauseEnabled = config->getBool("General", "PauseEnabled", true);
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

	void DrawDebugRectangle(float leftchars, float topchars, float numchars_horz, float numchars_vert)
	{
		float FontScale;
		if (!EnableFontScaling) FontScale = 1.0f;
		else
		{
			if ((float)HorizontalResolution / (float)VerticalResolution > 1.33f) FontScale = floor((float)VerticalResolution / 480.0f);
			else FontScale = floor((float)HorizontalResolution / 640.0f);
		}
		njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
		njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
		DrawRect_Queue(leftchars * FontScale * 16.0f, topchars * FontScale * 16.0f, numchars_horz * FontScale * 16.0f, numchars_vert * FontScale * 16.0f, 62041.496f, 0x7F0000FF, QueuedModelFlagsB_EnableZWrite);
		njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
		njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
	}



	void RandomPhysics()
	{


	}

	void RandomTank(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}

		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (RinoTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_SAI", &E_SAI_TEXLIST);
			RinoTextLoader = true;
		}

		int number = rand() % 2;
		ObjectMaster* RhinoTank = LoadObject((LoadObj)2, 3, RhinoTank_Main);
		SETObjData* RhinoTankSETData = new SETObjData();
		RhinoTank->SETData.SETData = RhinoTankSETData;
		RhinoTank->Data1->Position = EntityData1Ptrs[0]->Position;
		RhinoTank->Data1->Position.z += rand() % 10 + 1 * 9;
		if (number)
		{
			ObjectMaster* RhinoTank = LoadObject((LoadObj)2, 3, RhinoTank_Main);
			SETObjData* RhinoTankSETData = new SETObjData();
			RhinoTank->SETData.SETData = RhinoTankSETData;
			RhinoTank->Data1->Position = EntityData1Ptrs[0]->Position;
			RhinoTank->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Tank");
		PrintDebug("Spawned Tank\n");
		return;
	}
	void RandomChaooAnimal()
	{
		Animaltyperand = rand() % 15 - 1;
		return;
	}
	void RandomChaoo()
	{
		if (ChaooManagerLoader == false)
		{
			ChaoMain_Constructor();
			al_confirmload_load();
			ChaoManager_Load();
			ChaooManagerLoader = true;
		}

		int chaotype = rand() % 25;
		ChaoData* chaodata = new ChaoData();
		chaodata->data.Happiness = rand() % 100;
		chaodata->data.Energy = rand() % 32767;
		chaodata->data.Hunger = rand() % 32767;
		chaodata->data.StaminaStat = rand() % 3266;
		chaodata->data.StaminaLevel = rand() % 99;
		chaodata->data.FlyStat = rand() % 3266;
		chaodata->data.FlyLevel = rand() % 99;
		chaodata->data.PowerStat = rand() % 3266;
		chaodata->data.PowerLevel = rand() % 99;
		chaodata->data.RunStat = rand() % 3266;
		chaodata->data.RunLevel = rand() % 99;
		chaodata->data.SwimStat = rand() % 3266;
		chaodata->data.SwimLevel = rand() % 99;
		chaodata->data.UnknownStat = rand() % 3266; //why not lol
		chaodata->data.UnknownLevel = rand() % 99;
		chaodata->data.IntelligenceLevel = rand() % 99;
		chaodata->data.RunnyNoseLevel = rand() % 200 - 100; //hopfully generates a number between -100 and +100
		chaodata->data.SADXAnimalBehaviors = rand() % 32767; //not sure if it works
		chaodata->data.FavoriteFruit = rand() % 7;
		chaodata->data.Texture = rand() % 16;
		chaodata->data.Garden = rand() % (6 - 4 + 1) + 4;
		chaodata->data.SADXCharacterBonds->a = rand() % 100;
		chaodata->data.SADXCharacterBonds->b = rand() % 100;
		int bodychangechance = rand() % 10;
		if (bodychangechance == 1)
		{
			int bodyrand = rand() % 3;
			chaodata->data.BodyType = (SADXBodyType)bodyrand;
		}
		int headgearchance = rand() % 10;
		if (headgearchance == 1)
		{
			chaodata->data.Headgear = rand() % 84;
		}
		int medalchance = rand() % 4;
		if (medalchance == 1)
		{
			chaodata->data.Medal = rand() % 15;
		}
		int shinychance = rand() % 4;
		if (shinychance == 1)
		{
			chaodata->data.Shiny = 1;
		}
		RandomChaooAnimal();
		chaodata->data.ArmType = (SADXAnimal)Animaltyperand;
		RandomChaooAnimal();
		chaodata->data.WingType = (SADXAnimal)Animaltyperand;
		RandomChaooAnimal();
		chaodata->data.TailType = (SADXAnimal)Animaltyperand;
		RandomChaooAnimal();
		chaodata->data.LegType = (SADXAnimal)Animaltyperand;
		RandomChaooAnimal();
		chaodata->data.EarType = (SADXAnimal)Animaltyperand;
		RandomChaooAnimal();
		chaodata->data.ForeheadType = (SADXAnimal)Animaltyperand;
		RandomChaooAnimal();
		chaodata->data.EyebrowType = (SADXAnimal)Animaltyperand;
		RandomChaooAnimal();
		chaodata->data.UnknownType = (SADXAnimal)Animaltyperand; //why not lol
		chaodata->data.MouthType = rand() % 15;
		chaodata->data.EyeType = rand() % 13;
		chaodata->data.BallType = rand() % 3;
		chaodata->data.Alignment = rand() % 2 - 1; //test
		ObjectMaster* Chao = CreateChao(chaodata, 0, 0, &EntityData1Ptrs[0]->Position, 0);
		chaodata->data.Type = (ChaoType)chaotype;
		chaodata->data.Color = rand() % 15;
		chaodata->data.BodyTypeAnimal = 127;
		chaodata->data.Name[0] = rand() % 255;
		chaodata->data.Name[1] = rand() % 255;
		chaodata->data.Name[2] = rand() % 255;
		chaodata->data.Name[3] = rand() % 255;
		chaodata->data.Name[4] = rand() % 255;
		chaodata->data.Name[5] = rand() % 255;
		chaodata->data.Name[6] = rand() % 255;
		chaodata->data.FlyGrade = rand() % 5;
		chaodata->data.IntelligenceGrade = rand() % 5;
		chaodata->data.LuckyGrade = rand() % 5;
		chaodata->data.PowerGrade = rand() % 5;
		chaodata->data.RunGrade = rand() % 5;
		chaodata->data.StaminaGrade = rand() % 5;
		chaodata->data.SwimGrade = rand() % 5;
		chaodata->data.UnknownGrade = rand() % 5;

		PrintDebug("Random Chao\n");
		strcpy_s(LastEffect, 128, "Spawned Random Chao");
	}
	void RandomBuyon(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (BuyonTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_BUYON", &E_BUYON_TEXLIST);
			BuyonTextLoader = true;
		}

		int number = rand() % 2;
		ObjectMaster* Buyon = LoadObject((LoadObj)2, 3, EBuyon);
		SETObjData* BuyonSETData = new SETObjData();
		Buyon->SETData.SETData = BuyonSETData;
		Buyon->Data1->Position = EntityData1Ptrs[0]->Position;
		Buyon->Data1->Position.z += rand() % 10 + 1 * 9;
		if (number)
		{
			ObjectMaster* Buyon = LoadObject((LoadObj)2, 3, EBuyon);
			SETObjData* BuyonSETData = new SETObjData();
			Buyon->SETData.SETData = BuyonSETData;
			Buyon->Data1->Position = EntityData1Ptrs[0]->Position;
			Buyon->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Buyon");
		PrintDebug("Spawned Buyon\n");
		return;
	}
	void RandomUnidus(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (UnidusTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("UNI_A_UNIBODY", &UNI_A_UNIBODY_TEXLIST);
			LoadPVM("UNI_C_UNIBODY", &UNI_C_UNIBODY_TEXLIST);
			LoadPVM("TOGEBALL_TOGEBALL", &TOGEBALL_TOGEBALL_TEXLIST);
			UnidusTextLoader = true;
		}

		int number = rand() % 2;
		ObjectMaster* Unidus = LoadObject((LoadObj)2, 3, UnidusA_Main);
		SETObjData* UnidusSETData = new SETObjData();
		Unidus->SETData.SETData = UnidusSETData;
		Unidus->Data1->Position = EntityData1Ptrs[0]->Position;
		Unidus->Data1->Position.z += rand() % 10 + 1 * 9;
		if (number)
		{
			ObjectMaster* Unidus = LoadObject((LoadObj)2, 3, UnidusA_Main);
			SETObjData* UnidusSETData = new SETObjData();
			Unidus->SETData.SETData = UnidusSETData;
			Unidus->Data1->Position = EntityData1Ptrs[0]->Position;
			Unidus->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Unidus");
		PrintDebug("Spawned Unidus\n");
		return;
	}
	void RandomAmebot(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (AmebotTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_AMENBO", &E_AMENBO_TEXLIST);
			AmebotTextLoader = true;
		}

		int number = rand() % 2;
		ObjectMaster* Amebot = LoadObject((LoadObj)2, 3, Sweep_Load);
		SETObjData* AmebotSETData = new SETObjData();
		Amebot->SETData.SETData = AmebotSETData;
		Amebot->Data1->Position = EntityData1Ptrs[0]->Position;
		if (number)
		{
			ObjectMaster* Amebot = LoadObject((LoadObj)2, 3, Sweep_Load);
			SETObjData* AmebotSETData = new SETObjData();
			Amebot->SETData.SETData = AmebotSETData;
			Amebot->Data1->Position = EntityData1Ptrs[0]->Position;
		}
		strcpy_s(LastEffect, 128, "Spawned Amebo");
		PrintDebug("Spawned Amebo\n");
		return;
	}
	
	void RandomPolice(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (PoliceTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("NISEPAT", &NISEPAT_TEXLIST);
			PoliceTextLoader = true;
		}

		int number = rand() % 2;
		ObjectMaster* CopSpeeder = LoadObject((LoadObj)2, 3, EPolice);
		SETObjData* CopSpeederSETData = new SETObjData();
		CopSpeeder->SETData.SETData = CopSpeederSETData;
		CopSpeeder->Data1->Position = EntityData1Ptrs[0]->Position;
		CopSpeeder->Data1->Position.z += rand() % 10 + 1 * 9;
		if (number)
		{
			ObjectMaster* CopSpeeder = LoadObject((LoadObj)2, 3, EPolice);
			SETObjData* CopSpeederSETData = new SETObjData();
			CopSpeeder->SETData.SETData = CopSpeederSETData;
			CopSpeeder->Data1->Position = EntityData1Ptrs[0]->Position;
			CopSpeeder->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned The Police");
		PrintDebug("Spawned The Police\n");
		return;
	}
	
	void RandomSnake(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (SnakeTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_SNAKE", &E_SNAKE_TEXLIST);
			SnakeTextLoader = true;
		}
		int number = rand() % 2;
		ObjectMaster* Snake = LoadObject((LoadObj)2, 3, BoaBoa_Main);
		SETObjData* SnakeSETData = new SETObjData();
		Snake->SETData.SETData = SnakeSETData;
		Snake->Data1->Position = EntityData1Ptrs[0]->Position;
		Snake->Data1->Position.z += rand() % 90 + 1 * 9;
		if (number)
		{
			ObjectMaster* Snake = LoadObject((LoadObj)2, 3, BoaBoa_Main);
			SETObjData* SnakeSETData = new SETObjData();
			Snake->SETData.SETData = SnakeSETData;
			Snake->Data1->Position = EntityData1Ptrs[0]->Position;
			Snake->Data1->Position.z += rand() % 90 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Boa-Boa");
		PrintDebug("Spawned Boa-Boa\n");
		return;
	}
	
	void RandomRobo(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (RoboTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_ROBO", &E_ROBO_TEXLIST);
			SnakeTextLoader = true;
		}
		int number = rand() % 2;
		ObjectMaster* Robo = LoadObject((LoadObj)2, 3, ERobo_0);
		SETObjData* RoboSETData = new SETObjData();
		Robo->SETData.SETData = RoboSETData;
		Robo->Data1->Position = EntityData1Ptrs[0]->Position;
		Robo->Data1->Position.z += rand() % 10 + 1 * 9;
		if (number)
		{
			ObjectMaster* Robo = LoadObject((LoadObj)2, 3, ERobo_0);
			SETObjData* RoboSETData = new SETObjData();
			Robo->SETData.SETData = RoboSETData;
			Robo->Data1->Position = EntityData1Ptrs[0]->Position;
			Robo->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Robo");
		PrintDebug("Spawned Robo\n");
		return;
	}
	
	void RandomLeon(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (LeonTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_LEON", &E_LEON_TEXLIST);
			LeonTextLoader = true;
		}
		int number = rand() % 2;
		ObjectMaster* Leon = LoadObject((LoadObj)2, 3, Leon_Load);
		SETObjData* LeonSETData = new SETObjData();
		Leon->SETData.SETData = LeonSETData;
		Leon->Data1->Position = EntityData1Ptrs[0]->Position;
		Leon->Data1->Position.z += rand() % 10 + 1 * 9;
		if (number)
		{
			ObjectMaster* Leon = LoadObject((LoadObj)2, 3, Leon_Load);
			SETObjData* LeonSETData = new SETObjData();
			Leon->SETData.SETData = LeonSETData;
			Leon->Data1->Position = EntityData1Ptrs[0]->Position;
			Leon->Data1->Position.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Leon");
		PrintDebug("Spawned Leon\n");
		return;
	}

	void RandomKiki(EntityData1* p1) 
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (KikiTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_SARU", &E_SARU_TEXLIST);
			LoadPVM("E_BOMB", &E_BOMB_TEXLIST);
			KikiTextLoader = true;
		}
		int number = rand() % 2;
		ObjectMaster* Kiki = LoadObject((LoadObj)2, 3, Kiki_Load);
		SETObjData* KikiSETData = new SETObjData();
		Kiki->SETData.SETData = KikiSETData;
		Kiki->Data1->Position = EntityData1Ptrs[0]->Position;
		Kiki->Data1->Position.z += rand() % 10 + 1 * 9;
		Kiki->Data1->Position.y += rand() % 2 + 1 * 9;
		if (number)
		{
			ObjectMaster* Kiki = LoadObject((LoadObj)2, 3, Kiki_Load);
			SETObjData* KikiSETData = new SETObjData();
			Kiki->SETData.SETData = KikiSETData;
			Kiki->Data1->Position = EntityData1Ptrs[0]->Position;
			Kiki->Data1->Position.z += rand() % 10 + 1 * 9;
			Kiki->Data1->Position.y += rand() % 2 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Kiki");
		PrintDebug("Spawned Kiki\n");
		return;
	}

	void RandomFallingSpikeBall(EntityData1* p1)
	{
		if (FSBTextLoader == false)
		{

			LoadPVM("TOGEBALL_TOGEBALL", &TOGEBALL_TOGEBALL_TEXLIST);
			FSBTextLoader = true;
		}

		int number = rand() % 2;
		ObjectMaster* FallingSpikeBall = LoadObject((LoadObj)2, 3, FallingSpikeBall_Load);
		SETObjData* FallingSpikeBallSETData = new SETObjData();
		FallingSpikeBall->SETData.SETData = FallingSpikeBallSETData;
		FallingSpikeBall->Data1->Position = EntityData1Ptrs[0]->Position;
		FallingSpikeBall->Data1->Position.y += rand() % 30 + 1 * 9;
		FallingSpikeBall->Data1->Position.z += rand() % 30 + 1 * 9;
		if (number)
		{
			ObjectMaster* FallingSpikeBall = LoadObject((LoadObj)2, 3, FallingSpikeBall_Load);
			SETObjData* FallingSpikeBallSETData = new SETObjData();
			FallingSpikeBall->SETData.SETData = FallingSpikeBallSETData;
			FallingSpikeBall->Data1->Position = EntityData1Ptrs[0]->Position;
			FallingSpikeBall->Data1->Position.y += rand() % 30 + 1 * 9;
			FallingSpikeBall->Data1->Position.z += rand() % 30 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Falling SpikeBall");
		PrintDebug("Falling SpikeBall\n");
		return;
	}

	void RandomSpinnerA(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (SpinnerTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
			SpinnerTextLoader = true;
		}
		ObjectMaster* SpinnerA = LoadObject((LoadObj)2, 3, SpinnerA_Main);
		SETObjData* SpinnerASETData = new SETObjData();
		SpinnerA->SETData.SETData = SpinnerASETData;
		SpinnerA->Data1->Position = EntityData1Ptrs[0]->Position;
		SpinnerA->Data1->Position.z += rand() % 10 + 1 * 9;
		SpinnerA->Data1->Position.y += rand() % 2 + 1 * 9;
		strcpy_s(LastEffect, 128, "Spawned Spinner A");
		PrintDebug("Spawned Spinner A\n");
		return;
	}
	void RandomSpinnerB(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (SpinnerTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
			SpinnerTextLoader = true;
		}
		ObjectMaster* SpinnerB = LoadObject((LoadObj)2, 3, SpinnerB_Main);
		SETObjData* SpinnerBSETData = new SETObjData();
		SpinnerB->SETData.SETData = SpinnerBSETData;
		SpinnerB->Data1->Position = EntityData1Ptrs[0]->Position;
		SpinnerB->Data1->Position.z += rand() % 10 + 1 * 9;
		SpinnerB->Data1->Position.y += rand() % 2 + 1 * 9;
		strcpy_s(LastEffect, 128, "Spawned Spinner B");
		PrintDebug("Spawned Spinner B\n");
		return;
	}
	void RandomSpinnerC(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (SpinnerTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
			SpinnerTextLoader = true;
		}
		ObjectMaster* SpinnerC = LoadObject((LoadObj)2, 3, SpinnerC_Main);
		SETObjData* SpinnerCSETData = new SETObjData();
		SpinnerC->SETData.SETData = SpinnerCSETData;
		SpinnerC->Data1->Position = EntityData1Ptrs[0]->Position;
		SpinnerC->Data1->Position.z += rand() % 10 + 1 * 9;
		SpinnerC->Data1->Position.y += rand() % 2 + 1 * 9;
		strcpy_s(LastEffect, 128, "Spawned Spinner C");
		PrintDebug("Spawned Spinner C\n");
		return;
	}

	void RandomSman(EntityData1* p1)//
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (GameMode == GameModes_Adventure_Field)//sadly i havent stopped enemys from crashing when in Hub worlds
		{
			Chaos_Timer = EffectMax;
			return;

		}
		if (SmanTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_SNOWMAN", &E_SNOWMAN_TEXLIST);
			LoadNoNamePVM(&stx_ice0_TEXLIST);
			SmanTextLoader = true;
		}
		ObjectMaster* ESMAN = LoadObject((LoadObj)2, 3, ESman);
		SETObjData* ESMANSETData = new SETObjData();
		ESMAN->SETData.SETData = ESMANSETData;
		ESMAN->Data1->Position = EntityData1Ptrs[0]->Position;
		strcpy_s(LastEffect, 128, "Spawned IceBall");
		PrintDebug("Spawned IceBall\n");
		return;
	}

	void RandomEGacha(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (EGachaTextLoader == false)
		{
			if (AnimalTextLoader == false)
			{
				for (int j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("GACHAPON", &GACHAPON_TEXLIST);
			EGachaTextLoader = true;
		}
		int number = rand() % 2;
		ObjectMaster* GACHAPON = LoadObject((LoadObj)2, 3, OEGacha);
		SETObjData* GACHAPONSETData = new SETObjData();
		GACHAPON->SETData.SETData = GACHAPONSETData;
		GACHAPON->Data1->Position = EntityData1Ptrs[0]->Position;
		if (number)
		{
			ObjectMaster* GACHAPON = LoadObject((LoadObj)2, 3, OEGacha);
			SETObjData* GACHAPONSETData = new SETObjData();
			GACHAPON->SETData.SETData = GACHAPONSETData;
			GACHAPON->Data1->Position = EntityData1Ptrs[0]->Position;
			GACHAPON->Data1->Position.y += rand() % 30 + 1 * 9;
			GACHAPON->Data1->Position.z += rand() % 30 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Beat");
		PrintDebug("Spawned Beat\n");
		return;
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
		strcpy_s(LastEffect, 128, "Spawned Spring");
		PrintDebug("Random Spring\n");
		return;
	}

	void RandomCheckPoint(EntityData1* p1)
	{
		ObjectMaster* checkpoint = LoadObject((LoadObj)15, 6, CheckPoint_Main);
		SETObjData* CheckPointSETData = new SETObjData();
		checkpoint->SETData.SETData = CheckPointSETData;
		checkpoint->Data1->Rotation = p1->Rotation;
		checkpoint->Data1->Position = p1->Position;
		strcpy_s(LastEffect, 128, "Random CheckPoint");
		PrintDebug("Random Checkpoint\n");
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
		strcpy_s(LastEffect, 128, "Spawned SpeedPad");
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
		strcpy_s(LastEffect, 128, "Spawned SpikeBall");
		PrintDebug("Random Spike Balls\n");
		return;
	}

	void RandomBurgerMan(EntityData1* p1)
	{
		if (BugerManTextLoader == false)
		{
			LoadPVM("MI_3DASU", &mi_3dasu_TEXLIST);
			BugerManTextLoader = true;
		}

		ObjectMaster* BurgerMan = LoadObject((LoadObj)3, 3, MissionStatue_Load);
		SETObjData* BurgerManSETData = new SETObjData();
		BurgerMan->SETData.SETData = BurgerManSETData;
		BurgerMan->Data1->Position = EntityData1Ptrs[0]->Position;
		strcpy_s(LastEffect, 128, "Spawned BurgerMan");
		PrintDebug("Random BurgerMan\n");
		return;
	}


	void RandomKillMomentum(CharObj2* p1) 
	{
		PlayVoice(55555);//OOF
		p1->Speed = { 0, 0, 0 };
		strcpy_s(LastEffect, 128, "Killed Momentum");
		PrintDebug("Kill Momentum\n");
		return;
	}
	void FastAccel(CharObj2* p1)
	{
		FastAccel_Timer = 400;
		CharObj2Ptrs[0]->PhysicsData.MaxAccel = 10.0f;
		CharObj2Ptrs[0]->PhysicsData.AirAccel = 0.10f;
		CharObj2Ptrs[0]->PhysicsData.HangTime = 120;
		strcpy_s(LastEffect, 128, "Fast Accel Enabled");
		PrintDebug("Fast Accel Enabled\n");
		return;
	}
	void RandomVSpeed(CharObj2* p1) 
	{
		p1->Speed.y = p1->PhysicsData.VSpeedCap;
		strcpy_s(LastEffect, 128, "Random V Speed");
		PrintDebug("Random V Speed\n");
		return;
	}
	void RandomHSpeed(CharObj2* p1) 
	{
			p1->Speed.x = p1->PhysicsData.HSpeedCap;
			strcpy_s(LastEffect, 128, "Random H Speed");
			PrintDebug("Random H Speed\n");
			return;
	}
	void RandomHurt() 
	{
		if (Rings > 0)
		{
			HurtCharacter(0);
		}
		PrintDebug("Hurt\n");
		strcpy_s(LastEffect, 128, "Hurt");
		return;
	}
	void RandomPowerUP(EntityData1* p1)
	{
		int id = 0;
		if (id < 0 || id > 8) //failsafe
			id = rand() % 9;
		DoThingWithItemBoxPowerupIndex(id);
		PrintDebug("Random PowerUp\n");
		strcpy_s(LastEffect, 128, "Random PowerUp");
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
			strcpy_s(LastEffect, 128, "Random Time Of Day");
		}
		else
		{
			PrintDebug("Not in adventure field\n");
			Chaos_Timer = EffectMax;//forces another Chaos mod if not in Adventure 
		}
	}
	void RandomDroppedRings(EntityData1* p1)
	{
		int randomrings = rand() % 254;
		SpawnDroppedRings(EntityData1Ptrs[0]->Position.x, EntityData1Ptrs[0]->Position.y, EntityData1Ptrs[0]->Position.z, randomrings); //spawns random ammount of rings 0-255 at the player
		Rings = 0;
		PrintDebug("Random Dropped Rings\n");
		strcpy_s(LastEffect, 128, "Dropped Rings");
	}
	void RandomClipLevel()//currently disabled, may be removed. updated to only change 
	{
			ClipLevel = rand() % 3;
			PrintDebug("Clip Level Set\n");
	}
	void RandomPause() //randomly pauses the game LOL get good, time
	{
		if (!PauseEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		Pause_Timer = 5; //how long in frames? to pause unpause?
		PrintDebug("Random Pause\n");
		strcpy_s(LastEffect, 128, "Random Pause");
	}
	void RandomChar()//works but disabled
	{
		SetCharacter(rand() % 7);
		PrintDebug("Random Character\n");
	}
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
		strcpy_s(LastEffect, 128, "Camera Swapped");
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
			PrintDebug("Debug Mode Failed Due to Current Character\n");
			Chaos_Timer = EffectMax;
			return;
		}
		Debug_Timer = 333;
		PrintDebug("Debug Mode Enabled\n");
		strcpy_s(LastEffect, 128, "Debug Mode Enabled");
	}
	void RandomXGravity()//currently disabled,
	{
		Gravity.x = (float)rand() / RAND_MAX + (-1.5);
		PrintDebug("Random X Gravity\n");
	}
	void RandomYGravity()
	{
		Gravity_Timer = 1000;
		Gravity.y = (float)rand() / RAND_MAX + (-1.5);
		PrintDebug("Random Y Gravity\n");
		strcpy_s(LastEffect, 128, "Random Y Gravity");
	}
	void RandomZGravity()//currently disabled,
	{
		Gravity.z = (float)rand() / RAND_MAX + (-1.5);
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
	void RandomLifePowerup(EntityData1* p1)
	{
		ExtraLifePowerup(0);
		PrintDebug("Give Extra Life\n");
		strcpy_s(LastEffect, 128, "Extra Life");
	}
	void RandomControlDisable()
	{
		DisableControl_Timer = 90;
		ControlEnabled = 0;
		PrintDebug("Control Disabled\n");
		strcpy_s(LastEffect, 128, "Control Disabled");
	}
	void MSmallScale(EntityData1* p1)//disabled this
	{
		for (int i = 0; i < 21; i++) {
			SONIC_OBJECTS[i]->scl[0] = 0.5;
			SONIC_OBJECTS[i]->scl[1] = 0.5;
			SONIC_OBJECTS[i]->scl[2] = 0.5;
		}
		PrintDebug("Small Scale\n");
		strcpy_s(LastEffect, 128, "Small Scale");
		return;
	}
	void RandomSwapMusic() 
	{
		do {
			CurrentSong = rand() % 125;
		} while (LastSong == CurrentSong);
		LastSong = CurrentSong;
		PrintDebug("Random Song\n");
		strcpy_s(LastEffect, 128, "Random Song");
		return;
	}

	void ChaosPlayVoice_rng() 
	{
		int a1 = rand() % 2043;
		PlayVoice(a1);
		PrintDebug("Random Voice\n");
		strcpy_s(LastEffect, 128, "Random Voice");
		return;
	}

	void RandomDPadDownCheck()
	{
		//enable dpaddown check timer
		DPadDown_Timer = 90; //90 frames?
		DpadDown = 0;
		PrintDebug("Press Dpad Down Or Die\n");
		strcpy_s(LastEffect, 128, "Death");
	}

	void RandomTeleport()
	{
		if (TeleportEnabled == false)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		NJS_VECTOR RandomTeleport = GetRandomCoordinates((LevelAndActIDs)(GetLevelAndAct()));
		if (RandomTeleport.x == 0.0f && RandomTeleport.y == 0.0f && RandomTeleport.z == 0.0f)
		{
			PrintDebug("No Random Teleports for this Level/Act, causing new Effect\n");
			Chaos_Timer = EffectMax; //calls a new effect
			return;
		}
		EntityData1Ptrs[0]->Position = RandomTeleport;
		PrintDebug("Random Teleport\n");
		strcpy_s(LastEffect, 128, "Random Teleport");
	}

	void RandomNoClip()
	{
		NoClip_Timer = 800;
		WriteData((int*)0x00444C1D, (int)0x90909090);
		WriteData((int*)0x00444C21, (int)0x10C48390);
		WriteData((int*)0x0044A66B, (int)0x90909090);
		WriteData((int*)0x0044A66F, (int)0x14C48390);
		WriteData((int*)0x007887D9, (int)0x90909090);
		WriteData((int*)0x007887DD, (int)0x74C08590);
		PrintDebug("Walk Thru Walls Enabled\n");
		strcpy_s(LastEffect, 128, "Walk Thru Walls Enabled");
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

	const HintText_Text const Hints[48][3] = {
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
	{
	{ "You're the... Chao!", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Father; please don't!", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "My true hope is that someday\nwe'll understand each other.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "(gasps)", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Father!", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "(groans)", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Keep your balance;\nor else you'll fall off.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Hide in here.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Be careful of Leon.\nHe appears suddenly.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "You're going the wrong way.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Be brave; blue hedgehog.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Watch out for the helicopter propellers.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Save the animals.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Use the dash panels.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "This way!", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Sega!", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "I won't obey!", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Wow...", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "I'm shocked...!", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Oh please!", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "I'm Tikal.\nAnd you are?", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "But the number seven...", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Why?", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Select a memory card.", 100 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Oh no!", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Oh no!", 69 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "The ice looks kinda tasty!", 130 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "What a huge house!", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Froggy; where are you?", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Maybe I'll go home.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Uh; exits? Exits?", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "I wanna go fishing!", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "So; that's his core.", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Did you know that there are\n15 animals hidden in this stage?", 120 }, // text, time
	{ 0 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "Hey you. You're finally awake. You were\ntrying to cross the border right?", 380 }, // text, time
	{ "Walked right into that Imperial ambush\nsame as us, and that Thief over there.", 380 }, //Second page
	{ 0 } //idk 3rd page or always null?
	},
	{
	{ "I Used To Be An Adventurer Like You\nThen I Took An Arrow In The Knee.", 260 }, // text, time
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
	55555, //Custom OOF Voice
	919,
	1024,
	1222,
	1356,
	1444,
	1465,
	1594,
	1665,
	1674,
	1677,
	1714,
	1861,
	1875,
	1941,
	1954,
	2010,
	1440,
	1352,
	1141,
	1103,
	746,
	742,
	89,
	18,
	164,//knux oh-no
	165,//sonic oh-no
	241,
	298,
	310,
	319,
	344,
	367,
	389,//core
	145469,//Omochao
	69420, //skyrim intro
	42069 //skyrim adventure arrow
	};

	void RandomTikalHint()
	{
		int hintrand = rand() % HintSize;
		LoadAutoHint(Hints[hintrand], Voices[hintrand]);
	    PrintDebug("%i Random Hint\n", hintrand);
		strcpy_s(LastEffect, 128, "Tikal Hint");
	}
	void InputInvert()
	{
		if (!InvertEnabled)
		{
				Chaos_Timer = EffectMax;
				return;
		}
		WriteData<1>((int*)0x40F2A2, 0xC6);
		WriteData<1>((int*)0x40F2A1, 0x1);
		InputInvert_Timer = 420;
		PrintDebug("Input Inverted\n");
		strcpy_s(LastEffect, 128, "Input Inverted");
	}

	Void RandomRotate()
	{
		int Rotaterand = rand() % 65535;
			RotatePlayer(0, Rotaterand);
			PrintDebug("%i Rotated\n", Rotaterand);
			strcpy_s(LastEffect, 128, "Random Rotation");
	}

	void RandomSnowboard()
	{
		if (IssSowboarding == 0)
		{
			SnowboardTimer = 500;
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
			
			PrintDebug("Snowbaord Spawned\n");
			strcpy_s(LastEffect, 128, "Snowboard");
			return;
		}
		else
		{
			Chaos_Timer = EffectMax;//forces another Chaos mod if already on snowboard?
			PrintDebug("Currently on Snowboard new effect chosen\n");
		}
	}

	ChaosS ChaosArray[71]{

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
	{ RandomLifePowerup, nullptr, nullptr },
	{ RandomTank, nullptr, nullptr },
	{ RandomEGacha, nullptr, nullptr },
	{ RandomLeon, nullptr, nullptr },
	{ RandomSpinnerA, nullptr, nullptr },
	{ RandomSpinnerB, nullptr, nullptr },
	{ RandomSpinnerC, nullptr, nullptr },
	{ RandomRobo, nullptr, nullptr },
	{ RandomSnake, nullptr, nullptr },
	{ RandomPolice, nullptr, nullptr },
	{ RandomAmebot, nullptr, nullptr },
	{ RandomUnidus, nullptr, nullptr },
	{ RandomBuyon, nullptr, nullptr },
	{ RandomSman, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ RandomBurgerMan, nullptr, nullptr },
	{ nullptr, RandomKillMomentum, nullptr, },
	{ nullptr, RandomKillMomentum, nullptr, },
	{ nullptr, RandomVSpeed, nullptr, },
	{ nullptr, RandomVSpeed, nullptr, },
	{ nullptr, RandomHSpeed, nullptr, },
	{ nullptr, RandomHSpeed, nullptr, },
	{ nullptr, FastAccel, nullptr },
	{ nullptr, nullptr, RandomSwapMusic},
	{ nullptr, nullptr, ChaosPlayVoice_rng},
	{ nullptr, nullptr, RandomSnowboard},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomTimeOfDay},
	{ nullptr, nullptr, RandomPause},
	{ nullptr, nullptr, RandomPause},
	{ nullptr, nullptr, SwapCamera},
	{ nullptr, nullptr, SwapCamera},
	{ nullptr, nullptr, SwapCamera},
	{ nullptr, nullptr, SwapCamera},
	{ nullptr, nullptr, RandomDebug},
	{ nullptr, nullptr, RandomYGravity},
	{ nullptr, nullptr, RandomYGravity},
	{ nullptr, nullptr, RandomDPadDownCheck},
	{ nullptr, nullptr, RandomControlDisable},
	{ nullptr, nullptr, RandomControlDisable},
	{ nullptr, nullptr, RandomControlDisable},
	{ nullptr, nullptr, RandomNoClip},
	{ nullptr, nullptr, RandomNoClip},
	{ nullptr, nullptr, RandomNoClip},
	{ nullptr, nullptr, RandomTikalHint},
	{ nullptr, nullptr, RandomTikalHint},
	{ nullptr, nullptr, RandomTikalHint},
	{ nullptr, nullptr, RandomTikalHint},
	{ nullptr, nullptr, InputInvert},
	{ nullptr, nullptr, RandomTeleport},
	{ nullptr, nullptr, RandomHurt},
	{ nullptr, nullptr, RandomHurt},
	{ nullptr, nullptr, RandomRotate},
	{ nullptr, nullptr, RandomChaoo},
	};

	size_t ChaosSize = LengthOfArray(ChaosArray);
	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SADX
		if (!CharObj2Ptrs[0] || GameState != 15 || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || CurrentLevel >= LevelIDs_SSGarden)
			return;
		if (NoClip_Timer <= 800 && NoClip_Timer != 0)
		{
			NoClip_Timer--;
			if (NoClip_Timer == 1 && NoClip_Timer != 0)
			{
				WriteData((int*)0x00444C1D, (int)0xFF37EEE8);
				WriteData((int*)0x00444C21, (int)0x10C483FF);
				WriteData((int*)0x0044A66B, (int)0xFFA430E8);
				WriteData((int*)0x0044A66F, (int)0x14C483FF);
				WriteData((int*)0x007887D9, (int)0x00D042E8);
				WriteData((int*)0x007887DD, (int)0x74C08500);
				NoClip_Timer = 0;
				PrintDebug("Walk Thru Walls Disabled\n");
				strcpy_s(LastEffect, 128, "Walk Thru Walls Disabled");
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
			PrintDebug("Input Set to Default\n");
			strcpy_s(LastEffect, 128, "Input Set to Default");
		}

		if (Gravity_Timer <= 1000 && Gravity_Timer != 0)
		{
			Gravity_Timer--;
		}
		if (Gravity_Timer == 1 && Gravity_Timer != 0)
		{
			ResetGravity();
			Gravity_Timer = 0;
			PrintDebug("Y Gravity Reset\n");
			strcpy_s(LastEffect, 128, "Y Gravity Reset");
		}

		if (DebugToScreen == true)
		{
			SetDebugFontSize(15);
			SetDebugFontColor(0xFFFFFFFF);
			DrawDebugRectangle(0.30f, 7.90f, 17.9f, 6.2f);
			DisplayDebugStringFormatted(NJM_LOCATION(0, 7), " %s", LastEffect);
		}

		if (DisableControl_Timer <= 90 && DisableControl_Timer != 0)
		{
			DisableControl_Timer--;
		}
		if (DisableControl_Timer == 1 && DisableControl_Timer != 0)
		{
			ControlEnabled = 1;
			DisableControl_Timer = 0;
			PrintDebug("Control Enabled\n");
			strcpy_s(LastEffect, 128, "Control Enabled");
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
			KillPlayer(0);
			DPadDown_Timer = 0;
			PrintDebug("Failed Dpad Down Or Die Check\n");
		}
		if (Pause_Timer <= 5 && Pause_Timer != 0)
		{
			GameState = 16;
			Pause_Timer--;
		}
		if (GameState < 15 || GameState > 16)
		{
			if (AnimalTextLoader == true)
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
			}
		}
		if (SnowboardTimer <= 500 && SnowboardTimer != 0)
		{
			SnowboardTimer--;
		}
		if (SnowboardTimer == 1 && SnowboardTimer <= 2 && IssSowboarding == 1)
		{
			SnowboardTimer = 0;
			IssSowboarding = 0;
			EntityData1Ptrs[0]->Action = 1;
			PrintDebug("Snowboard off, Action Set\n");
			strcpy_s(LastEffect, 128, "Snowboard Off");

		}
		if (FastAccel_Timer <= 400 && FastAccel_Timer != 0)
		{
			FastAccel_Timer--;
		}
		if (FastAccel_Timer <= 2 && FastAccel_Timer != 0)
		{
			CharObj2Ptrs[0]->PhysicsData.MaxAccel = 3.0f;
			CharObj2Ptrs[0]->PhysicsData.AirAccel = 0.03099999949f;
			CharObj2Ptrs[0]->PhysicsData.HangTime = 60;
			strcpy_s(LastEffect, 128, "Fast Accel Disabled");
			PrintDebug("Fast Accel Disabled\n");
		}
		if (Debug_Timer < 333 && Debug_Timer != 0)
		{
			Debug_Timer--;
		}
		if (Debug_Timer <= 2 && Debug_Timer != 0)
		{

			EntityData1Ptrs[0]->Action = 1;
			PrintDebug("Debug turned Off, Default Action Set\n");
			strcpy_s(LastEffect, 128, "Debug Off");
			Debug_Timer = 0;
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
		if (Controllers[0].PressedButtons & Buttons_Y) //checks if Y is pressed
		{
			RandomPhysics();
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}