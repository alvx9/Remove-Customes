#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//hook function
BOOL Hook(void* pAddr, void* pNAddr, int len = 5);
void wconf();
void conf();
void cconf();
void onf();
char power[128];
DWORD desativar = 0x59FBC5;
DWORD nameReturn = 0x59FBB4;
DWORD original = 0x914490;
DWORD nameReturn2 = 0x478592;
DWORD return2 = 0x59F965;

int remo[] = { 0x0914493 };

DWORD  retorno = 0x41627D;

//DWORD return3 = 0x59F968;
unsigned char dv[] = "ativado";
unsigned char at[] = "desativado";
#endif
