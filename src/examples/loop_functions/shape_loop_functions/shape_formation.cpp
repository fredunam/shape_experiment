/*  Authors: Mohamed S. Talamali (mstalamali1@sheffield.ac.uk) and Andreagiovanni Reina (a.reina@sheffield.ac.uk)
 *
 *  If you use this code for scientific experiment, please cite: M.S. Talamali et al. Swarm Intelligence (2019)
 *
 *  Copyright University of Sheffield, 2019
 */

#include "shape_formation.h"
#include <limits>

#define I2I(x, y) int(x)*MatrixSize_x+int(y)
#define I2I_OBS(x, y) int(x)*OBSMatrixSize_x+int(y)


/****************************************/
/****************************************/

CShapeFormation::CShapeFormation()
        : CLoopFunctions(), m_cSimulator(GetSimulator()), m_iCellsPerMetre(100), m_iCellsPerMetreOBS(100),
          m_ohcEmbodiedEntity(
                  CEmbodiedEntity(NULL, "ohc_body", CVector3(0, 0, 1), CQuaternion())),
          m_cCommAnchor(m_ohcEmbodiedEntity.AddAnchor("comm", CVector3(0, 0, 0))),
          m_tx_flag(false), m_messaging_counter(0), m_floor_counter(0), m_update_matrix_timesteps(0),
          MatrixSize_x(0), MatrixSize_y(0), floorMatrix(0), OBSMatrixSize_x(0), OBSMatrixSize_y(0),
          diffusion_rate(0.02), m_Vmax(0) {
}

CShapeFormation::~CShapeFormation() {

}

void CShapeFormation::Init(TConfigurationNode& t_node) {

}


void CShapeFormation::Reset() {
    CLoopFunctions::Reset();
}

void CShapeFormation::Destroy() {
    CLoopFunctions::Destroy();
}

void CShapeFormation::PreStep() {
    CLoopFunctions::PreStep();
    printf("test de lecture");
}

void CShapeFormation::PostStep() {
    CLoopFunctions::PostStep();
}

/****************************************/
/****************************************/

void CShapeFormation::GetKilobotsEntities() {

    //Parcourez tous les robots de l'environnement et créez un vecteur de pointeurs sur leurs entités
    CSpace::TMapPerType &kilobots_map = CSimulator::GetInstance().GetSpace().GetEntitiesByType("kilobot");

    for (auto &it: kilobots_map) {
        m_KilobotsEntities.push_back(any_cast<CKilobotEntity*>(it.second));
    }
}

/****************************************/
/****************************************/


UInt16 CShapeFormation::GetKilobotId(CKilobotEntity *kilobot_entity) {
    std::string entity_id((kilobot_entity)->GetControllableEntity().GetController().GetId());
    return std::stoul(entity_id.substr(2));
}

/****************************************/
/****************************************/

CVector2 CShapeFormation::GetKilobotPosition(CKilobotEntity *kilobot_entity) {
    CVector3 pos3D = kilobot_entity->GetEmbodiedEntity().GetOriginAnchor().Position;
    return {pos3D.GetX(), pos3D.GetY()};
}

/****************************************/
/****************************************/

CRadians CShapeFormation::GetKilobotOrientation(CKilobotEntity *kilobot_entity) {
    CRadians cZAngle;
    CRadians cYAngle;
    CRadians cXAngle;
    CQuaternion cQuaternion = kilobot_entity->GetEmbodiedEntity().GetOriginAnchor().Orientation;
    cQuaternion.ToEulerAngles(cZAngle, cYAngle, cXAngle);
    return cZAngle;
}

/****************************************/
/****************************************/

void CShapeFormation::CreateOhcCommunicationEntities(unsigned int number_of_comm_entities) {
    m_ohcCommunicationEntities = KCVector(number_of_comm_entities,
                                          CKilobotCommunicationEntity(NULL, "kilocomm_0", 9, 1.0, m_cCommAnchor,
                                                                      m_ohcEmbodiedEntity));
    m_messages = KMVector(number_of_comm_entities);
}

/****************************************/
/****************************************/

int CShapeFormation::nbLineFile() {

    int nbLines = 0;
    std::ifstream file("/home/fred/argos3-kilobot/src/examples/shape_files/Shape_U.txt", ios::in);
    string lines;

    if (file) {
        while (getline(file, lines)) {
            nbLines++;
        }
        file.close();
    } else {
        cerr << "ERROR: Impossible to open the file" << endl;
    }

    return nbLines;
}


int CShapeFormation::nbCharFile() {

    int nbChar = 0;
    ifstream file("/home/fred/argos3-kilobot/src/examples/shape_files/Shape_U.txt", ios::in);

    if (file) {
        char characters;
        string lines;
        while (file.get(characters)) {
            if (characters == '0' || characters == '1') {
                nbChar++;
            }
        }
        file.close();
    } else {
        cerr << "ERROR: Impossible to open the file" << endl;
    }

    return nbChar;
}


void CShapeFormation::readFile() {

    m_hop = 0.10;
    m_xExtremFile = -1.40;
    m_yExtremFile = -1.50;
    m_nbLines = nbLineFile();
    m_nbChar = nbCharFile();
    m_nbColumn = m_nbChar / m_nbLines;


    STarget setTargets;

    ifstream file("/home/fred/argos3-kilobot/src/examples/shape_files/Shape_U.txt", ios::in);
    if (file) {
        for (int i = 0; i < m_nbLines; ++i) {
            for (int j = 0; j < m_nbColumn + 1; ++j) {
                file.get(m_charact);
                if (m_charact == '0') {
                    setTargets.xTarget = m_xExtremFile;
                    setTargets.yTarget = m_yExtremFile;
                    targetVector.push_back(setTargets);
                }
                m_yExtremFile = m_yExtremFile + m_hop;
            }
            m_yExtremFile = -1.50;
            m_xExtremFile = m_xExtremFile + m_hop;
        }
        file.close();
    } else {
        cerr << "ERROR: Impossible to open the file" << endl;
    }
}


REGISTER_LOOP_FUNCTIONS(CShapeFormation, "ARKloopfunction")
