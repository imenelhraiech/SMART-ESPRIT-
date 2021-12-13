#include <gtk/gtk.h>

int k;
int m;
int j;
int i ;
 GtkWidget *acceuilw;
  GtkWidget *gestionw;
GtkWidget *dialog_service_partie_2;
void
on_affi_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_actu_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_rech_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Modif_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);
void
on_supp_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_tree_mo_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_auth_youtube_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_auth_facebook_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_auth_instagram_clicked              (GtkButton       *button,
                                        gpointer         user_data);
void
on_checkbutton2MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ok_mo_clicked                       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton1MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_FacebookMO_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_youtubeMO_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_InstagramMO_clicked                   (GtkButton       *button,
                                        gpointer         user_data);


void
on_checkbutton4MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
///////////////////////////////////////////nourchene///////////////////////////


void
on_affi_nb_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actu_nb_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_rech_nb_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Modif_nb_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_nb_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);
void
on_supp_nb_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_tree_nb_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_auth_youtube_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_auth_facebook_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_auth_instagram_clicked              (GtkButton       *button,
                                        gpointer         user_data);
void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ok_nb_clicked                       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_Facebook_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_youtube_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Instagram_clicked                   (GtkButton       *button,
                                        gpointer         user_data);


void
on_radiobutton5etage2_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4etage1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3BlocA_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4BlocB_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

////////////////////////////imen///////////////////



void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercherreclamation_clicked          (GtkButton       *button,
                                        gpointer         user_data);



void
on_Ajouterreclamation_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierreclamation_clicked           (GtkButton       *button,
                                        gpointer         user_data);



void
on_button_calcule_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_validersomme_clicked                (GtkButton       *button,
                                        gpointer         user_data);


void
on_GestionAcceuilw_clicked             (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_service_partie_2_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_boutontache2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_service_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_heb_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_rest_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_radiobutton_rest_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
////////////hamzaa//////////////





/*void
on_treeview1_user_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);*/

void
on_go_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_user_clicked             (GtkButton       *button,
                                        gpointer         user_data);
/*
void
on_rechercher_user_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconn_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_treeview1_et_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_et_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_ajouteret_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_conf_supp_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_ha_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

/*void
on_auth_et_clicked                     (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_stat_etttttt_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_et_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_et_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

////salmaa//////
int o1;
int m;
int s;



// stock salma///////////////////////////////////////////////////////////////////////////

void
on_SJtreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_affich_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechSJ_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton2_nv_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_anc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_affichagesalma_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_rmod_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_nv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_anc_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_salmasupprimer_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_rsup_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_SJtreeview3_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbutton_sup_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_rruptu_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_rrrch_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherchesalma_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_SJtreeview4_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button3_rnon_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajoutsalma_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_yes_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttondur_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonper_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1per_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1dur_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonrupturee_clicked              (GtkButton       *button,
                                        gpointer         user_data);


