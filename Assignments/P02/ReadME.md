## Program #2 -P02- Blackjack Game
### Byron Dowling
### Description:

Eventually the program will take shape into actual files but for now this is a conceptual assignemnt with determining our stategy for what aspects of the Blackjack game should be in classes and what can be inherited from. This include an in-depth description of each proposed class as well as what data members and methods woudl be implemented. See below.

## Proposed Class Layout

#### Class: Card
> This class is most likely going to be the main parent class that other classes will either inherit from or directly utilize through member objects. As the title says, this is where we will design and handle all aspects of how the cards will function as they will be essential for the remaining aspects of the game.
>
> ##### Member Variables:
> - int suit
> - int rank
> - int value
> - string FaceCardRank
> - string SuitType
>
> ##### Methods:
> - Set_Rank
> - Set_Value
> - Get_Rank
> - Get_Value
> - Print
>
>
> For the card design we an use integer values 1-4 to keep track of the 4 different suits and have that int value correspond to the string name of the suit type. Likewise, we can do the same thing for the rank and values of the cards 1-14 and have those correspond to the string name of the cards. Once we have these hammered out, they will be fundamental for the rest of the classes as they will relay on a collection of card objects to handle the remaining aspects of the game. The methods are fairly straighforward as they will be setters and getters for creating the values of the cards and retrieving when necessary and then a print function for show and the game-like experience.


#### Class: Deck
> The next class we'll need is a Deck class that will handle the dealing of cards to players and ensuring that the deck is shuffled after each game or reset.
>
> ##### Member Variables:
> - Vector of Cards: Deck
> - const int Deck_Size 
> - int current_capacity
> - int Number_Of_Decks
>
> ##### Methods:
> - Deal_Cards
> - Shuffle_Deck
> - Reset_Deck
> - SetNumDecks
>
>
> Logically a deck is going to be a collection of Card objects and although we could use an array, the built in functions of the vector seem more appropriate. Additionally, many Vegas casinos will play Blackjack with multiple decks of cards at a table so I propose having a number of decks value along with a current capacity value to ensure the deck is not too low. After each hand the deck could theoretically be shuffled and then distributed and eventually when the deck gets below a certain capacity, the deck/decks could be reset and start again. We are also using a const int for the size of the deck since this won't change as it is always 52 cards per deck. As far as our methods go, we have ones that are pretty straightforward for dealing the cards and distributing them to a player, a method for shuffling or really randomizing the remaing cards in the deck, a setter for determining how many decks we'll be playing with, and a method, really a destructor most likely for resetting the deck.

#### Class: Player
> This class will handle the information needed for the player aspect of the Blackjack game
>
> ##### Member Variables:
> - int Bank
> - string PlayerName(or Alias)
> - Vector of Cards: Hand
>
> ##### Methods: 
> - Hit_Me
> - Bet
> - Winner_Winner_Chicken_Dinner (lame 21 reference, I know)
> - Stand
>
>
> For our player class, we need an int variable to keep track of the player's money, since Blackjack ordinarily bets in non-fractionated numbers, there's no need to use float or doubles here. We'll also need a simple string to keep track of the different player aliases, and most importantly we'll have a vector of cards that will be dealt to the player. A vector of cards is ideal here since different players will need a varying amount of cards to win, stand, or eventually bust. For our methods, we'll need one that can request a new card and push that into the player's "hand" to simulate "hitting" as well as a stand option to stop requesting cards and stand with the current hand. There will be a bet option to give the player an option to bet more at the beginning of each hand. Finally, this could be handled in a different class but the "Winner_Winner_Chicken_Dinner" Method could be used to automatically check if a player's hand equals 21 and if so iniates an instant winner after checking that the dealer does not also have 21. It could be handled in other classes but since this one is specific to only looking for one outcome (21) it could still work here and prevent from attempting to hit on an already winning hand.

#### Class: Hand
> This class will handle the aspects of Blackjack hands during each round of the game
>
> ##### Member Variables:
> - Vector of Cards: Hand
> - Vector of Hands: Current_Game 
>
> ##### Methods:
> - Sort Cards
> - Discard
> - Add Card
> - Disctribute Hand
>
>
> This class is the one I'm least sure about as I feel like it overlaps with both player and the Game class (description below). One way I imagine this potentially working is creating empty vectors of cards for the number of players and then distributing the first two cards to each one and then assigning those to a Vector of Hands and distributing them to each player. However I feel this could potentially be absorbed into work of other classes. If we stick with this route, there would be a method for sorting and distributing the cards, adding cards to each hand, potentially discarding cards, and then distributing the initial hands to the players.

#### Class: Game
> Arguably the joint most important class along with the Card class. This class will be heavily reliant on other objects and handle the game aspects.
>
> ##### Member Variables:
> - Vector of Players: Player_Table
> - Vector of Hands: Current_Game
> - Deck: Game_Deck
> - Player: Dealer
>
> ##### Methods:
> - Print_Current_Results
> - Accept_Bets
> - Max_Min_Bet
> - Double_Down
> - Determine_Winner/Outcome
> - Add_Player
>
>
> This class will rely on many other objects to provide the game experience. We will have a vector of player objects to fill the "table" of people playing the game. There will also be a vector of hands to keep track of what each players has, this could potentially be handled from the Hand class but I feel it might make more sense to be done here. There will be an Object derived from the Deck class called Game_Deck and this will have all the cards that we're working with. I also think this could be the place to declare the dealer either as a Player Class Object or as something else but in this aspect of the program, since the dealer is key to the outcome of the game I feel it makes sense to have it here. For our methods, we have a print method for printing all aspects of the game, the Accept Bets method can take bets derived from the player class and hold this value so it knows how much to pay out for a winner. Some Blackjack tables have Max and Min bets so this could be a setter function for this is we want these rules. There can also be a method for allowing a player to double down as this would be a form of accepting bets but also checking the results to see if the scenario allows for this. A method could also potentially belong here for adding players if we want to allow for more players in the middle of the game depending on design scope. Finally, the Determine Winner method will weigh the hands of each player against the dealer to see if payouts are warranted or not. 
>
>
>
![Image of flowchart](https://github.com/Byron-Dowling/2143-OOP-Dowling/blob/master/Assignments/P02/UML%20class.png)
