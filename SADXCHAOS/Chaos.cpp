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
//added random physics thanks to MainMemory (https://github.com/MainMemory/SADXPhysicsSwapMod) and Refrag  
//added Decoupple Camera
//added no sound,
//fixed a bug with fast accel
//added Disable Pause
//fixed a few warnings
//added Random Key Block
//added random colors for the random key block, 
//added random emblem.
//fixed a bug with the texture loader resetter 
//added config to disable, disable pause
//Removed OOF from Kill momentum
//updated Effect Table
//Tikal Hint now 20% less likely
//RandomKillMomentum 20% less likly
//changed no_s0und_ to 222 frames from 110 frames
//ghetto fix for Y offset change with Random Phys.
//fix for Debug Scaling thanks to PKR's Debug mod https://github.com/PiKeyAr/sadx-debug-mode/
//fix for debug mod stacking
//added Random Chao Fruit and Chao Hat, thanks to kell and pkr
//changed most spawn things to using tasks, removed creation of setdata for objects that dont need it.
//fixed RandomFallingSpikeBall moving up and down 
//Started Working on Big Ice Cap Rock
//Big IceCap Rock Finished
//AndKnuckles added 
//Made it So Big's Rock can be picked up by others!
//Fixed Random Chao (sorta)
//Fixed Random KeyBlock again,
//Added Config Option to Disabled Spawning of Grab-Able Objects
//Started working on bigCar
//Started Woking on Random X and Z gravity
//Added No Gravity
//Re-Enabled Random Invincibility Random Magnetic Barrier and Random Barrier
//Added Config Option For Gravity Mods
//Added Config Option for Random Physics
//Fixed a bug with Debug Movement
//Fixed a bug with Random Snowboard 
//Fixed Another Bug With Debug Movement
//Todo
//random emblem broke 
//Kill momentum doesn't always work?
//Add &Knuckles Tikal Hint with Short Clip of "&Knuckles" Rap
//Random Remove Powerup (idea from sora) (check current char, and current unlocked powerups and remove a random one)
//boss battles, might be like the hub worlds where enemys being killed can just randomly crash even tho i load all the animal textures?

//gamma hs, ham crashed 7 times, in a row
//seems to be related to gamma locking onto enemys he was never intended to? idk
// random phy crashes? idk man

char oldRand = -1;
int Chaos_Timer = 0;
int Debug_Timer = 0;
int Pause_Timer = 0;
int DPadDown_Timer = 0;
int DpadDown = 0;
int DisableControl_Timer = 0;
int XGravity_Timer = 0;
int YGravity_Timer = 0;
int ZGravity_Timer = 0;
int NoGravityTimer = 0;
Float XGravity = 0;
Float YGravity = 0;
Float ZGravity = 0;
int NoClip_Timer = 0;
int SnowboardTimer = 0;
int IssSowboarding = 0;
int InputInvert_Timer = 0;
int EffectMax = 0;
int FastAccel_Timer = 0;
int Camera_Timer = 0;
int s0und__Timer = 0;
int DisablePause_Timer = 0;
int Animaltyperand = 0;
int EmblemID = 0;
int CurrentLevelOld = -1;
int SaveHash = -1;
int FruitNumb = -1;
int HatNumb = -1;
bool DebugToScreen = false;
bool TeleportEnabled = true;
bool EnemysEnabled = true;
bool InvertEnabled = true;
bool RPauseEnabled = true;
bool PauseDisableEnabled = true;
bool GrabAbleObjectsEnabled = true;
bool GravityChangeEnabled = true;
bool RPhysicsEnabled = true;
char* LastEffect = new char();
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
bool KeyBlockTextLoader = false;
bool ChaooManagerLoader = false;
bool EmblemTextLoader = false;
bool IceTextLoader = false;
bool WindTextLoader = false;
bool ChaoFruitTextLoader = false;
bool ChaoHatTextLoader = false;
bool BigRockTextLoader = false;
bool CarTextLoader = false;
bool ShownMenu = false;
bool TextLoaded = false;
bool DebugEnabled = false;
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

PhysicsData_t PhyData[38]  //credits to MainMemory For this data, https://github.com/MainMemory/SADXPhysicsSwapMod
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
	60,2,32,32,2,0.6,1.66,3,0.11,0.46,1.39,2.3,3.7,5.09,0.076,0.071,0.051,-0.06,-0.22,-0.21,-0.028,-0.01,-0.01,-0.4,-0.125,-0.6,-0.45,0.28,3.5,9,0.08,6,4.5
};

static const char* Physnames[] = {
	"Sonic",
	"Eggman",
	"Tails",
	"Knuckles",
	"Tikal",
	"Amy",
	"Gamma",
	"Big",
	"Super Sonic",
	"Sa2b Sonic",
	"Sa2b Shadow",
	"Sa2b Tails",
	"Sa2b Eggman",
	"Sa2b Knuckles",
	"Sa2b Rouge",
	"Sa2b Mech Tails",
	"Sa2b Mech Eggman",
	"Sa2b Amy",
	"Sa2b Super Sonic",
	"Sa2b Super Shadow",
	"Sa2b Unused",
	"Sa2b Metal Sonic",
	"Sa2b Chao Walker",
	"Sa2b Dark Chao Walker",
	"Sa2b Tikal",
	"Sa2b Chaos",
	"Sa2b Unused2",
	"Sa2b Unused3",
	"Heroes Sonic",
	"Heroes Knuckles",
	"Heroes Tails",
	"Heroes Shadow",
	"Heroes Omega",
	"Heroes Rouge",
	"Heroes Amy",
	"Heroes Big",
	"Heroes Cream",
	"Heroes Espio",
	"Heroes Vector",
	"Heroes Charmy"
};


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

	customLocationsMap[LevelAndActIDs_RedMountain1] =
	{
		{18.208f,32.314f,636.059f}, //sonic act 0 spawn
		{-63.728f,921.607f,106.733f},//spring after rocket
		{-804.800f,1091.28f,-199.402f},//on rock that shoots you foward
		{-3401.674f,152.835f,-1586.210f},//on rock sonic does skip from
		{-3822.46f,1121.60f,-1910.86f}//top of mountain 
	};
}
//beat has bad texture in redmountain? 
void OverRideBigRockTex()
{
	njSetTexture(&OBJ_ICECAP_TEXLIST);
}
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
		PauseDisableEnabled = config->getBool("General", "PauseDisableEnabled", true);
		GrabAbleObjectsEnabled = config->getBool("General", "GrabAbleObjectsEnabled", true);
		GravityChangeEnabled = config->getBool("General", "GravityChangeEnabled", true);
		RPhysicsEnabled = config->getBool("General", "RPhysicsEnabled", true);
		delete config;
		InitializeRandomCoordinates();
		WriteCall((void*)0x4E9423, LoadSnowboardObject);
		WriteCall((void*)0x4E967E, LoadSnowboardObject);
		WriteCall((void*)0x4E9698, LoadSnowboardObject);
		WriteCall((void*)0x597B34, LoadSnowboardObject);
		WriteCall((void*)0x597B46, LoadSnowboardObject);
		WriteCall((void*)0x4EDD17, OverRideBigRockTex);
		WriteJump(Snowboard_Delete, Snowboard_Delete_r);
		WriteData((char*)0x4EE7BB, (char)4);//big ice rock pickup ability
		//WriteData((char*)0x639A00, (char)4);//Patch for Picking Up Car in Station Square Act 0
		WriteData((int*)0x017D0A2C, (int)0xC7C35000);//stops the amy key block from exploding 
		WriteData((int*)0x017D0A38, (int)0xC7C35000);//stops the amy key block from exploding
		WriteData((int*)0x017D0A44, (int)0xC7C35000);//stops the amy key block from exploding
		WriteData((int*)0x017D0A50, (int)0xC7C35000);//stops the amy key block from exploding
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

	void ScaleDebugFont(int scale)//thanks to PkR for this code https://github.com/PiKeyAr/sadx-debug-mode/
	{
		float FontScale;
		if (!EnableFontScaling) FontScale = 1.0f;
		else
		{
			if ((float)HorizontalResolution / (float)VerticalResolution > 1.33f) FontScale = floor((float)VerticalResolution / 480.0f);
			else FontScale = floor((float)HorizontalResolution / 640.0f);
		}
		SetDebugFontSize(FontScale * scale);
	}

	void DrawDebugRectangle(float leftchars, float topchars, float numchars_horz, float numchars_vert)//thanks to PkR for this code https://github.com/PiKeyAr/sadx-debug-mode/
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

	void DisablePausee()
	{
		if (!PauseDisableEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		PauseEnabled = false;
		DisablePause_Timer = 420;
		strcpy_s(LastEffect, 128, "Pause Disabled");
		////PrintDebug("Pause Disabled\n");
	}

	void RandomPhysics()
	{
		if (!RPhysicsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		int Phyrand = rand() % 38;
		int OldYOffset = CharObj2Ptrs[0]->PhysicsData.YOff; //store current Y Offset
		char charname[128];
		strcpy_s(charname, 128, Physnames[Phyrand]);
		char output[128];
		snprintf(output, 128, "%s Physics", charname);
		PhysicsData tmp = (PhysicsData)PhyData[Phyrand];
		memcpy(&CharObj2Ptrs[0]->PhysicsData, &tmp, sizeof(PhysicsData));
		CharObj2Ptrs[0]->PhysicsData.YOff = OldYOffset;//restores Saved Y Offset.
		strcpy_s(LastEffect, 128, output);
	}

	void Nos0und_ForYou()
	{
		PauseSound();
		EnableBGM = 0;
		VoicesEnabled = false;
		WriteData((int*)0x03B29CE0, (int)0xFFFFFFFF);
		strcpy_s(LastEffect, 128, "s0und_ Disabled");
		//PrintDebug("s0und_ Disabled\n");
		s0und__Timer = 222;
	}
	void UncoupleCamera()
	{
		Camera_Data1->Action = 3; //uncouples camera from char
		Camera_Timer = 100;
		strcpy_s(LastEffect, 128, "Camera Detached");
		////PrintDebug("Camera Detached\n");//this was crashing me? lol how
	}

	void RandomEmblem(EntityData1* p1)//updated 10/04/2021 doesnt work still lol get fucked, figured out emblem id but still doesnt work, lol
	{
		if (!EmblemTextLoader)
		{
			LoadPVM("EMBLEM", &EMBLEM_TEXLIST);
			EmblemTextLoader = true;
			TextLoaded = true;
		}
		task* Emblem;
		Emblem = (task*)LoadObject((LoadObj)2, 3, Emblem_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Emblem->ocp = objCondition;
		Emblem->twp->pos = EntityData1Ptrs[0]->Position;
		Emblem->twp->pos.y += rand() % 5 + 3;
		Emblem->twp->pos.z += rand() % 100 + 1 * 9;
		Emblem->twp->ang.x = rand() % 1000;
		Emblem->twp->value.l = 129; //Emblem ID, holy jesus 
		strcpy_s(LastEffect, 128, "Random Emblem");
		return;
		////WriteData((BYTE*)0x03B2B5F6, (BYTE)0x00);//resets the emblem so it can be collected again, sonic emeraldcoast
	}

	void BigRock(EntityData1* p1)
	{
		if (!GrabAbleObjectsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!BigRockTextLoader)
		{
			LoadPVM("OBJ_ICECAP", &OBJ_ICECAP_TEXLIST);
			BigRockTextLoader = true;
			TextLoaded = true;
		}

		task* BigRock;
		BigRock = (task*)LoadObject((LoadObj)3, 3, OBiciwa);
		BigRock->twp->pos = EntityData1Ptrs[0]->Position;
		strcpy_s(LastEffect, 128, "Spawned Big Rock");
		return;
	}

	void BigCar(EntityData1* p1)
	{
		if (!GrabAbleObjectsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!CarTextLoader)
		{
			//LoadPVM("OBJ_ICECAP", &OBJ_ICECAP_TEXLIST);
			CarTextLoader = true;
			TextLoaded = true;
		}

		task* Car;
		Car = (task*)LoadObject((LoadObj)7, 3, ORotyu);
		Car->twp->pos = EntityData1Ptrs[0]->Position;
		strcpy_s(LastEffect, 128, "Spawned Car");
		return;
	}
	void RandomIceKey(EntityData1* p1) // disabled for now 9/23/2021, updated to tasks, still disabled
	{
		if (!GrabAbleObjectsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!IceTextLoader)
		{
			IceTextLoader = true;
		}
		task* IceKey;
		IceKey = (task*)LoadObject((LoadObj)3, 3, IceKey_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		IceKey->ocp = objCondition;
		IceKey->twp->pos = EntityData1Ptrs[0]->Position;
		strcpy_s(LastEffect, 128, "Random IceKey");
		return;
	}
	void RandomWindKey(EntityData1* p1) // disabled for now 9/23/2021, updated to tasks, still disabled
	{
		if (!GrabAbleObjectsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!WindTextLoader)
		{
			LoadPVM("HANDKEY", &RUIN01_TEXLIST);
			WindTextLoader = true;
		}
		task* WindKey;
		WindKey = (task*)LoadObject((LoadObj)3, 3, OHandKey);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		WindKey->ocp = objCondition;
		WindKey->twp->pos = EntityData1Ptrs[0]->Position;
		strcpy_s(LastEffect, 128, "Random IceKey");
		return;
	} // disabled for now 9/23/2021

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
		if (!RinoTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_SAI", &E_SAI_TEXLIST);
			RinoTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* RhinoTank;
		RhinoTank = (task*)LoadObject((LoadObj)2, 3, RhinoTank_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		RhinoTank->ocp = objCondition;
		RhinoTank->twp->pos = EntityData1Ptrs[0]->Position;
		RhinoTank->twp->pos.z += rand() % 10 + 1 * 9;
		if (number)
		{
			RhinoTank = (task*)LoadObject((LoadObj)2, 3, RhinoTank_Main);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			RhinoTank->ocp = objCondition;
			RhinoTank->twp->pos = EntityData1Ptrs[0]->Position;
			RhinoTank->twp->pos.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned RhinoTank");
		return;
	}

	void RandomChaooAnimal()
	{
		Animaltyperand = rand() % 15 - 1;
		return;
	}

	void RandomChaoo()
	{

		if (!ChaooManagerLoader)
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
		//chaodata->data.Type = (ChaoType)chaotype; idk why this wasnt working disabled for now,
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
		//PrintDebug("Random Chao\n");
		strcpy_s(LastEffect, 128, "Spawned Random Chao");
	}

	void RandomFruit(EntityData1* p1)
	{
		if (!GrabAbleObjectsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!ChaoFruitTextLoader)
		{
			LoadPVM("AL_OBJECT", &AL_OBJECT_TEXLIST); //need to change to what ever loads the chao fruit textlist
			TextLoaded = true;
			ChaoFruitTextLoader = true;
		}
		Int FruitType = (rand() % (12 + 1 - 3)) + 3;
		LoadChaoFruit(FruitType, &EntityData1Ptrs[0]->Position, 0, nullptr, nullptr);
		strcpy_s(LastEffect, 128, "Spawned Chao Fruit");
	}

	void RandomHat(EntityData1* p1)
	{
		if (!GrabAbleObjectsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!ChaoHatTextLoader)
		{
			ChaoMain_Constructor();
			TextLoaded = true;
			ChaoHatTextLoader = true;
		}
		if (HatNumb < 10)
		{
			int HatType = rand() % 84 + 1;//chao hat 0-84 rng,
			LoadChaoHat(HatType, &EntityData1Ptrs[0]->Position, 0, nullptr, nullptr);
			strcpy_s(LastEffect, 128, "Spawned Chao Hat");
			HatNumb++;
		}
		if (HatNumb >= 10)
		{
			Chaos_Timer = EffectMax;
			return;
		}
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
		if (!BuyonTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_BUYON", &E_BUYON_TEXLIST);
			BuyonTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* Buyon;
		Buyon = (task*)LoadObject((LoadObj)2, 3, EBuyon);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Buyon->ocp = objCondition;
		Buyon->twp->pos = EntityData1Ptrs[0]->Position;
		Buyon->twp->pos.z += rand() % 10 + 1 * 9;
		if (number)
		{
			Buyon = (task*)LoadObject((LoadObj)2, 3, EBuyon);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			Buyon->ocp = objCondition;
			Buyon->twp->pos = EntityData1Ptrs[0]->Position;
			Buyon->twp->pos.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Buyon");
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
		if (!UnidusTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("UNI_A_UNIBODY", &UNI_A_UNIBODY_TEXLIST);
			LoadPVM("UNI_C_UNIBODY", &UNI_C_UNIBODY_TEXLIST);
			LoadPVM("TOGEBALL_TOGEBALL", &TOGEBALL_TOGEBALL_TEXLIST);
			UnidusTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* Unidus;
		Unidus = (task*)LoadObject((LoadObj)2, 3, UnidusA_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Unidus->ocp = objCondition;
		Unidus->twp->pos = EntityData1Ptrs[0]->Position;
		Unidus->twp->pos.z += rand() % 10 + 1 * 9;
		if (number)
		{
			Unidus = (task*)LoadObject((LoadObj)2, 3, UnidusA_Main);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			Unidus->ocp = objCondition;
			Unidus->twp->pos = EntityData1Ptrs[0]->Position;
			Unidus->twp->pos.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Unidus");
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
		if (!AmebotTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_AMENBO", &E_AMENBO_TEXLIST);
			AmebotTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* Amebot;
		Amebot = (task*)LoadObject((LoadObj)2, 3, Sweep_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Amebot->ocp = objCondition;
		Amebot->twp->pos = EntityData1Ptrs[0]->Position;
		Amebot->twp->pos.z += rand() % 10 + 1 * 9;
		if (number)
		{
			Amebot = (task*)LoadObject((LoadObj)2, 3, Sweep_Load);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			Amebot->ocp = objCondition;
			Amebot->twp->pos = EntityData1Ptrs[0]->Position;
			Amebot->twp->pos.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Amebot");
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
		if (!PoliceTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("NISEPAT", &NISEPAT_TEXLIST);
			PoliceTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* CopSpeeder;
		CopSpeeder = (task*)LoadObject((LoadObj)2, 3, EPolice);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		CopSpeeder->ocp = objCondition;
		CopSpeeder->twp->pos = EntityData1Ptrs[0]->Position;
		CopSpeeder->twp->pos.z += rand() % 10 + 1 * 9;
		if (number)
		{
			CopSpeeder = (task*)LoadObject((LoadObj)2, 3, EPolice);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			CopSpeeder->ocp = objCondition;
			CopSpeeder->twp->pos = EntityData1Ptrs[0]->Position;
			CopSpeeder->twp->pos.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned The Police");
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
		if (!SnakeTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_SNAKE", &E_SNAKE_TEXLIST);
			SnakeTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* Snake;
		Snake = (task*)LoadObject((LoadObj)2, 3, BoaBoa_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Snake->ocp = objCondition;
		Snake->twp->pos = EntityData1Ptrs[0]->Position;
		Snake->twp->pos.z += rand() % 90 + 1 * 9;
		if (number)
		{
			Snake = (task*)LoadObject((LoadObj)2, 3, BoaBoa_Main);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			Snake->ocp = objCondition;
			Snake->twp->pos = EntityData1Ptrs[0]->Position;
			Snake->twp->pos.z += rand() % 90 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Boa-Boa");
		return;
	}
	
	void RandomRobo(EntityData1* p1)//updated to task, untested 10/04/2021
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
		if (!RoboTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_ROBO", &E_ROBO_TEXLIST);
			SnakeTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* Robo;
		Robo = (task*)LoadObject((LoadObj)2, 3, ERobo_0);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Robo->ocp = objCondition;
		Robo->twp->pos = EntityData1Ptrs[0]->Position;
		Robo->twp->pos.z += rand() % 10 + 1 * 9;
		if (number)
		{
			Robo = (task*)LoadObject((LoadObj)2, 3, ERobo_0);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			Robo->ocp = objCondition;
			Robo->twp->pos = EntityData1Ptrs[0]->Position;
			Robo->twp->pos.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Robo");
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
		if (!LeonTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_LEON", &E_LEON_TEXLIST);
			LeonTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* Leon;
		Leon = (task*)LoadObject((LoadObj)2, 3, Leon_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Leon->ocp = objCondition;
		Leon->twp->pos = EntityData1Ptrs[0]->Position;
		Leon->twp->pos.z += rand() % 10 + 1 * 9;
		if (number)
		{
			Leon = (task*)LoadObject((LoadObj)2, 3, Leon_Load);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			Leon->ocp = objCondition;
			Leon->twp->pos = EntityData1Ptrs[0]->Position;
			Leon->twp->pos.z += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Leon");
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
		if (!KikiTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_SARU", &E_SARU_TEXLIST);
			LoadPVM("E_BOMB", &E_BOMB_TEXLIST);
			KikiTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* Kiki;
		Kiki = (task*)LoadObject((LoadObj)2, 3, Kiki_Load);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		Kiki->ocp = objCondition;
		Kiki->twp->pos = EntityData1Ptrs[0]->Position;
		Kiki->twp->pos.z += rand() % 10 + 1 * 9;
		Kiki->twp->pos.y += rand() % 2 + 1 * 9;
		if (number)
		{
			Kiki = (task*)LoadObject((LoadObj)2, 3, Kiki_Load);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			Kiki->ocp = objCondition;
			Kiki->twp->pos = EntityData1Ptrs[0]->Position;
			Kiki->twp->pos.z += rand() % 10 + 1 * 9;
			Kiki->twp->pos.y += rand() % 2 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Kiki");
		return;
	}

	void RandomFallingSpikeBall(EntityData1* p1)
	{
		if (!FSBTextLoader)
		{
			LoadPVM("TOGEBALL_TOGEBALL", &TOGEBALL_TOGEBALL_TEXLIST);
			FSBTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* FallingSpikeBall;
		FallingSpikeBall = (task*)LoadObject((LoadObj)2, 3, FallingSpikeBall_Load);
		FallingSpikeBall->twp->pos = EntityData1Ptrs[0]->Position;
		FallingSpikeBall->twp->pos.z += rand() % 30 + 1 * 9;
		FallingSpikeBall->twp->scl.z = 60;
		FallingSpikeBall->twp->scl.x = 60;
		FallingSpikeBall->twp->scl.y = 1;
		if (number)
		{
			FallingSpikeBall = (task*)LoadObject((LoadObj)2, 3, FallingSpikeBall_Load);
			FallingSpikeBall->twp->pos = EntityData1Ptrs[0]->Position;
			FallingSpikeBall->twp->pos.y += rand() % 30 + 1 * 9;
			FallingSpikeBall->twp->pos.z += rand() % 30 + 1 * 9;
			FallingSpikeBall->twp->scl.z = 60;
			FallingSpikeBall->twp->scl.x = 60;
			FallingSpikeBall->twp->scl.y = 1;
		}
		strcpy_s(LastEffect, 128, "Falling SpikeBall");
		return;
	}
	void RandomSpinnerA(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!SpinnerTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
			SpinnerTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* SpinnerA;
		SpinnerA = (task*)LoadObject((LoadObj)2, 3, SpinnerA_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerA->ocp = objCondition;
		SpinnerA->twp->pos = EntityData1Ptrs[0]->Position;
		SpinnerA->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerA->twp->pos.y += rand() % 2 + 1 * 9;
		if (number)
		{
			SpinnerA = (task*)LoadObject((LoadObj)2, 3, SpinnerA_Main);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			SpinnerA->ocp = objCondition;
			SpinnerA->twp->pos = EntityData1Ptrs[0]->Position;
			SpinnerA->twp->pos.z += rand() % 10 + 1 * 9;
			SpinnerA->twp->pos.y += rand() % 2 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Spinner A");
		return;
	}
	void RandomSpinnerB(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!SpinnerTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
			SpinnerTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* SpinnerB;
		SpinnerB = (task*)LoadObject((LoadObj)2, 3, SpinnerB_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerB->ocp = objCondition;
		SpinnerB->twp->pos = EntityData1Ptrs[0]->Position;
		SpinnerB->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerB->twp->pos.y += rand() % 2 + 1 * 9;
		if (number)
		{
			SpinnerB = (task*)LoadObject((LoadObj)2, 3, SpinnerB_Main);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			SpinnerB->ocp = objCondition;
			SpinnerB->twp->pos = EntityData1Ptrs[0]->Position;
			SpinnerB->twp->pos.z += rand() % 10 + 1 * 9;
			SpinnerB->twp->pos.y += rand() % 2 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Spinner B");
		return;
	}
	void RandomSpinnerC(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!SpinnerTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("SUPI_SUPI", &SUPI_SUPI_TEXLIST);
			SpinnerTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* SpinnerC;
		SpinnerC = (task*)LoadObject((LoadObj)2, 3, SpinnerC_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		SpinnerC->ocp = objCondition;
		SpinnerC->twp->pos = EntityData1Ptrs[0]->Position;
		SpinnerC->twp->pos.z += rand() % 10 + 1 * 9;
		SpinnerC->twp->pos.y += rand() % 2 + 1 * 9;
		if (number)
		{
			SpinnerC = (task*)LoadObject((LoadObj)2, 3, SpinnerC_Main);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			SpinnerC->ocp = objCondition;
			SpinnerC->twp->pos = EntityData1Ptrs[0]->Position;
			SpinnerC->twp->pos.z += rand() % 10 + 1 * 9;
			SpinnerC->twp->pos.y += rand() % 2 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Spinner C");
		return;
	}

	void RandomSman(EntityData1* p1)
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
		if (!SmanTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("E_SNOWMAN", &E_SNOWMAN_TEXLIST);
			LoadNoNamePVM(&stx_ice0_TEXLIST);
			SmanTextLoader = true;
			TextLoaded = true;
		}
		task* ESMAN;
		ESMAN = (task*)LoadObject((LoadObj)2, 3, ESman);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		ESMAN->ocp = objCondition;
		ESMAN->twp->pos = EntityData1Ptrs[0]->Position;
		ESMAN->twp->pos.z += rand() % 10 + 1 * 9;
		ESMAN->twp->pos.y += rand() % 2 + 1 * 9;
		strcpy_s(LastEffect, 128, "Spawned IceBall");
	}
	void RandomEGacha(EntityData1* p1)
	{
		if (!EnemysEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!EGachaTextLoader)
		{
			if (!AnimalTextLoader)
			{
				for (size_t  j = 0; j < LengthOfArray(MinimalPVMs); ++j) {
					LoadPVM(MinimalPVMs[j].Name, MinimalPVMs[j].TexList);
				}
				AnimalTextLoader = true;
			}
			LoadPVM("GACHAPON", &GACHAPON_TEXLIST);
			EGachaTextLoader = true;
			TextLoaded = true;
		}
		int number = rand() % 2;
		task* GACHAPON;
		GACHAPON = (task*)LoadObject((LoadObj)2, 3, OEGacha);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		GACHAPON->ocp = objCondition;
		GACHAPON->twp->pos = EntityData1Ptrs[0]->Position;
		GACHAPON->twp->pos.z += rand() % 10 + 1 * 9;
		GACHAPON->twp->pos.y += rand() % 10 + 1 * 9;
		if (number)
		{
			GACHAPON = (task*)LoadObject((LoadObj)2, 3, OEGacha);
			OBJ_CONDITION* objCondition = new OBJ_CONDITION();
			GACHAPON->ocp = objCondition;
			GACHAPON->twp->pos = EntityData1Ptrs[0]->Position;
			GACHAPON->twp->pos.z += rand() % 30 + 1 * 9;
			GACHAPON->twp->pos.y += rand() % 30 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Beat");
		return;
	}
	void RandomSpring(EntityData1* p1)
	{
		int number = rand() % 2;
		task* Spring;
		Spring = (task*)LoadObject((LoadObj)2, 3, SpringB_Main);
		Spring->twp->pos = EntityData1Ptrs[0]->Position;
		Spring->twp->ang = { rand() % 0x8000, rand() % 0x8000, rand() % 0x8000 };
		Spring->twp->scl.y = rand() % 4 + 1 * 2.5;
		Spring->twp->pos.z += rand() % 10 + 1 * 9;
		Spring->twp->pos.y += rand() % 10 + 1 * 9;
		if (number)
		{
			Spring = (task*)LoadObject((LoadObj)2, 3, SpringB_Main);
			Spring->twp->pos = EntityData1Ptrs[0]->Position;
			Spring->twp->ang = { rand() % 0x8000, rand() % 0x8000, rand() % 0x8000 };
			Spring->twp->scl.y = rand() % 4 + 1 * 2.5;
			Spring->twp->pos.z += rand() % 10 + 1 * 9;
			Spring->twp->pos.y += rand() % 10 + 1 * 9;
		}
		strcpy_s(LastEffect, 128, "Spawned Spring");
		return;
	}

	void RandomCheckPoint(EntityData1* p1)
	{
		task* CheckPoint;
		CheckPoint = (task*)LoadObject((LoadObj)15, 6, CheckPoint_Main);
		OBJ_CONDITION* objCondition = new OBJ_CONDITION();
		CheckPoint->ocp = objCondition;
		CheckPoint->twp->pos = EntityData1Ptrs[0]->Position;
		CheckPoint->twp->ang = PlayerTaskPtr[0]->ang;
		strcpy_s(LastEffect, 128, "Random CheckPoint");
	}

	void RandomSpeedPad(EntityData1* p1)
	{
		int number = rand() % 2;
		task* Speed;
		Speed = (task*)LoadObject((LoadObj)3, 3, DashPanel_Main);
		Speed->twp->scl.x = rand() % 5 + 10 * 2.5;
		Speed->twp->ang.y = rand() % 0x8000;
		Speed->twp->pos = EntityData1Ptrs[0]->Position;
		if (number)
		{
			task* Speed;
			Speed = (task*)LoadObject((LoadObj)3, 3, DashPanel_Main);
			Speed->twp->scl.x = rand() % 5 + 10 * 2.5;
			Speed->twp->ang.y = rand() % 0x8000;
			Speed->twp->pos = EntityData1Ptrs[0]->Position;
		}
		strcpy_s(LastEffect, 128, "Random SpeedPad");
		return;

	}
	void RandomSpikeBall(EntityData1* p1)
	{
		int number = rand() % 2;
		task* spike;
		spike = (task*)LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
		spike->twp->ang.y = rand() % 80 + 1000;
		spike->twp->scl.x = rand() % 5 + 10 * 2.5;
		spike->twp->pos = EntityData1Ptrs[0]->Position;
		spike->twp->pos.y += 2;
		spike->twp->pos.x += 80;
		if (number)
		{
			task* spike;
			spike = (task*)LoadObject((LoadObj)6, 3, SwingSpikeBall_Load);
			spike->twp->ang.y = rand() % 80 + 1000;
			spike->twp->scl.x = rand() % 5 + 10 * 2.5;
			spike->twp->pos = EntityData1Ptrs[0]->Position;
			spike->twp->pos.y += 2;
			spike->twp->pos.x += rand() % 10 + 1 * 9;

		}
		strcpy_s(LastEffect, 128, "Random SpikeBall");
		return;
	}

	void RandomBurgerMan(EntityData1* p1)
	{
		if (!GrabAbleObjectsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!BugerManTextLoader)
		{
			LoadPVM("MI_3DASU", &mi_3dasu_TEXLIST);
			BugerManTextLoader = true;
			TextLoaded = true;
		}
		task* BurgerMan;
		BurgerMan = (task*)LoadObject((LoadObj)3, 3, MissionStatue_Load);
		BurgerMan->twp->pos = EntityData1Ptrs[0]->Position;
		strcpy_s(LastEffect, 128, "Spawned BurgerMan");
		return;
	}

	void RandomKeyBlock(EntityData1* p1)//updated untested
	{
		if (!GrabAbleObjectsEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		if (!KeyBlockTextLoader)
		{
			LoadPVM("HOTSHELTER2", &HOTSHELTER2_TEXLIST);
			KeyBlockTextLoader = true;
			TextLoaded = true;
		}
		task* KeyBlock;
		KeyBlock = (task*)LoadObject((LoadObj)3, 3, OBoxSwitch);
		KeyBlock->twp->pos = EntityData1Ptrs[0]->Position;
		KeyBlock->twp->scl.x = rand() % 3;
		strcpy_s(LastEffect, 128, "Spawned KeyBlock");
		return;
	}
	void RandomKillMomentum(CharObj2* p1) 
	{
		p1->Speed = { 0, 0, 0 };
		strcpy_s(LastEffect, 128, "Killed Momentum");
		//PrintDebug("Kill Momentum\n");
		return;
	}
	void FastAccel(CharObj2* p1)
	{
		FastAccel_Timer = 400;
		CharObj2Ptrs[0]->PhysicsData.MaxAccel = 10.0f;
		CharObj2Ptrs[0]->PhysicsData.AirAccel = 0.10f;
		CharObj2Ptrs[0]->PhysicsData.HangTime = 120;
		strcpy_s(LastEffect, 128, "Fast Accel Enabled");
		//PrintDebug("Fast Accel Enabled\n");
		return;
	}
	void RandomVSpeed(CharObj2* p1) 
	{
		p1->Speed.y = p1->PhysicsData.VSpeedCap;
		strcpy_s(LastEffect, 128, "Random V Speed");
		//PrintDebug("Random V Speed\n");
		return;
	}
	void RandomHSpeed(CharObj2* p1) 
	{
			p1->Speed.x = p1->PhysicsData.HSpeedCap;
			strcpy_s(LastEffect, 128, "Random H Speed");
			//PrintDebug("Random H Speed\n");
			return;
	}
	void RandomHurt() 
	{
		if (Rings > 0)
		{
			HurtCharacter(0);
			strcpy_s(LastEffect, 128, "Hurt");
			return;
		}
		else
		{
			Chaos_Timer = EffectMax;
			return;
		}

	}
	void RandomPowerUP(EntityData1* p1)
	{
		int id = 0;
		if (id < 0 || id > 8) //failsafe
			id = rand() % 9;
		DoThingWithItemBoxPowerupIndex(id);
		//PrintDebug("Random PowerUp\n");
		strcpy_s(LastEffect, 128, "Random PowerUp");
	}
	void MGiantScale(EntityData1* p1) 
	{
		for (int i = 0; i < 21; i++) {
			SONIC_OBJECTS[i]->scl[0] = 4;
			SONIC_OBJECTS[i]->scl[1] = 4;
			SONIC_OBJECTS[i]->scl[2] = 4;
		}
		//PrintDebug("Giant Scale\n");
		return;
	}
	void RandomTimeOfDay() //sets time of day to a random time,
	{
		if (GameMode == GameModes_Adventure_Field)//made it so it only changes if you are in adventure field
		{
			SetTimeOfDay(rand() % 3);
			//PrintDebug("Random Time Of Day\n");
			strcpy_s(LastEffect, 128, "Random Time Of Day");
		}
		else
		{
			//PrintDebug("Not in adventure field\n");
			Chaos_Timer = EffectMax;//forces another Chaos mod if not in Adventure 
		}
	}
	void RandomDroppedRings(EntityData1* p1)
	{
		int randomrings = rand() % 254;
		SpawnDroppedRings(EntityData1Ptrs[0]->Position.x, EntityData1Ptrs[0]->Position.y, EntityData1Ptrs[0]->Position.z, randomrings); //spawns random ammount of rings 0-255 at the player
		Rings = 0;
		//PrintDebug("Random Dropped Rings\n");
		strcpy_s(LastEffect, 128, "Dropped Rings");
	}
	void RandomClipLevel()//currently disabled, may be removed. updated to only change 
	{
			ClipLevel = rand() % 3;
			//PrintDebug("Clip Level Set\n");
	}
	void RandomPause() //randomly pauses the game LOL get good, time
	{
		if (!RPauseEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		Pause_Timer = 5; //how long in frames? to pause unpause?
		//PrintDebug("Random Pause\n");
		strcpy_s(LastEffect, 128, "Random Pause");
	}
	void RandomChar()//works but disabled
	{
		SetCharacter(rand() % 7);
		//PrintDebug("Random Character\n");
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
		//PrintDebug("Camera Swapped\n");
		strcpy_s(LastEffect, 128, "Camera Swapped");
	}
	void RandomDebug() //debug mode currently lasts for 75ish? frames
	{
		if (DebugEnabled)
		{
			Chaos_Timer = EffectMax; //get new chaos effect because debug movement is enabled already
			return;
		}
		if (IssSowboarding == 1)
		{
			Chaos_Timer = EffectMax;
			return;
		}
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
			//PrintDebug("Debug Mode Failed Due to Current Character\n");
			Chaos_Timer = EffectMax;
			return;
		}
		Debug_Timer = 333;
		DebugEnabled = true;
		//PrintDebug("Debug Mode Enabled\n");
		strcpy_s(LastEffect, 128, "Debug Mode Enabled");
	}
	void RandomXGravity()//Updated 11/06/2021, Enabled For Now
	{
		/*if (XGravity_Timer == 0)
		{
			XGravity = Gravity.x;
		}*/
		if (!GravityChangeEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		XGravity_Timer = 1000;
		Gravity.x = (float)rand() / RAND_MAX + (-1.5);
		strcpy_s(LastEffect, 128, "Random X Gravity");
		//PrintDebug("Random X Gravity\n");
	}
	void RandomYGravity()
	{
		/*if (YGravity_Timer == 0)
		{
			YGravity = Gravity.y;
		}*/
		if (!GravityChangeEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		YGravity_Timer = 1000;
		Gravity.y = (float)rand() / RAND_MAX + (-1.5);
		strcpy_s(LastEffect, 128, "Random Y Gravity");
	}
	void RandomZGravity()//Updated 11/06/2021, Enabled For Now
	{
		/*if (ZGravity_Timer == 0)
		{
			ZGravity = Gravity.z;
		}*/
		if (!GravityChangeEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		ZGravity_Timer = 1000;
		Gravity.z = (float)rand() / RAND_MAX + (-1.5);
		strcpy_s(LastEffect, 128, "Random Z Gravity");
		//PrintDebug("Random Z Gravity\n");
	}
	void NoGravity()
	{
		if (!GravityChangeEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
		NoGravityTimer = 400;
		Gravity.x = 0;
		Gravity.y = 0;
		Gravity.z = 0;
		strcpy_s(LastEffect, 128, "Gravity Disabled");
	}
	void RandomBarrier()//Updated 11/06/2021, Enabled For Now
	{
		GiveBarrier(0);
		strcpy_s(LastEffect, 128, "Gave Barrier");
		//PrintDebug("Give Barrier\n");
	}
	void RandomMagneticBarrier()//Updated 11/06/2021, Enabled For Now
	{
		GiveMagneticBarrier(0);
		strcpy_s(LastEffect, 128, "Gave Magnetic Barrier");
		//PrintDebug("Give Magnetic Barrier\n");
	}
	void RandomInvincibility()//Updated 11/06/2021, Enabled For Now
	{
		GiveInvincibility(0);
		strcpy_s(LastEffect, 128, "Gave Invincibility");
		//PrintDebug("Give Invincibility\n");
	}
	void RandomLifePowerup(EntityData1* p1)
	{
		ExtraLifePowerup(0);
		//PrintDebug("Give Extra Life\n");
		strcpy_s(LastEffect, 128, "Extra Life");
	}
	void RandomControlDisable()
	{
		DisableControl_Timer = 90;
		ControlEnabled = 0;
		//PrintDebug("Control Disabled\n");
		strcpy_s(LastEffect, 128, "Control Disabled");
	}
	void MSmallScale(EntityData1* p1)//disabled this
	{
		for (int i = 0; i < 21; i++) {
			SONIC_OBJECTS[i]->scl[0] = 0.5;
			SONIC_OBJECTS[i]->scl[1] = 0.5;
			SONIC_OBJECTS[i]->scl[2] = 0.5;
		}
		//PrintDebug("Small Scale\n");
		strcpy_s(LastEffect, 128, "Small Scale");
		return;
	}

	void AndKnuckles()
	{
		int Knuckles = rand() % 3;
		if (Knuckles == 0)
		{
			PlayVoice(66666);//Custom Knuckles Meme Song Clip,
			strcpy_s(LastEffect, 128, "&Knuckles");
			return;
		}
		else
		{
			Chaos_Timer = EffectMax;
			return;
		}
	}

	void RandomSwapMusic() 
	{
		do {
			CurrentSong = rand() % 125;
		} while (LastSong == CurrentSong);
		LastSong = CurrentSong;
		//PrintDebug("Random Song\n");
		strcpy_s(LastEffect, 128, "Random Song");
		return;
	}

	void ChaosPlayVoice_rng() 
	{
		int Voice = rand() % 2043;
		PlayVoice(Voice);
		//PrintDebug("Random Voice\n");
		strcpy_s(LastEffect, 128, "Random Voice");
		return;
	}
	void RandomDPadDownCheck()
	{
		//enable dpaddown check timer
		DPadDown_Timer = 90; //90 frames?
		DpadDown = 0;
		//PrintDebug("Press Dpad Down Or Die\n");
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
			//PrintDebug("No Random Teleports for this Level/Act, causing new Effect\n");
			Chaos_Timer = EffectMax; //calls a new effect
			return;
		}
		EntityData1Ptrs[0]->Position = RandomTeleport;
		//PrintDebug("Random Teleport\n");
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
		//PrintDebug("Walk Thru Walls Enabled\n");
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
	    //PrintDebug("%i Random Hint\n", hintrand);
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
		//PrintDebug("Input Inverted\n");
		strcpy_s(LastEffect, 128, "Input Inverted");
	}

	Void RandomRotate()
	{
		int Rotaterand = rand() % 65535;
		RotatePlayer(0, Rotaterand);
		//PrintDebug("%i Rotated\n", Rotaterand);
		strcpy_s(LastEffect, 128, "Random Rotation");
	}

	void RandomSnowboard()
	{
		if (DebugEnabled)
		{
			Chaos_Timer = EffectMax;
			return;
		}
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
			
			//PrintDebug("Snowbaord Spawned\n");
			strcpy_s(LastEffect, 128, "Snowboard");
			return;
		}
		else
		{
			Chaos_Timer = EffectMax;//forces another Chaos mod if already on snowboard?
			//PrintDebug("Currently on Snowboard new effect chosen\n");
		}
	}

	ChaosS ChaosArray[82]{

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
	{ RandomKeyBlock, nullptr, nullptr },
	{ RandomKeyBlock, nullptr, nullptr },
	{ RandomFruit, nullptr, nullptr },
	{ RandomHat, nullptr, nullptr },
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
	{ nullptr, nullptr, InputInvert},
	{ nullptr, nullptr, RandomTeleport},
	{ nullptr, nullptr, RandomHurt},
	{ nullptr, nullptr, RandomHurt},
	{ nullptr, nullptr, RandomRotate},
	{ nullptr, nullptr, RandomChaoo},
	{ nullptr, nullptr, RandomPhysics},
	{ nullptr, nullptr, UncoupleCamera},
	{ nullptr, nullptr, Nos0und_ForYou},
	{ nullptr, nullptr, DisablePausee},
	{ nullptr, nullptr, AndKnuckles},
	{ nullptr, nullptr, NoGravity},
	{ nullptr, nullptr, NoGravity},
	{ nullptr, nullptr, RandomBarrier},
	{ nullptr, nullptr, RandomInvincibility},
	{ nullptr, nullptr, RandomMagneticBarrier},
	};

	size_t ChaosSize = LengthOfArray(ChaosArray);
	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SADX
		if (GameState != 15 && GameState != 16 && TextLoaded)
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
			DebugEnabled = false; //@temp.walker may remove
			ChaoFruitTextLoader = false; //@temp.walker may remove
			ChaoHatTextLoader = false;
			BigRockTextLoader = false;
			CarTextLoader = false;
			HatNumb = -1;
		}
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
				//PrintDebug("Walk Thru Walls Disabled\n");
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
			//PrintDebug("Input Set to Default\n");
			strcpy_s(LastEffect, 128, "Input Set to Default");
		}
		if (Camera_Timer <= 100 && Camera_Timer != 0)
		{
			Camera_Timer--;
		}
		if (Camera_Timer == 1 && Camera_Timer != 0)
		{
			Camera_Data1->Action = 2;
			Camera_Timer = 0;
			////PrintDebug("Camera Attached\n");
			strcpy_s(LastEffect, 128, "Camera Attached");
		}
		if (XGravity_Timer <= 1000 && XGravity_Timer != 0)
		{
			XGravity_Timer--;
		}
		if (XGravity_Timer == 1 && XGravity_Timer != 0)
		{
			ResetGravity();
			XGravity_Timer = 0;
			//PrintDebug("X Gravity Reset\n");
			strcpy_s(LastEffect, 128, "X Gravity Reset");
		}
		if (YGravity_Timer <= 1000 && YGravity_Timer != 0)
		{
			YGravity_Timer--;
		}
		if (YGravity_Timer == 1 && YGravity_Timer != 0)
		{
			ResetGravity();
			YGravity_Timer = 0;
			//PrintDebug("Y Gravity Reset\n");
			strcpy_s(LastEffect, 128, "Y Gravity Reset");
		}
		if (ZGravity_Timer <= 1000 && ZGravity_Timer != 0)
		{
			ZGravity_Timer--;
		}
		if (ZGravity_Timer == 1 && ZGravity_Timer != 0)
		{
			ResetGravity();
			ZGravity_Timer = 0;
			//PrintDebug("Z Gravity Reset\n");
			strcpy_s(LastEffect, 128, "Z Gravity Reset");
		}
		if (NoGravityTimer <= 400 && NoGravityTimer != 0)
		{
			NoGravityTimer--;
		}
		if (NoGravityTimer == 1 && NoGravityTimer != 0)
		{
			ResetGravity();
			strcpy_s(LastEffect, 128, "Gravity Restored");
		}
		if (DebugToScreen == true)
		{
			ScaleDebugFont(15);
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
			//PrintDebug("Control Enabled\n");
			strcpy_s(LastEffect, 128, "Control Enabled");
		}

		if (DPadDown_Timer <= 90 && DPadDown_Timer != 0)
		{
			SetDebugFontColor(0xFFFF0000);
			ScaleDebugFont(18);
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
			//PrintDebug("Failed Dpad Down Or Die Check\n");
		}
		if (Pause_Timer <= 5 && Pause_Timer != 0)
		{
			GameState = 16;
			Pause_Timer--;
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
			//PrintDebug("Snowboard off, Action Set\n");
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
			//PrintDebug("Fast Accel Disabled\n");
			FastAccel_Timer = 0;
		}
		if (s0und__Timer <= 222 && s0und__Timer != 0)
		{
			s0und__Timer--;
		}
		if (s0und__Timer == 1 && s0und__Timer != 0)
		{
			ResumeSound();
			EnableBGM = 1;
			VoicesEnabled = true;
			WriteData((int*)0x03B29CE0, (int)0x00000000);
			strcpy_s(LastEffect, 128, "s0und_ Enabled");
			//PrintDebug("s0und_ Enabled\n");
			s0und__Timer = 0;
		}
		if (DisablePause_Timer <= 420 && DisablePause_Timer != 0)
		{
			DisablePause_Timer--;
		}
		if (DisablePause_Timer = 1 && DisablePause_Timer != 0)
		{
			PauseEnabled = true;
			strcpy_s(LastEffect, 128, "Pause Enabled");
			//PrintDebug("Pause Enabled\n");
			DisablePause_Timer = 0;
		}

		if (Debug_Timer <= 333 && Debug_Timer != 0)
		{
			Debug_Timer--;
		}
		if (Debug_Timer <= 2 && Debug_Timer != 0)
		{

			EntityData1Ptrs[0]->Action = 1;
			//PrintDebug("Debug turned Off, Default Action Set\n");
			strcpy_s(LastEffect, 128, "Debug Off");
			Debug_Timer = 0;
			DebugEnabled = false;
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
		if (Controllers[0].PressedButtons & Buttons_Y) //Debug Testing
		{
			RandomPhysics();
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}