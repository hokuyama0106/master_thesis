{
  TCanvas *c = new TCanvas("test1");
  TH1 *frame = c->DrawFrame( 0.0, 0.0, 21000.0, 0.70 );
  frame->GetXaxis()->SetTitle("# of documents");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.7);
  
  const int n = 4;
  double x[n] = {5000,10000,15000,20000};
  double x_error[n] = {0,0,0,0};
  
  double y[n] = {
    0.23851616785125948, 0.3841055806515586, 0.5344418023500084, 0.6854130497876433
  };
  double y_error[n] = {
    0.005883732145758878, 0.008887898793898468, 0.005456984248339307, 0.007331255610758036 
  };
  double y2[n] = {
    0.15698097392364607, 0.2971611762823001, 0.44521617548804643, 0.6040072174932136 
  };
  double y2_error[n] = {
    0.008890934327273177, 0.00512256300373098, 0.0070901696171964, 0.01572501571784992 
  };
  double y3[n] = {
    0.1617080186230537, 0.29679870898234895, 0.42498094441787954, 0.575729643872155 
  };
  double y3_error[n] = {
    0.009111406511328534, 0.0055100111756552685, 0.007890283994327023, 0.008021231737640274 
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
  leg->AddEntry(g,"Method 2(red)");
  leg->AddEntry(g1,"Method 3(blue)");
  leg->AddEntry(g2,"Method 4(green)");
  leg->Draw("SAME");

  g->Draw("P");
  g->Fit("f1");
  g1->Draw("P");
  g1->Fit("f2");
  g2->Draw("P"); 
  g2->Fit("f3");
  gStyle->SetOptFit(0);
}
