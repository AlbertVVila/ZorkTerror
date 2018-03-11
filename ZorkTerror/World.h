#include <vector>
using namespace std;
class Entity;
class Player;

class World
{

public:
	World();
	~World();
	bool GetInput(const string &input);
private:
	vector<Entity*> rooms;
	Player *player;
};

