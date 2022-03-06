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
void RandomBarrier()//Updated 11/06/2021, Enabled For Now
{
	GiveBarrier(0);
	strcpy_s(LastEffect, 128, "Gave Barrier");
}
void RandomMagneticBarrier()//Updated 11/06/2021, Enabled For Now
{
	GiveMagneticBarrier(0);
	strcpy_s(LastEffect, 128, "Gave Magnetic Barrier");
}
void RandomInvincibility()//Updated 11/06/2021, Enabled For Now
{
	GiveInvincibility(0);
	strcpy_s(LastEffect, 128, "Gave Invincibility");
}
void RandomLifePowerup(taskwk* p1)
{
	ExtraLifePowerup(0);
	strcpy_s(LastEffect, 128, "Extra Life");
}