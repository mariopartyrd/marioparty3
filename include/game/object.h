#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "ultra64.h"
#include "math.h"
#include "process.h"


#define OM_GET_WORK_PTR(object, type) ((type *)(&((object)->work[0])))
#define OM_GET_DATA_PTR(object, type) ((type *)(((object)->data)))

struct om_obj_data;
typedef void (*omObjFunc)(struct om_obj_data *);

typedef struct om_obj_data {
/* 0x00 */ u16 stat;
/* 0x02 */ s16 next_idx_alloc;
/* 0x04 */ s16 prio;
/* 0x06 */ s16 prev;
/* 0x08 */ s16 next;
/* 0x0A */ s16 next_idx;
/* 0x0C */ s16 group;
/* 0x0E */ u16 group_idx;
/* 0x10 */ u32 unk10;
/* 0x14 */ omObjFunc func;
/* 0x18 */ Vec trans;
/* 0x24 */ Vec rot;
/* 0x30 */ Vec scale;
/* 0x3C */ u16 mdlcnt;
/* 0x40 */ s16* model;
/* 0x44 */ u16 mtncnt;
/* 0x48 */ s16* motion;
/* 0x4C */ u32 work[4];
/* 0x5C */ void* data;
} omObjData;

typedef struct Object_s {
/* 0x00 */ struct Object_s *prev;
/* 0x04 */ struct Object_s *next;
/* 0x08 */ u8 unk8;
/* 0x09 */ s8 unk9;
/* 0x0A */ u16 unkA;
/* 0x0C */ Vec coords;
// Three Vec groups (Scale?, Rotation?, Position?)
/* 0x18 */ Vec unk18;
/* 0x24 */ Vec scale;
/* 0x30 */ Vec unk30;
/* 0x3C */ omObjData* omObj1;
/* 0x40 */ omObjData* omObj2;
/* 0x44 */ s16 unk44;
/* 0x46 */ s16 unk46;
} Object; //sizeof 0x48

void omInitObjMan(s16 numOfObjs, s32 numOfPrcs);
void omSetStatBit(omObjData *obj, u16 stat);
s32 omOvlReturnEx(s16 level);
omObjData* omAddObj(s16 prio, u16 mdlcnt, u16 mtncnt, s16 group, omObjFunc func);
Process* omAddPrcObj(process_func func, u16 priority, s32 stackSize, s32 extDataSize);
void omDelPrcObj(s32);
s32 omOvlCallEx(s32 ovlID, s16 event, u16 stat);
void omMain(void);
u16 func_80049F98_4AB98(void);
void func_8004A208_4AE08(void);
void omPrcSetStatBit(Process* prc, s32 stat);
void omOvlGotoEx(s32 ovlID, s16 event, u16 stat);
void omOvlHisChg(s16 level, s32 overlay, s16 event, s16 stat);
void omOvlKill(void);
void omDestroyObjMan(void);
void omPrcSetDestructor(s32, void*);
void omPrcResetStatBit(Process* prc, s32 stat);
void omDelObj(omObjData*);

void omOutView(omObjData* object);
void omOutViewMulti(omObjData* object);

extern f32 CZoomM[];
extern f32 CZoom;
extern Vec CRot;
extern Vec CenterM[];
extern Vec Center;
extern Vec CRotM[];

#endif //_GAME_OBJECT_H
