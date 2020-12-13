{
  TCanvas *c = new TCanvas("test1");
  c->SetLogx();
  c->SetLogy();
  TH1 *frame = c->DrawFrame( 0.5, 2.0, 110000, 12.0 );
  frame->GetXaxis()->SetTitle("Data size[KB]");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.7);
  
  const int n = 11;
  double x[n] = {1,3,10,30,100,300,1000,3000,10000,30000,100000};
  double x_error[n] = {0,0,0,0,0,0,0,0,0,0,0};
  
  double y[n] = {
2.45,2.1,2.091,2.255,2.44,2.552,2.902,2.965,3.481,5.06,10.467
  };
  double y_error[n] = {
0.25264526441164425,0.006085806194501833,0.008670939117834078,0.04349684251347419,0.023674750836291693,0.023820315014865107,0.11482461129054475,0.04065057362205937,0.008951170693832344,0.025482988758177137,0.020126145393369765
  };
 
  TGraphErrors *g = new TGraphErrors(n,x,y,x_error,y_error);
  g->SetMarkerStyle(23);
  g->Draw("P");
 
  TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,1.2);
  f1->SetLineColor(kRed);
 
  TLegend *leg =new TLegend(0.1,0.75,0.3,0.9,"");
  leg->AddEntry(g,"KEK to LBL(Red)");
  //leg->AddEntry(g2,"CERN");
  leg->Draw("SAME");
  
  g->Fit("f1");
  //g1->Fit("f2");
  //g2->Fit("f3");
  gStyle->SetOptFit(0);
}
