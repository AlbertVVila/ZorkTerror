#include <vector>
#include "globals.h"
#include "Player.h"
using namespace std;
class Entity;

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

