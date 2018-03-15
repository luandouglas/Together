typedef struct agenda{
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
	char completo[300];
	struct agenda* prox;
}Agenda;

Agenda* agn_cria(Agenda* a);

Agenda* agn_insere(Agenda* a);

Agenda* agn_adiciona(Agenda* a);

Agenda* agn_modifica(Agenda* a);

void agn_busca(Agenda* a);

void agn_ordena(Agenda* a);

void agn_detalhe(Agenda* a);

void agn_remove(Agenda* a);
