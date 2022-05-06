#pragma once
void deleteRotaryEmeraldTask();
void BurgerManSpin();
extern int burgerManSpawned;
extern int TestSpawned;
extern task* g_RotaryEmerald_p;
void BurgerManSpinDelete();
extern task* BURGER1;
extern task* BURGER2;
extern task* BURGER3;
extern task* BURGER4;
extern task* BURGER5;
extern task* BURGER6;
extern task* BURGER7;
struct RotaryEmeraldWork
{
	task* eme_task_p[7];
	NJS_POINT3 eme_pos[7];
	NJS_POINT3 eme_spd[7];
	int eme_theta[7];
	int base_theta;
};
