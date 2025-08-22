#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <asio.hpp>

#include "../common/Game.h"

class NetworkServer {
  public:
    bool Start(unsigned short port);

    void Update();

    void Stop();

  private:
    Game game;
    
};


#endif
