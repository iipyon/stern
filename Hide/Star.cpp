﻿#include"Star.h"
#include"CoreTask.h"
//---------------------------------

//---------------------------------

Star::Star(Point point_, PhysicState physic_state_, StarState star_state) : Physic(point_, physic_state_)
{
	bright = star_state.bright;
	radius = star_state.radius;
	power = star_state.power;
	life = star_state.life;
	angle = star_state.angle;
	contact = false;
}

void Star::exercise() {
	Point starpoint = { point.x, point.y, radius * 2, radius * 2 };



	velocityY += gravity;

	if (abs(velocityX) <= 1) {
		velocityX = 0;
	}
	else if (ct->gts->map->get_left(starpoint) == 1 || ct->gts->map->get_right(starpoint) == 1) {
		velocityX = rebound_X(velocityX);
	}
	int prevelX = int(velocityX);
	while (prevelX != 0) {
		int preX = starpoint.x;
		if (prevelX >= 1) { starpoint.x += 1; point.x += 1; prevelX -= 1; }
		else if (prevelX <= -1) { starpoint.x -= 1; point.x -= 1; prevelX += 1; }
		Point hit = starpoint;
		if (ct->gts->map->get_hit(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			point.x = preX;
			break;
		}
	}
	if (abs(velocityY) <= 2&&ct->gts->map->get_bottom(starpoint) == 1) {//<=2にすることで星ががくがくしなくなる
		velocityY = 0;
	}
	else if (ct->gts->map->get_bottom(starpoint) == 1) {
		velocityY = rebound_Y(velocityY);
	}
	int prevelY = int(velocityY);
	while (prevelY != 0) {
		int preY = starpoint.y;

		if (prevelY >= 1) { starpoint.y += 1; point.y += 1; prevelY -= 1; }
		else if (prevelY <= -1) { starpoint.y -= 1; point.y -= 1; prevelY += 1; }
		Point hit = starpoint;
		if (ct->gts->map->get_hit(hit) == 1) {//＝＝1の部分はマップ変更時に要変更

			point.y = preY;
			break;
		}

	}



}
float Star::rebound_X(int velX)
{
	return velX*-repulsion;
}

float Star::rebound_Y(int velY)
{
	return velY*-repulsion;
}

bool Star::attack()
{
	Point enemy_point;
	for (auto itr = ct->gts->enemys->begin(); itr != ct->gts->enemys->end(); ++itr) {
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


