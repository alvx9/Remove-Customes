#include "pch.h"


// CHAMAR A FUNÇÃO nameKey 

void nameKey() {
	GetPrivateProfileStringA("efeito", "fantasia", "", power, 128, ".\\efeito.ini"); // arquivo .ini 
}
__declspec(naked) void wwconf() // funções de acordo com se tá ativado ou desativado!
{
	_asm
	{
		
		pushad
		call nameKey // chamar o efeito.ini
		popad

		pushad
		mov al,[power] // mover os bytes de power para al 
		cmp al, dv // comparar se estão ativados 
		popad
		je exit2 // permanecer ativado

		pushad
		cmp al, at // comparar se a fantasia está ligada movendo para al 
		popad
		mov byte ptr[original], 0x0000 // mover o type id 150 para 0
		mov[ebx + 0x0914484], al // carrega equipamentos quando equipa
		cmp [ebx + 0x0914484],0x96 // se o equipamento for de type 150 
		je remove2 // então remova e adicione 0
		jmp nameReturn // retorne para a função


		remove2:
		push ebx
			mov ebx,0x0000
		mov byte ptr[ebx + 0x0914493], 0x0000
			pop ebx
			jmp nameReturn


				exit2:
			mov[ebx + 0x0914484], al
			jmp nameReturn

			
 }
}




__declspec(naked) void wwwconf()
{
	_asm
	{

		pushad
		call nameKey // chamar o efeito.ini
		popad
		
		pushad
		mov al,[power] // mover os bytes de power para al 
		cmp al, dv
		popad
		je exit3


		pushad
		cmp al, at
		popad
		je enb

		enb :
		push ebx
			mov ebx,0x0000
		mov [ebx + 0x0914490], 0x000
			pop ebx
			jmp nameReturn2

			exit3 :
		push ebx
			mov ebx,0x0000
		mov [ebx + 0x0914490], edx
			pop ebx
			jmp nameReturn2

		

			



	}
}

_declspec(naked) void onff()
{
	_asm
	{
  //  DESATIVAR MODELO / FANTASIA QUANDO PASSAR DE PORTAL OU USAR RUNA
		pushad
		call nameKey
		popad

		pushad
		mov bl, [power]
		cmp bl, at
		popad
		je tirar

		pushad
		mov bl, [power]
		cmp bl, dv
		popad
		je org

		org:
		mov[esi + 0x00000AC], 00000001 // 01 = EQUIPOU FANTASIA
			jmp retorno

		tirar:
		mov[esi + 0x00000AC], 0x0000000 // 00 = SEM FANTASIA
			jmp retorno

	}
}

__declspec(naked) void conff()
{
	_asm
	{
		pushad
		call nameKey 
		popad
		pushad
		mov bl, byte ptr[power]
		cmp bl, dv
		popad
		je exitt
		pushad
		cmp bl , at
		popad
		je desativar2

		desativar2:
		nop
		jmp return2

		exitt:
		movzx ax, byte ptr[eax + 0x000A]
		jmp return2
		    
	}
};




void wconf() {
	Hook((void*)0x59FBAE, wwconf, 6);
}


void conf() {
	Hook((void*)0x47858C, wwwconf, 6);
}


void cconf() {
	Hook((void*)0x59F960, conff, 5);
}


void onf() {
	Hook((void*)0x416273, onff, 10);
}
