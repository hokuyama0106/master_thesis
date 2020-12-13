{
TCanvas *c = new TCanvas("test1");
TH1 *frame = c->DrawFrame( 0.0, 0.0, 12.0, 15.0 );
frame->GetXaxis()->SetTitle("Data size[MB]");
frame->GetXaxis()->SetTitleSize(0.05);
frame->GetXaxis()->SetTitleOffset(0.9);
frame->GetYaxis()->SetTitle("Time[sec]");
frame->GetYaxis()->SetTitleSize(0.05);
frame->GetYaxis()->SetTitleOffset(0.7);

double x[7] = {0.1,0.2,0.4,0.8,1.6,3.2,10};
double x_error[7] = {0,0,0,0,0,0,0};
double y[7] = {2.0915597438812257, 2.8414546569188435, 3.2773370265960695, 3.899307044347127, 4.262156081199646, 6.956383117039999, 10.911919728914897};
double y_error[7] = {0.048976111468219174, 0.0485761778005903, 0.03434264046259993, 0.0479727448144316, 0.07005030334128969, 0.09684278348486502, 0.15422609257743272};

TGraphErrors *g = new TGraphErrors(7,x,y,x_error,y_error);
//TGraph *g = new TGraph(6,x,y);
g->SetMarkerStyle(23);
//g->SetMarkerSize(20);
g->Draw("P");

//TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,12);
//f1->SetLineColor(kRed);
//g->Fit("f1");
//gStyle->SetOptFit(1);
}
