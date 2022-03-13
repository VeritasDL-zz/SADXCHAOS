#include "pch.h"
#include "Chaos.h"
void RandomBarrier()
{
	GiveBarrier(0);
	strcpy_s(LastEffect, 128, "Gave Barrier");
}
void RandomMagneticBarrier()
{
	GiveMagneticBarrier(0);
	strcpy_s(LastEffect, 128, "Gave Magnetic Barrier");
}
void RandomInvincibility()
{
	GiveInvincibility(0);
	strcpy_s(LastEffect, 128, "Gave Invincibility");
}
void RandomLifePowerup(taskwk* p1)
{
	ExtraLifePowerup(0);
	strcpy_s(LastEffect, 128, "Extra Life");
}