#include <vector>
#include "globals.h"
using namespace std;
class Entity;
class Player;

class World
{

public:
	World();
	~World();
	bool GetInput(const vector<string> &args);
private:
	vector<Entity*> entities;
	Player *player;
};

