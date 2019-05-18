#include"Star.h"
//
#include "Model.h"


//---------------------------------

//---------------------------------

Star::Star(Point point_, PhysicState physic_state_, StarState star_state) :BasicObject(point)
{
	bright = star_state.bright;
	radius = star_state.radius;
	power = star_state.power;
	life = star_state.life;
	angle = star_state.angle;
	contact = false;
}

/*void Star::exercise() {
	Point starpoint = { point.x - radius, point.y - point.y - radius, radius * 2, radius * 2 };
	velocityY += gravity;

	if (velocityX <= 0.5f && velocityY <= 0.5f) {
		repulsion = 0.0f;
	}
	int prevelX = int(velocityX);
	while (velocityX != 0) {
		int preX = starpoint.x;
		if (velocityX >= 1) { starpoint.x += 1; velocityX -= 1; }
		else if (velocityX <= -1) { starpoint.x -= 1; velocityX += 1; }
		Point hit = starpoint;
		if (ct->gts->map->get_left(hit) == 1 || ct->gts->map->get_right(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			starpoint.x = preX;
			rebound_X();
			break;
		}
	}
	int prevelY = int(velocityY);
	while (prevelY != 0) {
		int preY = starpoint.y;

		if (velocityY >= 1) {starpoint.y += 1; prevelY -= 1;}
		else if (velocityY <= -1) {starpoint.y -= 1; prevelY += 1; }
		Point hit = starpoint;
		if (ct->gts->map->get_bottom(hit) == 1 || ct->gts->map->get_top(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			starpoint.y = preY;
			rebound_Y();
			break;
		}

	}

}
void Star::rebound_X()
{
	velocityX *= -repulsion;
}

void Star::rebound_Y()
{
	velocityY *= -repulsion;
}*/
bool Star::attack()
{
	Point enemy_point;
	for (auto itr = mdl::enemys->begin(); itr != mdl::enemys->end(); ++itr) {
		enemy_point = (*itr)->get_point();
		if (check_hit(enemy_point)) {
			(*itr)->damage(power);
		}
	}
	return false;
}

bool Star::damage(int damage_)
{
	life -= damage_;
	if (life <= 0) {
		return true;
	}
	return false;
}

bool Star::check_hit(Point enemy_) {

	struct p {
		int x = 0, y = 0;
	}
	p[4];
	p[0] = { enemy_.x,enemy_.y};
	p[1] = { enemy_.x + enemy_.w,enemy_.y};
	p[2] = { enemy_.x ,enemy_.y + enemy_.h };
	p[3] = { enemy_.x + enemy_.w,enemy_.y + enemy_.h };
	for (int i = 0; i < 4; ++i) {
		if ((p[i].x - point.x)*(p[i].x - point.x) + (p[i].y - point.y)*(p[i].y - point.y) <= radius * radius) {
			return true;
		}
	}
	if (point.x + radius > p[0].x&&point.x - radius<p[1].x&&point.y + radius>p[0].y&&point.y - radius < p[2].y) {
		return true;
	}
	return false;
}


