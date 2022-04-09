#pragma once
//ScanLine
FunctionPointer(void, ___njColorBlendingMode, (int, int), 0x004030D0);
DataPointer(float, ScreenRaitoY, 0x8928C4);
DataPointer(float, ScreenRaitoX, 0x8928C0);
FunctionPointer(void, late_DrawBoxFill2D, (float x, float y, float x2, float y2, float pri, unsigned int argb, int flgs), 0x4073B0);
struct ScanLineWork
{
	NJS_COLOR line_col;
	int res;
};
void __cdecl deleteScanLine();
void __cdecl createScanLine(unsigned __int8 a, unsigned __int8 r, unsigned __int8 g, unsigned __int8 b, int res);
//BootEffect
struct BootWork
{
	unsigned __int8 backGroundAlpha;
	unsigned __int8 da;
	unsigned int wait_frame;
	unsigned int sstorm_frame;
	unsigned int poweron_frame;
	unsigned int adjust_frame;
	unsigned int noise_frame;
};
void __cdecl deleteBoot();
void __cdecl createBoot(int wait_frame, int sstorm_frame, int poweron_frame, int adjust_frame);
void RandomScanLine();
void RandomBoot();
void HAHA69();
void LigmaBoss(); 