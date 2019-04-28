#include "Physic.h"
#include "CoreTask.h"
//----------------------------------
//物理運動
//----------------------------------

Physic::Physic() 
{
	gravity = 1;//gravityがキャラによっていじる必要ないと判断した
	velocity = 0;
}


int Physic::fall(Point p_)
{
	//重力による落下
	velocity += int(gravity);  //gravityの分だけ加速させていく

	int prevel = velocity;//計算用かつ、velocityを不変のものであるために仮の値を用意
	while (prevel != 0) {//めり込まない移動処理の簡略化バージョン
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }//prevelを引いていくことでwhileを抜けられるように
		Point hit = p_;//当たり判定用の矩形を用意
		if (ct->gts->map->get_bottom(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			velocity = velocity-prevel-1;//直前のprevelの計算をなかったことにし、マップとの距離を求め直接velocityに代入
			break;
		}
	
	}
	return velocity;

}
int Physic::Movement_X(Point p_,int velocity_)
{

	int prevel = velocity_;//計算用かつ、velocityを不変のものであるために仮の値を用意
	while (prevel != 0) {//めり込まない移動処理の簡略化バージョン
		if (prevel >= 1) { p_.x += 1;  prevel -= 1; }
		if (prevel <= -1) { p_.x -= 1;  prevel += 1; }
		Point hit = p_;//当たり判定用の矩形を用意
		if (ct->gts->map->get_left(hit) == 1|| ct->gts->map->get_right(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			if (velocity_ > 0) {
				velocity_ = velocity_ - prevel - 1;//直前のprevelの計算をなかったことにし、マップとの距離を求め直接velocityに代入
			}
			else if (velocity_<0) {
				velocity_ = velocity_ - prevel + 1;
			}
			break;
		}

	}
	return velocity_;

}

int Physic::Movement_Y(Point p_, int velocity_)
{

	int prevel = velocity_;//計算用かつ、velocityを不変のものであるために仮の値を用意
	while (prevel != 0) {//めり込まない移動処理の簡略化バージョン
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }
		if (prevel <= -1) { p_.y -= 1;  prevel += 1; }
		Point hit = p_;//当たり判定用の矩形を用意
		if (ct->gts->map->get_top(hit) == 1 || ct->gts->map->get_bottom(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			if (velocity_ > 0) {
				velocity_ = velocity_ - prevel + 1;//直前のprevelの計算をなかったことにし、マップとの距離を求め直接velocityに代入
			}
			else if(velocity_ < 0){
				velocity_ = velocity_ - prevel - 1;
			}
			break;
		}

	}
	return velocity_;

}

/*void Physic::rebound_X()//バウンドの処理が必要になったら書くよ
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}*/

