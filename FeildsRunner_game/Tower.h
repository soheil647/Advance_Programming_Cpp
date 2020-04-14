#ifndef FEILDSRUNNER_GAME_TOWER_H
#define FEILDSRUNNER_GAME_TOWER_H


class Tower {
protected:
    string name;
    string picture;
    int position;
    int size;
    int cost;
public:
    Tower(string _name, int _position, int _size, string _picture, int _cost)
    virtual fire()
    virtual upgrade(int cost)
};


#endif //FEILDSRUNNER_GAME_TOWER_H
