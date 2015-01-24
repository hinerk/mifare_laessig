#include "interrupt.h"

void interrupt::handler1(){
	if(owner[0]){
		owner[0]->serviceRoutine();
	}
}
void interrupt::handler2(){
	if(owner[1]){
		owner[1]->serviceRoutine();
	}
}
void interrupt::handler3(){
	if(owner[2]){
		owner[2]->serviceRoutine();
	}
}
void interrupt::handler4(){
	if(owner[3]){
		owner[3]->serviceRoutine();
	}
}
void interrupt::handler5(){
	if(owner[4]){
		owner[4]->serviceRoutine();
	}
}
void interrupt::handler6(){
	if(owner[5]){
		owner[5]->serviceRoutine();
	}
}
void interrupt::handler7(){
	if(owner[6]){
		owner[6]->serviceRoutine();
	}
}
void interrupt::handler8(){
	if(owner[7]){
		owner[7]->serviceRoutine();
	}
}
void interrupt::handler9(){
	if(owner[8]){
		owner[8]->serviceRoutine();
	}
}
void interrupt::handler10(){
	if(owner[9]){
		owner[9]->serviceRoutine();
	}
}
void interrupt::handler11(){
	if(owner[10]){
		owner[10]->serviceRoutine();
	}
}
void interrupt::handler12(){
	if(owner[11]){
		owner[11]->serviceRoutine();
	}
}
void interrupt::handler13(){
	if(owner[12]){
		owner[12]->serviceRoutine();
	}
}
void interrupt::handler14(){
	if(owner[13]){
		owner[13]->serviceRoutine();
	}
}
void interrupt::handler15(){
	if(owner[14]){
		owner[14]->serviceRoutine();
	}
}
void interrupt::handler16(){
	if(owner[15]){
		owner[15]->serviceRoutine();
	}
}
void interrupt::handler17(){
	if(owner[16]){
		owner[16]->serviceRoutine();
	}
}
void interrupt::handler18(){
	if(owner[17]){
		owner[17]->serviceRoutine();
	}
}
void interrupt::handler19(){
	if(owner[18]){
		owner[18]->serviceRoutine();
	}
}
void interrupt::handler20(){
	if(owner[19]){
		owner[19]->serviceRoutine();
	}
}
void interrupt::handler21(){
	if(owner[20]){
		owner[20]->serviceRoutine();
	}
}
void interrupt::handler22(){
	if(owner[21]){
		owner[21]->serviceRoutine();
	}
}
void interrupt::handler23(){
	if(owner[22]){
		owner[22]->serviceRoutine();
	}
}
void interrupt::handler24(){
	if(owner[23]){
		owner[23]->serviceRoutine();
	}
}
void interrupt::handler25(){
	if(owner[24]){
		owner[24]->serviceRoutine();
	}
}
void interrupt::handler26(){
	if(owner[25]){
		owner[25]->serviceRoutine();
	}
}
void interrupt::handler27(){
	if(owner[26]){
		owner[26]->serviceRoutine();
	}
}
void interrupt::handler28(){
	if(owner[27]){
		owner[27]->serviceRoutine();
	}
}
void interrupt::handler29(){
	if(owner[28]){
		owner[28]->serviceRoutine();
	}
}
void interrupt::handler30(){
	if(owner[29]){
		owner[29]->serviceRoutine();
	}
}
void interrupt::handler31(){
	if(owner[30]){
		owner[30]->serviceRoutine();
	}
}
void interrupt::handler32(){
	if(owner[31]){
		owner[31]->serviceRoutine();
	}
}
void interrupt::handler33(){
	if(owner[32]){
		owner[32]->serviceRoutine();
	}
}
void interrupt::handler34(){
	if(owner[33]){
		owner[33]->serviceRoutine();
	}
}
void interrupt::handler35(){
	if(owner[34]){
		owner[34]->serviceRoutine();
	}
}

extern "C" void __cxa_pure_virtual() {
	for(;;)
		;
}

void interrupt::record(int interruptNumber,
		       interrupt *i) {
	owner[interruptNumber - 1] = i;
}

interrupt *interrupt::owner[] = {0};