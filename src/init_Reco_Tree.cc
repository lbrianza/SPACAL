#include "../interface/init_Reco_Tree.h"

void init()
{
}

void SetOutTree(TTree* outTree)
{
  //---standard analysis branches
  outTree->Branch("time_CF",&time_CF,"time_CF[32]/F");
  outTree->Branch("amp_max",&amp_max,"amp_max[32]/F");
  outTree->Branch("charge",&charge,"charge[32]/F"); 
  outTree->Branch("baseline",&baseline,"baseline[32]/F");
  
  outTree->Branch("run_id",&run_id,"run_id/I");

  outTree->Branch("energy",&energy,"energy/I");
  outTree->Branch("xTable",&xTable,"xTable/F");
  outTree->Branch("yTable",&yTable,"yTable/F");

  //---additional branches
  outTree->Branch("HV",&HV,"HV/I");

  outTree->Branch("tdcX",&tdcX,"tdcX/F");
  outTree->Branch("tdcY",&tdcY,"tdcY/F");
  outTree->Branch("hodoX1",&hodoX1,"hodoX1/F");
  outTree->Branch("hodoY1",&hodoY1,"hodoY1/F");
  outTree->Branch("hodoX2",&hodoX2,"hodoX2/F");
  outTree->Branch("hodoY2",&hodoY2,"hodoY2/F");
  //    outTree->Branch("MCPName"+nameMCP->at(Ch_1),&baseline_Ch1,"baseline_"+nameMCP->at(Ch_1)+"/F");          
}

   
void InitRecoTree(TTree* nt)
{
  nt->SetBranchAddress("time_CF", &time_CF, &b_time_CF);
  nt->SetBranchAddress("amp_max", &amp_max, &b_amp_max);
  nt->SetBranchAddress("charge", &charge, &b_charge);
  nt->SetBranchAddress("baseline", &baseline, &b_baseline);
  nt->SetBranchAddress("run_id", &run_id, &b_run_id);
  nt->SetBranchAddress("HV", &HV, &b_HV);
  nt->SetBranchAddress("tdcX", &tdcX, &b_tdcX);
  nt->SetBranchAddress("tdcY", &tdcY, &b_tdcY);
  nt->SetBranchAddress("hodoX1", &hodoX1, &b_hodoX1);
  nt->SetBranchAddress("hodoY1", &hodoY1, &b_hodoY1);
  nt->SetBranchAddress("hodoX2", &hodoX2, &b_hodoX2);
  nt->SetBranchAddress("hodoY2", &hodoY2, &b_hodoY2);

  nt->SetBranchAddress("energy", &energy, &b_energy);
  nt->SetBranchAddress("xTable", &xTable, &b_xTable);
  nt->SetBranchAddress("yTable", &yTable, &b_yTable);

}
