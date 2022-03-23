#include "pch.h"
#include "Chaos.h"
void RandomBarrier()
{
	strcpy_s(LastEffect, 128, "Gave Barrier");
	GiveBarrier(0);
}
void RandomMagneticBarrier()
{
	strcpy_s(LastEffect, 128, "Gave Magnetic Barrier");
	GiveMagneticBarrier(0);
}
void RandomInvincibility()
{
	strcpy_s(LastEffect, 128, "Gave Invincibility");
	GiveInvincibility(0);
}
void RandomLifePowerup(taskwk* p1)
{
	strcpy_s(LastEffect, 128, "Extra Life");
	ExtraLifePowerup(0);
}