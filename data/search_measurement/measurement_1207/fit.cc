#include <iostream>
#include <vector>
#include <TCanvas.h>
#include <TF1.h>
#include <TH1.h>

int main()
{
  TCanvas *c = new TCanvas("test1");
  TH1 *frame = c->DrawFrame( 0.0, 0.0, 22000.0, 1.0 );
  frame->GetXaxis()->SetTitle("# of keywords");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.9);
  
  const int n=4;
  std::vector<double> mean_list;
  std::vector<double> error_list;
  double a,b;
  ifstream ifs("result.txt");
  double x[n] = {5000,10000,15000,20000};
  double x_error[n] = {0,0,0,0}; 
  double y[n];
  double y_error[n];
  TH1 *f[n];
  TGraphErrors *g[n];

  while(ifs>>a>>b){
    mean_list.push_back(a);   
    error_list.push_back(b);

    if(mean_list.size()==n){
      for(int i;i<n;i++){
        y[i] = mean_list.at(i); 
        y_error[i] = error_list.at(i);
        std::cout<<y[i]<<std::endl;
      }
      
      TGraphErrors *g1 = new TGraphErrors(n,x,y,x_error,y_error); 
      g1->SetMarkerSize(20);
      g1->Draw("P");
      TF1 *f1 = new TF1("f1","[0]*x+[1]",0.0,20000.0);
      f1->SetLineColor(kRed);
      g1->Fit("f1");
      gStyle->SetOptFit(1); 

      mean_list.clear();
      error_list.clear();
    }
  }

}
