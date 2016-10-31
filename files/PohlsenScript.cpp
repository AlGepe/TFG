void PohlsenScript()
{
    TFile *file = TFile::Open("Pohlsen_233K.root");
    TH1D *histos[3];
    file->GetObject("ConvHisto_260V", histos[0]);
    histos[0]->SetTitle("260V");
    file->GetObject("ConvHisto_360V", histos[1]);
    histos[1]->SetTitle("360V");
    file->GetObject("ConvHisto_460V", histos[2]);
    for(int i = 0; i < 3; i++)
    {
        histos[i]->Scale(-1);
        histos[i]->SetLineWidth(2);
        histos[i]->SetBins(histos[i]->GetNbinsX(), 57., 87.);
    }
        
    TCanvas *c1 = new TCanvas("c1", "TCT Current Signal", (4./3.)*600, 600);
    histos[2]->GetYaxis()->SetTitle("Current [A]");
    histos[2]->GetXaxis()->SetTitle("Time [ns]");
    histos[2]->SetTitle("TCT Current Signal");
    histos[2]->SetAxisRange(72.5, 77.9);
    histos[1]->SetLineColor(kRed);
    histos[0]->SetLineColor(kGreen);
    histos[2]->Draw();
    histos[1]->Draw("same");
    histos[0]->Draw("same");
    histos[2]->SetTitle("460V");
    gPad->SetGrid();
    c1->BuildLegend();
} 
