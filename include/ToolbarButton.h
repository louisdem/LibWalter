// =============================================================================
//
// libwalter ToolbarButton.h
//
// Button control for WToolbar
//
// Page width 80, tab width 4, encoding UTF-8, line endings LF.
//
// Original author:
//     Gabriele Biffi - http://www.biffuz.it/
// Contributors:
//
// Released under the terms of the MIT license.
//
// =============================================================================

#ifndef _TOOLBAR_BUTTON_H_
#define _TOOLBAR_BUTTON_H_

// Standard C++ headers
#include <vector>

// Haiku headers
#include <Control.h> // For B_CONTROL_ON and B_CONTROL_OFF

// libwalter headers
#include "ButtonDecorator.h"
#include "ToolbarControl.h"

// Haiku classes
class BBitmap;

// =============================================================================
// WToolbarButton
// =============================================================================

class WToolbarButton : public WToolbarControl {
private:

	//		void				_calc_size(float &lh, float &lw, float &ph,
	//								float &pw);
			void				_init_object(void);
			ButtonDecorator *	fDecorator;
			bool				fSwitchMode;
			int32				fValue;

protected:

	// Infos for drawing hooks
			BView *				fCanvas;
			int					fStyle;

	// Drawing hooks
	virtual	float				BorderSize(void);
	virtual	void				ContentSize(float *width, float *height);
	virtual	void				DrawBackground(BRect updateRect);
	virtual	void				DrawBorder(BRect updateRect);
	virtual	void				DrawContent(BPoint position, BRect updateRect);
	virtual	float				Padding(void);

public:

								WToolbarButton(const char *name,
									const char *label,
									BBitmap *picture,
									BMessage *message = NULL,
									bool switchMode = false);
								WToolbarButton(BMessage *archive);

	virtual						~WToolbarButton();

	// BArchivable hooks
	virtual	status_t			Archive(BMessage *archive,
									bool deep = true) const;
	static	BArchivable *		Instantiate(BMessage *archive);

	// WToolbarControl hooks
	virtual	void				Draw(BView *canvas, BRect updateRect);
	virtual	void				GetPreferredSize(float *width, float *height);
	virtual	void				MouseUp(BPoint point);
	virtual	void				Update(void);

	// Picture
			void				GetPicture(BBitmap *picture[8]);
	virtual	bool				SetPicture(BBitmap *picture[8]);
	virtual	void				DeletePicture(void);

	// Special for bitmaps
			unsigned			CountBitmapSets(void);
			int					IndexOfBitmapSet(BDBitmapSet *set);
			BDBitmapSet *		GetBitmapSet(unsigned size);
			BDBitmapSet *		GetBitmapSetAt(unsigned index);
			bool				DeleteBitmapSet(unsigned size);
			bool				DeleteBitmapSetAt(unsigned index);

	// Label
			const char *		Label(void);
	virtual	void				SetLabel(const char *label);

	// Value
			int32				Value(void);
	virtual	void				SetValue(int32 value);

	// Other methods
			ButtonDecorator *	Decorator(void);
	static	BBitmap *			GetMenuCheckMark(void);
	virtual	void				SetSwitchMode(bool switchMode);
			bool				SwitchMode(void);
};

#endif // _TOOLBAR_BUTTON_H_
