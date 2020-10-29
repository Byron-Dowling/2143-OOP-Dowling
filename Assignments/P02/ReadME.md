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
> - Vector of Cards: Deck (wouldn't let me format that with proper syntax)
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
>
