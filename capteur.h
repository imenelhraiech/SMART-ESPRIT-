#include<gtk/gtk.h>
typedef struct 
{
char id[30];
char valeurMax[30];
char valeur[30];
char typecapture[30];
char date[30];
int valeurMin;
char etage[30];
char bloc [30];
}capteur ;

void ajouter_capture(capteur A);
void supp_capture(char id[]);
capteur rech_capture(char id[]);
void modi_capture(char id[], capteur U);
void afficher_capture (GtkWidget *treeview1 ,char *l);

