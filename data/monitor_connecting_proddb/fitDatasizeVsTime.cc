{
  TCanvas *c = new TCanvas("test1");
  TH1 *frame = c->DrawFrame( 1610276401., 0., 1610953201., 2. );
	frame->GetXaxis()->SetTimeDisplay(1);
	frame->GetXaxis()->SetTimeFormat("%m/%d %H:%M");
	frame->GetXaxis()->SetTimeOffset(0, "jst");
  frame->GetXaxis()->SetTitle("Date");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(0.9);
  frame->GetYaxis()->SetTitle("Time[sec]");
  frame->GetYaxis()->SetTitleSize(0.05);
  frame->GetYaxis()->SetTitleOffset(0.7);
	frame->GetYaxis()->SetRangeUser(0.,2.);
  gStyle->SetTimeOffset(-788918400);
  gStyle->SetNdivisions(505);
  gStyle->SetOptFit(0);
  
 	TGraphErrors* g1=new TGraphErrors("mes_kek.txt", "%lg %lg %lg", ""); //chuck
 	TGraphErrors* g2=new TGraphErrors("mes_lbl.txt", "%lg %lg %lg", ""); //chuck
	//g1->GetXaxis()->SetTimeDisplay(1);
	//g1->GetXaxis()->SetTimeFormat("%m/%d %H:%M");
	//g1->GetXaxis()->SetTimeOffset(0, "jst");
	//g1->GetYaxis()->SetRangeUser(0.,2.);
	g1->SetMarkerStyle(23);
	g1->SetLineColor(kRed);
	g1->SetMarkerSize(0.5);

	//g2->GetXaxis()->SetTimeDisplay(1);
	//g2->GetXaxis()->SetTimeFormat("%m/%d %H:%M");
	//g2->GetXaxis()->SetTimeOffset(0, "jst");
	//g2->GetYaxis()->SetRangeUser(0.,2.);
	g2->SetMarkerStyle(8);
	g2->SetLineColor(kBlue);
	g2->SetMarkerSize(0.5);

	g1->Draw("PL");
	g2->Draw("PL");

  TLegend *leg =new TLegend(0.1,0.1,0.35,0.3,"");
  leg->AddEntry(g1,"KEK(Red)");
  leg->AddEntry(g2,"LBNL(Blue)");
  leg->Draw("SAME");

}
