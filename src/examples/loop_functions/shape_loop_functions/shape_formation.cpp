/*  Authors: Mohamed S. Talamali (mstalamali1@sheffield.ac.uk) and Andreagiovanni Reina (a.reina@sheffield.ac.uk)
 *
 *  If you use this code for scientific experiment, please cite: M.S. Talamali et al. Swarm Intelligence (2019)
 *
 *  Copyright University of Sheffield, 2019
 */

#include "shape_formation.h"
#include <limits>
#define I2I(x,y) int(x)*MatrixSize_x+int(y)
#define I2I_OBS(x,y) int(x)*OBSMatrixSize_x+int(y)


/****************************************/
/****************************************/

CShapeFormation::CShapeFormation() {

}

CShapeFormation::~CShapeFormation() {

}

void CShapeFormation::Reset() {
    CLoopFunctions::Reset();
}

void CShapeFormation::Destroy() {
    CLoopFunctions::Destroy();
}

void CShapeFormation::PreStep() {
    CLoopFunctions::PreStep();
}

void CShapeFormation::PostStep() {
    CLoopFunctions::PostStep();
}


int CShapeFormation::nbLineFile(){

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


int CShapeFormation::nbCharFile(){

    int nbChar = 0;
    ifstream file("/home/fred/argos3-kilobot/src/examples/shape_files/Shape_U.txt", ios::in);

    if(file){
        char characters;
        string lines;
        while(file.get(characters)){
            if(characters == '0' || characters == '1'){
                nbChar++;
            }
        }
        file.close();
    } else {
        cerr << "ERROR: Impossible to open the file" << endl;
    }

    return nbChar;
}


void CShapeFormation::readFile(){

    m_hop = 0.10;
    m_xExtremFile = -1.40;
    m_yExtremFile = -1.50;
    m_nbLines = nbLineFile();
    m_nbChar = nbCharFile();
    m_nbColumn = m_nbChar / m_nbLines;

    STarget setTargets;

    ifstream file ("/home/fred/argos3-kilobot/src/examples/shape_files/Shape_U.txt", ios::in);
    if(file){
        for (int i = 0; i < m_nbLines; ++i) {
            for (int j = 0; j < m_nbColumn+1; ++j) {
                file.get(m_charact);
                if(m_charact == '0'){
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
