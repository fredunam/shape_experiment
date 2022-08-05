//
// Created by fred on 28/07/22.
//

#include "shape_formation.h"

CShapeLoopFunctions::CShapeLoopFunctions() : CLoopFunctions(), m_cSimulator(GetSimulator()), m_iCellsPerMetre(100),
         m_iCellsPerMetreOBS(100),
         m_ohcEmbodiedEntity(CEmbodiedEntity(NULL, "ohc_body", CVector3(0, 0, 1),
                                             CQuaternion())),
         m_cCommAnchor(m_ohcEmbodiedEntity.AddAnchor("comm", CVector3(0, 0, 0))),
         m_tx_flag(false), m_messaging_counter(0), m_floor_counter(0),
         m_update_matrix_timesteps(0), MatrixSize_x(0), MatrixSize_y(0),
         floorMatrix(0), OBSMatrixSize_x(0), OBSMatrixSize_y(0), obstacle_Matrix(0),
         m_showObstacleAvoidanceArea(false),
         maxPheroLimit(std::numeric_limits<float>::max()), evaporation_rate(0.05),
         diffusion_rate(0.02), pheromone_amount(250),
         m_obstacle_avoidance_range(0.05), m_Vmax(0) {
    }

CShapeLoopFunctions::~CShapeLoopFunctions(){}

void CShapeLoopFunctions::Init(TConfigurationNode &t_tree) {

}

void CShapeLoopFunctions::Reset() {

}

void CShapeLoopFunctions::write_file() {

}

void CShapeLoopFunctions::read_file() {
    ifstream file("src/examples/shape_files/u_letter.txt");
    char END_OF_FILE = '#';
    char singleChar;

    if(file){

    }
}

void CShapeLoopFunctions::Destroy() {

}

void CShapeLoopFunctions::Prestep() {

}

void CShapeLoopFunctions::PostStep() {

}

void CShapeLoopFunctions::GetKilobotsEntities() {

}

CVector2 CShapeLoopFunctions::GetKilobotPosition(CKilobotEntity *kilobot_entity) {
    CVector3 pos3D = kilobot_entity->GetEmbodiedEntity().GetOriginAnchor().Position;
    std::cout << "uid: " << kilo_uid << " - pos_X: " << pos3D.GetX() << " - pos_Y: " << pos3D.GetY() << std::endl;
    return CVector2(pos3D.GetX(), pos3D.GetY());
}


void CShapeLoopFunctions::Get_message_receive(CKilobotEntity *kilobot_entity, message_t &message) {

}

void CShapeLoopFunctions::Get_message_to_send(CKilobotEntity *kilobot_entity, message_t &message) {

    CVector2 kb_pos= GetKilobotPosition(kilobot_entity);

}


UInt16 CShapeLoopFunctions::GetKilobotId(CKilobotEntity *kilobot_entity){
    std::string entity_id((kilobot_entity)->GetControllableEntity().GetController().GetId());
    return std::stoul(entity_id.substr(2));
}




