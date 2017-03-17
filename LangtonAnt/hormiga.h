#ifndef HORMIGA_H
#define HORMIGA_H

class Hormiga
{
    public:
        Hormiga(int x, int y, char p, int *rgb);
        void giraDerecha();
        void giraIzquierda();
        void Avanza(int x, int y);
        int *invierteColor();
        int getX();
        int getY();
        int getR();
        int getG();
        int getB();
        int *getC();
        char getP();
        void setX(int x);
        void serY(int y);
        void serPosition(char p);
        void setRgb(int r, int g, int b);
        bool checaCelda(int x, int y);
        int densidad;
        void setCeldaActual(bool ca);
        bool getCeldaActual();
        void actualiza(char p, int rgb[3]);

        int getxInicial();
        int getyInicial();
        char getpInicial();
        void setxInicial(int xi);
        void setyInicial(int yi);
        void setpInicial(char pi);


    private:
        int x;
        int y;
        char posicion;
        int rgb[3];
        bool celdaActual;

        int xInicial;
        int yInicial;
        char pInicial;
};

#endif // HORMIGA_H
