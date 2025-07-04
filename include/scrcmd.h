#ifndef GUARD_SCRCMD_H
#define GUARD_SCRCMD_H

#include "script.h"

bool8 ScrCmd_callnative(struct ScriptContext *ctx);
typedef void (*NativeFunc)(void);

#endif // GUARD_SCRCMD_H