# Computacao-Gráfica

# Atividade 05
## Descrição

O objetivo deste trabalho é familiarizar os alunos com a estrutura do pipeline gráfico através da
implementação das transformações geométricas que o compõem. Esta implementação será feita com
auxílio da biblioteca glm e sua execução ocorrerá nos shaders do OpenGL.

  
### Requisitos

Para esta atividade foram definidos quatro requisitos:

- [x] **Exercício 01 - Escala**  

    Modificar a escala da matriz Model. 

- [x] **Exercício 02 - Translação**  

    Aplicar alterações na Matriz model para transladar a Figura.

- [x] **Exercício 03 - Projeção Perspectiva** 

    Modificar a matriz de projeção para um d = 1/2.

- [x] **Exercício 04 - Posição de Câmera**  

- [x] **Exercício 05 - Transformação Livre**  

## Exercício 01: Escala
### Descrição
  Para modificar a escala da imagem gerada pelo programa foi adicionado um fator multiplicate na matriz view, no qual
  o componente x da matriz identidade (posição 0 do model_array) foi multiplicado por 0.33 e o eixo y foi multiplicado por 1,5 (posição 5 do model_array). Dessa forma o resultado
  obtido está ilustrado na Figura a seguir:   

  <p align="center">
    <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/Atividade_3/Imagens/escala.png">
  </p>

## Exercício 02: Translação
### Descrição
  Para aplicar a translação em coordenadas homogêneas foi utilizado o seguinte princípio, a nova posição da Figura no eixo x
  seria equivalente a posição original somada da distância equivalencia a translação no eixo. Dessa forma, como o intuito seria transladar
  a figura com a escala (1,0,0) foi adicionado o valor (1) na última linha da matriz model. Assim a posição 12 desse vetor foi alterada com o valor da 
  distância equivalente a translação. Para as coordenadas Y e Z não foram necessárias alterações. O resultado está ilustrado na Figura abaixo:

  <p align="center">
    <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/Atividade_3/Imagens/trans.png">
  </p>

## Exercício 03: Projeção Perspectiva
### Descrição
  Para modificar a matriz de projeção para adicionarmos o parâmetro d = 1/2, foi utilizada a matriz de projeção que considera
   a câmera na origem do seu sistema de coordenadas. Para alterarmos o código é importante salientar que a matriz da forma em que foi estudada
   apresenta-se de modo diferente na programação. Pois suas linhas equivalem as colunas da matriz de projeção do arquivo main.cpp, ou seja
   o 'd' deve ser incluido na Dessa forma, foi preciso adicionar o valor 'd' na posição 14 do 'proj_array', enquanto o valor '-1/d'
   deve ser inserido na posição 11. Dessa forma ficamos com o seguinte resultado:
  <p align="center">
    <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/Atividade_3/Imagens/proje.png">
  </p>

### Referências

- [Definição do projeto](https://sig-arq.ufpb.br/arquivos/2020251182af5d2276812b448ad7142ee/trabalho_3.pdf)
- [Código suporte - disponibilizado pelo professor](https://github.com/capagot/icg/tree/master/03_transformations)
