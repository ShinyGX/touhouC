#include "SlowedBullet.h"
#include "Util.h"
#include "Math.h"
#include "Time.h"


SlowedBullet::SlowedBullet():angle(0)
{
}


SlowedBullet::~SlowedBullet()
{
}

SlowedBullet::SlowedBullet(const std::string & path, int width, int height, float aliveTime)
	:Bullet(path, width, height, aliveTime)
{
}

void SlowedBullet::draw(CDC * dc, CDC * canvasDC)
{

	if (bulletPos.x < 0 || bulletPos.y < 0 || bulletPos.x > 390 || bulletPos.y > 560)
		state = DIE_OUT_OF_RANGE;
	else
		state = DISPLAY;

	bulletPos.y += cos(angle / PI) * speed * (1 - timer / aliveTime);
	bulletPos.x += sin(angle / PI) * speed * (1 - timer / aliveTime);

	if (isDead())
		return;

	timer += Time.detlaTime;
	DRAW_IMG(dc, canvasDC, bullet, bulletPos.x, bulletPos.y);
}

Bullet * SlowedBullet::clone()
{
	SlowedBullet * b = new SlowedBullet();
	b->bullet = bullet;
	b->bulletPos = bulletPos;
	b->aliveTime = aliveTime;
	b->speed = speed;
	b->state = state;
	b->damage = damage;
	b->angle = angle;
	return b;
}



BulletType SlowedBullet::getBulletType()
{
	return BULLET_TYPE_CIRCLE;
}

void SlowedBullet::setAngle(float angle)
{
	this->angle = angle;
}
