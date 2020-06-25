#include <stdlib.h>
#include <time.h>//bibliotecas utilizadas apenas para aleatorizar a posição das coordenadas
#include <stdio.h>
#include <math.h>

#include "mygl.h"

Color color_white, color_pink, color_red, color_yellow, color_cyan, color_gradient;
Coordinates pixel_position;

void DefineColors(void){
    color_white.r=255;
    color_white.g=255;
    color_white.b=255;
    color_white.a=255;

    color_pink.r=255;
    color_pink.g=20;
    color_pink.b=147;
    color_pink.a=255;

    color_yellow.r=255;
    color_yellow.g=255;
    color_yellow.b=0;
    color_yellow.a=255;

    color_cyan.r=0;
    color_cyan.g=255;
    color_cyan.b=255;
    color_cyan.a=255;

    color_red.r=255;
    color_red.g=0;
    color_red.b=0;
    color_red.a=255;

}
                    
float Distance(int x1, int y1, int x2, int y2){
    int dx = abs( x2 - x1);
    int dy = abs( y2 - y1);
    float d = sqrt((dx*dx)+(dy*dy));
    return d;
}

void ColorGradient(int x1, int y1, int x2, int y2, Color *A, Color *B, Color *C){
    float d = Distance(x1,y1,x2,y2);
    C->r = (B->r * d) + ((1-d)*A->r);
    C->g = (B->g * d) + ((1-d)*A->g);
    C->b = (B->b * d) + ((1-d)*A->b);
    C->a = (B->a * d) + ((1-d)*A->a);
}


void PutPixel(int x, int y, Color *Color_reference ){
    //Rasteriza um ponto na memória de vídeo recebendo como parâmetros as
    //coordenadas (x,y) do pixel na tela e sua cor (RGBA).
    
    int offset;
    offset=x*4 + y*4*IMAGE_WIDTH;
    fb_ptr[offset++]= Color_reference->r;
    fb_ptr[offset++]= Color_reference->g;
    fb_ptr[offset++]= Color_reference->b;
    fb_ptr[offset++]= Color_reference->a;
}

void DrawLine (int x1, int y1, int x2, int y2, Color *A, Color *B, Color *Color_reference){
  int x_aux=0, y_aux=0, dx_aux=0;

    
    /*Primeira restrição
        X1>X2, a reta cresce para o lado negativo
        Desse modo, faz-se a inversão dos pontos*/
      if(x1>x2){
        x_aux=x1;
        x1=x2;
        x2=x_aux;
        y_aux=y1;
        y1=y2;
        y2=y_aux;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;
    int id_y_neg = 0;
    int id_y_x = 0;


    /* Segunda Restrição, dy negativo
        Inverte-se se sinal do dy(east-northeast) e o y é decrementado na função*/
      if(dy<0){
        dy=dy*-1;
        id_y_neg=1;
    }

    /*Terceira restrição, variacao de dy maior q dx
        atribui a variacao do eixo x ao y, e vice-versa
        Além disso, a condicao do while eh especial
        por isso tera um diferente*/
    
      if(dy>dx){
        dx_aux=dx;
        dx=dy;
        dy=dx_aux;
        id_y_x=1; //variacao de y>x, flag
    }

    int d = 2*dy-dx;
    int incr_e = 2*dy;
    int incr_ne= 2*(dy - dx);

    if(id_y_x==0){
        while(x1<=x2){
            ColorGradient(x1, y1, x2, y2, A, B, Color_reference);
            PutPixel(x1,y1,Color_reference);
            if(d<=0)
                d+=incr_e;
            else{
                d+=incr_ne;
                if(id_y_neg==1)
                    y1--;
                else
                    y1++;
            }
            x1++;
        }
    }
    else{
        while(y1>=y2){
            ColorGradient(x1, y1, x2, y2, A, B, Color_reference);
            PutPixel(x1,y1,Color_reference);
            //printf("D: %d  icr_e:%d  icr_ne: %d  X: %d   Y:%d  \n",d,incr_e, incr_ne, x1,y1);
            if(d<=0)
                d+=incr_e;
            else{
                d+=incr_ne;
                x1++;
            }
            y1--;
        }
    }
    //printf("\n\n");
}


void MyGlDraw(void) {
    
    srand(time(NULL));
    DefineColors();
    int i;

    /*for (i=0; i<30; i++){
        pixel_position.x1= rand() % IMAGE_WIDTH;
        pixel_position.y1= rand() % IMAGE_HEIGHT;
        PutPixel(pixel_position.x1,pixel_position.y1, &color_yellow);

        pixel_position.x2= rand() % IMAGE_WIDTH;
        pixel_position.y2= rand() % IMAGE_HEIGHT;
        PutPixel(pixel_position.x2,pixel_position.y2, &color_pink);

        pixel_position.x3= rand() % IMAGE_WIDTH;
        pixel_position.y3= rand() % IMAGE_HEIGHT;
        PutPixel(pixel_position.x3,pixel_position.y3, &color_cyan);
    }
*/

    //Teste para X2>X1 -- Dx>0 e Dy>0
    pixel_position.x1= 0;
    pixel_position.y1= 0;
    pixel_position.x2= IMAGE_WIDTH;
    pixel_position.y2= IMAGE_HEIGHT;
    DrawLine (pixel_position.x1, pixel_position.y1, pixel_position.x2, pixel_position.y2, &color_pink, &color_white, &color_gradient);

    //Teste para Dx<0 e Dy<0
    pixel_position.x1= 310;
    pixel_position.y1= 200;
    pixel_position.x2= 0;
    pixel_position.y2= 0;
    DrawLine (pixel_position.x1, pixel_position.y1, pixel_position.x2, pixel_position.y2, &color_pink,&color_white, &color_gradient);

    //Teste para X1>X2 -- Dx<0 e Dy>0
    pixel_position.x1= IMAGE_WIDTH;
    pixel_position.y1= 0;
    pixel_position.x2= 0;
    pixel_position.y2= IMAGE_HEIGHT;
    DrawLine (pixel_position.x1, pixel_position.y1, pixel_position.x2, pixel_position.y2, &color_white,&color_white, &color_gradient);

    //Teste para Dx>0 e Dy<0
    pixel_position.x1= 200;
    pixel_position.y1= 200;
    pixel_position.x2= IMAGE_WIDTH;
    pixel_position.y2= 0;
    DrawLine (pixel_position.x1, pixel_position.y1, pixel_position.x2, pixel_position.y2, &color_cyan,&color_white, &color_gradient);

    pixel_position.x1= 0;
    pixel_position.y1= 511;
    pixel_position.x2= 200;
    pixel_position.y2= 200;
    DrawLine (pixel_position.x1, pixel_position.y1, pixel_position.x2, pixel_position.y2, &color_cyan,&color_white, &color_gradient);

    //Teste para Dy=0
    pixel_position.x1= 0;
    pixel_position.y1= 256;
    pixel_position.x2= IMAGE_WIDTH;
    pixel_position.y2= 256;
    DrawLine (pixel_position.x1, pixel_position.y1, pixel_position.x2, pixel_position.y2, &color_yellow,&color_white, &color_gradient);

    pixel_position.x1= 0;
    pixel_position.y1= 0;
    pixel_position.x2= IMAGE_WIDTH;
    pixel_position.y2= IMAGE_WIDTH;
    DrawLine (pixel_position.x1, pixel_position.y1, pixel_position.x2, pixel_position.y2, &color_red,&color_cyan, &color_gradient);


}

