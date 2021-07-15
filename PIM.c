/*
Projeto Integrado Multidisciplinar

Integrantes

Nome                        RA
GUILHERME NABARRO LINO - N61956-2
JUAN CARLOS PAGAN - N62712-3
MARCO ANTONIO JORGE CARLOS - F30HED-8
PEDRO HENRIQUE DE JORGE ABREU - N626AB-2
ROGER FERREIRA DE SOUZA - N6220A-5


*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#define Senha 123
#define Login 123
#define ADMSENHA 321
#define ADMLOGIN 321

int autenticacao;

struct tela_de_login{
	int loginAdm;
	int senhaAdm;
	int loginStdin;
	int senhaStdin;
};

struct marcacao_de_unidade{
	char unidade[3];
};

struct menu{
	int sair;
	int opcao;
};

struct cadastro_consulta{
	char horario[5];
	char motivo[200];
	int dia;
	int mes;
	int ano;
	int id;
	char id_convertido[50];
	char cpf_cliente_consulta[50];
};

struct informacoesPessoais{
	
	char cpf[11];
	char rg[10];
	char nome[50];
	char cidade[20];
	char rua[30];
	char numero_resisdencial[6];
	char tipo_sanguineo[4];
	char telefone[12];
	char email[100];
	char data_nascimento[11];
	char bairro[20];
	char salario[8];
	
};

int login(int loginStdin, int senhaStdin);
int loginAdm(int loginAdm, int senhaAdm);
void debugar();
void cadastrarFuncionario();
void reclamacao();
void finalizarConsulta();
void cadastrarCliente();
void marcarConsulta();
void menuAdm();
void faturamentoMensal();
void cadastrarUnidade();
void descadastrarCliente();
void realizarFaturamento();
void cancelarConsulta();
void pesquisarFuncionarios();
void contarCadastros();
void faturamentoDiario();
void mostrarFuncionarios();

int main(){
	
	//Muda a língua para portugues
	setlocale(LC_ALL, "Portuguese");
	
	//A bre as estruturas responsáveis por guardarem as váriáveis relacionadas aos menus e as telas de login 
	struct menu navegar;
	struct tela_de_login logar;
	
	//Gera uma seed aleatória pela função time que modifica a função rand, fazendo que com que ela sempre gere número aleatórios
	srand(time(NULL));
	
	//Faz com que se o usuario tenha logado uma vez ele não precise sempre colocar a senha
	if(autenticacao == 1)
	goto menu;
	
	//Parte do código responsável por autenticar o usuário
	login:
	system("cls");
	printf("############################################################################ Tela de login #############################################################################");
	printf("\n\nDigite o usuário para entrar no sistema\n\n");
	printf("Usuário ->");
	scanf("%d",&logar.loginStdin);
	printf("\nDigite a senha para entrar no sistema\n");
	printf("\nSenha ->");
	scanf("%d",&logar.senhaStdin);
	
	//Chama a função login, se ela retornar algo diferente de 1 o programa não deixa seguir com o código
	if(login(logar.loginStdin,logar.senhaStdin) != 1){
		printf("Usuário ou senha incorretos, voltando para a tela de login\n");
		system("pause");
		goto login;
	}
	
	//Menu da tela inicial
	menu:
	printf("\nUsuário e senhas corretos, iniciando o sistema\n");
	system("pause");
	navegar.sair = 0;

	do{
		system("cls");
		printf("########################################################## Bem vindo ao software da clínica saúde total plus ###########################################################");
		printf("\n############################################################################# Tela inicial #############################################################################");
		printf("\n\nDigite um dos número abaixo para selecionar uma opção\n\n");
		printf("Digite 1 para cadastrar um cliente\n");
		printf("Digite 2 para descadastrar um cliente\n");
		printf("Digite 3 para agendar uma consulta\n");
		printf("Digite 4 para cancelar uma consulta\n");
		printf("Digite 5 para finalizar uma consulta\n");
		printf("Digite 6 para anotar uma reclamação\n");
		printf("Digite 7 para entrar nas opções de admnistrador\n");
		printf("\nOpção digitada -> ");
		//Salva o núemro digitado na estrutura menu na variável opcao
		scanf("%d",&navegar.opcao);
		switch(navegar.opcao){
			case 1:
					//chama primeiro a função debugar para limpar a entrada do teclado
					debugar();
					cadastrarCliente();
					break;
			case 2:
					//chama primeiro a função debugar para limpar a entrada do teclado
					debugar();
					descadastrarCliente();
					break;
			case 3:
					//chama primeiro a função debugar para limpar a entrada do teclado
					debugar();
					marcarConsulta();
					reclamacao();
					break;
			case 4:
					//chama primeiro a função debugar para limpar a entrada do teclado
					debugar();
					cancelarConsulta();
					break;
			case 5:
					//chama primeiro a função debugar para limpar a entrada do teclado
					debugar();
					finalizarConsulta();
					break;
			case 6: 
					//chama primeiro a função debugar para limpar a entrada do teclado
					debugar();
					reclamacao();
					break;
			case 7:
					//chama primeiro a função debugar para limpar a entrada do teclado
					debugar();
					menuAdm();
					break;
			default:
					printf("\nOpção inválida, reiniciando o software ");
					system("pause");
		}
	}while(navegar.sair == 0);
	
	printf("Software desligado, aperte no x para fechar a tela\n");

	return 0;
}

void cadastrarFuncionario(){
	//abre a estrutura que tem as varíaveis referentes ao cadastro
	struct informacoesPessoais funcionario;
	
	int opcao;

	//cria uma variável do tipo arquivo com um ponteiro
    FILE *file;
    system("cls");
    printf("################################################################# TELA DE CADASTRO DO FUNCIONÁRIO ############################################################\n");
  	printf("Digite o CPF do funcionario: ");
  	//Guarda o valor digitado na variavel cpf
	gets(funcionario.cpf);
	//Cria um arquivo com o nome do cpf digitado
	file = fopen(funcionario.cpf, "w");
    
    //Verifica se o arquivo foi aberto corretamente
    if(file == NULL){
    	printf("Erro na abertura do arquivo !");
	}else{
		
		//Parte responsável por receber os dados do funcionário e printar dentro do arquivo
		fprintf(file, "CPF: %s\n",funcionario.cpf);
	    
	    printf("Digite o nome do funcionário: ");
		gets(funcionario.nome);
		fprintf(file, "Nome: %s\n",funcionario.nome);
	
	    printf("Digite o RG: ");
	    gets(funcionario.rg);
	    fprintf(file, "RG: %s\n",funcionario.rg);
	
	    printf("Digite a data de nascimento: ");
	    gets(funcionario.data_nascimento);
	    fprintf(file, "Data de Nascimento: %s\n",funcionario.data_nascimento);
	
	    printf("Digite a cidade do funcionario:");
		fgets(funcionario.cidade,20,stdin);
		fprintf(file,"Cidade: %s",funcionario.cidade);
		
		printf("Digite a rua do funcionario:");
		gets(funcionario.rua);
		fprintf(file,"Rua: %s",funcionario.rua);
		
		printf("Digite o numero residencial do cliente:");
		gets(funcionario.numero_resisdencial);
		fprintf(file,"\nNumero residencial: %s",funcionario.numero_resisdencial);
		
		printf("Digite o bairro do cliente:");
		gets(funcionario.bairro);
		fprintf(file,"\nBairro: %s",funcionario.bairro);
	
	    printf("Digite o telefone: ");
	    gets(funcionario.telefone);
	    fprintf(file, "Telefone: %s\n",funcionario.telefone);
	    
	    printf("Digite o salário do funcionario:");
	    gets(funcionario.salario);
	    fprintf(file,"Salário: %s",funcionario.salario);
	    
	    //Fecha o arquivo para salva-lo
	    fclose(file);
	    
	    //Separa o cliente entre médico, atendente 
	    printf("\nDigite qual a posição do funcionario\n");
	    printf("\nDigite 1 caso seja um(a) médico(a)\n");
	    printf("Digite 2 caso seja um(a) atendente\n");
	    printf("Digite 3 caso seja um(a) faxineiro(a)");
	    printf("Digite 4 caso seja um(a) segurança");
	    printf("\n\nOpção selecionada ->");
	    scanf("%d",&opcao);
	    
	    switch(opcao){
	    	case 1:
	    			if(!(file = fopen("medicos.txt","a")))
	    				file = fopen("medicos.txt","w");
	    			//Limpa a entrada do teclado	
	    			debugar();
	    			//Digita o nome e cpf do funcionário do arquivo correspondente a sua profissão
					printf("\nDigite o nome do funcionario novamente:");
					gets(funcionario.email);
	    			fprintf(file,"\nNome:%s",funcionario.nome);
	    			
	    			printf("\nDigite o cpf do funcionario novamente:");
	    			gets(funcionario.cpf);
	    			fprintf(file," CPF:%s",funcionario.cpf);
	    			fclose(file);
	    			break;
	    	case 2:
	    			if(!(file = fopen("atendentes.txt","a")))
	    				file = fopen("atendentes.txt","w");
					
					debugar();
	    			printf("\nDigite o nome do funcionario novamente:");
					gets(funcionario.email);
	    			fprintf(file,"\nNome:%s",funcionario.nome);
	    			printf("\nDigite o cpf do funcionario novamente:");
	    			gets(funcionario.cpf);
	    			fprintf(file," CPF:%s",funcionario.cpf);
	    			fclose(file);
	    			break;
	    	case 3:
	    			if(!(file = fopen("faxineiros.txt","a")))
	    				file = fopen("faxineiro.txt","w");
					
					debugar();
	    			printf("\nDigite o nome do funcionario novamente:");
					gets(funcionario.email);
	    			fprintf(file,"\nNome:%s",funcionario.nome);
	    			printf("\nDigite o cpf do funcionario novamente:");
	    			gets(funcionario.cpf);
	    			fprintf(file," CPF:%s",funcionario.cpf);
	    			fclose(file);
	    			break;
	    	case 4:
	    			if(!(file = fopen("segurança.txt","a")))
	    				file = fopen("segurança.txt","w");
					
					debugar();
	    			printf("\nDigite o nome do funcionario novamente:");
					gets(funcionario.email);
	    			fprintf(file,"\nNome:%s",funcionario.nome);
	    			printf("\nDigite o cpf do funcionario novamente:");
	    			gets(funcionario.cpf);
	    			fprintf(file," CPF:%s",funcionario.cpf);
	    			fclose(file);
	    			break;
	    			
		}
	    
	    printf("Cadastro realizado com sucesso\n");
	    system("pause");
	}
}

void reclamacao() {
	
	char opiniao[200];
	
	//Criar a variável do tipo arquivo e abre o arquivo opiniao.txt
	FILE *file;
	file = fopen("opiniao.txt","a");
	
	if(file == NULL){
		//Caso ele não exista será criado
        file = fopen("opiniao.txt","w");
    }else{
    	
	printf("Conte como foi a sua experiência na nossa unidade:");
	gets(opiniao);
	fprintf(file, "Opinião do Cliente: %s \n", opiniao);
	
	fclose(file);
	
	printf("Obrigado pela Atenção.");
	system("pause");
	}
}

int login(int loginStdin, int senhaStdin){
	
	struct tela_de_login verificar;
	//Verifica se a senha e login estão corretas
	if(loginStdin == Login && senhaStdin == Senha){
		autenticacao = 1;
	}
	
	return autenticacao;
}

void cadastrarCliente() {
	
		
	struct informacoesPessoais cliente;
	char unidade[10];
	
	int contagem_de_clientes;
	int escolha;
	char quantidade_de_clientes[10];
	
	//Cria a variável do tipo FILE
	FILE *file;
	
	//Tela de cadastro
	//Função que limpa o prompt
	system("cls");
	printf("##################################################################### Tela de Cadastro de Clientes #####################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	//Limpa a entrada do teclado
	debugar();
	if(escolha == 1)
		main();
	
	//Pega o cpf do cliente
	printf("\nNão utilize acentos para escrever nomes\n");
	printf("\n\nDigite o CPF do cliente: ");
	gets(cliente.cpf);
	
	//Abre o arquivo com o nome do CPF do cliente
	file = fopen(cliente.cpf,"w");
	
	//Verifica se o arquivo foi aberto
	if(file == NULL){
		printf("Erro ao abrir o arquivo");
		system("pause");
		exit(0);
	}
	
	//Recebe as informações, guarda elas em variáveis e printa no arquivo
	fprintf(file,"CPF: %s",cliente.cpf);
	
	printf("Digite o nome do cliente(sem a utilização de acentos Ex: Joao):");
	gets(cliente.nome);
	fprintf(file,"\nNome: %s",cliente.nome);
	
	printf("Digite o RG do cliente:");
	gets(cliente.rg);
	fprintf(file,"\nRG: %s",cliente.rg);
	
	printf("Digite a cidade do cliente:");
	fgets(cliente.cidade,20,stdin);
	fprintf(file,"\nCidade: %s",cliente.cidade);
	
	printf("Digite a rua do cliente:");
	gets(cliente.rua);
	fprintf(file,"Rua: %s",cliente.rua);
	
	printf("Digite o numero residencial do cliente:");
	gets(cliente.numero_resisdencial);
	fprintf(file,"\nNumero residencial: %s",cliente.numero_resisdencial);
	
	printf("Digite o bairro do cliente:");
	gets(cliente.bairro);
	fprintf(file,"\nBairro: %s",cliente.bairro);
	
	printf("Digite o tipo sanguineo do cliente:");
	gets(cliente.tipo_sanguineo);
	fprintf(file,"\nTipo sanguineo: %s",cliente);
	
	printf("Digite o telefone do cliente(Ex:(99) 999999999 ):");
	gets(cliente.telefone);
	fprintf(file,"\nTelefone:%s",cliente.telefone);
	
	printf("Digite o email do cliente:");
	gets(cliente.email);
	fprintf(file,"\nE-Mail: %s",cliente.email);
	
	printf("Digite a data de nascimento:");
	gets(cliente.data_nascimento);
	fprintf(file,"\nData de nascimento: %s",cliente.data_nascimento);
	
	//Fecha o arquivo
	fclose(file);
	
	//Parte do código responsável por contar a quantidade de cadastros
	printf("\nDigite qual é esta unidade(Digite da seguinte forma, alterando apenas o numero 1 pelo numero da unidade - Unidade1)");
	printf("\nUnidade digitada ->");
	gets(unidade);
	
	//Abre o arquivo da unidade, em modo leitura se ele não existe cria e printa 0 no arquivo
	inicio:
	if(!(file = fopen(unidade,"r"))){
		char zero = '0';
		file = fopen(unidade,"w");
		fprintf(file,"%c",zero);
		fclose(file);
		file = fopen(unidade,"r");
	}
	//Lê a primeira linha do arquivo até o final do arquivo e armazena o que estava escrito na variável quantidade_de_clientes
	while(fscanf(file,"%s",quantidade_de_clientes)!= EOF){
		
		//A variáve contagem_de_cliente recebe a variável quantidade_de_clientes transformada de char para int pela função atoi
		contagem_de_clientes = atoi(quantidade_de_clientes);
		
		//Soma + 1 no valor 
		if(contagem_de_clientes >= 1){
			contagem_de_clientes++;
		}
	}
		//Converte a variável contagem_de_clientes em char e guarda esse valor na quantidade_de_clientes
		sprintf(quantidade_de_clientes,"%d",contagem_de_clientes);
	fclose(file);
	
	//Abre o arquivo no modo escrita
	file = fopen(unidade,"w");
	
	//Escreve no arquivo a nova quantidade de clientes
	fprintf(file,"%s",quantidade_de_clientes);
	fclose(file);	
	
	//Parte responsável por evitar bugs
	//Abre o arquivo e caso o valor dele seja 0 redefine o valor para 1
	file = fopen(unidade,"r");
	
	while(fscanf(file,"%s",quantidade_de_clientes)!= EOF){
		contagem_de_clientes = atoi(quantidade_de_clientes);
		
		if(contagem_de_clientes == 0){
			contagem_de_clientes = 1;
		}
	}
		sprintf(quantidade_de_clientes,"%d",contagem_de_clientes);
	fclose(file);
	
	file = fopen(unidade,"w");
	
	fprintf(file,"%s",quantidade_de_clientes);
	fclose(file);
		
	printf("\nCadastro feito com sucesso ");
	system("pause");	
}

void marcarConsulta(){
	
	//Abre as estruturas
	struct cadastro_consulta consulta;
	struct informacoesPessoais clientes;
	
	char texto[50];
	
	int verificacao = 1;
	int opcao;
	int opcao2;
	float preco;
	int escolha;
	
	//Tela de agendamento
	FILE *file;
	//Função para limpara o prompt
	system("cls");
	printf("####################################################################### Tela de agendamento ######################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	debugar();
	if(escolha == 1)
		main();
	
	//Salva o preço atual da consulta
	printf("\nDigite o preço atual da consulta:");
	scanf("%f",&preco);
	//Limpa a entrada do teclado
	debugar();
	
	//Salvo o cpf e abre o arquivo com o nome do CPF
	printf("\n\nDigite o cpf do cliente:");
	gets(consulta.cpf_cliente_consulta);
	file = fopen(consulta.cpf_cliente_consulta, "r");
	
	//Se o arquivo não abrir volta para a tela inicial
	if(file == NULL){
		printf("\nO CPF digitado não está cadastrado, voltando para a tela inicial\n");
		system("pause");
		main();
	}
	
	//Printa os dados do cliente na tela
	printf("\nDados do cliente:\n\n");
	
	//Enquanto a função de pegar texto foi diferente de null irá printar o texto pego na tela
	while(fgets(texto, 50, file) != NULL){
		printf("%s", texto);
	}
	
	printf("\n\nConfirme os dados com o cliente");
	printf("\n\nCaso os dados coincidam, digite 1 continuar com o agendamento, caso queira sair do agendamento digite 2");
	
	//Menu de opções
	opcao1:
	printf("\n\nOpcao selecionada ->");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			
			//Mostra as consultas já marcadas
			printf("\n\n");
			printf("Consultas ja marcadas\n\n");
			fclose(file);
			
			//Contade de 0 até 100000 para abrir todos os aqruivos possíveis de consultas
			for(int i=0;i<=100000;i++){
				//converte o valor de i para char
				sprintf(texto,"%d",i);
				//Abre os aquivos com o valor de i e printa o conteúdo deles na tela
				if((file=fopen(texto,"r"))){
					while((fgets(texto,50,file) != NULL)){
					printf("%s", texto);
					}
			
				}
			}
			
			//Printa os médicos cadastrados no sistema
			printf("\n\nMédicos disponiveis:\n");
	
			if(!(file=fopen("medicos.txt","r"))){
				//Se o arquivo não abrir volta para a tela inicial
				printf("Erro, não há médicos cadastrados voltando para a tela inicial");
				system("pause");
				main();
			}
			//Pega o que tem escrito no arquivo e digita o conteúdo na tela
			while(fgets(texto,50,file) != NULL){
				printf("%s", texto);
			}
			fclose(file);
			
			//Menu de opções
			printf("\n\nA consulta está custando %.2f", preco);
			opcao2:
			printf("\nConfirme com o cliente se ele deseja marcar a consulta");
			printf("\n\nDigite 1 para sim");
			printf("\nDigite 2 ou para não");
			printf("\nOpção ->");
			scanf("%d",&opcao2);
			
			switch(opcao2){
				case 1:	
						rand:
						do{
							//Limpa a entrada do teclado
							debugar();
							//Gera um ID aleatório e unico para a consulta
							consulta.id = rand() % 10000;
							sprintf(consulta.id_convertido,"%d",consulta.id);
							
							//Verifica se o arquivo já existe
							if(!(file = fopen(consulta.id_convertido, "r"))){
								//Caso não exista irá criar um arquivo com o ID
								verificacao = 2;
								fclose(file);
								file = fopen(consulta.id_convertido,"w");
								
								//Printa as informações no arquivo
								fprintf(file,"%.2f",preco);
								fprintf(file,"\nCPF do cliente:%s",consulta.cpf_cliente_consulta);
								fprintf(file,"\nID da consulta:%s",consulta.id_convertido);
								
								printf("\n\nDigite qual médico deseja consultar:");
								gets(consulta.motivo);
								fprintf(file,"\nNome do médico:%s",consulta.motivo);
								
								printf("\nDigite o horario da consulta:");
								gets(consulta.horario);
								fprintf(file,"\nHorario da consulta:%s",consulta.horario);
								
								printf("\nDigite o dia da consulta:");
								scanf("%d",&consulta.dia);
								fprintf(file,"\nDia da consulta:%d",consulta.dia);
								
								printf("\nDigite o mes da consulta:");
								scanf("%d",&consulta.mes);
								fprintf(file,"\nMes da consulta:%d\n",consulta.mes);
								
								printf("\n\nConsulta marcada com sucesso");
								printf("\nId da consulta ->%d\n", consulta.id);
								system("pause");
								fclose(file);
							}else{
								//volta para a criação do ID
								fclose(file);
								goto rand;
							}
						}while(verificacao == 1);
						break;
				case 2:
					//Volta para a tela inicial
					printf("\nVoltando apra a tela inicial\n");
					system("pause");
					main();
					break;
				default:
					printf("\nOpcao invalida, digite a opcao novamente");
					goto opcao2;
					break;
				}
						break;
		case 2:
				//Volta para a tela inicial
				printf("\nVoltando para a tela inicial\n");
				system("pause");
				main();
				break;
		default:
			printf("\nOpcao invalida, digite novamente");
			goto opcao1;
			break;
	}
	
}

void finalizarConsulta(){
	
	FILE *file;
	
	char id[10];
	char busca[80];
	char preco[10];
	int tamanho;
	float busca_convertida;
	char unidade[15];
	int escolha;
	float fatura_dia;
	char texto[50];
	
	//Limpa o prompt
	system("cls");
	printf("########################################################################### Finalizar Consulta #########################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	debugar();
	if(escolha == 1)
		main();
	
	//Pega o ID da consulta 
	printf("Digite o ID da consulta:");
	gets(id);
	
	//Abre o arquivo correspondente ao ID
	if(!(file=fopen(id,"r"))){
		//Se não abrir volta para a tela inicial
		printf("Não foi possivel abrir, voltando para a tela inicial\n");
		system("pause");
		main();
	}
	
	//Printa os dados da consulta
	printf("\nDados da consulta:\n\n");
	
	//Enquanto a função de pegar o texto do arquivo foi diferente de NULL irá printar o texto dentro do arquivo
	while(fgets(texto, 50, file) != NULL){
		printf("%s", texto);
	}
	fclose(file);
	
	if(!(file=fopen(id,"r"))){
		printf("Não foi possivel abrir, voltando para a tela inicial\n");
		system("pause");
		main();
	}
	
	//Salva o preço digitado na variável
	printf("\nDigite o preço: ");
	scanf("%[^\n]s", preco);
	//Digite \n no final da string;
	strcat(preco, "\n");

	//Verifica o tamanho da string
	tamanho = strlen(preco);
    do {
    	//Pega o preço digitado dentro do arquivo
        fgets(busca, tamanho+1, file);
        if(strcmp(busca, preco) == 0) {
        	//Converte o preço de string para float
            busca_convertida = atoi(busca);
        }
        
    } while(!feof(file));
	fclose(file);
	//Limpa a entrada do teclado
	debugar();
	
	//Salva qual o dia e o valor daquela consulta
	printf("\n\nDigite a unidade em que está sendo feito a finalização(Escreva dessa forma (diariox y) trocando x pelo número da unidade e y pelo dia");
	printf("\nUnidade digitada ->");
	gets(unidade);
	if(!(file=fopen(unidade,"r"))){
		file=fopen(unidade,"w");
		fprintf(file,"0");
		fclose(file);
		file=fopen(unidade,"r");
	}
	//Pega o que ta escrito no arquivo e salva na variável busca
	fgets(busca,100,file);
	//Converte a busca para float
	fatura_dia = atoi(busca);
	
	//Soma o que já estava no arquivo com a consulta realizada
	fatura_dia += busca_convertida;
	
	//Converte o valor da fatura do dia em string
	sprintf(busca,"%f",fatura_dia);
	
	//Fehcha o arquivo
	fclose(file);
	
	//Abre o arquivo e printa o valor da fatura convertida dentro dele
	file=fopen(unidade,"w");
	fprintf(file,"%s",busca);
	fclose(file);
	//Remove o arquivo
	remove(id);
	system("pause");
}

void menuAdm(){
	
	//Abre as estruturas
	struct menu navegar;
	struct tela_de_login logar;
	
	//Limpa a tela do prompt
	system("cls");
	//Tela de login
	printf("########################################################################## Tela de login ADM ###########################################################################");
	printf("\n\nDigite o usuário para entrar no sistema admnistrativo\n\n");
	printf("Usuário ->");
	scanf("%d",&logar.loginAdm);
	printf("\nDigite a senha para entrar no sistema admnistrativo\n");
	printf("\nSenha ->");
	scanf("%d",&logar.senhaAdm);
	
	//Confirmação se a função retornar algo diferente de 1 redireciona para a tela main
	if(loginAdm(logar.loginAdm,logar.senhaAdm) != 1){
		printf("Usuário ou senha incorretos, voltando para a tela de login\n");
		system("pause");
		main();
	}
	
	do{
	//Menu administrativo
	system("cls");
	navegar.sair = 0;
	printf("########################################################################## Menu administrativo #########################################################################");
	printf("\n\nDigite um dos número abaixo para selecionar uma opção\n\n");
	printf("Digite 1 para realizar o cadastro de um funcionario\n");
	printf("Digite 2 para obter as informacoes de um  funcionario cadastrado\n");
	printf("Digite 3 para obter o relatório do faturamento diario de cada unidade\n");
	printf("Digite 4 para obter o relatório do faturamento mensal de cada unidade\n");
	printf("Digite 5 para salvar o faturamento mensal\n");
	printf("Digite 6 para ver quantos cadastros cada unidade possui\n");
	printf("Digite 7 para voltar para a tela inicial");
	printf("\nOpção digitada -> ");
	scanf("%d",&navegar.opcao);
	switch(navegar.opcao){
			case 1:
					//Limpa a entrada do teclado
					debugar();
					cadastrarFuncionario();
					break;
			case 2:
					//Limpa a entrada do teclado
					debugar();
					pesquisarFuncionarios();
					break;
			case 3:
					//Limpa a entrada do teclado
					debugar();
					faturamentoDiario();
					break;
			case 4:
					//Limpa a entrada do teclado
					debugar();
					faturamentoMensal();
					break;
			case 5:
					//Limpa a entrada do teclado
					debugar();
					realizarFaturamento();
					break;
			case 6:
					//Limpa a entrada do teclado
					debugar();
					contarCadastros();
			case 7:
					//Limpa a entrada do teclado
					debugar();
					main();
					break;
			default:
					printf("\nOpção inválida, reiniciando o software ");
					system("pause");
		}
	}while(navegar.sair == 0);
}

int loginAdm(int loginAdm, int senhaAdm){
	
	int autenticacao;

	//Autentica o usuario e senha
	if(loginAdm == ADMLOGIN && senhaAdm == ADMSENHA){
		autenticacao = 1;
	}
	
	return autenticacao;
}

void descadastrarCliente(){
	
	//Abre as estruturas da função
	struct informacoesPessoais descadastrar;
	char unidade[10];
	
	int contagem_de_clientes;
	char quantidade_de_clientes[10];
	int escolha;
	
	FILE *file;
	
	//Limpa a tela do prompt
	system("cls");
	printf("########################################################################## TELA DE DESCADASTRO #########################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	//Limpa a entrada do teclado
	debugar();
	
	//Se a escolha for 1 volta para a tela inicial
	if(escolha == 1)
		main();
		
	//Pega o cpf do cliente
	printf("\n\nDigite o cpf do cliente\n\n");
	printf("CPF digitado ->");
	gets(descadastrar.cpf);
	
	//Verifica se o cpf existe
	if(!(file = fopen(descadastrar.cpf,"r"))){
		printf("\n\nCPF Inexistente, voltando para o menu principal\n");
		system("pause");
		main();
	}
	
	fclose(file);
	
	//Remove o cpf do sistema
	remove(descadastrar.cpf);
	printf("\n Cliente descadastrado");
	
	//Diminui 1 da contagem de clientes
	printf("\nDigite qual é esta unidade(Digite da seguinte forma, alterando apenas o numero - Unidade1)");
	printf("\nUnidade digitada ->");
	gets(unidade);
	
	inicio:
	if(!(file = fopen(unidade,"r"))){
		file = fopen(unidade,"w");
		fclose(file);
	}
	
	//Le o valor dentro do arquivo
	while(fscanf(file,"%s",quantidade_de_clientes)!= EOF){
		//Converte o valor string em int
		contagem_de_clientes = atoi(quantidade_de_clientes);
		//Diminui 1 do valor
		contagem_de_clientes--;
	}
		//Converte o int em string
		sprintf(quantidade_de_clientes,"%d",contagem_de_clientes);
	fclose(file);
	
	file = fopen(unidade,"w");
	
	//Printa no arquivo o valor diminuido
	fprintf(file,"%s",quantidade_de_clientes);
	fclose(file);
	
	system("pause");
	
}

void cancelarConsulta(){
	
	char ID[10];
	int decisao;
	char texto[50];
	int escolha;
	
	//Abre a estrutura
	struct informacoesPessoais cliente;
	
	FILE *file;
	
	//Limpa a tela
	system("cls");
	
	//Tela de cancelamento
	printf("################################################################### Tela de cancelamento de consultas ##################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	
	//Limpa a entrada do teclado
	debugar();
	
	//Volta para a tela inicial
	if(escolha == 1)
		main();
		
	//Pega o cpf do cliente
	printf("\n\nDigite o CPF do cliente:");
	gets(cliente.cpf);
	
	//Verifica se o cpf está cadastrado
	if(!(file=fopen(cliente.cpf,"r"))){
		printf("\nCPF não cadastrado no sistema\n");
		fclose(file);
		printf("Voltando para a tela inicial\n");
		system("pause");
		main();
	}
	
	fclose(file);
	
	//Pega o ID da consulta
	printf("\nDigite o ID da consulta que deseja cancelar:");
	gets(ID);
	
	//Verifica se a consulta existe
	if(!(file=fopen(ID,"r"))){
		printf("ID não encontrado\n");
		printf("Voltando para a tela inicial");
		system("pause");
		main();
	}
	
	//Printa os dados da consulta
	printf("\nDados da consulta \n\n");
	while(fgets(texto, 50, file) != NULL){
		printf("%s", texto);
	}
	
	fclose(file);
	
	//Menu de opção
	printf("\n\nConfirme os dados com o cliente\n");
	printf("\nDigite 1 para não cancelar a consulta");
	printf("\nDigite 2 ou qualquer outro numero para cancelar a consulta");
	printf("\nOpção escolhida ->");
	scanf("%d",&decisao);
	
	//Volta para a tela inicial
	if(decisao == 1)
		main();
		
	if(decisao != 1){
	//Exclui o arquivo da consulta
	remove(ID);
	printf("\nConsulta cancelada com sucesso\n");
	system("pause");
	}
}

void pesquisarFuncionarios(){
	FILE *file;
	
	char texto[50];
	char cpf[50];
	int escolha;
	
	//Limpa a tela
	system("cls");
	//Tela de pesquisa
	printf("####################################################################### Pesquisa de Funcionários #######################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	
	//Limpa a entrada do teclado
	debugar();
	
	//Volta para a tela inicial
	if(escolha == 1)
		main();
		
	//Printa na tela os funcionários já cadastrados
	printf("\nFuncionarios cadastrados:");
	printf("\n");
	
	file = fopen("medicos.txt","r");
	
	//Pega o que está escrito no arquivo e imprime na tela
	while(fgets(texto,50,file) != NULL){
		printf("%s\n",texto);
	}
	fclose(file);
	
	file = fopen("atendentes.txt","r");
	
	//Pega o que está escrito no arquivo e imprime na tela
	while(fgets(texto,50,file) != NULL){
		printf("%s\n",texto);
	}
	fclose(file);
	
	file = fopen("faxineiros.txt","r");
	
	//Pega o que está escrito no arquivo e imprime na tela
	while(fgets(texto,50,file) != NULL){
		printf("%s\n",texto);
	}
	fclose(file);
	
	file = fopen("seguranças.txt","r");
	
	//Pega o que está escrito no arquivo e imprime na tela
	while(fgets(texto,50,file) != NULL){
		printf("%s\n",texto);
	}
	fclose(file);
	
	//Pega o CPF do funcionário que deseja ver as informações
	printf("\nDigite o CPF do funcionario que deseja pesquisa\n");
	printf("CPF digitado ->");
	gets(cpf);
	
	//Abre o arquivo
	if(!(file = fopen(cpf,"r"))){
		printf("\nCPF não existe, voltando para a tela inicial");
		main();
	}
	//Digita as informações do arquivo na tela
	while(fgets(texto,50,file) != NULL){
		printf("%s",texto);
	}
	printf(" reais\n");
	system("pause");
}

void faturamentoDiario(){
	FILE *file;
	
	char busca[20];
	char unidade[15];
	
	int escolha;

	//Limpa a tela
	system("cls");

	printf("########################################################################## Relatório Diário ###########################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	
	//Limpa a entrada do teclado
	debugar();
	
	//Volta para a tela inicial
	if(escolha == 1)
		main();
	
	buscar:
	//Pega qual arquivo deseja abrir
	printf("\n\nDigite diarioX Y, trocando X pelo numero da unidade que deseja ver, e Y pelo dia(EX: diario1 20)");
	printf("\nEscolha ->");
	gets(unidade);
	
	printf("Valor ganho:");
	
	//Abre o arquivo
	if(!(file = fopen(unidade,"r"))){
		printf("\nArquivo não existe, digite novamente");
		goto buscar;
	}
	//Printa o que estava armazenado dentro do aquivo na tela
	fgets(busca,20,file);
	printf("\n\n%s",busca);
	
	//Verifica se deseja ver outra unidade
	printf("\n\nDeseja buscar outra unidade ?");
	printf("\nDigite 1 para sim");
	printf("\nDigite 2 para não");
	printf("\nEscolha ->");
	scanf("%d", &escolha);
	
	if(escolha == 1)
	//Volta para o começo do código
		goto buscar;
		
	system("pause");
}

void contarCadastros(){
	
	char unidade[15];
	char busca[20];
	int escolha;
	
	FILE *file;
	
	//Limpa o prompt
	system("cls");
	
	printf("######################################################################## Contagem de Cadastros #########################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	
	//Limpa a entrada do teclado
	debugar();
	
	//Volta para a tela principal
	if(escolha == 1)
		main();
	
	pesquisa:
		
	//Salva qual arquivo será aberto
	printf("\n\nPara ver a unidade desejada digite UnidadeX, trocando o X pelo número da unidade");
	printf("\nArquivo a ser aberto ->");
	gets(unidade);
	
	//Abre o arquivo
	if(!(file = fopen(unidade,"r"))){
		//Caso nao abra volta para a tela inicial
		printf("\nUnidade não existe, voltando para a tela inicial");
		system("pause");
		main();
	}
	
	//Printa o conteudo do arquivo na tela
	fgets(busca,20,file);
	printf("\nA %s possui %s cadastros", unidade,busca);
	
	fclose(file);
	
	//Verifica se deseja abrir outro arquivo
	printf("\n\nDeseja ver de outra unidade ?");
	printf("\nDigite 1 para sim");
	printf("\nDigite 2 para não");
	printf("\nEscolha ->");
	scanf("%d",&escolha);
	
	//volta para o começo do código
	if(escolha == 1){
		debugar();
		goto pesquisa;
	}
	
}

void realizarFaturamento(){
	FILE *file;
	
	char busca[20];
	char unidade[15];
	char texto[20];
	char unidade_diaria[15];
	float ganho_diario;
	float ganho_mensal;
	
	int escolha;

	//Limpa o prompt
	system("cls");
	
	printf("########################################################################## Realizar Relatório Mensal ###########################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	
	//Limpa a entrada do teclado
	debugar();
	
	//Volta para a tela principal
	if(escolha == 1)
		main();

	buscar:
	//Salva o nome do arquivo
	printf("\nTela responsável por salvar o ganho mensal.");
	printf("\n\nDigite mensalX Y, trocando X pelo numero da unidade que deseja ver, e Y pelo mes(EX: mensal1 11)");
	printf("\nEscolha ->");
	gets(unidade);
	
	//Abre o arquivo para alterar o valor
	if(!(file = fopen(unidade,"w"))){
		printf("Não foi possível abrir o arquivo");
		system("pause");
		main();
	}
	
	float num = 0;
	//Printa dentro do aquivo o numero 0
	fprintf(file,"%f",num);
	
	//Salva o nome do aqruivo
	printf("\nDigite diarioX Y, trocando X pelo numero da unidade que deseja salvar no lucro mensal, e Y pelo dia do lucro(Ex diario1 27)");
	printf("\nEscolha ->");
	gets(unidade_diaria);
	
	fclose(file);
	
	//Abre o aquivo com o nome da unidade
	file = fopen(unidade_diaria,"r");
	
	//Pega o conteudo do arquivo
	fgets(busca,20,file);
	fclose(file);
	
	//Converte a string do conteudo em float
	ganho_diario = atoi(busca);
	
	//Abre o arquivo no modo de leitura
	file = fopen(unidade,"r");
	
	//Pega o que está escrito no arquivo
	fgets(texto,20,file);
	
	//Converte a string escrita em float
	ganho_mensal = atoi(texto);
	
	//soma os ganhos
	ganho_mensal += ganho_diario;
	
	//Converte o float para string
	sprintf(busca,"%f",ganho_mensal);
	fclose(file);
	
	file = fopen(unidade,"w");
	
	//Printa a soma dos dois valores no arquivo
	fprintf(file,"%s",busca);
	fclose(file);
	
	//Pergunta se deseja adiciona mais valores
	printf("\n\nDeseja soma o valor de outra unidade ou dia?");
	printf("\nDigite 1 para sim");
	printf("\nDigite 2 para não");
	printf("\nEscolha ->");
	scanf("%d", &escolha);
	
	//volta para o começo do código
	if(escolha == 1){
		
		//Limpa a entrada do teclado
		debugar();
		goto buscar;
}else{
	//Limpa a entrada do teclado
	debugar();
	
}
	system("pause");
}

void faturamentoMensal(){
	FILE *file;
	
	char busca[20];
	char unidade[15];
	
	int escolha;

	//limpa a tela do prompt
	system("cls");
	
	printf("########################################################################## Relatório Mensal ###########################################################################");
	printf("\nCaso, tenha entrado nessa tela sem querer digite 1 para sair");
	printf("\nCaso queria continuar digite 2 para continuar");
	printf("\nOpção selecionada ->");
	scanf("%d",&escolha);
	
	//Limpa a entrada do tecaldo
	debugar();
	
	//Volta para a tela inicial
	if(escolha == 1)
		main();
	
	buscar:
	printf("\n\nDigite mensalX Y, trocando X pelo numero da unidade que deseja ver, e Y pelo mes(EX: mensal1 2)");
	printf("\nEscolha ->");
	gets(unidade);
	
	printf("Valor ganho:");
	if(!(file = fopen(unidade,"r"))){
		printf("\nArquivo não existe, digite novamente");
		goto buscar;
	}
	fgets(busca,20,file);
	printf("\n\n%s",busca);
	
	printf("\n\nDeseja buscar outra unidade ?");
	printf("\nDigite 1 para sim");
	printf("\nDigite 2 para não");
	printf("\nEscolha ->");
	scanf("%d", &escolha);
	
	if(escolha == 1)
		goto buscar;
		
	system("pause");
}

void debugar(){
	char cpf_cliente_bug[50];
	gets(cpf_cliente_bug);
}

