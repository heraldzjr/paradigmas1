#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct lista{
	char info[50];
}Lista;

int ordena(const void *a, const void *b);

int main(void)

{
    char url[] = "nomes", info[50];
    int numElementos = 0;
    Lista nomes[820];

    FILE *arquivo;
    FILE *arquivoOrdenado;
    FILE *listaGanhadoras;

    arquivo         = fopen(url,"r");
    arquivoOrdenado = fopen("nomes_ordenados", "w+");
    listaGanhadoras = fopen("listaGanhadoras.html", "w+");

    if(arquivo == NULL || arquivoOrdenado == NULL || listaGanhadoras == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
	    while( (fgets(info, sizeof(info), arquivo))!=NULL ){
			numElementos++;
			//printf("%s", info);
	    }
	    numElementos--;
		fseek(arquivo, 0, SEEK_SET);

		qsort(nomes, 820, sizeof(Lista), ordena);

		printf("Numero de Elementos: %d\n", numElementos);

		fprintf(listaGanhadoras, "<h1>Lista de Ganhadoras</h1>\n");
		fprintf(listaGanhadoras, "<ul>\n");

	    while( (fgets(info, sizeof(info), arquivo))!=NULL ){

			fprintf(arquivoOrdenado, "%s",info);

		    	if(info[0] == 'R' || info[0] == 'r'){
		    		fprintf(listaGanhadoras, " <li> %s </li> \n", info);
		  		}
	    }

	    fprintf(listaGanhadoras, "\n</ul>");
	}
	fclose(arquivo);
	fclose(arquivoOrdenado);
	fclose(listaGanhadoras);


	return 0;
}

int ordena(const void *a, const void *b){
	Lista *x = (Lista *) a;
	Lista *y = (Lista *) b;

	return strcmp(x->info, y->info);
}
