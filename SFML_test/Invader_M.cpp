#include "Invader_M.h"

Invader_M::Invader_M(sf::Vector2f size, sf::Vector2f screenSize, Direction dir) : m_pos((screenSize.x / 2), -size.y), m_direction(dir), m_speed(0.01), m_counter(0), m_screenSize(screenSize), m_size(size), m_hp(2)
{
	int rdAngle = 0;

	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distr(1, 360);

	rdAngle = distr(eng);

	m_InvaderSprite = new Entity(m_pos, size, "Ressources/textures/ET3.png");
	m_pos = m_InvaderSprite->rotate(rdAngle, sf::Vector2f(m_screenSize.x / 2, m_screenSize.y / 2));
}

void Invader_M::update()
{
	m_counter++;

	float dx = ((((m_screenSize.x - m_size.x) / 2) - (m_pos.x)) / 100000);
	float dy = ((((m_screenSize.y - m_size.y) / 2) - (m_pos.y)) / 100000);

	m_InvaderSprite->move(sf::Vector2f(dx, dy));

	m_pos = m_InvaderSprite->rotate(m_speed, sf::Vector2f(m_screenSize.x / 2, m_screenSize.y / 2));

}

void Invader_M::render(sf::RenderWindow &window)
{
	m_InvaderSprite->render(&window);
}

Invader_M::~Invader_M()
{
}
