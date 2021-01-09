{
  TCanvas *c = new TCanvas("test1");
  TH1 *frame = c->DrawFrame( 0.0, 0.0, 21000.0, 650.0 );
  frame->GetXaxis()->SetTitle("# of documents");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.7);
  
  const int n = 4;
  double x[n] = {5000,10000,15000,20000};
  double x_error[n] = {0,0,0,0};
  
  double y2[n] = {
    57.97141605654441, 171.140774887708, 353.5002939472176, 598.1811009268763
  };
  double y2_error[n] = {
    0.37116878824592464, 2.1457675651321435, 2.881353845530611, 3.233788875378024
  };
 
  
  TGraphErrors *g1 = new TGraphErrors(n,x,y2,x_error,y2_error);
  //TGraph *g = new TGraph(6,x,y);
  g1->SetMarkerStyle(8);
  //g->SetMarkerSize(20);
  //g1->SetMarkerSize(4);
 
  TF1 *f2 = new TF1("f2","[0]*x*x+[1]",0.0,1.2);
  f2->SetLineColor(kBlue);
  
  TLegend *leg =new TLegend(0.1,0.65,0.4,0.9,"");
  leg->AddEntry(g1,"Python list(blue)");
  //leg->AddEntry(g2,"Search words hash(green)");
  //leg->Draw("SAME");

  g1->Draw("P");
  g1->Fit("f2");
  gStyle->SetOptFit(0);
}
