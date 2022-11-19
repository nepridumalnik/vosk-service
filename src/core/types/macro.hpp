#pragma once

#if defined(_MSC_VER)
//  Microsoft
#define VOSK_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define VOSK_EXPORT __attribute__((visibility("default")))
#else
#define VOSK_EXPORT
#pragma warning Unknown dynamic link import / export semantics.
#endif
