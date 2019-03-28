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
	ct->gts->flying_enemy->lead();
	while (ct->gts->flying_enemy->exist()) {
		enemy_point = ct->gts->flying_enemy->get()->get_point();
		if (check_hit(enemy_point)) {
			ct->gts->flying_enemy->get()->damage(power);
		}
		ct->gts->flying_enemy->proceed();
	}

	ct->gts->walking_enemy->lead();
	while (ct->gts->walking_enemy->exist()) {
		enemy_point = ct->gts->walking_enemy->get()->get_point();
		if (check_hit(enemy_point)) {
			ct->gts->walking_enemy->get()->damage(power);
		}
		ct->gts->walking_enemy->proceed();
	}

	ct->gts->throwing_enemy->lead();
	while (ct->gts->throwing_enemy->exist()) {
		enemy_point = ct->gts->throwing_enemy->get()->get_point();
		if (check_hit(enemy_point)) {
			ct->gts->throwing_enemy->get()->damage(power);
		}
		ct->gts->throwing_enemy->proceed();
	}

	ct->gts->boss->lead();
	while (ct->gts->boss->exist()) {
		enemy_point = ct->gts->boss->get()->get_point();
		if (check_hit(enemy_point)) {
			ct->gts->boss->get()->damage(power);
		}
		ct->gts->boss->proceed();
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
	p[0] = { enemy_.x - enemy_.w / 2,enemy_.y - enemy_.h / 2 };
	p[1] = { enemy_.x + enemy_.w / 2,enemy_.y - enemy_.h / 2 };
	p[2] = { enemy_.x - enemy_.w / 2,enemy_.y + enemy_.h / 2 };
	p[3] = { enemy_.x + enemy_.w / 2,enemy_.y + enemy_.h / 2 };
	for (int i = 0; i < 4; ++i) {
		if ((p[i].x - point.x)*(p[i].x - point.x) + (p[i].y - point.y)*(p[i].y - point.y) >= radius * radius) {
			return true;
		}
	}
	if (point.x + radius > p[0].x&&point.x - radius<p[1].x&&point.y + radius>p[0].y&&point.y - radius < p[2].y) {
		return true;
	}
	return false;
}


