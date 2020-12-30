{
  Int_t palette[2];
  palette[0] = 0;
  palette[1] = 2;
  gStyle->SetPalette(2,palette);
  gStyle -> SetOptStat(0);

  std::vector<std::string> criteria = {
    "digital_dead",
    "digital_bad", 
    "analog_dead",
    "analog_bad", 
    "tuning_failed",
    "tuning_bad_threshold",
    "tuning_bad_tot",
    "high_enc",
    "noisy"
  };
  
  int ncol = 400;
  int nrow = 192;
  
  auto *c1 = new TCanvas( "test" );
  auto *output_file = TFile::Open("after_analysis.root");
  for(int n=0;n<criteria.size();n++){
    auto *h = new TH2D("h_tmp", (criteria.at(n) + ";Col;Row").c_str(), ncol, 0.5, ncol+0.5, nrow, 0.5, nrow+0.5);
    h->GetZaxis()->SetRange(0., 1.);
    if(n==0){
      auto *h_read1 = (TH2D*)output_file -> Get(("h_" + criteria.at(n)).c_str());
      for (int i = 0; i < ncol; i++) {
        for (int j = 0; j < nrow; j++) {
          h -> Fill( i+1, j+1, 1 - (h_read1 -> GetBinContent( i+1, j+1 )) );
        }
      }
      h -> Draw("colz");
      c1->SaveAs( ( criteria.at(n) + ".png" ).c_str() );
      delete h, h_read1;
    }
    else{
      auto *h_read1 = (TH2D*)output_file -> Get(("h_" + criteria.at(n)).c_str());
      auto *h_read2 = (TH2D*)output_file -> Get(("h_" + criteria.at(n-1)).c_str());
      for (int i = 0; i < ncol; i++) {
        for (int j = 0; j < nrow; j++) {
          h -> Fill( i+1, j+1, (h_read2 -> GetBinContent( i+1, j+1 )) - (h_read1 -> GetBinContent( i+1, j+1 )) );
        }
      }
      h -> Draw("colz");
      c1->SaveAs( ( criteria.at(n) + ".png" ).c_str() );
      delete h, h_read1, h_read2;
    }
  }  

  auto *h_health = (TH1F*)output_file -> Get("h_healthy_pixel");
  auto *h_bad = new TH1F( "h_bad_pixel", "# of Bad Pixels;;Pixels", criteria.size(), 0, criteria.size() );
  for(int i=1; i <= criteria.size(); i++) h_bad->Fill( criteria.at(i-1).c_str(), (h_health -> GetBinContent(i))-(h_health -> GetBinContent(i+1)));
  //for(int i=1; i <= criteria.size(); i++) std::cout<<h_health -> GetBinContent(i-1)<<std::endl;
  h_bad -> Draw("hist TEXT0");
  h_bad->SetMinimum(0);
  h_bad->GetYaxis()->SetTitleOffset(1.5);
  h_bad -> SetMarkerSize(2);
  c1->SaveAs( "Bad_pixels.png" ); 
}
