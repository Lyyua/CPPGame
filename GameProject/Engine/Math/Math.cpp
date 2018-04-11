#define randomInt(a,b) (rand()%(b-a))	//开区间，两个整数之间
#define randomFloat(a,b) (randomInt(a,b) + randomZERO_TO_ONE) //开区间，两个整数之间取浮点
#define randomZERO_TO_ONE (rand()/double(RAND_MAX))
#include "Math.h"

Math::Math()
{
}

float Math::RandFloat(float a, float b)
{
	//srand((unsigned)time(NULL));
	float r = randomZERO_TO_ONE;
	r = (b - a)*r + a;
	return r;
}

Math::~Math()
{
}
