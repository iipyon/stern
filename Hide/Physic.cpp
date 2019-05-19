#include "Physic.h"
#include "CoreTask.h"	//map
//
#include "Controller.h"


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

	int prevel = velocity;//�v�Z�p���Avelocity��s�ς̂�̂ł��邽�߂ɉ��̒l��p��
	while (prevel != 0) {//�߂荞�܂Ȃ��ړ������̊ȗ����o�[�W����
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }//prevel������Ă������Ƃ�while�𔲂�����悤��
		else { p_.y += prevel; prevel = 0; }
		Point hit = p_;//�����蔻��p�̋�`��p��
		if (ct->gts->map->get_bottom(hit) == 1) {//����1�̕����̓}�b�v�ύX���ɗv�ύX
			velocity = velocity-prevel-1;//���O��prevel�̌v�Z��Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋�����ߒ���velocity�ɑ��
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
		else if (prevel <= -1) { p_.x -= 1;  prevel += 1; }
		else { p_.y += prevel; prevel = 0; }
		Point hit = p_;//�����蔻��p�̋�`��p��
		if (ct->gts->map->get_left(hit) == 1|| ct->gts->map->get_right(hit) == 1) {//����1�̕����̓}�b�v�ύX���ɗv�ύX
			if (velocity_ > 0) {
				velocity_ = velocity_ - prevel -1;//���O��prevel�̌v�Z��Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋�����ߒ���velocity�ɑ��
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

	int prevel = velocity_;//計算用かつ、velocityを不変のものであるために仮の値を用意
	while (prevel != 0) {//めり込まない移動処理の簡略化バージョン
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }
		else if (prevel <= -1) { p_.y -= 1;  prevel += 1; }
		else { p_.y += prevel; prevel = 0; }
		Point hit = p_;//�����蔻��p�̋�`��p��
		if (ct->gts->map->get_top(hit) == 1 || ct->gts->map->get_bottom(hit) == 1) {//����1�̕����̓}�b�v�ύX���ɗv�ύX
			if (velocity_ > 0) {
				velocity_ = velocity_ - prevel-1;//���O��prevel�̌v�Z��Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋�����ߒ���velocity�ɑ��
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

