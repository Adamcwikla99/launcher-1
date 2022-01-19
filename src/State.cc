
#include "State.hh"

State::State(std::unique_ptr<Connection> &&connection)
    : connection(std::move(connection)) {
  update();
}

Connection &State::getConnection() { return *connection; }

void State::update() {
  user = connection->getUserInfo();
  allGames = connection->getAllGames();
  allNews = connection->getAllNews();
}

std::vector<GameInfo> &State::getAllGames() { return allGames; }
std::vector<News> &State::getAllNews() { return allNews; }
UserInfo &State::getUser() { return *user; }