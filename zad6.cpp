#include <iostream>
#include <array>
#include <cstdlib> 
#define TARGET_RATE 21

int getRandomNumber(int min,int max)
{
 	static const double fraction=1.0/(static_cast<double>(RAND_MAX) + 1.0);
 	return static_cast<int>(rand() * fraction * (max-min+1) + min);
}


enum Mast {
	TREF,
	BUBNA,
	CHERVI,
	PIKI,
	MAST_LENGTH
};

enum Dostoinstvo {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	VALET,
	DAMA,
	KOROL,
	TUZ,
	DOSTOINSTVO_LENGTH
};

struct Card {
	Mast mast;
	Dostoinstvo dostoinstvo;
};



void PrintCard(const Card &card){
	switch (card.dostoinstvo){
		case 	TWO:
			std::cout <<  "2 ";
			break;
		case 	THREE:
			std::cout <<  "3 ";
			break;
		case 	FOUR:
			std::cout <<  "4 ";
			break;
		case 	FIVE:
			std::cout <<  "5 ";
			break;
		case 	SIX:
			std::cout <<  "6 ";
			break;
		case 	SEVEN:
			std::cout <<  "7 ";
			break;
		case 	EIGHT:
			std::cout <<  "8 ";
			break;
		case 	NINE:
			std::cout <<  "9 ";
			break;
		case 	TEN:
			std::cout <<  "10 ";
			break;
		case 	VALET:
			std::cout <<  "valet ";
			break;
		case 	DAMA:
			std::cout <<  "dama ";
			break;
		case 	KOROL:
			std::cout <<  "korol ";
			break;
		case 	TUZ:
			std::cout <<  "tuz ";
			break;
		default:
			std::cout <<  "ERROR IN dostoinstvo!!! ";
		}
	switch (card.mast){
		case TREF:
			std::cout <<  "TREF (kresta)";
			break;
		case 	BUBNA:
			std::cout <<  "BUBNA (rombik)";
			break;
		case 	CHERVI:
			std::cout <<  "CHERVI (serdechko)";
			break;
		case 	PIKI:
			std::cout <<  "PIKI ";
			break;
		default:
			std::cout <<  "ERROR in mast !-!-! ";
		}
	//std::cout <<  '\n';
}

void swapCard(Card &a, Card &b){
	Card temp=a;
	a=b;
	b=temp;
}


void printDeck(const std::array<Card,52> &deck){
	for(Card a: deck){
		PrintCard(a);
		//std::cout<<'\n';
		}
}


void shuffleDeck(std::array<Card,52> &deck){
	srand(static_cast<unsigned int>(time(0)));
	std::cout<<"\n=== Shuffling the deck ===\n";
	int ra;
	for(Card &a: deck){
		ra=getRandomNumber(0,51);
		swapCard(a,deck[ra]);
	}
}

int getCardValue(Card &card){
	int rez{static_cast<int>(card.dostoinstvo)};
	if(rez<9) return rez+2;
	else if(rez<12) return 10;
	else return 11;
}


int main(){
// Declaration of the deck of cards
	std::array<Card,52> deck;
	int ind;
	
	// Create of the deck of cards
	for(int i=0; i<DOSTOINSTVO_LENGTH; ++i){
		for(int j=0; j<MAST_LENGTH;++j){
			ind= j*(DOSTOINSTVO_LENGTH)+i;
			deck[ind].mast=static_cast<Mast>(j);
			deck[ind].dostoinstvo=static_cast<Dostoinstvo>(i);
		}
	}

	// Start Game
	std::cout<<"=== Start Game ===\n";
	int dealer_rate {0};
	int gamer_rate {0};
	int tmp_var;
	shuffleDeck(deck);
	int indexCard{0};
	Card top_deck=deck[indexCard];
	
	std::cout<<"The dealer takes 1 card\n";
	dealer_rate=getCardValue(top_deck);
	std::cout<<"This is " << dealer_rate <<" point\n";
	++indexCard;
	gamer_rate = getCardValue(deck[indexCard++]);
	
	std::cout<<"\nPlayer, you get two cards\nThis is " << gamer_rate;
	tmp_var=getCardValue(deck[indexCard++]);
	std::cout<< " and " << tmp_var << " points.  ";
	gamer_rate+=tmp_var;
	std::cout<<"Total " << gamer_rate << " points\n";

	// TURN 1

	std::cout<<"Player, it's your turn. Enter 1 to hit a card or 0 to stand: ";
	int turn;
	std::cin>>turn;	

	if(turn==1){
		tmp_var=getCardValue(deck[indexCard++]);
		std::cout<<"You get " << tmp_var << " points. ";
		gamer_rate+=tmp_var;
		if(gamer_rate>TARGET_RATE){
			std::cout<<"You lose!!!\n"<<"You total rate " << gamer_rate << " points\n";
		}
		else{
			std::cout<<"You total rate " << gamer_rate << " points\n";
		}
		
	}
	else if(turn==0){
		std::cout<<"You abstain\n";
		if(gamer_rate>TARGET_RATE){
			std::cout<<"You lose!!!\n";
		}
		else{
			std::cout<<"You win!!!\n";
		}
	}
	else{
		std::cout<<"ERROR!!!\n";
	}

	return 0;
}