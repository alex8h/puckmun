#pragma once

// Класс для рисования вещей во время игры. Содержит примитивные и не очень
// методы, дёргаемые ивентами

#include <ncurses.h>

#include "objects/ViewableObject.h"
#include "objects/GameField.h"
#include "objects/Block.h"
#include "view/NcursesScreen.h"

class GameRender
{
	NcursesScreen m_screen;

	WINDOW* m_map_window;

	size_t m_max_x, m_max_y;
	size_t m_max_map_width, m_max_map_height;


	//move cursor to nowhere
	void idle_cursor();
	//move cursor to map line
	void map_cursor(Coordinate x, Coordinate y);
	//draw character under cursor
	void basic_draw(char, Color fore, Color back);
	//redraw block under cursor
	void draw_current_block(const Block&);
	//redraw object under cursor
	void draw_current_object(const ViewableObject&);

public:
	GameRender();
	// draw object at its place
	GameRender& redraw_object_nomove(const GameField&, const ViewableObject&);

	// draw objects with new coordinated provided
	GameRender& redraw_object_pre_move(const GameField&, const ViewableObject&,
	                                   Coordinate x, Coordinate y);

	// draw objects with old coordinated provided
	GameRender& redraw_object_post_move(const GameField&,
	                                    Coordinate x, Coordinate y,
	                                    const ViewableObject&);

	GameRender& redraw_map_block(const GameField&,
	                          Coordinate x, Coordinate y);

	GameRender& redraw_any_block(const GameField&, const Block&,
	                         Coordinate x, Coordinate y);

	GameRender& redraw_complete(const GameField&);
};

// vim: tw=78
