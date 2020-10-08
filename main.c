#include <stdio.h>
#include <allegro.h>
#include <stdlib.h>
#define MAXFILAS 20
#define MAXCOLS  31

BITMAP * buffer;
BITMAP * barco;
BITMAP * agua;
BITMAP * hielo;
BITMAP * destruir;
BITMAP * uno;
BITMAP * dos;
BITMAP * tres;
BITMAP * cuatro;
BITMAP * cinco;
BITMAP * seis;
BITMAP * siete;
BITMAP * ocho;
BITMAP * nueve;
BITMAP * diez;
BITMAP * Perder;
BITMAP * cambiar;
BITMAP * Ganar;
BITMAP * Empatar;
BITMAP * menu;
BITMAP * jugar;
BITMAP * instrucciones;
BITMAP * Salir;
BITMAP * cursor;
BITMAP * Juego;
BITMAP * limpiar;
BITMAP * ganarcursor;
BITMAP * perdercursor;
BITMAP * ClicInstruccion;
MIDI * musicafondo;

char matriz[11][11]={
  " 123456789A",
  "1..........",
  "2..........",
  "3..........",
  "4..........",
  "5..........",
  "6..........",
  "7..........",
  "8..........",
  "9..........",
  "A..........",
};
char matrizA[11][11]={
  " 123456789A",
  "1..........",
  "2..........",
  "3..........",
  "4..........",
  "5..........",
  "6..........",
  "7..........",
  "8..........",
  "9..........",
  "A..........",
};
char matrizpc[11][11]={
  " 123456789A",
  "1..........",
  "2..........",
  "3..........",
  "4..........",
  "5..........",
  "6..........",
  "7..........",
  "8..........",
  "9..........",
  "A..........",
};
char matrizApc[11][11]={
  " 123456789A",
  "1..........",
  "2..........",
  "3..........",
  "4..........",
  "5..........",
  "6..........",
  "7..........",
  "8..........",
  "9..........",
  "A..........",
};
char mostrarmatriz[11][11]={
  " 123456789A",
  "1..........",
  "2..........",
  "3..........",
  "4..........",
  "5..........",
  "6..........",
  "7..........",
  "8..........",
  "9..........",
  "A..........",
};

void dibujar_matriz()
{
    int i, j;
    int trow,tcol;
    for(i=0 ; i<11;i++)
    {
        for(j=0 ; j<11; j++)
        {
            if(matriz[i][j]==' ')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, limpiar, tcol, trow);
            }
            if(matriz[i][j]== '.')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, agua, tcol, trow);
            }else if(matriz[i][j]=='*')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, barco, tcol, trow);
            }
            if(matriz[i][j]=='x')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, destruir, tcol, trow);
            }
            if(matriz[i][j]=='o')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, hielo, tcol, trow);
            }
            else if(matriz[i][j]=='1')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, uno, tcol, trow);
            }else if(matriz[i][j]=='2')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, dos, tcol, trow);
            }else if(matriz[i][j]=='3')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, tres, tcol, trow);
            }
            else if(matriz[i][j]=='4')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, cuatro, tcol, trow);
            }else if(matriz[i][j]=='5')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, cinco, tcol, trow);
            }else if(matriz[i][j]=='6')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, seis, tcol, trow);
            }else if(matriz[i][j]=='7')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, siete, tcol, trow);
            }else if(matriz[i][j]=='8')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, ocho, tcol, trow);
            }
            else if(matriz[i][j]=='9')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, nueve, tcol, trow);
            }
            else if(matriz[i][j]=='A')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, diez, tcol, trow);
            }
        }
    }
}
void dibujar_matrizA()
{
    int i,j;
    int trow,tcol;
    for(i=0 ; i<11;i++)
    {
        for(j=0 ; j<11; j++)
        {
            if(matrizA[i][j]=='.')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, agua, tcol, trow);
            }else if(matrizA[i][j]=='*')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, barco, tcol, trow);
            }
            if(matrizA[i][j]=='x')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, destruir, tcol, trow);
            }
            if(matrizA[i][j]=='o')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, hielo, tcol, trow);
            }else if(matrizA[i][j]=='1')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, uno, tcol, trow);
            }else if(matrizA[i][j]=='2')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, dos, tcol, trow);
            }else if(matrizA[i][j]=='3')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, tres, tcol, trow);
            }
            else if(matrizA[i][j]=='4')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, cuatro, tcol, trow);
            }else if(matrizA[i][j]=='5')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, cinco, tcol, trow);
            }else if(matrizA[i][j]=='6')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, seis, tcol, trow);
            }else if(matrizA[i][j]=='7')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, siete, tcol, trow);
            }else if(matrizA[i][j]=='8')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, ocho, tcol, trow);
            }
            else if(matrizA[i][j]=='9')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, nueve, tcol, trow);
            }
            else if(matrizA[i][j]=='A')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, diez, tcol, trow);
            }
        }
    }
}
void dibujar_matrizmostrar()
{
    int i, j;
    int trow,tcol;
    for(i=0 ; i<11;i++)
    {
        for(j=0 ; j<11; j++)
        {
            if(mostrarmatriz[i][j]== '.')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, agua, tcol, trow);
            }else if(mostrarmatriz[i][j]=='*')
            {
                trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, barco, tcol, trow);
            }
            else if(mostrarmatriz[i][j]=='1')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, uno, tcol, trow);
            }else if(mostrarmatriz[i][j]=='2')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, dos, tcol, trow);
            }else if(mostrarmatriz[i][j]=='3')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, tres, tcol, trow);
            }
            else if(mostrarmatriz[i][j]=='4')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, cuatro, tcol, trow);
            }else if(mostrarmatriz[i][j]=='5')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, cinco, tcol, trow);
            }else if(mostrarmatriz[i][j]=='6')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, seis, tcol, trow);
            }else if(mostrarmatriz[i][j]=='7')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, siete, tcol, trow);
            }else if(mostrarmatriz[i][j]=='8')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, ocho, tcol, trow);
            }
            else if(mostrarmatriz[i][j]=='9')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, nueve, tcol, trow);
            }
            else if(mostrarmatriz[i][j]=='A')
            {
               trow=i*40;
                tcol=j*40;
                draw_sprite(buffer, diez, tcol, trow);
            }
        }
    }
}
void pantalla()
{
    blit(buffer,screen,0,0,0,0,440,440);
}
void pantallapc()
{
    blit(buffer,screen,0,0,440,0,440,440);
}
void pantallamostrar()
{
    blit(buffer,screen,0, 0, 0, 100,440,440);
}
void llenarbarcos()
{
    int pos1, pos2, i, j, cont=0, verhor;
    srand(time(NULL));
    pos1=rand()%5+1; //Genera aletoriamente la cordenada y
    pos2=rand()%5+1; //Genera aleatoriamente la cordenada x
    verhor=rand()%2+1; //Genera aleatoriamente 1)Vertical 2)Horizontal
    if(verhor==1)
    {
        for(i=pos2; i<pos2+5; i++)
        {
        matrizA[pos1][i]='*'; //Asgina * en donde van a estar los barcos en la matriz
        }
    }
    if(verhor==2)
    {
        for(i=pos1; i<pos1+5; i++)
        {
        matrizA[i][pos2]='*';
        }
    }
    for(j=0; j<2; j++)
    {
    do{
        cont=0;
        pos1=rand()%6+1; //Genera aletoriamente la cordenada y
        pos2=rand()%6+1; //Genera aleatoriamente la cordenada x
        verhor=rand()%2+1; //Genera aleatoriamente 1)Vertical 2)Horizontal
            if(verhor==1)
            {
                for(i=pos2; i<pos2+4; i++)
                {
                    if(matrizA[pos1][i]=='*')
                    {
                        cont++;
                    }

                }
            }
            if(verhor==2)
            {
                for(i=pos1; i<pos1+4; i++)
                {
                    if(matrizA[i][pos2]=='*')
                    {
                        cont++;
                    }
                }
            }
    }while(cont>0);
    if(verhor==1)
        {
            for(i=pos2; i<pos2+4; i++)
            {
            matrizA[pos1][i]='*'; //Asgina un * en las posiciones donde van a estar los barcos en la matriz
            }
        }
        if(verhor==2)
        {
            for(i=pos1; i<pos1+4; i++)
            {
            matrizA[i][pos2]='*';
            }
        }
    }

    for(j=0; j<4; j++)
    {
        do{
            cont=0;
            pos1=rand()%7+1; //Genera aletoriamente la cordenada y
            pos2=rand()%7+1; //Genera aleatoriamente la cordenada x
            verhor=rand()%2+1; //Genera aleatoriamente 1)Vertical 2)Horizontal
                if(verhor==1)
                {
                    for(i=pos2; i<pos2+3; i++)
                    {
                        if(matrizA[pos1][i]=='*')
                        {
                            cont++;
                        }

                    }
                }
                if(verhor==2)
                {
                    for(i=pos1; i<pos1+3; i++)
                    {
                        if(matrizA[i][pos2]=='*')
                        {
                            cont++;
                        }
                    }
                }
        }while(cont>0);
    if(verhor==1)
    {
        for(i=pos2; i<pos2+3; i++)
        {
            matrizA[pos1][i]='*';
        }
    }
    if(verhor==2)
    {
        for(i=pos1; i<pos1+3; i++)
        {
            matrizA[i][pos2]='*';
        }
    }
    }

    for(j=0; j<4; j++)
    {
            do{
                    cont=0;
                    pos1=rand()%8+1; //Genera aletoriamente la cordenada y
                    pos2=rand()%8+1; //Genera aleatoriamente la cordenada x
                    verhor=rand()%2+1; //Genera aleatoriamente 1)Vertical 2)Horizontal
                        if(verhor==1)
                        {
                            for(i=pos2; i<pos2+2; i++)
                            {
                                if(matrizA[pos1][i]=='*')
                                {
                                    cont++;
                                }
                            }
                        }
    if(verhor==2)
        {
            for(i=pos1; i<pos1+2; i++)
            {
                if(matrizA[i][pos2]=='*')
                {
                    cont++;
                }
            }
        }
            }while(cont>0);

    if(verhor==1)
    {
        for(i=pos2; i<pos2+2; i++)
        {
            matrizA[pos1][i]='*';
        }
    }
    if(verhor==2)
    {
        for(i=pos1; i<pos1+2; i++)
        {
            matrizA[i][pos2]='*';
        }
    }
    }
}
void llenarbarcospc()
{
    int pos1, pos2, i, j, cont=0, verhor;
    srand(time(NULL));
    pos1=rand()%5+1; //Genera aletoriamente la cordenada y
    pos2=rand()%5+1; //Genera aleatoriamente la cordenada x
    verhor=rand()%2+1; //Genera aleatoriamente 1)Vertical 2)Horizontal
    if(verhor==1)
    {
        for(i=pos2; i<pos2+5; i++)
        {
        matrizApc[pos1][i]='*'; //Asgina * en donde van a estar los barcos en la matriz
        }
    }
    if(verhor==2)
    {
        for(i=pos1; i<pos1+5; i++)
        {
            matrizApc[i][pos2]='*';
        }
    }
    for(j=0; j<2; j++)
    {
    do{
        cont=0;
        pos1=rand()%6+1; //Genera aletoriamente la cordenada y
        pos2=rand()%6+1; //Genera aleatoriamente la cordenada x
        verhor=rand()%2+1; //Genera aleatoriamente 1)Vertical 2)Horizontal
            if(verhor==1)
            {
                for(i=pos2; i<pos2+4; i++)
                {
                    if(matrizApc[pos1][i]=='*')
                    {
                        cont++;
                    }

                }
            }
            if(verhor==2)
            {
                for(i=pos1; i<pos1+4; i++)
                {
                    if(matrizApc[i][pos2]=='*')
                    {
                        cont++;
                    }
                }
            }
    }while(cont>0);
    if(verhor==1)
        {
            for(i=pos2; i<pos2+4; i++)
            {
                matrizApc[pos1][i]='*'; //Asgina un * en las posiciones donde van a estar los barcos en la matriz
            }
        }
        if(verhor==2)
        {
            for(i=pos1; i<pos1+4; i++)
            {
                matrizApc[i][pos2]='*';
            }
        }
    }

    for(j=0; j<4; j++)
    {
        do{
            cont=0;
            pos1=rand()%7+1; //Genera aletoriamente la cordenada y
            pos2=rand()%7+1; //Genera aleatoriamente la cordenada x
            verhor=rand()%2+1; //Genera aleatoriamente 1)Vertical 2)Horizontal
                if(verhor==1)
                {
                    for(i=pos2; i<pos2+3; i++)
                    {
                        if(matrizApc[pos1][i]=='*')
                        {
                            cont++;
                        }

                    }
                }
                if(verhor==2)
                {
                    for(i=pos1; i<pos1+3; i++)
                    {
                        if(matrizApc[i][pos2]=='*')
                        {
                            cont++;
                        }
                    }
                }
        }while(cont>0);

    if(verhor==1)
    {
        for(i=pos2; i<pos2+3; i++)
        {
            matrizApc[pos1][i]='*';
        }
    }
    if(verhor==2)
    {
        for(i=pos1; i<pos1+3; i++)
        {
            matrizApc[i][pos2]='*';
        }
    }
    }

    for(j=0; j<4; j++)
    {
        do{
                cont=0;
                pos1=rand()%8+1; //Genera aletoriamente la cordenada y
                pos2=rand()%8+1; //Genera aleatoriamente la cordenada x
                verhor=rand()%2+1; //Genera aleatoriamente 1)Vertical 2)Horizontal
                    if(verhor==1)
                    {
                        for(i=pos2; i<pos2+2; i++)
                        {
                            if(matrizApc[pos1][i]=='*')
                            {
                                cont++;
                            }
                        }
                    }
                    if(verhor==2)
                    {
                        for(i=pos1; i<pos1+2; i++)
                        {
                            if(matrizApc[i][pos2]=='*')
                            {
                            cont++;
                            }
                        }
                    }
        }while(cont>0);

    if(verhor==1)
    {
        for(i=pos2; i<pos2+2; i++)
        {
            matrizApc[pos1][i]='*';
        }
    }
    if(verhor==2)
    {
        for(i=pos1; i<pos1+2; i++)
        {
            matrizApc[i][pos2]='*';
        }
    }
    }
    for(i=0; i<11; i++)
    {
        for(j=0; j<11; j++)
        {
            mostrarmatriz[i][j]=matrizApc[i][j];
        }
    }
}

void atacar()
{
    int i, j, cont=0, contajugador=0, ataque_x, ataque_y, contapc=0, ataque_x_pc, ataque_y_pc, clic=1;;
    srand(time(NULL));
    blit(cambiar, screen, 0, 0, 0, 440, 880, 100);
    do{
            do{
                    textprintf(screen, font, 20, 450, palette_color[11], "Coordenada x:");
                    readkey();
                    if(key[KEY_1])
                    {
                        ataque_x=1;
                    }
                    if(key[KEY_2])
                    {
                        ataque_x=2;
                    }
                    if(key[KEY_3])
                    {
                        ataque_x=3;
                    }
                    if(key[KEY_4])
                    {
                        ataque_x=4;
                    }
                    if(key[KEY_5])
                    {
                        ataque_x=5;
                    }
                    if(key[KEY_6])
                    {
                        ataque_x=6;
                    }
                    if(key[KEY_7])
                    {
                        ataque_x=7;
                    }
                    if(key[KEY_8])
                    {
                        ataque_x=8;
                    }
                    if(key[KEY_9])
                    {
                        ataque_x=9;
                    }
                    if(key[KEY_0])
                    {
                        ataque_x=10;
                    }
                    if(!key[KEY_0] && !key[KEY_1] && !key[KEY_2] && !key[KEY_3] && !key[KEY_4] && !key[KEY_5] && !key[KEY_6] && !key[KEY_7] && !key[KEY_8] && !key[KEY_9])
                        {
                            ataque_x=0;
                        }
                    textprintf(screen, font, 130, 450, palette_color[11], "%d", ataque_x);
                    clear_keybuf();
            }while(ataque_x<1 || ataque_x>10);

                do{
                        textprintf(screen, font, 20, 460, palette_color[11], "Coordenada y:");
                        readkey();
                        if(key[KEY_1])
                        {
                            ataque_y=1;
                        }
                        if(key[KEY_2])
                        {
                            ataque_y=2;
                        }
                        if(key[KEY_3])
                        {
                            ataque_y=3;
                        }
                        if(key[KEY_4])
                        {
                            ataque_y=4;
                        }
                        if(key[KEY_5])
                        {
                            ataque_y=5;
                        }
                        if(key[KEY_6])
                        {
                            ataque_y=6;
                        }
                        if(key[KEY_7])
                        {
                            ataque_y=7;
                        }
                        if(key[KEY_8])
                        {
                            ataque_y=8;
                        }
                        if(key[KEY_9])
                        {
                            ataque_y=9;
                        }
                        if(key[KEY_0])
                        {
                            ataque_y=10;
                        }
                        if(!key[KEY_0] && !key[KEY_1] && !key[KEY_2] && !key[KEY_3] && !key[KEY_4] && !key[KEY_5] && !key[KEY_6] && !key[KEY_7] && !key[KEY_8] && !key[KEY_9])
                        {
                            ataque_y=0;
                        }
                        textprintf(screen, font, 130, 460, palette_color[11], "%d", ataque_y);
                        clear_keybuf();
                }while(ataque_y<1 || ataque_y>10);

    while(matriz[ataque_y][ataque_x]!='.')
    {
        textprintf(screen, font, 20, 470, palette_color[12], "ERROR! Ya se te ataco esa posicion o no existe");
        textprintf(screen, font, 20, 480, palette_color[9], "Dame otra posicion");
        textprintf(screen, font, 20, 490, palette_color[15], "Presiona una tecla para continuar...");
                        readkey();
                        blit(cambiar, screen, 0, 0, 0, 450, 880, 100);
                        clear_keybuf();
        do{
                textprintf(screen, font, 20, 450, palette_color[11], "Coordenada x:");
                    readkey();
                    if(key[KEY_1])
                    {
                        ataque_x=1;
                    }
                    if(key[KEY_2])
                    {
                        ataque_x=2;
                    }
                    if(key[KEY_3])
                    {
                        ataque_x=3;
                    }
                    if(key[KEY_4])
                    {
                        ataque_x=4;
                    }
                    if(key[KEY_5])
                    {
                        ataque_x=5;
                    }
                    if(key[KEY_6])
                    {
                        ataque_x=6;
                    }
                    if(key[KEY_7])
                    {
                        ataque_x=7;
                    }
                    if(key[KEY_8])
                    {
                        ataque_x=8;
                    }
                    if(key[KEY_9])
                    {
                        ataque_x=9;
                    }
                    if(key[KEY_0])
                    {
                        ataque_x=10;
                    }
                    if(!key[KEY_0] && !key[KEY_1] && !key[KEY_2] && !key[KEY_3] && !key[KEY_4] && !key[KEY_5] && !key[KEY_6] && !key[KEY_7] && !key[KEY_8] && !key[KEY_9])
                        {
                            ataque_x=0;
                        }
                    textprintf(screen, font, 130, 450, palette_color[11], "%d", ataque_x);
                    clear_keybuf();
    }while(ataque_x<1 || ataque_x>10);
                do{
                        textprintf(screen, font, 20, 460, palette_color[11], "Coordenada y: ", ataque_y);
                        readkey();
                        if(key[KEY_1])
                        {
                            ataque_y=1;
                        }
                        if(key[KEY_2])
                        {
                            ataque_y=2;
                        }
                        if(key[KEY_3])
                        {
                            ataque_y=3;
                        }
                        if(key[KEY_4])
                        {
                            ataque_y=4;
                        }
                        if(key[KEY_5])
                        {
                            ataque_y=5;
                        }
                        if(key[KEY_6])
                        {
                            ataque_y=6;
                        }
                        if(key[KEY_7])
                        {
                            ataque_y=7;
                        }
                        if(key[KEY_8])
                        {
                            ataque_y=8;
                        }
                        if(key[KEY_9])
                        {
                            ataque_y=9;
                        }
                        if(key[KEY_0])
                        {
                            ataque_y=10;
                        }
                        if(!key[KEY_0] && !key[KEY_1] && !key[KEY_2] && !key[KEY_3] && !key[KEY_4] && !key[KEY_5] && !key[KEY_6] && !key[KEY_7] && !key[KEY_8] && !key[KEY_9])
                        {
                            ataque_y=0;
                        }
                        textprintf(screen, font, 130, 460, palette_color[11], "%d", ataque_y);
                        clear_keybuf();
                }while(ataque_y<1 || ataque_y>10);

    }
                        textprintf(screen, font, 20, 480, palette_color[15], "Presiona una tecla para continuar...");
                        readkey();
                        blit(cambiar, screen, 0, 0, 0, 440, 880, 100);
                        textprintf(screen, font, 20, 470, palette_color[11], "Atacaste en (%d, %d)", ataque_x, ataque_y);
    if(matrizApc[ataque_y][ataque_x]=='*')
    {
        matriz[ataque_y][ataque_x]='x';
        textprintf(screen, font, 20, 480, palette_color[11], "Acertaste el ataque! ");
        contajugador++;
    }
    else
        {
            textprintf(screen, font, 20, 480, palette_color[11], "Fallaste el ataque! ");
            matriz[ataque_y][ataque_x]='o';
        }
        ataque_x_pc=rand()%10+1;
        ataque_y_pc=rand()%10+1;
        while(matrizA[ataque_y_pc][ataque_x_pc]=='o' || matrizA[ataque_y_pc][ataque_x_pc]=='x')
        {
            ataque_x_pc=rand()%10+1;
            ataque_y_pc=rand()%10+1;
        }
        textprintf(screen, font, 20, 490, palette_color[11], "La pc te ataco en (%d, %d)", ataque_x_pc, ataque_y_pc);
        if(matrizA[ataque_y_pc][ataque_x_pc]=='*')
    {
        matrizA[ataque_y_pc][ataque_x_pc]='x';
        textprintf(screen, font, 20, 500, palette_color[11], "La pc acerto el ataque");
        contapc++;
    }
    if(matrizA[ataque_y_pc][ataque_x_pc]=='.')
        {
            textprintf(screen, font, 20, 500, palette_color[11], "La pc fallo el ataque");
            matrizA[ataque_y_pc][ataque_x_pc]='o';
        }
        cont++;
        textprintf(screen, font, 300, 460, palette_color[11], "Intentos: %d", cont);
        textprintf(screen, font, 300, 490, palette_color[11], "Llevas %d ataques acertados", contajugador);
        textprintf(screen, font, 300, 520, palette_color[11], "La pc lleva %d ataques acertados", contapc);

        dibujar_matriz();
        pantalla();
        dibujar_matrizA();
        pantallapc();
        textprintf(screen, font, 20, 530, palette_color[15], "Presiona una tecla para continuar excepto ESC...");
        textprintf(screen, font, 410, 530, palette_color[30], "Presiona ESC para volver al menu principal...");
                readkey();
                if(key[KEY_ESC])
                {
                    contajugador=34;
                    contapc=34;
                }
                blit(cambiar, screen, 0, 0, 0, 450, 880, 100);

        while(contajugador==33 && contapc==33)
        {
            blit(Empatar, screen, 0, 0, 0, 0, 880, 540);
            readkey();
            contajugador=34;
            contapc=34;
        }
   while(contajugador==33)
   {
       if (mouse_x > 631 && mouse_x < 863 && mouse_y > 220 && mouse_y < 321)
            {
            blit(ganarcursor,buffer,0,0,0,0,880,540);
            if (mouse_b & 1){
                                contajugador=34;
                                contapc=34;
                            }
            }

        else
        {
            blit(Ganar,buffer,0,0,0,0,880,540);
        }
            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
            blit(buffer,screen,0,0,0,0,880,540);

    }
        while(contapc==33)
        {
            blit(Perder, screen, 0, 0, 0, 0, 880, 540);
            blit(perdercursor, screen, 0, 0, 440, 100, 440, 440);
            dibujar_matrizmostrar();
            pantallamostrar();
            readkey();
            contajugador=34;
            contapc=34;
            clear_keybuf();
        }
    }while(contajugador+contapc<66);

}

int main()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    // incializa el audio en allegro
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

    // ajustamos el volumen
	set_volume(230, 200);

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 880,540,0,0);

    buffer = create_bitmap(880,540);
    barco = load_bitmap("Barco (Ventana).bmp", NULL);
    agua = load_bitmap("Agua.bmp", NULL);
    hielo = load_bitmap("Hielo.bmp", NULL);
    destruir = load_bitmap("Redstone.bmp", NULL);
    uno = load_bitmap("1.bmp",NULL);
    dos = load_bitmap("2.bmp",NULL);
    tres = load_bitmap("3.bmp",NULL);
    cuatro = load_bitmap("4.bmp",NULL);
    cinco = load_bitmap("5.bmp",NULL);
    seis = load_bitmap("6.bmp",NULL);
    siete = load_bitmap("7.bmp",NULL);
    ocho = load_bitmap("8.bmp",NULL);
    nueve = load_bitmap("9.bmp",NULL);
    diez = load_bitmap("10.bmp",NULL);
    Perder = load_bitmap("perder.bmp", NULL);
    cambiar = load_bitmap("negro.bmp", NULL);
    Ganar = load_bitmap("ganado.bmp", NULL);
    Empatar = load_bitmap("empate.bmp", NULL);
    menu = load_bitmap("normal.bmp", NULL);
    jugar = load_bitmap("jugar.bmp", NULL);
    instrucciones = load_bitmap("instrucciones.bmp", NULL);
    Salir = load_bitmap("salir.bmp", NULL);
    cursor = load_bitmap("cursor.bmp",NULL);
    limpiar = load_bitmap("limpiar.bmp", NULL);
    ganarcursor = load_bitmap("ganadocursor.bmp", NULL);
    perdercursor = load_bitmap("perdermenu.bmp", NULL);
    ClicInstruccion = load_bitmap("clicins.bmp", NULL);

    musicafondo  = load_midi("Bomberman2-Powerup.mid");
    play_midi(musicafondo, 1);
    int tecla=0, clic=1, i, j;

   while(tecla==0)
   {
        clic=1;
      if (mouse_x > 320 && mouse_x < 573 && mouse_y > 449 && mouse_y < 522){
            blit(jugar,buffer,0,0,0,0,880,540);
            if (mouse_b & 1){
                    rest(200);

                    do{
                        for(i=1; i<11; i++)
                        {
                            for(j=1; j<11; j++)
                            {
                                matrizA[i][j]='.';
                                matriz[i][j]='.';
                                matrizApc[i][j]='.';
                                matrizpc[i][j]='.';
                                matrizpc[i][j]='.';
                            }
                        }
                        llenarbarcos();
                        llenarbarcospc();
                        dibujar_matriz();
                        pantalla();
                        dibujar_matrizA();
                        pantallapc();
                        atacar();
                        clic=0;
                    }while(clic==1);

                }
            }

        else if (mouse_x > 18 && mouse_x < 274 && mouse_y > 449 && mouse_y < 522){
            blit(instrucciones,buffer,0,0,0,0,880,540);
            if (mouse_b & 1){
                    do{
                        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
                        blit(buffer,screen,0,0,0,0,880,540);
                        blit(ClicInstruccion,buffer,0,0,0,0,880,540);
                        {
                            if(mouse_x > 0 && mouse_x < 50 && mouse_y > 0 && mouse_y < 50)
                            {
                                if(mouse_b & 1)
                                {
                                    clic=0;
                                }
                            }
                        }

                    }while(clic==1);
            }
        }
        else if (mouse_x > 613 && mouse_x < 867 && mouse_y > 449 && mouse_y < 522){
            blit(Salir,buffer,0,0,0,0,880,540);
            if (mouse_b & 1){
                tecla = 1;
            }
        }
        else
            blit(menu,buffer,0,0,0,0,880,540);
            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
            blit(buffer,screen,0,0,0,0,880,540);

    }
    destroy_midi(musicafondo);
}
END_OF_MAIN();
