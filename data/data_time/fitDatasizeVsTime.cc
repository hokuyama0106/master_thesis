{
  TCanvas *c = new TCanvas("test1");
  TH1 *frame = c->DrawFrame( 0.0, 0.0, 1.2, 5.0 );
  frame->GetXaxis()->SetTitle("Data size[MB]");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.7);
  
  const int n = 6;
  double x[n] = {0.0000001,0.2,0.4,0.6,0.8,1.0};
  double x_error[n] = {0,0,0,0,0,0};
  
  double y[n] = {
    0.5411863724390665,1.7765121380488078, 2.579552968343099, 3.0997323036193847, 3.6207748889923095, 3.8895620028177897
  };
  double y_error[n] = {
    0.037339000935228045,0.08241972721484155, 0.08504334363476099, 0.11130350336760832, 0.058171012320221434, 0.061866753371777244
  };
  double y2[n] = {
    0.34385626316070556,0.8190374215443929, 1.0788128534952799, 1.462095022201538, 1.9299415508906046, 2.4158699830373127
  };
  double y2_error[n] = {
    0.025390908538464502,0.050751851864951604, 0.06424400821783274, 0.1078576876322301, 0.1383877282540458, 0.1825025427938974
  };
  double y3[n] = {
    0.391983421643575,0.5558398564656576, 0.6174984216690064, 0.9511854966481527, 0.971021318435669, 1.1980659325917562
  };
  double y3_error[n] = {
    0.02466642021667535,0.036813101606730445, 0.027170629553695622, 0.0747159445309714, 0.02944249197616593, 0.048472261894491595
  };
  
  
  TGraphErrors *g = new TGraphErrors(n,x,y,x_error,y_error);
  TGraphErrors *g1 = new TGraphErrors(n,x,y2,x_error,y2_error);
  TGraphErrors *g2 = new TGraphErrors(n,x,y3,x_error,y3_error);
  //TGraph *g = new TGraph(6,x,y);
  g->SetMarkerStyle(23);
  g1->SetMarkerStyle(8);
  g2->SetMarkerStyle(26);
  //g->SetMarkerSize(20);
  //g1->SetMarkerSize(4);
  g->Draw("P");
  g1->Draw("P");
  g2->Draw("P");
  
  TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,1.2);
  f1->SetLineColor(kRed);
  TF1 *f2 = new TF1("f2","[0]*x+[1]",0.0,1.2);
  f2->SetLineColor(kBlue);
  TF1 *f3 = new TF1("f3","[0]*x+[1]",0.0,1.2);
  f3->SetLineColor(kGreen);
  
  TLegend *leg =new TLegend(0.7,0.75,0.9,0.9,"");
  leg->AddEntry(g,"KEK");
  leg->AddEntry(g1,"LBL");
  leg->AddEntry(g2,"CERN");
  leg->Draw("SAME");
  
  //g->Fit("f1");
  g1->Fit("f2");
  g2->Fit("f3");
  gStyle->SetOptFit(0);
}
