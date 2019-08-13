#include "Physic.h"
#include "CoreTask.h"
//----------------------------------
//�����^��
//----------------------------------

Physic::Physic() 
{
	//fall�p
	gravity = 1;
	velocity = 0;
}


int Physic::fall(Point p_)//�I�u�W�F�N�g�̍��W�������ɂ��Ď��ۂɂǂꂾ��������������Ԃ�
{
	//�d�͂ɂ�闎��
	velocity += int(gravity);                                            //gravity�̕��������������Ă���

	int prevel = velocity;                                               //�v�Z�p���Avelocity��s�ς̂��̂ł��邽�߂ɉ��̒l��p��
	while (prevel != 0) {                                                //�߂荞�܂Ȃ��ړ������̊ȗ����o�[�W����
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }                    //1�h�b�g������
		else { p_.y += prevel; prevel = 0; }                             //1�h�b�g�����̏ꍇ�̈ړ��p�i�{���s�K�v�j
		Point hit = p_;                                                  //�����蔻��p�̋�`��p��
		hit.y--;
		if (ct->gts->map->get_bottom(hit) == 1) {                        //�}�b�v�Ƃ̓����蔻��
			velocity = velocity-prevel-1;                                //���O��prevel�̌v�Z���Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋��������ߒ���velocity�ɑ��
			break;
		}
	
	}
	return velocity;

}

//----------------------------------------------------------------
//Movement_X,Y �I�u�W�F�N�g�̍��W�ƈړ��������l�������ɂ��āA���ۂɈړ��ł���l��Ԃ�
//----------------------------------------------------------------
int Physic::Movement_X(Point p_,int velocity_)
{

	int prevel = velocity_;                                                          //�v�Z�p���Avelocity��s�ς̂��̂ł��邽�߂ɉ��̒l��p��
	while (prevel != 0) {                                                            //�߂荞�܂Ȃ��ړ������̊ȗ����o�[�W����
		if (prevel >= 1) { p_.x += 1;  prevel -= 1; }                                //�ړ�������+�������}�C�i�X�������̔��肵�A�P�h�b�g���߂荞�܂Ȃ����ǂ����̔�����s��
		else if (prevel <= -1) { p_.x -= 1;  prevel += 1; }
		else { p_.y += prevel; prevel = 0; }                                         //1�h�b�g�����̏ꍇ�̈ړ��p�i�{���s�K�v�j
		Point hit = p_;                                                              //�����蔻��p�̋�`��p��
		hit = { hit.x - 1,hit.y,hit.w + 2,hit.h -1 };
		if (ct->gts->map->get_left(hit) == 1|| ct->gts->map->get_right(hit) == 1) {  //�}�b�v�Ƃ̓����蔻��

			if (velocity_ > 0) {
				velocity_ = velocity_ - prevel -1;                                   //���O��prevel�̌v�Z���Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋��������ߒ���velocity�ɑ��
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

	int prevel = velocity_;                                                           //�v�Z�p���Avelocity��s�ς̂��̂ł��邽�߂ɉ��̒l��p��
	while (prevel != 0) {                                                             //�߂荞�܂Ȃ��ړ������̊ȗ����o�[�W����
		if (prevel >= 1) { p_.y += 1;  prevel -= 1; }                                 //�ړ�������+�������}�C�i�X�������̔��肵�A�P�h�b�g���߂荞�܂Ȃ����ǂ����̔�����s��
		else if (prevel <= -1) { p_.y -= 1;  prevel += 1; }
		else { p_.y += prevel; prevel = 0; }                                          //1�h�b�g�����̏ꍇ�̈ړ��p�i�{���s�K�v�j
		Point hit = p_;                                                               //�����蔻��p�̋�`��p��
		hit = { hit.x,hit.y,hit.w -1,hit.h };
		if (velocity_ > 0) {
			hit.y++;                             //���O��prevel�̌v�Z���Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋��������ߒ���velocity�ɑ��
		}
		else if (velocity_<0) {
			hit.y--;
		}
		if (ct->gts->map->get_top(hit) == 1 || ct->gts->map->get_bottom(hit) == 1) {  //�}�b�v�Ƃ̓����蔻��

			if (velocity_ > 0) {                                                      //���O��prevel�̌v�Z���Ȃ��������Ƃɂ��A�}�b�v�Ƃ̋��������ߒ���velocity�ɑ��
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

/*void Physic::rebound_X()//�o�E���h�̏������K�v�ɂȂ����珑����
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}*/

