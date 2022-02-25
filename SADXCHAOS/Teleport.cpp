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
std::unordered_map<LevelAndActIDs, std::vector<NJS_VECTOR>> customLocationsMap;
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
	customLocationsMap[LevelAndActIDs_FinalEgg1] =
	{
		{170.0f,-167.0f,490.0f},//sonic act 0 spawn
		{177.9f,-99.4f,-143.9f},//sonic act 0 ontop of life box
		{120.9f,-232.0f,-1248.8f},//sonic act 0 first checkpoint
		{1658.36f,291.88f,-1301.19f},//sonic act 0 ontop of spring
		{985.2f,453.81f,-293.0f},//sonic act 0 before act change
	};
	customLocationsMap[LevelAndActIDs_FinalEgg2] =
	{
		{1060.69f,580.0f,-620.0f}, //sonic act 1 spawn
		{1059.3f,873.0f,-199.92f}, //sonic act 1 speedrun skip
		{845.0f,-850.0f,-967.4f}, //sonic act 1 checkpoint before elevator
		{1060.0f,-1614.8f,-895.4f}, //sonic act 1 in front of elevator
		{899.95f,507.0f,-1142.22f}, //sonic act 1 infront of first speed tunnel
		{1148.2f,4.0f,-618.0f}, //sonic act 1 ontop of spring after first speed tunnel checkpoint
		{981.82f,78.5f,-1152.15f}, //sonic act 1 enterance to second speed tunnel on speedpad
		{1108.45f,-646.52f,-625.10f}, //sonic act 1 end of second speed tunnel on top of spring
	};
	customLocationsMap[LevelAndActIDs_FinalEgg3] =
	{
		{1071.9f,6.06f,-543.2f}, //sonic act 2 just outside of elevator 
		{1210.0f,1.16f,-984.77f}, //sonic act 2 ontop of spring
		{1088.6f,-411.8f,-1740.5f}, //sonic act 2 middle of first gachapon room
		{1380.45f,-265.6f,-1545.2f}, //sonic act 2 checkpoint infront of floating fans
		{2558.98f,-403.52f,-1779.5f}, //sonic act 2 middle of second gachapon room
		{2270.14f,-2999.17f,-1047.92f}, //sonic act 2 ontop of speed shoes at bottom of pit
		{2269.0f,-2666.666f,-876.0f}, //sonic act 2 top of pit after fans
		{2330.9f,-3317.666f,-250.6f}, //sonic act to middle of thrid gachapon room
		{1746.9f,-3317.8f,-703.2f}, //sonic act 2 there the sonic doll would be for gamma
		{1394.2f,-3298.8f,-263.7f}, //sonic act 2 checkpoint near sonic doll as gamma
		{85.58f,-3222.1f,-785.11f}, //sonic act 2 end of level
	};
}
NJS_VECTOR GetRandomCoordinates(LevelAndActIDs levelAndAct)
{
	std::vector<NJS_VECTOR> coordsvector = customLocationsMap[levelAndAct];
	UINT coordsSize = coordsvector.size();
	if (coordsSize == 0)
		return { 0.0f,0.0f,0.0f };
	UINT random = rand() % (coordsSize - 1);
	return coordsvector[random];
}
void RandomTeleport()
{
	if (TeleportEnabled == false)
	{
		NewEffect();
		return;
	}
	NJS_VECTOR RandomTeleport = GetRandomCoordinates((LevelAndActIDs)(GetLevelAndAct()));
	if (RandomTeleport.x == 0.0f && RandomTeleport.y == 0.0f && RandomTeleport.z == 0.0f)
	{
		NewEffect();
		return;
	}
	EntityData1Ptrs[0]->Position = RandomTeleport;
	strcpy_s(LastEffect, 128, "Random Teleport");
}