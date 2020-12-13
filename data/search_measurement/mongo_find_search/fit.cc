{
TCanvas *c = new TCanvas("test1");
TH1 *frame = c->DrawFrame( 0.0, 0.0, 110000.0, 0.07 );
frame->GetXaxis()->SetTitle("# of document");
frame->GetXaxis()->SetTitleSize(0.05);
frame->GetXaxis()->SetTitleOffset(0.9);
frame->GetYaxis()->SetTitle("Time[sec]");
frame->GetYaxis()->SetTitleSize(0.05);
frame->GetYaxis()->SetTitleOffset(0.9);

const int n = 10;
double x[n] = {10000,20000,30000,40000,50000,60000,70000,80000,90000,100000};
double y[n] = 
{
0.006987166404724121, 0.011696314811706543, 0.016917729377746583, 0.021704697608947755, 0.026652729511260985, 0.03134013414382934, 0.03586820363998413, 0.04113174676895141, 0.045749115943908694, 0.050351929664611814
};

double xerror[n] = {0,0,0,0,0,0,0,0,0,0};
double yerror[n] = 
{
8.926809062100603e-05, 5.074214207949351e-05, 0.00018705299591682885, 8.185441397275296e-05, 0.000122632820414109, 7.802945229091034e-05, 6.417253303071577e-05, 0.00042356816917243705, 0.00017810630274181096, 8.880934092166489e-05
};

TGraphErrors *g = new TGraphErrors(n,x,y, xerror, yerror);
g->SetMarkerStyle(22);
//g->SetMarkerSize(20);
g->Draw("P");

TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,100000.0);
f1->SetLineColor(kRed);
g->Fit("f1");
gStyle->SetOptFit(0);
}
