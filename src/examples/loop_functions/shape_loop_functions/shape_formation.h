/*  Authors: Mohamed S. Talamali (mstalamali1@sheffield.ac.uk) and Andreagiovanni Reina (a.reina@sheffield.ac.uk)
 *
 *  If you use this code for scientific experiment, please cite: M.S. Talamali et al. Swarm Intelligence (2019)
 *
 *  Copyright University of Sheffield, 2019
 */

#ifndef OBS_LOOP_H // changed from ARK_TEST_H
#define OBS_LOOP_H // changed from ARK_TEST_H

namespace argos {
    class CSpace;
    class CRay3;
    class CFloorEntity;
    class CSimulator;
}


#include <math.h>
// basic file operations
#include <iostream>
#include <fstream>

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/core/simulator/simulator.h>
#include <argos3/core/utility/math/vector3.h>
#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/math/quaternion.h>
#include <argos3/core/utility/logging/argos_log.h>
//#include <argos3/plugins/simulator/visualizations/qt-opengl/qtopengl_user_functions.h>

#include <argos3/core/simulator/entity/embodied_entity.h>
#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/plugins/simulator/entities/led_equipped_entity.h>
#include <argos3/core/simulator/entity/floor_entity.h>

#include <argos3/plugins/robots/kilobot/simulator/kilobot_entity.h>
#include <argos3/plugins/robots/kilobot/simulator/kilobot_communication_entity.h>
#include <argos3/plugins/robots/kilobot/simulator/kilobot_communication_medium.h>
#include <argos3/plugins/robots/kilobot/simulator/kilobot_communication_default_actuator.h>

//kilobot messaging
#include <argos3/plugins/robots/kilobot/control_interface/kilolib.h>
#include <argos3/plugins/robots/kilobot/control_interface/message_crc.h>
#include <argos3/plugins/robots/kilobot/control_interface/message.h>

#include <array>
#include <list>
#include <iostream>
#include <vector>

using namespace std;
using namespace argos;

class CShapeFormation : public CLoopFunctions {

public:

    typedef std::map<CKilobotEntity*, std::vector<CVector3> > TWaypointMap;

public:

    CShapeFormation();
    virtual ~CShapeFormation();
    virtual void Init(TConfigurationNode& t_tree);// Peut être utilisé pour ajouter des éléments du fichier .argos.
    virtual void Reset();
    virtual void Destroy();
    virtual void PreStep();
    virtual void PostStep();

    /**
     * Créé un vecteur m_KilobotsEntities de pointeurs sur chaque entité 'kilobot'
     */
    void GetKilobotsEntities();

    /**
     * Donne la position d'un kilobot
     * @param kilobot_entity ptr sur une entité 'kilobot'
     * @return un vecteur 2d posX et posY
     */
    CVector2 GetKilobotPosition(CKilobotEntity *kilobot_entity);


    /**
     * Récupère l'orientation des robots
     * @param kilobot_entity ptr sur une entité 'kilobot'
     * @return l'angle du robot par rapport à l'axe des Y
     */
    CRadians GetKilobotOrientation(CKilobotEntity *kilobot_entity);


    /**
     * Converti et renvoie un entier représentant l'id du robot associé à ce contrôleur.
     * @param kilobot_entity ptr sur une entité 'kilobot'
     * @return l'id du 'kilobot'
     */
    UInt16 GetKilobotId(CKilobotEntity *kilobot_entity);

    /**
     *
     * @param number_of_comm_entities
     */
    void CreateOhcCommunicationEntities(unsigned int number_of_comm_entities);

    /**
     * lit un fichier, parcourt toutes les lignes et incrémente une variable à retourner
     * @return the number of lines
     */
    static int nbLineFile();


    /**
     * lit un fichier, parcourt toutes les caractères et incrémente une variable à retourner
     * @return le nombre de carcatère correspondant à '1' ou à '0'
     */
    static int nbCharFile();


    /**
     * Lit un fichier et construit un vecteur de structures reprennant les coordonnées X et Y
     *   des caractères '0' présents dans le fichier. LE contenu de ce vecteur sera les cibles que devront
     *   atteindre les kilobots
     */
    void readFile();



private:

    //Calculate the evaporation and diffusion for each cell
    void updatePheromoneMatrix();

    void write_file();

    void read_file();

    // A reference to the simulator
    CSimulator& m_cSimulator;

    // A reference to the space
    //CSpace& m_cSpace;

    // Space size
    CVector3 m_vSpaceSize;

    // Padding of the space to shift the index and access the floorMatrix
    CVector3 m_vSpaceLimits;

    // Cells per metre
    int m_iCellsPerMetre;

    // Cells per metre
    int m_iCellsPerMetreOBS;

    //The OHC embodied entity
    CEmbodiedEntity m_ohcEmbodiedEntity;

    //The OHC communication Anchor
    SAnchor& m_cCommAnchor;

    //List of the OHC communication entities
    typedef std::vector<CKilobotCommunicationEntity> KCVector;
    KCVector m_ohcCommunicationEntities;

    //List of the Kilobots in the space
    typedef std::vector<CKilobotEntity*> KVector;
    KVector m_KilobotsEntities;

    // List of the messages sent by communication entities
    typedef std::vector<message_t> KMVector;
    KMVector m_messages;


    std::vector<int> m_BringingFoodFrom;


    //A flag for a kilbot needs a message to be sent or not
    bool m_tx_flag;

    //Counters for messages and data acquizition
    unsigned int m_messaging_counter, m_floor_counter;
    unsigned int m_update_matrix_timesteps;

    //output file name
    std::string m_strOutput;

    //Radius of the circles
    std::vector<int> hasFood;
    std::map<UInt16, int> collected;
    std::vector<int> onPath;
    float phToSend[210][4];

    //options vector
    struct FoodClass{
        int id;
        int quality;
        CVector2 position;
        Real radius;
        UInt8 colour;
    };

    std::vector<FoodClass> foodVector;

    int MatrixSize_x;
    int MatrixSize_y;
    float *floorMatrix;


    int OBSMatrixSize_x;
    int OBSMatrixSize_y;

    std::string m_strOutputFilename;

    float  diffusion_rate;

    int m_Vmax;

    Real m_fTimeInMinutes;

    Real m_fDataRecordingStartTimeInMinutes;

    float m_hop;
    float m_xExtremFile, m_yExtremFile;

    int m_nbLines, m_nbChar, m_nbColumn;

    char m_charact;
    string m_line;

    /******************************************************************/
    /******************************************************************/

    static int nbChar;

    //Target vector
    typedef struct{
        float xTarget;
        float yTarget;
    }STarget;
    std::vector<STarget> targetVector;

};




#endif
