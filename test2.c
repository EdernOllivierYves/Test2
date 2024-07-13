//include "/usr/include/linux/math.h"
#include <stdio.h> 
#include <math.h>
#include "test1.h"
//#include "glibc/math/math.h"
//#ifndef TEST1_H
//#define TEST1_H

struct vecteur {
    float x_v;
    float y_v;
    float phi_v;
};
/*
struct matrice {
    struct vecteur x_m;
    struct vecteur y_m;
    struct vecteur z_m;
};
struct vecteur multiplication_matrice_vecteur(struct matrice, struct vecteur) {
	multiplication_vecteur_vecteur();
	multiplication_vecteur_vecteur();
	multiplication_vecteur_vecteur();
};
*/
void main(void) {
// 09/12/2019 � 11:53 d'apr�s le sch�ma num�rique produit avec Maple 2019 entre le 04/12/2019 et le 09/12/2019
int V = 109;
int dt = 1;
int l = 5;
//float x = 0;
//float y = 0;
//float phi = 0;
FILE* fd = fopen("text.txt","wt");
//mfprintf(fd,'hello %s %d.\n','world',1);
//mfprintf(fd,'hello %s %d.\n','scilab',2);
//fprintf(fd, "ceci est un test.\n");
int i;

//int nombre = 0;
int res;
printf("Entrez une vitesse : ");
res = scanf("%i", &V);

int delta = 0;
//int res;
printf("Entrez un angle au volant : ");
res = scanf("%i", &delta);
for (i=0; i<1000; i++) {
    //char c;
    //c = getchar();
    //putchar(c);
    //printf("%c\n", c);
    //fprintf(fd, "ceci est un test..\n");
    //for k = 0:100
    // dphi/dt = tan(0.01*t)/l
    float phi = (float)((tan(delta)/l)*dt + phi);
    //  fprintf(fd, "La valeur de l'orientation du vehicule vaut : %f\n", phi);
    //disp(phi)
    // dx/dt = V*cos(phi)
    float x = (float)(V*cos(phi)*dt + x);
    //  fprintf(fd, "La valeur de la position en x du vehicule vaut : %f\n", x);
    //plot(i,x);
    //disp(x)
    // dy/dt = V*sin(phi)
    float y = (float)(V*sin(phi)*dt + y);
    //  fprintf(fd, "La valeur de la position en y du vehicule vaut : %f\n", y);
    //disp(y)
    //plot(x,y);//,'ro');
    //X = [x; y; phi];
    //U = [V; 0.01*i];

    //disp("Etat du v�hicule : ")
    //disp(X)
    //disp("Commande : ")
    //disp(U)
    /*
    k = 1;
    phi(i, k) = phi(i);
    */
    // Linear approximation done here
    //A = [1 ,0 ,-V*sin(phi)*dt; 0 ,1 ,V*cos(phi)*dt; 0 ,0 ,1];
    float x_app = (float)(x -V*sin(phi)*dt*phi);
    float y_app = (float)(y +V*cos(phi)*dt*phi);
    float phi_app = (float)(phi);
    //  fprintf(fd, "La valeur de l'approximation de la position en x du vehicule vaut : %f\n", x_app);
    //  fprintf(fd, "La valeur de l'approximation de la position en y du vehicule vaut : %f\n", y_app);
    //  fprintf(fd, "La valeur de l'approximation de la position en phi du vehicule vaut : %f\n", phi_app);
    //B = [cos(phi)*dt, 0; sin(phi)*dt, 0; tan(0.01*i)*dt/l, V*dt/(l*cos(0.01*i)^2)];
    float u_x = (float)(V*cos(phi)*dt);
    float u_y = (float)(delta*sin(phi)*dt);
    float u_phi = (float)(V*tan(delta)*dt/l +delta*V*dt/(l*cos(delta)*cos(delta)));
    //  fprintf(fd, "La valeur de l'approximation de la position en x du vehicule avec l'entree en x vaut : %f\n", x_app +u_x);
    //  fprintf(fd, "La valeur de l'approximation de la position en y du vehicule avec l'entree en y vaut : %f\n", y_app +u_y);
    //  fprintf(fd, "La valeur de l'approximation de la position en phi du vehicule avec l'entree en phi vaut : %f\n", phi_app +u_phi);
    //C = [1, 0, 0; 0, 1, 0; 0, 0, 1];
    //Xapp = A*X +B*U;
    //plot(Xapp(1,:),Xapp(2,:),'g+-');
    //disp("Etat approxim� du v�hicule : ")
    //disp(Xapp)

    //Y = C*X;
    //disp(Y)
    //end;

    //mfprintf(fd,'This line is built with a column vector (26:28) %d.\n',[26:28].');
    //mfprintf(fd,'This line is built with a row vector (26:28) %d.\n',[26:28]);
    //mfprintf(fd,'This line is built with a matrix %.3f.\n',Xapp);
    //mfprintf(fd,'This line is built with a matrix %.3f.\n',Y);
    //  fprintf(fd, "%f\t%f\t%f\t%f\t%f\t%f\t\n", phi, x, y, phi_app, x_app, y_app);
    fprintf(fd, "%f\t%f\t%f\t%f\t\n", x, y, x_app, y_app);
    }
    fclose(fd);
    //plot(x,y,'ro');
}
//eof
