#include "Physic.h"
#include "CoreTask.h"
//----------------------------------
//物理運動
//----------------------------------

Physic::Physic() 
{
	//fall用
	gravity = 1;
	velocity = 0;
}


int Physic::fall(Point p_)//オブジェクトの座標を引数にして実際にどれだけ落下したかを返す
{
	//重力による落下
	velocity += int(gravity);                                            //gravityの分だけ加速させていく

	int prevel = velocity;                                               //計算用かつ、velocityを不変のものであるために仮の値を用意
	while (prevel != 0) {                                                //めり込まない移動処理の簡略化バージョン
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }                    //1ドットずつ判定
		else { p_.y += prevel; prevel = 0; }                             //1ドット未満の場合の移動用（本来不必要）
		Point hit = p_;                                                  //当たり判定用の矩形を用意
		hit.y--;
		if (ct->gts->map->get_bottom(hit) == 1) {                        //マップとの当たり判定
			velocity = velocity-prevel-1;                                //直前のprevelの計算をなかったことにし、マップとの距離を求め直接velocityに代入
			break;
		}
	
	}
	return velocity;

}

//----------------------------------------------------------------
//Movement_X,Y オブジェクトの座標と移動したい値を引数にして、実際に移動できる値を返す
//----------------------------------------------------------------
int Physic::Movement_X(Point p_,int velocity_)
{

	int prevel = velocity_;                                                          //計算用かつ、velocityを不変のものであるために仮の値を用意
	while (prevel != 0) {                                                            //めり込まない移動処理の簡略化バージョン
		if (prevel >= 1) { p_.x += 1;  prevel -= 1; }                                //移動方向は+方向かマイナス方向かの判定し、１ドットずつめり込まないかどうかの判定を行う
		else if (prevel <= -1) { p_.x -= 1;  prevel += 1; }
		else { p_.y += prevel; prevel = 0; }                                         //1ドット未満の場合の移動用（本来不必要）
		Point hit = p_;                                                              //当たり判定用の矩形を用意
		hit = { hit.x - 1,hit.y,hit.w + 2,hit.h -1 };
		if (ct->gts->map->get_left(hit) == 1|| ct->gts->map->get_right(hit) == 1) {  //マップとの当たり判定

			if (velocity_ > 0) {
				velocity_ = velocity_ - prevel -1;                                   //直前のprevelの計算をなかったことにし、マップとの距離を求め直接velocityに代入
			}
			else if (velocity_<0) {
				velocity_ = velocity_ - prevel +1;
			}
			break;
		}

	}
	return velocity_;

}

int Physic::Movement_Y(Point p_, int velocity_)
{

	int prevel = velocity_;                                                           //計算用かつ、velocityを不変のものであるために仮の値を用意
	while (prevel != 0) {                                                             //めり込まない移動処理の簡略化バージョン
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }                                 //移動方向は+方向かマイナス方向かの判定し、１ドットずつめり込まないかどうかの判定を行う
		else if (prevel <= -1) { p_.y -= 1;  prevel += 1; }
		else { p_.y += prevel; prevel = 0; }                                          //1ドット未満の場合の移動用（本来不必要）
		Point hit = p_;                                                               //当たり判定用の矩形を用意
		hit = { hit.x,hit.y,hit.w -1,hit.h };
		if (velocity_ > 0) {
			hit.y++;                             //直前のprevelの計算をなかったことにし、マップとの距離を求め直接velocityに代入
		}
		else if (velocity_<0) {
			hit.y--;
		}
		if (ct->gts->map->get_top(hit) == 1 || ct->gts->map->get_bottom(hit) == 1) {  //マップとの当たり判定

			if (velocity_ > 0) {                                                      //直前のprevelの計算をなかったことにし、マップとの距離を求め直接velocityに代入
				velocity_ = velocity_ - prevel-1;                                     
			}
			else if(velocity_ < 0){
				velocity_ = velocity_ - prevel+1;
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

