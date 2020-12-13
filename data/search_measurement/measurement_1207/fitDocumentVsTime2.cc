{
  TCanvas *c = new TCanvas("test1");
  TH1 *frame = c->DrawFrame( 0.0, 0.0, 21000.0, 600.0 );
  frame->GetXaxis()->SetTitle("# of documents[MB]");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.7);
  
  const int n = 4;
  double x[n] = {5000,10000,15000,20000};
  double x_error[n] = {0,0,0,0};
  
  double y2[n] = {
    43.8940601, 143.74964135, 303.0591842, 513.687512
  };
  double y2_error[n] = {
    0.17928264406683384, 0.30193476854358736, 0.29483395721445443, 0.2533670957566504
  };
  double y3[n] = {
    0.22534425, 0.37306665, 0.51679375, 0.6696931
  };
  double y3_error[n] = {
    0.005541891290853682, 0.007501845015637333, 0.00608717726607001, 0.007497518380166986
  };
  
  
  TGraphErrors *g1 = new TGraphErrors(n,x,y2,x_error,y2_error);
  TGraphErrors *g2 = new TGraphErrors(n,x,y3,x_error,y3_error);
  //TGraph *g = new TGraph(6,x,y);
  g1->SetMarkerStyle(8);
  g2->SetMarkerStyle(26);
  //g->SetMarkerSize(20);
  //g1->SetMarkerSize(4);
 
  TF1 *f2 = new TF1("f2","[0]*x*x+[1]",0.0,1.2);
  f2->SetLineColor(kBlue);
  TF1 *f3 = new TF1("f3","[0]*x+[1]",0.0,1.2);
  f3->SetLineColor(kRed);
  
  TLegend *leg =new TLegend(0.1,0.65,0.4,0.9,"");
  leg->AddEntry(g1,"Python list(blue)");
  leg->AddEntry(g2,"Search words hash(green)");
  leg->Draw("SAME");

  g1->Draw("P");
  g1->Fit("f2");
  g2->Draw("P"); 
  g2->Fit("f3");
  gStyle->SetOptFit(0);
}
