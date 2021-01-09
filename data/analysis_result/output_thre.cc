{
  Int_t palette[2];
  palette[0] = 0;
  palette[1] = 2;
  gStyle->SetPalette(2,palette);
  gStyle -> SetOptStat(0);

  auto *c1 = new TCanvas( "test" );
  auto *treefile = TFile::Open( "Tree.root", "READ" );
  auto *t = dynamic_cast<TTree*>( treefile->Get( "QCscan_20UPGFC9999999" ) );

  std::string branch = "MODULEWIREBONDING_std_thresholdscan_1_ThresholdMap_0";
  Int_t col;
  Float_t val;
  t -> SetBranchAddress( branch.c_str(), &val );
  t -> SetBranchAddress( "col", &col );

  Float_t max = t -> GetMaximum( branch.c_str() );

  std::unique_ptr<TH1F> hist( new TH1F( "", ";Threshold[e];# of pixels", max, 1 ,max+1 ) );
  std::unique_ptr<TF1> f( new TF1( "fit_func", "gaus", 1, max+1 ) );
  Int_t nevents = t -> GetEntries();

  for ( Int_t ii = 0; ii < nevents; ii++ ){
    t -> GetEntry(ii); 
    if(col>267) hist -> Fill( val );
  }

  hist->Rebin(8);
  hist -> Fit("fit_func","0Q","");
  Float_t mean = f -> GetParameter(1);
  Float_t sigma = f -> GetParameter(2);
  hist -> Fit( "fit_func", "0Q", "", mean - sigma, mean + sigma );
  hist->GetXaxis()->SetRangeUser(1000,2000);
  hist -> Draw("hist");
  f->Draw("SAME");
  c1->SaveAs( "Threshold_mean_dist.png" ); 
}
