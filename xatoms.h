/*-lX11
 */

#include <X11/Xlib.h>

void xatoms(void)
{
  Display *display;
  Atom  atom;

  display	= XOpenDisplay(NULL);
  FATAL(!display);
  /* Why isn't this pre-defined?  Only works with:  False	*/
  atom		= XInternAtom(display, "XSEL_DATA", True);
  FATAL(atom == None);
  /* Note: This works after it was once called with False	*/
}

