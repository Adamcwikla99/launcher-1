
#pragma once

#include <map>
#include <memory>

#include <FL/Fl_Group.H>

#include "Connection.hh"
#include "DLCInfo.hh"
#include "GameInfo.hh"
#include "UserInfo.hh"
#include "News.hh"

class State {
public:
  State(const State &) = delete;
  State &operator=(const State &) = delete;

  ~State() = default;
  State() = delete;
  State(std::unique_ptr<Connection> &&connection);

  Connection &getConnection();

  void update();

  std::vector<GameInfo> &getAllGames();

  std::vector<News> &getAllNews();

  UserInfo &getUser();

private:
  std::unique_ptr<Connection> connection;
  std::unique_ptr<UserInfo> user;

  std::vector<GameInfo> allGames;
  std::vector<News> allNews;
};
