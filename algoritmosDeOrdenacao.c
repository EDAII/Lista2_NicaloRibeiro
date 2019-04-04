//Lista 2 - ED2 2019.1
//Nícalo Ribeiro 16/0016169
//Algorítmos de Ordenação n²

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void menu();

void verificaEcopia();
void selectionSort();
void bubbleSort();
void insertionSort();
void shellSort();
void mostrarTempos();
void mostrarArqOriginal();
void mostrarRegOrdenado();
void gerarIDS();
void gravarArquivoOrdenado();


typedef struct registroAnimais{
   
   int id;
   char nome[50];
   char nome_cientifico[50];

}Animais;
Animais *registrosOriginais = NULL;
Animais *registrosOrdenados = NULL;

double *resultadoSelectionSort = NULL, *resultadoBubbleSort = NULL, *resultadoInsertionSort = NULL, *resultadoShellSort = NULL;
int tamanho = 1000,qtdSelectionSort = 0, qtdBubbleSort = 0, qtdInsertionSort = 0, qtdShellSort = 0;

int main(){

    registrosOriginais = malloc(sizeof(Animais) * 1000);
    resultadoSelectionSort = (double *)malloc(qtdSelectionSort * sizeof(double));
    resultadoBubbleSort = (double *)malloc(qtdBubbleSort * sizeof(double));
    resultadoInsertionSort = (double *)malloc(qtdInsertionSort * sizeof(double));
    resultadoShellSort = (double *)malloc(qtdShellSort * sizeof(double));


    if(registrosOriginais == NULL){
        printf("Falha na alocação dos registros!\n");
        exit(1);
    }else{
        printf("Registros alocados.\n");
    }


    if(resultadoSelectionSort == NULL || resultadoBubbleSort == NULL || resultadoInsertionSort == NULL || resultadoShellSort == NULL){
        printf("Erro na alocação dos vetores de resultados!\n");
        exit(1);
    }else{
        printf("Vetores de resultados alocados.\n");
    }


    FILE *arq;
    arq = fopen("data.txt","r");
    if(arq == NULL){
        printf("Erro na aberturo do arquivo!\n");
        exit(1);
    }else{
        printf("Arquivo aberto.\n");
    }
    for(int c = 0; c<tamanho && !feof(arq); c++){
        fscanf(arq,"\n%d;%[^;];%[^\n]",&registrosOriginais[c].id,registrosOriginais[c].nome,registrosOriginais[c].nome_cientifico);     
    }

    menu();

    printf("Liberando espaços alocados e fechando arquivos abertos...\n");
    free(registrosOriginais);
    free(registrosOrdenados);
    free(resultadoSelectionSort);
    free(resultadoBubbleSort);
    free(resultadoInsertionSort);
    free(resultadoShellSort);
    fclose(arq);
    printf("Fim do programa.\n");
    return 0;
}

void menu(){
    int opcao;

    do{
        printf("\n|\t\tMENU\n");
        printf("|\t\t----\n");
        printf("|Escolha uma das opcões :\n");
        printf("|1-Realizar SELECTION SORT.\n");
        printf("|2-Realizar BUBBLE SORT.\n");
        printf("|3-Realizar INSERTION SORT.\n");
        printf("|4-Realizar SHELL SORT.\n");
        printf("|5-Gerar novos IDs para os registros.\n");
        printf("|6-Mostrar tempos de ordenação.\n");
        printf("|7-Mostrar registros a serem ordenados.\n");
        printf("|8-Mostrar registros ordenados.\n");
        printf("|9-Gravar arquivo com registros ordenados.\n");        
        printf("|0-Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
            selectionSort();
            break;
        
            case 2:
            bubbleSort();
            break;

            case 3:
            insertionSort();
            break;

            case 4:
            shellSort();
            break;

            case 5:
            gerarIDS();
            break;

            case 6:
            mostrarTempos();
            break;

            case 7:
            mostrarArqOriginal();
            break;

            case 8:
            mostrarRegOrdenado();
            break;

            case 9:
            gravarArquivoOrdenado();
            break;

            case 0:
            printf("Encerrando...\n");
            break;

            default:
            printf("Digite uma opção válida.\n");
            
        }

    }while(opcao != 0);
    
    return;
}

void verificaEcopia(){
    if(registrosOrdenados == NULL){
        registrosOrdenados = malloc(sizeof(Animais) * 1000);
    }else if(registrosOrdenados != NULL){
        free(registrosOrdenados);
        registrosOrdenados = malloc(sizeof(Animais) * 1000);
    }

    for(int i = 0; i < 1000; i++){
        registrosOrdenados[i] = registrosOriginais[i];
    }
    return;
}

void selectionSort(){
    double duracaoSelSort = 0;
    qtdSelectionSort++;
    resultadoSelectionSort = (double*)realloc(resultadoSelectionSort, qtdSelectionSort * sizeof(double));

    srand(0);
    clock_t time;
    verificaEcopia(); 

    int i, j, min;
    Animais aux;

    time = clock();
    for (i = 0; i < (tamanho - 1); i++){
        min = i;
        for (j = (i+1); j < tamanho; j++){
            if(registrosOrdenados[j].id < registrosOrdenados[min].id){           
                min = j;
            }
        }
        if (registrosOrdenados[i].id != registrosOrdenados[min].id) {
            aux = registrosOrdenados[min];
            registrosOrdenados[i] = registrosOrdenados[min];
            registrosOrdenados[min] = aux;
        }
    }
    time = clock() - time;
    duracaoSelSort = ((double)time)/CLOCKS_PER_SEC;

    resultadoSelectionSort[qtdSelectionSort - 1] = duracaoSelSort;
    system("clear");
    printf("Selection Sort realizado.\n\n");
    return;

}

void bubbleSort(){
    double duracaoBubSort = 0;

    qtdBubbleSort++;
    resultadoBubbleSort = (double *)realloc(resultadoBubbleSort, qtdBubbleSort * sizeof(double));

    srand(0);
    clock_t time;
    verificaEcopia();

    int i,j,k = (tamanho - 1);
    Animais aux;    

    time = clock();
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < k; j++){
            if(registrosOrdenados[j].id > registrosOrdenados[j+1].id){
                aux = registrosOrdenados[j];
                registrosOrdenados[j] = registrosOrdenados[j+1];
                registrosOrdenados[j+1]=aux;
            }
        }
        k--;
    }
    time = clock() - time;
    duracaoBubSort = ((double)time)/CLOCKS_PER_SEC;

    resultadoBubbleSort[qtdBubbleSort - 1] = duracaoBubSort;

    system("clear");
    printf("Bubble Sort realizado.\n\n");
    return;
}

void insertionSort(){
    double duracaoInsSort = 0;

    qtdInsertionSort++;
    resultadoInsertionSort = (double *)realloc(resultadoInsertionSort,qtdInsertionSort * sizeof(double));

    srand(0);
    clock_t time;
    verificaEcopia();

    int i,j;
    Animais aux;

    time = clock();     
    for (i = 1; i < tamanho; i++) { 
        aux = registrosOrdenados[i]; 
        j = i - 1; 
        while (j >= 0 && (registrosOrdenados[j].id > aux.id)) { 
            registrosOrdenados[j + 1] = registrosOrdenados[j]; 
            j--; 
        } 
        registrosOrdenados[j + 1] = aux; 
    }  
    time = clock() - time;
    duracaoInsSort = ((double)time)/CLOCKS_PER_SEC;

    resultadoInsertionSort[qtdInsertionSort - 1] = duracaoInsSort;

    system("clear");
    printf("Insertion Sort realizado.\n\n");
    return;
}

void shellSort(){

    double duracaoShellSort = 0;

    qtdShellSort++;
    resultadoShellSort = (double *)realloc(resultadoShellSort, qtdShellSort * sizeof(double));

    srand(0);
    clock_t time;
    verificaEcopia();

    int i , j , gap = 1;
    Animais aux;
    
    time = clock();
    do{
        gap = 3*gap+1;
    }while(gap < tamanho);
  
    do{
        gap /= 3;
        for(i = gap; i < tamanho; i++) {
            aux = registrosOrdenados[i];
        
            j = i - gap;
    
            while(j >= 0 && aux.id < registrosOrdenados[j].id) {
                registrosOrdenados[j + gap] = registrosOrdenados[j];
                j -= gap;
            }
        registrosOrdenados[j + gap] = aux;
        }
    }while(gap > 1);
    time = clock() - time;
    duracaoShellSort = ((double)time)/CLOCKS_PER_SEC;

    resultadoShellSort[qtdShellSort - 1] = duracaoShellSort;

    system("clear");
    printf("Shell Sort realizado.\n\n");
    return;
}

void mostrarTempos(){
    int voltar = 1;

    do{
    system("clear");
    if(qtdSelectionSort == 0 && qtdBubbleSort == 0 && qtdInsertionSort == 0 && qtdShellSort == 0){
        printf("Nenhuma ordenação foi realizada ainda!\n");
        return;
    }

    printf("Até o momento foram realizadas :\n->%d SELECTION SORT;\n->%d BUBBLE SORT;\n->%d ISERTION SORT;\n->%d SHELL SORT.\n",qtdSelectionSort,qtdBubbleSort,qtdInsertionSort,qtdShellSort);
    int i;

    if(qtdSelectionSort){
        printf("\n\nSELECTION SORT : \n");
        for (i = 0; i < qtdSelectionSort; i++){
            printf("%dº SELECTION SORT realizado durou %lf segundos.\n", i + 1, resultadoSelectionSort[i]);
        }
    }

    if(qtdBubbleSort){
        printf("\n\nBUBBLE SORT : \n");
        for(i = 0; i< qtdBubbleSort; i++){
            printf("%dº BUBBLE SORT realizado durou %lf segundos.\n", i + 1, resultadoBubbleSort[i]);
        }
    }

    if(qtdInsertionSort){
        printf("\n\nINSERTION SORT : \n");
        for(i = 0; i<qtdInsertionSort; i++){
            printf("%dº INSERTION SORT realizado durou %lf segundos.\n", i + 1, resultadoInsertionSort[i]);
        }
    }

    if(qtdShellSort){
        printf("\n\nSHELL SORT : \n");
        for(i = 0; i<qtdShellSort; i++){
            printf("%dº SHELL SORT realizado durou %lf segundos.\n", i + 1, resultadoShellSort[i]);
        }
    }

    printf("Digite <0> para voltar ao menu\n");
    scanf("%d", &voltar);
    }while(voltar);

    system("clear");
    return;
}

void mostrarArqOriginal(){
    
    int voltar = 1;
    do{ 
        system("clear");
        for(int i = 0; i < tamanho; i++){
            printf("%d;%s;%s\n",registrosOriginais[i].id, registrosOriginais[i].nome, registrosOriginais[i].nome_cientifico);
        }

        printf("Digite <0> para voltar ao MENU\n");
        scanf("%d",&voltar);    
    }while(voltar);

    system("clear");
    return;

}

void mostrarRegOrdenado(){

    int voltar = 1;
    do{
        system("clear");

        if(registrosOrdenados == NULL){
            printf("Nenhuma ordenação foi feita ainda.\n\n");
            return;
        }

        for(int i = 0; i < tamanho; i++){
            printf("%d;%s;%s\n",registrosOrdenados[i].id, registrosOrdenados[i].nome, registrosOrdenados[i].nome_cientifico);
        }

        printf("Digite <0> para voltar ao MENU\n");
        scanf("%d", &voltar);
    }while(voltar);

    system("clear");
    return;

}

void gerarIDS(){

    int numeroGerado , repetido = 1;    
    int *vetorAux = (int *)malloc(1000 * sizeof(int));
    srand(time(NULL)); 
    for(int i = 0; i < tamanho; i++){
        while(repetido){
            numeroGerado = (rand() % (tamanho*2) + 1);
            repetido = 0;
            for (int j = 0; j < tamanho; j++){
                if(numeroGerado == vetorAux[j]){
                    repetido = 1;
                }
            }        
        }        
        vetorAux[i] = numeroGerado;
        registrosOriginais[i].id = vetorAux[i];
        repetido = 1;        
    }

    free(vetorAux);
    system("clear");
    printf("Novos IDs gerados.\n\n");
    return;
}

void gravarArquivoOrdenado(){

    if(registrosOrdenados == NULL){
        printf("Ainda não há registros orenados.\n\n");
        return;
    }

    FILE *arq2;
    arq2 = fopen("dataInOrder.txt","w");
    printf("Gravação em andamento...\n");
    for(int j = 0; j < tamanho; j++){
        fprintf(arq2,"%d;%s;%s\n",registrosOrdenados[j].id,registrosOrdenados[j].nome,registrosOrdenados[j].nome_cientifico);
    }

    system("clear");
    printf("Gravação concluída.\n");

    fclose(arq2);
    return;
}
