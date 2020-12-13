{
  TCanvas *c = new TCanvas("test1");
  c->SetLogx();
  c->SetLogy();
  TH1 *frame = c->DrawFrame( 0.5, 1.5, 110000, 22.0 );
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
2.113,2.088,2.073,2.325,2.4210000000000003,2.541,2.81,2.948,3.525,5.421,10.763,
  };
  double y_error[n] = {
0.022610496852153324,0.0068132043185581605,0.006858355272004864,0.14008154591584446,0.005317104939557941,0.008951170693832382,0.021023208809360563,0.013407202781331881,0.032174293856822786,0.15051721529036283,0.04139690451837785,
  };
  double y2[n] = {
2.047,2.117,2.054,2.101,2.264,2.355,2.596,2.727,3.189,4.4,9.483,
  };
  double y2_error[n] = {
0.10116665141253167,0.17629975875840448,0.1004582094796232,0.03951714739542325,0.013165611772087625,0.0061363116762151665,0.015962919996504878,0.013882220621453736,0.020272830446708433,0.04914076530554663,0.19207155302511997,
  };

  double y3[n] = {
4.686,4.667,4.808,4.786,5.037,5.127,5.457,5.539,5.44,5.657,10.399
  };
  double y3_error[n] = {
0.8784866336103804,0.8808750559514844,0.9374838928657474,0.881950979853301,0.8805274092942925,0.8773952049555619,0.8628062884321281,0.7564332320620909,0.21088877180654755,0.2343578038959095,0.043303408470756484
  };
 
 
  TGraphErrors *g = new TGraphErrors(n,x,y,x_error,y_error);
  TGraphErrors *g1 = new TGraphErrors(n,x,y2,x_error,y2_error);
  TGraphErrors *g2 = new TGraphErrors(n,x,y3,x_error,y3_error);
  g->SetMarkerStyle(23);
  g1->SetMarkerStyle(8);
  g2->SetMarkerStyle(26);
  g->Draw("P");
  g1->Draw("P");
  g2->Draw("P");
 
  TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,1.2);
  f1->SetLineColor(kRed);
  TF1 *f2 = new TF1("f2","[0]*x+[1]",0.0,1.2);
  f2->SetLineColor(kBlue);
 
  TLegend *leg =new TLegend(0.1,0.75,0.3,0.9,"");
  leg->AddEntry(g,"KEK to LBL");
  leg->AddEntry(g1,"LBL to KEK");
  leg->AddEntry(g2,"TITECH to LBL");
  leg->Draw("SAME");
  
  //g->Fit("f1");
  //g1->Fit("f2");
  //g2->Fit("f3");
  gStyle->SetOptFit(0);
}
