#include "people.hpp"

#ifndef PLAYER_CPP
#define PLAYER_CPP

//class People; // Forward declaration

class Player : public People {

    std::string m_team {"None"};
    std::string m_game {"None"};

    // friend std::ostream& operator<<(std::ostream& out, const Player& Player);

    public:
        Player() = default;
        ~Player() = default;

        Player(std::string_view team, std::string_view game);

        std::string_view get_team();
        std::string_view get_game();

        Player set_game(std::string_view game);
        Player set_team(std::string_view team);
};


#endif // PLAYER_CPP
