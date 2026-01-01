#pragma once

#include "Logging/LogMacros.h"

class UObject;

LCHFPS_API DECLARE_LOG_CATEGORY_EXTERN(LogLch, Log, All);

LCHFPS_API FString GetClientServerContextString(UObject* ContextObject = nullptr);