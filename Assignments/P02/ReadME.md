## Program #2 -P02- BlackJack Game
### Byron Dowling
### Description:

Eventually the program will take shape into actual files but for now this is a conceptual assignemnt with determining our stategy for what aspects of the BlackJack game should be in classes and what can be inherited from. This include an in-depth description of each proposed class as well as what data members and methods woudl be implemented. See below.

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
> - Vector<Card> Deck
> - const int Deck_Size 
