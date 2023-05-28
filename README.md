# Primeiro-Projeto-EDA

## Sobre:
O projeto consiste em uma aplicação de árvores AVL a partir de um arquivo 
CSV que contém informações sobre pessoas, como nome, data de nascimento e 
CPF. Cada uma das árvores é organizada usando cada um desses atributos, 
mantendo uma referência para a(s) pessoa(s) que possuírem esses dados.

Essa aplicação permite que as operações desejadas sejam efetuadas de forma eficiente e rápida.

## Instruções de compilação e execução
1. Abra um terminal/prompt de comando e navegue até o diretório que contém os arquivos necessários.
2. Insira o comando ``g++ Pessoa.cpp AVL.cpp teste.cpp -o main.exe`` para gerar o executável.
3. Insira o comando ``./main.exe`` para executar o projeto.

## Notas:
1. Datas são escritas no formato mm/dd/aaaa, e se for escrito em outro formato o programa pode realizar comportamentos inesperados.
2. CPFs são exibidos no formato numérico xxxxxxxxxxx, mas em caso de leitura e escrita o formato xxx.xxx.xxx-xx também é aceito.
3. Nomes acentuados não são exibidos corretamente, podendo gerar confusões nos dados.