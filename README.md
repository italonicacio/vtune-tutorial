# Tutorial Vtune

Tutorial basico de uso do vtune para utilizar o proffiling em sua aplicações.

## Pré-requisitos
<!--ts-->
* Sistema Operacional Linux
* [oneAPI](https://www.intel.com/content/www/us/en/developer/tools/oneapi/overview.html#gs.krfpec)
    * [Base toolkit](https://www.intel.com/content/www/us/en/developer/tools/oneapi/base-toolkit.html)
    * [HPC toolkit](https://www.intel.com/content/www/us/en/developer/tools/oneapi/hpc-toolkit.html)
* Makefile
<!--te-->

### Váriaveis de ambiente
Em seu línux é necessario setar as variaveis de ambiente abaixo:
<!--ts-->
* MKLROOT - váriavel de ambiente com o caminho até o diretorio da MKL
<!--te-->


    OBS:
        Esse tutorial foi criado em um ambiente linux, entretanto é possivel que seja replicavel no SO Windows com a modificação de alguns aspectos do tutorial.

## Programa 

O programa teste consiste em uma diagonalização de matriz, temos uma matriz 5000x5000 por padrão, entretanto podemos aumentar ou diminuir a dimensão dela modificando a linha x aonde tem o seguinte codigo

```c++
#define MAX 5000
```


## Compilando O Programa Teste

```bash
# Abrindo o diretorio para compilar o projeto
cd build

# Comando para compilar o projeto
make 
```

## Executando o programa
O programa pode ser executado de duas formas a primeira é como normalmente já é feito no linux.

```bash
./vtune_test
```

A segunda forma é utilizando o comando

```bash
make run
```

