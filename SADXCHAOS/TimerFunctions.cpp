#include "pch.h"
int Chaos_Timer = 0;
int Debug_Timer = 0;
int Pause_Timer = 0;
int DPadDown_Timer = 0;
int DisableControl_Timer = 0;
int XGravity_Timer = 0;
int YGravity_Timer = 0;
int ZGravity_Timer = 0;
int NoGravityTimer = 0;
int NoClip_Timer = 0;
int SnowboardTimer = 0;
int InputInvert_Timer = 0;
int FastAccel_Timer = 0;
int Camera_Timer = 0;
int s0und__Timer = 0;
int DisablePause_Timer = 0;
int RingAllergy_Timer = 0;
int CameraFlip_Timer = 0;
int CameraSpin_Timer = 0;
int CameraSpin_Val = 0;
int DrunkCamera_Timer = 0;
int DrunkCam = 0;
int Direction = 0x50;
int AirCraftSpawerFollow_Timer = 0;
int RandomSpawnAmount = 0;
bool DebugEnabled = false;
int SideWaysCamera_Timer = 0;
int BurgerSpin_Timer = 0;
int Cart_Timer = 0;
int Bl1ngBl0ng = 50;

void ChaosTimer()
{
	if (Chaos_Timer < EffectMax)//30 seconds is 1800
	{
		Chaos_Timer++;
	}
	if (Chaos_Timer >= EffectMax)
	{
		char curRand = 0;
		do {
			curRand = rand() % ChaosSize;
		} while (oldRand == curRand);
		if (ChaosArray[curRand].func != nullptr)
			ChaosArray[curRand].func(playertwp[0]);
		else if (ChaosArray[curRand].func2 != nullptr)
			ChaosArray[curRand].func2(playerpwp[0]);
		else
			ChaosArray[curRand].func3();
		oldRand = curRand;
		Chaos_Timer = 0;
	}
}
void NoClipTimerCheck()
{
	if (NoClip_Timer <= 800 && NoClip_Timer != 0)
	{
		NoClip_Timer--;
	}
	if (NoClip_Timer == 1 && NoClip_Timer != 0)
	{
		WalkThruWallsReset();
		NoClip_Timer = 0;
		strcpy_s(LastEffect, 128, "Walk Thru Walls Disabled");
		return;
	}
}
void InputInvertTimerCheck()
{
	if (InputInvert_Timer <= 420 && InputInvert_Timer != 0)
	{
		InputInvert_Timer--;
	}
	if (InputInvert_Timer == 1 && InputInvert_Timer != 0)
	{
		WriteData<1>((int*)0x40F2A2, 0xF0);
		WriteData<1>((int*)0x40F2A1, 0x2B);
		InputInvert_Timer = 0;
		strcpy_s(LastEffect, 128, "Input Set to Default");
	}
}
void CameraDeattchTimerCheck()
{
	if (Camera_Timer <= 100 && Camera_Timer != 0)
	{
		Camera_Timer--;
	}
	if (Camera_Timer == 1 && Camera_Timer != 0)
	{
		Camera_Data1->Action = 2;
		Camera_Timer = 0;
		strcpy_s(LastEffect, 128, "Camera Attached");
	}
}
void XYZGravityTimerCheck()
{
	if (XGravity_Timer <= 500 && XGravity_Timer != 0)
	{
		XGravity_Timer--;
	}
	if (XGravity_Timer == 1 && XGravity_Timer != 0)
	{
		ResetGravity();
		XGravity_Timer = 0;
		strcpy_s(LastEffect, 128, "X Gravity Reset");
	}
	if (YGravity_Timer <= 500 && YGravity_Timer != 0)
	{
		YGravity_Timer--;
	}
	if (YGravity_Timer == 1 && YGravity_Timer != 0)
	{
		ResetGravity();
		YGravity_Timer = 0;
		strcpy_s(LastEffect, 128, "Y Gravity Reset");
	}
	if (ZGravity_Timer <= 500 && ZGravity_Timer != 0)
	{
		ZGravity_Timer--;
	}
	if (ZGravity_Timer == 1 && ZGravity_Timer != 0)
	{
		ResetGravity();
		ZGravity_Timer = 0;
		strcpy_s(LastEffect, 128, "Z Gravity Reset");
	}
}
void NoGravityTimerCheck()
{
	if (NoGravityTimer <= 400 && NoGravityTimer != 0)
	{
		NoGravityTimer--;
	}
	if (NoGravityTimer == 1 && NoGravityTimer != 0)
	{
		ResetGravity();
		strcpy_s(LastEffect, 128, "Gravity Restored");
	}
}
void DisableControlTimerCheck()
{
	if (DisableControl_Timer <= 90 && DisableControl_Timer != 0)
	{
		DisableControl_Timer--;
	}
	if (DisableControl_Timer == 1 && DisableControl_Timer != 0)
	{
		ControlEnabled = 1;
		DisableControl_Timer = 0;
	}
}
void DpadDownOrDieTimerCheck()
{
	if (DPadDown_Timer <= 90 && DPadDown_Timer != 0)
	{
		SetDebugFontColor(0xFFFF0000);
		ScaleDebugFont(18);
		DisplayDebugString(NJM_LOCATION(15, 0), "- PRESS DPAD DOWN OR DIE!!! -");
		if (ControllerPointers[0]->HeldButtons & Buttons_Down) //Checks if dpad pressed down
		{
			DpadDown = 1; //Sets dpadcheck to 1
		}
		DPadDown_Timer--;
	}
	if (DPadDown_Timer == 1 && DpadDown != 1)//If timer is 1 and DPadDown is not 1 
	{
		KillPlayer(0);
		DPadDown_Timer = 0;
	}
	Veritas = *(DWORD*)Aequitas;
}
void ForcePauseTimerCheck()
{
	if (Pause_Timer <= 5 && Pause_Timer != 0)
	{
		GameState = 16;
		Pause_Timer--;
	}
	GlitchGlider();
}
void SnowBoardTimerCheck()
{
	if (SnowboardTimer <= 500 && SnowboardTimer != 0)
	{
		SnowboardTimer--;
	}
	if (SnowboardTimer == 1 && SnowboardTimer <= 2 && IssSowboarding == 1)
	{
		strcpy_s(LastEffect, 128, "Snowboard Off");
		SnowboardTimer = 0;
		IssSowboarding = 0;
		playertwp[0]->mode = 1;
	}
}
void FastAccelTimerCheck()
{
	if (FastAccel_Timer <= 400 && FastAccel_Timer != 0)
	{
		FastAccel_Timer--;
	}
	if (FastAccel_Timer <= 2 && FastAccel_Timer != 0)
	{
		strcpy_s(LastEffect, 128, "Fast Accel Disabled");
		playerpwp[0]->p.max_x_spd = OldMaxAccel;
		playerpwp[0]->p.air_accel = OldAirAccel;
		playerpwp[0]->p.jump2_timer = OldHangTime;
		FastAccel_Timer = 0;
	}
}
void Nos0und__TimerCheck()
{
	if (s0und__Timer <= 222 && s0und__Timer != 0)
	{
		s0und__Timer--;
	}
	if (s0und__Timer == 1 && s0und__Timer != 0)
	{
		ResumeSound();
		EnableBGM = 1;
		VoicesEnabled = true;
		WriteData((int*)0x03B29CE0, (int)0x00000000);
		strcpy_s(LastEffect, 128, "s0und_ Enabled");
		s0und__Timer = 0;
	}
	if (IsMatthew2837 && Bl1ngBl0ng > 0)
	{
		ScaleDebugFont(30);
		SetDebugFontColor((0x00000001FFFE0030+0x00000000FFFF0218+0x00000000FFFF0818-0x00000002FFFD0A48));
		DisplayDebugStringFormatted(NJM_LOCATION((0x0000000000000006+0x0000000000000203+0x0000000000000803-0x0000000000000A09),(0x000000000000001E+0x000000000000020F+0x000000000000080F-0x0000000000000A2D)), "\x2D"" \124e\x6D""p");
		SetDebugFontColor((0x00000001FFFF4A58+0x00000000FFFFA72C+0x00000000FFFFAD2C-0x00000002FFFEF984));
		DisplayDebugStringFormatted(NJM_LOCATION((0x0000000000000012+0x0000000000000209+0x0000000000000809-0x0000000000000A1B),(0x000000000000001E+0x000000000000020F+0x000000000000080F-0x0000000000000A2D)), "\x57""a\154k\x65""r"); 
		SetDebugFontColor((0x00000001FFFFFE82+0x0000000100000141+0x0000000100000741-0x00000003000007C3));
		DisplayDebugStringFormatted(NJM_LOCATION((0x0000000000000020+0x0000000000000210+0x0000000000000810-0x0000000000000A30),(0x000000000000001E+0x000000000000020F+0x000000000000080F- 0x0000000000000A2D)), "\x49""s"); 
		SetDebugFontColor((0x00000001FE010030+0x00000000FF008218+0x00000000FF008818-0x00000002FD018A48));
		DisplayDebugStringFormatted(NJM_LOCATION((0x0000000000000026+0x0000000000000213+0x0000000000000813-0x0000000000000A39),(0x000000000000001E+0x000000000000020F+0x000000000000080F-0x0000000000000A2D)), "\x41"""); 
		SetDebugFontColor((0x00000001FE0001F2+0x00000000FF0002F9+0x00000000FF0008F9-0x00000002FD000CEB));
		DisplayDebugStringFormatted(NJM_LOCATION((0x000000000000002A+0x0000000000000215+0x0000000000000815-0x0000000000000A3F),(0x000000000000001E+0x000000000000020F+0x000000000000080F-0x0000000000000A2D)), "\x46""u\162r\x79""");
		SetDebugFontColor((0x00000001FF0C00FA+0x00000000FF86027D+0x00000000FF86087D-0x00000002FE920B77));
		DisplayDebugStringFormatted(NJM_LOCATION((0x0000000000000036+0x000000000000021B+0x000000000000081B-0x0000000000000A51),(0x000000000000001E+0x000000000000020F+0x000000000000080F-0x0000000000000A2D)), "\x4C""U\114 \x2D""");
		Bl1ngBl0ng--;
	}
	if (IsMatthew2837 && Bl1ngBl0ng == 0)
	{
		IsMatthew2837 = false;
		Bl1ngBl0ng = ((0x00000000000000C8+0x0000000000000264+0x0000000000000864-0x0000000000000B2C)+(0x0000000000000464+0x0000000000000432+0x0000000000000A32-0x0000000000001096)+(0x0000000000001064+0x0000000000000A32+0x0000000000001032-0x0000000000002296)-(0x000000000000152C+0x0000000000000C96+0x0000000000001296-0x00000000000029C2));
	}
}
void RingAllergyTimerCheck()
{
	if (RingAllergy_Timer <= 250 && RingAllergy_Timer != 0)
	{
		if (Rings != RingCount)
		{
			KillPlayer(0);
			RingCount = 0;
			Rings = 0;
			RingAllergy_Timer = 2; //temp may remove,
		}
		RingAllergy_Timer--;
	}
	if (RingAllergy_Timer == 1 && RingAllergy_Timer != 0)
	{
		RingAllergy_Timer = 0;
	}
}
void PauseDisableTimerCheck()
{
	if (DisablePause_Timer <= 420 && DisablePause_Timer != 0)
	{
		DisablePause_Timer--;
	}
	if (DisablePause_Timer == 1 && DisablePause_Timer != 0)
	{
		strcpy_s(LastEffect, 128, "Pause Enabled");
		PauseEnabled = true;
		DisablePause_Timer = 0;
	}
}
void CustomCameraEffectsTimersCheck()
{
	if (CameraFlip_Timer <= 250 && CameraFlip_Timer != 0)
	{
		CameraFlip_Timer--;//subtract timer
		SetCameraMode_(0);//Force AutoCam
		WriteData((int*)0x03B2C68C, (int)0x8000); //force upside down
	}
	if (CameraFlip_Timer == 1 && CameraFlip_Timer != 0)
	{
		CameraReset();//resets camera ASM
		CameraFlip_Timer = 0;//set timer to 0
		WriteData((int*)0x03B2C68C, (int)0);
	}
	if (CameraSpin_Timer <= 240 && CameraSpin_Timer != 0)
	{
		SetCameraMode_(0);//Force AutoCam
		CameraSpin_Val += 0x300; //spins camera 
		CameraSpin_Timer--;//subtract timer
		WriteData((int*)0x03B2C68C, (int)CameraSpin_Val); //force camera spin
	}
	if (CameraSpin_Timer == 1 && CameraSpin_Timer != 0)
	{
		CameraReset();//resets camera ASM
		CameraSpin_Timer = 0;//set timer to 0 
		CameraSpin_Val = 0;//set spin val to 0 
		WriteData((int*)0x03B2C68C, (int)0);
	}
	if (DrunkCamera_Timer <= 275 && DrunkCamera_Timer != 0)
	{
		SetCameraMode_(0);//Force AutoCam
		CameraNOP();
		DrunkCam = *(int*)0x03B2C68C;
		DrunkCam += Direction;
		if (DrunkCam >= 4269)
		{
			Direction = -0x40;
		}
		else if (DrunkCam <= -4269)
		{
			Direction = +0x40;
		}
		WriteData((int*)0x03B2C68C, (int)DrunkCam); //force camera sway
		DrunkCamera_Timer--;//subtract timer
	}
	if (DrunkCamera_Timer == 1 && DrunkCamera_Timer != 0)
	{
		CameraReset();//resets camera ASM
		DrunkCamera_Timer = 0;//set timer to 0 
		DrunkCam = 0;
		Direction = 0x50;//resets direction 
		WriteData((int*)0x03B2C68C, (int)0x0); //force camera reset
	}
	if (SideWaysCamera_Timer <= 240 && SideWaysCamera_Timer != 0)
	{
		SetCameraMode_(0);//Force AutoCam
		CameraNOP();
		
		if (CameraSide == 0)
		{
			WriteData((int*)0x03B2C68C, (int)-0x4000); //force camera sideways
		}
		if (CameraSide == 1)
		{
			WriteData((int*)0x03B2C68C, (int)0x4000); //force camera sideways
		}
		SideWaysCamera_Timer--;//subtract timer
	}
	if (SideWaysCamera_Timer == 1 && SideWaysCamera_Timer != 0)
	{
		CameraReset();//resets camera ASM
		SideWaysCamera_Timer = 0;//set timer to 0 
		WriteData((int*)0x03B2C68C, (int)0x0); //force camera reset
	}
}
void DebugTimerCheck()
{
	if (Debug_Timer <= 333 && Debug_Timer != 0)
	{
		Debug_Timer--;
	}
	if (Debug_Timer <= 2 && Debug_Timer != 0)
	{
		strcpy_s(LastEffect, 128, "Debug Off");
		playertwp[0]->mode = 1;
		Debug_Timer = 0;
		DebugEnabled = false;
	}
}
void AirCraftSpawnerTimerCheck()
{
	if (AirCraftSpawerFollow_Timer <= 350 && AirCraftSpawerFollow_Timer != 0)
	{
		RandomSpawnAmount = rand() % 50;
		if (RandomSpawnAmount == 0)
		{
			RandomAirCraft(0);
		}
		AirCraftSpawerFollow_Timer--;
	}
	if (AirCraftSpawerFollow_Timer == 1)
	{
		AirCraftSpawerFollow_Timer = 0;
	}
}
void BurgerSpinDeleteTimerCheck() //need to fix
{
	if (BurgerSpin_Timer <= 420 && BurgerSpin_Timer != 0)
	{
		BurgerSpin_Timer--;
	}
	if (BurgerSpin_Timer == 1)
	{
		BurgerManSpinDelete(); //to end the burgerspin
		BurgerSpin_Timer = 0;
	}
}
void CartTimerCheck()
{
	if (Cart_Timer <= 1000 && Cart_Timer != 0)
	{
		Cart_Timer--;
	}
	if (Cart_Timer == 1)
	{
		DeleteCartAndExitPlayer();
		WriteData<1>((void*)0x798306, 0x85); //Jump auto in the cart
		WriteData<1>((void*)0x7983c4, 0x7C); //Jump auto in the cart
		Cart_Timer = 0;
	}
}
void CheckAllEffectsTimer()
{
	NoClipTimerCheck();
	InputInvertTimerCheck();
	CameraDeattchTimerCheck();
	XYZGravityTimerCheck();
	NoGravityTimerCheck();
	DisableControlTimerCheck();
	DpadDownOrDieTimerCheck();
	ForcePauseTimerCheck();
	SnowBoardTimerCheck();
	FastAccelTimerCheck();
	Nos0und__TimerCheck();
	RingAllergyTimerCheck();
	PauseDisableTimerCheck();
	CustomCameraEffectsTimersCheck();
	DebugTimerCheck();
	AirCraftSpawnerTimerCheck();
	BurgerSpinDeleteTimerCheck();
	CartTimerCheck();
}