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

Para esta atividade foram definidos três requisitos:
- **[x] Implementação da função PutPixel**  

  A função *PutPixel* recebe como entrada as coordenadas de um ponto e uma cor (RGBA). Para que dessa forma, possa rasterizar um ponto na memória de vídeo.
  
- **[x] Implementação da função DrawLine**

  Esta função rasteriza uma linha utilizando o algoritmo de Bresenham. Para isso,receberá como entrada as coordenadas de dois pontos e as cores atribuídas aos seus respectivos vértices. Com os dados dessas cores é realizada uma interpolação e a reta plotada é colorida com uma tonalidade degradê entre essas duas cores. 

- **[x] Implementação da função DrawTriangle**

  A função *DrawTriangle* recebe como parâmetros três vértice e suas respectivas cores, para que desse modo seja invocada a função *DrawLine* e un triângulo possa ser plotado.

### Estratégias

### Resultados e discussão

### Referências
