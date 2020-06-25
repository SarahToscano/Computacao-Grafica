# Computacao-Grafica
Repositório destinado a implementação das atividades práticas desenvolvidas na disciplina de Computação Gráfica, ministrada pelo professor Christian Azambuja, no Centro de Informática da UFPB.
Autora: Sarah Andrade Toscano de Carvalho.

## Atividade 01: Rasterização de pontos e linhas. 
### Descrição
   A atividade consistiu na implementação de algoritmos e utilização do OpenGL para a rasterização de pontos, linhas e triângulos com interpolação de cores. Para a rasterização destas primitivas foi utilizado um framework de simulação ao acesso direto a memória de vídeo, forncido pelo professor.  
  
   A Estrutura de organização dos arquivos do framework está dispostas da seguinte forma:
   * O *core.h* configura a dimensão da tela simulada;  
   
   * No código *frame_buffer.h* o ponteiro aponta para o primeiro byte color é declarado. Desse modo,a posição apontada por este ponteiro irá representar as coordenadas do pixel a ser rasterizado;  
   
   * Os arquivos *main.c* e *main.h* definem funções e variáveis necessárias a simulação de acesso à memória de vídeo;
   
   * O arquivo *mygl.c* define as funções e variáveis necessárias a simulação de acesso à memória de vídeo. Neste caso, foram implementadas 6 funções neste arquivo, sendo 3 para os processos relacionados à rasterização e 3 para a interpolação de cor;  
   
   * Por fim, o arquivo *mygl.h* é o cabeçalho incluso da função principal, no qual são definidas todas as funções e estruturas de organização dos dados utilizados na main.c.
  
### Requisitos

Para esta atividade foram definidos quatro requisitos:

- [x] **Implementação da Interpolação de cores**  

  Dado dois pontos quaisquers e duas cores, a função de interpolação deve interpolar a cor da linha traçada com base na dimensão da reta e nas cores recebidas.
  
- [x] **Implementação da função PutPixel**  

  A função *PutPixel* recebe como entrada as coordenadas de um ponto e uma cor (RGBA). Para que dessa forma, possa rasterizar um ponto na memória de vídeo.
  
- [x] **Implementação da função DrawLine**

  Esta função rasteriza uma linha utilizando o algoritmo de Bresenham. Para isso,receberá como entrada as coordenadas de dois pontos e as cores atribuídas aos seus respectivos vértices. Com os dados dessas cores é realizada uma interpolação e a reta plotada é colorida com uma tonalidade degradê entre essas duas cores. 

- [x] **Implementação da função DrawTriangle**

  A função *DrawTriangle* recebe como parâmetros três vértice e suas respectivas cores, para que desse modo seja invocada a função *DrawLine* e un triângulo possa ser plotado.

### Estratégias e Resultados

#### PutPixel
   Nesta função a lógica de implementação utilizada baseou-se no cálculo do offset, posição do pixel da tela, e na atribuição da cor desejada para a rasterização do ponto. O offset foi cálculado por meio da expressão 
   X*4 + Y*4*Altura, no qual o *X* e *Y* representam as coordenadas x e y do ponto a ser rasterizado, e a *Altura* está relacionada a dimenssão da tela.
   
   Para facilitar a relação e atribuição das cores, foi criado um struct *Color* com as variáveis associadas aos valores RGBA. Desse modo, foram criados 5 instâncias desses structs para a representação de diferentes cores. A definição dos seus valores é realizada na função *DefineColors*.
  
  Para a chamada da função, foi utilizada uma função para aleatorizar os valores das coordenadas. Desta forma, esta chamada foi alocada dentro de um laço de repetição para que fossem rasterizados 30 pontos a cada atualização da tela.
  
  O resultado obtido é ilustrado na Figura abaixo.
  
  
  <center>![Resultado PutPixel](https://github.com/SAndradeTC/Computacao-Grafica/blob/master/pontos.png)<\center>

### Resultados e discussão

### Referências
