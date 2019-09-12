#include <stdio.h>
#define tam 5

struct aluno{
	long int matric;
	char nome[70];
	float nota[3];
	float media;
};

int main(){
	struct aluno vet[tam];
	int i, j, indice, repetido;
	float maior=-1;
	
	
	for(i=0;i<tam;i++){
		
		vet[i].media=0;
		
		printf("aluno %d\n",i+1);
		printf("digite a matricula do aluno\n");
		scanf("%ld", &vet[i].matric);
		
		printf("digite o nome do aluno\n");
		fflush(stdin);
		gets(vet[i].nome);
		
		for(j=0;j<3;j++){
			printf("digite a nota %d do aluno\n",j+1);
			scanf("%f",&vet[i].nota[j]);
			while(vet[i].nota[j]<0 || vet[i].nota[j]>10){
				printf("nota invalida, a nota tem que ser maior ou igual a 0, ou menor ou igual a 10\n");
				printf("digite a nota %d do aluno\n",j+1);
			    scanf("%f",&vet[i].nota[j]);
			}
			vet[i].media+=vet[i].nota[j];
		}
		vet[i].media=vet[i].media/3;
		printf("a media do aluno eh: %.2f\n\n",vet[i].media);
		
		if(maior<vet[i].media){
			maior=vet[i].media;
			indice=i;
			repetido=1;
		}else if(maior==vet[i].media){
			repetido++;
		}
	}
	
	if(repetido>1){
		printf("os alunos com maior media sao os alunos:\n");
		for(i=0;i<tam;i++){
			if(vet[i].media==maior){
		        printf(" aluno %d\n matricula: %ld\n nome: %s \n notas: %.2f | %.2f | %.2f \n media: %.2f\n\n",i+1, vet[i].matric,vet[i].nome,vet[i].nota[0],vet[i].nota[1],vet[i].nota[2],vet[i].media);
			}
		}	
	}else{
		printf("o aluno com maior media eh o aluno %d\n dados:\n",indice+1);
		printf(" matricula: %ld\n nome: %s \n notas: %.2f | %.2f | %.2f \n media: %.2f", vet[indice].matric,vet[indice].nome,vet[indice].nota[0],vet[indice].nota[1],vet[indice].nota[2],vet[indice].media);
	}
	
}
