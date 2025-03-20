## Aula 02,  14-11-2024 
### Ambiente de Desenvolvimento, Depuração e Testes

#### Programa

* Configuração do ambiente VSCode
* Exemplo de Depuração: MDC
* Header files
* [Atividades Práticas](#atividades)

<a id="atividades"></a>
#### Atividade: Teste de Primalidade por Crivo de Eratóstenes

* Escrever um programa `prime.c` para ler do teclado um número inteiro positivo `N` e imprimir
```C
N is prime
```
ou
```C
N is not prime
```
dependendo se `N` é um número primo ou não.
* O programa deve conter uma função `is_prime` para testar a primalidade de um número através do Crivo de Eratóstenes. A função deve retornar um booleano.
* Utilizar os recursos de depuração do VSCode para testar o código

#### Atividade: Criação de biblioteca

* Expor a função `is_prime` através de um header file `prime.h` 

#### Atividade: Decomposição em fatores primos

* Escrever um programa em C `primefactors.c` para ler um número inteiro positivo `N` e imprimir a sua decomposição em fatores primos. 

Exemplo
```
Enter a positive integer: 42
42 = 2 * 3 * 7
```
* O programa deve utilizar a função `is_prime` acima importando o header `prime.h`
* Utilizar os recursos de depuração do VSCode para testar o código





#### Referências




___
[[Código-fonte: /src]](./src)   [[< Anterior]](../aula01/aula01.md) [[Próximo >]](../aula03/aula03.md)  [[Índice ^]](../index.md)

