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
3.879,3.623,3.981,3.852,4.152,4.241,4.574,5.809,6.265,10.342,20.989
  };
  double y_error[n] = {
0.11857643260939492,0.07085108709970425,0.1252597301609739,0.10165057553291484,0.06892113940432304,0.09287519835314376,0.04037478739002996,0.8649662092878985,0.26881656511274066,0.8696910193487126,1.3191518505988127
  };
  double y2[n] = {
4.287,3.624,3.475,3.397,3.681,3.684,4.156,4.547,5.9190000000000005,8.01,16.97
  };
  double y2_error[n] = {
0.26463135318102377,0.21767684735989543,0.13545761489151786,0.12394791817434081,0.14773558294850903,0.01906454274624643,0.12867990720589803,0.18333030300525877,0.22973119020517524,0.13017556995206775,0.3779346079697314
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
  //g2->Draw("P");
 
  TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,1.2);
  f1->SetLineColor(kRed);
  TF1 *f2 = new TF1("f2","[0]*x+[1]",0.0,1.2);
  f2->SetLineColor(kBlue);
 
  TLegend *leg =new TLegend(0.1,0.75,0.3,0.9,"");
  leg->AddEntry(g,"KEK to CERN");
  leg->AddEntry(g1,"LBNL to CERN");
  //leg->AddEntry(g2,"TITECH to LBL");
  leg->Draw("SAME");
  
  //g->Fit("f1");
  //g1->Fit("f2");
  //g2->Fit("f3");
  gStyle->SetOptFit(0);
}
