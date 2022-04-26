#pragma once
//XBOX_LIVE_CREATORS_SDK;

#ifdef EXP_STL
#define KRXB_DLL     __declspec(dllexport)
#else
#define KRXB_DLL     __declspec(dllimport)
#endif 

#define KRXB_C_DLL extern "C" __declspec(dllexport)

#ifndef KRXB_BASE
#define KRXB_BASE
typedef KRXB_DLL void (*int_callback_t)(int);

void call_g(int_callback_t callback, int val);

#endif // !KRXB_BASE

