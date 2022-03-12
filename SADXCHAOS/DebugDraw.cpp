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
bool EnableFontScaling = true;
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
void DebugPrintOutCheck()
{
	if (DebugToScreen)
	{
		ScaleDebugFont(15);
		SetDebugFontColor(0xFFFFFFFF);
		DrawDebugRectangle(0.30f, 7.90f, 17.9f, 6.2f);
		DisplayDebugStringFormatted(NJM_LOCATION(0, 7), " %s", LastEffect);
	}
}