# Computacao-Gráfica

# Atividade 05
## Descrição

O objetivo deste trabalho é familiarizar os alunos com a estrutura do pipeline gráfico através da
implementação das transformações geométricas que o compõem. Esta implementação será feita com
auxílio da biblioteca glm e sua execução ocorrerá nos shaders do OpenGL.

  
### Requisitos

Para esta atividade foram definidos quatro requisitos:

- [x] **Exercício 01 - Escala**  

    Modificar a escala da matriz Model 

- [x] **Exercício 02 - Translação**  

    Aplicar alterações na Matriz model para transladar a Figura.

- [x] **Exercício 03 - Projeção Perspectiva**  

- [x] **Exercício 04 - Posição de Câmera**  

- [x] **Exercício 05 - Transformação Livre**  

## Exercício 01: Escala
### Descrição
   Para modificar a escala da imagem gerada pelo programa foi adicionado um fator multiplicate na matriz view, no qual
   o componente x da matriz identidade foi multiplicado por 1/3 e o eixo y foi multiplicado por 1,5. Dessa forma o Resultados
   obtido foi igual ao da Figura 01.
   A atividade consistiu na implementação de algoritmos e utilização do OpenGL para a rasterização de pontos, linhas e triângulos com interpolação de cores. Para a rasterização destas primitivas foi utilizado um framework de simulação ao acesso direto a memória de vídeo, forncido pelo professor.  
  
Por fim, o resultado obtido com essa função é apresentado na Figura a seguir:

  <p align="center">
  <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/Atividade_3/Imagens/escala.png">
</p>

### Referências

- [Definição do projeto](https://sig-arq.ufpb.br/arquivos/2020251182af5d2276812b448ad7142ee/trabalho_3.pdf)
- [Código suporte - disponibilizado pelo professor](https://github.com/capagot/icg/tree/master/03_transformations)
