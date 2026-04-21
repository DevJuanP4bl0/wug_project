# Sistema de criação de Wugs

Projeto em C que implementa a criação e gerenciamento de criaturas chamadas "Wugs".
O sistema permite gerar indivíduos com diferentes combinações genéticas, classificá-los por tipos, realizar o rankeamento e gerenciar uma população completa. Também, conta com funcionalidades de ordenação, geração de relatórios estatísticos e a conversão da genética para formato de string para exibição ao usuário.

## Funcionalidades

- Criação de Wugs
- Classificação genética
- Rankeamento dos indivíduos
- Ordenação 
- Gerenciamento da população
- Relatório estatístico da população
- Impressão da população e indívíduos

## Como compilar o projeto

Após clonar este repositório, abra seu terminal (Ubuntu/WSL ou VS Code com WSL), acesse a pasta do projeto e compile, com o seguinte comando:

```bash
gcc util.c testes.c wug.c -o wugs
``` 
Depois, execute:
```bash
./wugs
``` 

## Tecnologias usadas

- C (linguagem principal)
- GCC (compilador)
- WSL / Linux (ambiente de execução)

