{
  TCanvas *c = new TCanvas("test1");
  TH1 *frame = c->DrawFrame( 4000.0, 0.1, 21000.0, 0.70 );
  frame->GetXaxis()->SetTitle("# of documents[MB]");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.7);
  
  const int n = 4;
  double x[n] = {5000,10000,15000,20000};
  double x_error[n] = {0,0,0,0};
  
  double y[n] = {
    0.2291034, 0.371536, 0.5140538, 0.67714115
  };
  double y_error[n] = {
    0.007152353131716557, 0.009060323583038463, 0.006473959304638573, 0.008924903912756658
  };
  double y2[n] = {
    0.1547217, 0.2939585, 0.46603835, 0.60020675
  };
  double y2_error[n] = {
    0.00795622458842038, 0.004590743911918845, 0.009610073307555611, 0.00768020669803328
  };
  double y3[n] = {
    0.16598695, 0.281872, 0.4138172, 0.5548567
  };
  double y3_error[n] = {
    0.008354077725595498, 0.005052602995533185, 0.007311662802647028, 0.006499479039894485
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
 
  TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,20000);
  f1->SetLineColor(kRed);
  TF1 *f2 = new TF1("f2","[0]*x+[1]",0.0,20000);
  f2->SetLineColor(kBlue);
  TF1 *f3 = new TF1("f3","[0]*x+[1]",0.0,20000);
  f3->SetLineColor(kGreen);
  
  TLegend *leg =new TLegend(0.1,0.65,0.4,0.9,"");
  leg->AddEntry(g,"Search words(red)");
  leg->AddEntry(g1,"Summary hash(blue)");
  leg->AddEntry(g2,"Multi thread(green)");
  leg->Draw("SAME");

  g->Draw("P");
  g->Fit("f1");
  g1->Draw("P");
  g1->Fit("f2");
  g2->Draw("P"); 
  g2->Fit("f3");
  gStyle->SetOptFit(0);
}
