#include <iostream>
#include <windows.h>
#include "lib_agenda.h"
#include <string.h>

using namespace std;
int main()
{
	/*char nome[20] = {};
	scanf("%[^\n]", nome);
	printf("%s", nome);
	
	if(!strcmp(nome, ""))
		printf("JJJ");
	
	puts(nome);
	*/
	Agenda* a;
	a = agn_cria(a);
	a = agn_insere(a);
	agn_busca(a);
	
	return 0;
}
