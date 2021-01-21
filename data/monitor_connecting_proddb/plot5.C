void plot5(){
	TGraph* g1=new TGraph("1603733964_4.log", "%lg %lg", ""); //chuck
        gStyle->SetTimeOffset(-788918400);
        gStyle->SetNdivisions(505);
	g1->GetXaxis()->SetTimeDisplay(1);
	g1->GetXaxis()->SetTimeFormat("%H:%M");
	g1->GetXaxis()->SetTimeOffset(0, "jst");
	g1->GetYaxis()->SetRangeUser(-30.,30.);
	g1->SetMarkerStyle(21);
	g1->SetMarkerColor(2);
	g1->SetMarkerSize(0.5);

	TCanvas* c=new TCanvas("c", "", 1000, 1000);
	c->cd();

	//TH1* frame=gPad->DrawFrame(0, 0, 500, 500);
	//g1->Draw();
	g1->Draw("AP");

        //TGraph* g2=new TGraph("201028_22.log", "%lg %*lg %lg", ""); //chuck
        //gStyle->SetTimeOffset(-788918400);
        ////gStyle->SetTimeOffset(0);
        //gStyle->SetNdivisions(505);
        //g2->GetXaxis()->SetTimeDisplay(1);
        //g2->GetXaxis()->SetTimeFormat("%H:%M");
        //g2->GetXaxis()->SetTimeOffset(0, "jst");
        //g2->SetMarkerStyle(21);
	//g2->SetMarkerColor(2);
        //g2->SetMarkerSize(0.5);

        ////TH2* frame=gPad->DrawFrame(0, 0, 500, 500);
        ////g2->Draw();
        //g2->Draw("P");

	//TGraph* g3=new TGraph("20200908_mon2.txt", "%lg %*lg %*lg %lg", ""); //HS
        //gStyle->SetTimeOffset(-788918400);
        ////gStyle->SetTimeOffset(0);
        //gStyle->SetNdivisions(505);
        //g3->GetXaxis()->SetTimeDisplay(1);
        //g3->GetXaxis()->SetTimeFormat("%H:%M");
        //g3->GetXaxis()->SetTimeOffset(0, "jst");
        //g3->SetMarkerStyle(21);
        //g3->SetMarkerColor(1);
        //g3->SetMarkerSize(0.5);

        ////TH2* frame=gPad->DrawFrame(0, 0, 500, 500);
        ////g2->Draw();
        //g3->Draw("P");


}
