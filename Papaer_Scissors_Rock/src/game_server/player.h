#pragma once

class Player
{
public:
    Player();
    virtual ~Player();

    virtual void StartGame() = 0;
    //virtual void RestartGame() = 0;
    virtual void Play() = 0;
    virtual void Update() = 0;
    virtual void ExitGame() = 0;
};

