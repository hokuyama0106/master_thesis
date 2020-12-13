{
TCanvas *c = new TCanvas("test1");
TH1 *frame = c->DrawFrame( 0.0, 0.22, 5.0, 0.28 );
frame->GetXaxis()->SetTitle("# of thread");
frame->GetXaxis()->SetTitleSize(0.05);
frame->GetXaxis()->SetTitleOffset(0.9);
frame->GetYaxis()->SetTitle("Time[sec]");
frame->GetYaxis()->SetTitleSize(0.05);
frame->GetYaxis()->SetTitleOffset(0.9);

const int n = 4;
double x[n] = {1,2,3,4};
double x_error[n] = {0,0,0,0};
double y[n] = 
{0.26218914, 0.2376328, 0.23949652, 0.23901156 };
double y_error[n] =
{0.0034962451917706647, 0.0020186032820959958, 0.002082494928426416, 0.0020368806266794597 };
double y2[n] = 
{0.2537072, 0.25199384, 0.25239532, 0.25231152 };
double y2_error[n] =
{0.002522028881640452, 0.002401595443398338, 0.0024430289453649602, 0.002212634438064851 };

TGraphErrors *g1 = new TGraphErrors(n,x,y,x_error,y_error);
g1->SetMarkerSize(2);
g1->SetMarkerStyle(8);
g1->Draw("P");

TGraphErrors *g2 = new TGraphErrors(n,x,y2,x_error,y2_error);
g2->SetMarkerSize(2);
g2->SetMarkerStyle(26);
g2->Draw("P");



}
