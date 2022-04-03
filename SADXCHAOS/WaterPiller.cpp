#include "pch.h"
task* p_SplashTask;
task* p_PillarTask;
task* p_WaterPillarTask;
void TaskEmptySub(task*)
{
}
void ___njSetTexture(NJS_TEXLIST* texlist)
{
	njds_texList = texlist;
	njds_texNum = 0;
	njSetTexture(texlist);
}
void __cdecl dispSplashTask(task* tp)
{
		___njSetTexture(&texlist_l_sibuki);
		njPushMatrix(0);
		njTranslateV(0, &tp->twp->pos);
		njScaleV(0, &tp->twp->scl);
		njPopMatrix(1);
}
void __cdecl destTaskGeneric(task* tp)
{
	if (tp->twp->value.ptr)
	{
		FreeMemory(tp->twp->value.ptr);
	}
}
void __cdecl execSplashTask(task* tp)
{
	taskwk* twp;
	twp = tp->twp;
	switch (twp->mode) {
	case 0:
		twp->mode = 1;
		break;
	case 1:
		twp->counter.f = twp->timer.f + twp->counter.f;
		if (twp->counter.f >= action_l_sibuki.motion->nbFrame)
		{
			twp->mode = 2;
		}
		break;
	case 2:
		FreeTask(tp);
		p_SplashTask = 0;
		break;
	default:
		break;
	}
	dispSplashTask(tp);
}
void __cdecl initSplashTask(task* tp)
{
	tp->exec = execSplashTask;
	tp->disp = dispSplashTask;
	tp->dest = TaskEmptySub;
}
void __cdecl createSplashTask(float pos_x, float pos_y, float pos_z, float play_spd, float scale)
{
	taskwk* twp;
	p_SplashTask = CreateElementalTask(2, 5, initSplashTask);
	twp = p_SplashTask->twp;
	twp->pos.x = pos_x;
	twp->pos.y = pos_y;
	twp->pos.z = pos_z;
	twp->scl.y = scale;
	twp->mode = 0;
	twp->scl.x = scale;
	twp->scl.z = scale;
	twp->timer.f = play_spd;
	twp->counter.f = 0.0f;
}
void __cdecl dispWaveTask_WP(task* tp)
{
	taskwk* twp;
	twp = tp->twp;
	___njSetTexture(&texlist_l_sibuki);
	njPushMatrix(0);
	njTranslateV(0, &twp->pos);
	njScaleV(0, &twp->scl);
	late_ActionClipEx(&action_l_circle, twp->counter.f, 0, VectorMaxAbs(&twp->scl));
	njPopMatrix(1);
}
void __cdecl execWaveTask_WP(task* tp)
{
	taskwk* twp;
	twp = tp->twp;
	switch (twp->mode) {
	case 0:
		twp->mode = 1;
		break;
	case 1:
		twp->counter.f = twp->timer.f + twp->counter.f;
		if (twp->counter.f >= action_l_circle.motion->nbFrame)
		{
			twp->mode = 2;
		}
		break;
	case 2:
		FreeTask(tp);
		break;
	default:
		break;
	}
	dispWaveTask_WP(tp);
}
void __cdecl initWaveTask_WP(task* tp)
{
	tp->exec = execWaveTask_WP;
	tp->disp = dispWaveTask_WP;
	tp->dest = TaskEmptySub;
}
void __cdecl createWaveTask_WP(float pos_x, float pos_y, float pos_z, float play_spd, float scale)
{
	taskwk* twp;
	twp = CreateElementalTask(2, 5, initWaveTask_WP)->twp;
	twp->pos.x = pos_x;
	twp->pos.y = pos_y;
	twp->pos.z = pos_z;
	twp->scl.y = scale;
	twp->mode = 0;
	twp->scl.x = scale;
	twp->scl.z = scale;
	twp->timer.f = play_spd;
	twp->counter.f = 0.0f;
}
void __cdecl dispPillarTask(task* tp)
{
	taskwk* twp;
	PillarWork* pillar;
	float scaleX;
	float scaleY;
	float scaleZ;
	float clipScl;
	twp = tp->twp;
	pillar = (PillarWork*)twp->value.ptr;
	___njSetTexture(&texlist_l_sibuki);
	SetMaterial(0.0f, 0.0f, 0.0f, 0.0f);
	njPushMatrix(0);
	njTranslateV(0, &twp->pos);
	njScale(0,
	twp->scl.x * pillar->scl.x,
	pillar->scl.y * twp->scl.y,
	twp->scl.x * pillar->scl.z);
	scaleX = twp->scl.x * pillar->scl.x;
	scaleY = pillar->scl.y * twp->scl.y;
	scaleZ = twp->scl.x * pillar->scl.z;
	if (fabs(scaleX) <= fabs(scaleY) && fabs(scaleY) > fabs(scaleZ))
	{
		clipScl = (float)fabs(scaleY);
	}
	else if (fabs(scaleX) > fabs(scaleZ))
	{
		clipScl = (float)fabs(scaleX);
	}
	else 
	{
		clipScl = (float)fabs(scaleZ);
	}
	late_DrawObjectClipMesh(&objPillar, 0, (float)fabs(clipScl));
	njPopMatrix(1);
	SetMaterial(0.0f, 0.0f, 0.0f, 0.0f);
}
void __cdecl textureUVScroll()
{
	NJS_MODEL* model;
	NJS_TEX* vertuv;
	PillarWork* pillar;
	pillar = (PillarWork*)p_PillarTask->twp->value.ptr;
	model = (NJS_MODEL*)object_l_hasira_l_hasira.child->model;
	vertuv = model->meshsets->vertuv;
	for (int i = 0; i < (2 * model->nbPoint); i++, vertuv++) 
	{
		vertuv->u -= pillar->uvscr_spd;
		vertuv->v += pillar->uvscr_spd;
	}
	model = (NJS_MODEL*)object_l_hasira_l_hasira.child->sibling->model;
	vertuv = model->meshsets->vertuv;
	for (int i = 0; i < (2 * model->nbPoint); i++, vertuv++) 
	{
		vertuv->u += pillar->uvscr_spd / -2;
		vertuv->v += pillar->uvscr_spd / 2;
	}
}
void __cdecl execPillarTask(task* tp)
{
	taskwk* twp;
	PillarWork* pillar;
	twp = tp->twp;
	pillar = (PillarWork*)twp->value.ptr;
	switch (twp->mode)
	{
	case 0:
		twp->mode = 1;
		break;
	case 1:
		textureUVScroll();
		twp->scl.x = pillar->dscl.x + twp->scl.x;
		twp->scl.y = pillar->dscl.y + twp->scl.y;
		twp->scl.z = pillar->dscl.z + twp->scl.z;
		pillar->col.a = pillar->dcol.a + pillar->col.a;
		pillar->col.r = pillar->dcol.r + pillar->col.r;
		pillar->col.g = pillar->dcol.g + pillar->col.g;
		pillar->col.b = pillar->dcol.b + pillar->col.b;
		if (twp->scl.x < 1.0f)
		{
			break;
		}
		twp->scl.x = 1.0f;
		twp->scl.y = 1.0f;
		twp->scl.z = 1.0f;
		pillar->col.a = 1.0f;
		pillar->col.r = 1.0f;
		pillar->col.g = 1.0f;
		pillar->col.b = 1.0f;
		twp->mode = 2;
		break;
	case 2:
		textureUVScroll();
		if (++twp->counter.l <= 75)
		{
			break;
		}
		twp->mode = 3;
		break;
	case 3:
		textureUVScroll();
		twp->scl.x = twp->scl.x - pillar->dscl.x;
		twp->scl.y = twp->scl.y - pillar->dscl.y;
		twp->scl.z = twp->scl.z - pillar->dscl.z;
		pillar->col.a = pillar->col.a - pillar->dcol.a;
		pillar->col.r = pillar->col.r - pillar->dcol.r;
		pillar->col.g = pillar->col.g - pillar->dcol.g;
		pillar->col.b = pillar->col.b - pillar->dcol.b;
		if (twp->scl.x > 0.01f)
		{
			break;
		}
		twp->scl.x = 0.01f;
		twp->scl.y = 0.01f;
		twp->scl.z = 0.01f;
		twp->mode = 4;
		break;
	case 4:
		FreeTask(tp);
		p_PillarTask = 0;
		break;
	default:
		break;
	}
	dispPillarTask(tp);
}
void __cdecl initPillarTask(task* tp)
{
	tp->exec = execPillarTask;
	tp->disp = dispPillarTask;
	tp->dest = destTaskGeneric;
}
void __cdecl createPillar(float pos_x, float pos_y, float pos_z, float play_spd, float scale)
{
	taskwk* twp;
	PillarWork* pillar;
	p_PillarTask = CreateElementalTask(2, 5, initPillarTask);
	pillar = (PillarWork*)MAlloc(0x3C);
	twp = p_PillarTask->twp;
	twp->pos.x = pos_x;
	twp->pos.y = pos_y;
	twp->pos.z = pos_z;
	twp->value.ptr = pillar;
	twp->scl.x = 0.01f;
	twp->scl.z = 0.01f;
	twp->timer.f = play_spd;
	twp->mode = 0;
	twp->counter.l = 0;
	twp->scl.y = 1.0f;
	pillar->scl.x = scale;
	pillar->scl.y = scale;
	pillar->scl.z = scale;
	pillar->dscl.y = 0.0f;
	pillar->dscl.x = (1.0f - twp->scl.x) * twp->timer.f * 0.06666667f;
	pillar->dscl.z = (1.0f - twp->scl.z) * twp->timer.f * 0.06666667f;
	pillar->col.r = 1.0f;
	pillar->col.g = 1.0f;
	pillar->col.b = 1.0f;
	pillar->dcol.a = twp->timer.f * 0.06666667f;
	pillar->dcol.r = 0.0f;
	pillar->dcol.g = 0.0f;
	pillar->dcol.b = 0.0f;
	pillar->col.a = -1.0f;
	pillar->uvscr_spd = 10;
	memcpy(&objPillar, &object_l_hasira_l_hasira, 52u);
}
void __cdecl execWaterPillarTask(task* tp)
{
	taskwk* twp;
	float timer;
	twp = tp->twp;
	switch (twp->mode) {
	case 0:
		//Initial shockwave (broken in SADX)
		createSplashTask(twp->pos.x, twp->pos.y, twp->pos.z, twp->timer.f, twp->scl.x);
		twp->mode = 1;
		break;
	case 1:
		timer = 8.0f / twp->timer.f;
		if (++twp->counter.l == (int)timer)
		{
			//Main pillar body
			createPillar(twp->pos.x, twp->pos.y, twp->pos.z, twp->timer.f, twp->scl.x);
		}
		timer = 1.0f / twp->timer.f;
		if (twp->counter.l >= (unsigned int)(20.0f * timer) && !(twp->counter.l % (unsigned int)(timer * 5.0f)))
		{
			//Animated waves at bottom.
			createWaveTask_WP(twp->pos.x, twp->pos.y, twp->pos.z, twp->timer.f, twp->scl.x);
		}
		if (twp->counter.l >= (unsigned int)(60.0f / twp->timer.f))
		{
			twp->mode = 2;
		}
		break;
	case 2:
		FreeTask(tp);
		break;
	default:
		break;
	}
	dispWaveTask_WP(tp);
}
void __cdecl initWaterPillarTask(task* tp)
{
	tp->exec = execWaterPillarTask;
	tp->disp = TaskEmptySub;
	tp->dest = TaskEmptySub;
}
void __cdecl WaterPillarOn(float pos_x, float pos_y, float pos_z, float play_spd, float scale)
{
	taskwk* twp;
	p_WaterPillarTask = CreateElementalTask(2, 5, initWaterPillarTask);
	twp = p_WaterPillarTask->twp;
	twp->pos.x = pos_x;
	twp->pos.y = pos_y;
	twp->pos.z = pos_z;
	twp->scl.y = scale;
	twp->mode = 0;
	twp->scl.x = scale;
	twp->scl.z = scale;
	twp->timer.f = play_spd;
	twp->counter.l = 0;
}
void __cdecl WaterPillarOff()
{
	if (p_WaterPillarTask)
	{
		FreeTask(p_WaterPillarTask);
		p_WaterPillarTask = 0;
	}
}