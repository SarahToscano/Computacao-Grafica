#ifndef MYGL_H
#define MYGL_H

#include "core.h"
#include "frame_buffer.h"

typedef struct {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;

}Color;

typedef struct {
    int x1;
    int x2;
    int x3;
    int y1;
    int y2;
    int y3;

}Coordinates;

void MyGlDraw(void);

void PutPixel(int x1, int y1, Color *reference);
void DrawLine (Coordinates *p, Color *A, Color *B, Color *Color_reference);
void DrawTriangle(Coordinates *p, Color *A, Color *B, Color *C, Color *Color_reference);

//Funções para o interpolação das cores
double percetage(Coordinates *p, int x0, int y0);
void ColorGradient(Coordinates *p, int x0, int y0, Color *A, Color *B, Color *C, Color *color_mix);

#endif  // MYGL_H



//
// >>> Declare aqui as funções que você implementar <<<
//

#endif  // MYGL_H

