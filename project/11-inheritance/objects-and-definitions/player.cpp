#include "player.hpp"

Player::Player(std::string_view team, std::string_view game){
    m_game = game;
    m_team = team;
}

std::ostream& operator<<(std::ostream& out, const Player& Player){
    out << "Player: [ Game: "
        << Player.m_game
        << ", Team: "
        << Player.m_team
        << " ]";
    return out;
}

std::string_view Player::get_team(){
    return m_team;
}

std::string_view Player::get_game(){
    return m_game;
}

Player Player::set_game(std::string_view game){
    m_game = game;
    return *this;
}

Player Player::set_team(std::string_view team){
    m_team = team;
    return *this;
}

