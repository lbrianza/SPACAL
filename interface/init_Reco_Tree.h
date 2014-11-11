#ifndef __init_Reco_Tree__
#define __init_Reco_Tree__

#include "TTree.h"
#include "TChain.h"

    // Declaration of leaf types
float                 time_CF[32]={};   
float                 amp_max[32]={};   
float                 charge[32]={};   
float                 baseline[32]={};   
int                   run_id=0;   
int                   HV=0;   
float tdcX=-999.;
float tdcY=-999.;
float hodoX1=-999.;
float hodoY1=-999.;
float hodoX2=-999.;
float hodoY2=-999.;
int energy=0;
float xTable=0.;
float yTable=0.;

    // List of branches
    TBranch        *b_time_CF;   //!
    TBranch        *b_amp_max;   //!
    TBranch        *b_baseline;   //!
    TBranch        *b_charge;   //!
    TBranch        *b_run_id;   //!
    TBranch        *b_HV;   //!
TBranch *b_tdcX;
TBranch *b_tdcY;
TBranch *b_hodoX1;
TBranch *b_hodoY1;
TBranch *b_hodoX2;
TBranch *b_hodoY2;
TBranch *b_energy;
TBranch *b_xTable;
TBranch *b_yTable;
   
void InitRecoTree(TTree* nt);

void init();

void SetOutTree(TTree* outTree);

#endif
