#include "pch.h"
task* p_ScanLineTask;
int base_pos;
enum MODE
{
    MODE_WAIT,
    MODE_TEST
};
void __cdecl deleteScanLine()
{
    if (p_ScanLineTask)
    {
        FreeTask(p_ScanLineTask);
        p_ScanLineTask = 0;
    }
}
void __cdecl dispScanLine_sub(task* tp)
{
    NJS_COLOR color[2]{};
    NJS_POINT2 ptr[2]{};
    NJS_POINT2COL p{};
    float base;
    ScanLineWork* scanline;
    scanline = (ScanLineWork*)tp->twp->value.ptr;
    p.p = ptr;
    p.col = color;
    p.tex = 0;
    p.num = 2;
    ResetMaterial();
    ___njColorBlendingMode(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    ___njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
    base = (float)base_pos;
    for (int i = base_pos; base < ScreenRaitoY * 480.0f; base = (float)i)
    {
        p.p->x = 0.0;
        p.p->y = base;
        p.col->argb.a = scanline->line_col.argb.a;
        p.col->argb.r = scanline->line_col.argb.r;
        p.col->argb.g = scanline->line_col.argb.g;
        p.col->argb.b = scanline->line_col.argb.b;
        p.p[1].x = ScreenRaitoX * 640.0f;
        p.p[1].y = base;
        p.col[1].argb.a = scanline->line_col.argb.a;
        p.col[1].argb.r = scanline->line_col.argb.r;
        p.col[1].argb.g = scanline->line_col.argb.g;
        p.col[1].argb.b = scanline->line_col.argb.b;
        njDrawLine2D(&p, 1, -1.0f, 0x40u);
        i += scanline->res + 1;
    }
}
void __cdecl dispScanLineTask(task* tp)
{
    ScanLineWork* scanline;
    scanline = (ScanLineWork*)tp->twp->value.ptr;
    if (MODE_TEST)
    {
        if (++base_pos == scanline->res)
        {
            base_pos = 0;
        }
        late_SetFunc((void(__cdecl*)(void*))dispScanLine_sub, tp, 22048.0f, 4);
    }
}
void __cdecl execScanLineTask(task* tp)
{
    dispScanLineTask(tp);
}
void __cdecl initScanLineTask(task* tp)
{
    tp->exec = execScanLineTask;
    tp->disp = dispScanLineTask;
    tp->dest = destTaskGeneric;
}
void RandomScanLine()
{
    createScanLine(128, 0, 80, 85, 5);
}
void __cdecl createScanLine(unsigned __int8 a, unsigned __int8 r, unsigned __int8 g, unsigned __int8 b, int res)
{
    if (!RandomScanLineEnabled)
    {
        NewEffect();
        return;
    }
    if (ScanLine_Timer != 0)
    {
        NewEffect();
        return;
    }
    strcpy_s(LastEffect, 128, "Random ScanLines");
    ScanLineWork* scanline;
    p_ScanLineTask = CreateElementalTask(2u, 5, initScanLineTask);
    scanline = (ScanLineWork*)MAlloc(8);
    p_ScanLineTask->twp->value.ptr = scanline;
    p_ScanLineTask->twp->mode = MODE_TEST;
    p_ScanLineTask->twp->counter.l = 0;
    scanline->line_col.argb.a = a;
    scanline->line_col.argb.r = r;
    scanline->line_col.argb.g = g;
    scanline->line_col.argb.b = b;
    scanline->res = res;
    ScanLine_Timer = 333;
}
//Boot
task* p_BootTask;
void __cdecl deleteBoot()
{
    if (p_BootTask)
    {
        FreeTask(p_BootTask);
        p_BootTask = 0;
    }
}
void __cdecl dispSandStorm(task* tp) {
    float x;
    float y;
    BootWork* boot;
    boot = (BootWork*)tp->twp->value.ptr;
    late_DrawBoxFill2D(0.0f, 0.0f, ScreenRaitoX * 640.0f, ScreenRaitoY * 480.0f, 22046.801f, boot->backGroundAlpha << 24, 4);
    for (int i = 0; i < 1000; i++) {
        x = (float)(rand() * 0.000030517578f * (ScreenRaitoX * 640.0f));
        y = (float)(rand() * 0.000030517578f * (ScreenRaitoY * 480.0f));
        late_DrawBoxFill2D(x, y, x + 1.0f, y + 1.0f, 22047.0f, (boot->backGroundAlpha << 24) | 0xFFFFFF, 4);
    }
}
void __cdecl dispBootTask(task* tp)
{
    taskwk* twp;
    unsigned int timer;
    twp = tp->twp;
    switch (twp->mode)
    {
    case 0:
        late_DrawBoxFill2D(0.0f, 0.0f, ScreenRaitoX * 640.0f, ScreenRaitoY * 480.0f, 22046.801f, 0xFF000000, 4);
        break;
    case 1:
        timer = twp->counter.l % 60u;
        if (timer >= 15 && timer <= 20 || timer >= 50 && timer <= 53) //Blinking at the beginning.
        {
            dispSandStorm(tp);
            return;
        }
        late_DrawBoxFill2D(0.0f, 0.0f, ScreenRaitoX * 640.0f, ScreenRaitoY * 480.0f, 22046.801f, 0xFF000000, 4);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        dispSandStorm(tp);
        break;
    default:
        return;
    }
}
void __cdecl execBootTask(task* tp)
{
    taskwk* twp;
    BootWork* boot;
    twp = tp->twp;
    boot = (BootWork*)twp->value.ptr;
    ++twp->counter.l;
    switch (twp->mode)
    {
    case 0:
        if (twp->counter.l < boot->wait_frame)
        {
            break;
        }
        twp->mode = 1;
        twp->counter.l = 0;
        dispBootTask(tp);
        return;
    case 1:
        if (twp->counter.l < boot->sstorm_frame)
        {
            break;
        }
        twp->mode = 2;
        twp->counter.l = 0;
        dispBootTask(tp);
        return;
    case 2:
        if (twp->counter.l < boot->poweron_frame)
        {
            boot->backGroundAlpha -= boot->da;
        }
        else
        {
            twp->mode = 3;
            twp->counter.l = 0;
        }
        break;
    case 3:
        if (twp->counter.l >= boot->adjust_frame)
        {
            boot->backGroundAlpha = 0;
            twp->mode = 4;
        }
    case 5:
        if (twp->counter.l >= boot->noise_frame)
        {
            boot->backGroundAlpha = 0;
            twp->mode = 4;
        }
        break;
    default:
        break;
    }
    dispBootTask(tp);
}
void __cdecl initBootTask(task* p_task)
{
    p_task->exec = execBootTask;
    p_task->disp = dispBootTask;
    p_task->dest = destTaskGeneric;
}
void RandomBoot()
{
    createBoot(10, 50, 60, 20);
}
void __cdecl createBoot(int wait_frame, int sstorm_frame, int poweron_frame, int adjust_frame)
{
    if (!RandomBootEnabled)
    {
        NewEffect();
        return;
    }
    if (p_BootTask != 0)
    {
		NewEffect();
		return;
    }
    if (RandomBoot_Timer != 0)
    {
		NewEffect();
		return;
    }
    BootWork* boot;
    p_BootTask = CreateElementalTask(2u, 5, initBootTask);
    boot = (BootWork*)MAlloc(24);
    p_BootTask->twp->value.ptr = boot;
    p_BootTask->twp->mode = 0;
    p_BootTask->twp->counter.l = 0;
    boot->backGroundAlpha = -16;
    boot->da = (unsigned char)(1 - (-112.0f / poweron_frame));
    boot->wait_frame = wait_frame;
    boot->sstorm_frame = sstorm_frame;
    boot->poweron_frame = poweron_frame;
    boot->adjust_frame = adjust_frame;
    RandomBoot_Timer = 200;
}
void __cdecl CreateBootSleep()
{
    BootWork* boot;
    p_BootTask = CreateElementalTask(2u, 5, initBootTask);
    boot = (BootWork*)MAlloc(24);
    p_BootTask->twp->value.ptr = boot;
    p_BootTask->twp->mode = 4;
    p_BootTask->twp->counter.l = 0;
    boot->backGroundAlpha = 0;
}
void __cdecl sandStorm(int frame, int alpha)
{
    BootWork* boot;
    boot = (BootWork*)p_BootTask->twp->value.ptr;
    p_BootTask->twp->mode = 5;
    p_BootTask->twp->counter.l = 0;
    boot->noise_frame = frame;
    boot->backGroundAlpha = alpha;
}