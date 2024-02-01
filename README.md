# WarZone #

A C++ Warzone game played from the terminal where (Similar to the boardgame [Risk](https://store.steampowered.com/app/1128810/RISK_Global_Domination/)) with the following design:
- The map is implemented as a connected graph, where each node represents a territory.
- The player owns a collection of territories and cards.
- A deck and hand of Warzone cards. Each card has a type from: bomb, reinforcement, blockade, airlift and diplomacy.
- A game engine that controls the flow of the game by using the notion of state, transition, and command. The state represents a certain phase of the game and dictates what are the valid actions or user commands that take place in this phase.
  
## Resources ##

- Warzone online online game to test expected behaviour (https://www.warzone.com)
- The different downloadable maps for the game Warzone (http://domination.sourceforge.net/getmaps.shtml)
