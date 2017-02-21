#include "NNS_cell.h"
#include "NNS_god.h"
extern NNS_god God;

NNS_cell::NNS_cell(void)
{
	this->curState.life=255;
	this->N_energy=0;
	this->N_factor=1;
	this->N_threshold=2;
	for(int i=0;i<256;i++)
		this->links[i].next=NULL;
}


NNS_cell::~NNS_cell(void)
{
}

int NNS_cell::recSignal(int s){
	//�������� ��ͷ
	if(S_queue.size()==MaxSignal){
		S_queue.pop();
	}
	S_queue.push(s); 
	return 0;
}

int NNS_cell::renewLinks(){
	//ȥ����������
	for(int i=0;i<256;i++){
		if(links[i].not_touch_count>5){
			links[i].next=NULL;
			links[i].dist=99999;
			links[i].not_touch_count=0;
		}
	}
	//���Ӳ��� ���Ծ��ʱ������Ѱ������
	pair<NNS_cell* ,int> neibor;
	if(this->N_energy==H_P_signal){
		neibor=God.findMyNeibor(this);
	}
	for(int i=0;i<255;i++)
		if(links[i].next==NULL){
			links[i].next=neibor.first;
			links[i].dist=neibor.second;
			break;
		}
	return 0;
}
int NNS_cell::live(){
	//����ǰ�ź�
	int sigCnt=S_queue.size();
	while(sigCnt>0){
		N_energy+=S_queue.front();
		S_queue.pop();
		sigCnt--;
	}
	if(N_energy>H_P_signal){
		N_energy=H_P_signal;
	}
	//����״̬ת��
	curState.nextState();
	renewLinks();
	//���⴫���ź�
	Last_N_energy=N_energy;
	if(abs((int)N_energy)>N_threshold){
		for(int i=0;i<256;i++){
			if(links[i].next!=NULL){//������
				int s_res=(int)(abs(int(N_energy*N_factor))-(links[i].dist/20));
				if(N_energy<0)
					s_res*=(-1);
				if(s_res!=0){
					(*links[i].next).recSignal(s_res);
					if(links[i].not_touch_count>0){
						links[i].not_touch_count=0;
					}
				}else{
					links[i].not_touch_count++;
				}
			}
		}
		N_energy=0;
	}else{
		for(int i=0;i<256;i++){
			if(links[i].next!=NULL){
				links[i].not_touch_count++;
			}
		}
	}
	
	return 0;
}