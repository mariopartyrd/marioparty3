#include "common.h"

f32 _atan2d(f32, f32);
void HuVecNormalize3F(Vec *);
f32 func_8008D800_8E400(f32);
f32 HuVecDot3F(Vec *, Vec *);

f32 MBVecAngleGet(Vec *arg0) {
    f32 temp_f16;

    if (arg0->x != 0.0f || arg0->z != 0.0f) {
        if (arg0->x == 0.0f) {
            if (0.0f < arg0->z) {
                return 0.0f;
            }
            return 180.0f;
        }

        if (arg0->z == 0.0f) {
            if (0.0f < arg0->x) {
                return 90.0f;
            }
            return 270.0f;
        }

        temp_f16 = _atan2d(arg0->z, arg0->x);

        if (arg0->z < 0.0f) {
            temp_f16 = 90.0f - temp_f16;
        } else {
            temp_f16 = 90.0f - temp_f16;
            if (temp_f16 < 0.0f) {
                temp_f16 += 360.0f;
            }
        }
        return temp_f16;
    }

    return -1.0f;
}

void MBVecNormalize(Vec *vec) {
    if ((vec->x == 0.0f) && (vec->y == 0.0f) && (vec->z == 0.0f)) {
        vec->z = 1.0f;
    }

    HuVecNormalize3F(vec);
}

void MBVecRotateX(Vec *arg0, f32 arg1) {
    Vec sp10;

    sp10.y = arg0->y;
    sp10.z = arg0->z;

    arg0->y = ((HuMathCos(arg1) * sp10.y) - (HuMathSin(arg1) * sp10.z));
    arg0->z = ((HuMathCos(arg1) * sp10.z) + (HuMathSin(arg1) * sp10.y));
}

void MBVecRotateY(Vec *arg0, f32 arg1) {
    Vec sp10;

    sp10.x = arg0->x;
    sp10.z = arg0->z;

    arg0->x = ((HuMathCos(arg1) * sp10.x) + (HuMathSin(arg1) * sp10.z));
    arg0->z = ((HuMathCos(arg1) * sp10.z) - (HuMathSin(arg1) * sp10.x));
}

void MBVecRotateZ(Vec *arg0, f32 arg1) {
    Vec sp10;

    sp10.x = arg0->x;
    sp10.y = arg0->y;

    arg0->x = ((HuMathCos(arg1) * sp10.x) - (HuMathSin(arg1) * sp10.y));
    arg0->y = ((HuMathCos(arg1) * sp10.y) + (HuMathSin(arg1) * sp10.x));
}


void func_800D8B2C_EC74C_shared_board(Vec* arg0, Vec* arg1, f32 arg2) {
    Vec origPos;
    f32 temp_f2; //should be fs4
    f32 temp_f3; //should be fs1
    f32 temp_f4; //should be fs2
    f32 temp_f5; //should be fs3
    f32 temp_f0;
    
    // Store original vector
    origPos.x = arg0->x;
    origPos.y = arg0->y;
    origPos.z = arg0->z;
    
    // Normalize the rotation axis
    MBVecNormalize(arg1);

    arg0->x = ((arg1->x * arg1->x + (1.0f - arg1->x * arg1->x) * HuMathCos(arg2)) * origPos.x) +
              ((arg1->x * arg1->y * (1.0f - HuMathCos(arg2)) - HuMathSin(arg2) * arg1->z) * origPos.y) +
              ((arg1->x * arg1->z * (1.0f - HuMathCos(arg2)) + HuMathSin(arg2) * arg1->y) * origPos.z);

    arg0->y = ((arg1->x * arg1->y * (1.0f - HuMathCos(arg2)) + HuMathSin(arg2) * arg1->z) * origPos.x) +
              ((arg1->y * arg1->y + (1.0f - arg1->y * arg1->y) * HuMathCos(arg2)) * origPos.y) +
              ((arg1->y * arg1->z * (1.0f -  HuMathCos(arg2)) - HuMathSin(arg2) * arg1->x) * origPos.z);
    
    arg0->z = ((arg1->x * arg1->z * (1.0f - HuMathCos(arg2)) - HuMathSin(arg2) * arg1->y) * origPos.x) +
              ((arg1->y * arg1->z * (1.0f - HuMathCos(arg2)) + HuMathSin(arg2) * arg1->x) * origPos.y) +
              ((arg1->z * arg1->z + (1.0f - arg1->z * arg1->z) * HuMathCos(arg2)) * origPos.z);
}



#ifdef NON_MATCHING //matches, but nop memes
f32 func_800D8DAC_EC9CC_shared_board(Vec *vec_1, Vec *vec_2) {
    f32 length;
    f32 dot;

    dot = HuVecDot3F(vec_1, vec_2);
    length = HuVecGetLength3F(vec_1) * HuVecGetLength3F(vec_2);
    if (length != 0.0f) {
        return func_8008D800_8E400(dot / length);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EC3B0", func_800D8DAC_EC9CC_shared_board);
#endif