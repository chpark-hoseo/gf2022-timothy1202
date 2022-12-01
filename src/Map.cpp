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
            x[i][j] = 100 * i;
            y[i][j] = 100 * j;
            std::cout << x[i][j] << std::endl;
            std::cout << y[i][j] << std::endl;

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
                if (((Player::Player_x <= x[i][j] + 100) && (Player::Player_x + 96 >= x[i][j])) &&
                    ((Player::Player_y <= y[i][j] + 100) && (Player::Player_y + 96 >= y[i][j])))
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
