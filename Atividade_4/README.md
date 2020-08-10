# Modelos de Iluminação

# Computação Gráfica - Atividade 04
## Especificação da Atividade

Esta atividade consiste em 2 questões, as quais buscam realizar modificações no modelo de reflexão aplicado ao objeto.
Desse modo, serão aplicados modelos de iluminação tradicionalmente utilizados na rasterização: ambiente, difuso e especular 
A partir de um código em C++ disponibilizado pelo professor da disciplina de Computação Gráfica. Esta implementação
terá o auxílio da biblioteca glm e sua execução ocorrerá nos shaders do OpenGL.

  
### Requisitos

Para esta atividade foram definidos cinco requisitos:

- [x] **Exercício 01 - Implementação do Modelo de Reflexão Difuso**  

- [x] **Exercício 02 - Implementação do Modelo de Reflexão Especular**  


## Exercício 01: Implementação do Modelo de Reflexão Difuso
### Estratégias e Resultados
  
Este exercício consiste em se alterar o conteúdo do vertex shader (arquivo vertex_shader.glsl) de forma a se 
adicionarem os modelos de reflexão difuso e especular. Para isso, após as transformações feitas pela matriz Model
foram recalculados os seguintes vetores:
  - Vetor normal N;
  - Vetor L.
Assim, para realizar a multiplicação desses vetores não normais utiliza-se um recurso chamado "dot".
Dessa forma, uma vez que o resultado deste produto é equivalente ao cosseno presente no cálculo do modelo de iluminação ambiente, 
atualizam-se esses valores e obtem-se o seguinte resultado.

 <p align="center">
    <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/Atividade_4/Image/bule1.png">
  </p>


## Exercício 02: Implementação do Modelo de Reflexão Especular
### Estratégias 
  Este exercício consistirá em adicionar o modelo espetacular de iluminação ao objeto gerado no item anterior, o qual já possui
  os modelos de iluminação ambiente e difuso. As modificações também serão realizadas através de alterações no vertex shader.
  Devem ser seguidas as instruções abaixo:
  - Calcular o vetor R,de reflexão da luz L;
  - Calcular o vetor da câmera V, que aponta do vértice em questão para a câmera;
  - Ajustar o cálculo do modelo de iluminação para o modelo de Phong.

  ### Problemas

  Ao ajustar o modelo do cálculo de iluminação para o modelo Phong é necessário inclui na fórmula a potência do termo espetacular.
  No entanto, ao realizar o cálculo de potência com a função "pow" com o n igual a 64, o resultado obtido foi diferente do esperado, como ilustra a Figura baixo.

  <p align="center">
    <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/Atividade_4/Image/bule_errado.png">
  </p>


  Pode-se perceber que no fundo do bule temos uma iluminação não desejada, dessa forma. Foi realizado o caso de teste com o n igual a 65 e 
  mantendo-se o uso da função "pow", mas o resultado permaneceu o mesmo.

  ### Resultado
  
    Desse modo, o Cálculo da potência teve de ser realizado de forma bruta através de um laço de repetição (sem o uso da função "pow"), com o n igual a 65, para que dessa forma o resultado esperado fosse alcançado.
    O resultado foi o seguinte:

     <p align="center">
    <img src="https://github.com/SAndradeTC/Computacao-Grafica/blob/master/Atividade_4/Image/bule2.png">
  </p>


  
### Referências

- [Definição do projeto](https://sig-arq.ufpb.br/arquivos/202004601628a22351319359d68daf29e/trabalho_4.pdf)
