#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "lib_agenda.h"
#include <locale.h>

using namespace std;

Agenda* agn_cria(Agenda* a){
	return NULL;
}

bool verifica_telefone(char* linha){
	int par = 0;
	for(int i=0; linha[i] != '.'; ++i)
		if(linha[i] == '(')
			par++;
	if(par == 2)
		return true;
	return false;
}

bool verifica_parametros(char* linha){
	if(strstr(linha, "Apt") != NULL){
		return true;
	}
	return false;
}

Agenda* insere_lista(Agenda* agenda, char completo[], char nome[], char sobrenome[], char rua[], char numero[], 
char complemento[], char bairro[], char cidade[], char estado[], char fone1[], char fone2[]){

	Agenda* nova = (Agenda*)malloc(sizeof(Agenda) * 1);
	
	strcpy(nova->completo, completo);
	strcpy(nova->nome, nome);
	strcpy(nova->sobrenome, sobrenome);
	strcpy(nova->rua, rua);
	strcpy(nova->numero, numero);
	strcpy(nova->complemento, complemento);
	strcpy(nova->bairro, bairro);
	strcpy(nova->cidade, cidade);
	strcpy(nova->estado, estado);
	strcpy(nova->fone1, fone1);
	strcpy(nova->fone2, fone2);
	
	nova->prox = agenda;
	return nova;
}

Agenda* agn_adiciona(Agenda* a){
    Agenda* aux = a;
    char nome[20];
	char sobrenome[50];
	char rua[40];
	char numero[8];
	char complemento[10];
	char bairro[20];
	char cidade[30];
	char estado[15];
	char fone1[15];
	char fone2[15];
	char apt[30] = "Apt ";
    
	Agenda* nova = (Agenda*)malloc(sizeof(Agenda) * 1);
    do{
    	printf("Nome: ");
		gets(nome);
	}while(strcmp(nome, "") == 0);
    do{
    	printf("Sobrenome: ");
		gets(sobrenome);
	}while(strcmp(sobrenome, "") == 0);
	do{
    	printf("Rua: ");
		gets(rua);
	}while(strcmp(rua, "") == 0);
	do{
    	printf("Numero: ");
		gets(numero);
	}while(strcmp(numero, "") == 0); 
	printf("Complemento: Apt ");
	gets(complemento);
	if(strcmp(complemento, "") != 0)
		strcat(apt, complemento);
	do{
    	printf("Bairro: ");
		gets(bairro);
	}while(strcmp(bairro, "") == 0);
	do{
    	printf("Cidade: ");
		gets(cidade);
	}while(strcmp(cidade, "") == 0);
	do{
    	printf("Estado: ");
		gets(estado);
	}while(strcmp(estado, "") == 0);
	do{
    	printf("Telefone 1: ");
		gets(fone1);
	}while(strcmp(fone1, "") == 0);
    printf("Telefone 2: ");
	gets(fone2);
	
	strcpy(nova->nome, nome);
	strcpy(nova->sobrenome, sobrenome);
	strcpy(nova->rua, rua);
	strcpy(nova->numero, numero);
	if(strcmp(complemento, "") != 0)
		strcpy(nova->complemento, apt);
	else
		strcpy(nova->complemento, complemento);
	strcpy(nova->bairro, bairro);
	strcpy(nova->cidade, cidade);
	strcpy(nova->estado, estado);
	strcpy(nova->fone1, fone1);
	strcpy(nova->fone2, fone2);
	
    nova->prox = aux;
	return nova;
}

void imprimir(Agenda* a){
	printf("Nome: %s\n", a->nome);
	printf("Sobrenome: %s\n", a->sobrenome);
	printf("Rua: %s\n", a->rua);
	printf("Numero: %s\n", a->numero);
	if(strcmp(a->complemento, "") != 0)
		printf("Complemento: %s\n", a->complemento);
	printf("Bairro: %s\n", a->bairro);
	printf("Cidade: %s\n", a->cidade);
	printf("Estado: %s\n", a->estado);
	printf("Telefone 1: %s\n", a->fone1);
	if(strcmp(a->fone2, "") != 0)
		printf("Telefone 2: %s\n", a->fone2);
}

void agn_busca(Agenda* a){
	setlocale(LC_ALL, "Portuguese");
	Agenda* aux;
	char nome[20] = {};
	scanf("%[^\n]s", nome);
	for(aux = a; aux != NULL; aux = aux->prox){
		if(strcmp(aux->nome, nome) == 0){
			cout << aux->nome << " ";
			cout << aux->sobrenome << "; ";
			cout << aux->rua << "; ";
			cout << aux->numero << "; ";
			cout << aux->complemento << "; ";
			cout << aux->bairro << "; ";
			cout << aux->cidade << ",";
			cout << aux->estado << "; ";
			cout << aux->fone1 << "; ";
			cout << aux->fone2 << ". \n";
		}
	}
}

void agn_detalhe(Agenda* a){
	
	Agenda* aux;
	char busca[100] = {};
	cout << "Digite sua busca: ";
	gets(busca);
	
	for(aux = a; aux != NULL; aux = aux->prox){
		if(strstr(aux->completo, busca) != NULL){
			imprimir(aux);
			Sleep(1000);
		}
	}
}

Agenda* agn_modifica(Agenda* a){
	Agenda* aux;
	
	char nome[20] = {};
	char sobrenome[30] = {};
	char rua[40] = {};
	char numero[8] = {};
	char complemento[10] = {};
	char bairro[20] = {};
	char cidade[30] = {};
	char estado[15] = {};
	char fone1[15] = {};
	char fone2[15] = {};
	
	bool flag = false;
	char buscaNome[20] = {};
	char buscaSobrenome[30] = {};
	printf("Nome: ");
	gets(buscaNome);
	printf("Sobrenome: ");
	gets(buscaSobrenome);
	
	for(aux = a; aux != NULL; aux = aux->prox){
		if( (strcmp(buscaNome, aux->nome) == 0) && (strcmp(buscaSobrenome, aux->sobrenome) == 0)){
			flag = true;
			break;
		}
		flag = false;
	}
	if(flag){
		cout<<"Caso não queira editar um campo determinado, tecle ENTER "<<endl;
		
		cout << "Nome: ";
	    gets(nome);
	    cout << "Sobrenome: ";
	    gets(sobrenome);
	    cout << "Rua: ";
	    gets(rua);
	    cout << "Numero: ";
	    gets(numero);
	    cout << "Complemento: ";
	    gets(complemento);
	    cout << "Bairro: ";
	    gets(bairro);
	    cout << "Cidade: ";
	    gets(cidade);
	    cout << "Estado: ";
	    gets(estado);
	    cout << "Telefone 1: ";
	    gets(fone1);
	    cout << "Telefone 2: ";
	    gets(fone2);
	    
	    if(strcmp(nome, "") != 0)
	    	strcpy(a->nome, nome);
	    if(strcmp(sobrenome, "") != 0)
			strcpy(a->sobrenome, sobrenome);
		if(strcmp(rua, "") != 0)
			strcpy(a->rua, rua);
		if(strcmp(numero, "") != 0)
			strcpy(a->numero, numero);
		if(strcmp(complemento, "") != 0)
			strcpy(a->complemento, complemento);
		if(strcmp(bairro, "") != 0)
			strcpy(a->bairro, bairro);
		if(strcmp(cidade, "") != 0)
			strcpy(a->cidade, cidade);
		if(strcmp(estado, "") != 0)
			strcpy(a->estado, estado);
		if(strcmp(fone1, "") != 0)
			strcpy(a->fone1, fone1);
		if(strcmp(fone2, "") != 0)
		strcpy(a->fone2, fone2);
	
	    a->prox = aux;
	    return a;
	}else
		printf("Não encontrado");
}

Agenda* agn_insere(Agenda* a){
	setlocale(LC_ALL, "Portuguese");
    Agenda* novo = a;
	/** * ** ** *
	 ** Auxiliar*
	 ** * ** ** */
	char linha[300];
	/** * ** ** *
	 ** Agenda **
	 ** * ** ** */
	char nome[20] = {};
	char sobrenome[30] = {};
	char rua[40] = {};
	char numero[8] = {};
	char complemento[10] = {};
	char bairro[20] = {};
	char cidade[30] = {};
	char estado[15] = {};
	char fone1[15] = {};
	char fone2[15] = {};
	char completo[300] = {};
	
	FILE* fp = fopen("agenda2.txt", "r");
	if(fp != NULL){
		while(fgets(linha, 300, fp))
		{
			strcpy(completo, "");
			bool teste = verifica_parametros(linha);
			if(teste)
				sscanf(linha, "%[^ ] %[^;]; %[^;]; %[0-9]; %[^;]; %[^;]; %[^,],%[^;]", nome, sobrenome, rua, numero, complemento, bairro, cidade, estado);
			else{
				sscanf(linha, "%[^ ] %[^;]; %[^;]; %[0-9]; %[^;]; %[^,],%[^;]", nome, sobrenome, rua, numero, bairro, cidade, estado);
				strcpy(complemento, "");
			}
			char* l = strstr(linha, "(");
			teste = verifica_telefone(l);
			if(teste)
				sscanf(l, "%[^;]; %[^.].", fone1, fone2);
			else{
				sscanf(l, "%[^.].", fone1);
				strcpy(fone2, "");
			}
			strcat(completo, strcat(nome, " "));
			strcat(completo, strcat(sobrenome, "; "));
			strcat(completo, strcat(rua, "; "));
			strcat(completo, strcat(numero, "; "));
			if(strcmp(complemento, "") != 0)
				strcat(completo, strcat(complemento, "; "));
			strcat(completo, strcat(bairro, "; "));
			strcat(completo, strcat(cidade, "; "));
			strcat(completo, strcat(estado, "; "));
			strcat(completo, strcat(fone1, "; "));
			if(strcmp(fone2, "") != 0)
				strcat(completo, strcat(fone2, "; "));
			novo = insere_lista(novo, completo, nome, sobrenome, rua, numero, complemento, bairro, cidade, estado, fone1, fone2);
		
		}
	}
	fclose(fp);
	return novo;
}
