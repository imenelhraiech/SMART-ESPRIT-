
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include <string.h>
#include <time.h>

#include <stdio.h>








void ajouter_capture(capteur A)
{
    FILE *F=NULL;

F=fopen("capture.txt","a");
if(F!=NULL)
{

    fprintf(F,"%.4s %s %s %s %s %d %s %s\n",A.id,A.valeurMax,A.valeur,A.typecapture,A. date,A.valeurMin,A.etage,A.bloc);
    fclose(F);
    

}

}
void supp_capture(char id[])
{
  
   FILE *F, *FW;
  capteur D ;
  
F = fopen ("capture.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %s %s %d %s %s",D.id,D.valeurMax,D.valeur,D.typecapture,D. date,&D.valeurMin,D.etage,D.bloc) == 8)
    if (strcmp (D.id, id) != 0)
      fprintf (FW, "%s %s %s %s %s %d %s %s\n", D.id,D.valeurMax,D.valeur,D.typecapture,D. date,D.valeurMin,D.etage,D.bloc);
}
  fclose (F);
  fclose (FW);
remove("capture.txt");
rename("tr.txt", "capture.txt");




}
capteur rech_capture(char id[])
{
char ch;
FILE *F;
  capteur Q;
  capteur A;
  
F = fopen ("capture.txt", "r");


  if (F!=NULL)
{
  while (fscanf (F, "%s %s %s %s %s %d %s %s", Q.id,Q.valeurMax,Q.valeur,Q.typecapture,Q. date, &Q.valeurMin,Q.etage,Q.bloc) != EOF)
    if (strcmp (Q.id, id) == 0)
        {
        strcpy(A.valeurMax,Q.valeurMax);
        strcpy(A.valeur,Q.valeur);
        strcpy(A.typecapture,Q.typecapture);
        strcpy(A.date,Q.date);
        strcpy(A.etage,Q.etage);
        strcpy(A.bloc,Q.bloc);
	
        }

  }
  return (A);
  fclose (F);  
}



void modi_capture(char id [] , capteur U) 
{
   FILE *F, *FW;
  capteur c; 
  
F = fopen ("capture.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL)) 
{
  while (fscanf (F, "%s %s  %s %s %s %d %s %s",c.id,c.valeurMax,c.valeur,c.typecapture,c. date,&c.valeurMin,c.etage,c.bloc) ==8)
	
    if (strcmp (c.id, id) == 0)
     {

fprintf (FW, "%s %s %s %s %s %d %s %s\n",id,U.valeurMax,U.valeur,U.typecapture,U. date,U.valeurMin,U.etage,U.bloc);

     }
     else
     {

       fprintf (FW, "%s %s %s %s %s %d %s %s\n", c.id,c.valeurMax,c.valeur,c.typecapture,c. date,c.valeurMin,c.etage,c.bloc);
     }
}    

  fclose (F);
  fclose (FW);
remove("capture.txt");
rename("tr.txt", "capture.txt");

}
void afficher_capture (GtkWidget *treeview1, char*l )

{
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;


	char id[30];
	char valeurMax[30];
	char valeurMin[30];
	char valeur[30];
	char typecapture[30];
	char date[30];
	char etage[30];
	char bloc[30];

        /* Creation du modele */
        adstore = gtk_list_store_new(8,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,valeurMax,valeur,typecapture,date,valeurMin,etage,bloc)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,valeurMax,
                            2,valeur,
                            3,typecapture,
                            4,date,
			    5,valeurMin,
                            6,etage,
			    7,bloc,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(k==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeurMax",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeurMin",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Capteur",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Valeur",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);

	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Etage",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);

	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Bloc",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);

	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	k++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}

