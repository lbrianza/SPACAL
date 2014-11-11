/*******************************************************************************
THIS PROGRAM READ THE RAW DATA AND PRODUCE THE RECO FILE USED FOR THE ANALYSIS

*******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <stdint.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream> 
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <iomanip>
#include <ctime>
#include <map>
#include <math.h>

#include "TROOT.h"
#include "TFile.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TChain.h"
#include "TF1.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TMath.h"
#include "TString.h"
#include "TClass.h"
#include "TApplication.h"

#include "../src/analysis_tools.cc"
#include "../src/init_tree_H4.cc"
#include "../src/init_Reco_Tree.cc"
//#include "../interface/histo_func.h"

//*******MAIN*******************************************************************
int main (int argc, char** argv)
{  
    std::cout<<"--------DUMPER: READ RAW DATA AND PRODUCE RECO TREE--------"<<std::endl;

    
    //--------Read Options--------------------------------
    ifstream inputCfg (argv[1], ios::in);

    std::string inputFolder = argv[2];
    int nChannels = atoi (argv[3]);
    std::string outputFile = argv[4];

    //---------output tree----------------
    TFile* outROOT = TFile::Open(("ntuples/reco_"+outputFile+".root").c_str(),"recreate");  
    outROOT->cd();

    TTree* outTree = new TTree("reco_tree", "reco_tree");
    outTree->SetDirectory(0);
    SetOutTree(outTree);

    int run=0, chNumber=0, hv=0;

    int Energy=-10000;
    float xPos=-10000, yPos=-10000;

    //-------start to read the cfg file--------
    while(!inputCfg.eof())  
    {
      inputCfg >> run >> Energy >> xPos >> yPos >> hv;


      TChain* t1 = new TChain("outputTree");
      InitTree2(t1);

      TChain* chain = new TChain("H4tree");
      InitTree(chain);

      char command1[300];
      sprintf(command1, "find  %s/%d/*/dqmPlotstotal.root > listTemp.txt", (inputFolder).c_str(), run);
      system(command1);
      char command2[300];
      sprintf(command2, "find  %s/%d/[0-9]*.root > listTemp2.txt", (inputFolder).c_str(), run);
      system(command2);

      ifstream rootList ("listTemp.txt");
      ifstream rootList2 ("listTemp2.txt");

      while (!rootList.eof() && !rootList2.eof())
	{
	  char iRun_tW[70];
	  rootList >> iRun_tW;
	  char iRun_str[70];
	  rootList2 >> iRun_str;
	  
	  TChain* tTemp = new TChain("outputTree");
	  tTemp->Add(iRun_tW);
	  TChain* tTempH4 = new TChain("H4tree");
	  tTempH4->Add(iRun_str);
	  
	  if (tTemp->GetEntries() == tTempH4->GetEntries())
	    {
	      t1->Add(iRun_tW);	
	      chain->Add(iRun_str);	
	    }
	  else
	    std::cout<<"Bad spill found.. Skipped"<<std::endl;
	  tTemp->Delete();
	  tTempH4->Delete();
	}
      
      system("rm listTemp.txt");
      system("rm listTemp2.txt");
      
      std::cout<<"start reading run: "<<run<<std::endl;
      
      //-----Data loop--------------------------------------------------------
      for(int iEntry=0; iEntry<chain->GetEntries(); iEntry++){

	    if(iEntry % 1000 == 0)
		cout << "read entry: " << iEntry << endl;

            //---Read the entry
            chain->GetEntry(iEntry);
 
	    int spill=spillNumber;
	    int event=evtNumber;

	    //---Read digitizer samples

	    //	    for(unsigned int iSample=0; iSample<nDigiSamples; iSample++){
	    //	      if (digiGroup[iSample]==3 && digiChannel[iSample]>=1) continue;
	    //	      int i = (digiGroup[iSample]*9+digiChannel[iSample]);
	    //  digiCh[i].push_back(digiSampleValue[iSample]);
	    //  }
      	     run_id = run;
	     HV = hv;

	     t1->GetEntry(iEntry);

	     for (int iCh=0; iCh<nChannels; iCh++)
		  {
		    time_CF[iCh]   = (*digi_time_at_frac50)[iCh];
		    amp_max[iCh]   = (*digi_max_amplitude)[iCh];
		    charge[iCh]    = (*digi_charge_integrated)[iCh];
		    baseline[iCh]  = (*digi_pedestal)[iCh];
		    hodoX1 = (*HODOX1)[iCh];
		    hodoX2 = (*HODOX2)[iCh];
		    hodoY1 = (*HODOY1)[iCh];
		    hodoY2 = (*HODOY2)[iCh];
		  }


	     tdcX = (*TDCreco)[0];
	     tdcY = (*TDCreco)[1];

	     if (spill!=spillNumber || event!=evtNumber) {
	       std::cout<<"PROBLEM: non-coherent read"<<std::endl;
	       continue;
	     }

	     energy=Energy;
	     xTable = xPos;
	     yTable = yPos;
	     outTree->Fill();    

	     //  }
	}     
        //---Get ready for next run
        chain->Delete();
	t1->Delete();
    }
    
    //-----close everything-----------------------------------------------------
    outTree->Write();
    outROOT->Close();
    
//---------Done-----------------------------------------------------------------
}

        
