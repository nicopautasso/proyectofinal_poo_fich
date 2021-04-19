#include "Application.h"
#include "VPrincipal.h"
#include <wx/image.h>

IMPLEMENT_APP(mxApplication)

bool mxApplication::OnInit() {
	wxInitAllImageHandlers();
	new VPrincipal(NULL);
	return true;
}

