#include "trajectory_loop_functions.h"
#include <iostream>

using namespace std;

/****************************************/
/****************************************/

/*
 * Pour réduire le nombre de points de passage stockés en mémoire, considérez que
 * deux positions du robot sont distinctes si elles sont distantes d'au moins MIN_DISTANCE.
 * Cette constante est exprimée en mètres
 */
static const Real MIN_DISTANCE = 0.05f;  //5cm
/* Constante de commodité pour éviter de calculer la racine carrée dans PostStep() */
static const Real MIN_DISTANCE_SQUARED = MIN_DISTANCE * MIN_DISTANCE; //0,25cm

/****************************************/
/****************************************/

void CTrajectoryLoopFunctions::Init(TConfigurationNode& t_tree) {
   /*
    * Passez en revue tous les robots de l'environnement et créez une entrée
    * dans la carte des points de passage pour chacun d'entre eux.
    */
   /* Obtenez la carte de tous les kilobots de l'espace */
   CSpace::TMapPerType& tKBMap = GetSpace().GetEntitiesByType("kilobot");
   /* Go through them */
   for(CSpace::TMapPerType::iterator it = tKBMap.begin(); it != tKBMap.end(); ++it)
   {
      /* Create a pointer to the current kilobot */
      CKilobotEntity* pcKB = any_cast<CKilobotEntity*>(it->second);
      /* Create a waypoint vector */
      m_tWaypoints[pcKB] = std::vector<CVector3>();
      /* Add the initial position of the kilobot */
      m_tWaypoints[pcKB].push_back(pcKB->GetEmbodiedEntity().GetOriginAnchor().Position);

      //cout << pcKB->GetEmbodiedEntity().GetOriginAnchor().Position << endl;
   }
}

/****************************************/
/****************************************/

void CTrajectoryLoopFunctions::Reset() {
   /*
    * Clear all the waypoint vectors
    */
   /* Get the map of all kilobots from the space */
   CSpace::TMapPerType& tFBMap = GetSpace().GetEntitiesByType("kilobot");
   /* Go through them */
   for(CSpace::TMapPerType::iterator it = tFBMap.begin();
       it != tFBMap.end();
       ++it) {
      /* Create a pointer to the current kilobot */
      CKilobotEntity* pcFB = any_cast<CKilobotEntity*>(it->second);
      /* Clear the waypoint vector */
      m_tWaypoints[pcFB].clear();
      /* Add the initial position of the kilobot */
      m_tWaypoints[pcFB].push_back(pcFB->GetEmbodiedEntity().GetOriginAnchor().Position);

   }
}

/****************************************/
/****************************************/

void CTrajectoryLoopFunctions::PostStep() {
   /* Get the map of all kilobots from the space */
   CSpace::TMapPerType& tKBMap = GetSpace().GetEntitiesByType("kilobot");
   /* Go through them */
   for(CSpace::TMapPerType::iterator it = tKBMap.begin();
       it != tKBMap.end();
       ++it) {
      /* Create a pointer to the current kilobot */
      CKilobotEntity* pcKB = any_cast<CKilobotEntity*>(it->second);
      /*
       * Ajouter la position actuelle du kilobot si elle est suffisamment éloignée de
       * la dernière position du kilobot.
      */
      if(SquareDistance(pcKB->GetEmbodiedEntity().GetOriginAnchor().Position,
                        m_tWaypoints[pcKB].back()) > MIN_DISTANCE_SQUARED) {
         m_tWaypoints[pcKB].push_back(pcKB->GetEmbodiedEntity().GetOriginAnchor().Position);
          cout << pcKB->GetEmbodiedEntity().GetOriginAnchor().Position << endl;
      }
   }

}

/****************************************/
/****************************************/



REGISTER_LOOP_FUNCTIONS(CTrajectoryLoopFunctions, "trajectory_loop_functions")
