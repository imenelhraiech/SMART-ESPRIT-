#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h> 

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include <time.h>
#include "menu.h"
#include "capteur.h"
#include"tree.h"
#include"CRUD.h"
#include"etudiant.h"

#include "stock.h"

GtkTreeSelection *selection1;


Etudiant o;
char sexe1[10]="Homme";
char zz[10]="";
int conf1=0;




int x1;//
int t1[2]={0,0};
int x;//
int t[2]={0,0};



void
on_affi_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *message,*dateN;


int nb1=1000;


	char id[30];
	char type[30];
	int nb;
	char plat[30];
	char ing[30];
	int date;
	char groupetr[30];
	char modetr [30];
	
	int dateNBcode=0;

	char resultat [30];
dateN = lookup_widget (objet_graphique,"DateS");
dateNBcode =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dateN));


      
  FILE* F;

F=fopen("menu.txt","r");
if(F!=NULL)
{

    
    while(fscanf(F,"%s %s %s %s %d %d %s %s\n",id,type,ing,plat,&date,&nb,groupetr,modetr)!=EOF)
    {
        if(date==dateNBcode){
        if(nb1>nb){
	nb1=nb;
  	strcpy(resultat,id);
            }                                 

}
}

fclose(F);
message = lookup_widget(objet_graphique, "label11");
gtk_label_set_text(GTK_LABEL(message),resultat);



}

}







void
on_actu_mo_clicked                     (GtkWidget       *objet,             
                                        gpointer         user_data)
{

        GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeviewMolka");
	gchar *type;
        gchar *plat;
        gchar *etat;
        gchar *date;
  	gchar *nb;
        gchar *id;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,1,&type,2,&plat,3,&etat,4,&date,5,&nb,-1);
  
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entryid_nb")),id);

GtkWidget *dd,*type,*plat,*ing,*date,*ty,*se,*da,*po;

	dd = lookup_widget (objet,"entryid_nb");
	type = lookup_widget(objet,"labelchef_nb");
	plat = lookup_widget(objet,"labeling_nb");
	ing = lookup_widget(objet, "labelplat_nb");
	date = lookup_widget(objet, "labeldate_nb");

	ty = lookup_widget (objet,"entrychef_nb");
	se = lookup_widget (objet,"entrying_nb");
	da = lookup_widget (objet,"comboboxplat_nb");
	po = lookup_widget (objet,"entrydate_nb");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
	nutri A= rech_nb(id);

	gtk_label_set_text(GTK_LABEL(type),A.type); 
	gtk_label_set_text(GTK_LABEL(plat),A.plat);
	gtk_label_set_text(GTK_LABEL(ing),A.ing);
	gtk_label_set_text(GTK_LABEL(date),A.date);

	gtk_entry_set_text(GTK_LABEL(ty),A.type);  
	gtk_entry_set_text(GTK_LABEL(se),A.plat);
	gtk_label_set_text(GTK_LABEL(da),A.ing);
	gtk_entry_set_text(GTK_LABEL(po),A.date);
			
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebookMolka")));//redirection vers la page precedente
}


afficher_nb(p ,"menu.txt");

}





////////////////////////  RECHERCHE   ////////////////////////////
void
on_rech_mo_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{




GtkWidget *dd,*type,*plat,*ing,*date,*ty,*se,*da,*po,*lb;
char idd[20];

int k=-1;
char type1[20];
char plat1[20];
char date1[20];
char nb1[20];
char id[20];
char ing1[20];
char groupetr[30];
char modetr [30];



FILE *F;
dd = lookup_widget (button,"entryid_nb");
type = lookup_widget(button, "labelchef_nb");
plat = lookup_widget(button, "labeling_nb");
ing = lookup_widget(button, "labelplat_nb");
date = lookup_widget(button, "labeldate_nb");
lb= lookup_widget(button, "labelid");

ty = lookup_widget (button,"entrychef_nb");
se = lookup_widget (button,"entrying_nb");
da = lookup_widget (button,"comboboxplat_nb");
po = lookup_widget (button,"entrydate_nb");




strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("menu.txt", "r");


if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s \n",id,type1,plat1,ing1,date1,nb1,groupetr,modetr) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      k=1;
      } 
     } 
    
     fclose (F);
  }

if(k==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");

}else
{
    nutri A= rech_nb(idd);
    gtk_label_set_text(GTK_LABEL(lb),"Id Exist ");
gtk_label_set_text(GTK_LABEL(type),A.type);
gtk_label_set_text(GTK_LABEL(plat),A.plat);
gtk_label_set_text(GTK_LABEL(ing),A.ing);
gtk_label_set_text(GTK_LABEL(date),A.date);


gtk_entry_set_text(GTK_LABEL(ty),A.type);
gtk_entry_set_text(GTK_LABEL(se),A.plat);
gtk_label_set_text(GTK_LABEL(da),A.ing);
gtk_entry_set_text(GTK_LABEL(po),A.date);
}



}




///////////////// MODIFIER //////////////////////////////////
void
on_Modif_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*ty,*se,*da,*po,*nb,*lb;
int v=-1;
char id[20];
char idd[20];
char type1[20];
char plat1[20];
char ing1[20];
char date1[20];
char groupe1[20];
char mode1[20];
char nb1[20];
nutri U ;

dd = lookup_widget (objet_graphique,"entryid_nb");
ty = lookup_widget (objet_graphique,"entrychef_nb");
se = lookup_widget (objet_graphique,"entrying_nb");
da = lookup_widget (objet_graphique,"comboboxplat_nb");
po = lookup_widget (objet_graphique,"entrydate_nb");
nb = lookup_widget (objet_graphique,"spinbuttondechet_nb");
lb = lookup_widget (objet_graphique,"labelid");


if (x1==1) 
strcpy(U.modetr,"Mode_jour");
 if (x1==2) 
strcpy(U.modetr,"Mode_nuit");
 if (x1==0) 
strcpy(U.modetr,"NULL");

 if (t1[0]==1)
 strcat(U.groupetr,"GroupeB"); 
if(t1[1]==1)
 strcat (U.groupetr,"GroupeA");
if((t1[1]==0)&&(t1[0]==0))
 strcpy (U.groupetr,"NULL");




FILE *F;

F = fopen ("menu.txt", "r");


if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s  \n",id,type1,plat1,ing1,date1,nb1,groupe1,mode1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      v=1;
      } 
     } 
    
     fclose (F);
  }

    
    gtk_label_set_text(GTK_LABEL(lb),"Modification valiée");

U.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
strcpy(U.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(U.plat,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(U.ing,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(U.date,gtk_entry_get_text(GTK_ENTRY(po)));


modi_nb(id,U);






 GtkWidget* p=lookup_widget(objet_graphique,"treeviewMolka");
afficher_nb(p ,"menu.txt");
}





///////////////// AJOUTER ///////////////////////
void
on_ajout_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*da,*po,*nb,*Ajouter,*labeldate,*labelmain,*labelty;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
nutri A ;
char id[30];
int i, longueurChaine = 0;
char chaine[] = "jijnkbjyvgtc1a2z3e4r5t6y7u8i9opqsdfghjklmwxcvbn";
int b=1;

ty = lookup_widget (objet_graphique,"chef_nb");
se = lookup_widget (objet_graphique,"ing_nb");
da = lookup_widget (objet_graphique,"plat_nb");
po = lookup_widget (objet_graphique,"date_nb");
nb = lookup_widget (objet_graphique,"dechet_nb");


A.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));


strcpy(A.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.plat,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.ing,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(A.date,gtk_entry_get_text(GTK_ENTRY(po)));

labelty=lookup_widget(objet_graphique,"labelchef");
labelmain=lookup_widget(objet_graphique,"labeling");
labeldate=lookup_widget(objet_graphique,"labeldate");

if (x==1) 
strcpy(A.modetr,"Mode_jour");
 if (x==2) 
strcpy(A.modetr,"Mode_nuit");
 if (x==0) 
strcpy(A.modetr,"NULL");

 if (t[0]==1)
 strcat(A.groupetr,"GroupeB"); 
if(t[1]==1)
 strcat (A.groupetr,"GroupeA");
if((t[1]==0)&&(t[0]==0))
 strcpy (A.groupetr,"NULL");


    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }

 strcpy(A.id,id);

// controle saisie
if(strcmp(A.type,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelty),"saisir Chef !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelty),"");
}

if(strcmp(A.plat,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"saisir Ingrédient !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"");
}


if(strcmp(A.date,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir date !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"");
}


if(b==1){

ajouter_nb(A);
}

 GtkWidget* p=lookup_widget(objet_graphique,"treeviewMolka");
afficher_nb(p ,"menu.txt");
}




////////////////// SUPPRIMER /////////////////////////
void
on_supp_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char type[20];
char plat[20];
char date[20];
char ing[20];
char id[20];
char nb [20];
char group[50];
char mode[50];

lb = lookup_widget (objet_graphique,"labelid"); 
dd = lookup_widget (objet_graphique,"entryid_nb");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("menu.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s \n",id,type,plat,ing,date,nb,group,mode) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_nb(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");
}



 GtkWidget* p=lookup_widget(objet_graphique,"treeviewMolka");
afficher_nb(p ,"menu.txt");
}




void
on_supp_tree_mo_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeviewMolka");;

        gchar *id;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
            supp_nb( id);
}
}





void
on_checkbutton2MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))

   {t[1]=1;}    
}


void
on_checkbutton1MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;}   
}






void
on_radiobutton1MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 
}


void
on_radiobutton2MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 
}








void
on_FacebookMO_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/");
}


void
on_youtubeMO_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.youtube.com/");
}


void
on_InstagramMO_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}


void
on_checkbutton4MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {t1[0]=1;} 
else 
   {t1[0]=0;} 
}


void
on_checkbutton3MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {t1[1]=1;} 
else 
   {t1[1]=0;} 
}


void
on_radiobutton4MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x1=2;} 
else 
{x1=0;} 

}

void
on_radiobutton3MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x1=1;} 
else 
{x1=0;}  

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////nourchene//////////////////////////////////////////////////////////////////
int y1;
int tab1[2]={0,0};
int y;
int tab[2]={0,0};


void
on_affi_nb_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
                                       
{


	char id[30];
	int valeurMax;
	int valeurMin;
	int valeur;
	char typecapture[30];
	char date[30];
	char etage[30];
	char bloc [30];

  capteur c;
  
   FILE *F, *FW;
  
  
F = fopen ("capture.txt", "r");
FW = fopen ("cp.txt", "w");


  if ((F!=NULL)&&(FW!=NULL))
 {


    while(fscanf(F,"%s %d %d %s %s %d %s %s\n",id,&valeurMax,&valeurMin,typecapture,date,&valeur,etage,bloc)!=EOF)
    if ((valeur<valeurMin) || (valeur>valeurMax))
     {
	fprintf (FW, "%s %d %d %s %s %d %s %s \n",id,valeurMax,valeurMin,typecapture,date,valeur,etage,bloc);

     }

     

     
     

  fclose (F);
  fclose (FW);

 GtkWidget* p=lookup_widget(objet,"treeview1");
afficher_capture(p,"cp.txt");
}
}






void
on_actu_nb_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview1");
	gchar *valeurMax;
        gchar *valeur;
        gchar *etat;
        gchar *date;
  	gchar *valeurMin;
        gchar *id;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,1,&valeurMax,2,&valeur,3,&etat,4,&date,5,&valeurMin,-1);
  
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry1NourChen")),id);

GtkWidget *dd,*valeurMax,*valeur,*typecapture,*date,*ty,*se,*da,*po;

	dd = lookup_widget (objet,"entry1NourChen");
	valeurMax = lookup_widget(objet,"label23NourChen");
	valeur = lookup_widget(objet,"label24NourChen");
	typecapture = lookup_widget(objet, "label25NourChen");
	date = lookup_widget(objet, "label26NourChen");

	ty = lookup_widget (objet,"entry2NourChen");
	se = lookup_widget (objet,"entry3NourChen");
	da = lookup_widget (objet,"combobox2NourChen");
	po = lookup_widget (objet,"entry5NourChen");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
	capteur A= rech_capture(id);

	gtk_label_set_text(GTK_LABEL(valeurMax),A.valeurMax);
	gtk_label_set_text(GTK_LABEL(valeur),A.valeur);
	gtk_label_set_text(GTK_LABEL(typecapture),A.typecapture);
	gtk_label_set_text(GTK_LABEL(date),A.date);

	gtk_entry_set_text(GTK_LABEL(ty),A.valeurMax);
	gtk_entry_set_text(GTK_LABEL(se),A.valeur);
	gtk_label_set_text(GTK_LABEL(da),A.typecapture);
	gtk_entry_set_text(GTK_LABEL(po),A.date);
			
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1")));
}


afficher_capture(p ,"capture.txt");

}

void
on_rech_nb_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{



GtkWidget *dd,*valeurMax,*valeur,*typecapture,*date,*ty,*se,*da,*po,*lb;
char idd[20];

int x=-1;
char valeurMax1[20];
char valeur1[20];
char date1[20];
char valeurMin1[20];
char id[20];
char typecapture1[20];
	char etage1[30];
	char bloc1 [30];

FILE *F;
dd = lookup_widget (button,"entry1NourChen");
valeurMax = lookup_widget(button, "label23NourChen");
valeur = lookup_widget(button, "label24NourChen");
typecapture = lookup_widget(button, "label25NourChen");
date = lookup_widget(button, "label26NourChen");
lb= lookup_widget(button, "label19NourChen");

ty = lookup_widget (button,"entry2NourChen");
se = lookup_widget (button,"entry3NourChen");
da = lookup_widget (button,"combobox2NourChen");
po = lookup_widget (button,"entry5NourChen");




strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("capture.txt", "r");

if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s \n",id,valeurMax1,valeur1,typecapture1,date1,valeurMin1,etage1,bloc1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
   gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_label_set_text(GTK_LABEL(dd),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    capteur A= rech_capture(idd);
    gtk_label_set_text(GTK_LABEL(lb),"ID Trouvé");
gtk_label_set_text(GTK_LABEL(valeurMax),A.valeurMax);
gtk_label_set_text(GTK_LABEL(valeur),A.valeur);
gtk_label_set_text(GTK_LABEL(typecapture),A.typecapture);
gtk_label_set_text(GTK_LABEL(date),A.date);


gtk_entry_set_text(GTK_LABEL(ty),A.valeurMax);
gtk_entry_set_text(GTK_LABEL(se),A.valeur);
gtk_label_set_text(GTK_LABEL(da),A.typecapture);
gtk_entry_set_text(GTK_LABEL(po),A.date);
}



}


void
on_Modif_nb_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*ty,*se,*da,*po,*nb,*lb;
int v=-1;
char id[20];
char idd[20];
char valeurMax1[20];
char valeur1[20];
char typecapture1[20];
char date1[20];
char valeurMin1[20];
	char etage1[30];
	char bloc1 [30];


capteur U ;

dd = lookup_widget (objet_graphique,"entry1NourChen");
ty = lookup_widget (objet_graphique,"entry2NourChen");
se = lookup_widget (objet_graphique,"entry3NourChen");
da = lookup_widget (objet_graphique,"combobox2NourChen");
po = lookup_widget (objet_graphique,"entry5NourChen");
nb = lookup_widget (objet_graphique,"spinbutton35NourChen");
lb = lookup_widget (objet_graphique,"label19NourChen");


 strcpy (U.etage,"");

if (y1==1) 
strcpy(U.bloc,"BlocA");
 if (y1==2) 
strcpy(U.bloc,"BlocB");
 if (y1==0) 
strcpy(U.bloc,"NULL");

 if (tab1[0]==1)
 strcat(U.etage,"etage1"); 
if(tab1[1]==1)
 strcat (U.etage,"etage2");
if((tab1[1]==0)&&(tab1[0]==0))
 strcpy (U.etage,"NULL");


FILE *F;
F = fopen ("capture.txt", "r");

if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s \n",id,valeurMax1,valeur1,typecapture1,date1,valeurMin1,etage1,bloc1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      v=1;
      } 
     } 
    
     fclose (F);
  }

    
    gtk_label_set_text(GTK_LABEL(lb),"Modification effectué");

U.valeurMin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
strcpy(U.valeurMax,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(U.valeur,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(U.typecapture,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(U.date,gtk_entry_get_text(GTK_ENTRY(po)));

modi_capture(id,U);

 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_capture(p ,"capture.txt");
}


void
on_ajout_nb_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*da,*po,*nb,*Ajouter,*labeldate,*labelmain,*labelty;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
capteur A ;
char id[30];
int i, longueurChaine = 0;
char chaine[] = "1a2z3e4r5t6y7u8i9uhherhehervkherherrekuhreveheiehhrhzfzejhkhkhkuhukgopqsdfghjklmwxcvbn";
int b=1;

ty = lookup_widget (objet_graphique,"entry6NourChen");
se = lookup_widget (objet_graphique,"entry7NourChen");
da = lookup_widget (objet_graphique,"combobox3NourChen");
po = lookup_widget (objet_graphique,"entry9NourChen");
nb = lookup_widget (objet_graphique,"spinbutton33NourChen");


A.valeurMin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));


strcpy(A.valeurMax,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.valeur,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.typecapture,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(A.date,gtk_entry_get_text(GTK_ENTRY(po)));

labelty=lookup_widget(objet_graphique,"label263NourChen");
labelmain=lookup_widget(objet_graphique,"label264NourChen");
labeldate=lookup_widget(objet_graphique,"label265NourChen");


 strcpy (A.etage,"");

if (y==1) 
strcpy(A.bloc,"BlocA");
 if (y==2) 
strcpy(A.bloc,"BlocB");
 if (y==0) 
strcpy(A.bloc,"NULL");

 if (tab[0]==1)
 strcat(A.etage,"etage1"); 
if(tab[1]==1)
 strcat (A.etage,"etage2");
if((tab[1]==0)&&(tab[0]==0))
 strcpy (A.etage,"NULL");


    longueurChaine = strlen(chaine);
    srand(time(NULL));
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }

 strcpy(A.id,id);

if(strcmp(A.valeurMax,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelty),"saisir valeurMax !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelty),"");
}

if(strcmp(A.valeur,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"saisir Valeur Min !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"");
}


if(strcmp(A.date,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir date !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"");
}


if(b==1){

ajouter_capture(A);
}
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_capture(p ,"capture.txt");
}

void
on_supp_nb_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char valeurMax[20];
char valeur[20];
char date[20];
char typecapture[20];
char id[20];
char valeurMin [20];
	char etage[30];
	char bloc [30];

lb = lookup_widget (objet_graphique,"label19NourChen");
dd = lookup_widget (objet_graphique,"entry1NourChen");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));	

F = fopen ("capture.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,valeurMax,valeur,typecapture,date,valeurMin,etage,bloc) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_capture(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");
}



 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_capture(p ,"capture.txt");
}




void
on_supp_tree_nb_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview1");;

        gchar *id;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

            supp_capture( id);
}
}





void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {tab[1]=1;}  
else 
   {tab[1]=0;}  
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) 
  {tab[0]=1;} 
else 
   {tab[0]=0;}  
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {y=1;} 
else 
{y=0;} 
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{y=2;} 
else 
{y=0;} 
}








void
on_Facebook_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.google.com/");
}


void
on_youtube_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.youtube.com/");
}


void
on_Instagram_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.electronicaembajadores.com/fr/Subfamilias/Index/SS/capteurs");
}



void
on_radiobutton5etage2_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{y1=2;} 
else 
{y1=0;} 


}


void
on_radiobutton4etage1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {y1=1;} 
else 
{y1=0;}


}


void
on_checkbutton3BlocA_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) 
   {tab1[0]=1;} 
else 
   {tab1[0]=0;}  

}


void
on_checkbutton4BlocB_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
   {tab1[1]=1;} 
else 
   {tab1[1]=0;}

}
/////////////////////////////imen/////////////////////



void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *p;
gtk_widget_hide (acceuilw);
gestionw = create_gestionw ();
p=lookup_widget(gestionw,"treeview2w");
Afficherreclamation(p,"reclamation.txt");
gtk_widget_show (gestionw);
}


void
on_Ajouterreclamation_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 reclamation t;
GtkWidget *entryservicew;
GtkWidget *entryIdw;
GtkWidget *entrynumerochambrew;

GtkWidget *entrynometprenomw;
GtkWidget *labelIdw;
GtkWidget *labelservicew;
GtkWidget *labelnumerochambrew;
GtkWidget *labelDatew;
GtkWidget *labelnometprenomw;
GtkWidget *existew;
GtkWidget* successw;
GtkWidget *calw;
GtkWidget *entryreclamation;
GtkWidget *labelreclamation;
int b=1;
int jj1,mm1,aa1;

FILE*f=NULL;


entryIdw=lookup_widget(gestionw,"entry5w");
entryservicew=lookup_widget(gestionw,"combobox1w");
entrynumerochambrew=lookup_widget(gestionw,"combobox2w");
entryreclamation=lookup_widget(gestionw,"entryreclamation");


entrynometprenomw=lookup_widget(gestionw,"entry3w");

labelIdw=lookup_widget(gestionw,"label13w");
labelservicew=lookup_widget(gestionw,"label7w");
labelnumerochambrew=lookup_widget(gestionw,"label8w");


labelreclamation=lookup_widget(gestionw,"labellabel");


labelnometprenomw=lookup_widget(gestionw,"label10w");
existew=lookup_widget(gestionw,"label34w");
successw=lookup_widget(gestionw,"label35w");
calw=lookup_widget(gestionw,"yawmia");
        strcpy(t.cin,gtk_entry_get_text(GTK_ENTRY(entryIdw) ) );
        strcpy(t.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryservicew)));
        strcpy(t.numerochambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrynumerochambrew)));

        strcpy(t.nometprenom,gtk_entry_get_text(GTK_ENTRY(entrynometprenomw) ) );
        strcpy(t.reclamation,gtk_entry_get_text(GTK_ENTRY(entryreclamation) ) );
 gtk_widget_hide (successw);

 gtk_calendar_get_date (GTK_CALENDAR(calw),
                       &aa1,
                       &mm1,
                       &jj1);
 gtk_widget_hide (successw);


// controle saisie
if(strcmp(t.cin,"")==0){
		  gtk_widget_show (labelIdw);
b=0;
}
else {
		  gtk_widget_hide(labelIdw);
}

if(strcmp(t.service,"")==0){
		  gtk_widget_show (labelservicew);
b=0;
}
else {
		  gtk_widget_hide(labelservicew);
}
if(strcmp(t.numerochambre,"")==0){
		  gtk_widget_show (labelnumerochambrew);
b=0;
}
else {
		  gtk_widget_hide(labelnumerochambrew);
}

if(strcmp(t.nometprenom,"")==0){
		  gtk_widget_show (labelnometprenomw);
b=0;
}
else {
		  gtk_widget_hide(labelnometprenomw);
}

if(strcmp(t.reclamation,"")==0){
		  gtk_widget_show (labelreclamation);
b=0;
}
else {
		  gtk_widget_hide(labelreclamation);
}


if(b==1){

        if(exist_reclamation(t.cin)==1)
        {

				  gtk_widget_show (existew);
                }
                else {
                     gtk_widget_hide (existew);

       f=fopen("reclamation.txt","a+");

fprintf(f,"%s %s %s  %d/%d/%d %s %s\n",t.cin,t.service,t.numerochambre, jj1,mm1+1,aa1 ,t.nometprenom,t.reclamation);
fclose(f);
     

                  gtk_widget_show (successw);



      GtkWidget* p=lookup_widget(gestionw,"treeview2w");

        Afficherreclamation(p,"reclamation.txt");
}

}
}



void
on_Modifierreclamation_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *combobox3w;
        GtkWidget *combobox4w;
     combobox3w=lookup_widget(button,"combobox3w");
     combobox4w=lookup_widget(button,"combobox4w");
       	 reclamation t;

        strcpy(t.cin,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionw,"label20w"))));
        strcpy(t.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox3w"))));
        strcpy(t.numerochambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox4w"))));
        strcpy(t.nometprenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w"))));
        strcpy(t.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w"))));
	strcpy(t.reclamation,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entryrec"))));
        supprimer_reclamation(t.cin);
        ajouter_reclamation(t);

        Afficherreclamation(lookup_widget(gestionw,"treeview1"),"reclamation.txt");
	gtk_widget_show(lookup_widget(gestionw,"label37w"));
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherreclamation(p,"reclamation.txt");
}





void
on_chercherreclamation_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1w;
GtkWidget *entryw;
GtkWidget *labelidw;
GtkWidget *nbResultatw;
GtkWidget *messagew;
char cin[30];
char chnb[30];
int b=0,nb; 
entryw=lookup_widget(gestionw,"entry10w");
labelidw=lookup_widget(gestionw,"label28w");
p1w=lookup_widget(gestionw,"treeview2w");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entryw)));

if(strcmp(cin,"")==0){
  gtk_widget_show (labelidw);b=0;
}else{
b=1;
gtk_widget_hide (labelidw);}

if(b==0)
    {return;
    }
    else
    {

nb=Chercherreclamation(p1w,"reclamation.txt",cin);

 

sprintf(chnb,"%d",nb);        //conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultatw=lookup_widget(gestionw,"label27");
messagew=lookup_widget(gestionw,"label26w");
gtk_label_set_text(GTK_LABEL(nbResultatw),chnb);

gtk_widget_show (nbResultatw);
gtk_widget_show (messagew);
}
}


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuilw);
gtk_widget_destroy (gestionw);

}




void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data)
{
        gchar *cin;
        gchar *service;
        gchar *numerochambre;
        gchar *date;
        gchar *nometprenom;
	gchar *reclamation;
  
        GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

        gtk_widget_hide(lookup_widget(gestionw,"label37w"));
                gtk_tree_model_get (model,&iter,0,&cin,1,&service,2,&numerochambre,3,&date,4,&nometprenom,5,&reclamation,-1);
               
   
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w")),nometprenom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entryrec")),reclamation);
                GtkWidget* msgId=lookup_widget(gestionw,"label20w");
                GtkWidget* msg1=lookup_widget(gestionw,"label36w");
                gtk_label_set_text(GTK_LABEL(msgId),cin);
                gtk_widget_show(msgId);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestionw,"button4w"));
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionw,"notebook1w")));
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                
             
        }

}


void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data)
{
    gchar *cin;
    gchar *service;
    gchar *numerochambre;
    gchar *date;
    gchar *nometprenom;
    gchar *reclamation;
    GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&cin,1,&service,2,&numerochambre,3,&date,4,&nometprenom,5,&reclamation,-1);//recuperer les information de la ligne selectionneé
            supprimer_reclamation(cin);
            Afficherreclamation(lookup_widget(gestionw,"treeview2w"),"reclamation.txt");        
        }
}


void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherreclamation(p,"reclamation.txt");
}


void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
    	gchar *cin;
        gchar *service;
        gchar *numerochambre;
        gchar *date;
        gchar *nometprenom;
	gchar *reclamation;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       
}










void
on_button_service_partie_2_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *b;
int nbr=0,nbh=0 ;
FILE*f=NULL;
reclamation t;
char max[30];



f=fopen("reclamation.txt","r");
while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF)
	{
		if(strcmp(t.service,"restauration")==0)
		nbr++;
		else
		nbh++;
	}
fclose(f);

if (nbr>nbh)
strcpy(max,"restauration");
else
strcpy(max,"hebergement");



b=lookup_widget (button,"label_service_tache_2");
gtk_label_set_text(GTK_LABEL(b),max);



}


void
on_boutontache2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

gtk_widget_hide (acceuilw);
dialog_service_partie_2 = create_dialog_service_partie_2 ();
gtk_widget_show (dialog_service_partie_2);
}


void
on_checkbutton_service_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *i1,*i2;
i1=lookup_widget(togglebutton,"radiobutton_heb");
i2=lookup_widget(togglebutton,"radiobutton_rest");

if(gtk_toggle_button_get_active(togglebutton))
{
gtk_widget_show(i1);
gtk_widget_show(i2);
}
else
{

GtkWidget *p;
p=lookup_widget(gestionw,"treeview2w");
Afficherreclamation(p,"reclamation.txt");
gtk_widget_hide(i1);
gtk_widget_hide(i2);

}
}















//=================================================================

//===================================================================
void
on_radiobutton_heb_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *p=lookup_widget(gestionw,"treeview2w");
Afficherheb(p,"reclamation.txt");
}






//=====================================================================


void
on_radiobutton_rest_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *p=lookup_widget(gestionw,"treeview2w");
Afficherrest(p,"reclamation.txt");
}
////////////hamza/////////////////






void
on_go_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);
GtkWidget *ajouter_et;
ajouter_et = create_ajouter_et ();
  gtk_widget_show (ajouter_et);
}


void
on_go_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");

GtkWidget *supprimer_et;
supprimer_et = create_supprimer_et ();
  gtk_widget_show (supprimer_et);
}


void
on_go_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);

    char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
    char niveaux[40];
    char id[10];
    char username[40];
    char password[40];
    char num_etage[40];
    char num_ch[40];
    char type_ch[40];
FILE *f;

f=fopen("etudiant.txt","r");
GtkWidget *Modifier_et;
Modifier_et = create_Modifier_et ();
gtk_widget_show (Modifier_et);

GtkWidget *nom_et1;
nom_et1 = lookup_widget (Modifier_et ,"nom_et1");
GtkWidget *prenom_et1;
prenom_et1 = lookup_widget (Modifier_et ,"prenom_et1");
GtkWidget *cin_et1;
cin_et1 = lookup_widget (Modifier_et ,"cin_et1");
GtkWidget *tel_et1;
tel_et1 = lookup_widget (Modifier_et ,"tel_et1");
GtkWidget *username_et1;
username_et1 = lookup_widget (Modifier_et ,"username_et1");
GtkWidget *password_et1;
password_et1 = lookup_widget (Modifier_et ,"password_et1");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux)!=EOF){
 if (strcmp(o.id,id)==0){
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"nom_et1")),nom);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"prenom_et1")),prenom);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"cin_et1")),cin);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"tel_et1")),gsm);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"username_et1")),username);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"password_et1")),password);

}}
}


void
on_actualiser_user_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_et;
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
treeview1_et=lookup_widget(afficher_et,"treeview1_et");
afficher_ett(treeview1_et);
}


/*void
on_deconn_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);
GtkWidget *window1;
window1 = create_auth_et ();
gtk_widget_show (window1);
}
*/

void
on_treeview1_et_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* sexe;
	gchar* dns;
	gchar* gsm;
	gchar* niv;
	gchar* username;
	gchar* password;
	gchar* etage;
	gchar* chambre;
	gchar* type;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id, 1, &nom,2,&prenom,3,&cin,4,&sexe,5,&dns,6,&gsm,7,&niv,8,&username,9,&password,10,&etage,11,&chambre,12,&type,-1);
	strcpy(o.id,id);strcpy(zz,id);
	
	}
}

void
on_chercher_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_user;
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");

treeview1_user=lookup_widget(afficher_et,"treeview1_et");
cherch = lookup_widget (button ,"entry1_chercher");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_ett(treeview1_user,ch);
}

void
on_ajouter_et_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";

int x=0;
Etudiant p;
GtkWidget *calendar1_et;
GtkWidget *id_et,*nom_et,*prenom_et,*cin_et,*tel_et,*comboboxentry1_et,*comboboxentry2_et;
GtkWidget *spinbutton1_et;
GtkWidget *username_et,*password_et,*cin_user,*num_etage,*num_ch;

calendar1_et=lookup_widget(button,"calendar1_et");

nom_et=lookup_widget(button,"entre_nomet");
prenom_et=lookup_widget(button,"entre_prenom_et");
cin_et=lookup_widget(button,"entre_cinet");
tel_et=lookup_widget(button,"entre_telet");
password_et=lookup_widget(button,"entre_passwordet");
username_et=lookup_widget(button,"entre_usernameet");


comboboxentry1_et=lookup_widget(button,"comboboxentry1_et");
comboboxentry2_et=lookup_widget(button,"comboboxentry2_et");
id_et=lookup_widget(button,"entre_id");
num_etage=lookup_widget(button,"spinbutton2_et");
num_ch=lookup_widget(button,"spinbutton3_et");




GtkWidget *e_id;
e_id = lookup_widget (button ,"e_id");
GtkWidget *e_nom;
e_nom = lookup_widget (button ,"e_nom");
GtkWidget *e_prenom;
e_prenom = lookup_widget (button ,"e_prenom");
GtkWidget *e_cin;
e_cin = lookup_widget (button ,"e_cin");
GtkWidget *e_num;
e_num = lookup_widget (button ,"e_num");
GtkWidget *e_username;
e_username = lookup_widget (button ,"e_username");
GtkWidget *e_password;
e_password = lookup_widget (button ,"e_password");
GtkWidget *e_niveaux;
e_niveaux = lookup_widget (button ,"e_niveaux");
GtkWidget *e_typeet;
e_typeet = lookup_widget (button ,"e_typeet");
GtkWidget *e_confet;
e_confet = lookup_widget (button ,"e_confet");


int bbb=0;
gtk_calendar_get_date (GTK_CALENDAR(calendar1_et),
                       &aa,
                       &mm,
                       &jj);

mm=mm+1;

sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);


p.num_etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_etage));
p.num_ch=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_ch));

strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id_et)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_et)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_et)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin_et)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(tel_et)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(username_et)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(password_et)));



strcpy(p.date_naissance,y);
strcpy(p.niveaux,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1_et)));
strcpy(p.type_ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2_et)));

strcpy(p.sexe,sexe1);

if (strcmp(p.id,"")==0)
{x=1;
gtk_widget_show(e_id);
}
else {x=0;
gtk_widget_hide(e_id);
}
if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(e_nom);
}
else {x=0;
gtk_widget_hide(e_nom);
}
if (strcmp(p.prenom,"")==0)
{x=1;
gtk_widget_show(e_prenom);
}
else {x=0;
gtk_widget_hide(e_prenom);
}
if (strcmp(p.cin,"")==0)
{x=1;
gtk_widget_show(e_cin);
}
else {x=0;
gtk_widget_hide(e_cin);
}
if (strcmp(p.gsm,"")==0)
{x=1;
gtk_widget_show(e_num);
}
else {x=0;
gtk_widget_hide(e_num);
}
if (strcmp(p.username,"")==0)
{x=1;
gtk_widget_show(e_username);
}
else {x=0;
gtk_widget_hide(e_username);
}
if (strcmp(p.password,"")==0)
{x=1;
gtk_widget_show(e_password);
}
else {x=0;
gtk_widget_hide(e_password);
}
if (strcmp(p.niveaux,"")==0)
{x=1;
gtk_widget_show(e_niveaux);
}
else {x=0;
gtk_widget_hide(e_niveaux);
}
if (strcmp(p.type_ch,"")==0)
{x=1;
gtk_widget_show(e_typeet);
}
else {x=0;
gtk_widget_hide(e_typeet);
}
if (conf1==0)
{x=1;
gtk_widget_show(e_confet);
}
else {
gtk_widget_hide(e_confet);
}


if(x==0){
ajouter_et(p);
GtkWidget *ajouter_et;
ajouter_et=lookup_widget(button,"ajouter_et");
gtk_widget_destroy(ajouter_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}}




void
on_modifier_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{


Etudiant p;


GtkWidget *nom_et1;
nom_et1 = lookup_widget (button ,"nom_et1");
GtkWidget *prenom_et1;
prenom_et1 = lookup_widget (button ,"prenom_et1");
GtkWidget *cin_et1;
cin_et1 = lookup_widget (button ,"cin_et1");
GtkWidget *tel_et1;
tel_et1 = lookup_widget (button ,"tel_et1");
GtkWidget *username_et1;
username_et1 = lookup_widget (button ,"username_et1");
GtkWidget *password_et1;
password_et1 = lookup_widget (button ,"password_et1");





GtkWidget *e_nom;
e_nom = lookup_widget (button ,"e_nom1");
GtkWidget *e_prenom;
e_prenom = lookup_widget (button ,"e_prenom1");
GtkWidget *e_cin;
e_cin = lookup_widget (button ,"e_cin1");
GtkWidget *e_num;
e_num = lookup_widget (button ,"e_tel1");
GtkWidget *e_username;
e_username = lookup_widget (button ,"e_username1");
GtkWidget *e_password;
e_password = lookup_widget (button ,"e_password1");




int x=0;



strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_et1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_et1)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin_et1)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(tel_et1)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(username_et1)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(password_et1)));
if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(e_nom);
}
else {x=0;
gtk_widget_hide(e_nom);
}
if (strcmp(p.prenom,"")==0)
{x=1;
gtk_widget_show(e_prenom);
}
else {x=0;
gtk_widget_hide(e_prenom);
}
if (strcmp(p.cin,"")==0)
{x=1;
gtk_widget_show(e_cin);
}
else {x=0;
gtk_widget_hide(e_cin);
}
if (strcmp(p.gsm,"")==0)
{x=1;
gtk_widget_show(e_num);
}
else {x=0;
gtk_widget_hide(e_num);
}
if (strcmp(p.username,"")==0)
{x=1;
gtk_widget_show(e_username);
}
else {x=0;
gtk_widget_hide(e_username);
}
if (strcmp(p.password,"")==0)
{x=1;
gtk_widget_show(e_password);
}
else {x=0;
gtk_widget_hide(e_password);
}


if (x==0){

 modifier_ett(o.id,p);
GtkWidget *Modifier_et;
Modifier_et=lookup_widget(button,"Modifier_et");
gtk_widget_destroy(Modifier_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);

}}


void
on_retour_ajouteret_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_et;
ajouter_et=lookup_widget(button,"ajouter_et");
gtk_widget_destroy(ajouter_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}


void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier_et;
Modifier_et=lookup_widget(button,"Modifier_et");
gtk_widget_destroy(Modifier_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}


void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer_et;
supprimer_et=lookup_widget(button,"supprimer_et");
gtk_widget_destroy(supprimer_et);
GtkWidget *afficher_et;

  gtk_widget_show (afficher_et);
}


void
on_conf_supp_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_ett(o.id);
GtkWidget *supprimer_et;
supprimer_et=lookup_widget(button,"supprimer_et");
gtk_widget_destroy(supprimer_et);
GtkWidget *afficher_et;

  gtk_widget_show (afficher_et);
}


void
on_radiobutton1_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Homme");
}


void
on_radiobutton2_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Femme");
}


void
on_checkbutton1_ha_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
conf1=1;
}


/*void
on_auth_et_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *erreur_pass;

erreur_pass = lookup_widget(button,"e_auth");

GtkWidget *username, *password, *windowAcceuil_hsm;
char user[20];
char passw[20];
int trouve;
username = lookup_widget (button, "username_et");
password = lookup_widget (button, "password_et");
strcpy(user ,gtk_entry_get_text ( GTK_ENTRY(username)));
strcpy(passw ,gtk_entry_get_text ( GTK_ENTRY(password)));
trouve=verif_pass(user,passw);
if (trouve==1)
{

GtkWidget *window1;
window1=lookup_widget(button,"auth_et");
gtk_widget_destroy(window1);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}
else if (trouve==-1){gtk_widget_show (erreur_pass);}
}
*/

void
on_stat_etttttt_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char nnn[20];
char a[20];
int s;
GtkWidget *comboboxentry3_et;
comboboxentry3_et=lookup_widget(button,"comboboxentry3_et");

GtkWidget *nbr_ettt;
nbr_ettt=lookup_widget(button,"nbr_ettt");

strcpy(nnn,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3_et)));
s = stat(nnn);
sprintf(a,"%d",s);
gtk_label_set_text(GTK_LABEL(nbr_ettt),a);
}
////////////////////////////salmaa ////////////////////////

int z,y;
int l,t2;

//stock salma



void
on_SJtreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
void
on_ajoutsalma_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
produit a;
GtkWidget *windowstock,*type,*id,*nom,*quantite,*jour,*mois,*annee,*choix,*etat;

windowstock=create_window_stock();
id = lookup_widget(button,"entry1_iden");
nom = lookup_widget(button,"entry2_nom");
quantite = lookup_widget(button,"spinbutton1_quantite");
type=lookup_widget(button,"comboboxentry1_type");
jour = lookup_widget(button,"spinbutton1_date");
mois = lookup_widget(button,"spinbutton1_mois");
annee = lookup_widget(button,"spinbutton1_annee");
strcpy(a.identifiant,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
a.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (quantite));
strcpy(a.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
a.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
a.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
a.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
if(z==1 )
{strcpy(a.choix,"produit durable");} 
else
{strcpy(a.choix,"produit périssable");}
if(l==1)
{strcpy(a.etat,"existe déjà");} 
else
{strcpy(a.etat,"inexistant");}
ajouterproduit(a);
z=0;
l=0;
windowstock=create_window_stock();
gtk_widget_show(windowstock);
}

void
on_button2_yes_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
produit a1;
GtkWidget *windowmodif, *windowstock, *id1, *nom1, *quant1,*type1,*jour1,*mois1,*annee1,*choix1,*etat1;
id1 = lookup_widget(button,"entry2_iden");
nom1 = lookup_widget(button,"entry2_nom");
quant1 = lookup_widget(button,"spinbutton2_quantite");
type1=lookup_widget(button,"comboboxentry2_type");
jour1 = lookup_widget(button,"spinbutton2_jour");
mois1 = lookup_widget(button,"spinbutton2_mois");
annee1 = lookup_widget(button,"spinbutton2_annee");
strcpy(a1.identifiant,gtk_entry_get_text(GTK_ENTRY(id1)));
strcpy(a1.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
a1.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (quant1));
strcpy(a1.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type1)));
a1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
a1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
a1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
if(y==1 )
{strcpy(a1.choix,"produit durable");} 
else
{strcpy(a1.choix,"produit périssable");}
if(t2==1)
{strcpy(a1.etat,"existe déjà");} 
else
{strcpy(a1.etat,"inexistant");}
modifierproduit(a1);
y=0;
t2=0;

windowstock=create_window_stock();
gtk_widget_show (windowstock);
}

void
on_radiobuttondur_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_radiobuttonper_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=0;}
}


void
on_radiobutton1per_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=0;}
}


void
on_radiobutton1dur_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_checkbutton2_nv_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{t2=0;}
}


void
on_checkbutton2_anc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{t2=1;}
}

void
on_checkbutton_nv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{l=0;}
}


void
on_checkbutton_anc_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
{l=1;}

}
void
on_salmasupprimer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowstock, *iden, *identi;
GtkWidget *tree;
//windowstock=create_window_stock();
/*windowstock=lookup_widget(button,"window_stock");
tree=lookup_widget(windowstock,"SJtreeview1");
iden = lookup_widget(button,"entry3");
strcpy(identi,gtk_entry_get_text(GTK_ENTRY(iden)));
supprimerproduit(identi);
affichageproduit(tree);

gtk_widget_show(windowstock);*/

windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
gtk_widget_show (windowstock);

}



void
on_button_rechSJ_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrechercher, *windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);

}

/*
void
on_affichagesalma_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowstock;
windowstock=create_window_stock();
tree=lookup_widget(windowstock,"SJtreeview5");

affichageproduit(tree);

gtk_widget_hide(windowstock);
gtk_widget_show(windowstock);
}
*/
////Bouton retour modification ////
void
on_button2_rmod_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodif, *windowstock;
windowstock=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowstock);
//windowinscrit=create_window_inscrit();
//gtk_widget_show (windowinscrit);
}




void
on_button1_rsup_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *windowinscrit;
windowsup=lookup_widget(button,"window_stock");
gtk_widget_destroy(windowsup);
//windowinscrit=create_window_inscrit();
//gtk_widget_show (windowinscrit);
}


void
on_SJtreeview3_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

//rupture//
void
on_checkbutton_sup_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowstock ;
GtkWidget *tree1;
remove("produitrupturer.txt");
windowstock=create_window_stock ();
tree1=lookup_widget(windowstock,"treeview3");
affichageproduitrupturer(tree1);

gtk_widget_hide(windowstock);
gtk_widget_show(windowstock);
}




////Boutton Retour aff rechercher///
void
on_button4_rrrch_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *o, *windowstock;
o=lookup_widget(button,"create_oui");
gtk_widget_destroy(o);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}

void
on_button_affich_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowstock;
windowstock=create_window_stock();
tree=lookup_widget(windowstock,"SJtreeview1");

affichageproduit(tree);

gtk_widget_hide(windowstock);
gtk_widget_show(windowstock);
}
//recherche stock//
void
on_recherchesalma_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
char identir[20];
GtkWidget *idenr, *rech,*o, *n;
GtkWidget *tree;
GtkWidget *windowrechercher;

int ce;
windowrechercher=lookup_widget(button,"window_stock");
o=create_oui();
n=create_non();
idenr = lookup_widget(button,"entry_rech");
strcpy(identir,gtk_entry_get_text(GTK_ENTRY(idenr)));
ce=rechercherproduit(identir);
if (ce==0)
	{
		gtk_widget_show(n);
	}
if (ce==1)	
	{	

gtk_widget_destroy(windowrechercher);
tree=lookup_widget(o,"treeview4");

affichageproduitrechercher(tree);
gtk_widget_show(o);
}
}


void
on_SJtreeview4_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button3_rnon_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *n, *windowstock;
n=lookup_widget(button,"create_non");
gtk_widget_destroy(n);
windowstock=create_window_stock();
gtk_widget_show (windowstock);
}






void
on_button1_rruptu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_buttonrupturee_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowstock;
GtkWidget *output1 ,*output2, *output3 ,*inputquantite;
GtkWidget *o1 ,*o2, *o3, *i11;
char ch[100];

windowstock=create_window_stock();

i11=lookup_widget(button,inputquantite);
o1= lookup_widget(button,output1);
o2= lookup_widget(button,output2);
o3= lookup_widget(button,output3);
gtk_widget_hide (o1);
gtk_widget_hide (o2);
gtk_widget_hide (o3);
message(ch);


windowstock=create_window_stock();
gtk_widget_show (windowstock);
}


