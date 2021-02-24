{
  TCanvas *c = new TCanvas("test1");
  c->SetLogx();
  c->SetLogy();
  TH1 *frame = c->DrawFrame( 0.9, 0.2, 5000., 11 );
  frame->GetXaxis()->SetTitle("Datasize[KB]");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.7);
  
  const int n = 8;
  double x[n] = {1,3,10,30,100,300,1000,4000};
  double x_error[n] = {0,0,0,0,0,0,0,0};
  
  double y[n] = {
0.525464926027488,0.6221637188348157,0.6938755657036508,1.0607360395735197,1.7246991029855492,1.8602623738666775,3.2155732966561787,9.321162855357283
  };
  double y_error[n] = {
0.0502411709487583,0.07588908486917736,0.11688618163386263,0.10025350197844192,0.10771667234377472,0.06906351250343548,0.2002440897511907,0.4307452777358986
  };
  double y2[n] = {
0.40502891832124,0.3459121036506339,0.44941576199974015,0.5580690646804489,0.8531719045853859,1.1720983554701798,2.2031183201665416,8.440716689052843
  };
  double y2_error[n] = {
0.05426716284875596,0.026184570063864192,0.05427469673268716,0.053039843039312404,0.040707652675835,0.09065828156160263,0.07631525129925382,0.3960474916387049
  };

  double y3[n] = {
0.47832151417295976,0.5446369276782876,0.28155499246519194,0.46565382484710205,0.7116740045434653,1.0754063915641001,2.2556286405167754,9.0591170224624
  };
  double y3_error[n] = {
0.09231169908391954,0.1284272048620035,0.04770149382589296,0.062175154098103744,0.11375923921819946,0.12876361232172617,0.29927175487963437,0.9684102828331884
  };
  
  
  TGraphErrors *g = new TGraphErrors(n,x,y,x_error,y_error);
  TGraphErrors *g1 = new TGraphErrors(n,x,y2,x_error,y2_error);
  TGraphErrors *g2 = new TGraphErrors(n,x,y3,x_error,y3_error);
  g->SetMarkerStyle(23);
  g1->SetMarkerStyle(8);
  g2->SetMarkerStyle(26);
  //g->SetMarkerColor(kRed);
  g->SetLineColor(kRed);
  //g1->SetMarkerColor(kBlue);
  g1->SetLineColor(kBlue);
  //g2->SetMarkerColor(kGreen);
  g2->SetLineColor(kGreen);
  g->Draw("PL");
  g1->Draw("PL");
  g2->Draw("PL");
  
  TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,1.2);
  f1->SetLineColor(kRed);
  TF1 *f2 = new TF1("f2","[0]*x+[1]",0.0,1.2);
  f2->SetLineColor(kBlue);
  TF1 *f3 = new TF1("f3","[0]*x+[1]",0.0,4000);
  f3->SetLineColor(kGreen);
  
  TLegend *leg =new TLegend(0.1,0.7,0.35,0.9,"");
  leg->AddEntry(g,"KEK(Red)");
  leg->AddEntry(g1,"LBNL(Blue)");
  leg->AddEntry(g2,"CERN(Green)");
  leg->Draw("SAME");
  
  //g->Fit("f1");
  //g1->Fit("f2");
  //g2->Fit("f3");
  gStyle->SetOptFit(0);
}
