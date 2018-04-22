#ifndef GAME_H
#define GAME_H

class Graphics;

class Game{
public:
	Game();
	~Game();
private:
	void game_loop();
	void draw(Graphics &graphics);
	void update(float elapsedtime);
};

#endif