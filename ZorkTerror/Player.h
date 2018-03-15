#pragma once
#include "Creature.h"

class Player :
	public Creature
{
public:

	Player(const string &name, const string &description, Room *room);
	~Player();

	void Look(const vector<string> &args) const;
	void Go(const vector<string> &args);
	void Take(const vector<string> &args);
	void Drop(const vector <string> &args);
	void Put(const vector <string> &args);
	void Read(const vector<string> &args) const;
	void Open(const vector<string> &args) const;
	void Close(const vector<string> &args) const;
	void Inventory() const;
	void Turn(const vector<string> &args) const;
	void Hide();
	void Reveal();
	void Unlock(const vector<string> &args) const;
	void Move(const vector<string> &args) const;
	void ChangeParent(Entity* newParent);
	bool isHiding=false;
};
