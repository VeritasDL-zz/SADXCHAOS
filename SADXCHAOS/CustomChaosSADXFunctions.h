#pragma once
//most of these are from the xbox360 symbols ported to dx 
//I'll remove them slowly as the modloader programming includes add them
DataPointer(NJS_MOTION**, SS_PEOPLE_MOTIONS, 0x38F6EA4);
FunctionPointer(void, effect_create2, (task* obj, int ef_num, float ef_x, float ef_y, float ef_z, NJS_TEXLIST* ef_name), 0x6ED770);
FunctionPointer(void, effect_scl, (int ef_num, float sx, float sy), 0x6ED8E0);
FunctionPointer(void, effect_color, (__int16 ef_num, float col_a, float col_r, float col_g, float col_b), 0x6ED910);
FunctionPointer(void, effect_delete, (__int16 ef_num), 0x6ED490);
FunctionPointer(void, EmeraldShard_Create, (int num), 0x6F53B0);
ObjectFunc(KnuEffectRingSpring, 0x4C1FC0);
ObjectFunc(EnemyAir, 0x4AA340);
FunctionPointer(ObjectMaster*, LoadChaoFruit, (int type, NJS_VECTOR* position, Angle angle, NJS_VECTOR* vector, void* savedata), 0x722DE0);
FunctionPointer(ObjectMaster*, LoadChaoHat, (int type, NJS_VECTOR* position, Angle angle, NJS_VECTOR* vector, void* savedata), 0x7236F0);
VoidFunc(PauseSound, 0x40D060);
FunctionPointer(void, KillPlayer, (uint8_t ID), 0x440CD0);
VoidFunc(ResumeSound, 0x40D0A0);
FunctionPointer(ObjectMaster*, LoadAutoHint, (const HintText_Text* texts, int voice), 0x7A1BE0);
ObjectFunc(dummytarget_init, 0x5B60D0);
DataPointer(NJS_TEXLIST, ev_effect_list19, 0x2C49740);
//01FF86C4     texlist_tate_chg
DataPointer(NJS_TEXLIST, texlist_tate_chg, 0x01FF86C4);
