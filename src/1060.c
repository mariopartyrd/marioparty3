#include "common.h"
#include "PR/os.h"

extern void func_800354A0_360A0(void* arg);

extern OSThread gInitThread;
extern u8 gThread1Stack[];
extern OSThread gMainThread;
extern u64* gThread3Stack;

void ultraMain(void);
void thread1_idle(void *arg);

void __osInitialize_common(void);
void __osInitialize_autodetect(void);
void InitSchedulerEvent(void);
void func_800357AC_363AC(s32);

void ultraMain() {
    __osInitialize_common();
    __osInitialize_autodetect();
    InitSchedulerEvent();
    func_800357AC_363AC(3);
    osCreateThread(&gInitThread, 1, &thread1_idle, NULL, &gThread1Stack[2048], 10);
    osStartThread(&gInitThread);
}

void thread1_idle(void* arg) {
    osCreateThread(&gMainThread, 3, &func_800354A0_360A0, arg, &gThread3Stack, 2);
    osStartThread(&gMainThread);
    osSetIntMask(0x3FFF01);
    osSetThreadPri(NULL, 0);

    // idle forever
    while (1) {}
}
