# Computacao-Gráfica
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
  
  Desta forma, a função possui a seguinte estrutura `PutPixel(int x1, int y1, Color *Color_reference)`. Para a definição das coordenadas foi utilizada a função *rand* da biblioteca *times.h* para aleatorizar os valores das coordenadas. 
  
  A PutPixel foi alocada dentro de um laço de repetição na função *MyGlDraw*, para que fossem rasterizados 3 pontos de cores distintas, trinta vezes, a cada atualização da tela. O resultado obtido é ilustrado na Figura abaixo.
  
  <p align="center">
  <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/pontos.png">
</p>

#### DrawLine
A função *DrawLine* utiliza as coordenadas de dois pontos para traçar uma reta de conexão entre eles, utilizando o algoritmo de Bresenham. Sua estrutura é a seguinte `DrawLine (Coordinates *p, Color *A, Color *B, Color *Color_reference)`.

A implementação desta função foi a mais complexa, comparando a com as outras funções desta atividade. Uma vez, que, foi necessário realizar alterações na sua estrtura para garantir que as retas pudessem ser rasterizadas em todos os octantes do plano. Para isso foram analisadas 4 situações:


- [x] **Implementação da Interpolação de cores**  

- [x] **Implementação da Interpolação de cores**  

- [x] **Implementação da Interpolação de cores**  

- [x] **Implementação da Interpolação de cores**  



#### DrawTriangle
Esta função consiste em três chamadas da função *DrawLine* para que três retas possam ser rasterizadas e formem o desenho de um triângulo. Cujas arestas possuem cores interpoladas de acordo com a atribuição da cor princiapal para cada vértice. 

A função se estrutura assim `DrawTriangle(Coordinates *p, Color *A, Color *B, Color *C, Color *Color_reference)`, no qual o *p* é um ponteiro que contém os dados das coordenadas dos três vértices, os structs *A, B e C* são as cores originais dos vértices, enquanto o *Color_reference* é a cor definida através do cálculo da interpolação.

Pelo fato da função *DrawLine* ter sido configurada para receber apenas dois pontos por vez, a DrawTriangle muda os parâmetros de coordenadas a cada rasterização de linha. Dessa forma, inicialmente é rasterizada a reta AB, em seguida BC e por fim, CA. Como as coordenadas são armazenadas em um struct, os valores das coordenadas são atualizados de acordo com a configuração da reta a ser rasterizada. O trecho de código abaixo exemplifica a atualização de parametros e da chamada da função. Vale salientar, que as cores também variam para cada vértice. 

```
//Atualização dos valores
    p->x1 = p->x3;
    p->y1 = p->y3;
    p->x2 = x_0;
    p->y2 = y_0;

//Rasterização da reta C->A
    DrawLine (p, C, A, Color_reference); 
```

Por fim, o resultado obtido com essa função é apresentado na Figura a seguir:

  <p align="center">
  <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/triangulo.png">
</p>


### Referências

- [Framework disponibilizado pelo professor](https://github.com/capagot/icg/tree/master/mygl_framework)
- [Material sobre interpolaçao de cores em RGBA](http://letslearnbits.blogspot.com/2014/10/icgt1-interpolacao-de-cores.html)

