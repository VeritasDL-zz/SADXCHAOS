#include "pch.h"
Float PlaceX;
Float PlaceZ;
//PlaceInFront Usage
//Set PlaceX to TASK->twp->pos.x; (replace "TASK" with task's name)
//Set PlaceZ to TASK->>twp->pos.z;  (replace "TASK" with task's name)
//do PlaceInFront();
//Set TASK->twp->pos.x to PlaceX; (replace "TASK" with task's name)
//Set TASK->twp->pos.z to PlaceZ; (replace "TASK" with task's name)
void PlaceInFront() //credits to Skoob For this, you the GOAT
{
	double PosOffset = rand() % 25 + (25); //place in front offset rand from 25 to 50 //temp.walker need to test
	PlaceX += PosOffset * sin(-2 * M_PI * ((playertwp[0]->ang.y - 0x4000) & 0xffff) / 65536.0); //Place In Front X
	PlaceZ += PosOffset * sin(2 * M_PI * ((playertwp[0]->ang.y) & 0xffff) / 65536.0); //Place In Front Y
}