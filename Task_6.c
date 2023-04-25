#include <stdio.h>
int main() 
{
    struct fridge
    {
        int moloko;
        int measo;
        int sir;
        int v_znachit_vkusno;
    };
    
    struct fridge holodos = {8, 2, 3, 4};
    holodos.moloko --; 
    holodos.sir -=2; 
    holodos.measo --;
    holodos.v_znachit_vkusno -= 4; 

    holodos.sir += 2; 
    holodos.v_znachit_vkusno += 3;

    printf("kol_vo moloko (l): %d\n", holodos.moloko);
    printf("kol_vo measo (kg): %d\n", holodos.measo);
    printf("kol_vo sir (p): %d\n", holodos.sir);
    printf("kol_vo v_znachit_vkusno; (p): %d\n", holodos.v_znachit_vkusno);

    return 0;
}
