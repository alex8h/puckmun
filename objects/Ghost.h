#include "objects/GameObject.h"

class Ghost: public GameObject
{	
	MoveDirection m_current;
public:
	Ghost();
	MoveDirection tick() override;
	Ghost & set_current(MoveDirection);
	char get_form() const override;
	Color get_bg_color() const override;
	Color get_body_color() const override;
};
