﻿
#pragma once

#include "Connection.hh"

class MockConnection : public Connection {
public:
  MockConnection(const MockConnection &) = delete;
  MockConnection &operator=(const MockConnection &) = delete;

  ~MockConnection() = default;
  MockConnection();

  bool isConnected() override;
  bool login(std::string name, std::string pass) override;
  bool registerAccount(std::string name, std::string pass) override;

  bool updateGame(std::string title, std::string description,
                  int price); // dodaje też grę jeśli nie ma jej na liście
  bool
  updateNews(std::string gametitle, std::string title,
             std::string content); // dodaje też grę jeśli nie ma jej na liście
  bool
  updateSocials(std::string medium,
                std::string link); // dodaje też grę jeśli nie ma jej na liście
  
  
  /*
  Istniejące zapytania sql do zaimplementowania
  
  zapytania sql
////////////////////////////////
logowanie 
select users.id
from users
where users.name = 'user1' and users.password = '123' 
//////////////////////////////////////////////////
rejestracja
poprzedozne zapytanie login i sprawdzeniem czy jest jakiś wynik
insert into users (name, password, publisher)
values ('aaa', '123', 0)
////////////////////////////////
Dekou521 — Dziś o 13:48
dodawanie gry
insert into games (name, description, price)
values ('warhammer', 'fajna gra rts', 21)
//////////////////////////////////
wybranie wszystkich gier
select *
from games
///////////////////////////////////
info o dlc
select * 
from dlcs
where gameID = '2'
////////////////////////////////////
utworzenie newsa
problem
////////////////////////////////////
info o grze
select *
from games 
where games.id = 1
/////////////////////
dostań posiadane gry
Select gameOwnership.gameID
from gameOwnership
where gameOwnership.userID = 3
////////////////////////
is logged in - no nie wiem jak to zrobić
///////////////////////////////////////
posiadane dlc
select *
from dlcOwnership
where dlcOwnership.userID = 3
////////////////////
update info o grze
UPDATE games
SET description = 'Alfred Schmidt'
WHERE games.id = 3;
/////////////////////////////////////
update login
UPDATE users
SET name = 'Alfred'
WHERE users.id = 3;
////////////////////////////
update password
UPDATE users
SET password = '123'
WHERE users.id = 3
/////////////////////////
update news
UPDATE news
SET content = 'asdwqe asd awd waeqe asdaw'
WHERE news.id = 1
  
  */
  
};
