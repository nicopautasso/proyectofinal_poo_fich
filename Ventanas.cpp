///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Ventanas.h"

///////////////////////////////////////////////////////////////////////////

VentanaPrincipal::VentanaPrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("SISTEMA DE VENTAS 1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 12, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer3->Add( m_staticText1, 1, wxALL, 9 );
	
	m_button1 = new wxButton( this, wxID_ANY, wxT("Ir a STOCK"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer3->Add( m_button1, 0, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline6 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer41->Add( m_staticline6, 0, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( bSizer41, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("REALIZAR VENTA:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 8, 74, 90, 90, true, wxT("Tahoma") ) );
	
	bSizer4->Add( m_staticText2, 0, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer4, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer401;
	bSizer401 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Buscar artículo:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText3->Wrap( -1 );
	bSizer401->Add( m_staticText3, 0, wxALL|wxEXPAND, 8 );
	
	busqueda_art = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer401->Add( busqueda_art, 1, wxALL|wxEXPAND, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer401->Add( m_button2, 0, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer401, 0, wxEXPAND, 5 );
	
	bSizer2->Add( bSizer8, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Artículo:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText25->Wrap( -1 );
	bSizer35->Add( m_staticText25, 0, wxALL, 9 );
	
	lista_articulos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	lista_articulos->CreateGrid( 0, 1 );
	lista_articulos->EnableEditing( false );
	lista_articulos->EnableGridLines( true );
	lista_articulos->EnableDragGridSize( false );
	lista_articulos->SetMargins( 0, 0 );
	
	// Columns
	lista_articulos->SetColSize( 0, 170 );
	lista_articulos->EnableDragColMove( false );
	lista_articulos->EnableDragColSize( false );
	lista_articulos->SetColLabelSize( 0 );
	lista_articulos->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	lista_articulos->AutoSizeRows();
	lista_articulos->EnableDragRowSize( false );
	lista_articulos->SetRowLabelSize( 0 );
	lista_articulos->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	lista_articulos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer35->Add( lista_articulos, 1, wxALL|wxEXPAND, 6 );
	
	bSizer40->Add( bSizer35, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText251 = new wxStaticText( this, wxID_ANY, wxT("Disponibles:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText251->Wrap( -1 );
	bSizer39->Add( m_staticText251, 0, wxALL|wxEXPAND, 9 );
	
	cantidad_disp = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	cantidad_disp->Enable( false );
	
	bSizer39->Add( cantidad_disp, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Precio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer39->Add( m_staticText26, 0, wxALL|wxEXPAND, 9 );
	
	precio_unit = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	precio_unit->Enable( false );
	
	bSizer39->Add( precio_unit, 1, wxALL|wxEXPAND, 5 );
	
	bSizer40->Add( bSizer39, 0, wxEXPAND, 5 );
	
	bSizer10->Add( bSizer40, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer361;
	bSizer361 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Cantidad:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText5->Wrap( -1 );
	bSizer11->Add( m_staticText5, 0, wxALIGN_RIGHT|wxALL|wxEXPAND, 9 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Total:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText6->Wrap( -1 );
	bSizer11->Add( m_staticText6, 0, wxALIGN_RIGHT|wxALL|wxEXPAND, 8 );
	
	bSizer361->Add( bSizer11, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	cantidad_venta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	cantidad_venta->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &cantidad ) );
	
	bSizer14->Add( cantidad_venta, 0, wxALL, 5 );
	
	precio_total = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 75,-1 ), wxTE_READONLY );
	precio_total->Enable( false );
	
	bSizer14->Add( precio_total, 0, wxALL, 5 );
	
	bSizer361->Add( bSizer14, 0, wxEXPAND, 5 );
	
	bSizer38->Add( bSizer361, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_button3 = new wxButton( this, wxID_ANY, wxT("VENDER"), wxDefaultPosition, wxSize( 90,45 ), 0 );
	bSizer15->Add( m_button3, 0, wxALL, 12 );
	
	bSizer38->Add( bSizer15, 1, wxEXPAND, 5 );
	
	bSizer10->Add( bSizer38, 1, wxEXPAND, 5 );
	
	bSizer2->Add( bSizer10, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer17->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Ventas de hoy:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer17->Add( m_staticText7, 0, wxALL|wxEXPAND, 5 );
	
	grillaventashoy = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grillaventashoy->CreateGrid( 0, 4 );
	grillaventashoy->EnableEditing( false );
	grillaventashoy->EnableGridLines( true );
	grillaventashoy->EnableDragGridSize( false );
	grillaventashoy->SetMargins( 0, 0 );
	
	// Columns
	grillaventashoy->SetColSize( 0, 130 );
	grillaventashoy->SetColSize( 1, 95 );
	grillaventashoy->SetColSize( 2, 95 );
	grillaventashoy->SetColSize( 3, 100 );
	grillaventashoy->EnableDragColMove( false );
	grillaventashoy->EnableDragColSize( false );
	grillaventashoy->SetColLabelSize( 20 );
	grillaventashoy->SetColLabelValue( 0, wxT("Artículo") );
	grillaventashoy->SetColLabelValue( 1, wxT("Cantidad") );
	grillaventashoy->SetColLabelValue( 2, wxT("Precio total") );
	grillaventashoy->SetColLabelValue( 3, wxT("Hora") );
	grillaventashoy->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grillaventashoy->AutoSizeRows();
	grillaventashoy->EnableDragRowSize( false );
	grillaventashoy->SetRowLabelSize( 0 );
	grillaventashoy->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grillaventashoy->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer17->Add( grillaventashoy, 1, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( bSizer17, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	m_button4 = new wxButton( this, wxID_ANY, wxT("VER HISTORIAL DE VENTAS"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer36->Add( m_button4, 0, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( bSizer36, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu2 = new wxMenu();
	wxMenuItem* ayuda;
	ayuda = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Ayuda del sistema") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( ayuda );
	
	m_menubar1->Append( m_menu2, wxT("Ayuda") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( VentanaPrincipal::CambiaTamanio ) );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickIrStock ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBuscarArt ), NULL, this );
	lista_articulos->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( VentanaPrincipal::articulo_ongrid ), NULL, this );
	cantidad_venta->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( VentanaPrincipal::cant_onwindow ), NULL, this );
	cantidad_venta->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( VentanaPrincipal::cant_ontext ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickVender ), NULL, this );
	grillaventashoy->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( VentanaPrincipal::ClickGrillaVentasHoy ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickVerHistorial ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::click_ayuda ) );
}

VentanaPrincipal::~VentanaPrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( VentanaPrincipal::CambiaTamanio ) );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickIrStock ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBuscarArt ), NULL, this );
	lista_articulos->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( VentanaPrincipal::articulo_ongrid ), NULL, this );
	cantidad_venta->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( VentanaPrincipal::cant_onwindow ), NULL, this );
	cantidad_venta->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( VentanaPrincipal::cant_ontext ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickVender ), NULL, this );
	grillaventashoy->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( VentanaPrincipal::ClickGrillaVentasHoy ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickVerHistorial ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::click_ayuda ) );
	
}

VentanaStock::VentanaStock( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("STOCK DE PRODUCTOS"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText8->Wrap( -1 );
	bSizer18->Add( m_staticText8, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Buscar artículo:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText9->Wrap( -1 );
	bSizer19->Add( m_staticText9, 0, wxALL, 10 );
	
	busqueda_art_stock = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( busqueda_art_stock, 1, wxALL|wxEXPAND, 5 );
	
	m_button5 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button5, 0, wxALL, 5 );
	
	bSizer18->Add( bSizer19, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	grillastock = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grillastock->CreateGrid( 0, 3 );
	grillastock->EnableEditing( false );
	grillastock->EnableGridLines( true );
	grillastock->EnableDragGridSize( false );
	grillastock->SetMargins( 0, 0 );
	
	// Columns
	grillastock->SetColSize( 0, 140 );
	grillastock->SetColSize( 1, 105 );
	grillastock->SetColSize( 2, 105 );
	grillastock->EnableDragColMove( false );
	grillastock->EnableDragColSize( false );
	grillastock->SetColLabelSize( 20 );
	grillastock->SetColLabelValue( 0, wxT("Artículo") );
	grillastock->SetColLabelValue( 1, wxT("Cantidad") );
	grillastock->SetColLabelValue( 2, wxT("Precio") );
	grillastock->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grillastock->AutoSizeRows();
	grillastock->EnableDragRowSize( false );
	grillastock->SetRowLabelSize( 0 );
	grillastock->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grillastock->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer24->Add( grillastock, 1, wxALL|wxEXPAND, 5 );
	
	bSizer18->Add( bSizer24, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Alertas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_button6, 0, wxALL|wxEXPAND, 7 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("Sin stock"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_button7, 0, wxALL|wxEXPAND, 7 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );
	
	m_button8 = new wxButton( this, wxID_ANY, wxT("Agregar artículo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button8, 1, wxALIGN_RIGHT|wxALL|wxEXPAND, 2 );
	
	m_button9 = new wxButton( this, wxID_ANY, wxT("Eliminar artículo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button9, 1, wxALIGN_RIGHT|wxALL|wxEXPAND, 2 );
	
	m_button81 = new wxButton( this, wxID_ANY, wxT("Modificar artículo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button81, 0, wxALIGN_RIGHT|wxALL|wxEXPAND, 2 );
	
	bSizer25->Add( bSizer26, 1, wxEXPAND, 5 );
	
	bSizer18->Add( bSizer25, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer18 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( VentanaStock::cerrar_stock ) );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickBuscarArtStock ), NULL, this );
	grillastock->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( VentanaStock::ClickGrillaStock ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickAlertas ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickSinStock ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickAgregarArt ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickEliminaArt ), NULL, this );
	m_button81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickModificarArt ), NULL, this );
}

VentanaStock::~VentanaStock()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( VentanaStock::cerrar_stock ) );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickBuscarArtStock ), NULL, this );
	grillastock->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( VentanaStock::ClickGrillaStock ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickAlertas ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickSinStock ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickAgregarArt ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickEliminaArt ), NULL, this );
	m_button81->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaStock::ClickModificarArt ), NULL, this );
	
}

VentanaIngresoArticulo::VentanaIngresoArticulo( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	titu_ingresa_art = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	titu_ingresa_art->Wrap( -1 );
	bSizer27->Add( titu_ingresa_art, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText11->Wrap( -1 );
	bSizer41->Add( m_staticText11, 1, wxALL|wxEXPAND, 8 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Cantidad:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText12->Wrap( -1 );
	bSizer41->Add( m_staticText12, 1, wxALL|wxEXPAND, 8 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Precio:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText13->Wrap( -1 );
	bSizer41->Add( m_staticText13, 1, wxALL|wxEXPAND, 8 );
	
	bSizer40->Add( bSizer41, 0, 0, 5 );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );
	
	nombre_ingresa_art = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( nombre_ingresa_art, 1, wxALL|wxEXPAND, 5 );
	
	cant_ingresa_art = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	cant_ingresa_art->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &cant_articulo ) );
	
	bSizer43->Add( cant_ingresa_art, 1, wxALL|wxEXPAND, 5 );
	
	precio_ingresa_art = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	precio_ingresa_art->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &precio_articulo ) );
	
	bSizer43->Add( precio_ingresa_art, 1, wxALL|wxEXPAND, 5 );
	
	bSizer40->Add( bSizer43, 1, 0, 5 );
	
	bSizer27->Add( bSizer40, 1, wxEXPAND, 5 );
	
	boton_aceptar_art = new wxButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( boton_aceptar_art, 0, wxALIGN_BOTTOM|wxALIGN_RIGHT|wxALL, 5 );
	
	this->SetSizer( bSizer27 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	boton_aceptar_art->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaIngresoArticulo::acepta_articulo ), NULL, this );
}

VentanaIngresoArticulo::~VentanaIngresoArticulo()
{
	// Disconnect Events
	boton_aceptar_art->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaIngresoArticulo::acepta_articulo ), NULL, this );
	
}

VentanaAlertas::VentanaAlertas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	titulo_alerta = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	titulo_alerta->Wrap( -1 );
	bSizer52->Add( titulo_alerta, 0, wxALL|wxEXPAND, 5 );
	
	grillapocostock = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grillapocostock->CreateGrid( 0, 2 );
	grillapocostock->EnableEditing( false );
	grillapocostock->EnableGridLines( true );
	grillapocostock->EnableDragGridSize( false );
	grillapocostock->SetMargins( 0, 0 );
	
	// Columns
	grillapocostock->SetColSize( 0, 144 );
	grillapocostock->SetColSize( 1, 140 );
	grillapocostock->EnableDragColMove( true );
	grillapocostock->EnableDragColSize( true );
	grillapocostock->SetColLabelSize( 20 );
	grillapocostock->SetColLabelValue( 0, wxT("Artículo") );
	grillapocostock->SetColLabelValue( 1, wxT("Cantidad restante") );
	grillapocostock->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grillapocostock->AutoSizeRows();
	grillapocostock->EnableDragRowSize( false );
	grillapocostock->SetRowLabelSize( 0 );
	grillapocostock->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grillapocostock->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer52->Add( grillapocostock, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );
	
	m_button16 = new wxButton( this, wxID_ANY, wxT("Modificar stock"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( m_button16, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	bSizer52->Add( bSizer53, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer52 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( VentanaAlertas::cierra_alerta ) );
	m_button16->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAlertas::click_agregar_stock ), NULL, this );
}

VentanaAlertas::~VentanaAlertas()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( VentanaAlertas::cierra_alerta ) );
	m_button16->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAlertas::click_agregar_stock ), NULL, this );
	
}

HistorialDeVentas::HistorialDeVentas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("HISTORIAL DE VENTAS:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText26->Wrap( -1 );
	bSizer58->Add( m_staticText26, 0, wxALL|wxEXPAND, 5 );
	
	grillaventashistorial = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grillaventashistorial->CreateGrid( 0, 4 );
	grillaventashistorial->EnableEditing( false );
	grillaventashistorial->EnableGridLines( true );
	grillaventashistorial->EnableDragGridSize( false );
	grillaventashistorial->SetMargins( 0, 0 );
	
	// Columns
	grillaventashistorial->SetColSize( 0, 110 );
	grillaventashistorial->SetColSize( 1, 71 );
	grillaventashistorial->SetColSize( 2, 102 );
	grillaventashistorial->SetColSize( 3, 120 );
	grillaventashistorial->EnableDragColMove( true );
	grillaventashistorial->EnableDragColSize( true );
	grillaventashistorial->SetColLabelSize( 20 );
	grillaventashistorial->SetColLabelValue( 0, wxT("Artículo") );
	grillaventashistorial->SetColLabelValue( 1, wxT("Cantidad") );
	grillaventashistorial->SetColLabelValue( 2, wxT("Precio total") );
	grillaventashistorial->SetColLabelValue( 3, wxT("Fecha") );
	grillaventashistorial->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grillaventashistorial->AutoSizeRows();
	grillaventashistorial->EnableDragRowSize( true );
	grillaventashistorial->SetRowLabelSize( 0 );
	grillaventashistorial->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grillaventashistorial->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer58->Add( grillaventashistorial, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button22 = new wxButton( this, wxID_ANY, wxT("Filtrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_button22, 0, wxALIGN_LEFT|wxALL, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	bSizer59->Add( bSizer34, 1, wxEXPAND, 5 );
	
	m_button19 = new wxButton( this, wxID_ANY, wxT("Eliminar venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_button19, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	bSizer58->Add( bSizer59, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	this->SetSizer( bSizer58 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HistorialDeVentas::cierra_historial ) );
	grillaventashistorial->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( HistorialDeVentas::ClickGrillaVentasHistorial ), NULL, this );
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HistorialDeVentas::ventana_filtrar_click ), NULL, this );
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HistorialDeVentas::eliminar_venta_click ), NULL, this );
}

HistorialDeVentas::~HistorialDeVentas()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HistorialDeVentas::cierra_historial ) );
	grillaventashistorial->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( HistorialDeVentas::ClickGrillaVentasHistorial ), NULL, this );
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HistorialDeVentas::ventana_filtrar_click ), NULL, this );
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HistorialDeVentas::eliminar_venta_click ), NULL, this );
	
}

VentanaFiltraHist::VentanaFiltraHist( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("FILTRAR VENTAS POR FECHA"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText23->Wrap( -1 );
	bSizer35->Add( m_staticText23, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer371;
	bSizer371 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText252 = new wxStaticText( this, wxID_ANY, wxT("Desde:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText252->Wrap( -1 );
	bSizer371->Add( m_staticText252, 0, wxALL|wxEXPAND, 9 );
	
	dia_fechadesde = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	dia_fechadesde->SetMaxLength( 2 ); 
	dia_fechadesde->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &desde_dia ) );
	
	bSizer371->Add( dia_fechadesde, 0, wxALL, 5 );
	
	m_staticText272 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText272->Wrap( -1 );
	bSizer371->Add( m_staticText272, 0, wxALL|wxEXPAND, 8 );
	
	mes_fechadesde = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	mes_fechadesde->SetMaxLength( 2 ); 
	mes_fechadesde->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &desde_mes ) );
	
	bSizer371->Add( mes_fechadesde, 0, wxALL, 5 );
	
	m_staticText282 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText282->Wrap( -1 );
	bSizer371->Add( m_staticText282, 0, wxALL|wxEXPAND, 8 );
	
	anio_fechadesde = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	anio_fechadesde->SetMaxLength( 4 ); 
	anio_fechadesde->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &desde_anio ) );
	
	bSizer371->Add( anio_fechadesde, 0, wxALL, 5 );
	
	bSizer43->Add( bSizer371, 0, 0, 5 );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText251 = new wxStaticText( this, wxID_ANY, wxT("Hasta:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText251->Wrap( -1 );
	bSizer37->Add( m_staticText251, 0, wxALL|wxEXPAND, 9 );
	
	dia_fechahasta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	dia_fechahasta->SetMaxLength( 2 ); 
	dia_fechahasta->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &hasta_dia ) );
	
	bSizer37->Add( dia_fechahasta, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText271 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText271->Wrap( -1 );
	bSizer37->Add( m_staticText271, 0, wxALL|wxEXPAND, 8 );
	
	mes_fechahasta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	mes_fechahasta->SetMaxLength( 2 ); 
	mes_fechahasta->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &hasta_mes ) );
	
	bSizer37->Add( mes_fechahasta, 0, wxALL, 5 );
	
	m_staticText281 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText281->Wrap( -1 );
	bSizer37->Add( m_staticText281, 0, wxALL|wxEXPAND, 8 );
	
	anio_fechahasta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	anio_fechahasta->SetMaxLength( 4 ); 
	anio_fechahasta->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &hasta_anio ) );
	
	bSizer37->Add( anio_fechahasta, 1, wxALL, 5 );
	
	bSizer43->Add( bSizer37, 0, wxEXPAND, 5 );
	
	bSizer45->Add( bSizer43, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer461;
	bSizer461 = new wxBoxSizer( wxVERTICAL );
	
	m_button25 = new wxButton( this, wxID_ANY, wxT("Filtrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer461->Add( m_button25, 1, wxALIGN_LEFT|wxALL, 12 );
	
	bSizer45->Add( bSizer461, 1, wxEXPAND, 5 );
	
	bSizer35->Add( bSizer45, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	grillaventasfiltrado = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grillaventasfiltrado->CreateGrid( 0, 4 );
	grillaventasfiltrado->EnableEditing( false );
	grillaventasfiltrado->EnableGridLines( true );
	grillaventasfiltrado->EnableDragGridSize( false );
	grillaventasfiltrado->SetMargins( 0, 0 );
	
	// Columns
	grillaventasfiltrado->SetColSize( 0, 105 );
	grillaventasfiltrado->SetColSize( 1, 75 );
	grillaventasfiltrado->SetColSize( 2, 81 );
	grillaventasfiltrado->SetColSize( 3, 134 );
	grillaventasfiltrado->EnableDragColMove( true );
	grillaventasfiltrado->EnableDragColSize( true );
	grillaventasfiltrado->SetColLabelSize( 20 );
	grillaventasfiltrado->SetColLabelValue( 0, wxT("Artículo") );
	grillaventasfiltrado->SetColLabelValue( 1, wxT("Cantidad") );
	grillaventasfiltrado->SetColLabelValue( 2, wxT("Precio total") );
	grillaventasfiltrado->SetColLabelValue( 3, wxT("Fecha") );
	grillaventasfiltrado->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grillaventasfiltrado->AutoSizeRows();
	grillaventasfiltrado->EnableDragRowSize( true );
	grillaventasfiltrado->SetRowLabelSize( 0 );
	grillaventasfiltrado->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grillaventasfiltrado->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer46->Add( grillaventasfiltrado, 1, wxALL|wxEXPAND, 5 );
	
	bSizer35->Add( bSizer46, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText55 = new wxStaticText( this, wxID_ANY, wxT("Total periodo:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText55->Wrap( -1 );
	bSizer52->Add( m_staticText55, 1, wxALL|wxEXPAND, 9 );
	
	total_periodo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	total_periodo->Enable( false );
	
	bSizer52->Add( total_periodo, 0, wxALIGN_RIGHT|wxALL|wxEXPAND|wxFIXED_MINSIZE, 5 );
	
	bSizer35->Add( bSizer52, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer35 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button25->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaFiltraHist::filtrar_ahora_click ), NULL, this );
	grillaventasfiltrado->Connect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( VentanaFiltraHist::ClickGrillaFiltrar ), NULL, this );
}

VentanaFiltraHist::~VentanaFiltraHist()
{
	// Disconnect Events
	m_button25->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaFiltraHist::filtrar_ahora_click ), NULL, this );
	grillaventasfiltrado->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( VentanaFiltraHist::ClickGrillaFiltrar ), NULL, this );
	
}

VentanaConfirmar::VentanaConfirmar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );
	
	texto_desea_eliminar = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	texto_desea_eliminar->Wrap( -1 );
	bSizer60->Add( texto_desea_eliminar, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	no_eliminar = new wxButton( this, wxID_ANY, wxT("No"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( no_eliminar, 1, wxALL, 5 );
	
	si_eliminar = new wxButton( this, wxID_ANY, wxT("Si, eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( si_eliminar, 1, wxALL, 5 );
	
	bSizer60->Add( bSizer61, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer60 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	no_eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaConfirmar::no_elimina_click ), NULL, this );
	si_eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaConfirmar::si_elimina_click ), NULL, this );
}

VentanaConfirmar::~VentanaConfirmar()
{
	// Disconnect Events
	no_eliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaConfirmar::no_elimina_click ), NULL, this );
	si_eliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaConfirmar::si_elimina_click ), NULL, this );
	
}

VentanaAyuda::VentanaAyuda( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );
	
	texto_ayuda = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer81->Add( texto_ayuda, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer81 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

VentanaAyuda::~VentanaAyuda()
{
}
