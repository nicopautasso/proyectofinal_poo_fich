///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __Ventanas__
#define __Ventanas__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/valtext.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/html/htmlwin.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class VentanaPrincipal
///////////////////////////////////////////////////////////////////////////////
class VentanaPrincipal : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxButton* m_button1;
		wxStaticLine* m_staticline6;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxTextCtrl* busqueda_art;
		wxButton* m_button2;
		wxStaticText* m_staticText25;
		wxGrid* lista_articulos;
		wxStaticText* m_staticText251;
		wxTextCtrl* cantidad_disp;
		wxStaticText* m_staticText26;
		wxTextCtrl* precio_unit;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxTextCtrl* cantidad_venta;
		wxTextCtrl* precio_total;
		wxButton* m_button3;
		wxStaticLine* m_staticline4;
		wxStaticText* m_staticText7;
		wxGrid* grillaventashoy;
		wxButton* m_button4;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void CambiaTamanio( wxSizeEvent& event ) { event.Skip(); }
		virtual void ClickIrStock( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscarArt( wxCommandEvent& event ) { event.Skip(); }
		virtual void articulo_ongrid( wxGridEvent& event ) { event.Skip(); }
		virtual void cant_onwindow( wxMouseEvent& event ) { event.Skip(); }
		virtual void cant_ontext( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVender( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGrillaVentasHoy( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickVerHistorial( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_ayuda( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxString cantidad; 
		
		VentanaPrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sistema de ventas 1.0"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 545,493 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~VentanaPrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaStock
///////////////////////////////////////////////////////////////////////////////
class VentanaStock : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxTextCtrl* busqueda_art_stock;
		wxButton* m_button5;
		wxGrid* grillastock;
		wxButton* m_button6;
		wxButton* m_button7;
		wxButton* m_button8;
		wxButton* m_button9;
		wxButton* m_button81;
		
		// Virtual event handlers, overide them in your derived class
		virtual void cerrar_stock( wxCloseEvent& event ) { event.Skip(); }
		virtual void ClickBuscarArtStock( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGrillaStock( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAlertas( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickSinStock( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarArt( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminaArt( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickModificarArt( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaStock( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 382,402 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaStock();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaIngresoArticulo
///////////////////////////////////////////////////////////////////////////////
class VentanaIngresoArticulo : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* titu_ingresa_art;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxTextCtrl* nombre_ingresa_art;
		wxTextCtrl* cant_ingresa_art;
		wxTextCtrl* precio_ingresa_art;
		wxButton* boton_aceptar_art;
		
		// Virtual event handlers, overide them in your derived class
		virtual void acepta_articulo( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxString cant_articulo; 
		wxString precio_articulo; 
		
		VentanaIngresoArticulo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 244,185 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaIngresoArticulo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAlertas
///////////////////////////////////////////////////////////////////////////////
class VentanaAlertas : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* titulo_alerta;
		wxGrid* grillapocostock;
		wxButton* m_button16;
		
		// Virtual event handlers, overide them in your derived class
		virtual void cierra_alerta( wxCloseEvent& event ) { event.Skip(); }
		virtual void click_agregar_stock( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaAlertas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 324,243 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaAlertas();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class HistorialDeVentas
///////////////////////////////////////////////////////////////////////////////
class HistorialDeVentas : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText26;
		wxGrid* grillaventashistorial;
		wxButton* m_button22;
		wxButton* m_button19;
		
		// Virtual event handlers, overide them in your derived class
		virtual void cierra_historial( wxCloseEvent& event ) { event.Skip(); }
		virtual void ClickGrillaVentasHistorial( wxGridEvent& event ) { event.Skip(); }
		virtual void ventana_filtrar_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void eliminar_venta_click( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		HistorialDeVentas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 449,352 ), long style = wxDEFAULT_DIALOG_STYLE );
		~HistorialDeVentas();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaFiltraHist
///////////////////////////////////////////////////////////////////////////////
class VentanaFiltraHist : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText23;
		wxStaticText* m_staticText252;
		wxTextCtrl* dia_fechadesde;
		wxStaticText* m_staticText272;
		wxTextCtrl* mes_fechadesde;
		wxStaticText* m_staticText282;
		wxTextCtrl* anio_fechadesde;
		wxStaticText* m_staticText251;
		wxTextCtrl* dia_fechahasta;
		wxStaticText* m_staticText271;
		wxTextCtrl* mes_fechahasta;
		wxStaticText* m_staticText281;
		wxTextCtrl* anio_fechahasta;
		wxButton* m_button25;
		wxGrid* grillaventasfiltrado;
		wxStaticText* m_staticText55;
		wxTextCtrl* total_periodo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void filtrar_ahora_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGrillaFiltrar( wxGridEvent& event ) { event.Skip(); }
		
	
	public:
		wxString desde_dia; 
		wxString desde_mes; 
		wxString desde_anio; 
		wxString hasta_dia; 
		wxString hasta_mes; 
		wxString hasta_anio; 
		
		VentanaFiltraHist( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 431,288 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaFiltraHist();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaConfirmar
///////////////////////////////////////////////////////////////////////////////
class VentanaConfirmar : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* texto_desea_eliminar;
		wxButton* no_eliminar;
		wxButton* si_eliminar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void no_elimina_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void si_elimina_click( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaConfirmar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 268,97 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaConfirmar();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAyuda
///////////////////////////////////////////////////////////////////////////////
class VentanaAyuda : public wxFrame 
{
	private:
	
	protected:
		wxHtmlWindow* texto_ayuda;
	
	public:
		
		VentanaAyuda( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 536,429 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~VentanaAyuda();
	
};

#endif //__Ventanas__
