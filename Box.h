#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

struct Box {
    int x1 ; int y1 ; int x2 ; int y2 ;
    Box(){} ;
    Box(int a, int b, int c, int d) {
        x1 = a ; y1 = b ; x2 = c ; y2 = d ;
    }
};

bool InsideBox(int &x, int &y, Box &curBox) ;

#endif // BOX_H_INCLUDED
