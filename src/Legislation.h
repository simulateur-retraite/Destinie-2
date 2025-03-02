/**
 * \file Legislation.h
 * \brief Contient la classe \ref Leg qui définit l'ensemble des paramètres législatifs pour un individu à un âge et
 * une date de législation donnés
 */


#pragma once
#include "Simulation.h"
#include "Indiv.h"

#define UNDEF 9999


/**
 * \class Leg
 * \brief Contient les valeurs des paramètres législatifs pour un individu, un âge et une date de législation donnés
 * 
 * \ref Leg contient les valeurs des paramètres législatifs pour un individu X et une année
 * donnés. Ces paramètres sont ceux qui ne sont pas directement importés depuis le
 * fichier Excel de paramètres sociaux. Ces paramètres législatitifs 
 * dépendent des caractéristiques individuelles, telles que la génération, le sexe,
 * l'année, et qui sont utiles au calcul des droits à la liquidation avec DroitsRetr.
 * 
 */

class  Leg {
  public:
    double DureeMinFPA;         	  ///<	Durée minimale de carrière pour bénéficier d'une pension FP en catégorie active (ajout  23/09/2011)
    int    an_leg;                     ///<	Année de législation
    int    an_leg_DRA;                 ///<	Année de la législation appliquée en ce qui concerne les départs en retraite anticipé
    int    an_leg_SAM;                 ///<	Année de législation appliquée en ce qui concerne le calcul du SAM
    double DureeCibRG;              ///<	 Durée cible au régime général
    double DureeProratRG;           ///<	 Durée de proratisation du régime général
    double DureeCalcSAM;            ///<	 Nombre d'années pour calcul du SAM dans le RG
    double TauxPleinRG;             ///<	 Taux plein du régime général
    double DecoteRG;                ///<	 Coefficient de décote du régime général (par année d'écart au taux plein)
    double SurcoteRG1;              ///<	 Coefficient de surcote du régime général, 1ere année
    double SurcoteRG2;              ///<	 Coefficient de surcote du régime général, 2eme année
    double SurcoteRG3;              ///<	 Coefficient de surcote du régime général, 3eme année
    double TauxRGMax;               ///<	 Taux maximal de la pension RG
    double MajTauxRGMax;            ///<	 Majoration du taux maximal de pension pris en compte dans le plafonnement
    double DureeCibFP;              ///<	 Durée cible à la fonction publique
    double DureeProratFP;           ///<	 Durée de référence pour une carrière complète à la FP (au dénominateur du coefficient de proratisation)
    double DecoteFP;                ///<	 Decote fonction publique
    double SurcoteFP;               ///<	 Surcote fonction publique
    double AgeAnnDecFP;             ///<	 Âge d'annulation de la décote fonction publique.
    double AgeMinMG;                ///<	 Âge minimal de jouissance du minimum garanti (ajout  27/10/2010)
    double AgeMaxFP;                ///<	 Âge de liquidation maximal FP
    int    LegMin;                  ///<	 Millésime de la législation appliquée pour le calcul des minima de pensions
    int    LegDRA;                  ///<	 Millésime de la législation appliquée pour les départs anticipés
    int    LegSAM;                  ///<	 Millésime de la législation appliquée pour le calcul du SAM
    double AgeMinRG;                ///<	 Âge minimal d'ouverture des droits, RG
    double AgeMaxRG;                ///<	 Âge maximal de liquidation RG
    double AgeAnnDecRG;             ///<	 Âge d'annulation de la décote au RG
    double DureeMinFP;              ///<	 Durée minimale de carrière pour bénéficier d'une pension à la fonction publique (ajout  25/10/2010)
    double AnOuvDroitFP;            ///<	 Année d'ouverture des droits dans la fonction publique (peut être différente de l'année des 60 ans pour les catégories actives et les mères de 3 enfants) (ajout 09/12/2011)
    double AgeSurcote;              ///<	 Âge minimal pour le calcul de la surcote (60 ans avant la réforme de 2010, 62 ans progressivement après)
    double DeplafProrat;            ///<	 Durée au-delà de la durée de référence prise en compte dans le calcul du coefficient de proratisation (dans tous les régimes) (dans le cadre d'un déplafonnement progressif de ce coefficient)
    double DureeValCibDRA[5];       ///<	 Durée validée requise pour un départ anticipé pour carrière longue (plusieurs "jeux" de condition de départ sont possibles, il s'agit donc d'un tableau)
    double DureeCotCibDRA[5];       ///<	 Durée cotisée requise pour un départ anticipé pour carrière longue (plusieurs "jeux" de condition de départ sont possibles, il s'agit donc d'un tableau)
    double DebActCibDRA[5];         ///<	 Âge de début d'activité requis pour un départ anticipé pour carrière longue (plusieurs "jeux" de condition de départ sont possibles, il s'agit donc d'un tableau)
    double AgeDRA[5];               ///<	 Âge d'ouverture des droits dans le cadre d'un départ anticipé pour carrière longue (sous conditions de durée et d'âge définies par l'indice)
    double AgeMinFP;                ///<	 Âge minimal d'ouverture des droits, FP (cet âge est défini par individu, après analyse de la catégorie pertinente) 
    double ageouvdroitfp;           ///<	 Âge d'ouverture des droits pour les fonctionnaires sédentaires calculé en fonction de la génération
    int    durfpa;                  ///<	 Durée passée en catégorie active
    
    
    /**
     * \fn Leg(const Indiv& X, int age, int an_leg)
     * \brief Crée un objet législation pour un individu, un âge et une date de législation donnés.
     * 
     * Crée un objet législation pour un individu particulier, à un age donné, et une législation donnée.
     * 
     * Appelle les sous-méthodes suivantes :
     * - leg_priv (Législation régimes RG, RSI, Arrco, Agirc)
     * - leg_pub  (Législation régime FP)
     * - leg_spe  (Régimes spéciaux)
     * - leg_dra  (Législation sur les départ en retraite anticipée pour carrière longue)
     * - an_ouv_droit_fp (Calcul de l'année d'ouverture des droits à la FP)
     **/
    Leg(const Indiv& X, int age, int an_leg);   
    
private:
    void leg_priv(const Indiv & X, int age);
    void leg_pub(const Indiv & X, int age);
    void leg_spe(const Indiv & X, int age);
    void leg_dra(const Indiv & X, int age);
    double an_ouv_droit_fp(const Indiv & X, int age);
};


// Destinie 2
// Copyright © 2005-2018, Institut national de la statistique et des études économiques
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.