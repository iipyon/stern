#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"CoreTask.h"


//--------------------------------
//•’Ê‚Ì¯
//--------------------------------

NormalStar::NormalStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_,physic_state_,star_state)
{

}

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//‰¼‚ÌˆÚ“®//moveijì‚ç‚ËH
	if (contact) {
		x += (int)(-sin(angle) * velocityX);
		y += (int)(cos(angle) * velocityY);
			if (ct->gts->map->get_bottom(Point{ x,y,width,height }) && ct->gts->map->get_top(Point{ x,y,width,height }) && ct->gts->map->get_left(Point{ x,y,width,height }) && ct->gts->map->get_right(Point{ x,y,width,height })) {
			contact = true;

		}
	}
	else {
		this->exercise();
	}
	if (attack()) {
		//enemy‚Ìƒ_ƒ[ƒW‚ðŒÄ‚Ô
	}


	draw();
	if (damage(1)) {
		ct->gts->normalstar->destroy();
	}
	//if(gravitystar‚ª‚ ‚é‚©‚Ç‚¤‚©)o//d—Í‚ª‚©‚©‚é”ÍˆÍ‚ðŒˆ‚ß‚Ä‹ß‚­‚É‚È‚©‚Á‚½‚çfalse‚Å‚à‚¢‚¢‚©‚à
	//gravitystar‚ÌÀ•W‚ðŽæ‚è‘±‚¯‚é
	//inhale(gravitystar‚ÌÀ•W);
	//p
}

void NormalStar::inhale(int, int, float)
{
	//ˆÚ“®—Ê‚Égravitystar‚ÌÀ•W‚Æ‚Ì·‚ðo‚µ‚Ä‘«‚µ‘±‚¯‚é
}

