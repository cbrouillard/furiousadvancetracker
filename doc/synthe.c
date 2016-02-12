#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846264338327
#define AMPLITUDE_MAXI 32767

unsigned int taux ;
unsigned long int taille ;
double *gauche, *droite ;
double duree ;

void ecrire_little_endian(unsigned int octets, int taille, FILE *fichier) {
    unsigned char faible ;
    
    while(taille > 0) {   
        faible = octets & 0x000000FF ;
        fwrite(&faible, 1, 1, fichier) ;
        octets = octets >> 8 ;
        taille = taille - 1 ;
    }
}

void ecrire_en_tete_WAV(FILE *fichier) {
    unsigned short int nb_canaux = 2 ;
    unsigned short int nb_bits = 16 ; 
    taux = 44100 ;
    duree = 60 ;
    taille = taux * duree ;
    unsigned long int nb_octets_donnees = (nb_bits / 8) * nb_canaux * taille ;

    gauche = calloc(taille, sizeof(double)) ;
    droite = calloc(taille, sizeof(double)) ;

    fwrite("RIFF", 4, 1, fichier) ;
    ecrire_little_endian(36 + nb_octets_donnees, 4, fichier) ;
    fwrite("WAVE", 4, 1, fichier) ;

    fwrite("fmt ", 4, 1, fichier) ;    
    ecrire_little_endian(16, 4, fichier) ;
    ecrire_little_endian(1, 2, fichier) ;
    ecrire_little_endian(nb_canaux, 2, fichier) ;
    ecrire_little_endian(taux, 4, fichier) ;
    ecrire_little_endian(taux * nb_canaux * (nb_bits / 8), 4, fichier) ;
    ecrire_little_endian(nb_canaux * (nb_bits / 8), 2, fichier) ;
    ecrire_little_endian(nb_bits, 2, fichier) ;

    fwrite("data", 4, 1, fichier) ;   
    ecrire_little_endian(taille * nb_canaux * (nb_bits / 8), 4, fichier) ;
}

void ecrire_donnees_normalisees_WAV(FILE *fichier) {
    unsigned int i ;
    double maxi = 1e-16 ;

    for (i = 0 ; i < taille ; i=i+1) {
        if (fabs(gauche[i]) > maxi)  maxi = fabs(gauche[i]) ;
        if (fabs(droite[i]) > maxi)  maxi = fabs(droite[i]) ;
    }

    for (i = 0 ; i < taille ; i=i+1) {
        ecrire_little_endian((int)(gauche[i]/maxi*AMPLITUDE_MAXI), 2, fichier) ;
        ecrire_little_endian((int)(droite[i]/maxi*AMPLITUDE_MAXI), 2, fichier) ;
    }
}

void mon_signal(double t1, double t2, double f, double Amp) {
    unsigned int i;
    double omega = 2 * PI * f ;
    double t = 0 ;
    double dt = 1.0 / taux ;
    double phi = 0 ;

    for (i=(unsigned int)(t1*taux) ; i<(unsigned int)(t2*taux) ; i=i+1) {
        gauche[i] = gauche[i] + Amp * sin(omega*t + phi) ;
        droite[i] = droite[i] + Amp * sin(omega*t + phi) ;
        t = t + dt ;
    }
}

void generateur_enveloppe(double t1, double t2, double attack, double decay, double sustain, double release) {
    unsigned int i ;    
    unsigned int i1 = t1 * taux ;
    unsigned int i2 = (t1 + (t2-t1) * attack / 100) * taux ;
    unsigned int i3 = (t1 + (t2-t1) * (attack+decay) / 100) * taux ;
    unsigned int i4 = (t2 - (t2-t1) * release / 100) * taux ;
    unsigned int i5 = t2 * taux ;    
    
    for (i=i1 ; i<i2 ; i=i+1) {    
        gauche[i] = gauche[i] * (i-i1)/(double)(i2-i1) ;
        droite[i] = droite[i] * (i-i1)/(double)(i2-i1) ;
    }    
    for (i=i2 ; i<i3 ; i=i+1) {    
        gauche[i] = gauche[i] * (100 - (i-i2)/(double)(i3-i2)*(100-sustain))/100 ;
        droite[i] = droite[i] * (100 - (i-i2)/(double)(i3-i2)*(100-sustain))/100 ;
    }    
    for (i=i3 ; i<i4 ; i=i+1) {    
        gauche[i] = gauche[i] * (sustain / 100) ;
        droite[i] = droite[i] * (sustain / 100) ;
    }       
    for (i=i4 ; i<i5 ; i=i+1) {    
        gauche[i] = gauche[i] * (sustain - (i-i4)/(double)(i5-i4)*sustain) / 100 ;
        droite[i] = droite[i] * (sustain - (i-i4)/(double)(i5-i4)*sustain) / 100 ;
    } 
}

int main(void) {
    FILE *fichier_wav = fopen("synthe.wav", "wb") ;
    ecrire_en_tete_WAV(fichier_wav) ;
    
    mon_signal(0.0, 5.0, 440.0, 1.0) ;
    //generateur_enveloppe(0.0, 5.0, 30.0, 20.0, 80.0, 30.0) ; 
     
    ecrire_donnees_normalisees_WAV(fichier_wav) ;
    fclose(fichier_wav) ;  

    free(gauche) ; 
    free(droite) ;
}