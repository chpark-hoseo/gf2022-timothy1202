#include"Map.h"
#include"Player.h"
#include<iostream>

Map* Map::s_pInstance = 0;

void Map::map()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            x[j][i] = 100 * j;
            y[j][i] = 100 * i;

        }
    }
}

void Map::update()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map1[i][j] == 1)
            {
                if (((Player::Player_x <= x[j][i] + 100) && (Player::Player_x + 96 >= x[j][i])) &&
                    ((Player::Player_y <= y[j][i] + 100) && (Player::Player_y + 96 >= y[j][i])))
                {
                    Player::Block = 1;
                }
                else
                    Player::Block = 0;
            }
            else
                Player::Block = 0;
        }
    }
}
