#include <stdio.h>
#include <locale.h>
#define MAX 200

int menup(); // prototipos de função e procedimentos
void cadastro();
void pesq();
void impress();
void infoAluno();

struct registro{
	int codigo, ano, estrela, status, numPart;
	char titulo[50], descr[255], gerente[25], referen[126];
};

struct registro projetos[MAX]; // variavel de escopo global para acesso dos procedimentos
int j=0; // variavel de escopo global inicializada para continuar cadastro no numero seguinte 

int main(){
	setlocale(LC_ALL, "Portuguese");
	system("color 1e"); //fundo azul letras amarelas
	int menu1, opt;
	char sair;
	
	do{
		system("color 1e");
		printf("\n********************************************************");
		printf("\n***************** REGISTRO DE PROJETOS *****************");
		printf("\n********************************************************\n\n");
		menu1=menup(opt); // função com retorno de numero inteiro para escolha do menu
		switch (menu1){
			case 1:
				system("cls");
				cadastro(); // procedimento de cadastro de projetos com codigo de cadastro sequencial com opção retomar o cadastro
				break;
			case 2:
				system("cls");
				pesq(); // procedimento para pesquisa de projetos individualmente
				break;
			case 3:
				system("cls");
				impress(); // impressão na tela de nenhum, um ou mais projetos
				break;
			case 4:
				system("cls");
				infoAluno(); // dados academicos ou empresariais
				break;
			case 5:
				system("cls");
				system("color 4f"); // tela vermelha letras brancas
				printf("\nDeseja realmente sair do programa? (s/n)\n\n***ATENÇÃO: OS DADOS CADASTRADOS SERÃO PERDIDOS. OBRIGADO POR PARTICIPAR***\n");
				scanf("%c",&sair);
				fflush(stdin);
				if ((sair=='n')||(sair=='N')){
					system("cls");
				}
				break;
			default:
				system("cls");
				printf("\n\nOpção inválida.\n");
				break;
		}
	}
	while (sair!='s'); 		/* Por algum motivo não consegui utilizar o operador logico de disjunção (ou - ||) 
							para 's' maiusculo. O que estou fazedo errado? (compilador compila, mas não aceita
							 o comando ao inserir s ou S)
							** Comando utilizado sem funcionar: while ((sair!='s')||(sair!='S')); */
	return(0);
}

int menup(int x){
	printf("\n1- Novo/Próximo Cadastro\n2- Pesquisar projetos cadastrados\n3- Impressão na tela\n4- Informações do aluno\n5- Sair\n");
	printf("\nDigite a opção desejada: ");
	scanf("%d", &x);
	fflush(stdin);
	return(x);
}
void cadastro(){
	int i, sair;
	sair=1;
	for (i=j;i<MAX;i++){
		if (sair!=0){
			system("cls");
			projetos[i].codigo=i+1;
			printf("Projeto Nº %d\n", projetos[i].codigo);
			printf("\n\nDigite o titulo do projeto: ");
			scanf("%50[^\n]s", &projetos[i].titulo);
			fflush(stdin);
			printf("\nFaça uma breve descrição do projeto (até 254 caracteres): ");
			scanf("%254[^\n]s", &projetos[i].descr);
			fflush(stdin);
			printf("\nDigite o nome do gerente do projeto: ");
			scanf("%25[^\n]s", &projetos[i].gerente);
			fflush(stdin);
			printf("\nInsira o ano de inicio do projeto: ");
			scanf("%d", &projetos[i].ano);
			fflush(stdin);
			printf("\nInsira o codigo de Status do projeto\n(1- A fazer\n2- Em andamento\n3- Concluido): ");
			scanf("%d", &projetos[i].status);
			fflush(stdin);
			printf("\nDigite o numero de participantes do projeto: ");
			scanf("%d", &projetos[i].numPart);
			fflush(stdin);
			if (projetos[i].status==3){
				printf("\nAvalie este projeto de 1 a 5: ");
				scanf("%d", &projetos[i].estrela);
				fflush(stdin);
			}
			printf("\nInsira uma referencia para o projeto (Bibliografia, website, etc.): ");
			scanf("%126[^\n]s", &projetos[i].referen);
			printf("\n\n***PROJETO CADASTRADO ***\n");
			system("pause");
			system("cls");
			printf("\n\nDigite 1 para continuar cadastrando projetos ou 0 para voltar ao menu principal: ");
			scanf("%d", &sair);
			fflush(stdin);
			system("cls");
			j=i+1; // registro do fim do cadastro. Em caso de novos cadastros, o codigo não irá repetir
		}
	}
}
void pesq(){
	int acha, busca, i, sair, codPesq;
	sair=1;
	while (sair!=0){
		printf("\n\nDigite o codigo do projeto a ser pesquisado: ");
		scanf("%d", &busca);
		fflush(stdin);
		i=0;
		acha=0;
		while ((i<MAX)&&(acha==0)){
			if (projetos[i].codigo==busca){
				acha=1;
			}else{
				i++;
			}
		}
		if (acha==1){
			printf("\nDigite a opção a ser impressa na tela: \n1- Titulo do projeto\n2- Descrição do projeto\n3- Gerente do projeto\n4- Status do projeto\n5- Todas as informações do projeto: ");
			scanf("%d", &codPesq);
			fflush(stdin);
			switch (codPesq){
				case 1:
					printf("\nTitulo: %s\n", projetos[i].titulo);
					break;
				case 2:
					printf("\nDescrição: %s\n", projetos[i].descr);
					break;
				case 3:
					printf("\nGerente: %s\n", projetos[i].gerente);
					break;
				case 4:
					printf("\nStatus: %d\n", projetos[i].status);
					break;
				case 5:
					printf("\nTitulo: %s\nDescrição: %s\nGerente: %s\nAno inicial: %d\nStatus: %d\nNumero de participantes: %d\nReferencias: %s\n", projetos[i].titulo, projetos[i].descr, projetos[i].gerente, projetos[i].ano, projetos[i].status, projetos[i].numPart, projetos[i].referen);
					break;
				default:
					printf("\nOpção inválida!\n");
					break;
			}
		}else{
			printf("\nCódigo inválido.\n");
		}
		system("pause");
		system("cls");
		printf("\nDigite 1 para retornar a pesquisa ou 0 para voltar ao menu principal.\n");
		scanf("%d", &sair);
		fflush(stdin);
		system("cls");
	}
}
void impress(){
	int i, codImp;
	codImp=1;
	while (codImp!=0){
		printf("\nDigite o codigo para selecionar o criterio de impressão: \n1- Todos os projetos\n2- Projetos A fazer\n3- Projetos em andamento\n4- Projetos concluidos\n5- Projetos concluidos com 5 estrelas\n0- Voltar\n");
		scanf("%d", &codImp);
		fflush(stdin);
		switch (codImp){
			case 1:
				for (i=0;i<MAX;i++){
					if (projetos[i].codigo!=0){
						printf("\nTitulo: %s\nDescrição: %s\nGerente: %s\nAno inicial: %d\nStatus: %d\nNumero de participantes: %d\nReferencias: %s\n", projetos[i].titulo, projetos[i].descr, projetos[i].gerente, projetos[i].ano, projetos[i].status, projetos[i].numPart, projetos[i].referen);
					}
				}
				break;
			case 2:
				for (i=0;i<MAX;i++){
					if (projetos[i].status == 1){
						printf("\nTitulo: %s\nDescrição: %s\nGerente: %s\nAno inicial: %d\nStatus: %d\nNumero de participantes: %d\nReferencias: %s\n", projetos[i].titulo, projetos[i].descr, projetos[i].gerente, projetos[i].ano, projetos[i].status, projetos[i].numPart, projetos[i].referen);
					}
				}
				break;
			case 3:
				for (i=0;i<MAX;i++){
					if (projetos[i].status == 2){
						printf("\nTitulo: %s\nDescrição: %s\nGerente: %s\nAno inicial: %d\nStatus: %d\nNumero de participantes: %d\nReferencias: %s\n", projetos[i].titulo, projetos[i].descr, projetos[i].gerente, projetos[i].ano, projetos[i].status, projetos[i].numPart, projetos[i].referen);
					}
				}
				break;
			case 4:
				for (i=0;i<MAX;i++){
					if (projetos[i].status == 3){
						printf("\nTitulo: %s\nDescrição: %s\nGerente: %s\nAno inicial: %d\nStatus: %d\nNumero de participantes: %d\nReferencias: %s\n", projetos[i].titulo, projetos[i].descr, projetos[i].gerente, projetos[i].ano, projetos[i].status, projetos[i].numPart, projetos[i].referen);
					}
				}
				break;
			case 5:
				for (i=0;i<MAX;i++){
					if (projetos[i].estrela == 5){
						printf("\nTitulo: %s\nDescrição: %s\nGerente: %s\nAno inicial: %d\nStatus: %d\nNumero de participantes: %d\nReferencias: %s\n", projetos[i].titulo, projetos[i].descr, projetos[i].gerente, projetos[i].ano, projetos[i].status, projetos[i].numPart, projetos[i].referen);
					}
				}
				break;
			case 0:
				printf("\nRetornando ao menu principal\n");
				system("pause");
				system("cls");
				break;
			default:
				printf("\nOpção inválida!\n");
				system("pause");
				system("cls");
		}
	}
}
void infoAluno(){
	system("color 2f"); // tela verde letras brancas
	char nome[30] = "John Doe";
	char professor[20] = "Jane Doe";
	char discp[40] = "[Editar codigo...]";
	char curso[40] = "[Editar codigo...]";
	int ra = 0000000000;
	int rad = 00;
	printf("\nAluno: %s\nRA: %d-%d\n\nProfessor: %s\n\nDisciplina: %s\n\nCurso: %s\n\n", nome, ra, rad, professor, discp, curso);
	system("pause");
	system("cls");
}
