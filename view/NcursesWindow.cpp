#include "view/NcursesWindow.h"

#include "view/NcursesScreen.h"
#include "errors/GameRender-errors.h"
#include "errors/NcursesError.h"

using Border = NcursesWindow::Border;

NcursesWindow::NcursesWindow(int x, int y, int w, int h, const Border& border)
	: m_start_x (x)
	, m_start_y (y)
	, m_height  (h)
	, m_width   (w)
	, m_border  (border)
{
	if (NcursesScreen::get_screens_open() == 0)
	{
		throw ScreenError("Trying to create window with no screens open");
	}

	// create window
	m_window = newwin(m_height, m_width, m_start_y, m_start_x);
	// draw a box around it
	wborder(m_window, m_border.left,    m_border.right,
	                  m_border.top,     m_border.bottom,
	                  m_border.topleft, m_border.topright,
	                  m_border.botleft, m_border.botright);
	// show it
	wrefresh(m_window);
	refresh();
}

NcursesWindow::~NcursesWindow()
{
	// delete the border
	wborder(m_window, ' ',' ',  //left, right
	                  ' ',' ',  //top, bottom
	                  ' ',' ',  //top corners:    left, right
	                  ' ',' '); //bottom corners: left, right
	//show deletion
	wrefresh(m_window);
	//delete window
	delwin(m_window);
}

WINDOW* NcursesWindow::get() const
{
	return m_window;
}

NcursesWindow& NcursesWindow::rebox()
{
	wborder(m_window, m_border.left,    m_border.right,
	                  m_border.top,     m_border.bottom,
	                  m_border.topleft, m_border.topright,
	                  m_border.botleft, m_border.botright);
	wrefresh(m_window);

	return *this;
}