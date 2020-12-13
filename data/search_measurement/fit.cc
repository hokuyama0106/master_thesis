{
TCanvas *c = new TCanvas("test1");
TH1 *frame = c->DrawFrame( 0.0, 0.0, 6.0, 0.7 );
frame->GetXaxis()->SetTitle("# of keywords");
frame->GetXaxis()->SetTitleSize(0.05);
frame->GetXaxis()->SetTitleOffset(0.9);
frame->GetYaxis()->SetTitle("Time[sec]");
frame->GetYaxis()->SetTitleSize(0.05);
frame->GetYaxis()->SetTitleOffset(0.9);

const int n = 5;
double x[n] = {1,2,3,4,5};
double x_error[n] = {0,0,0,0,0};
double y[n] = 
{0.41766543434343434, 0.4095558787878788, 0.41802704040404043, 0.5052925858585858, 0.5058073838383839};
double y_error[n] =
{0.006716345156386554, 0.003686109040216617, 0.003266389579845273, 0.0125996618901603, 0.010208219197960451};

TGraphErrors *g = new TGraphErrors(n,x,y,x_error,y_error);
//TGraph *g = new TGraph(6,x,y);
//g->SetMarkerStyle(22);
g->SetMarkerSize(20);
g->Draw("P");

TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,10000.0);
f1->SetLineColor(kRed);
g->Fit("f1");
gStyle->SetOptFit(1);
}
