#include"Star.h"
#include"CoreTask.h"
//---------------------------------
//¯‘S”Ê
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

bool Star::attack()
{
	for (auto itr = ct->gts->walking_enemy.begin(); itr != ct->gts->walking_enemy.end(); ++itr) {
		enemy_point = itr->get_point();
		if (check_hit(enemy_point)) {
			itr->damage(power);
		}
	}
	for (auto itr = ct->gts->flying_enemy.begin(); itr != ct->gts->flying_enemy.end(); ++itr) {
		enemy_point = itr->get_point();
		if (check_hit(enemy_point)) {
			itr->damage(power);
		}
	}
	for (auto itr = ct->gts->throwing_enemy.begin(); itr != ct->gts->throwing_enemy.end(); ++itr) {
		enemy_point = itr->get_point();
		if (check_hit(enemy_point)) {
			itr->damage(power);
		}
	}
	for (auto itr = ct->gts->boss.begin(); itr != ct->gts->boss.end(); ++itr) {
		enemy_point = itr->get_point();
		if (check_hit(enemy_point)) {
			itr->damage(power);
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


