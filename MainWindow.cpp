#include "MainWindow.h"
#include "play.xpm"
#include "pause.xpm"
#include "next.xpm"
#include "trash.xpm"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_MENU(ID_PLAY, MainWindow::OnPlay)
EVT_MENU(ID_PAUSE, MainWindow::OnPause)
EVT_MENU(ID_NEXT, MainWindow::OnNext)
EVT_MENU(ID_CLEAR, MainWindow::OnClear)
wxEND_EVENT_TABLE()

MainWindow::MainWindow()
    : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(800, 600)) {

    // Create status bar
    statusBar = this->CreateStatusBar();

    // Create toolbar
    toolBar = this->CreateToolBar();

    // Load icons and add buttons to the toolbar
    wxBitmap playIcon(play_xpm);
    wxBitmap pauseIcon(pause_xpm);
    wxBitmap nextIcon(next_xpm);
    wxBitmap trashIcon(trash_xpm);

    toolBar->AddTool(ID_PLAY, "Play", playIcon);
    toolBar->AddTool(ID_PAUSE, "Pause", pauseIcon);
    toolBar->AddTool(ID_NEXT, "Next", nextIcon);
    toolBar->AddTool(ID_CLEAR, "Clear", trashIcon);

    // Render the toolbar
    toolBar->Realize();

    // Initialize the game board
    InitializeGrid();

    // Create the DrawingPanel and pass gameBoard reference
    drawingPanel = new DrawingPanel(this, gameBoard);

    // Bind resize event
    this->Bind(wxEVT_SIZE, &MainWindow::OnSizeChange, this);

    // Initial status update
    UpdateStatusBar();

    // Ensure layout updates correctly to show toolbar & status bar
    this->Layout();
}

MainWindow::~MainWindow() {}

void MainWindow::InitializeGrid() {
    gameBoard.resize(gridSize);
    for (int i = 0; i < gridSize; ++i) {
        gameBoard[i].resize(gridSize, false);
    }

    // Reset game stats
    generationCount = 0;
    livingCellsCount = 0;

    // Update the drawing panel and status bar
    drawingPanel->SetGridSize(gridSize);
    UpdateStatusBar();
}

void MainWindow::UpdateStatusBar() {
    // Count living cells
    livingCellsCount = 0;
    for (const auto& row : gameBoard) {
        for (bool cell : row) {
            if (cell) livingCellsCount++;
        }
    }

    // Update status bar text
    wxString statusText = wxString::Format("Generations: %d | Living Cells: %d", generationCount, livingCellsCount);
    statusBar->SetStatusText(statusText);
}

void MainWindow::OnSizeChange(wxSizeEvent& event) {
    wxSize newSize = GetClientSize();
    if (drawingPanel) {
        drawingPanel->SetSize(newSize);
    }
    event.Skip(); // Ensures other events continue processing properly
}

// Toolbar event handlers
void MainWindow::OnPlay(wxCommandEvent& event) {
    wxLogMessage("Play button clicked");
    // TODO: Start game loop for automatic generation updates
}

void MainWindow::OnPause(wxCommandEvent& event) {
    wxLogMessage("Pause button clicked");
    // TODO: Pause the game loop
}

void MainWindow::OnNext(wxCommandEvent& event) {
    wxLogMessage("Next Generation button clicked");
    // TODO: Implement logic to advance to the next generation
}

void MainWindow::OnClear(wxCommandEvent& event) {
    wxLogMessage("Clear Grid button clicked");
    InitializeGrid();
    drawingPanel->Refresh();
}