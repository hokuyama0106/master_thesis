{
  TCanvas *c = new TCanvas("test1");
  TH1 *frame = c->DrawFrame( 0.0, 0.0, 21000.0, 600.0 );
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
    48.26447270788271, 155.7234235290253, 320.2777944339164, 541.0049189675715 
  };
  double y2_error[n] = {
    0.11943498621120978, 0.3795670529566454, 4.956947013672909, 8.798930896975698 
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
