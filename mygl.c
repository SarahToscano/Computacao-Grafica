#include <stdlib.h>
#include <time.h>//bibliotecas utilizadas apenas para aleatorizar a posição das coordenadas
#include <stdio.h>
#include <math.h>

#include "mygl.h"

Color color_white, color_pink, color_red, color_yellow, color_blue, color_gradient;
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

    color_blue.r=0;
    color_blue.g=0;
    color_blue.b=255;
    color_blue.a=255;

    color_red.r=255;
    color_red.g=0;
    color_red.b=0;
    color_red.a=255;
}
                    
double percetage(Coordinates *p, int x0, int y0){
    
    int pf_x, pf_y;
    pf_x = p->x2;
    pf_y = p->y2;
    
    double dist_t= sqrt( pow((pf_x - x0), 2) + pow((pf_y - y0),2) );
    double dist_p= sqrt( pow((pf_x - p->x1),2) + pow((pf_y- p->y1),2) );
    double perc =  dist_p/dist_t;  
    
    return perc;
}

void ColorGradient(Coordinates *p, int x0, int y0, Color *A, Color *B, Color *C, Color *color_mix){
    double perc = percetage(p, x0, y0);
    color_mix->r = (A->r * perc) + ((1-perc)*B->r);
    color_mix->g = (A->g * perc) + ((1-perc)*B->g);
    color_mix->b = (A->b * perc) + ((1-perc)*B->b);
    color_mix->a = (A->a * perc) + ((1-perc)*B->a);
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

void DrawLine (Coordinates *p, Color *A, Color *B, Color *Color_reference){
  int x_aux=0, y_aux=0, dx_aux=0;

    //printf("x1:%d  y1:%d x2:%d  y2:%d\n", p->x1, p->y1, p->x2, p->y2);

    /*Primeira restrição
        X1>X2, a reta cresce para o lado negativo
        Desse modo, faz-se a inversão dos pontos*/
      if(p->x1 > p->x2){
        x_aux=p->x1;
        p->x1=p->x2;
        p->x2=x_aux;
        y_aux=p->y1;
        p->y1=p->y2;
        p->y2=y_aux;
    }

    int dx = p->x2 - p->x1;
    int dy = p->y2 - p->y1;
    int id_y_neg = 0;
    int id_y_x = 0;
    int dx_0= 0;


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

    int x0=p->x1; 
    int y0 =p->y1;


    if(dx==0){
        while(p->y1 <= p->y2){
            ColorGradient(p, x0, y0, A, B, B, Color_reference);
            PutPixel(p->x1,p->y1,Color_reference);
            p->y1++;
        }
    }
    else if((id_y_x==1) && (dy==0)){
        //printf("x1:%d  y1:%d x2:%d  y2:%d\n", p->x1, p->y1, p->x2, p->y2);
        while(p->y1<=p->y2){
            ColorGradient(p, x0, y0, A, B, B, Color_reference);
            PutPixel(p->x1,p->y1,Color_reference);
            p->y1++;
        }
    }
    else if(id_y_x==0){
        while(p->x1<=p->x2){
            ColorGradient(p, x0, y0, A, B, B, Color_reference);
            PutPixel(p->x1,p->y1,Color_reference);
            if(d<=0)
                d+=incr_e;
            else{
                d+=incr_ne;
                if(id_y_neg==1)
                    p->y1--;
                else
                    p->y1++;
            }
            p->x1++;
        }
    }
    else{
        if(p->y1>p->y2){
            while(p->y1>=p->y2){
                ColorGradient(p, x0, y0, A, B, B, Color_reference);
                PutPixel(p->x1,p->y1,Color_reference);
                if(d<=0)
                    d+=incr_e;
                else{
                    d+=incr_ne;
                    p->x1++;
                }
                p->y1--;
            }
        }
        else{
            while(p->y1<=p->y2){
                ColorGradient(p, x0, y0, A, B, B, Color_reference);
                PutPixel(p->x1,p->y1,Color_reference);
                if(d<=0)
                    d+=incr_e;
                else{
                    d+=incr_ne;
                    p->x1++;
                }
                p->y1++;
            }
        }
    }
    //puts("\n\n");
}

void DrawTriangle(Coordinates *p, Color *A, Color *B, Color *C, Color *Color_reference){
    int x_next;
    int y_next;
    int x_ini=p->x1;
    int y_ini=p->y1;
    x_next=p->x2;
    y_next=p->y2;

    //printf("A->B  xa:%d ya:%d xb:%d yb:%d\n",p->x1, p->y1, p->x2, p->y2);
    DrawLine (p, A, B, Color_reference); //(A->B)
    p->x1=x_next;
    p->y1=y_next;
    p->x2=p->x3;
    p->y2=p->y3;
    //printf("B->C  xb:%d yb:%d xc:%d yc:%d\n",p->x1, p->y1, p->x2, p->y2);
    DrawLine (p, B, C, Color_reference); //(B->C)

    p->x1=p->x3;
    p->y1=p->y3;
    p->x2=x_ini;
    p->y2=y_ini;
    //printf("C->A  xc:%d yc:%d xa:%d ya:%d\n",p->x1, p->y1, p->x2, p->y2);
    DrawLine (p, C, A, Color_reference); //(C->A)
    
}


void MyGlDraw(void) {
    
    srand(time(NULL));
    DefineColors();
    int i;

    //Chamada da função PutPixel

    for (i=0; i<30; i++){
        pixel_position.x1= rand() % IMAGE_WIDTH;
        pixel_position.y1= rand() % IMAGE_HEIGHT;
        PutPixel(pixel_position.x1,pixel_position.y1, &color_yellow);

        pixel_position.x2= rand() % IMAGE_WIDTH;
        pixel_position.y2= rand() % IMAGE_HEIGHT;
        PutPixel(pixel_position.x2,pixel_position.y2, &color_pink);

        pixel_position.x3= rand() % IMAGE_WIDTH;
        pixel_position.y3= rand() % IMAGE_HEIGHT;
        PutPixel(pixel_position.x3,pixel_position.y3, &color_blue);
    }



    //Chamada da função DrawLine
        //Teste Dx>0 e Dy>0
        pixel_position.x1= 0;
        pixel_position.y1= 0;
        pixel_position.x2= IMAGE_WIDTH;
        pixel_position.y2= IMAGE_WIDTH;
        DrawLine (&pixel_position, &color_pink, &color_white, &color_gradient);

        //Teste para Dx>0 e Dy<0
        pixel_position.x1= 200;
        pixel_position.y1= 200;
        pixel_position.x2= IMAGE_WIDTH;
        pixel_position.y2= 0;
        DrawLine (&pixel_position, &color_red,&color_yellow,&color_gradient);

        //Teste para Dx<0 e Dy>0
        pixel_position.x1= 511;
        pixel_position.y1= 0;
        pixel_position.x2= 256;
        pixel_position.y2= 511;
        DrawLine (&pixel_position, &color_blue,&color_red,&color_gradient);

        //Teste para Dx<0 e Dy<0
        pixel_position.x1= 310;
        pixel_position.y1= IMAGE_HEIGHT;
        pixel_position.x2= 420;
        pixel_position.y2= 0;
        DrawLine (&pixel_position, &color_blue, &color_yellow, &color_gradient);


    //Chamada da Função DrawTriangle

    pixel_position.x1= 256;
    pixel_position.y1= 10;
    pixel_position.x2= 10;
    pixel_position.y2= 256;
    pixel_position.x3= 500;
    pixel_position.y3= 256;

    DrawTriangle(&pixel_position, &color_blue, &color_red, &color_white, &color_gradient);

}
