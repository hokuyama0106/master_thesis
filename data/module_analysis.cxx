{
 auto h = new TH1I("h_module_analysis","Module Production Analysis;;# of modules", 7, 0, 7);
 h -> Fill( "Bare to PCB assembly", 100 );
 h -> Fill( "Wirebonding", 350 );
 h -> Fill( "Wirebond protection", 160 );
 h -> Fill( "Palylene Coating", 450 );
 h -> Fill( "Thremal Cycling", 270 );
 h -> Fill( "Burn-In", 500 );
 h -> Fill( "Reception", 1000 );
 h -> Draw("hist TEXT0");
 h -> SetMarkerSize(2);
 gStyle -> SetOptStat(0);
}
