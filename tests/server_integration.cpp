#include <gtest/gtest.h>

TEST(server, cpp_api) {
  Domain internet = network{"Global", InvisiblePolicy}; // can not list components, but can connect openly
  Domain lan = network{"CoinAcid", ClosedPolicy}; // can not add components or connection, without being owner
  {
    Component database_server = System{"db.coinacid.biz", SystemState::Normal};
    Component web_server = System{"web.coinacid.biz", SystemState::Normal};
    connect(lan, web_server, database_server, OpenPolicy); // everything goes
    add_component(internet, webserver, ProtocolPolicy("HTTP")); // only accept connections with protocol "HTTP"
  }

  Actor player = Component{ ACE{"bot8df3.casa"} };
  std::optional<ComponentRef> db_server = player.try_find(internet, "db.coinacid.biz");
  // TODO add db_server is none assertion
  std::optional<ComponentRef> web_server = player.try_find(internet, "web.coinacid.biz");
  // TODO add web_server exists assertion
  std::optional<ConnectionRef> socket = player.try_connect(web_server);
  // TODO add socket exists assertion

  // Response is some normal
  Response r1 = player.request(socket, Protocol("HTTP").query("wordcoin"));

  // Response is some error
  Response r2 = player.request(socket, "Hey there!");
  // Response is some error
  Response r3 = player.request(socket, Protocol("HTTP").post("Give me money!"));

  // Response is some unintended behaviour (leak of information)
  auto exploit = SQLInject().select("USERS.wallet_key").from("USERS");
  Response r4 = player.request(socket, Protocol("HTTP").query());
}
