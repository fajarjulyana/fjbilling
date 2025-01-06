#include <wx/wx.h>
#include <wx/timer.h>

// Deklarasi kelas utama
class BillingFrame : public wxFrame {
public:
    BillingFrame(const wxString& title);

private:
    wxTimer* timer;
    wxTextCtrl* timeDisplay;
    wxTextCtrl* rateInput;  // Input tarif per detik
    wxButton* startButton;
    wxButton* stopButton;
    wxStaticText* costLabel;

    int elapsedSeconds;    // Waktu berjalan dalam detik
    double ratePerSecond;  // Tarif per detik

    // Konstanta ID untuk event
    enum {
        ID_START = 1,
        ID_STOP,
        ID_TIMER
    };

    // Event handler
    void OnStart(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnClose(wxCloseEvent& event); // Handler untuk menutup aplikasi

    wxDECLARE_EVENT_TABLE();
};

// Event table untuk menghubungkan event handler dengan kontrol
wxBEGIN_EVENT_TABLE(BillingFrame, wxFrame)
    EVT_BUTTON(ID_START, BillingFrame::OnStart)
    EVT_BUTTON(ID_STOP, BillingFrame::OnStop)
    EVT_TIMER(ID_TIMER, BillingFrame::OnTimer)
    EVT_CLOSE(BillingFrame::OnClose) // Tambahkan handler untuk EVT_CLOSE
wxEND_EVENT_TABLE()

// Implementasi konstruktor
BillingFrame::BillingFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 300)),
      elapsedSeconds(0),
      ratePerSecond(0.8333) // Tarif default per detik
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Layout kontrol
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    timeDisplay = new wxTextCtrl(panel, wxID_ANY, "00:00:00", wxDefaultPosition, wxSize(200, 30), wxTE_READONLY | wxTE_CENTRE);
    rateInput = new wxTextCtrl(panel, wxID_ANY, wxString::Format("%.2f", ratePerSecond), wxDefaultPosition, wxSize(200, 30));
    startButton = new wxButton(panel, ID_START, "Mulai");
    stopButton = new wxButton(panel, ID_STOP, "Berhenti");
    costLabel = new wxStaticText(panel, wxID_ANY, "Biaya: 0 IDR");

    timer = new wxTimer(this, ID_TIMER);

    // Tambahkan kontrol ke layout
    vbox->Add(new wxStaticText(panel, wxID_ANY, "Waktu Berjalan:"), 0, wxALIGN_CENTER | wxTOP, 10);
    vbox->Add(timeDisplay, 0, wxALIGN_CENTER | wxBOTTOM, 10);
    vbox->Add(new wxStaticText(panel, wxID_ANY, "Tarif Per Detik (IDR):"), 0, wxALIGN_CENTER | wxTOP, 10);
    vbox->Add(rateInput, 0, wxALIGN_CENTER | wxBOTTOM, 10);
    vbox->Add(startButton, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 5);
    vbox->Add(stopButton, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 5);
    vbox->Add(costLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    panel->SetSizer(vbox);
}

// Event handler untuk tombol "Mulai"
void BillingFrame::OnStart(wxCommandEvent& event) {
    // Ambil tarif per detik dari input
    wxString rateString = rateInput->GetValue();
    double newRate;
    if (rateString.ToDouble(&newRate) && newRate > 0) {
        ratePerSecond = newRate;
    } else {
        wxMessageBox("Masukkan tarif yang valid (angka positif)!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    elapsedSeconds = 0;
    costLabel->SetLabel("Biaya: 0 IDR"); // Reset biaya
    timer->Start(1000); // Mulai timer, interval 1 detik
}

// Event handler untuk tombol "Berhenti"
void BillingFrame::OnStop(wxCommandEvent& event) {
    timer->Stop(); // Hentikan timer

    // Kalkulasi biaya otomatis
    double cost = elapsedSeconds * ratePerSecond; // Biaya = detik * tarif per detik
    costLabel->SetLabel(wxString::Format("Biaya: %.2f IDR", cost));
}

// Event handler untuk timer
void BillingFrame::OnTimer(wxTimerEvent& event) {
    elapsedSeconds++; // Tambah waktu
    int hours = elapsedSeconds / 3600;
    int minutes = (elapsedSeconds % 3600) / 60;
    int seconds = elapsedSeconds % 60;
    timeDisplay->SetValue(wxString::Format("%02d:%02d:%02d", hours, minutes, seconds));
}

// Event handler untuk menutup aplikasi
void BillingFrame::OnClose(wxCloseEvent& event) {
    if (wxMessageBox("Apakah Anda yakin ingin menutup aplikasi?", "Konfirmasi", wxYES_NO | wxICON_QUESTION) == wxYES) {
        event.Skip(); // Lanjutkan proses menutup aplikasi
    } else {
        event.Veto(); // Batalkan proses menutup aplikasi
    }
}

// Aplikasi utama
class BillingApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(BillingApp);

bool BillingApp::OnInit() {
    BillingFrame* frame = new BillingFrame("Billing Warnet Sederhana");
    frame->Show(true);
    return true;
}
