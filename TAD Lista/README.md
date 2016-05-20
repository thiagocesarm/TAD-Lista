## TAD Lista

por João Emmanuel Izidio da Silva & Thiago César Morais Diniz de Lucena

Descrição
--------------------------------------------------------------------------------------

Esse projeto contém a implementação, em C++, do tipo abstrato de dados *lista*, 
através de três estrutura de dados: array dinâmico, lista simplesmente encadeada 
e lista duplamente encadeada, implementadas em classes separadas. As classes das 
três estruturas de dados e seus métodos baseiam-se, respectivamente, nas classes
 std::vector, std::forward_list e std::list da biblioteca padrão STL.
 
O projeto também contém arquivos com exemplos de funcionamento dos métodos de 
cada classe. 


Instalação e execução
--------------------------------------------------------------------------------------

Para instalar o programar, basta seguir os seguintes passos: 

1. Extrair o arquivo "TAD_Lista.zip" que contém todos os arquivos com os códigos.
2. Abrir o terminal e navegar até a pasta extraída do arquivo zip.
3. Executar o comando:

g++ -std=c++11 -I include src/*nome_do_arquivo* -o bin/list

*nome_do_arquivo* deve ser substituído por um dos três arquivos contidos na 
pasta src/ de acordo com qual estrutura de dados deseja-se executar.

Em seguida, para executar o programa, execute o seguinte comando:

bin/list


Estrutura
--------------------------------------------------------------------------------------

A pasta */bin* armazena o arquivo executável que é gerado após a execução do
programa.

A pasta */include* contêm a biblioteca com as classe implementadas e os arquivos
com a implementação dos métodos das classes.

A pasta */src* contêm os arquivos com exemplos de funcionamento de cada uma das 
estruturas de dados ( o arquivo referente a classe List está drasticamente 
incompleto).


Operações não suportadas
--------------------------------------------------------------------------------------

Nas classes Forward_List e List, as operações insert e assign que requerem
iteradores e utilizam templates não foram implementadas.