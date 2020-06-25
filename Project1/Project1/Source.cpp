#include <SFML/Graphics.hpp>

#include <iostream>

int windowX = 1000; //initial window width
int windowY = 600; //initial window height
int speed = 10; //how fast we move

int main()
{

	//shape stuff
	sf::Vector2f rectSize = sf::Vector2f(100.f, 50.f); //size of our rectangle in pixels
	sf::Vector2f rectPos = sf::Vector2f((windowX / 2) - (rectSize.x / 2), (windowY / 2) - (rectSize.y / 2)); //centre
	sf::Color rectColour = sf::Color(255, 255, 0, 255); //0-255 for all 4, r,g,b,a

	//window stuff
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Breakout Clone!");
	window.setFramerateLimit(60); //stop game going lightspeed

	//paddle stuff
	sf::RectangleShape paddle(rectSize); //our paddle object
	paddle.setFillColor(rectColour); //set colour
	paddle.setPosition(rectPos); //set position

	//ball stuff
	sf::CircleShape ball(10.f); //create ball
	ball.setFillColor(sf::Color::Cyan);
	sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);//setup velocity
	velocity.x = rand() % 10; //initial x will be random
	velocity.y = -5;
	//move start position of the ball up by the height of the paddle
	ball.setPosition(sf::Vector2f(rectPos.x, rectPos.y - rectSize.y));

	//borders stuff
	sf::RectangleShape top;
	sf::RectangleShape bottom;
	sf::RectangleShape left;
	sf::RectangleShape right;
	top.setSize(sf::Vector2f(windowX, 1));
	top.setPosition(0, 0);
	top.setFillColor(sf::Color::Black);
	bottom.setSize(sf::Vector2f(windowX, 1));
	bottom.setPosition(sf::Vector2f(0, windowY - 1));
	bottom.setFillColor(sf::Color::Black);
	left.setSize(sf::Vector2f(1, windowY));
	left.setPosition(sf::Vector2f(0, 0));
	left.setFillColor(sf::Color::Black);
	right.setSize(sf::Vector2f(1, windowY));
	right.setPosition(sf::Vector2f(windowX - 1, 0));
	right.setFillColor(sf::Color::Black);


	//code to run whilst window is open
	while (window.isOpen())
	{
		//check if left is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			//move left
			rectPos.x -= speed;
			//if our position is outside window come back
			if (rectPos.x <= 0)
			{
				rectPos.x = 0;
			}
			paddle.setPosition(rectPos);
		}
		//check if right is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//move right
			rectPos.x += speed;
			//if our position is outside window come back
			if (rectPos.x >= windowX - rectSize.x)
			{
				rectPos.x = windowX - rectSize.x;
			}
			paddle.setPosition(rectPos);
		}
		
		if (top.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			//did we hit top
			velocity.y = -velocity.y;
		}
		if (bottom.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			//did we hit bottom
			velocity.y = -velocity.y;
		}
		if (left.getGlobalBounds().intersects(ball.getGlobalBounds()) || right.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			//left or right
			velocity.x = -velocity.x;
		}
		if (paddle.getGlobalBounds().intersects(ball.getGlobalBounds()))
		{
			//did paddle hit ball
			velocity.y = -velocity.y;
		}
		ball.move(velocity); //move ball around
		
		//PollEvent is our window updating event
		sf::Event event;
		while (window.pollEvent(event))
		{
			//if window closes
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//clear our window, and redraw everything
		window.clear();
		window.draw(paddle);
		window.draw(ball);
		window.display();
	}

	return 0;
}