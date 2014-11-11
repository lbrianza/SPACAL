#ifndef __init_tree_H4__
#define __init_tree_H4__

#include "TTree.h"
#include "TChain.h"

    // Declaration of leaf types
    unsigned int          evtNumber;
    unsigned int          evtTimeDist;
    unsigned int          evtTimeStart;
//    unsigned int          evtTime;
//    unsigned int          boardTriggerBit;
//    unsigned int          triggerWord;
    unsigned int          nAdcChannels;
    unsigned int          adcBoard[100];   
    unsigned int          adcChannel[100];   
    unsigned int          adcData[100];   
    unsigned int          nTdcChannels;
    unsigned int          tdcBoard[10];   
    unsigned int          tdcChannel[10];  
    unsigned int          tdcData[10];  
    unsigned int          nDigiSamples;
    unsigned int          digiGroup[100000];   
    unsigned int          digiChannel[100000];   
    unsigned int          digiSampleIndex[100000];   
    float                 digiSampleValue[100000];   

std::vector<float>   *TDCreco = 0;
std::vector<float>   *digi_charge_integrated = 0;
std::vector<float>   *digi_max_amplitude = 0;
std::vector<float>   *digi_pedestal = 0;
std::vector<float>   *digi_time_at_frac50 = 0;
std::vector<float>   *digi_time_at_max = 0;
std::vector<float>   *HODOX1 = 0;
std::vector<float>   *HODOX2 = 0;
std::vector<float>   *HODOY1 = 0;
std::vector<float>   *HODOY2 = 0;
int spillNumber;

    // List of branches
    TBranch        *b_evtNumber;   //!
    TBranch        *b_evtTimeDist;   //!
    TBranch        *b_evtTimeStart;   //!
//    TBranch        *b_evtTime;   //!
//    TBranch        *b_boardTriggerBit;   //!
//    TBranch        *b_triggerWord;   //!
    TBranch        *b_nAdcChannels;   //!
    TBranch        *b_adcBoard;   //!
    TBranch        *b_adcChannel;   //!
    TBranch        *b_adcData;   //!
    TBranch        *b_nTdcChannels;   //!
    TBranch        *b_tdcBoard;   //!
    TBranch        *b_tdcChannel;   //!
    TBranch        *b_tdcData;   //!
    TBranch        *b_nDigiSamples;   //!
    TBranch        *b_digiGroup;   //!
    TBranch        *b_digiChannel;   //!
    TBranch        *b_digiSampleIndex;   //!
    TBranch        *b_digiSampleValue;   //!

TBranch  *b_TDCreco;
TBranch  *b_spillNumber;
TBranch  *b_digi_charge_integrated;
TBranch  *b_digi_max_amplitude;
TBranch  *b_digi_time_at_frac50;
TBranch  *b_digi_time_at_max;
TBranch  *b_digi_pedestal;
TBranch  *b_HODOX1;
TBranch  *b_HODOY1;
TBranch  *b_HODOX2;
TBranch  *b_HODOY2;
   
void InitTree(TChain* nt);

void InitTree2(TChain* nt2);

#endif
