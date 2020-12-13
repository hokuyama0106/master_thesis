{
TCanvas *c = new TCanvas("test1");
TH1 *frame = c->DrawFrame( 1.0, 0.0, 12000000.0, 15.0 );
frame->GetXaxis()->SetTitle("Data size[Byte]");
frame->GetXaxis()->SetTitleSize(0.05);
frame->GetXaxis()->SetTitleOffset(0.9);
frame->GetYaxis()->SetTitle("Time[sec]");
frame->GetYaxis()->SetTitleSize(0.05);
frame->GetYaxis()->SetTitleOffset(0.7);

double x[8] = {1,10,100,1000,10000,100000,1000000,10000000};
double x_error[8] = {0,0,0,0,0,0,0,0};
double y[8] = {1.2452330509821574, 1.1509685834248862, 1.8860018014907838, 1.3124862432479858, 1.2087007204691569, 2.147912057240804, 5.100979789098104, 10.911919728914897};
double y_error[8] = {0.07617480285977768, 0.04457986438949918, 0.06639640653326634, 0.08909798359311359, 0.043540928899745146, 0.0495654709943475, 0.0570758351065052, 0.15422609257743272};


TGraphErrors *g = new TGraphErrors(8,x,y,x_error,y_error);
//TGraph *g = new TGraph(6,x,y);
//g->SetMarkerStyle(22);
g->SetMarkerSize(20);
g->Draw("P");

TF1 *f1 = new TF1("f1","[0]*x+[1]",1.0,12000000.0);
f1->SetLineColor(kRed);
g->Fit("f1");
gStyle->SetOptFit(0);
}
