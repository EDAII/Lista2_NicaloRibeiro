# Lista 2 -- Algorítmos de Ordenação

| Aluno          | Matrícula  |
|----------------|------------|
| Nícalo Ribeiro | 16/0016169 |

---

## Funcionamento básico do programa
* O programa realizará a leitura de um arquivo texto que contém 1000 registros de animais, que possuem uma chave primária , seu nome comum e nome científico, gerados randomicamente no site [Mockaroo](https://www.mockaroo.com/ "Mockaroo");
* As linhas do arquivo seguem o padrão :
    * ID;NOME_COMUM;NOME_CIENTIFICO
* Após sua leitura, os dados do arquivo são armazenados em um vetor dinâmico de structs, onde serão realizadas ordenações **baseadas nas chaves primárias** de cada registro;
* As ações fornecidas pelo programa são :
  * Realizar selection sort;
  * Realizar bubble sort;
  * Realizar insertion sort;
  * Realizar shell sort;
  * Gerar novas chaves primárias para os registros;
  * Mostrar os tempos de execução de cada ordenação realizada;
  * Mostrar os registros do arquivo original;
  * Mostrar os registros ordenados;
  * Gravar um novo arquivo com os registros ordenados. 
* Antes de cada ordenação ser feita, é verificado se já existe um vetor com a cópia dos registros originais. Caso não haja, o vetor será alocado e a ordenação ocorrerá em cima dele. Caso haja, é entendível que ele já seja um vetor ordenado, então ele é liberado e um novo vetor é alocado para que a ordenação ocorra;
* É calculado o tempo de cada ordenação, que é salvo separadamente de acordo com o tipo de ordenação; 
* Consultas de resultados e novas ordenações podem, recorrentemente, serem realizados;
* A possibilidade de gerar novas chaves primárias para os registros é interessante para a realização de novos testes;
* Por fim, também é possível visualisar os registros originais e ordenados, além da gravação dos registros ordenados(de acordo com sua chave ordenada) em um novo arquivo.
  
---
