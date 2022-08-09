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
     * reads a file and calculates the number of lines
     * @return the number of lines
     */
    int nbLineFile();

    /**
     * reads a file and calculates the number of characters
     * @return
     */
    int nbCharFile();

    /**
     *
     */
    void readFile();



private:

    // Space size
    CVector3 m_vSpaceSize;

    int m_iCellsPerMetre;

    int m_iCellsPerMetreOBS;

    //List of kilobots
    typedef  std::vector<CKilobotEntity*> KVector;
    KVector m_kilobotsEntities;

    typedef std::vector<message_t> KMVector;
    KMVector m_messages;

    //Counter for messages
    unsigned int m_messaging_counter;

    //Target vector
    typedef struct{
        float xTarget;
        float yTarget;
    }STarget;

    std::vector<STarget> targetVector;

    int MatrixSize_x;
    int MatrixSize_y;
    float *floorMatrix;

    float m_hop;
    float m_xExtremFile, m_yExtremFile;

    int m_nbLines, m_nbChar, m_nbColumn;

    char m_charact;
    string m_line;

};




#endif
