#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nome[50];
    char email[50];
    char endereco[200];
    char telefone[20];
    char aniversario[10];
    char observacoes[200];
}Contato;
char* upper(char string[50]){
    char *maiuscula;
    maiuscula=malloc(sizeof(char)*50);
    for (int i = 0; string[i] != '\0'; i++) {
        if ('a'<=string[i]&&string[i]<='z')
        {
           maiuscula[i]=(string[i] - 32);  
           
        }else{
            maiuscula[i]=string[i];
        }
    }
    return maiuscula;
}
void limparEntradas(){
      fflush(stdin);
    __fpurge(stdin);
}
int verificaInformacao(Contato contato){
    //printf("\n%ld\n",strlen(contato.nome));
    if (strlen(contato.nome)==1&&strlen(contato.email)==1
    &&strlen(contato.endereco)==1&&strlen(contato.telefone)==1
    &&strlen(contato.aniversario)==1&&strlen(contato.observacoes)==1)
    {
        return 1;
    }
    return 0;
}
void imprimirVariaveis(Contato listaContaots[20], int numContatos){
        for (int i = 0; i < numContatos; i++)
        {
           
            printf("\tnome:%s\temail:%s\tendereco: %s\ttel: %s\taniver:%s\tobs: %s",listaContaots[i].nome,listaContaots[i].email,listaContaots[i].endereco,listaContaots[i].telefone,listaContaots[i].aniversario,listaContaots[i].observacoes);
             printf("\n");
                }        }
int criarContato(Contato listaContatos[20],int numContatos){
    limparEntradas();
    printf("Preencha os campos conforme o solicitado\nnome(Ex:Lara Lana):");
    fgets(listaContatos[numContatos].nome,50,stdin);
    if(strchr(listaContatos[numContatos].nome,'\n')==NULL){
        strcat(listaContatos[numContatos].nome,"\n");
    }
    limparEntradas();
    printf("email(ex:nome@dominio.com):");
    fgets(listaContatos[numContatos].email,50,stdin);
     if(strchr(listaContatos[numContatos].email,'\n')==NULL){
        strcat(listaContatos[numContatos].email,"\n");
    }
    limparEntradas();
    printf("endereco(ex:rua,num,bairro,cidade,estado,Pais):");
    fgets(listaContatos[numContatos].endereco,200,stdin);
     if(strchr(listaContatos[numContatos].endereco,'\n')==NULL){
        strcat(listaContatos[numContatos].endereco,"\n");
    }
       limparEntradas();
    printf("telefone(ex:(XX) XXXXX-XXXX):");
    fgets(listaContatos[numContatos].telefone,20,stdin);
     if(strchr(listaContatos[numContatos].telefone,'\n')==NULL){
        strcat(listaContatos[numContatos].telefone,"\n");
    }
       limparEntradas();
    printf("Aniversario(ex:03/nov):");
    fgets(listaContatos[numContatos].aniversario,10,stdin);
     if(strchr(listaContatos[numContatos].aniversario,'\n')==NULL){
        strcat(listaContatos[numContatos].aniversario,"\n");
    }
       limparEntradas();
    printf("obs(ex:trabalho):");
    fgets(listaContatos[numContatos].observacoes,200,stdin);
     if(strchr(listaContatos[numContatos].observacoes,'\n')==NULL){
        strcat(listaContatos[numContatos].observacoes,"\n");
    }
    limparEntradas();
    return verificaInformacao(listaContatos[numContatos])?  numContatos: numContatos+1;
}
int existeSubstring(char* string,char* substring){
    int  j, k;
    int tamanhoString = strlen(string);
    int tamanhoSubstring = strlen(substring)-1;
    for (int i = 0; i <= tamanhoString - tamanhoSubstring; i++) {
        j = 0;
        k = i;

        while (string[k] == substring[j]) {
            k++;
            j++;
            if (j == tamanhoSubstring)
                return 1;
        }
    }

    return 0;
}
void buscaPorNome(Contato listaContatos[20],int num){
    Contato listaBusca[20];
    int tamanhoBusca=0;
    char busca[50];
     limparEntradas();
    printf("Digite o nome que deseja procurar:");
    fgets(busca,50,stdin);
    char* ponteiro;
    for (int i = 0; i < num; i++)
    {
        if(existeSubstring(upper(listaContatos[i].nome),upper(busca))){
            listaBusca[tamanhoBusca]=listaContatos[i];
            tamanhoBusca++;
        }
    }
    printf("Aqui estão os contatos encontrados:\n");
    imprimirVariaveis(listaBusca,tamanhoBusca);
    
}
int main(){
    FILE *arquivo;
    Contato listaContatos[20];
    int linhas=0;
    int numContatos=0;
    int escolha;
    int erro;
    arquivo=fopen("arquivo.txt","r");
    if (arquivo==NULL)
    {
        perror("arquivo.txt");
        return 0;
    }
    while(feof(arquivo)==0){
        
        switch (linhas%6)
        {
        case 0: 
            fgets(listaContatos[numContatos].nome,50,arquivo);
            if(strchr(listaContatos[numContatos].nome,'\n')==NULL){
                strcat(listaContatos[numContatos].nome,"\n");
            }
            strcpy(listaContatos[numContatos].email,"\n");
            strcpy(listaContatos[numContatos].endereco,"\n");
            strcpy(listaContatos[numContatos].telefone,"\n");
            strcpy(listaContatos[numContatos].aniversario,"\n");
            strcpy(listaContatos[numContatos].observacoes,"\n");
            numContatos++;
            break;
        case 1: 
            fgets(listaContatos[numContatos-1].email,50,arquivo);
            if(strchr(listaContatos[numContatos-1].email,'\n')==NULL){
                strcat(listaContatos[numContatos-1].email,"\n");
            }
            break;
        case 2: 
            fgets(listaContatos[numContatos-1].endereco,200,arquivo);
              if(strchr(listaContatos[numContatos-1].endereco,'\n')==NULL){
                strcat(listaContatos[numContatos-1].endereco,"\n");
            }
            break;
        case 3: 
            fgets(listaContatos[numContatos-1].telefone,20,arquivo);
              if(strchr(listaContatos[numContatos-1].telefone,'\n')==NULL){
                strcat(listaContatos[numContatos-1].telefone,"\n");
            }
            break;
        case 4: 
            fgets(listaContatos[numContatos-1].aniversario,10,arquivo);
              if(strchr(listaContatos[numContatos-1].aniversario,'\n')==NULL){
                strcat(listaContatos[numContatos-1].aniversario,"\n");
            }
            break;
        case 5: 
            fgets(listaContatos[numContatos-1].observacoes,200,arquivo);
              if(strchr(listaContatos[numContatos-1].observacoes,'\n')==NULL){
                strcat(listaContatos[numContatos-1].observacoes,"\n");
            }
            
            if(verificaInformacao(listaContatos[numContatos-1])) numContatos=numContatos-1;
            break;
        default:
            break;
        }
        linhas++;
    } 
    fclose(arquivo);
    if(verificaInformacao(listaContatos[numContatos-1])) numContatos=numContatos-1;
    do
    {
        printf("Ola, bem-vindo a agenda o que voce deseja:\n\t1.Listar Seus Contatos\t2.Pequisar contatos por nome\n\t3.Novo Contato\t4.Sair\nDigito:");
        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            printf("Aqui estão os seus contatos:\n");
            imprimirVariaveis(listaContatos,numContatos);
            break;
        case 2:
            buscaPorNome(listaContatos,numContatos);
            break;
         case 3:
           numContatos= criarContato(listaContatos,numContatos);
            break;
        case 4: 
            arquivo=fopen("arquivo.txt","w");
             if (arquivo==NULL)
             {
                    perror("arquivo.txt");
                   return 0;
             }
             for (int i = 0; i < numContatos; i++)
             {
               erro= fprintf(arquivo,"%s%s%s%s%s%s",listaContatos[i].nome,listaContatos[i].email,listaContatos[i].endereco,listaContatos[i].telefone,listaContatos[i].aniversario,listaContatos[i].observacoes);
                if (erro == EOF)		    
	                  printf("Erro na Gravacao\n");
             }
             fclose(arquivo);
        return 0;
        default:
            printf("Digite um valor valido!\n");
            break;
        }
    } while (1);
    
   
    return 0;
}