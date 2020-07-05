#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Brick
{
public:
	sf::RectangleShape bShape;
	sf::Color bColour;
	sf::Vector2f bSize;
	sf::Vector2f bPos;
};

class Ball
{
public:
	void Bounce(int dir, sf::RectangleShape obj, sf::CircleShape ball) 
	{
		//what surface did we hit, and what direction do we need to travel?
		int x = (obj.getPosition().x + obj.getSize().x / 2) - (ball.getPosition().x + ball.getRadius());
		switch (dir)
		{
		case 0:
			if (x > 0)
			{
				//right side
				ballVelocity.y = -ballVelocity.y;
				ballVelocity.x += 1;
			}
			else
			{
				//left side
				ballVelocity.y = -ballVelocity.y;
				ballVelocity.x -= 1;
			}
			break;
		case 1:
			//horizontally (left or right side of screen)
			ballVelocity.x = -ballVelocity.x;
			break;

		}
	}

	sf::CircleShape ballshape;
	sf::Vector2f ballStartPos;
	sf::Vector2f ballVelocity;
	float ballRadius = 10.f;
};

class Paddle
{
public:
	void UpdatePosition(float dir)
	{
		pShape.setPosition(dir * speed, pShape.getPosition().y);
	}
	sf::RectangleShape pShape;
	float speed = 10.f;
	sf::Vector2f pSize;
	sf::Color pColour;
};

class Game
{
public:
	//Functions to run the game
	bool Start();
	int Update();

	sf::RenderWindow window;
	sf::RectangleShape top;
	sf::RectangleShape bottom;
	sf::RectangleShape left;
	sf::RectangleShape right;
	float windowWidth = 1000;
	float windowHeight = 600;
	int score = 0;
	int lives = 3;
	sf::Font font;
	sf::Text scoreText;
	sf::Text livesText;
	sf::SoundBuffer paddleSB;
	sf::SoundBuffer wallSB;
	sf::SoundBuffer bricksSB;
	sf::Sound sound;
};