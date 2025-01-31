#include "DrawingPanel.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

// Event table for DrawingPanel
wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
EVT_PAINT(DrawingPanel::OnPaint)
EVT_LEFT_UP(DrawingPanel::OnMouseUp)
wxEND_EVENT_TABLE()

DrawingPanel::DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& gameBoardRef)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE),
    gameBoard(gameBoardRef) {
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
}

DrawingPanel::~DrawingPanel() {}

void DrawingPanel::SetSize(const wxSize& newSize) {
    wxPanel::SetSize(newSize);
    Refresh();
}

void DrawingPanel::SetGridSize(int newGridSize) {
    gridSize = newGridSize;
    Refresh();
}

void DrawingPanel::OnPaint(wxPaintEvent& event) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext* context = wxGraphicsContext::Create(dc);
    if (!context) return;

    context->SetPen(*wxBLACK_PEN);

    wxSize panelSize = GetClientSize();
    int cellWidth = panelSize.GetWidth() / gridSize;
    int cellHeight = panelSize.GetHeight() / gridSize;

    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            int x = col * cellWidth;
            int y = row * cellHeight;

            if (gameBoard[row][col]) {
                context->SetBrush(*wxLIGHT_GREY_BRUSH); // Alive cells
            }
            else {
                context->SetBrush(*wxWHITE_BRUSH); // Dead cells
            }
            context->DrawRectangle(x, y, cellWidth, cellHeight);
        }
    }

    delete context;
}

void DrawingPanel::OnMouseUp(wxMouseEvent& event) {
    int clickX = event.GetX();
    int clickY = event.GetY();

    wxSize panelSize = GetClientSize();
    int cellWidth = panelSize.GetWidth() / gridSize;
    int cellHeight = panelSize.GetHeight() / gridSize;

    int col = clickX / cellWidth;
    int row = clickY / cellHeight;

    if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
        gameBoard[row][col] = !gameBoard[row][col];
    }

    Refresh();
}