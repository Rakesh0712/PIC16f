#include <main.h>

void main()
{
	setup_timer_2(T2_DIV_BY_16,255,1);		//819 us overflow, 819 us interrupt

	setup_ccp1(CCP_PWM);
	set_pwm1_duty((int16)510);

	while(TRUE)
	{
		//TODO: User Code
	}

}
